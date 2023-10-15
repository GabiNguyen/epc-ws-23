#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace technikum {

    template<typename T>
    class unique_ptr {
        public:
            unique_ptr(T* ptr);
            ~unique_ptr();

            // Copying is not allowed
            unique_ptr(const unique_ptr&) = delete;
            unique_ptr& operator=(const unique_ptr&) = delete;

            // Moving is allowed
            unique_ptr(unique_ptr&& other) noexcept;
            unique_ptr& operator=(unique_ptr&& other) noexcept;

            T* operator->() const;
            T& operator*() const;
            operator bool() const;

        private:
            T* owned_ptr;
    };
}

// /////////////////////////////////////////////////////////////////////////
// rule of five
// /////////////////////////////////////////////////////////////////////////

template<typename T>
technikum::unique_ptr<T>::unique_ptr(T* ptr) : owned_ptr(ptr) {
    // noop
}

template<typename T>
technikum::unique_ptr<T>::~unique_ptr() {
    delete owned_ptr;
}

template<typename T>
technikum::unique_ptr<T>::unique_ptr(unique_ptr&& other) noexcept : owned_ptr(other.owned_ptr) {
    other.owned_ptr = nullptr;
}

template<typename T>
technikum::unique_ptr<T>& technikum::unique_ptr<T>::operator=(unique_ptr&& other) noexcept {
    if (this != &other) {
        delete owned_ptr;
        owned_ptr = other.owned_ptr;
        other.owned_ptr = nullptr;
    }
    return *this;
}

// /////////////////////////////////////////////////////////////////////////
// operators
// /////////////////////////////////////////////////////////////////////////

template<typename T>
T* technikum::unique_ptr<T>::operator->() const {
    return owned_ptr;
}

template<typename T>
T& technikum::unique_ptr<T>::operator*() const {
    return *owned_ptr;
}

template<typename T>
technikum::unique_ptr<T>::operator bool() const {
    return owned_ptr != nullptr;
}

#endif // UNIQUE_PTR_H
