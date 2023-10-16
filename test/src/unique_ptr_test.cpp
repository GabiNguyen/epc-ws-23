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
