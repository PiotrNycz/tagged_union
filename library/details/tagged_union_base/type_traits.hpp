#pragma once

#include <details/tagged_union_base/type.hpp>

namespace exp
{

template <typename T_>
struct is_tagged_union_base_type : std::false_type {};

template <typename ...T_>
struct is_tagged_union_base_type<tagged_union_base<T_...>> : std::true_type {};

} // namespace exp
