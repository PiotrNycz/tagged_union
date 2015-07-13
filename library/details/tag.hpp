
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

#ifndef TAGGED_TAG_HPP
#define TAGGED_TAG_HPP

namespace exp
{

template <typename Type, Type Value>
struct tag
{
    using type = Type;
    static constexpr type value = Value;
};
template <typename Type, Type Value>
constexpr typename tag<Type, Value>::type tag<Type, Value>::value;

template <typename Type, Type Value>
constexpr tag<Type, Value> make_tag()
{
    return tag<Type, Value>{};
}

} // namespace exp

#endif // TAGGED_TAG_HPP
