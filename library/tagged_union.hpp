#pragma once

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
