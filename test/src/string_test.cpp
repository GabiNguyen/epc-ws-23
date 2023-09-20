#include "technikum/string.h"

#include <gtest/gtest.h>

#include <string>

#define SUITE technikum_string

TEST(SUITE, c_str) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.c_str(), str);
}

TEST(SUITE, str_length) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.length(str), 12);
}

TEST(SUITE, epmty_str_length) {
    char const* str = "";
    technikum::string string(str);
    ASSERT_EQ(string.length(str), 0);
}

TEST(SUITE, string_size) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.size(str), 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
