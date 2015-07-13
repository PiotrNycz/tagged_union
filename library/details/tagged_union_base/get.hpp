
/// \file
// Tagged library
//
//  Copyright Piotr Nycz 2015
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/PiotrNycz/tagged_union
//

#ifndef TAGGED_TAGGED_UNION_BASE_GET_HPP
#define TAGGED_TAGGED_UNION_BASE_GET_HPP

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

#endif // TAGGED_TAGGED_UNION_BASE_GET_HPP
