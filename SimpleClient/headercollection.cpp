#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADERCOL_H
#define HEADERCOL_H
#include "headercollection.h"
#endif

#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif


int HeaderCollection::length() {
  printf("Entering length()\r\n");
  return this->sizeOfArray;
};

HeaderCollection::HeaderCollection() {
  printf("Creating HeaderCollection()\r\n");

  int size = sizeof(KeyValuePair *) * 20;

  printf("Allocating ");
  printf("%d", &size);
  printf(" bytes...\r\n");

  this->headers = (KeyValuePair **)malloc(size);
  memset(this->headers, 0, size);
};

HeaderCollection::~HeaderCollection() {
  printf("Deconstructing HeaderCollection()\r\n");
  
  if (this->headers)
  {
    free(this->headers);
  } 
}

KeyValuePair *HeaderCollection::getHeader(int index) {
  printf("Entering getHeader()\r\n");
  return headers[index];
};

void HeaderCollection::addHeader(char *headerName, char *headerValue) {
  printf("Entering addHeader(%s, %s)\r\n", headerName, headerValue);

  this->sizeOfArray++;
  
  printf("Adding new header to end of array...\r\n");
  KeyValuePair *header = (KeyValuePair *)malloc(sizeof(KeyValuePair) * 1);
  header->setKey(headerName);
  header->setValue(headerValue);


  this->headers[this->sizeOfArray - 1] = header;

  printf("Size of headers is now ");
  printf("%d \r\n", &this->sizeOfArray);
};