#pragma once

#include <details/unrestricted_union/element.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
class tagged_union_base;

template <typename Type, typename TagType, TagType Tag>
struct tagged_union_base_element;

template <typename TagTraits, typename TagTraits::type Tag, typename Value1, typename ...Value>
struct tagged_union_base_element<tagged_union_base<TagTraits, Value1, Value...>, typename TagTraits::type, Tag>
{
    using type = typename unrestricted_union_element<TagTraits::index(Tag), unrestricted_union<Value1, Value...>>::type;
};

template <typename Type, typename TagType, TagType Tag>
using tagged_union_base_element_t = typename tagged_union_base_element<Type, TagType, Tag>::type;

} // namespace exp
