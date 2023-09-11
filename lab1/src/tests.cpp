#include <gtest/gtest.h>
#include "foo.h"

TEST(test01, basic_test_set) {
    ASSERT_TRUE(time_calc(100, 10, 910) == 10);
}

TEST(test02, basic_test_set) {
    ASSERT_TRUE(time_calc(100, 10, 460) == 5);
}

TEST(test03, basic_test_set) {
    ASSERT_TRUE(time_calc(0, 0, 100) == -1);
}

TEST(test04, basic_test_set) {
    ASSERT_TRUE(time_calc(-1, 0, 10) == -1);
}

TEST(test05, basic_test_set) {
    ASSERT_TRUE(time_calc(15, -24, -5400) == -1);
}

TEST(test06, basic_test_set) {
    ASSERT_TRUE(time_calc(15, 3, 39) == 3);
}

TEST(test07, basic_test_set) {
    ASSERT_TRUE(time_calc(15, 3, 45) == -1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}