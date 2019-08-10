#ifndef HEADERCOL_H
#define HEADERCOL_H
#include "headercollection.h"
#endif


class HttpRequest {
  public:
    HeaderCollection *headers;
    char *url;
    char *method;
    char *body;
    char *token;
    HttpRequest(char *method, char *url);
    ~HttpRequest();
};