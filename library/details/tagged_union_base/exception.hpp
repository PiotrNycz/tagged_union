#pragma once

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
