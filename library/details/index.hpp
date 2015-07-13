
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

#ifndef TAGGED_INDEX_HPP
#define TAGGED_INDEX_HPP

#include <details/tag.hpp>
#include <cstddef>

namespace exp
{

template <std::size_t Value>
using index = tag<std::size_t, Value>;

template <std::size_t Value>
constexpr index<Value> make_index()
{
    return make_tag<std::size_t, Value>();
}

} // namespace exp

#endif // TAGGED_INDEX_HPP
