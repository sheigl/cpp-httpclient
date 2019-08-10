#ifndef KVP_H
#define KVP_H
#include "keyvaluepair.h"
#endif

class HeaderCollection {
  public:    
    void addHeader(char *headerName, char *headerValue);
    int length();
    KeyValuePair *getHeader(int index);
    HeaderCollection();
    ~HeaderCollection();
  private:
    KeyValuePair **headers;
    int sizeOfArray = 0;
};