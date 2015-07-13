#pragma once

#include <details/tagged_union_base/type.hpp>
#include <details/tagged_union_base/exception.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag>
inline auto tagged_union_base<TagTraits, Value1, Value...>::get() -> element_type<Tag>&
{
    return ::exp::get<TagTraits::index(Tag)>(this->data);
}

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag>
inline auto tagged_union_base<TagTraits, Value1, Value...>::get() const -> element_type<Tag> const &
{
    return ::exp::get<TagTraits::index(Tag)>(this->data);
}

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag>
inline auto tagged_union_base<TagTraits, Value1, Value...>::at() -> element_type<Tag>&
{
    this->template verify<Tag>();
    return this->template get<Tag>();
}

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag>
inline auto tagged_union_base<TagTraits, Value1, Value...>::at() const -> element_type<Tag> const&
{
    this->template verify<Tag>();
    return this->template get<Tag>();
}

template <typename TagTraits, typename Value1, typename ...Value>
constexpr typename TagTraits::type tagged_union_base<TagTraits, Value1, Value...>::tag_value() const
{
    return current_tag;
}

template <typename TagTraits, typename Value1, typename ...Value>
template <typename TagTraits::type Tag>
void tagged_union_base<TagTraits, Value1, Value...>::verify() const
{
    if (Tag != current_tag)
    {
        throw_tag_not_expected<TagTraits>(Tag, current_tag);
    }
}

} // namespace exp
