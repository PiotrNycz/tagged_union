#pragma once

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
