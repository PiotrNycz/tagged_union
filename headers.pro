
LIBHEADERS = ../library
DETAILS = $$LIBHEADERS/details
TAGGED_UNION_BASE = $$DETAILS/tagged_union_base
UNRESTRICTED_UNION = $$DETAILS/unrestricted_union

INCLUDEPATH += $$LIBHEADERS

HEADERS += $$LIBHEADERS/tagged_union.hpp
HEADERS += $$LIBHEADERS/unrestricted_union.hpp
HEADERS += $$LIBHEADERS/indexed_union.hpp

HEADERS += $$DETAILS/tuple_traits.hpp
HEADERS += $$DETAILS/tag.hpp
HEADERS += $$DETAILS/index.hpp
HEADERS += $$DETAILS/tagged_index_traits.hpp
HEADERS += $$DETAILS/index_traits.hpp
HEADERS += $$DETAILS/indexed_union_operations.hpp
HEADERS += $$DETAILS/tagged_union_base.hpp
HEADERS += $$DETAILS/tagged_union_definition_base.hpp
HEADERS += $$DETAILS/tagged_union_definition.hpp


HEADERS += $$TAGGED_UNION_BASE/type.hpp
HEADERS += $$TAGGED_UNION_BASE/type_traits.hpp
HEADERS += $$TAGGED_UNION_BASE/element.hpp
HEADERS += $$TAGGED_UNION_BASE/exception.hpp
HEADERS += $$TAGGED_UNION_BASE/get.hpp
HEADERS += $$TAGGED_UNION_BASE/emplace.hpp
HEADERS += $$TAGGED_UNION_BASE/construct.hpp
HEADERS += $$TAGGED_UNION_BASE/destruct.hpp
HEADERS += $$TAGGED_UNION_BASE/copy.hpp


HEADERS += $$UNRESTRICTED_UNION/type.hpp
HEADERS += $$UNRESTRICTED_UNION/type_traits.hpp
HEADERS += $$UNRESTRICTED_UNION/element.hpp
HEADERS += $$UNRESTRICTED_UNION/get.hpp
HEADERS += $$UNRESTRICTED_UNION/construct.hpp
HEADERS += $$UNRESTRICTED_UNION/destruct.hpp


