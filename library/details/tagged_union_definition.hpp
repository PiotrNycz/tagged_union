#pragma once

#include <details/tagged_union_definition_base.hpp>


namespace exp
{

namespace details
{
    template <typename TagType, typename ...TagValue>
    struct tagged_union_definition;

    template <typename TagType>
    struct tagged_union_definition<TagType>
    {
        using tag_type = TagType;

        template <typename ...TagValue>
        using data_type = exp::details::tagged_union_definition_base_t<TagType, TagValue...>;
    };


    template <typename TagType, TagType Tag1, typename Value1, typename ...TagValue>
    struct tagged_union_definition<TagType, exp::tag<TagType, Tag1>, Value1, TagValue...>
    {
        using next_definition = tagged_union_definition<TagType, TagValue...>;
        using tag_type = typename next_definition::tag_type;

        template <typename ...PreviousValue>
        using data_type = typename next_definition::template data_type<PreviousValue..., exp::tag<TagType, Tag1>, Value1>;

        using type = data_type<>;

        template <tag_type Tag2>
        struct with
        {
            template <typename Value2>
            using as = tagged_union_definition<tag_type, exp::tag<TagType, Tag1>, Value1, TagValue..., exp::tag<TagType, Tag2>, Value2>;
        };
    };

} // namespace details

} // namespace exp
