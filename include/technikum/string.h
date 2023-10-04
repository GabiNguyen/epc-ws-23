#ifndef STRING_H
#define STRING_H

#include <cstddef>

namespace technikum {
    class string {
        public:
            string(char const* s);

            ~string();

            // copy constructor
            string(string const& other) noexcept;

            // move constructor
            string(string&& other) noexcept;

            // copy assignment
            string& operator=(string const& other) noexcept;

            // move assignment
            string& operator=(string&& other) noexcept;

            string operator+(string const& other) const;
            string operator+(char const* s) const;

            string& operator+=(string const& other);
            string& operator+=(char const* s);

            operator char*() const;

            char const* c_str() const;

            size_t length() const;

            size_t size() const;

            string& append(char const* s);

        private:
            char* str;

            static size_t length(char const* s);
    };
}

#endif // STRING_H
