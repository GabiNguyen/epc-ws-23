#include "technikum/string.h"

#include <gtest/gtest.h>

#include <string>

#define SUITE technikum_string

TEST(SUITE, c_str) {
    char const* str = "Hello World!";
    technikum::string string(str);
    ASSERT_EQ(string.c_str(), str);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
