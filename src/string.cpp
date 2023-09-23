#include "technikum/string.h"
#include <string.h>
#include <cstddef>
#include <stdexcept>

#include <utility>

technikum::string::string(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }
    str_size = length(s);
    this->str = new char[length(s) + 1];
    memcpy(this->str, s, length(s) + 1);
}

technikum::string::~string() {
    delete[] this->str;
}

// copy constructor
technikum::string::string(string const& other) : string(other.str) {
    // noop
}

// move constructor
/* technikum::string::string(string&& other) : string(std::exchange(other.str, nullptr)) {
    delete[] other.str;
}
 */

technikum::string::string(string&& other) noexcept {
    str_size = other.str_size;
    str = other.str;

    other.str = nullptr;
    other.str_size = 0;
}

// copy assignment
technikum::string& technikum::string::operator=(string const& other) {
    return *this = string(other);
}

// move assignment
technikum::string& technikum::string::operator=(string&& other) {
    std::swap(this->str, other.str);
    return *this;
}

char const* technikum::string::c_str() {
    return this->str;
}

size_t technikum::string::length() {
    return length(this->str);
}

size_t technikum::string::size() {
    return length();
}

void technikum::string::append(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    size_t strLength = length();
    size_t sLength = length(s);

    char* newStr = new char[strLength + sLength + 1];

    memcpy(newStr, this->str, strLength);
    memcpy(newStr + strLength, s, sLength);
    newStr[strLength + sLength] = '\0';

    delete[] this->str;
    this->str = newStr;
}

size_t technikum::string::length(char const* s) {
    size_t length = 0;

    while(s[length] != '\0') {
        length++;
    }

    return length;
}
