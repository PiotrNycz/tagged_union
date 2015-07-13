#pragma once

#include <details/tagged_union_base/element.hpp>
#include <details/tag.hpp>
#include <unrestricted_union.hpp>
#include <details/tuple_traits.hpp>

namespace exp
{

template <typename TagTraits, typename Value1, typename ...Value>
class tagged_union_base
{
public:
    using tag_traits = TagTraits;
    using tag_type = typename tag_traits::type;
    template <tag_type Tag>
    using tag = ::exp::tag<tag_type, Tag>;
    template <tag_type Tag>
    using element_type = tagged_union_base_element_t<tagged_union_base, tag_type, Tag>;
    using data_type = unrestricted_union<Value1, Value...>;

    template <tag_type Tag, typename ...Arg>
    tagged_union_base(tag<Tag>, Arg&& ...arg);
    tagged_union_base();
    ~tagged_union_base();
    tagged_union_base(const tagged_union_base&);
    tagged_union_base(tagged_union_base&&);

    tagged_union_base& operator = (const tagged_union_base&);
    tagged_union_base& operator = (tagged_union_base&&);



    template <tag_type Tag>
    auto get() -> element_type<Tag>&;
    template <tag_type Tag>
    auto get() const -> element_type<Tag> const &;

    template <tag_type Tag>
    auto at() -> element_type<Tag>&;
    template <tag_type Tag>
    auto at() const -> element_type<Tag> const &;


    template <tag_type Tag, typename ...Arg>
    auto emplace(Arg&&... arg) -> element_type<Tag>&;

    constexpr tag_type tag_value() const;
    static constexpr std::size_t size()
    {
        return details::tuple_traits<tagged_union_base>::size();
    }

private:
    void destruct();
    template <tag_type Tag>
    void verify() const;

    tag_type current_tag;
    data_type data;
};

} // namespace exp

