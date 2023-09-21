#include "technikum/string.h"

technikum::string::string(char const* s) {
    this->str = s;
}

char const* technikum::string::c_str() {
    return this->str;
}

int technikum::string::length() {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}

int technikum::string::size() {
    return length();
}

char* technikum::string::append(char* dest, const char* src) {
    int i, j;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return dest;
}