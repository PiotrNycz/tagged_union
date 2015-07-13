#pragma once

namespace exp
{

namespace details
{
    template <typename TagType, std::size_t Index1, TagType ...Tag>
    struct tagged_index_traits;

    template <typename TagType, std::size_t Index1>
    struct tagged_index_traits<TagType, Index1>
    {
        using type = TagType;
        static constexpr std::size_t index(type)
        {
            return Index1;
        }
        static constexpr type tag(std::size_t)
        {
            return static_cast<TagType>(Index1);
        }
    };

    template <typename TagType, std::size_t Index1, TagType Tag1, TagType ...Tag>
    struct tagged_index_traits<TagType, Index1, Tag1, Tag...>
    {
        using next_traits = tagged_index_traits<TagType, Index1 + 1u, Tag...>;
        using type = typename next_traits::type;
        static constexpr std::size_t index(type tag)
        {
            return tag == Tag1 ? Index1 : next_traits::index(tag);
        }
        static constexpr type tag(std::size_t index)
        {
            return index == Index1 ? Tag1 : next_traits::tag(index);
        }
    };

} // namespace details

} // namespace exp
