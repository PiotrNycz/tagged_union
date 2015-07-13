
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

#ifndef TAGGED_TAGGED_UNION_HPP
#define TAGGED_TAGGED_UNION_HPP

#include <details/tagged_union_definition.hpp>

namespace exp
{

template <typename TagType>
struct tagged_union
{
    using tag_type = TagType;

    template <tag_type Tag>
    struct with
    {
        template <typename Value>
        using as = details::tagged_union_definition<tag_type, tag<tag_type, Tag>, Value>;
    };
};

} // namespace exp

#endif // TAGGED_TAGGED_UNION_HPP
