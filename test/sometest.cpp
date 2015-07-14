#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct success {};
void assertNumbers(int a, int b)
{
    ASSERT_EQ(a, b);
    throw success{};
}


TEST(A,B)
{
    ASSERT_THROW(assertNumbers(1,2), success);
}
