#define _CRT_SECURE_NO_WARNINGS

#ifndef SIMPLE_H
#define SIMPLE_H
#include "simpleclient.h"
#endif

#ifndef REQ_H
#define REQ_H
#include "httprequest.h"
#endif

#ifndef RES_H
#define RES_H
#include "httpresponse.h"
#endif

#ifndef STD
#define STD
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

int main() {
  char *method = (char *)malloc(sizeof(char) * sizeof("GET"));
  char *url = (char *)malloc(sizeof(char) * sizeof("/api"));
  char *host = (char *)malloc(sizeof(char) * sizeof("host.com"));

  strcpy(method, "GET");
  strcpy(url, "/api");
  strcpy(host, "host.com");

  HttpRequest req = HttpRequest(method, url);
  SimpleClient client = SimpleClient(host, 80);

  client.request(&req);
}