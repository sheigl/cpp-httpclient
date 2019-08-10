class KeyValuePair {
  public:    
    KeyValuePair(char *k, char *v);
    KeyValuePair();
    ~KeyValuePair();
    char *getKey();
    void setKey(char* k);
    char *getValue();
    void setValue(char* v);
  private:
    char *key;
    char *value;

    void init();
};