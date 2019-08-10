#define _CRT_SECURE_NO_WARNINGS

#ifndef RES_H
#define RES_H
#include "httpresponse.h"
#endif

#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

HttpResponse::HttpResponse() {
  printf("Creating HttpResponse()\r\n");

  int size = sizeof(char) * 512;

  printf("Allocating ");
  printf("%d", &size);
  printf(" bytes...\r\n");

  this->body = (char *)malloc(size);
  memset(this->body, 0, size);

  this->headers = (HeaderCollection *)malloc(sizeof(HeaderCollection) * 1);
  memset(this->headers, 0, sizeof(HeaderCollection) * 1);

  this->request = (HttpRequest *)malloc(sizeof(HttpRequest) * 1);
  memset(this->request, 0, sizeof(HttpRequest) * 1);
}

HttpResponse::~HttpResponse() {
  printf("Deconstructing HttpResponse()\r\n");

  if (this->body)
  {
    free(this->body);
  }

  if (this->headers)
  {
    free(this->headers);
  }

  if (this->request)
  {
    free(this->request);
  }
}