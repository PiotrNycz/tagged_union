#pragma once

#include <details/unrestricted_union/type.hpp>
#include <cstddef>

namespace exp
{

namespace details
{

template <std::size_t Index, typename Value1, typename ...Value>
struct unrestricted_union_get_field;

template <typename Value1, typename ...Value>
struct unrestricted_union_get_field<0u, Value1, Value...>
{
    static constexpr Value1& get(unrestricted_union<Value1, Value...>& arg) noexcept
    {
        return arg.u.value;
    }
    static constexpr Value1 const & get(const unrestricted_union<Value1, Value...>& arg) noexcept
    {
        return arg.u.value;
    }
    static constexpr Value1&& get(unrestricted_union<Value1, Value...>&& arg) noexcept
    {
        return std::move(arg.u.value);
    }
};

template <std::size_t Index, typename Value1, typename ...Value>
struct unrestricted_union_get_field
{
    static constexpr auto get(unrestricted_union<Value1, Value...>& arg) noexcept -> unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>>&
    {
        return unrestricted_union_get_field<Index - 1, Value...>::get(arg.u.next_values);
    }
    static constexpr auto get(unrestricted_union<Value1, Value...> const& arg) noexcept ->  unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>> const&
    {
        return unrestricted_union_get_field<Index - 1, Value...>::get(arg.u.next_values);
    }
    static constexpr auto get(unrestricted_union<Value1, Value...>&& arg) noexcept ->  unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>>&&
    {
        return unrestricted_union_get_field<Index - 1, Value...>::get(std::move(arg.u.next_values));
    }
};

} // namespace details


template <std::size_t Index, typename Value1, typename ...Value>
inline auto get(unrestricted_union<Value1, Value...>& arg) -> unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>>&
{
    return details::unrestricted_union_get_field<Index, Value1, Value...>::get(arg);
}

template <std::size_t Index, typename Value1, typename ...Value>
inline auto get(unrestricted_union<Value1, Value...> const& arg) -> unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>> const &
{
    return details::unrestricted_union_get_field<Index, Value1, Value...>::get(arg);
}

template <std::size_t Index, typename Value1, typename ...Value>
inline auto get(unrestricted_union<Value1, Value...>&& arg) -> unrestricted_union_element_t<Index, unrestricted_union<Value1, Value...>>&&
{
    return details::unrestricted_union_get_field<Index, Value1, Value...>::get(std::move(arg));
}

} // namespace exp
