
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

#ifndef TAGGED_DETAILS_INDEX_TRAITS_HPP
#define TAGGED_DETAILS_INDEX_TRAITS_HPP

namespace exp
{

namespace details
{
    template <typename IndexType = std::size_t>
    struct index_traits
    {
        using type = IndexType;
        static constexpr std::size_t index(type tag)
        {
            return tag;
        }
        static constexpr type tag(std::size_t index)
        {
            return index;
        }
    };

} // namespace details

} // namespace exp

#endif // TAGGED_DETAILS_INDEX_TRAITS_HPP
