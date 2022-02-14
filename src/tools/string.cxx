
#include<iostream>
#include "../../include/tools/string.h"

STRING::STRING(){
    _size = 0;
    data = new char[51];
}

void STRING::show(){
    std::cout << *data << std::endl;
}

bool STRING::eq(STRING *s){
    if (_size != s->_size) return false;
    int i;
    for (i = 0; i < _size; i++){
        if (data[i] != s->data[i]) return false;
    }
    return true;
}

