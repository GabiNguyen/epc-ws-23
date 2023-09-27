#include "technikum/string.h"
#include <string.h>
#include <cstddef>
#include <stdexcept>

#include <utility>

technikum::string::string(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    this->str = new char[length(s) + 1];
    memcpy(this->str, s, length(s) + 1);
}

technikum::string::~string() {
    delete[] this->str;
}

// copy constructor
technikum::string::string(string const& other) noexcept : string(other.str) {
    // noop
}

// move constructor
technikum::string::string(string&& other) noexcept : str(nullptr) {
    // Copy c string
    str = other.str;

    // Set to nullptr to memory is not
    // freed when other is destroyed
    other.str = nullptr;
}

// copy assignment
technikum::string& technikum::string::operator=(string const& other) noexcept {
    return *this = string(other);
}

// move assignment
technikum::string& technikum::string::operator=(string&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] str;

    // Copy c string
    str = other.str;

    // Set to nullptr to memory is not
    // freed when other is destroyed
    other.str = nullptr;

    return *this;
}

char const* technikum::string::c_str() const {
    return this->str;
}

size_t technikum::string::length() const {
    return length(this->str);
}

size_t technikum::string::size() const {
    return length();
}

technikum::string* technikum::string::append(char const* s) {
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
    return this;
}

size_t technikum::string::length(char const* s) {
    size_t length = 0;

    while(s[length] != '\0') {
        length++;
    }

    return length;
}
