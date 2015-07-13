
/// \file
// Tagged library
//
//  Copyright Piotr Nycz 2015
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/PiotrNycz/tagged_union
//

#ifndef TAGGED_UNRESTRICTED_UNION_TYPE_HPP
#define TAGGED_UNRESTRICTED_UNION_TYPE_HPP

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

#endif // TAGGED_UNRESTRICTED_UNION_TYPE_HPP
