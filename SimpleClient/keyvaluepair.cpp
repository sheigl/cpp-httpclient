#define _CRT_SECURE_NO_WARNINGS

#ifndef KVP_H
#define KVP_H
#include "keyvaluepair.h"
#endif

#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

KeyValuePair::KeyValuePair(char *k, char *v) {
  printf("Creating KeyValuePair(%s, %s)\r\n", k, v);
  this->init();

  this->setKey(k);
  this->setValue(v);
};

KeyValuePair::KeyValuePair() {
  printf("Creating KeyValuePair()\r\n");

  this->init();
};

KeyValuePair::~KeyValuePair() {
  printf("Deconstructing KeyValuePair(%s, %s)\r\n", this->key, this->value);

  if (this->key)
  {
    free(this->key);
  }
  
  if (this->value)
  {
    free(this->value);
  }
};

char *KeyValuePair::getKey() {
  printf("Entering getKey()\r\n");

  if (this->key == NULL)
  {
    printf("key is NULL!\r\n");
    return NULL;
  }
  
  //printf("key is %s\r\n", this->key);
  return this->key;
}
char *KeyValuePair::getValue() {
  printf("Entering getValue()\r\n");

  if (this->value == NULL)
  {
    printf("value is NULL!\r\n");
    return NULL;
  }

  //printf("value is %s\r\n", this->value);
  return this->value;
}

void KeyValuePair::setKey(char *k) {
  printf("Entering setKey(%s)\r\n", k);

    //realloc(this->key, sizeof(char) * strlen(k));
    strcpy(this->key, k);
}

void KeyValuePair::setValue(char *v) {
  printf("Entering setValue(%s)\r\n", v);
  
  //realloc(this->value, sizeof(char) * strlen(v));
  strcpy(this->value, v);
}

void KeyValuePair::init() {
  int size = sizeof(char) * 256;

  printf("Allocating ");
  printf("%d", &size);
  printf(" bytes...\r\n");

  this->key = (char *)malloc(size);
  this->value = (char *)malloc(size);

  memset(this->key, 0, size);
  memset(this->value, 0, size);
}
