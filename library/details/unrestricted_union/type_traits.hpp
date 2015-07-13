
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

#ifndef TAGGED_UNRESTRICTED_UNION_TYPE_TRAITS_HPP
#define TAGGED_UNRESTRICTED_UNION_TYPE_TRAITS_HPP

#include <details/unrestricted_union/type.hpp>
#include <type_traits>

namespace exp
{

template <typename>
struct is_unrestricted_union_type : std::false_type {};

template <typename ...Value>
struct is_unrestricted_union_type<unrestricted_union<Value...>> : std::true_type {};

} // namespace exp

#endif // TAGGED_UNRESTRICTED_UNION_TYPE_TRAITS_HPP
