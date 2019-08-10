#ifndef RES_H
#define RES_H
#include "httpresponse.h"
#endif


class SimpleClient {
  public:
    bool isConnected;
    HttpResponse *request(HttpRequest *request);
    SimpleClient(char *host, int port);
    ~SimpleClient();
    private:
      char *host;
      int port;

      void initClient();

      HeaderCollection *createHeaders(char *method, char* host, char *relativeUrl);
};