#include "technikum/string.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>

// /////////////////////////////////////////////////////////////////////////
// iterator
// /////////////////////////////////////////////////////////////////////////

technikum::string::iterator::iterator(pointer p) : ptr(p) {
    // noop
}

technikum::string::iterator& technikum::string::iterator::operator++() {
    ptr++;
    return *this;
}

technikum::string::iterator technikum::string::iterator::operator++(int) {
    iterator tmp(*this);
    ++(*this);
    return tmp;
}

technikum::string::iterator& technikum::string::iterator::operator--() {
    ptr--;
    return *this;
}

technikum::string::iterator technikum::string::iterator::operator--(int) {
    iterator tmp(*this);
    --(*this);
    return tmp;
}

bool technikum::string::iterator::operator!=(iterator const& other) const {
    if (ptr == nullptr || other.ptr == nullptr) {
        throw std::logic_error("Iterator cannot be null");
    }
    return ptr != other.ptr;
}

bool technikum::string::iterator::operator==(iterator const& other) const {
    if (ptr == nullptr || other.ptr == nullptr) {
        throw std::logic_error("Iterator cannot be null");
    }
    return ptr == other.ptr;
}

technikum::string::iterator::reference technikum::string::iterator::operator*() const {
    return *ptr;
}

// /////////////////////////////////////////////////////////////////////////
// rule of five
// /////////////////////////////////////////////////////////////////////////

technikum::string::string(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    this->str = new char[length(s) + 1];
    std::copy(s, s + length(s) + 1, this->str);
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

// /////////////////////////////////////////////////////////////////////////
// operators
// /////////////////////////////////////////////////////////////////////////

technikum::string technikum::string::operator+(string const& other) const {
    return *this + other.str;
}

technikum::string technikum::string::operator+(char const* s) const {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    technikum::string copy(*this);
    copy.append(s);
    return copy;
}

technikum ::string& technikum::string::operator+=(string const& other) {
    return *this += other.str;
}

technikum::string& technikum::string::operator+=(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    *this = *this + s;
    return *this;
}

technikum::string::operator char*() const {
    return this->str;
}

// /////////////////////////////////////////////////////////////////////////
// members
// /////////////////////////////////////////////////////////////////////////

char const* technikum::string::c_str() const {
    return this->str;
}

size_t technikum::string::length() const {
    return length(this->str);
}

size_t technikum::string::size() const {
    return length();
}

technikum::string& technikum::string::append(char const* s) {
    if (s == nullptr) {
        throw std::logic_error("String cannot be null");
    }

    // "Hello " -> strLength = 6
    size_t strLength = length();
    // "World!" -> sLength = 6
    size_t sLength = length(s);

    // size of newStr = 13
    char* newStr = new char[strLength + sLength + 1];

    // copy "Hello " from H to " " to newStr
    std::copy(this->str, this->str + strLength, newStr);
    // newStr = "Hello XXXXXXX"
    // copy "World!" from W to ! to newStr + 6
    std::copy(s, s + sLength, newStr + strLength);
    // newStr = "Hello World!X"
    newStr[strLength + sLength] = '\0';
    // newStr = "Hello World!\0"

    delete[] this->str;
    this->str = newStr;
    return *this;
}

technikum::string::iterator technikum::string::begin() const {
    return iterator(this->str);
}

technikum::string::iterator technikum::string::end() const {
    return iterator(this->str + length());
}

size_t technikum::string::length(char const* s) {
    size_t length = 0;

    while(s[length] != '\0') {
        length++;
    }

    return length;
}
