#ifndef REQ_H
#define REQ_H
#include "httprequest.h"
#endif

class HttpResponse {
  public:
    char *body;
    HeaderCollection *headers;
    HttpRequest *request;

    HttpResponse();
    ~HttpResponse();
};