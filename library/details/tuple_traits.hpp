
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

#ifndef TAGGED_DETAILS_TUPLE_TRAITS_HPP
#define TAGGED_DETAILS_TUPLE_TRAITS_HPP

#include <type_traits>

namespace exp
{

namespace details
{

template <typename Value>
struct tuple_traits;

template <template <typename ...> class Tuple, typename Value1, typename ...Value>
struct tuple_traits<Tuple<Value1, Value...>>
{
    static constexpr std::size_t last_index() { return sizeof...(Value); }
    static constexpr std::size_t size() { return last_index() + 1u; }
};

template <template <typename ...> class Tuple>
struct tuple_traits<Tuple<>>
{
    static constexpr std::size_t size() { return 0u; }
};

template <std::size_t Index, typename Tuple>
struct tuple_index_in_range : std::false_type {};

template <std::size_t Index, template <typename...> class Tuple, typename ...Value>
struct tuple_index_in_range<Index, Tuple<Value...>> : std::integral_constant<bool, (Index < tuple_traits<Tuple<Value...>>::size())> {};

} // namespace details

} // namespace exp

#endif // TAGGED_DETAILS_TUPLE_TRAITS_HPP


