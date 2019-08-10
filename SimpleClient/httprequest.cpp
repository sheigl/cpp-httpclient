#define _CRT_SECURE_NO_WARNINGS

#ifndef REQ_H
#define REQ_H
#include "httprequest.h"
#endif

#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

HttpRequest::HttpRequest(char *method, char *url) {
  printf("Creating HttpRequest()\r\n");

  int size = sizeof(char) * 256;

  this->body = (char *)malloc(size);
  memset(this->body, 0, size);

  this->method = (char *)malloc(sizeof(char) * 10);
  memset(this->method, 0, sizeof(char) * 10);

  this->url = (char *)malloc(size);
  memset(this->url, 0, size);

  this->token = (char *)malloc(size);
  memset(this->token, 0, size);

  strcpy(this->method, method);
  strcpy(this->url, url);
};

HttpRequest::~HttpRequest() {
  printf("Deconstructing HttpRequest()\r\n");
  
  if (this->body)
  {
    free(this->body);
  }
  
  if (this->method)
  {
    free(this->method);
  }

  if (this->url)
  {
    free(this->url);
  }

  if (this->token)
  {
    free(this->token);
  }

};