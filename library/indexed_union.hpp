#pragma once

#include <details/tagged_union_base.hpp>
#include <details/index_traits.hpp>

namespace exp
{

template <typename ...Value>
using indexed_union = tagged_union_base<details::index_traits<>, Value...>;

} // namespace exp
