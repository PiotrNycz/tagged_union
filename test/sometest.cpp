#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace ::testing;

#include <stdexcept>

class ISome
{
public:
    virtual ~ISome() {}
    virtual int getA(int c) = 0;
};

class SomeMock : public ISome
{
public:
    MOCK_METHOD1(getA, int(int));
};

class SomeException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

int testedFunction1(ISome& some, int c)
{
    try {
        return some.getA(c);
    } catch (std::runtime_error&) {
        return 0;
    }
}

int testedFunction2(ISome& some, int c)
{
    try {
        return testedFunction1(some, c);
    } catch (SomeException&) {
        return c - 1;
    }
}



class SomeTS : public Test
{
protected:
    StrictMock<SomeMock> someMock;
};

TEST_F(SomeTS, someTC)
{
    const auto c = 12;
    EXPECT_CALL(someMock, getA(c)).WillOnce(Throw(SomeException("Hello CPLANE!")));
    ASSERT_EQ(c - 1, testedFunction2(someMock, c));
}

