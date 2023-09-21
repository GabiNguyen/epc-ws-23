#include "technikum/string.h"

#include <gtest/gtest.h>

#include <string>

#define SUITE technikum_string

TEST(SUITE, c_str) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.c_str(), str);
}

TEST(SUITE, strlen) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.length(), strlen(str));
}

TEST(SUITE, str_length) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.length(), 12);
}

TEST(SUITE, epmty_str_length) {
    char const* str = "";
    technikum::string string(str);
    ASSERT_EQ(string.length(), 0);
}

TEST(SUITE, string_size) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.size(), 12);
}

/* TEST(SUITE, append) {
    char s1[] = "Hello ";
    char s2[] = "World!";
    technikum::string string(s1);
    ASSERT_EQ(string.append(s1, s2), "Hello World!");
} */

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
