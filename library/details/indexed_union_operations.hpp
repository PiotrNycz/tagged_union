#pragma once

#include <details/tuple_traits.hpp>
#include <unrestricted_union.hpp>

namespace exp
{

namespace details
{

class indexed_union_operations
{
public:

    template <typename Data>
    static void destruct(Data& data, std::size_t index)
    {
        find_and_do<0u>(index, data, destruct_impl());
    }

    template <typename Data, typename Source>
    static void copy_construct(Data& data, Source&& source, std::size_t index)
    {
        find_and_do<0u>(index, data, copy_construct_impl(), std::forward<Source>(source));
    }

    template <typename Data, typename Source>
    static void assign(Data& data, std::size_t data_index, Source&& source, std::size_t source_index)
    {
        if (data_index == source_index)
        {
            find_and_do<0u>(source_index, data, assign_impl(), std::forward<Source>(source));
        }
        else
        {
            destruct(data, data_index);
            copy_construct(data, source, source_index);
        }
    }

    template <typename Field, typename ...Arg>
    static auto assign_field(Field& field, Arg&&... arg) -> Field&
    {
        return field = Field(std::forward<Arg>(arg)...);
    }

    template <typename Field, typename Arg>
    static auto assign_field(Field& field, Arg&& arg) -> Field&
    {
        return field = std::forward<Field>(arg);
    }

    template <typename Field, typename ...Arg>
    static auto construct_field(Field& field, Arg&& ...arg) -> Field&
    {
        return *new (&field) Field(std::forward<Arg>(arg)...);
    }

private:
    template <std::size_t Index, typename Data, typename Operation, typename ...Arg>
    static auto find_and_do(std::size_t index, Data& data, Operation&& operation, Arg&& ...arg) -> typename std::enable_if<(Index < tuple_traits<Data>::size())>::type
    {
        if (index == Index)
        {
            std::forward<Operation>(operation).template perform<Index>(data, std::forward<Arg>(arg)...);
        }
        else
        {
            find_and_do<Index + 1u>(index, data, std::forward<Operation>(operation), std::forward<Arg>(arg)...);
        }
    }

    template <std::size_t Index, typename Data, typename Operation, typename ...Arg>
    static auto find_and_do(std::size_t, Data& data, Operation&& operation, Arg&& ...arg) -> typename std::enable_if<(Index >= tuple_traits<Data>::size())>::type
    {
        // sentinel - out of range
    }

    struct destruct_impl
    {
        template <std::size_t Index, typename Data>
        void perform(Data& data)
        {
            ::exp::destruct<Index>(data);
        }
    };

    struct assign_impl
    {
        template <std::size_t Index, typename Data, typename Source>
        static void perform(Data& data, Source&& source)
        {
            ::exp::get<Index>(data) = ::exp::get<Index>(std::forward<Source>(source));
        }
    };

    struct copy_construct_impl
    {
        template <std::size_t Index, typename Data, typename Source>
        static void perform(Data& data, Source&& source)
        {
            ::exp::construct<Index>(data, ::exp::get<Index>(std::forward<Source>(source)));
        }
    };
};

} // namespace details

} // namespace exp


