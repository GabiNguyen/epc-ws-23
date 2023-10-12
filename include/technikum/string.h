#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <iterator>

namespace technikum {
    class string {
        public:
            // ////////////////////////////////////////////
            // iterator
            // ////////////////////////////////////////////

            class iterator {
                using iterator_category = std::bidirectional_iterator_tag;
                using difference_type   = std::ptrdiff_t;
                using value_type        = char;
                using pointer           = value_type*;
                using reference         = value_type&;

                public:
                    iterator& operator++();
                    iterator operator++(int);

                    iterator& operator--();
                    iterator operator--(int);

                    bool operator!=(iterator const& other) const;
                    bool operator==(iterator const& other) const;

                    reference operator*();
                    reference operator*() const;
                    pointer operator->();
                    pointer operator->() const;

                private:
                    iterator(pointer p);
                    pointer ptr;

                friend string;
            };

            // ////////////////////////////////////////////
            // rule of five
            // ////////////////////////////////////////////

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

            // ////////////////////////////////////////////
            // operators
            // ////////////////////////////////////////////

            string operator+(string const& other) const;
            string operator+(char const* s) const;

            string& operator+=(string const& other);
            string& operator+=(char const* s);

            operator char*() const;

            // ////////////////////////////////////////////
            // members
            // ////////////////////////////////////////////

            char const* c_str() const;

            size_t length() const;

            size_t size() const;

            string& append(char const* s);

            iterator begin() const;

            iterator end() const;

        private:
            char* str;

            static size_t length(char const* s);
    };
}

#endif // STRING_H
