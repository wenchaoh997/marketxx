
#ifndef _STRING_H_
#define _STRING_H_

class STRING
{
private:
    int _size;
    char *data;
public:
    STRING();
    ~STRING(){};
    void show();
    int length(){ return _size; }
    bool eq(STRING *s);
    bool eq(STRING s){ return eq(&s); }
    // void set(char& c);
};

#endif