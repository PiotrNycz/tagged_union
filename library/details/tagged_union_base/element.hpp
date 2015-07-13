
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

#ifndef TAGGED_TAGGED_UNION_BASE_ELEMENT_HPP
#define TAGGED_TAGGED_UNION_BASE_ELEMENT_HPP

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

#endif // TAGGED_TAGGED_UNION_BASE_ELEMENT_HPP
