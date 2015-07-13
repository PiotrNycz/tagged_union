#pragma once

#include <details/unrestricted_union/element.hpp>

namespace exp
{

template <typename Value1>
struct unrestricted_union<Value1>
{
    using value_type = Value1;
    union type
    {
        value_type value;

        type() {}
        ~type() {}
    };

    type u;
};

template <typename Value1, typename ...Value>
struct unrestricted_union<Value1, Value...>
{
    using value_type = Value1;
    using next_values_types = unrestricted_union<Value...>;
    union type
    {
        value_type value;
        next_values_types next_values;

        type() {}
        ~type() {}
    };
    type u;
};

} // namespace exp
