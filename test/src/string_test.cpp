#include "technikum/string.h"

#include <gtest/gtest.h>

#include <string>

TEST(SUITE, c_str) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.c_str(), str);
}

TEST(SUITE, copy_constructor) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string copy(string);
    ASSERT_EQ(copy.c_str(), str);
}

TEST(SUITE, move_constructor) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string move(std::move(string));
    ASSERT_EQ(move.c_str(), str);
}

TEST(SUITE, copy_assignment) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string copy = string;
    ASSERT_EQ(copy.c_str(), str);
}

TEST(SUITE, move_assignment) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string move = std::move(string);
    ASSERT_EQ(move.c_str(), str);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
