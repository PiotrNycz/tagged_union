
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

#ifndef TAGGED_UNRESTRICTED_UNION_ELEMENT_HPP
#define TAGGED_UNRESTRICTED_UNION_ELEMENT_HPP

#include <type_traits>
#include <details/index.hpp>
#include <details/tuple_traits.hpp>

namespace exp
{

template <typename ...Value>
struct unrestricted_union;

template <std::size_t Index, typename Union>
struct unrestricted_union_element;

template <std::size_t Index, typename Value1, typename ...Value>
struct unrestricted_union_element<Index, unrestricted_union<Value1, Value...>>
{
    using type = typename unrestricted_union_element<Index - 1u, unrestricted_union<Value...>>::type;
};

template <typename Value1, typename ...Value>
struct unrestricted_union_element<0u, unrestricted_union<Value1, Value...>>
{
    using type = typename std::remove_reference<Value1>::type;
};

template <std::size_t Index, typename Union>
using unrestricted_union_element_t = typename unrestricted_union_element<Index, Union>::type;

} // namespace exp

#endif // TAGGED_UNRESTRICTED_UNION_ELEMENT_HPP
