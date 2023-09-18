#include "technikum/string.h"

technikum::string::string(char const* s) {
    this->str = s;
}

char const* technikum::string::c_str() {
    return this->str;
}
