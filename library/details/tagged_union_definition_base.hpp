#pragma once

#include <details/tagged_union_base.hpp>
#include <details/tagged_index_traits.hpp>
#include <details/tag.hpp>
#include <type_traits>
#include <limits>

namespace exp
{

namespace details
{
    template <typename TagType, typename ...TagValue>
    struct tagged_union_definition_base;

    template <typename TagType>
    struct tagged_union_definition_base<TagType>
    {
        template <typename TagTraits, typename ...Value>
        using data_type = exp::tagged_union_base<TagTraits, Value...>;

        template <TagType ...Tag>
        using tag_traits = tagged_index_traits<TagType, 0u, Tag...>;
    };


    template <typename TagType, TagType Tag1, typename Value1, typename ...TagValue>
    struct tagged_union_definition_base<TagType, exp::tag<TagType, Tag1>, Value1, TagValue...>
    {
        using next_definition = tagged_union_definition_base<TagType, TagValue...>;

        template <typename TagTraits, typename ...PreviousValue>
        using data_type = typename next_definition::template data_type<TagTraits, PreviousValue..., Value1>;

        template <TagType ...PreviousTag>
        using tag_traits = typename next_definition::template tag_traits<PreviousTag..., Tag1>;

        using type = data_type<tag_traits<>>;
    };

    template <typename TagType, typename ...TagValue>
    using tagged_union_definition_base_t = typename details::tagged_union_definition_base<TagType, TagValue...>::type;

} // namespace details

} // namespace exp
