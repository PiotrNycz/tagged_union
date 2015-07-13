
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

#ifndef TAGGED_UNRESTRICTED_UNION_DESTRUCT_HPP
#define TAGGED_UNRESTRICTED_UNION_DESTRUCT_HPP

#include <details/unrestricted_union/type.hpp>
#include <details/unrestricted_union/get.hpp>

namespace exp
{

namespace details
{

template <typename Field>
inline void unrestricted_union_destruct_field(Field& field)
{
    field.~Field();
}

} // namespace details

template <std::size_t Index, typename Value1, typename ...Value>
inline void destruct(unrestricted_union<Value1, Value...>& arg)
{
    auto& field_ref = get<Index>(arg);
    details::unrestricted_union_destruct_field(field_ref);
}

} // namespace exp

#endif // TAGGED_UNRESTRICTED_UNION_DESTRUCT_HPP
