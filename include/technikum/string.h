#ifndef STRING_H
#define STRING_H

namespace technikum {
    class string {
        public:
            string(char const* s);

            char const* c_str();

        private:
            char const* str;
    };
}

#endif // STRING_H
