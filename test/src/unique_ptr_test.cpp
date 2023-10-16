#include "technikum/unique_ptr.h"

#include <gtest/gtest.h>

#define SUITE technikum_unique_ptr

struct Foo {
    int bar = 42;
};

// /////////////////////////////////////////////////////////////////////////
// rule of five
// /////////////////////////////////////////////////////////////////////////

TEST(SUITE, constructor) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    ASSERT_EQ(*unique_ptr, 42);
}

// TEST(SUITE, destructor) { ??? }

TEST(SUITE, move_constructor) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    technikum::unique_ptr<int> move(std::move(unique_ptr));

    ASSERT_FALSE(unique_ptr);
    ASSERT_EQ(*move, 42);
}

TEST(SUITE, move_assignment) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    technikum::unique_ptr<int> move = std::move(unique_ptr);

    ASSERT_FALSE(unique_ptr);
    ASSERT_EQ(*move, 42);
}

// /////////////////////////////////////////////////////////////////////////
// operators
// /////////////////////////////////////////////////////////////////////////

TEST(SUITE, arrow_operator) {
    Foo* ptr = new Foo;
    technikum::unique_ptr<Foo> unique_ptr(ptr);
    ASSERT_EQ(unique_ptr->bar, 42);
}

TEST(SUITE, dereference_operator) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    ASSERT_EQ(*unique_ptr, 42);
}

TEST(SUITE, bool_operator) {
    ASSERT_TRUE(technikum::unique_ptr<int>(new int(42)));
    ASSERT_FALSE(technikum::unique_ptr<int>(nullptr));
}

// /////////////////////////////////////////////////////////////////////////
// functions
// /////////////////////////////////////////////////////////////////////////

TEST(SUITE, release) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    int* released_ptr = unique_ptr.release();
    ASSERT_EQ(released_ptr, ptr);
    ASSERT_FALSE(unique_ptr);
    delete released_ptr;
}

TEST(SUITE, reset) {
    int* ptr = new int(42);
    technikum::unique_ptr<int> unique_ptr(ptr);
    unique_ptr.reset();
    ASSERT_FALSE(unique_ptr);
}

TEST(SUITE, swap) {
    int* ptr = new int(42);
    int* other_ptr = new int(1337);
    technikum::unique_ptr<int> unique_ptr(ptr);
    technikum::unique_ptr<int> other_unique_ptr(other_ptr);
    unique_ptr.swap(other_unique_ptr);
    ASSERT_EQ(*unique_ptr, 1337);
    ASSERT_EQ(*other_unique_ptr, 42);
}