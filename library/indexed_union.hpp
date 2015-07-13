
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

#ifndef TAGGED_INDEXED_UNION_HPP
#define TAGGED_INDEXED_UNION_HPP

#include <details/tagged_union_base.hpp>
#include <details/index_traits.hpp>

namespace exp
{

template <typename ...Value>
using indexed_union = tagged_union_base<details::index_traits<>, Value...>;

} // namespace exp

#endif // TAGGED_INDEXED_UNION_HPP
