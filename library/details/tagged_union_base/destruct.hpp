
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

#ifndef TAGGED_TAGGED_UNION_BASE_DESTRUCT_HPP
#define TAGGED_TAGGED_UNION_BASE_DESTRUCT_HPP

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

#endif // TAGGED_TAGGED_UNION_BASE_DESTRUCT_HPP
