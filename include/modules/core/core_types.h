#pragma once


#include <cstdint>
#include <cstddef>


namespace suucat {
namespace detail {

template<typename Type64Bit, typename Type32Bit, int PointerSize>
struct SelectPointerSizeType
{

};


template<typename Type64Bit, typename Type32Bit>
struct SelectPointerSizeType<Type64Bit, Type32Bit, 4>
{
    static_assert(sizeof(Type32Bit) == 4, "pointer size mismatch");
    typedef Type32Bit Type;
};


template<typename Type64Bit, typename Type32Bit>
struct SelectPointerSizeType<Type64Bit, Type32Bit, 8>
{
    static_assert(sizeof(Type64Bit) == 8, "pointer size mismatch");
    typedef Type64Bit Type;
};


} // detail


typedef std::int8_t  int8;
typedef std::int16_t int16;
typedef std::int32_t int32;
typedef std::int64_t int64;

typedef std::uint8_t  uint8;
typedef std::uint16_t uint16;
typedef std::uint32_t uint32;
typedef std::uint64_t uint64;

typedef char ANSICHAR;
typedef wchar_t WIDECHAR;

typedef detail::SelectPointerSizeType<int64, int32, sizeof(void*)>::Type IntPtr;
typedef detail::SelectPointerSizeType<uint64, uint32, sizeof(void*)>::Type UIntPtr;

typedef IntPtr SSIZE_T;
typedef UIntPtr SIZE_T;


} // suucat
