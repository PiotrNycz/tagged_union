#pragma once

#include "constructdestructmock.hpp"

namespace exp
{

struct ExampleBase
{
    using Value=int;
    ExampleBase(Value value) : value(value) {}
    virtual ~ExampleBase() {}
    virtual Value getValue() const { return value; }
    Value value;
};

struct Example : ExampleBase
{
    Example(Value value, ConstructDestructMock& constructDestructMock) : ExampleBase(value), constructDestructMock(constructDestructMock)
    {
        constructDestructMock.construct();
    }
    Example(const Example& other) : ExampleBase(other), constructDestructMock(other.constructDestructMock)
    {
        constructDestructMock.copyConstruct();
    }
    Example(Example&& other) : ExampleBase(std::move(other)), constructDestructMock(other.constructDestructMock)
    {
        constructDestructMock.moveConstruct();
    }
    Example& operator = (const Example& other)
    {
        ExampleBase::operator = (other);
        constructDestructMock.copyAssign();
        return *this;
    }
    Example& operator = (Example&& other)
    {
        ExampleBase::operator = (std::move(other));
        constructDestructMock.moveAssign();
        return *this;
    }

    ~Example()
    {
        constructDestructMock.destruct();
    }

    ConstructDestructMock& constructDestructMock;
};
//bool operator < (const ExampleBase& lhs, const ExampleBase& rhs)
//{
//    return lhs.getValue() < rhs.getValue();
//}

} // namespace experimental
