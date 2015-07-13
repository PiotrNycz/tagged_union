#pragma once

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

