#ifndef STRING_H
#define STRING_H

#include <cstddef>

namespace technikum {
    class string {
        public:
            string(char const* s);

            ~string();

            // copy constructor
            string(string const& other);

            // move constructor
            string(string&& other) noexcept;

            // copy assignment
            string& operator=(string const& other);

            // move assignment
            string& operator=(string&& other);

            char const* c_str();

            size_t length();

            size_t size();

            void append(char const* s);

        private:
            char* str;

            static size_t length(char const* s);
            
            size_t str_size;
    };
}

#endif // STRING_H
