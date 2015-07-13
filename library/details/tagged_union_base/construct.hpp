
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

#ifndef TAGGED_TAGGED_UNION_BASE_CONSTRUCT_HPP
#define TAGGED_TAGGED_UNION_BASE_CONSTRUCT_HPP

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

#endif // TAGGED_TAGGED_UNION_BASE_CONSTRUCT_HPP
