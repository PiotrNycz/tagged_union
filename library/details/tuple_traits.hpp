#pragma once

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


