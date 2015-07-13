#pragma once

#include <details/unrestricted_union/type.hpp>
#include <type_traits>

namespace exp
{

template <typename>
struct is_unrestricted_union_type : std::false_type {};

template <typename ...Value>
struct is_unrestricted_union_type<unrestricted_union<Value...>> : std::true_type {};

} // namespace exp
