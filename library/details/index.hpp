#pragma once

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

