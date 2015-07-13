
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

#ifndef TAGGED_UNRESTRICTED_UNION_CONSTRUCT_HPP
#define TAGGED_UNRESTRICTED_UNION_CONSTRUCT_HPP

#include <details/unrestricted_union/type.hpp>
#include <details/unrestricted_union/get.hpp>
#include <details/unrestricted_union/type_traits.hpp>

namespace exp
{

namespace details
{

template <typename Field, typename ...Arg>
inline auto unrestricted_union_construct_field(Field& field, Arg&&... arg) -> Field&
{
    return *new (&field) Field(std::forward<Arg>(arg)...);
}

} // namespace details

template <std::size_t Index, typename Union, typename ...Arg>
inline auto construct(Union& union_data, Arg&&... arg) -> typename std::enable_if<is_unrestricted_union_type<Union>::value, unrestricted_union_element_t<Index, Union>&>::type
{
    auto& field_data = get<Index>(union_data);
    return details::unrestricted_union_construct_field(field_data, std::forward<Arg>(arg)...);
}

} // namespace exp

#endif // TAGGED_UNRESTRICTED_UNION_CONSTRUCT_HPP
