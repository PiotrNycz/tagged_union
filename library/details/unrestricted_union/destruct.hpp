#pragma once

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
