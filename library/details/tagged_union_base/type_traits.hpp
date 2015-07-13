
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

#ifndef TAGGED_TAGGED_UNION_BASE_TYPE_TRAITS_HPP
#define TAGGED_TAGGED_UNION_BASE_TYPE_TRAITS_HPP

#include <details/tagged_union_base/type.hpp>

namespace exp
{

template <typename T_>
struct is_tagged_union_base_type : std::false_type {};

template <typename ...T_>
struct is_tagged_union_base_type<tagged_union_base<T_...>> : std::true_type {};

} // namespace exp

#endif // TAGGED_TAGGED_UNION_BASE_TYPE_TRAITS_HPP
