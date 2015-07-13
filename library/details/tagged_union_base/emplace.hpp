#pragma once

#include <details/tagged_union_base/type.hpp>
#include <details/indexed_union_operations.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag, typename ...Arg>
inline auto tagged_union_base<TagTraits, Value1, Value...>::emplace(Arg&&... arg) -> element_type<Tag>&
{
    constexpr auto index = TagTraits::index(Tag);
    static_assert(index < size(), "Tag out of range");
    auto& field_ref = ::exp::get<index>(this->data);
    using field_type = typename std::remove_reference<decltype(field_ref)>::type;

    if (Tag == this->current_tag)
    {
        details::indexed_union_operations::assign_field(field_ref, std::forward<Arg>(arg)...);
    }
    else
    {
        this->destruct();
        this->current_tag = Tag;
        details::indexed_union_operations::construct_field(field_ref, std::forward<Arg>(arg)...);
    }
    return field_ref;
}

} // namespace exp
