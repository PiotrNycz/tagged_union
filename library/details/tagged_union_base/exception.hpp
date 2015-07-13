
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

#ifndef TAGGED_TAGGED_UNION_BASE_EXCEPTION_HPP
#define TAGGED_TAGGED_UNION_BASE_EXCEPTION_HPP

#include <stdexcept>

namespace exp
{

template <typename TagTraits>
class tag_not_expected : public std::runtime_error
{
public:
    tag_not_expected(typename TagTraits::type given, typename TagTraits::type expected)
        :   std::runtime_error(build_what(given, expected)),
            given(given),
            expected(expected)
    {}

    typename TagTraits::type given;
    typename TagTraits::type expected;

private:
    static std::string build_what(typename TagTraits::type given, typename TagTraits::type expected)
    {
        return std::to_string(TagTraits::index(given))
                + " given, but expected "
                + std::to_string(TagTraits::index(expected));
    }
};

template <typename TagTraits>
void throw_tag_not_expected(typename TagTraits::type given, typename TagTraits::type expected)
{
    throw tag_not_expected<TagTraits>(given, expected);
}


} // namespace exp

#endif // TAGGED_TAGGED_UNION_BASE_EXCEPTION_HPP
