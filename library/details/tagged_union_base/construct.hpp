#pragma once

#include <details/tagged_union_base/type.hpp>
#include <details/tag.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag, typename ...Arg>
inline tagged_union_base<TagTraits, Value1, Value...>::tagged_union_base(
        tag<Tag>,
        Arg&& ...arg)
    : current_tag(Tag)
    , data()
{
    constexpr auto index = TagTraits::index(Tag);
    static_assert(index < size(), "Index out of range");
    ::exp::construct<index>(data, std::forward<Arg>(arg)...);
}

template <typename TagTraits, typename Value1, typename ...Value>
inline tagged_union_base<TagTraits, Value1, Value...>::tagged_union_base()
    : tagged_union_base(make_tag<typename TagTraits::type, TagTraits::tag(0u)>())
{}

} // namespace exp
