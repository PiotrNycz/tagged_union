#pragma once

template <typename T_, T_ V_>
struct ConstExprValue
{
    static constexpr T_ get() { return V_; }
};


