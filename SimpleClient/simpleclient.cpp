#define _CRT_SECURE_NO_WARNINGS

#ifndef SIMPLE_H
#define SIMPLE_H
#include "simpleclient.h"
#endif

#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

SimpleClient::SimpleClient(char *host, int port) {
    
    printf("Creating SimpleClient()\r\n");

    int size = sizeof(char) * 2048;

    printf("Allocating ");
    printf("%d", &size);
    printf(" bytes...\r\n");

    this->host = (char *)malloc(size);
    
    strcpy(this->host, host);
    this->port = port;
};

SimpleClient::~SimpleClient() {
    printf("Deconstructing SimpleClient(%s, %n)", this->host, &this->port);
    
    if (this->host)
    {
        free(this->host);
    }
};

HttpResponse *SimpleClient::request(HttpRequest *request) {
    printf("Entering request()\r\n");

    this->initClient();

    HeaderCollection *defaultHeaders = createHeaders(request->method, this->host, request->url);
    
    printf("POST /%s HTTP/1.1\r\n", request->url);
    //client.printf("POST /%s HTTP/1.1\r\n", request->url);

    printf("Sendng headers...\r\n");
    int len = defaultHeaders->length();
    
    KeyValuePair kvp = defaultHeaders->getHeader(0);
    printf("%s", kvp.getKey());
    printf(":");
    printf("%s\r\n", kvp.getValue());

    if (request->token != NULL)
    {
        //client.print("X-TOKEN: ");
        //client.println(request->token);
    }
    
    printf("Sendng content...\r\n");
    //client.print("Content-Length: ");
    //client.println(strlen(request->body));
    //client.println();
    //client.println(request->body); 

    printf("Reading response...\r\n");

    HttpResponse *res = (HttpResponse *)malloc(sizeof(HeaderCollection) * 1);
    res = new HttpResponse();

    /*
    while(client.connected() || client.available()) 
    {
        int clientAvailable = client.available();

        if (clientAvailable)
        {            
            //Serial.println(client.readStringUntil('\r'));
        }      
    }*/

    return res;
};

HeaderCollection *SimpleClient::createHeaders(char *method, char *host, char *relativeUrl) {
    printf("Entering createHeaders()\r\n");
    HeaderCollection *headers = (HeaderCollection *)malloc(sizeof(HeaderCollection) * 1);   
    headers = new HeaderCollection();

    char *hostKey = (char*)malloc(sizeof(char) * sizeof("Host"));
    strcpy(hostKey, "Host");

    char *ccKey = (char*)malloc(sizeof(char) * sizeof("Cache-Control"));
    strcpy(ccKey, "Cache-Control");

    char *cc = (char*)malloc(sizeof(char) * sizeof("no-cache"));
    strcpy(cc, "no-cache");

    char *ctKey = (char*)malloc(sizeof(char) * sizeof("Content-Type"));
    strcpy(ctKey, "Content-Type");

    char *ct = (char*)malloc(sizeof(char) * sizeof("application/json"));
    strcpy(ct, "application/json");

    headers->addHeader(hostKey, host);
    headers->addHeader(ccKey, cc);
    headers->addHeader(ctKey, ct);

  return headers;
};

void SimpleClient::initClient() {
    /*Serial.println("Entering initClient()");
    // Use WiFiClient class to create TCP connections
    if (!client.connect(host, port)) {
        isConnected = false;
    }
    else {
        isConnected = true;
    }*/
}

