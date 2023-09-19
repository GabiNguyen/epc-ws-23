#include "technikum/string.h"

#include <utility>

technikum::string::string(char const* s) {
    this->str = s;
}

technikum::string::string(string const& other) : string(other.str) {
    // noop
}

technikum::string::string(string&& other) : string(std::exchange(other.str, nullptr)) {
    // noop
}

technikum::string& technikum::string::operator=(string const& other) {
    return *this = string(other);
}

technikum::string& technikum::string::operator=(string&& other) {
    std::swap(this->str, other.str);
    return *this;
}

char const* technikum::string::c_str() {
    return this->str;
}
