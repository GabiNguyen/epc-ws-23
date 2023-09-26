#ifndef STRING_H
#define STRING_H

#include <cstddef>

namespace technikum {
    class string {
        public:
            string(char const* s);
            
            ~string();

            char const* c_str() const;

            size_t length() const;

            size_t size() const;

            string* append(char const* s);

        private:
            char* str;

            static size_t length(char const* s);
    };
}

#endif // STRING_H
