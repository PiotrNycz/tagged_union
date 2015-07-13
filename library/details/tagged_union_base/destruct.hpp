#pragma once

#include <details/tagged_union_base/type.hpp>
#include <details/indexed_union_operations.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
inline tagged_union_base<TagTraits, Value1, Value...>::~tagged_union_base()
{
    this->destruct();
}

template <typename TagTraits, typename Value1, typename ...Value>
inline void tagged_union_base<TagTraits, Value1, Value...>::destruct()
{
    details::indexed_union_operations::destruct(this->data, TagTraits::index(this->current_tag));
}

} // namespace exp
