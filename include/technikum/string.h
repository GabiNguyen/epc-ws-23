#ifndef STRING_H
#define STRING_H

namespace technikum {
    class string {
        public:
            string(char const* s);

            // copy constructor
            string(string const& other);

            // move constructor
            string(string&& other);

            // copy assignment
            string& operator=(string const& other);

            // move assignment
            string& operator=(string&& other);

            char const* c_str();

        private:
            char const* str;
    };
}

#endif // STRING_H
