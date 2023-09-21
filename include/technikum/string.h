#ifndef STRING_H
#define STRING_H

#include <cstddef>

namespace technikum {
    class string {
        public:
            string(char const* s);

            char const* c_str();

            size_t length();

            size_t size();

            void append(char const* s);

        private:
            char* str;

            static size_t length(char const* s);
    };
}

#endif // STRING_H
