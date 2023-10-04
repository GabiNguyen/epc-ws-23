#include "technikum/string.h"

#include <gtest/gtest.h>

#include <string>

#define SUITE technikum_string

TEST(SUITE, nullptr) {
    ASSERT_THROW(technikum::string(nullptr), std::logic_error);
}

TEST(SUITE, c_str) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_STREQ(string.c_str(), str);
}

TEST(SUITE, str_length_with_strlen) {
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

TEST(SUITE, append) {
    char s1[] = "Hello ";
    char s2[] = "World!";
    technikum::string string(s1);
    string.append(s2);
    ASSERT_STREQ(string.c_str(), "Hello World!");
}

TEST(SUITE, append_empty) {
    char s1[] = "Hello ";
    char s2[] = "";
    technikum::string string(s1);
    string.append(s2);
    ASSERT_STREQ(string.c_str(), "Hello ");
}

TEST(SUITE, append_to_empty) {
    char s1[] = "";
    char s2[] = "World!";
    technikum::string string(s1);
    string.append(s2);
    ASSERT_STREQ(string.c_str(), "World!");
}

TEST(SUITE, append_empty_to_empty) {
    char s1[] = "";
    char s2[] = "";
    technikum::string string(s1);
    string.append(s2);
    ASSERT_STREQ(string.c_str(), "");
}

TEST(SUITE, append_multiple) {
    char s1[] = "Hello ";
    char s2[] = "World!";
    char s3[] = " How are you?";
    technikum::string string(s1);
    string.append(s2).append(s3);
    ASSERT_STREQ(string.c_str(), "Hello World! How are you?");
}

TEST(SUITE, append_nullptr) {
    technikum::string string("Hello ");
    ASSERT_THROW(string.append(nullptr), std::logic_error);
}

TEST(SUITE, copy_constructor) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string copy(string);
    string.append(" How are you?");

    ASSERT_STREQ(string.c_str(), "Hello World! How are you?");
    ASSERT_STREQ(copy.c_str(), str);
}

TEST(SUITE, move_constructor) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string move(std::move(string));

    ASSERT_EQ(string.c_str(), nullptr);
    ASSERT_STREQ(move.c_str(), str);
}

TEST(SUITE, copy_assignment) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string copy = string;
    string.append(" How are you?");

    ASSERT_STREQ(string.c_str(), "Hello World! How are you?");
    ASSERT_STREQ(copy.c_str(), str);
}

TEST(SUITE, move_assignment) {
    char const* str = "Hello World!";
    technikum::string string(str);
    technikum::string move = std::move(string);

    ASSERT_EQ(string.c_str(), nullptr);
    ASSERT_STREQ(move.c_str(), str);
}

TEST(SUITE, plus_operator_string) {
    technikum::string hello("Hello ");
    technikum::string world("World!");
    technikum::string hello_world = hello + world;
    technikum::string hello_world_hello = hello + world + hello;

    ASSERT_STREQ(hello_world.c_str(), "Hello World!");
    ASSERT_STREQ(hello_world_hello.c_str(), "Hello World!Hello ");
    ASSERT_STREQ(hello.c_str(), "Hello ");
    ASSERT_STREQ(world.c_str(), "World!");

    hello.append(" Space!");

    ASSERT_STREQ(hello_world.c_str(), "Hello World!");
}

TEST(SUITE, plus_operator_c_string) {
    technikum::string hello("Hello ");
    technikum::string hello_world = hello + "World!";
    technikum::string hello_world_how_are_you = hello + "World!" + " How are you?";

    ASSERT_STREQ(hello_world.c_str(), "Hello World!");
    ASSERT_STREQ(hello_world_how_are_you.c_str(), "Hello World! How are you?");
}

TEST(SUITE, c_string_conversion_operator) {
    technikum::string hello_world("Hello World!");
    ASSERT_EQ(12, strlen(hello_world));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
