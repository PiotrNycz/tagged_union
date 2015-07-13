
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

#ifndef TAGGED_TAGGED_UNION_BASE_COPY_HPP
#define TAGGED_TAGGED_UNION_BASE_COPY_HPP

#include <details/tagged_union_base/type.hpp>
#include <details/indexed_union_operations.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
inline tagged_union_base<TagTraits, Value1, Value...>::tagged_union_base(const tagged_union_base& other)
    : current_tag(other.current_tag),
      data()
{
    details::indexed_union_operations::copy_construct(this->data, other.data, TagTraits::index(this->current_tag));
}

template <typename TagTraits, typename Value1, typename ...Value>
inline tagged_union_base<TagTraits, Value1, Value...>::tagged_union_base(tagged_union_base&& other)
    : current_tag(other.current_tag),
      data()
{
    details::indexed_union_operations::copy_construct(this->data, std::move(other.data), TagTraits::index(this->current_tag));
}

template <typename TagTraits, typename Value1, typename ...Value>
inline auto tagged_union_base<TagTraits, Value1, Value...>::operator = (const tagged_union_base& other) -> tagged_union_base&
{
    details::indexed_union_operations::assign(this->data, TagTraits::index(this->current_tag), other.data, TagTraits::index(other.current_tag));
    this->current_tag = other.current_tag;
    return *this;
}

template <typename TagTraits, typename Value1, typename ...Value>
inline auto tagged_union_base<TagTraits, Value1, Value...>::operator = (tagged_union_base&& other) -> tagged_union_base&
{
    details::indexed_union_operations::assign(this->data, TagTraits::index(this->current_tag), std::move(other.data), TagTraits::index(other.current_tag));
    this->current_tag = other.current_tag;
    return *this;
}

} // namespace exp

#endif // TAGGED_TAGGED_UNION_BASE_COPY_HPP

