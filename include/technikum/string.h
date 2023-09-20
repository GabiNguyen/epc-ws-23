#ifndef STRING_H
#define STRING_H

namespace technikum {
    class string {
        public:
            string(char const* s);

            char const* c_str();

            int length(const char *s);

            int size(const char *s);

        private:
            char const* str;
    };
}

#endif // STRING_H
