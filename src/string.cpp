#include "technikum/string.h"

technikum::string::string(char const* s) {
    this->str = s;
}

char const* technikum::string::c_str() {
    return this->str;
}

int technikum::string::length(const char *s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

int technikum::string::size(const char *s) {
    return sizeof(s);
}