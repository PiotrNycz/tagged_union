#pragma once

#include <gmock/gmock.h>

namespace exp
{

struct ConstructDestructMock
{
    MOCK_METHOD0(construct, void());
    MOCK_METHOD0(copyConstruct, void());
    MOCK_METHOD0(moveConstruct, void());
    MOCK_METHOD0(copyAssign, void());
    MOCK_METHOD0(moveAssign, void());
    MOCK_METHOD0(destruct, void());
};

} // namespace experimental
