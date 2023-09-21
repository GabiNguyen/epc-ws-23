#ifndef STRING_H
#define STRING_H

namespace technikum {
    class string {
        public:
            string(char const* s);

            char const* c_str();

            int length();

            int size();

            char* append(char* s1, const char* s2);

        private:
            char const* str;
    };
}

#endif // STRING_H
