//////////////////////////////////////////////////////////////////////
//                                                                  //
//                  Created by RoseKavalier:                        //
//                  rosekavalierhc@gmail.com                        //
//                                                                  //
//          ***You may use or distribute these files freely         //
//             so long as this notice remains present.***           //
//                                                                  //
//              Automatically generated on: 2023-12-16              //
//                                                                  //
//          In preparing these files, several sources were          //
//            consulted, they are listed in no particular           //
//                          order below.                            //
//                                                                  //
//  Source: https://github.com/potmdehex/homm3tools                 //
//  Author: potmdehex and contributors                              //
//                                                                  //
//  Source: https://github.com/redxu/HoMM3_FA                       //
//  Author: redxu                                                   //
//                                                                  //
//  Source: https://github.com/openhomm/openhomm                    //
//  Author: Ershov Stanislav, Fomin Roman, Akulich Alexander        //
//                                                                  //
//  Source: https://github.com/GrayFace/wog                         //
//  Author: GrayFace and WoG team                                   //
//                                                                  //
//  Source: https://github.com/ethernidee/era                       //
//  Author: Berserker                                               //
//                                                                  //
//  Source: https://github.com/ethernidee/era-editor                //
//  Author: Grayface and Berserker                                  //
//                                                                  //
//  Source: http://wforum.heroes35.net/showthread.php?tid=3900      //
//  Author: Slava and GrayFace                                      //
//                                                                  //
//  Source: http://wforum.heroes35.net/showthread.php?tid=4583      //
//  Author: gamecreator                                             //
//                                                                  //
//  Thanks: patcher_x86 by baratorch and code therein               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

//
//  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄
// ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
// ▐░▌       ▐░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀
// ▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌
// ▐░█▄▄▄▄▄▄▄█░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌
// ▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀      ▐░▌
// ▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌               ▐░▌
// ▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌           ▄▄▄▄█░█▄▄▄▄
// ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░░░░░░░░░░░▌
//  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀            ▀▀▀▀▀▀▀▀▀▀▀
//

// * Note to USERS
// *
// * If you are using MSVC 2017+ and are getting errors
// * with the H3API headers, go to your project's
// * Property Pages. Under the C/C++ options, look
// * for "Conformance mode" and set it as "No".
// * It's a bug that is still not resolved in VS.
// *
// * https://developercommunity.visualstudio.com/content/problem/174539/objbaseh-error-when-compiling-with-permissive-and.html

// *
// * H3API Preprocessor Definitions Overview
// *

// * _H3API_STD_CONVERSIONS_
// * allows conversion between the following formats
// * std::string <<==>> h3::H3String
// * std::vector <<==>> h3::H3Vector

// * _H3API_STD_VECTOR_
// * If you are using Visual Studio 2013 or more recent you can
// * define this preprocessor to use H3StdVector<> which acts as std::vector<>
// * with correct padding and uses H3ObjectAllocator<>

// * _H3API_EXCEPTION_
// * tells the library to include the H3Exception exception handler within your project
// * which is derived from std::exception and may catch SEH errors.
// * your project needs to use /EHa compiler flag to use it.

// * _H3API_DONT_USE_MACROS_
// * tells the library to exclude macros that can pollute the global namespace when defined.
// * these macros are then replaced by typedefs so extra parentheses may be required.
// * if you would like the convenience of switching between both modes, always add parentheses at the end.

// * _H3API_UNPREFIXED_NAMES_
// * H3API structures are always prefixed with H3#### and used so internally.
// * By defining this preprocessor option, declarations will also
// * add an unprefixed typedef so that code may appear less redundant when
// * accessing them from outside the h3 namespace, e.g. h3::Vector vs h3::H3Vector
// * If you prefer 'using namespace h3;' then it may be better to use the prefixed versions
// * to avoid potential conflicts.

// * _H3API_NO_VALIDATION_
// * there are compile-time asserts in H3API to verify
// * structures' sizes and validate some template parameters.
// * define this macro if you do not wish to perform these validations.

// * _H3API_PATCHER_X86_
// * tells the library to include its own "patcher_x86.hpp" header within your project
// * don't use this if you prefer having your own patcher_x86 header.

// * _H3API_PLUGINS_
// * tells the library to include the necessary headers to interact with H3Plugins projects
// * in most cases you won't need this.
#pragma once

#ifdef _H3API_LIBRARY_
	#define _H3API_ // allow function to be compiled
#else
	#define _H3API_ inline // force function to be inline
#endif /* _H3API_LIBRARY_ */

#define _CRT_SECURE_NO_WARNINGS // Prevents some warnings

#ifndef _WINDOWS_
	#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
	#define NOMINMAX // use std::min and std::max instead
	#include <Windows.h>
	#undef NOMINMAX
#endif /* _WINDOWS_ */

#ifdef VOID
	#undef VOID
#endif

#ifdef min
	#undef min // H3API uses std::min
#endif

#ifdef max
	#undef max // H3API uses std::max
#endif

typedef void(*naked_t)();
typedef void(*H3NakedFunction)();
typedef unsigned long h3func;
typedef char          BOOL8;
typedef char          h3unk, h3unk8;
typedef short         h3unk16;
typedef int           h3unk32;
typedef char          h3align;
#ifdef VOID
#undef VOID
#endif

typedef int              INT,    *PINT;
typedef unsigned int     UINT,   *PUINT;
typedef signed char      INT8,   *PINT8;
typedef signed short     INT16,  *PINT16;
typedef signed int       INT32,  *PINT32;
typedef signed __int64   INT64,  *PINT64;
typedef unsigned char    UINT8,  *PUINT8;
typedef unsigned short   UINT16, *PUINT16;
typedef unsigned int     UINT32, *PUINT32;
typedef unsigned __int64 UINT64, *PUINT64;
typedef int              BOOL,    BOOL32;
typedef float            FLOAT;
typedef                  FLOAT   *PFLOAT;
typedef double           DOUBLE;
typedef                  DOUBLE  *PDOUBLE;
typedef char             CHAR;
typedef                  CHAR    *PCHAR;
typedef unsigned char    UCHAR;
typedef                  UCHAR   *PUCHAR;
typedef unsigned char    BYTE;
typedef                  BYTE    *PBYTE;
typedef unsigned short   WORD;
typedef                  WORD    *PWORD;
typedef unsigned long    DWORD;
typedef                  DWORD   *PDWORD;
typedef const char*      LPCSTR;
typedef wchar_t          WCHAR,  *PWCHAR;
typedef const wchar_t*   LPCWSTR;
typedef void             VOID,   *PVOID;

namespace h3
{
	typedef unsigned int ADDRESS;
}

class Patcher;
class PatcherInstance;

#include <algorithm>   // use STL functions instead of C-style
#include <cstdio>      // Input / output functions

#ifndef _LIMITS_
#include <limits>
#endif

#ifndef INT_MIN
	#define INT_MIN  0x80000000
#endif
#ifndef INT_MAX
	#define INT_MAX  0x7FFFFFFF
#endif
#ifndef UINT_MAX
	#define UINT_MAX 0xFFFFFFFF
#endif
#ifndef RAND_MAX
	#define RAND_MAX 0x7fff
#endif
#ifndef SEEK_SET
	#define SEEK_SET 0
#endif
#ifndef SEEK_CUR
	#define SEEK_CUR 1
#endif
#ifndef SEEK_END
	#define SEEK_END 2
#endif

#if (__cplusplus >= 199711L || (_MSC_VER && _MSC_VER >= 1500))
	#define _H3API_CPLUSPLUS98_
#endif

#if (__cplusplus >= 201103L || (_MSC_VER && _MSC_VER >= 1900))
	#define _H3API_CPLUSPLUS11_
#endif

#if (__cplusplus >= 201402L || (_MSC_VER && _MSC_VER >= 1900))
	#define _H3API_CPLUSPLUS14_
#endif

#if (__cplusplus >= 201703L || (_MSC_VER && _MSC_VER >= 1910))
	#define _H3API_CPLUSPLUS17_
#endif

#if (_MSC_VER && _MSC_VER <= 1500)
	#pragma warning (disable:4482)
#endif

#ifndef _H3API_CPLUSPLUS11_
	#ifndef nullptr
		#define nullptr NULL // nullptr was added with C++11
	#endif
	#ifndef constexpr
		#define constexpr const // constexpr was added with C++11
	#endif
	#ifndef _H3API_ENUM_
		#define _H3API_ENUM_ enum // enum class was added with C++11
	#endif
	#ifndef noexcept
		#define noexcept throw() // noexcept keyword added with C++11
	#endif
	#ifndef override
		#define override // override keyword comes with C++11
	#endif
#else
	#ifndef _H3API_ENUM_
		#define _H3API_ENUM_ enum class // enum class
	#endif
#endif

#ifndef _H3API_ENUM_OPERATORS_
	#define _H3API_ENUM_OPERATORS_(ENUM_TYPE, TYPE_SIZE)\
		inline constexpr ENUM_TYPE operator|(ENUM_TYPE a, ENUM_TYPE b) throw()\
		{ return ENUM_TYPE(TYPE_SIZE(a) | TYPE_SIZE(b)); }\
		inline ENUM_TYPE operator|=(ENUM_TYPE& a, ENUM_TYPE b) throw()\
		{ return (ENUM_TYPE&)((TYPE_SIZE&)(a) |= TYPE_SIZE(b)); }\
		inline constexpr ENUM_TYPE operator&(ENUM_TYPE a, ENUM_TYPE b) throw()\
		{ return ENUM_TYPE(TYPE_SIZE(a) & TYPE_SIZE(b)); }\
		inline ENUM_TYPE operator&=(ENUM_TYPE& a, ENUM_TYPE b) throw()\
		{ return (ENUM_TYPE&)((TYPE_SIZE&)(a) &= TYPE_SIZE(b)); }\
		inline constexpr ENUM_TYPE operator^(ENUM_TYPE a, ENUM_TYPE b) throw()\
		{ return ENUM_TYPE(TYPE_SIZE(a) ^ TYPE_SIZE(b)); }\
		inline ENUM_TYPE operator^=(ENUM_TYPE& a, ENUM_TYPE b) throw()\
		{ return (ENUM_TYPE&)(((TYPE_SIZE&)(a)) ^= TYPE_SIZE(b)); }\
		inline constexpr ENUM_TYPE operator~(ENUM_TYPE a) throw()\
		{ return ENUM_TYPE(~TYPE_SIZE(a)); }
#endif

#ifndef _H3API_LIBRARY_
	#ifndef _H3API_DEPRECATED_
		#define _H3API_DEPRECATED_(msg)
	#endif
#else
	#if _MSC_VER && _MSC_VER >= 1900
		#ifndef _H3API_DEPRECATED_
			#define _H3API_DEPRECATED_(msg) [[deprecated(msg)]]
		#endif
	#elif _MSC_VER
		#ifndef _H3API_DEPRECATED_
			#define _H3API_DEPRECATED_(msg) __declspec(deprecated(msg))
		#endif
	#elif defined(__GNUC__) || defined(__clang__)
		#ifndef _H3API_DEPRECATED_
			#define _H3API_DEPRECATED_(msg) __attribute__((deprecated(msg)))
		#endif
	#else
		#pragma message("WARNING: _H3API_DEPRECATED_ is not implemented for this compiler.")
		#ifndef _H3API_DEPRECATED_
			#define _H3API_DEPRECATED_(msg)
		#endif
	#endif
#endif /* _H3API_LIBRARY_ */

#ifndef _H3API_NOVTABLE_
	#define _H3API_NOVTABLE_ __declspec(novtable)
#endif

namespace h3
{
	namespace H3Internal
	{
		_H3API_DEPRECATED_("See original definition to get its replacement.") inline void H3DeprecatedFunctionMessage(LPCSTR newFunction) {}
	} // namespace H3Internal
} // namespace h3

#ifdef _MSC_VER
	#ifndef _H3API_FORCEINLINE_
		#define _H3API_FORCEINLINE_ __forceinline
	#endif
#elif defined(__GNUC__)
	#ifndef _H3API_FORCEINLINE_
		#define _H3API_FORCEINLINE_ inline __attribute__((__always_inline__))
	#endif
#elif defined(__CLANG__)
	#if __has_attribute(__always_inline__)
		#ifndef _H3API_FORCEINLINE_
		#define _H3API_FORCEINLINE_ inline __attribute__((__always_inline__))
		#endif
	#else
		#ifndef _H3API_FORCEINLINE_
			#define _H3API_FORCEINLINE_ inline
		#endif
	#endif
#else
	#ifndef _H3API_FORCEINLINE_
		#define _H3API_FORCEINLINE_ inline
	#endif
#endif

#ifndef _H3API_DECLARE_
	#ifndef _H3API_UNPREFIXED_NAMES_
		#define _H3API_DECLARE_(NAME) struct H3 ## NAME; typedef H3 ## NAME *PH3 ## NAME
	#else
		#define _H3API_DECLARE_(NAME) struct H3 ## NAME; typedef H3 ## NAME *PH3 ## NAME; typedef H3 ## NAME NAME
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif

#ifndef _H3API_TYPE_DECLARE_
	#ifndef _H3API_UNPREFIXED_NAMES_
		#define _H3API_TYPE_DECLARE_(struct_type, NAME) typedef struct_type H3 ## NAME
	#else
		#define _H3API_TYPE_DECLARE_(struct_type, NAME) typedef struct_type H3 ## NAME; typedef struct_type NAME
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif

#ifndef _H3API_TEMPLATE_DECLARE_
	#if defined(_H3API_CPLUSPLUS11_) && defined(_H3API_UNPREFIXED_NAMES_)
		#define _H3API_TEMPLATE_DECLARE_
	#endif /* _H3API_CPLUSPLUS11_ && _H3API_UNPREFIXED_NAMES_ */
#endif /* _H3API_TEMPLATE_DECLARE_ */

#ifndef _H3API_EXPORT_
	#define _H3API_EXPORT_ comment(linker, "/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__)
#endif

#ifndef _H3API_STR_EXPAND_
	#define _H3API_STR_EXPAND_(x) #x // inserts text representation of macro
#endif
#ifndef _H3API_STR_
	#define _H3API_STR_(x) _H3API_STR_EXPAND_(x) // expands a macro into its actual text
#endif

#ifndef _H3API_SIZE_
	#define _H3API_SIZE_(struct_size) static constexpr UINT32 SIZE = struct_size
#endif

#ifndef _H3API_GET_INFO_
	#define _H3API_GET_INFO_(address_pointer, struct_type) \
	static constexpr h3::ADDRESS ADDRESS = address_pointer;\
	static struct_type* Get() { return StructAt<struct_type>(ADDRESS); }\
	typedef struct_type TYPE
#endif

#ifndef _H3API_NAMED_STRUCT_
	#ifndef _H3API_UNPREFIXED_NAMES_
		#define _H3API_NAMED_STRUCT_(struct_type, NAME, address_pointer)\
		struct H3 ## NAME : struct_type { _H3API_GET_INFO_(address_pointer, struct_type); }
	#else
		#define _H3API_NAMED_STRUCT_(struct_type, NAME, address_pointer)\
		struct H3 ## NAME : struct_type { _H3API_GET_INFO_(address_pointer, struct_type); };\
		typedef struct_type NAME;
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif /* _H3API_NAMED_STRUCT_ */

#ifndef _H3API_CTOR_DTOR_
	#define _H3API_CTOR_DTOR_(constructor_address, destructor_address) \
	static constexpr h3func CONSTRUCTOR = constructor_address;\
	static constexpr h3func DESTRUCTOR  = destructor_address
#endif

#ifndef _H3API_VTABLE_
	#define _H3API_VTABLE_(virtual_table_address) \
	static constexpr h3::ADDRESS VTABLE = virtual_table_address
#endif /* define _H3API_VTABLE_ */

namespace h3
{
#ifdef _H3API_CPLUSPLUS11_
	constexpr inline UINT8 operator""_byte(UINT64 value)
	{
		return static_cast<UINT8>(value);
	}
	constexpr inline UINT16 operator""_word(UINT64 value)
	{
		return static_cast<UINT16>(value);
	}
	constexpr inline UINT32 operator""_dword(UINT64 value)
	{
		return static_cast<UINT32>(value);
	}
	constexpr inline UINT8 operator""_u8(UINT64 value)
	{
		return static_cast<UINT8>(value);
	}
	constexpr inline UINT16 operator""_u16(UINT64 value)
	{
		return static_cast<UINT16>(value);
	}
	constexpr inline UINT32 operator""_u32(UINT64 value)
	{
		return static_cast<UINT32>(value);
	}
	constexpr inline INT8 operator""_i8(UINT64 value)
	{
		return static_cast<INT8>(value);
	}
	constexpr inline INT16 operator""_i16(UINT64 value)
	{
		return static_cast<INT16>(value);
	}
	constexpr inline INT32 operator""_i32(UINT64 value)
	{
		return static_cast<INT32>(value);
	}
	constexpr inline ADDRESS operator""_h3(UINT64 value)
	{
		return static_cast<ADDRESS>(value);
	}
#endif // _H3API_CPLUSPLUS11_

	template<typename T>
	T Abs(T value)
	{
		return value >= 0 ? value : -value;
	}

	template<typename T>
	_H3API_FORCEINLINE_ T& ValueAt(ADDRESS address) { return *reinterpret_cast<T*>(address); }

	_H3API_FORCEINLINE_ LPCSTR& StrAt(ADDRESS address) { return ValueAt<LPCSTR>(address); }
	template<typename T>
	_H3API_FORCEINLINE_ UINT32& PtrAt(T data) { return ValueAt<UINT32>(ADDRESS(data)); }
	_H3API_FORCEINLINE_ UINT32& DwordAt(ADDRESS address) { return ValueAt<UINT32>(address); }
	_H3API_FORCEINLINE_ INT32&  IntAt(ADDRESS address) { return ValueAt<INT32>(address); }
	_H3API_FORCEINLINE_ UINT16& WordAt(ADDRESS address) { return ValueAt<UINT16>(address); }
	_H3API_FORCEINLINE_ INT16&  ShortAt(ADDRESS address) { return ValueAt<INT16>(address); }
	_H3API_FORCEINLINE_ UINT8&  ByteAt(ADDRESS address) { return ValueAt<UINT8>(address); }
	_H3API_FORCEINLINE_ INT8&   CharAt(ADDRESS address) { return ValueAt<INT8>(address); }
	_H3API_FORCEINLINE_ FLOAT&  FloatAt(ADDRESS address) { return ValueAt<FLOAT>(address); }
	_H3API_FORCEINLINE_ DOUBLE& DoubleAt(ADDRESS address) { return ValueAt<DOUBLE>(address); }
	_H3API_FORCEINLINE_ h3func  FuncAt(ADDRESS address) { return ValueAt<h3func>(address + 1) + address + 5; }
	template<typename T>
	_H3API_FORCEINLINE_ T* StructAt(ADDRESS address_pointer) { return *reinterpret_cast<T**>(address_pointer); }
	template<typename T>
	_H3API_FORCEINLINE_ ADDRESS AddressOf(const T& value) { return reinterpret_cast<ADDRESS>(&value); }
	template<typename T>
	_H3API_FORCEINLINE_ UINT32 ValueAsDword(T value) { return DwordAt(AddressOf(value)); }
	_H3API_FORCEINLINE_ FLOAT LoadFloatFromFPU()
	{
		FLOAT value = 0;
		__asm FSTP DWORD PTR SS : [value]
		return value;
	}
	_H3API_FORCEINLINE_ VOID StoreToFPU(FLOAT value)
	{
		__asm FLD DWORD PTR SS : [value]
	}
	_H3API_FORCEINLINE_ DOUBLE LoadDoubleFromFPU()
	{
		DOUBLE value = 0;
		__asm FSTP QWORD PTR SS : [value]
		return value;
	}
	_H3API_FORCEINLINE_ VOID StoreToFPU(DOUBLE value)
	{
		__asm FLD QWORD PTR SS : [value]
	}

#ifndef _H3API_STATIC_ASSERT_
	#ifdef _H3API_NO_VALIDATION_
		#define _H3API_STATIC_ASSERT_(condition, message)
	#else
		#ifdef _H3API_CPLUSPLUS11_
			#define _H3API_STATIC_ASSERT_(condition, message) static_assert(condition, message)
		#else /* !_H3API_CPLUSPLUS11_ */
			namespace H3Internal
			{
				template<bool>  struct H3StaticAssert;
				template<>      struct H3StaticAssert<true> {};
				template<int i>	struct H3StaticAssertTest {};
			}
			#define _H3API_CONCATENATE2_(arg1, arg2)  arg1 ## arg2
			#define _H3API_CONCATENATE1_(arg1, arg2)  _H3API_CONCATENATE2_(arg1, arg2)
			#define _H3API_CONCATENATE_(arg1, arg2)   _H3API_CONCATENATE1_(arg1, arg2)
			#define _H3API_STATIC_ASSERT_(condition, message)\
				namespace _H3API_CONCATENATE_(NH3StaticAssert_, __COUNTER__) {\
				struct _H3API_CONCATENATE_(H3StaticAssertion_at_line_, __LINE__)\
				{\
				h3::H3Internal::H3StaticAssert<static_cast<bool>((condition))> _H3API_CONCATENATE_(H3_STATIC_ASSERTION_FAILED_AT_LINE_, __LINE__);\
				};\
				typedef h3::H3Internal::H3StaticAssertTest<sizeof(_H3API_CONCATENATE_(H3StaticAssertion_at_line_, __LINE__))> _H3API_CONCATENATE_(H3StaticAssertionTest_at_line_ , __LINE__); }
		#endif /* _H3API_CPLUSPLUS11_ */
	#endif /* _H3API_NO_VALIDATION_ */
#endif /* _H3API_STATIC_ASSERT_ */

#ifndef _H3API_ASSERT_SIZE_
	#define _H3API_ASSERT_SIZE_(name) _H3API_STATIC_ASSERT_(sizeof(name) == name::SIZE, #name " size is incorrect")
#endif /* _H3API_ASSERT_SIZE_ */

#ifndef _H3API_ASSERT_OFFSET_
	#define _H3API_ASSERT_OFFSET_(name, member, offset) _H3API_STATIC_ASSERT_(offsetof(name, member) == offset, #name "::" #member " offset invalid")
#endif

	namespace H3Internal
	{
		template<bool condition, class T = VOID>
		struct enable_if {};
		template<class T>
		struct enable_if<true, T> { typedef T type; };
		template<class T>
		struct remove_pointer { typedef T type; };
		template<class T>
		struct remove_pointer<T*> { typedef T type; };
		template<class T>
		struct remove_pointer<T* const> { typedef T type; };
		template<class T>
		struct remove_pointer<T* volatile> { typedef T type; };
		template<class T>
		struct remove_pointer<T* const volatile> { typedef T type; };
	}

#pragma region Function_Templates
	namespace H3Internal
	{
#pragma region Stdcall_Templates
		template<typename return_type>
		inline return_type H3Stdcall_0(UINT address)
		{
			return (reinterpret_cast<return_type(__stdcall*)()>(address)());
		}
		template<typename return_type, typename Arg1>
		inline return_type H3Stdcall_1(UINT address, Arg1 a1)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1)>(address)(a1));
		}
		template<typename return_type, typename Arg1, typename Arg2>
		inline return_type H3Stdcall_2(UINT address, Arg1 a1, Arg2 a2)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2)>(address)(a1, a2));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3>
		inline return_type H3Stdcall_3(UINT address, Arg1 a1, Arg2 a2, Arg3 a3)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3)>(address)(a1, a2, a3));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		inline return_type H3Stdcall_4(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4)>(address)(a1, a2, a3, a4));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		inline return_type H3Stdcall_5(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5)>(address)(a1, a2, a3, a4, a5));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		inline return_type H3Stdcall_6(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>(address)(a1, a2, a3, a4, a5, a6));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		inline return_type H3Stdcall_7(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)>(address)(a1, a2, a3, a4, a5, a6, a7));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
		inline return_type H3Stdcall_8(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)>(address)(a1, a2, a3, a4, a5, a6, a7, a8));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
		inline return_type H3Stdcall_9(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
		inline return_type H3Stdcall_10(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
		inline return_type H3Stdcall_11(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
		inline return_type H3Stdcall_12(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
		inline return_type H3Stdcall_13(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
		inline return_type H3Stdcall_14(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
		inline return_type H3Stdcall_15(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
		inline return_type H3Stdcall_16(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
		inline return_type H3Stdcall_17(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
		inline return_type H3Stdcall_18(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
		inline return_type H3Stdcall_19(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19, typename Arg20>
		inline return_type H3Stdcall_20(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19, Arg20 a20)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20));
		}
#pragma endregion
#pragma region Thiscall_Templates
		template<typename return_type>
		inline return_type H3Thiscall_0(UINT address)
		{
			return (reinterpret_cast<return_type(__thiscall*)()>(address)());
		}
		template<typename return_type, typename Arg1>
		inline return_type H3Thiscall_1(UINT address, Arg1 a1)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1)>(address)(a1));
		}
		template<typename return_type, typename Arg1, typename Arg2>
		inline return_type H3Thiscall_2(UINT address, Arg1 a1, Arg2 a2)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2)>(address)(a1, a2));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3>
		inline return_type H3Thiscall_3(UINT address, Arg1 a1, Arg2 a2, Arg3 a3)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3)>(address)(a1, a2, a3));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		inline return_type H3Thiscall_4(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4)>(address)(a1, a2, a3, a4));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		inline return_type H3Thiscall_5(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5)>(address)(a1, a2, a3, a4, a5));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		inline return_type H3Thiscall_6(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>(address)(a1, a2, a3, a4, a5, a6));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		inline return_type H3Thiscall_7(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)>(address)(a1, a2, a3, a4, a5, a6, a7));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
		inline return_type H3Thiscall_8(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)>(address)(a1, a2, a3, a4, a5, a6, a7, a8));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
		inline return_type H3Thiscall_9(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
		inline return_type H3Thiscall_10(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
		inline return_type H3Thiscall_11(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
		inline return_type H3Thiscall_12(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
		inline return_type H3Thiscall_13(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
		inline return_type H3Thiscall_14(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
		inline return_type H3Thiscall_15(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
		inline return_type H3Thiscall_16(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
		inline return_type H3Thiscall_17(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
		inline return_type H3Thiscall_18(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
		inline return_type H3Thiscall_19(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19, typename Arg20>
		inline return_type H3Thiscall_20(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19, Arg20 a20)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20));
		}
#pragma endregion
#pragma region Fastcall_Templates
		template<typename return_type>
		inline return_type H3Fastcall_0(UINT address)
		{
			return (reinterpret_cast<return_type(__fastcall*)()>(address)());
		}
		template<typename return_type, typename Arg1>
		inline return_type H3Fastcall_1(UINT address, Arg1 a1)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1)>(address)(a1));
		}
		template<typename return_type, typename Arg1, typename Arg2>
		inline return_type H3Fastcall_2(UINT address, Arg1 a1, Arg2 a2)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2)>(address)(a1, a2));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3>
		inline return_type H3Fastcall_3(UINT address, Arg1 a1, Arg2 a2, Arg3 a3)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3)>(address)(a1, a2, a3));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		inline return_type H3Fastcall_4(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4)>(address)(a1, a2, a3, a4));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		inline return_type H3Fastcall_5(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5)>(address)(a1, a2, a3, a4, a5));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		inline return_type H3Fastcall_6(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>(address)(a1, a2, a3, a4, a5, a6));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		inline return_type H3Fastcall_7(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)>(address)(a1, a2, a3, a4, a5, a6, a7));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
		inline return_type H3Fastcall_8(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)>(address)(a1, a2, a3, a4, a5, a6, a7, a8));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
		inline return_type H3Fastcall_9(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
		inline return_type H3Fastcall_10(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
		inline return_type H3Fastcall_11(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
		inline return_type H3Fastcall_12(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
		inline return_type H3Fastcall_13(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
		inline return_type H3Fastcall_14(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
		inline return_type H3Fastcall_15(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
		inline return_type H3Fastcall_16(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
		inline return_type H3Fastcall_17(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
		inline return_type H3Fastcall_18(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
		inline return_type H3Fastcall_19(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19, typename Arg20>
		inline return_type H3Fastcall_20(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19, Arg20 a20)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20));
		}
#pragma endregion
#pragma region Cdecl_Templates
		template<typename return_type>
		inline return_type H3Cdecl_0(UINT address)
		{
			return (reinterpret_cast<return_type(__cdecl*)()>(address)());
		}
		template<typename return_type, typename Arg1>
		inline return_type H3Cdecl_1(UINT address, Arg1 a1)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1)>(address)(a1));
		}
		template<typename return_type, typename Arg1, typename Arg2>
		inline return_type H3Cdecl_2(UINT address, Arg1 a1, Arg2 a2)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2)>(address)(a1, a2));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3>
		inline return_type H3Cdecl_3(UINT address, Arg1 a1, Arg2 a2, Arg3 a3)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3)>(address)(a1, a2, a3));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		inline return_type H3Cdecl_4(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4)>(address)(a1, a2, a3, a4));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		inline return_type H3Cdecl_5(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5)>(address)(a1, a2, a3, a4, a5));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		inline return_type H3Cdecl_6(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>(address)(a1, a2, a3, a4, a5, a6));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		inline return_type H3Cdecl_7(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)>(address)(a1, a2, a3, a4, a5, a6, a7));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
		inline return_type H3Cdecl_8(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)>(address)(a1, a2, a3, a4, a5, a6, a7, a8));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
		inline return_type H3Cdecl_9(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
		inline return_type H3Cdecl_10(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
		inline return_type H3Cdecl_11(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
		inline return_type H3Cdecl_12(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
		inline return_type H3Cdecl_13(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
		inline return_type H3Cdecl_14(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
		inline return_type H3Cdecl_15(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
		inline return_type H3Cdecl_16(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
		inline return_type H3Cdecl_17(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
		inline return_type H3Cdecl_18(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
		inline return_type H3Cdecl_19(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19));
		}
		template<typename return_type, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19, typename Arg20>
		inline return_type H3Cdecl_20(UINT address, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5, Arg6 a6, Arg7 a7, Arg8 a8, Arg9 a9, Arg10 a10, Arg11 a11, Arg12 a12, Arg13 a13, Arg14 a14, Arg15 a15, Arg16 a16, Arg17 a17, Arg18 a18, Arg19 a19, Arg20 a20)
		{
			return (reinterpret_cast<return_type(__cdecl*)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20)>(address)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20));
		}
#pragma endregion
	} /* namespace H3Internal */
#pragma endregion

#pragma region Model Functions macros
#pragma region STDCALL_DECLARATIONS
#ifndef STDCALL_0
#define STDCALL_0(return_type, address) h3::H3Internal::H3Stdcall_0<return_type>(UINT(address))
#endif
#ifndef STDCALL_1
#define STDCALL_1(return_type, address, arg1) h3::H3Internal::H3Stdcall_1<return_type>(UINT(address), arg1)
#endif
#ifndef STDCALL_2
#define STDCALL_2(return_type, address, arg1, arg2) h3::H3Internal::H3Stdcall_2<return_type>(UINT(address), arg1, arg2)
#endif
#ifndef STDCALL_3
#define STDCALL_3(return_type, address, arg1, arg2, arg3) h3::H3Internal::H3Stdcall_3<return_type>(UINT(address), arg1, arg2, arg3)
#endif
#ifndef STDCALL_4
#define STDCALL_4(return_type, address, arg1, arg2, arg3, arg4) h3::H3Internal::H3Stdcall_4<return_type>(UINT(address), arg1, arg2, arg3, arg4)
#endif
#ifndef STDCALL_5
#define STDCALL_5(return_type, address, arg1, arg2, arg3, arg4, arg5) h3::H3Internal::H3Stdcall_5<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5)
#endif
#ifndef STDCALL_6
#define STDCALL_6(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6) h3::H3Internal::H3Stdcall_6<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6)
#endif
#ifndef STDCALL_7
#define STDCALL_7(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7) h3::H3Internal::H3Stdcall_7<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#endif
#ifndef STDCALL_8
#define STDCALL_8(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) h3::H3Internal::H3Stdcall_8<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#endif
#ifndef STDCALL_9
#define STDCALL_9(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) h3::H3Internal::H3Stdcall_9<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
#endif
#ifndef STDCALL_10
#define STDCALL_10(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) h3::H3Internal::H3Stdcall_10<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
#endif
#ifndef STDCALL_11
#define STDCALL_11(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) h3::H3Internal::H3Stdcall_11<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
#endif
#ifndef STDCALL_12
#define STDCALL_12(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) h3::H3Internal::H3Stdcall_12<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
#endif
#ifndef STDCALL_13
#define STDCALL_13(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) h3::H3Internal::H3Stdcall_13<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
#endif
#ifndef STDCALL_14
#define STDCALL_14(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) h3::H3Internal::H3Stdcall_14<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
#endif
#ifndef STDCALL_15
#define STDCALL_15(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) h3::H3Internal::H3Stdcall_15<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
#endif
#ifndef STDCALL_16
#define STDCALL_16(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) h3::H3Internal::H3Stdcall_16<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16)
#endif
#ifndef STDCALL_17
#define STDCALL_17(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) h3::H3Internal::H3Stdcall_17<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
#endif
#ifndef STDCALL_18
#define STDCALL_18(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) h3::H3Internal::H3Stdcall_18<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18)
#endif
#ifndef STDCALL_19
#define STDCALL_19(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) h3::H3Internal::H3Stdcall_19<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19)
#endif
#ifndef STDCALL_20
#define STDCALL_20(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) h3::H3Internal::H3Stdcall_20<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20)
#endif
#pragma endregion
#pragma region THISCALL_DECLARATIONS
#ifndef THISCALL_0
#define THISCALL_0(return_type, address) h3::H3Internal::H3Thiscall_0<return_type>(UINT(address))
#endif
#ifndef THISCALL_1
#define THISCALL_1(return_type, address, arg1) h3::H3Internal::H3Thiscall_1<return_type>(UINT(address), arg1)
#endif
#ifndef THISCALL_2
#define THISCALL_2(return_type, address, arg1, arg2) h3::H3Internal::H3Thiscall_2<return_type>(UINT(address), arg1, arg2)
#endif
#ifndef THISCALL_3
#define THISCALL_3(return_type, address, arg1, arg2, arg3) h3::H3Internal::H3Thiscall_3<return_type>(UINT(address), arg1, arg2, arg3)
#endif
#ifndef THISCALL_4
#define THISCALL_4(return_type, address, arg1, arg2, arg3, arg4) h3::H3Internal::H3Thiscall_4<return_type>(UINT(address), arg1, arg2, arg3, arg4)
#endif
#ifndef THISCALL_5
#define THISCALL_5(return_type, address, arg1, arg2, arg3, arg4, arg5) h3::H3Internal::H3Thiscall_5<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5)
#endif
#ifndef THISCALL_6
#define THISCALL_6(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6) h3::H3Internal::H3Thiscall_6<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6)
#endif
#ifndef THISCALL_7
#define THISCALL_7(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7) h3::H3Internal::H3Thiscall_7<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#endif
#ifndef THISCALL_8
#define THISCALL_8(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) h3::H3Internal::H3Thiscall_8<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#endif
#ifndef THISCALL_9
#define THISCALL_9(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) h3::H3Internal::H3Thiscall_9<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
#endif
#ifndef THISCALL_10
#define THISCALL_10(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) h3::H3Internal::H3Thiscall_10<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
#endif
#ifndef THISCALL_11
#define THISCALL_11(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) h3::H3Internal::H3Thiscall_11<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
#endif
#ifndef THISCALL_12
#define THISCALL_12(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) h3::H3Internal::H3Thiscall_12<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
#endif
#ifndef THISCALL_13
#define THISCALL_13(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) h3::H3Internal::H3Thiscall_13<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
#endif
#ifndef THISCALL_14
#define THISCALL_14(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) h3::H3Internal::H3Thiscall_14<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
#endif
#ifndef THISCALL_15
#define THISCALL_15(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) h3::H3Internal::H3Thiscall_15<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
#endif
#ifndef THISCALL_16
#define THISCALL_16(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) h3::H3Internal::H3Thiscall_16<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16)
#endif
#ifndef THISCALL_17
#define THISCALL_17(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) h3::H3Internal::H3Thiscall_17<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
#endif
#ifndef THISCALL_18
#define THISCALL_18(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) h3::H3Internal::H3Thiscall_18<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18)
#endif
#ifndef THISCALL_19
#define THISCALL_19(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) h3::H3Internal::H3Thiscall_19<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19)
#endif
#ifndef THISCALL_20
#define THISCALL_20(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) h3::H3Internal::H3Thiscall_20<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20)
#endif
#pragma endregion
#pragma region FASTCALL_DECLARATIONS
#ifndef FASTCALL_0
#define FASTCALL_0(return_type, address) h3::H3Internal::H3Fastcall_0<return_type>(UINT(address))
#endif
#ifndef FASTCALL_1
#define FASTCALL_1(return_type, address, arg1) h3::H3Internal::H3Fastcall_1<return_type>(UINT(address), arg1)
#endif
#ifndef FASTCALL_2
#define FASTCALL_2(return_type, address, arg1, arg2) h3::H3Internal::H3Fastcall_2<return_type>(UINT(address), arg1, arg2)
#endif
#ifndef FASTCALL_3
#define FASTCALL_3(return_type, address, arg1, arg2, arg3) h3::H3Internal::H3Fastcall_3<return_type>(UINT(address), arg1, arg2, arg3)
#endif
#ifndef FASTCALL_4
#define FASTCALL_4(return_type, address, arg1, arg2, arg3, arg4) h3::H3Internal::H3Fastcall_4<return_type>(UINT(address), arg1, arg2, arg3, arg4)
#endif
#ifndef FASTCALL_5
#define FASTCALL_5(return_type, address, arg1, arg2, arg3, arg4, arg5) h3::H3Internal::H3Fastcall_5<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5)
#endif
#ifndef FASTCALL_6
#define FASTCALL_6(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6) h3::H3Internal::H3Fastcall_6<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6)
#endif
#ifndef FASTCALL_7
#define FASTCALL_7(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7) h3::H3Internal::H3Fastcall_7<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#endif
#ifndef FASTCALL_8
#define FASTCALL_8(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) h3::H3Internal::H3Fastcall_8<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#endif
#ifndef FASTCALL_9
#define FASTCALL_9(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) h3::H3Internal::H3Fastcall_9<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
#endif
#ifndef FASTCALL_10
#define FASTCALL_10(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) h3::H3Internal::H3Fastcall_10<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
#endif
#ifndef FASTCALL_11
#define FASTCALL_11(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) h3::H3Internal::H3Fastcall_11<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
#endif
#ifndef FASTCALL_12
#define FASTCALL_12(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) h3::H3Internal::H3Fastcall_12<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
#endif
#ifndef FASTCALL_13
#define FASTCALL_13(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) h3::H3Internal::H3Fastcall_13<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
#endif
#ifndef FASTCALL_14
#define FASTCALL_14(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) h3::H3Internal::H3Fastcall_14<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
#endif
#ifndef FASTCALL_15
#define FASTCALL_15(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) h3::H3Internal::H3Fastcall_15<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
#endif
#ifndef FASTCALL_16
#define FASTCALL_16(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) h3::H3Internal::H3Fastcall_16<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16)
#endif
#ifndef FASTCALL_17
#define FASTCALL_17(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) h3::H3Internal::H3Fastcall_17<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
#endif
#ifndef FASTCALL_18
#define FASTCALL_18(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) h3::H3Internal::H3Fastcall_18<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18)
#endif
#ifndef FASTCALL_19
#define FASTCALL_19(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) h3::H3Internal::H3Fastcall_19<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19)
#endif
#ifndef FASTCALL_20
#define FASTCALL_20(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) h3::H3Internal::H3Fastcall_20<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20)
#endif
#pragma endregion
#pragma region CDECL_DECLARATIONS
#ifndef CDECL_0
#define CDECL_0(return_type, address) h3::H3Internal::H3Cdecl_0<return_type>(UINT(address))
#endif
#ifndef CDECL_1
#define CDECL_1(return_type, address, arg1) h3::H3Internal::H3Cdecl_1<return_type>(UINT(address), arg1)
#endif
#ifndef CDECL_2
#define CDECL_2(return_type, address, arg1, arg2) h3::H3Internal::H3Cdecl_2<return_type>(UINT(address), arg1, arg2)
#endif
#ifndef CDECL_3
#define CDECL_3(return_type, address, arg1, arg2, arg3) h3::H3Internal::H3Cdecl_3<return_type>(UINT(address), arg1, arg2, arg3)
#endif
#ifndef CDECL_4
#define CDECL_4(return_type, address, arg1, arg2, arg3, arg4) h3::H3Internal::H3Cdecl_4<return_type>(UINT(address), arg1, arg2, arg3, arg4)
#endif
#ifndef CDECL_5
#define CDECL_5(return_type, address, arg1, arg2, arg3, arg4, arg5) h3::H3Internal::H3Cdecl_5<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5)
#endif
#ifndef CDECL_6
#define CDECL_6(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6) h3::H3Internal::H3Cdecl_6<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6)
#endif
#ifndef CDECL_7
#define CDECL_7(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7) h3::H3Internal::H3Cdecl_7<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#endif
#ifndef CDECL_8
#define CDECL_8(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) h3::H3Internal::H3Cdecl_8<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#endif
#ifndef CDECL_9
#define CDECL_9(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) h3::H3Internal::H3Cdecl_9<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
#endif
#ifndef CDECL_10
#define CDECL_10(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) h3::H3Internal::H3Cdecl_10<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
#endif
#ifndef CDECL_11
#define CDECL_11(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) h3::H3Internal::H3Cdecl_11<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
#endif
#ifndef CDECL_12
#define CDECL_12(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) h3::H3Internal::H3Cdecl_12<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
#endif
#ifndef CDECL_13
#define CDECL_13(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) h3::H3Internal::H3Cdecl_13<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
#endif
#ifndef CDECL_14
#define CDECL_14(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) h3::H3Internal::H3Cdecl_14<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
#endif
#ifndef CDECL_15
#define CDECL_15(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) h3::H3Internal::H3Cdecl_15<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
#endif
#ifndef CDECL_16
#define CDECL_16(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) h3::H3Internal::H3Cdecl_16<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16)
#endif
#ifndef CDECL_17
#define CDECL_17(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) h3::H3Internal::H3Cdecl_17<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
#endif
#ifndef CDECL_18
#define CDECL_18(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) h3::H3Internal::H3Cdecl_18<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18)
#endif
#ifndef CDECL_19
#define CDECL_19(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) h3::H3Internal::H3Cdecl_19<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19)
#endif
#ifndef CDECL_20
#define CDECL_20(return_type, address, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) h3::H3Internal::H3Cdecl_20<return_type>(UINT(address), arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20)
#endif
#pragma endregion
#pragma region VA_DECLARATIONS

#ifdef _H3API_CPLUSPLUS11_
	namespace h3vargs
	{
		template<typename return_type, typename ...Args>
		return_type Stdcall_Variadic(UINT address, Args... args)
		{
			return (reinterpret_cast<return_type(__stdcall*)(Args...)>(address))(args...);
		}
		template<typename return_type, typename ...Args>
		return_type Thiscall_Variadic(UINT address, Args... args)
		{
			return (reinterpret_cast<return_type(__thiscall*)(Args...)>(address))(args...);
		}
		template<typename return_type, typename ...Args>
		return_type Fastcall_Variadic(UINT address, Args... args)
		{
			return (reinterpret_cast<return_type(__fastcall*)(Args...)>(address))(args...);
		}
	}
	#ifndef STDCALL_VA
		#define STDCALL_VA(return_type, address, ...) h3vargs::Stdcall_Variadic<return_type>(address, __VA_ARGS__)
	#endif
	#ifndef THISCALL_VA
		#define THISCALL_VA(return_type, address, ...) h3vargs::Thiscall_Variadic<return_type>(address, __VA_ARGS__)
	#endif
	#ifndef FASTCALL_VA
		#define FASTCALL_VA(return_type, address, ...) h3vargs::Fastcall_Variadic<return_type>(address, __VA_ARGS__)
	#endif
#endif /* _H3API_CPLUSPLUS11_ */

#ifndef CDECL_VA
	#define CDECL_VA(return_type, address, a1, ...) ((return_type(__cdecl *)(UINT, ...))(address))((UINT)(a1), __VA_ARGS__)
#endif
#ifndef CDECL_VA2
	#define CDECL_VA2(return_type, address, a1, a2, ...) ((return_type(__cdecl *)(UINT, UINT, ...))(address))((UINT)(a1), (UINT)(a2), __VA_ARGS__)
#endif

#pragma endregion
#pragma endregion Model Functions macros

	class H3Uncopyable
	{
	public:
		H3Uncopyable() {}
	private:
#ifdef _H3API_CPLUSPLUS11_
		H3Uncopyable(const H3Uncopyable&) = delete;
		H3Uncopyable& operator=(const H3Uncopyable&) = delete;
#else
		H3Uncopyable(const H3Uncopyable&);
		H3Uncopyable& operator=(const H3Uncopyable&);
#endif /* _H3API_CPLUSPLUS11_ */
	};
	template<class type>
	class H3DataPointer : public H3Uncopyable
	{
	public:
		typedef type* pointer;
		typedef type& reference;
		_H3API_FORCEINLINE_ H3DataPointer() :
			m_address(getAddress())
		{
		}
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		pointer operator->() { return reinterpret_cast<pointer>(m_address); }
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		H3DataPointer<type>& operator()() { return *this; }
#endif
		operator pointer() { return reinterpret_cast<pointer>(m_address); }
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

	template<class type>
	class H3DataArrayPointer : public H3Uncopyable
	{
	public:
		typedef type* pointer;
		typedef type& reference;
		_H3API_FORCEINLINE_ H3DataArrayPointer() :
			m_address(getAddress())
		{
		}
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		pointer operator->() { return reinterpret_cast<pointer>(m_address); }
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		H3DataArrayPointer<type>& operator()() { return *this; }
#endif
		operator pointer*() { return reinterpret_cast<pointer*>(m_address); }
		reference operator[](UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
		reference operator[](INT index) { return reinterpret_cast<pointer>(m_address)[static_cast<UINT>(index)]; }
		pointer operator()(UINT index) { return &reinterpret_cast<pointer>(m_address)[index]; }

#ifdef _H3API_CPLUSPLUS11_
		explicit operator pointer() { return *reinterpret_cast<pointer>(m_address); }
#endif

	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

	template<class type>
	class H3PrimitivePointer : public H3Uncopyable
	{
	public:
		typedef typename type::VALUE_TYPE* pointer;
		typedef typename type::VALUE_TYPE& reference;
		typedef typename type::VALUE_TYPE  value_type;
		_H3API_FORCEINLINE_ H3PrimitivePointer() :
			m_address(getAddress())
		{
		}
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		H3PrimitivePointer<type/*, value_type*/>& operator()() { return *this; }
#endif
		operator value_type() { return *reinterpret_cast<pointer>(m_address); }
		void operator=(value_type new_data) { *reinterpret_cast<pointer>(m_address) = new_data; }
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return type::ADDRESS; }
	};

	template<typename type>
	class H3PrimitiveArrayPointer : public H3Uncopyable
	{
	public:
		typedef typename H3Internal::remove_pointer<typename type::VALUE_TYPE>::type value_type;
		typedef value_type* pointer;
		typedef value_type& reference;

		_H3API_FORCEINLINE_ H3PrimitiveArrayPointer() :
			m_address(getAddress())
		{
		}
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }

#ifndef _H3API_DONT_USE_MACROS_
		H3PrimitiveArrayPointer<type>& operator()() { return *this; }
#endif
		operator pointer*() { return reinterpret_cast<pointer*>(m_address); }
		reference operator[](UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
		reference operator[](INT index) { return reinterpret_cast<pointer>(m_address)[static_cast<UINT>(index)]; }
		value_type operator()(UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
#ifdef _H3API_CPLUSPLUS11_
		explicit operator pointer() { return *reinterpret_cast<pointer>(m_address); }
#endif
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

} /* namespace h3 */

namespace h3
{
	struct H3POINT;
	_H3API_DECLARE_(Point);
	_H3API_DECLARE_(Position);
	template<typename T> class H3Map;
	template<typename T> class H3FastMap;

	typedef H3Map<UINT16>     H3Map_UINT16;
	typedef H3FastMap<UINT16> H3FastMap_UINT16;

	LPCSTR const h3_NullString = LPCSTR(0x63A608);
	PCHAR  const h3_TextBuffer = PCHAR(0x697428);
	LPCSTR const h3_GamePath   = LPCSTR(0x698614);
	PCHAR  const h3_SaveName   = PCHAR(0x69FC88);

	class H3Version
	{
	public:
		_H3API_ENUM_ GameVersion : INT32
		{
			UNKNOWN         = -1,
			ROE             = 0,
			SOD             = 1,
			SOD_POLISH_GOLD = 2,
			HOTA            = 3,
			ERA             = 4,
			WOG             = 5,
		};
		_H3API_ H3Version();
		_H3API_ GameVersion version() const;
		_H3API_ BOOL roe()  const;
		_H3API_ BOOL sod()  const;
		_H3API_ BOOL hota() const;
		_H3API_ BOOL era()  const;
		_H3API_ BOOL wog()  const;
	private:
		GameVersion m_version;
	};

	namespace H3Numbers
	{
		_H3API_ INT32 AddCommas(INT32 num, CHAR* out);
		_H3API_ INT32 MakeReadable(INT32 num, CHAR* out, INT32 decimals = 1);
	}

	namespace H3Error
	{
		_H3API_ VOID ShowError(LPCSTR message, LPCSTR title = "H3Error!");
		_H3API_ BOOL ShowErrorChoice(LPCSTR message, LPCSTR title = "H3Error!");
		_H3API_ VOID ShowErrorW(LPCWSTR message, LPCWSTR title = L"H3Error!");
		_H3API_ BOOL ShowErrorChoiceW(LPCWSTR message, LPCWSTR title = L"H3Error!");
	}

#pragma pack(push, 4)

	struct H3POINT
	{
		INT32 x, y;

		_H3API_ H3POINT();
		_H3API_ H3POINT(INT32 x, INT32 y);
		_H3API_ H3POINT(const H3POINT& other);
		_H3API_ H3POINT(const ::POINT& point);
		_H3API_ BOOL     operator==(const H3POINT& other) const;
		_H3API_ BOOL     operator!=(const H3POINT& other) const;
		_H3API_ H3POINT& operator=(const  H3POINT& other);
		_H3API_ H3POINT& operator=(const  ::POINT& point);
		_H3API_ H3POINT& IncX(INT32 dx = 1);
		_H3API_ H3POINT& IncY(INT32 dy = 1);
		_H3API_ H3POINT& DecX(INT32 dx = 1);
		_H3API_ H3POINT& DecY(INT32 dy = 1);
		_H3API_ H3POINT& operator+(const H3POINT& other);
		_H3API_ H3POINT& operator-(const H3POINT& other);
		_H3API_ VOID     Clamp(INT32 map_size);
		_H3API_ VOID     Clamp();
		_H3API_ H3POINT& GetCurrentCursorPosition();

		_H3API_ static H3POINT GetCursorPosition();
		_H3API_ static VOID    GetCursorPosition(INT32& x, INT32& y);
		_H3API_ static VOID    GetCursorPosition(H3POINT& p);
	};

	struct H3Point
	{
		INT32 x;
		INT32 y;
		INT32 z;

		_H3API_ H3Point();
		_H3API_ H3Point(INT32 x, INT32 y, INT32 z);
		_H3API_ H3Point(const H3Point& pt);
		_H3API_ H3Point(const H3Position& pos);
		_H3API_ H3Point& operator=(const H3Point& pt);
		_H3API_ H3Point& operator=(const H3Position& pos);
		_H3API_ BOOL     operator==(const H3Point& pt) const;
		_H3API_ BOOL     operator==(const H3Position& pos) const;
		_H3API_ BOOL     operator!=(const H3Point& pt) const;
		_H3API_ BOOL     operator!=(const H3Position& pos) const;
		_H3API_ UINT32   Pack() const;
		_H3API_ VOID     Clamp(INT32 map_size);
		_H3API_ VOID     Clamp();
		_H3API_ H3Point& IncX(INT32 dx = 1);
		_H3API_ H3Point& IncY(INT32 dy = 1);
		_H3API_ H3Point& DecX(INT32 dx = 1);
		_H3API_ H3Point& DecY(INT32 dy = 1);
	}; /* H3Point */

	struct H3Position
	{
	protected:
		UINT pos;
	public:
		_H3API_ H3Position();
		_H3API_ H3Position(UINT32 mixed_position);
		_H3API_ H3Position(const H3Position& other);
		_H3API_ H3Position(INT16 x, INT16 y, INT8 z);
		_H3API_ H3Position(const H3Point& pt);
		_H3API_ VOID operator=(const H3Position& other);
		_H3API_ VOID operator=(const H3Point& pt);
		_H3API_ VOID operator=(UINT32 mixed_position);
		_H3API_ BOOL operator==(const H3Position& other) const;
		_H3API_ BOOL operator==(const H3Point& other) const;
		_H3API_ BOOL operator!=(const H3Position& other) const;
		_H3API_ BOOL operator!=(const H3Point& other) const;
		_H3API_ UINT32 operator*() const;
		_H3API_ operator UINT () const;
		_H3API_ UINT Mixed() const;
		_H3API_ UINT GetX() const;
		_H3API_ UINT GetY() const;
		_H3API_ UINT8 GetZ() const;
		_H3API_ VOID GetXYZ(INT& x, INT& y, INT& z) const;
		_H3API_ VOID SetX(INT16 x);
		_H3API_ VOID SetY(INT16 y);
		_H3API_ VOID SetZ(INT16 z);
		_H3API_ VOID SetXYZ(INT x, INT y, INT z);
		_H3API_ H3Point Unpack() const;
		_H3API_ static UINT Pack(INT x, INT y, INT z);
		_H3API_ static UINT Pack(const H3Point& pt);
		_H3API_ static VOID UnpackXYZ(UINT coord, INT& x, INT& y, INT& z);
		_H3API_ static UINT UnpackX(UINT coord);
		_H3API_ static UINT UnpackY(UINT coord);
		_H3API_ static UINT8 UnpackZ(UINT coord);
	}; /* H3Position */

	template<typename T>
	class H3Map
	{
	public:
		typedef T* pointer;
		typedef T& reference;

		class iterator
		{
		public:
			iterator(const iterator& it);
			iterator(H3Map* map, UINT x, UINT y, UINT z);
			iterator(H3Map* map, pointer item);
			BOOL      operator==(const iterator& it) const;
			BOOL      operator!=(const iterator& it) const;
			iterator& operator++();
			iterator  operator++(int);
			pointer   operator->() const;
			pointer   operator&() const;
			reference operator*() const;
			reference operator()(INT32 dx, INT32 dy) const;
			UINT      GetX() const;
			UINT      GetY() const;
			UINT      GetZ() const;
			H3Point   Get() const;
		private:
			pointer m_current;
			UINT    m_x;
			UINT    m_y;
			UINT    m_z;
			H3Map* m_map;
		};
		H3Map(pointer base, UINT map_size, BOOL has_underground);
		iterator begin();
		iterator end();
		iterator operator()(UINT x, UINT y, UINT z);
		reference At(UINT x, UINT y, UINT z);

	private:
		pointer at(UINT x, UINT y, UINT z);

		pointer m_base;
		UINT    m_dimensions;
		UINT    m_levels;
	};

	template<typename T>
	class H3FastMap
	{
	public:
		typedef T* pointer;
		typedef T& reference;

		class iterator
		{
		public:
			iterator(const iterator& it);
			iterator(H3FastMap* map, UINT x, UINT y, UINT z);
			iterator(pointer item, UINT map_size);
			BOOL      operator==(const iterator& it) const;
			BOOL      operator!=(const iterator& it) const;
			iterator& operator++();
			iterator  operator++(int);
			reference operator()(INT32 dx, INT32 dy) const;
			reference operator*() const;
			pointer   operator&() const;
			pointer   operator->() const;
		private:
			pointer m_current;
			UINT    m_dimensions;
		};

		H3FastMap(pointer base, UINT map_size, BOOL has_underground);
		iterator  begin();
		iterator  end();
		iterator  operator()(UINT x, UINT y, UINT z);
		reference At(UINT x, UINT y, UINT z);
		H3Point   GetCoordinates(const iterator& it) const;
		H3Point   GetCoordinates(const pointer item) const;
	private:
		pointer at(UINT x, UINT y, UINT z);

		pointer m_base;
		UINT    m_dimensions;
		UINT    m_levels;
	};
#pragma pack(pop) /* align-4 */

	template<typename T>
	inline H3Map<T>::iterator::iterator(const iterator& it) :
		m_current(it.m_current),
		m_x(it.m_x),
		m_y(it.m_y),
		m_z(it.m_z),
		m_map(it.m_map)
	{
	}
	template<typename T>
	inline H3Map<T>::iterator::iterator(H3Map* map, UINT x, UINT y, UINT z) :
		m_current(map->at(x, y, z)),
		m_x(x),
		m_y(y),
		m_z(z),
		m_map(map)
	{
	}
	template<typename T>
	inline H3Map<T>::iterator::iterator(H3Map* map, pointer item) :
		m_current(item),
		m_map(map)
	{
		UINT delta = item - map->m_base;
		m_x = delta % map->m_dimensions;
		delta /= map->m_dimensions;
		m_y = delta % map->m_dimensions;
		m_z = delta / map->m_dimensions;
	}
	template<typename T>
	inline BOOL H3Map<T>::iterator::operator==(const iterator& it) const
	{
		return m_current == it.m_current;
	}
	template<typename T>
	inline BOOL H3Map<T>::iterator::operator!=(const iterator& it) const
	{
		return m_current != it.m_current;
	}
	template<typename T>
	inline typename H3Map<T>::iterator& H3Map<T>::iterator::operator++()
	{
		++m_current;
		if (++m_x < m_map->m_dimensions)
			return *this;
		m_x = 0;
		if (++m_y < m_map->m_dimensions)
			return *this;
		m_y = 0;
		++m_z;
		return *this;
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::iterator::operator++(int)
	{
		iterator it(*this);
		++(*this);
		return it;
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::iterator::operator->() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::iterator::operator&() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::iterator::operator*() const
	{
		return *m_current;
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::iterator::operator()(INT32 dx, INT32 dy) const
	{
		return m_current[dx + m_map->m_dimensions * dy];
	}

	template<typename T>
	inline UINT H3Map<T>::iterator::GetX() const
	{
		return m_x;
	}
	template<typename T>
	inline UINT H3Map<T>::iterator::GetY() const
	{
		return m_y;
	}
	template<typename T>
	inline UINT H3Map<T>::iterator::GetZ() const
	{
		return m_z;
	}
	template<typename T>
	inline H3Point H3Map<T>::iterator::Get() const
	{
		return H3Point(m_x, m_y, m_z);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::begin()
	{
		return iterator(this, 0, 0, 0);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::end()
	{
		return iterator(this, 0, 0, m_levels);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::operator()(UINT x, UINT y, UINT z)
	{
		return iterator(this, x, y, z);
	}
	template<typename T>
	inline H3Map<T>::H3Map(pointer base, UINT map_size, BOOL has_underground) :
		m_base(base),
		m_dimensions(map_size),
		m_levels(has_underground ? 2 : 1)
	{
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::At(UINT x, UINT y, UINT z)
	{
		return *at(x, y, z);
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::at(UINT x, UINT y, UINT z)
	{
		return &m_base[x + m_dimensions * (y + z * m_dimensions)];
	}

	template<typename T>
	inline BOOL H3FastMap<T>::iterator::operator==(const iterator& it) const
	{
		return m_current == it.m_current;
	}

	template<typename T>
	inline BOOL H3FastMap<T>::iterator::operator!=(const iterator& it) const
	{
		return m_current != it.m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::iterator& H3FastMap<T>::iterator::operator++()
	{
		++m_current;
		return *this;
	}

	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::iterator::operator++(int)
	{
		iterator it(*this);
		++m_current;
		return it;
	}

	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::iterator::operator()(INT32 dx, INT32 dy) const
	{
		return m_current[dx + m_dimensions * dy];
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(const iterator& it) :
		m_current(it.m_current),
		m_dimensions(it.m_dimensions)
	{
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(H3FastMap* map, UINT x, UINT y, UINT z) :
		m_current(map->at(x, y, z)),
		m_dimensions(map->m_dimensions)
	{
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(pointer item, UINT map_size) :
		m_current(item),
		m_dimensions(map_size)
	{
	}

	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::iterator::operator*() const
	{
		return *m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::iterator::operator&() const
	{
		return m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::iterator::operator->() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::begin()
	{
		return iterator(this, 0, 0, 0);
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::end()
	{
		return iterator(this, 0, 0, m_levels);
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::operator()(UINT x, UINT y, UINT z)
	{
		return iterator(this, x, y, z);
	}
	template<typename T>
	inline H3FastMap<T>::H3FastMap(pointer base, UINT map_size, BOOL has_underground) :
		m_base(base),
		m_dimensions(map_size),
		m_levels(has_underground ? 2 : 1)
	{
	}
	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::At(UINT x, UINT y, UINT z)
	{
		return *at(x, y, z);
	}
	template<typename T>
	inline H3Point H3FastMap<T>::GetCoordinates(const iterator& it) const
	{
		return GetCoordinates(&it);
	}
	template<typename T>
	inline H3Point H3FastMap<T>::GetCoordinates(const pointer item) const
	{
		H3Point p;
		UINT delta = item - m_base;
		p.x        = delta % m_dimensions;
		delta     /= m_dimensions;
		p.y        = delta % m_dimensions;
		p.z        = delta / m_dimensions;
		return p;
	}
	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::at(UINT x, UINT y, UINT z)
	{
		return &m_base[x + m_dimensions * (y + z * m_dimensions)];
	}

} /* namespace h3 */

namespace h3
{
	template <typename T> struct H3ObjectAllocator;
	template <typename T> struct H3ArrayAllocator;
	template <typename T> struct H3AutoPtr;
	template <typename T, typename Allocator> struct H3UniquePtr;
#ifdef _H3API_TEMPLATE_DECLARE_
	template <typename T>
	using ObjectAllocator = H3ObjectAllocator<T>;
	template <typename T>
	using ArrayAllocator  = H3ArrayAllocator<T>;
	template <typename T>
	using AutoPtr         = H3AutoPtr<T>;
	template <typename T, typename Allocator>
	using UniquePtr       = H3UniquePtr<T, Allocator>;
#endif /* _H3API_TEMPLATE_DECLARE_ */

	typedef H3ObjectAllocator<BYTE> ByteAllocator;
	typedef H3ObjectAllocator<CHAR> CharAllocator;

#pragma pack(push, 4)

	_H3API_ PVOID H3Realloc(PVOID obj, UINT new_size);
	_H3API_ PVOID H3Calloc(UINT count, UINT size = 1);
	_H3API_ PVOID H3Malloc(UINT size);
	_H3API_ VOID H3Free(PVOID obj);
	template<typename Type>
	inline Type* H3Alloc(UINT count = 1);

	struct H3Allocator
	{
		_H3API_ static PVOID operator new(const size_t sz);
		_H3API_ static VOID  operator delete(PVOID block);
		_H3API_ static PVOID operator new[](const size_t sz);
		_H3API_ static VOID  operator delete[](PVOID block);
	};

	template <typename T>
	struct H3ObjectAllocator
	{
		typedef T        value_type;
		typedef T*       pointer;
		typedef const T* const_pointer;
		typedef T&       reference;
		typedef const T& const_reference;
		typedef size_t   size_type;

		H3ObjectAllocator() noexcept;
		T* allocate(size_t number = 1) const noexcept;
		VOID deallocate(T* block) const noexcept;
		VOID deallocate(T* block, size_t number) const noexcept;
		VOID construct(T* block) const noexcept;
		VOID construct(T* block, const T& value) const noexcept;
		template<typename U>
		VOID construct(T* block, const U& arg) const noexcept;
		VOID destroy(T* block) const noexcept;
		template <typename U>
		H3ObjectAllocator(const H3ObjectAllocator<U>&) noexcept;
		template <typename U>
		bool operator==(const H3ObjectAllocator<U>&) const noexcept;
		template <typename U>
		bool operator!=(const H3ObjectAllocator<U>&) const noexcept;

#ifdef _H3API_CPLUSPLUS11_
		template<typename... Args>
		VOID construct(T* block, Args&&... args);
#endif
	};

	template <typename T>
	struct H3ArrayAllocator
	{
		typedef T        value_type;
		typedef T*       pointer;
		typedef const T* const_pointer;
		typedef T&       reference;
		typedef const T& const_reference;
		typedef size_t   size_type;
	private:
		size_t* getArrayBase(T* block) const noexcept;
		size_t getArraySize(T* block) const noexcept;
	public:
		H3ArrayAllocator() noexcept;
		T* allocate(size_t number = 1) const noexcept;
		VOID deallocate(T* block) const noexcept;
		VOID construct(T* block) const noexcept;
		VOID construct(T* block, const T& value) const noexcept;
		template<typename U>
		VOID construct(T* block, const U& arg) const noexcept;
		VOID destroy(T* block) const noexcept;
		template <typename U>
		H3ArrayAllocator(const H3ArrayAllocator<U>&) noexcept;
		template <typename U>
		bool operator==(const H3ArrayAllocator<U>&) const noexcept;
		template <typename U>
		bool operator!=(const H3ArrayAllocator<U>&) const noexcept;

#ifdef _H3API_CPLUSPLUS11_
		template<typename... Args>
		VOID construct(T* block, Args&&... args);
#endif
	};
#pragma pack(push, 4)
	template<typename T>
	struct H3AutoPtr
	{
		_H3API_SIZE_(0x8);
	protected:
		BOOL8 m_used;
		T*    m_data;
	public:
		H3AutoPtr(T* _Ptr = 0);
		~H3AutoPtr();
		T* Get();
		T* operator->();
		T* Release();
		BOOL8 Exists() const;
		operator BOOL() const;
		BOOL operator!() const;
		T& operator*() const;
	}; /* H3AutoPtr<> */
	_H3API_ASSERT_SIZE_(H3AutoPtr<h3unk>);
#pragma pack(pop)

	template<typename T, typename Allocator = H3ObjectAllocator<T>>
	struct H3UniquePtr
	{
	protected:
		T* data;
		void destroy(T* block = nullptr);

	public:
		H3UniquePtr();
		H3UniquePtr(T* source);
		~H3UniquePtr();
		void Set(T* source);
		T* Get();
		T* operator->();
		T* Release();
		void Swap(H3UniquePtr<T>& other);
		BOOL operator!() const;
		operator BOOL() const;

#ifdef _H3API_CPLUSPLUS11_
		H3UniquePtr(H3UniquePtr<T, Allocator>&& other);
		H3UniquePtr<T, Allocator>& operator=(H3UniquePtr<T, Allocator>&& other);
		H3UniquePtr<T, Allocator>& operator=(const H3UniquePtr<T, Allocator>& other) = delete;
#else
	private:
		H3UniquePtr<T, Allocator>& operator=(H3UniquePtr<T, Allocator>& other);
#endif
	}; /* H3UniquePtr<> */

#pragma pack(pop) /* align-4 */

#ifdef _H3API_CPLUSPLUS11_

	namespace H3Internal
	{

		template<typename T, typename Allocator>
		struct H3UniqueIf
		{
			typedef H3UniquePtr<T, Allocator> SingleObject;
		};

		template<typename T, typename Allocator>
		struct H3UniqueIf<T[], Allocator>
		{
			typedef H3UniquePtr<T[], Allocator> UnknownBound;
		};

		template<typename T, typename Allocator, size_t N>
		struct H3UniqueIf<T[N], Allocator>
		{
			typedef void KnownBound;
		};
	} /* H3Internal */

	template<typename T, typename Allocator = H3ObjectAllocator<T>, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::SingleObject
		MakeUnique(Args&&... args)
	{
		H3UniquePtr<T, Allocator> ptr(Allocator().allocate());
		Allocator().construct(ptr.Get(), std::forward<Args>(args)...);
		return ptr;
	}

	template<typename T, typename Allocator = H3ArrayAllocator<T>, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::UnknownBound
		MakeUnique(size_t n)
	{
		H3UniquePtr<T> ptr(Allocator().allocate(n));
		Allocator().construct(ptr.Get());
		return ptr;
	}

	template<typename T, typename Allocator, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::KnownBound
		MakeUnique(Args&&...) = delete;

#endif /* _H3API_CPLUSPLUS11_ */

	template<typename T>
	inline H3ObjectAllocator<T>::H3ObjectAllocator() noexcept
	{
	}
	template<typename T>
	inline T* H3ObjectAllocator<T>::allocate(size_t number) const noexcept
	{
		return reinterpret_cast<T*>(H3Malloc(number * sizeof(T)));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::deallocate(T* block) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(block));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::deallocate(T* block, size_t number) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(block));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::construct(T* block) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T();
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::construct(T* block, const T& value) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T(value);
	}
	template<typename T>
	template<typename U>
	inline VOID H3ObjectAllocator<T>::construct(T* block, const U& arg) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T(arg);
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::destroy(T* block) const noexcept
	{
		block->~T();
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T>
	template<typename ...Args>
	inline VOID H3ObjectAllocator<T>::construct(T* block, Args && ...args)
	{
		::new(reinterpret_cast<PVOID>(block)) T(std::forward<Args>(args)...);
	}
#endif

	template<typename T>
	inline size_t* H3ArrayAllocator<T>::getArrayBase(T* block) const noexcept
	{
		return reinterpret_cast<size_t*>(block) - 1;
	}
	template<typename T>
	inline size_t H3ArrayAllocator<T>::getArraySize(T* block) const noexcept
	{
		return *getArrayBase(block);
	}
	template<typename T>
	inline H3ArrayAllocator<T>::H3ArrayAllocator() noexcept
	{
	}
	template<typename T>
	inline T* H3ArrayAllocator<T>::allocate(size_t number) const noexcept
	{
		size_t* block = reinterpret_cast<size_t*>(H3Malloc(number * sizeof(T) + sizeof(size_t)));
		*block = number;
		return reinterpret_cast<T*>(block + 1);
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::deallocate(T* block) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(getArrayBase(block)));
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::construct(T* block) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			new(reinterpret_cast<PVOID>(block)) T();
			++block;
		}
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::construct(T* block, const T& value) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(value);
			++block;
		}
	}
	template<typename T>
	template<typename U>
	inline VOID H3ArrayAllocator<T>::construct(T* block, const U& arg) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(arg);
			++block;
		}
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::destroy(T* block) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			block->~T();
			++block;
		}
	}
	template<typename T>
	template<typename U>
	inline H3ObjectAllocator<T>::H3ObjectAllocator(const H3ObjectAllocator<U>&) noexcept
	{
	}
	template<typename T>
	template<typename U>
	inline bool H3ObjectAllocator<T>::operator==(const H3ObjectAllocator<U>&) const noexcept
	{
		return TRUE;
	}
	template<typename T>
	template<typename U>
	inline bool H3ObjectAllocator<T>::operator!=(const H3ObjectAllocator<U>&) const noexcept
	{
		return FALSE;
	}
	template<typename T>
	template<typename U>
	inline H3ArrayAllocator<T>::H3ArrayAllocator(const H3ArrayAllocator<U>&) noexcept
	{
	}

	template<typename T>
	template<typename U>
	inline bool H3ArrayAllocator<T>::operator==(const H3ArrayAllocator<U>&) const noexcept
	{
		return true;
	}

	template<typename T>
	template<typename U>
	inline bool H3ArrayAllocator<T>::operator!=(const H3ArrayAllocator<U>&) const noexcept
	{
		return false;
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T>
	template<typename ...Args>
	inline VOID H3ArrayAllocator<T>::construct(T* block, Args && ...args)
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(std::forward<Args>(args)...);
			++block;
		}
	}
#endif
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::destroy(T* replacement)
	{
		if (replacement && replacement == data)
			return;
		if (data)
		{
			Allocator().destroy(data);
			Allocator().deallocate(data);
			data = nullptr;
		}
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr() :
		data()
	{
	}

	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr(T* source) :
		data(source)
	{
		source = nullptr;
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::~H3UniquePtr()
	{
		destroy();
	}
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::Set(T* source)
	{
		destroy(source); // check we aren't releasing ourselves
		data = source;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::Get()
	{
		return data;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::operator->()
	{
		return data;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::Release()
	{
		T* r = data;
		data = nullptr;
		return r;
	}
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::Swap(H3UniquePtr<T>& other)
	{
		T* tmp = data;
		data = other.data;
		other.data = tmp;
	}
	template<typename T, typename Allocator>
	inline BOOL H3UniquePtr<T, Allocator>::operator!() const
	{
		return data == nullptr;
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::operator BOOL() const
	{
		return data != nullptr;
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr(H3UniquePtr<T, Allocator>&& other) :
		data(other.Release())
	{
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>& H3UniquePtr<T, Allocator>::operator=(H3UniquePtr<T, Allocator>&& other)
	{
		if (&other == this)
			return *this;

		destroy();
		data = other.Release();

		return *this;
	}
#endif

	template<typename T>
	inline H3AutoPtr<T>::H3AutoPtr(T* _Ptr) :
		m_used(_Ptr != 0),
		m_data(_Ptr)
	{
	}

	template<typename T>
	inline H3AutoPtr<T>::~H3AutoPtr()
	{
		if (m_used)
		{
			delete m_data;
			m_used = FALSE;
		}
	}

	template<typename T>
	inline T* H3AutoPtr<T>::Get()
	{
		return m_data;
	}

	template<typename T>
	inline T* H3AutoPtr<T>::operator->()
	{
		return m_data;
	}

	template<typename T>
	inline T* H3AutoPtr<T>::Release()
	{
		T* ptr = m_data;
		m_used = FALSE;
		m_data = nullptr;
		return ptr;
	}
	template<typename T>
	inline BOOL8 H3AutoPtr<T>::Exists() const
	{
		return m_used;
	}
	template<typename T>
	inline H3AutoPtr<T>::operator BOOL() const
	{
		return m_used != FALSE;
	}
	template<typename T>
	inline BOOL H3AutoPtr<T>::operator!() const
	{
		return m_used == FALSE;
	}
	template<typename T>
	inline T& H3AutoPtr<T>::operator*() const
	{
		return *m_data;
	}
	template<typename Type>
	inline Type* H3Alloc(UINT count)
	{
		return reinterpret_cast<Type*>(H3Malloc(sizeof(Type) * count));
	}
}

namespace h3
{
	_H3API_DECLARE_(Bitfield);
	_H3API_DECLARE_(ObjectMask);
	_H3API_DECLARE_(PlayersBitfield);
	_H3API_DECLARE_(PlayersBitfield32);
	_H3API_DECLARE_(TownsBitfield);
	_H3API_DECLARE_(BuildingsBitfield);
	_H3API_DECLARE_(TerrainBitfield);

#pragma pack(push, 4)

	struct H3Bitfield
	{
		struct reference
		{
		protected:
			H3Bitfield* m_bitfield;
			UINT32      m_position;
		public:
			_H3API_ reference(H3Bitfield* bitfield);
			_H3API_ reference(H3Bitfield* bitfield, UINT position);
			_H3API_ reference& operator++();
			_H3API_ reference operator++(int);
			_H3API_ reference& operator~();
			_H3API_ operator BOOL();
			_H3API_ BOOL operator!();
			_H3API_ VOID operator=(BOOL state);
			_H3API_ VOID Set();
			_H3API_ VOID Reset();
			_H3API_ VOID Flip();
		};

	protected:
		UINT m_bf;
	public:
		_H3API_ BOOL GetState(UINT32 position) const;
		_H3API_ VOID SetState(UINT32 position, BOOL state);
		_H3API_ VOID Set(UINT32 value);
		_H3API_ UINT Get() const;
		_H3API_ VOID Flip(UINT32 position);
		_H3API_ reference operator[](UINT32 position);
		_H3API_ BOOL operator()(UINT position);
		_H3API_ static UINT Mask(UINT number_bits);
	}; /* H3Bitfield */

	struct H3ObjectMask
	{
		union
		{
			H3Bitfield m_bits[2];
			UINT64     m_bitsPacked;
		};

		class iterator
		{
		private:
			H3ObjectMask* m_mask;
			UINT32        m_position;
		public:
			_H3API_ iterator(const iterator& it);
			_H3API_ iterator(H3ObjectMask* mask);
			_H3API_ iterator(H3ObjectMask* mask, UINT32 index);
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ iterator& operator~();
			_H3API_ operator BOOL() const;
			_H3API_ BOOL operator!() const;
			_H3API_ VOID operator=(BOOL state);
			_H3API_ BOOL GetState() const;
			_H3API_ VOID SetState(BOOL state);
			_H3API_ VOID Set();
			_H3API_ VOID Reset();
			_H3API_ VOID Flip();
			_H3API_ BOOL operator==(const iterator& it);
			_H3API_ BOOL operator!=(const iterator& it);
		};
		_H3API_ VOID operator=(const H3ObjectMask& other);
		_H3API_ VOID operator=(UINT64 value);
		_H3API_ H3Bitfield& operator[](UINT index);
		_H3API_ const H3Bitfield& operator[](UINT index) const;
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ iterator operator()(UINT8 index);
		_H3API_ iterator operator()(UINT8 column, UINT8 row);
	}; /* H3ObjectMask */

	struct H3PlayersBitfield
	{
		_H3API_SIZE_(1);
		union
		{
			UINT8 bits;
			struct
			{
				BOOL8 red    : 1;
				BOOL8 blue   : 1;
				BOOL8 tan    : 1;
				BOOL8 green  : 1;
				BOOL8 orange : 1;
				BOOL8 purple : 1;
				BOOL8 teal   : 1;
				BOOL8 pink   : 1;
			};
		};

		_H3API_ H3PlayersBitfield();
		_H3API_ H3PlayersBitfield(UINT8 player_bits);
		_H3API_ H3PlayersBitfield(const H3PlayersBitfield& other);
		_H3API_ VOID operator|=(UINT8 value);
		_H3API_ VOID operator=(UINT8 value);
		_H3API_ VOID operator=(const H3PlayersBitfield& other);
		_H3API_ VOID Hide(UINT32 player);
		_H3API_ VOID Reveal(UINT32 player);
		_H3API_ VOID Set(UINT32 player, BOOL8 state);
		_H3API_ BOOL Status(UINT32 player) const;
		_H3API_ operator UINT8() const;
	};
	_H3API_ASSERT_SIZE_(H3PlayersBitfield);

	struct H3PlayersBitfield32 : H3PlayersBitfield
	{
		_H3API_SIZE_(4);
	private:
		h3align _f_01[3];
	};
	_H3API_ASSERT_SIZE_(H3PlayersBitfield32);

	struct H3TownsBitfield
	{
		_H3API_SIZE_(2);

		union
		{
			UINT16 bits;
			struct
			{
				BOOL8 castle     : 1;
				BOOL8 rampart    : 1;
				BOOL8 tower      : 1;
				BOOL8 inferno    : 1;
				BOOL8 necropolis : 1;
				BOOL8 deungeon   : 1;
				BOOL8 stronghold : 1;
				BOOL8 fortess    : 1;
				BOOL8 conflux    : 1;
			};
		};
	};
	_H3API_ASSERT_SIZE_(H3TownsBitfield);

	struct H3BuildingsBitfield
	{
		_H3API_SIZE_(0x8);
		union
		{
			struct
			{
				unsigned mageGuild1   : 1;
				unsigned mageGuild2   : 1;
				unsigned mageGuild3   : 1;
				unsigned mageGuild4   : 1;
				unsigned mageGuild5   : 1;
				unsigned tavern       : 1;
				unsigned wharf        : 1;
				unsigned fort         : 1;
				unsigned citadel      : 1;
				unsigned castle       : 1;
				unsigned villageHall  : 1;
				unsigned townHall     : 1;
				unsigned cityHall     : 1;
				unsigned capitol      : 1;
				unsigned market       : 1;
				unsigned resourceSilo : 1;
				unsigned blacksmith   : 1;
				unsigned special17    : 1;
				unsigned horde1       : 1;
				unsigned horde1u      : 1;
				unsigned wharf2       : 1;
				unsigned special21    : 1;
				unsigned special22    : 1;
				unsigned special23    : 1;
				unsigned horde2       : 1;
				unsigned horde2u      : 1;
				unsigned grail        : 1;
				unsigned decor27      : 1;
				unsigned decor28      : 1;
				unsigned decor29      : 1;
				unsigned dwelling1    : 1;
				unsigned dwelling2    : 1;
				unsigned dwelling3    : 1;
				unsigned dwelling4    : 1;
				unsigned dwelling5    : 1;
				unsigned dwelling6    : 1;
				unsigned dwelling7    : 1;
				unsigned dwelling1u   : 1;
				unsigned dwelling2u   : 1;
				unsigned dwelling3u   : 1;
				unsigned dwelling4u   : 1;
				unsigned dwelling5u   : 1;
				unsigned dwelling6u   : 1;
				unsigned dwelling7u   : 1;
				unsigned unused       : 20;
			};
			UINT64 value;
			H3Bitfield bitfield[2];
		};

	};

	struct H3TerrainBitfield
	{
		_H3API_SIZE_(4); // not sure if smaller is seen in game, maybe combat obstacles?
		union
		{
			struct
			{
				unsigned dirt         : 1;
				unsigned sand         : 1;
				unsigned grass        : 1;
				unsigned snow         : 1;
				unsigned swamp        : 1;
				unsigned rough        : 1;
				unsigned subterranean : 1;
				unsigned lava         : 1;
				unsigned water        : 1;
				unsigned rock         : 1;
			};
			UINT16 bits;
			H3Bitfield bitfield;
		};
	};
	_H3API_ASSERT_SIZE_(H3TerrainBitfield);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	namespace libc
	{
		_H3API_ INT32  strlen(LPCSTR text);
		_H3API_ LPCSTR strtok(LPCSTR text, LPCSTR delimiters);
		_H3API_ INT32  strcspn(LPCSTR text, LPCSTR keys);
		_H3API_ PCHAR  strncpy(PCHAR destination, LPCSTR source, UINT32 number);
		_H3API_ LPCSTR strrchr(LPCSTR text, CHAR last_char);
		_H3API_ INT32  strcmp(LPCSTR str1, LPCSTR str2);
		_H3API_ INT32  strncmp(LPCSTR str1, LPCSTR str2, UINT32 number);
		_H3API_ INT32  strnicmp(LPCSTR str1, LPCSTR str2, UINT32 number);
		_H3API_ INT32  strcmpi(LPCSTR str1, LPCSTR str2);
		_H3API_ PCHAR  strdup(LPCSTR string);
		_H3API_ LPCSTR strchr(LPCSTR string, INT32 character);
		_H3API_ PCHAR  strstr(LPCSTR string, LPCSTR substring);
		_H3API_ INT32  strtol(LPCSTR text, CHAR** endptr, INT32 base);
		_H3API_ UINT32 strtoul(LPCSTR text, CHAR** endptr, INT32 base);
		_H3API_ DOUBLE strtod(LPCSTR text, CHAR** endptr);
		_H3API_ PCHAR  strrev(PCHAR text);
		_H3API_ PCHAR  strupr(PCHAR text);
		_H3API_ INT32  atoi(LPCSTR text);
		_H3API_ UINT   atol(LPCSTR text);
		_H3API_ DOUBLE atof(LPCSTR text);
		_H3API_ UINT32 wcslen(LPCWSTR string);
		_H3API_ VOID   memcpy(PVOID dst, PVOID src, UINT32 len);
		_H3API_ VOID   memset(PVOID dest, INT32 value, const UINT len);
		_H3API_ INT32  vsprintf(PCHAR buffer, LPCSTR format, va_list args);
		_H3API_ INT32  sprintf(PCHAR buffer, LPCSTR format, ...);
		_H3API_ INT32  CompareStringW(LCID locale, DWORD flags, LPCWSTR str1, INT32 str1_length,
			LPCWSTR str2, INT32 str2_length);
		_H3API_ DWORD  GetFullPathNameA(LPCSTR file, DWORD buffer_length, PCHAR buffer, PCHAR* file_part);
		_H3API_ INT32  MultiByteToWideChar(UINT code_page, DWORD flags, LPCSTR string,
			INT32 string_length, WCHAR* buffer, INT32 buffer_length);
		_H3API_ INT32  WideCharToMultiByte(UINT code_page, DWORD flags, LPCWSTR string,
			INT32 string_length, PCHAR buffer, INT32 buffer_length, PCHAR default_char, BOOL* default_used);
	} /* namespace libc */

	_H3API_ VOID WaitFor(DWORD milliseconds);

	_H3API_ DWORD GetTime();
	_H3API_ INT32 Clamp(INT32 min_value, INT32 value, INT32 max_value);
	template<typename T>
	H3Point ReverseCoordinates(const T* current_point, const T* base_point, UINT map_size);

	struct H3Encoding
	{
		typedef H3UniquePtr<WCHAR> WCHARPtr;
		typedef H3UniquePtr<CHAR>  CHARPtr;

		_H3API_ static H3UniquePtr<WCHAR> Utf8ToUnicode(LPCSTR utf8);
		_H3API_ static H3UniquePtr<WCHAR> AnsiToUnicode(LPCSTR ansi,     UINT code_page = CP_ACP);
		_H3API_ static H3UniquePtr<CHAR>  UnicodeToAnsi(LPCWSTR unicode, UINT code_page = CP_ACP);
		_H3API_ static H3UniquePtr<CHAR>  UnicodeToUtf8(LPCWSTR unicode);
	};

	template<typename T>
	H3Point ReverseCoordinates(const T* current_point, const T* base_point, UINT map_size)
	{
		H3Point coordinates;
		UINT delta    = current_point - base_point;
		coordinates.x = delta % map_size;
		delta        /= map_size;
		coordinates.y = delta % map_size;
		coordinates.z = delta / map_size;
		return coordinates;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GlobalObjectSettings);

#pragma pack(push, 4)

	struct H3GlobalObjectSettings
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x660428, H3GlobalObjectSettings);

		BOOL8  cannotEnter;
		BOOL8  exitTop;
		BOOL8  canBeRemoved;
		LPCSTR objectName;
		INT32  objectID;
		BOOL32 decor;
	};
	_H3API_ASSERT_SIZE_(H3GlobalObjectSettings);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

#ifdef _H3API_STD_CONVERSIONS_
#include <string>
#endif

namespace h3
{
	_H3API_DECLARE_(String);
	_H3API_DECLARE_(WString);

#pragma pack(push, 4)
	struct H3String : H3Allocator
	{
		_H3API_SIZE_(0x10);
		friend H3WString;
	protected:
		h3unk8 _allocator; // useless
		PCHAR  m_string;
		UINT32 m_length;
		UINT32 m_capacity;

		_H3API_ VOID Deref();
		_H3API_ VOID NullTerminate();
		_H3API_ BOOL Realloc(UINT new_size);
		_H3API_ VOID ClearUnused();
		_H3API_ BOOL CompareChars(LPCSTR chars, UINT num_chars, UINT pos, BOOL is_true) const;
		_H3API_ UINT CompareFirstOf(LPCSTR chars, UINT num_chars, BOOL is_true) const;
		_H3API_ UINT CompareLastOf(LPCSTR chars, UINT num_chars, BOOL is_true) const;
		_H3API_ LPCSTR nullstring() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3String& move(H3String&& other);
#endif

	public:
		_H3API_ H3String();
		_H3API_ H3String(LPCSTR msg);
		_H3API_ H3String(LPCSTR msg, UINT len);
		_H3API_ H3String(const H3String& other);
		_H3API_ H3String(CHAR ch);
	#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3String(H3String&& other) noexcept;
	#endif

		_H3API_ ~H3String();

		_H3API_ VOID Init();
		_H3API_ VOID Dereference();

		_H3API_ BOOL Empty() const;

		_H3API_ UINT Length() const;
		_H3API_ UINT MaxLength() const;
		_H3API_ LPCSTR String() const;

		_H3API_ CHAR* begin();
		_H3API_ CHAR* end();
		_H3API_ const CHAR* begin() const;
		_H3API_ const CHAR* end() const;

		_H3API_ VOID swap(H3String& other);

		_H3API_ PCHAR Begin();
		_H3API_ PCHAR End();

		_H3API_ CHAR Last() const;

		_H3API_ H3String& Assign(LPCSTR mes, UINT len);
		_H3API_ H3String& Assign(LPCSTR mes);
		template<UINT Sz>
		inline H3String& AssignA(const CHAR(&buffer)[Sz]);
		_H3API_ H3String& Assign(CHAR ch);
		_H3API_ H3String& Assign(const H3String &other);
		_H3API_ H3String& Assign(INT32 number);
#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3String& Assign(H3String&& other);
#endif /* _H3API_CPLUSPLUS11_ */

		_H3API_ BOOL Reserve(UINT new_size = 0x1E);
		_H3API_ BOOL SetLength(UINT len);
		_H3API_ VOID ShrinkToFit();

		_H3API_ H3String& Append(LPCSTR mes, UINT len);
		template<UINT Sz>
		inline H3String& AppendA(const CHAR (&buffer)[Sz]);
		_H3API_ H3String& Append(const H3String & other);
		_H3API_ H3String& Append(INT32 number);
		_H3API_ H3String& Append(UINT32 number);
		_H3API_ H3String& Append(LPCSTR mes);
		_H3API_ H3String& Append(CHAR ch);

		_H3API_ LPCSTR FindFirst(CHAR ch);
		_H3API_ LPCSTR FindFirst(LPCSTR substr) const;

		_H3API_ UINT FindFirstOf(LPCSTR chars, UINT num_chars) const;
		_H3API_ UINT FindFirstOf(LPCSTR chars) const;
		_H3API_ UINT FindFirstOf(const H3String& chars) const;
		_H3API_ UINT FindFirstOf(const CHAR ch) const;

		_H3API_ UINT FindFirstNotOf(LPCSTR chars, UINT num_chars) const;
		_H3API_ UINT FindFirstNotOf(LPCSTR chars) const;
		_H3API_ UINT FindFirstNotOf(const H3String& chars) const;
		_H3API_ UINT FindFirstNotOf(const CHAR ch) const;

		_H3API_ UINT FindLastOf(LPCSTR chars, UINT num_chars) const;
		_H3API_ UINT FindLastOf(LPCSTR chars) const;
		_H3API_ UINT FindLastOf(const H3String& chars) const;
		_H3API_ UINT FindLastOf(const CHAR ch) const;

		_H3API_ UINT FindLastNotOf(LPCSTR chars, UINT num_chars) const;
		_H3API_ UINT FindLastNotOf(LPCSTR chars) const;
		_H3API_ UINT FindLastNotOf(const H3String& chars) const;
		_H3API_ UINT FindLastNotOf(const CHAR ch) const;

		_H3API_ H3String& Trim();

		_H3API_ PCHAR At(UINT pos);
		_H3API_ CHAR GetCharAt(UINT pos) const;

		_H3API_ H3String& Remove(CHAR ch);
		_H3API_ H3String& Remove(LPCSTR substr);
		_H3API_ H3String& Remove(LPCSTR substr, UINT sublen);
		_H3API_ H3String& Remove(UINT start, UINT end);
		_H3API_ H3String& Erase(UINT pos);
		_H3API_ H3String& Erase(UINT first, UINT last);
		_H3API_ H3String& Erase(PCHAR first, PCHAR last);

		_H3API_ BOOL Split(CHAR ch, H3String& out);

		_H3API_ VOID Erase();

		_H3API_ BOOL Equals(LPCSTR msg, UINT len) const;
		_H3API_ BOOL Equals(LPCSTR msg) const;
		_H3API_ BOOL Equals(const H3String& other) const;

		_H3API_ BOOL Equals_i(LPCSTR msg, UINT len) const;
		_H3API_ BOOL Equals_i(LPCSTR msg) const;
		_H3API_ BOOL Equals_i(const H3String& other) const;

		_H3API_ H3String& Insert(UINT pos, LPCSTR msg, UINT len);
		_H3API_ H3String& Insert(UINT pos, LPCSTR msg);
		_H3API_ H3String& Insert(UINT pos, const H3String& to_insert);
		_H3API_ H3String& Insert(UINT pos, CHAR ch);

		_H3API_ INT Compare(LPCSTR other) const;
		_H3API_ INT Compare(const H3String& other) const;
		_H3API_ INT Comparei(LPCSTR other) const;
		_H3API_ INT Comparei(const H3String& other) const;

		_H3API_ BOOL operator<(const H3String& other) const;

		_H3API_ BOOL Truncate(UINT position);

		_H3API_ UINT Occurrences(CHAR ch) const;

		_H3API_ H3String& operator=(const H3String& other);
		_H3API_ H3String& operator=(LPCSTR msg);
		_H3API_ H3String& operator=(CHAR ch);

	#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3String& operator=(H3String&& other) noexcept;
	#endif

		_H3API_ H3String& operator+=(const H3String& other);
		_H3API_ H3String& operator+=(LPCSTR msg);
		_H3API_ H3String& operator+=(CHAR ch);
		_H3API_ H3String& operator+=(INT32 number);
		_H3API_ H3String& operator+=(UINT32 number);

		_H3API_ BOOL operator==(const H3String& h3str) const;
		_H3API_ BOOL operator==(LPCSTR str) const;
		_H3API_ BOOL operator!=(const H3String& h3str) const;
		_H3API_ BOOL operator!=(LPCSTR str) const;

		_H3API_ CHAR  operator[](UINT32 pos) const;
		_H3API_ CHAR& operator[](UINT32 pos);

		_H3API_ INT8 References() const;

		_H3API_ VOID IncreaseReferences();

		_H3API_ BOOL FormattedNumber(INT32 number);

		_H3API_ BOOL ScaledNumber(INT32 number, INT32 decimals = 1);

		_H3API_ H3String& PrintfAppendH3(LPCSTR format, ...);

		_H3API_ INT32  ToSigned() const;
		_H3API_ UINT32 ToUnsigned() const;
		_H3API_ DOUBLE ToDouble() const;
		_H3API_ INT32  HexToSigned() const;
		_H3API_ UINT32 HexToUnsigned() const;

		_H3API_ H3String& Printf(LPCSTR format, ...);
		_H3API_ H3String& PrintfAppend(LPCSTR format, ...);

		_H3API_ static H3String GetLocalTime();
		_H3API_ static H3String FormatNumber(INT32 number);
		_H3API_ static H3String ShortScale(INT32 number, INT32 decimals);
		_H3API_ static H3String Format(LPCSTR format, ...);
		_H3API_ static H3String Format(LPCSTR format, va_list args);
		_H3API_ static H3String PrintfH3(LPCSTR format, ...);

	#ifdef _H3API_STD_CONVERSIONS_
		_H3API_ H3String(const std::string& str);
		_H3API_ INT operator==(const std::string& str) const;
		_H3API_ H3String& operator+=(const std::string& str);
		_H3API_ H3String& operator=(const std::string& str);
		_H3API_ H3String& Assign(const std::string& str);
		_H3API_ H3String& Append(const std::string& str);
		_H3API_ std::string to_std_string() const;
	#endif /* _H3API_STD_CONVERSIONS_ */


		friend inline H3String operator+(const H3String& lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(const H3String& lhs, H3String&& rhs);
		friend inline H3String operator+(H3String&& lhs, const H3String& rhs);
		friend inline H3String operator+(H3String&& lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		friend inline H3String operator+(const H3String& lhs, LPCSTR rhs);
		friend inline H3String operator+(LPCSTR lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(H3String&& lhs, LPCSTR rhs);
		friend inline H3String operator+(LPCSTR lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		friend inline H3String operator+(const H3String& lhs, CHAR rhs);
		friend inline H3String operator+(CHAR lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(H3String&& lhs, CHAR rhs);
		friend inline H3String operator+(CHAR lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		enum eH3String : UINT
		{
			max_len     = static_cast<UINT>(-3),
			npos        = static_cast<UINT>(-1),
		};

		_H3API_ H3WString ToH3WString(UINT code_page = CP_ACP) const;
	};
	_H3API_ASSERT_SIZE_(H3String);

	struct H3WString : H3Allocator
	{
		_H3API_SIZE_(0x10);
		friend H3String;
	protected:
		h3unk8 _allocator; // useless
		WCHAR* m_string;
		UINT32 m_length;
		UINT32 m_capacity;

		_H3API_ VOID tidy(BOOL8 dereference=TRUE);
		_H3API_ VOID deref();
		_H3API_ BOOL8 grow(UINT32 size, BOOL8 trim=FALSE);
		_H3API_ UINT8& references();
		_H3API_ PBYTE base();

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3WString& move(H3WString&& other);
#endif

	public:
		_H3API_ H3WString();
		_H3API_ H3WString(const H3WString& other);
		_H3API_ H3WString(LPCWSTR text, UINT32 length);
		_H3API_ H3WString(LPCWSTR text);
		_H3API_ H3WString(WCHAR character);
		_H3API_ ~H3WString();
		_H3API_ H3WString& Append(LPCWSTR text, UINT32 length);
		_H3API_ H3WString& Append(LPCWSTR text);
		_H3API_ H3WString& Append(WCHAR character);
		_H3API_ H3WString& Append(const H3WString& other);
		_H3API_ H3WString& Append(const H3WString& other, UINT32 start_position, UINT32 end_position);
#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3WString& Assign(H3WString&& other);
#endif
		_H3API_ H3WString& Assign(LPCWSTR text, UINT32 length);
		_H3API_ H3WString& Assign(LPCWSTR text);
		_H3API_ H3WString& Assign(const H3WString& other);
		_H3API_ H3WString& Assign(WCHAR character);
		_H3API_ H3WString& SoftCopy(const H3WString& other);
		_H3API_ VOID Destroy();
		_H3API_ UINT32 Size() const;
		_H3API_ UINT32 Length() const;
		_H3API_ BOOL32 IsEmpty() const;
		_H3API_ LPCWSTR String() const;
		_H3API_ VOID Insert(UINT32 start_position, UINT32 end_position, WCHAR character);
		_H3API_ H3WString& Insert(UINT32 start_position, LPCWSTR text);
		_H3API_ H3WString& Insert(UINT32 start_position, LPCWSTR text, UINT length);
		_H3API_ H3WString& Insert(UINT32 start_position, WCHAR text);
		_H3API_ H3WString& Insert(UINT32 start_position, const H3WString& other);

		_H3API_ PWCHAR Begin();

		_H3API_ LPCWSTR begin();
		_H3API_ LPCWSTR end();
		_H3API_ LPCWSTR begin() const;
		_H3API_ LPCWSTR end() const;

		_H3API_ BOOL8 Reserve(UINT32 length);

		_H3API_ UINT8 References() const;
		_H3API_ VOID  IncreaseReferences();
		_H3API_ VOID  DecreaseReferences();

		_H3API_ H3WString& Erase(UINT32 start_position, UINT32 end_position);
		_H3API_ H3WString& Erase();

		_H3API_ INT32 Compare(LPCWSTR string, UINT32 length) const;
		_H3API_ INT32 Compare(LPCWSTR string) const;
		_H3API_ INT32 Compare(const H3WString& other) const;
		_H3API_ INT32 Compare(WCHAR character) const;

		_H3API_ BOOL Equals(LPCWSTR string, UINT32 length) const;
		_H3API_ BOOL Equals(LPCWSTR string) const;
		_H3API_ BOOL Equals(const H3WString& other) const;
		_H3API_ BOOL Equals(WCHAR character) const;

		_H3API_ WCHAR  operator[](UINT position) const;
		_H3API_ WCHAR& operator[](UINT position);

		_H3API_ H3WString& operator=(const H3WString& other);
		_H3API_ H3WString& operator=(LPCWSTR msg);
		_H3API_ H3WString& operator=(WCHAR ch);

		_H3API_ H3WString& operator+=(const H3WString& other);
		_H3API_ H3WString& operator+=(LPCWSTR msg);
		_H3API_ H3WString& operator+=(WCHAR ch);

		_H3API_ BOOL operator==(const H3WString& other);
		_H3API_ BOOL operator==(LPCWSTR msg);
		_H3API_ BOOL operator==(WCHAR ch);


		friend inline H3WString operator+(const H3WString& lhs, const H3WString& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3WString operator+(H3WString&& lhs, const H3WString& rhs);
		friend inline H3WString operator+(const H3WString& lhs, H3WString&& rhs);
		friend inline H3WString operator+(H3WString&& lhs, H3WString&& rhs);
#endif

		friend inline H3WString operator+(const H3WString& lhs, LPCWSTR rhs);
		friend inline H3WString operator+(LPCWSTR lhs, const H3WString& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3WString operator+(H3WString&& lhs, LPCWSTR rhs);
		friend inline H3WString operator+(LPCWSTR lhs, H3WString&& rhs);
#endif

		friend inline H3WString operator+(const H3WString& lhs, WCHAR rhs);
		friend inline H3WString operator+(WCHAR lhs, const H3WString& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3WString operator+(H3WString&& lhs, WCHAR rhs);
		friend inline H3WString operator+(WCHAR lhs, H3WString&& rhs);
#endif

		enum eH3WString : UINT
		{
			max_len           = static_cast<UINT>(0x7FFFFFFD),
			npos              = static_cast<UINT>(-1),
			frozen            = static_cast<UINT>(0xFF),
		};

		_H3API_ H3String ToH3String(UINT code_page = CP_ACP) const;
	};
	_H3API_ASSERT_SIZE_(H3WString);
#pragma pack(pop) /* align-4 */
	_H3API_NAMED_STRUCT_(H3String, DataPath, 0x55AA7A + 1);

	template<UINT Sz>
	inline H3String& H3String::AppendA(const CHAR(&buffer)[Sz])
	{
		return Append(buffer, Sz - 1);
	}
	template<UINT Sz>
	inline H3String& H3String::AssignA(const CHAR(&buffer)[Sz])
	{
		return Assign(buffer, Sz - 1);
	}
	inline H3String operator+(const H3String& lhs, const H3String& rhs)
	{
		H3String ans;
		if (!ans.Reserve(lhs.Length() + rhs.Length()))
			return ans;
		ans += lhs;
		ans += rhs;
		return ans;
	}
#ifdef _H3API_CPLUSPLUS11_
	inline H3String operator+(const H3String& lhs, H3String&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}

	inline H3String operator+(H3String&& lhs, const H3String& rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}

	inline H3String h3::operator+(H3String&& lhs, H3String&& rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}

	inline H3String operator+(H3String&& lhs, LPCSTR rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}

	inline H3String operator+(LPCSTR lhs, H3String&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}

	inline H3String operator+(H3String&& lhs, CHAR rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}

	inline H3String operator+(CHAR lhs, H3String&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}

#endif

	inline H3String operator+(const H3String& lhs, CHAR rhs)
	{
		H3String ans;
		if (!(ans.Reserve(lhs.Length() + 1)))
			return ans;
		ans += lhs;
		ans += rhs;
		return ans;
	}

	inline H3String operator+(CHAR lhs, const H3String& rhs)
	{
		H3String ans;
		if (!(ans.Reserve(rhs.Length()) + 1))
			return ans;
		ans += lhs;
		ans += rhs;
		return ans;
	}

	inline H3String operator+(const H3String& lhs, LPCSTR rhs)
	{
		H3String ans;
		const UINT slen = libc::strlen(rhs);
		if (!(ans.Reserve(lhs.Length()) + slen))
			return ans;
		ans += lhs;
		ans += rhs;
		return ans;
	}

	inline H3String operator+(LPCSTR lhs, const H3String& rhs)
	{
		H3String ans;
		UINT slen = libc::strlen(lhs);
		if (!(ans.Reserve(rhs.Length()) + slen))
			return ans;
		ans += lhs;
		ans += rhs;
		return ans;
	}

	inline H3WString operator+(const H3WString& lhs, const H3WString& rhs)
	{
		H3WString string(lhs);
		string += rhs;
		return string;
	}
#ifdef _H3API_CPLUSPLUS11_
	inline H3WString operator+(H3WString&& lhs, const H3WString& rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}
	inline H3WString h3::operator+(const H3WString& lhs, H3WString&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}
	inline H3WString h3::operator+(H3WString&& lhs, H3WString&& rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}
	inline H3WString h3::operator+(H3WString&& lhs, LPCWSTR rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}
	inline H3WString h3::operator+(LPCWSTR lhs, H3WString&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}
	inline H3WString h3::operator+(H3WString&& lhs, WCHAR rhs)
	{
		lhs += rhs;
		return std::move(lhs);
	}
	H3WString h3::operator+(WCHAR lhs, H3WString&& rhs)
	{
		rhs.Insert(0, lhs);
		return std::move(rhs);
	}
#endif

	inline H3WString operator+(const H3WString& lhs, WCHAR rhs)
	{
		H3WString string(lhs);
		string += rhs;
		return string;
	}

	inline H3WString operator+(WCHAR lhs, const H3WString& rhs)
	{
		H3WString string(lhs);
		string += rhs;
		return string;
	}

	inline H3WString operator+(const H3WString& lhs, LPCWSTR rhs)
	{
		H3WString string(lhs);
		string += rhs;
		return string;
	}

	inline H3WString operator+(LPCWSTR lhs, const H3WString& rhs)
	{
		H3WString string(lhs);
		string += rhs;
		return string;
	}
}

namespace h3
{
    namespace NH3Creatures
    {
        enum eCreatures : INT32
        {
            UNDEFINED           = -1,
            PIKEMAN             = 0,
            HALBERDIER          = 1,
            ARCHER              = 2,
            MARKSMAN            = 3,
            GRIFFIN             = 4,
            ROYAL_GRIFFIN       = 5,
            SWORDSMAN           = 6,
            CRUSADER            = 7,
            MONK                = 8,
            ZEALOT              = 9,
            CAVALIER            = 10,
            CHAMPION            = 11,
            ANGEL               = 12,
            ARCHANGEL           = 13,
            CENTAUR             = 14,
            CENTAUR_CAPTAIN     = 15,
            DWARF               = 16,
            BATTLE_DWARF        = 17,
            WOOD_ELF            = 18,
            GRAND_ELF           = 19,
            PEGASUS             = 20,
            SILVER_PEGASUS      = 21,
            DENDROID_GUARD      = 22,
            DENDROID_SOLDIER    = 23,
            UNICORN             = 24,
            WAR_UNICORN         = 25,
            GREEN_DRAGON        = 26,
            GOLD_DRAGON         = 27,
            GREMLIN             = 28,
            MASTER_GREMLIN      = 29,
            STONE_GARGOYLE      = 30,
            OBSIDIAN_GARGOYLE   = 31,
            STONE_GOLEM         = 32,
            IRON_GOLEM          = 33,
            MAGE                = 34,
            ARCH_MAGE           = 35,
            GENIE               = 36,
            MASTER_GENIE        = 37,
            NAGA                = 38,
            NAGA_QUEEN          = 39,
            GIANT               = 40,
            TITAN               = 41,
            IMP                 = 42,
            FAMILIAR            = 43,
            GOG                 = 44,
            MAGOG               = 45,
            HELL_HOUND          = 46,
            CERBERUS            = 47,
            DEMON               = 48,
            HORNED_DEMON        = 49,
            PIT_FIEND           = 50,
            PIT_LORD            = 51,
            EFREETI             = 52,
            EFREET_SULTAN       = 53,
            DEVIL               = 54,
            ARCH_DEVIL          = 55,
            SKELETON            = 56,
            SKELETON_WARRIOR    = 57,
            WALKING_DEAD        = 58,
            ZOMBIE              = 59,
            WIGHT               = 60,
            WRAITH              = 61,
            VAMPIRE             = 62,
            VAMPIRE_LORD        = 63,
            LICH                = 64,
            POWER_LICH          = 65,
            BLACK_KNIGHT        = 66,
            DREAD_KNIGHT        = 67,
            BONE_DRAGON         = 68,
            GHOST_DRAGON        = 69,
            TROGLODYTE          = 70,
            INFERNAL_TROGLODYTE = 71,
            HARPY               = 72,
            HARPY_HAG           = 73,
            BEHOLDER            = 74,
            EVIL_EYE            = 75,
            MEDUSA              = 76,
            MEDUSA_QUEEN        = 77,
            MINOTAUR            = 78,
            MINOTAUR_KING       = 79,
            MANTICORE           = 80,
            SCORPICORE          = 81,
            RED_DRAGON          = 82,
            BLACK_DRAGON        = 83,
            GOBLIN              = 84,
            HOBGOBLIN           = 85,
            WOLF_RIDER          = 86,
            WOLF_RAIDER         = 87,
            ORC                 = 88,
            ORC_CHIEFTAIN       = 89,
            OGRE                = 90,
            OGRE_MAGE           = 91,
            ROC                 = 92,
            THUNDERBIRD         = 93,
            CYCLOPS             = 94,
            CYCLOPS_KING        = 95,
            BEHEMOTH            = 96,
            ANCIENT_BEHEMOTH    = 97,
            GNOLL               = 98,
            GNOLL_MARAUDER      = 99,
            LIZARDMAN           = 100,
            LIZARD_WARRIOR      = 101,
            GORGON              = 102,
            MIGHTY_GORGON       = 103,
            SERPENT_FLY         = 104,
            DRAGON_FLY          = 105,
            BASILISK            = 106,
            GREATER_BASILISK    = 107,
            WYVERN              = 108,
            WYVERN_MONARCH      = 109,
            HYDRA               = 110,
            CHAOS_HYDRA         = 111,
            AIR_ELEMENTAL       = 112,
            EARTH_ELEMENTAL     = 113,
            FIRE_ELEMENTAL      = 114,
            WATER_ELEMENTAL     = 115,
            GOLD_GOLEM          = 116,
            DIAMOND_GOLEM       = 117,
            PIXIE               = 118,
            SPRITE              = 119,
            PSYCHIC_ELEMENTAL   = 120,
            MAGIC_ELEMENTAL     = 121,
            NOT_USED1           = 122,
            ICE_ELEMENTAL       = 123,
            NOT_USED2           = 124,
            MAGMA_ELEMENTAL     = 125,
            NOT_USED3           = 126,
            STORM_ELEMENTAL     = 127,
            NOT_USED4           = 128,
            ENERGY_ELEMENTAL    = 129,
            FIREBIRD            = 130,
            PHOENIX             = 131,
            AZURE_DRAGON        = 132,
            CRYSTAL_DRAGON      = 133,
            FAERIE_DRAGON       = 134,
            RUST_DRAGON         = 135,
            ENCHANTER           = 136,
            SHARPSHOOTER        = 137,
            HALFLING            = 138,
            PEASANT             = 139,
            BOAR                = 140,
            MUMMY               = 141,
            NOMAD               = 142,
            ROGUE               = 143,
            TROLL               = 144,
            CATAPULT            = 145,
            BALLISTA            = 146,
            FIRST_AID_TENT      = 147,
            AMMO_CART           = 148,
            ARROW_TOWER         = 149,
        };
    } /* namespace NH3Creatures */
    typedef NH3Creatures::eCreatures eCreature;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Army);
	struct H3Hero;
	struct H3MapitemMonster;

#pragma pack(push, 4)
	struct H3Army
	{
		_H3API_SIZE_(0x38);
		_H3API_CTOR_DTOR_(0x44A750, 0x44A750);

		struct iterator
		{
		protected:
			INT32* m_type;
		public:
			_H3API_ iterator(INT32* type);
			_H3API_ iterator& operator*();
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ BOOL operator==(const iterator& other);
			_H3API_ BOOL operator!=(const iterator& other);
			_H3API_ iterator& operator=(const iterator& other);
			_H3API_ BOOL operator!() const;

			_H3API_ INT32& Type();
			_H3API_ INT32  Type() const;
			_H3API_ INT32& Count();
			_H3API_ INT32  Count() const;
		};
		INT32 type[7];
		INT32 count[7];

		_H3API_ H3Army();
		_H3API_ H3Army(const H3Army& other);
		_H3API_ BOOL AddStack(INT32 type, INT32 amount, INT32 slot);
		_H3API_ VOID SplitFromStackToStack(INT32 fromStack, INT32 toStack, INT32 fraction);
		_H3API_ INT32 FirstFreeSlot();
		_H3API_ INT32 FindExistingByIndex(INT32 index);
		_H3API_ INT32 GetStackCount();
		_H3API_ INT32 GetCreaturesCount();
		_H3API_ BOOL8 HasCreatureType(INT32 cre);
		_H3API_ BOOL HasCreatures();
		_H3API_ VOID Clear();
		_H3API_ VOID Clear(INT stack);
		_H3API_ VOID ClearAndGive(INT type, INT count);
		_H3API_ BOOL8 IsUndeadArmy();
		_H3API_ INT32 NumberAlignments(INT8(&towns)[9]);
		_H3API_ INT32 GetArmyValue();
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ H3Army& operator=(const H3Army& other);
		_H3API_ iterator operator[](UINT index);
		_H3API_ VOID Swap(UINT from, UINT to);
		_H3API_ static H3Army SplitCreatures(const H3Point& p, H3Hero* hero, INT32 type0, INT32 amount0,
			INT32 type1 = -1, INT32 amount1 = 0, INT32 stacks1 = 0,
			INT32 type2 = -1, INT32 amount2 = 0, INT32 stacks2 = 0);
	};
	_H3API_ASSERT_SIZE_(H3Army);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemArtifact);
	_H3API_DECLARE_(MapArtifact);
	struct H3Main;

#pragma pack(push, 4)

	struct H3MapArtifact
	{
		_H3API_SIZE_(0x4C);
		H3String message;
		BOOL8 isGuarded;
		H3Army guardians;
	};
	_H3API_ASSERT_SIZE_(H3MapArtifact);

	struct H3MapitemArtifact
	{
		enum eType
		{
			FREE,
			GOLD2000,
			WISDOM,
			LEADERSHIP,
			GOLD2500_WOOD3,
			GOLD3000_WOOD5,
			FIGHT,
		};

		unsigned type     : 4;
		unsigned _u1      : 15;
		unsigned id       : 12;
		unsigned hasSetup : 1;

		_H3API_ H3MapArtifact* Get();
		_H3API_ H3MapArtifact* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Artifacts
    {
        namespace NArtifacts
        {
            enum eArtifacts
            {
                NONE                           = -1,
                SPELLBOOK                      = 0,
                SPELL_SCROLL                   = 1,
                GRAIL                          = 2,
                CATAPULT                       = 3,
                BALLISTA                       = 4,
                AMMO_CART                      = 5,
                FIRST_AID_TENT                 = 6,
                CENTAUR_AXE                    = 7,
                BLACKSHARD_OF_THE_DEAD_KNIGHT  = 8,
                GREATER_GNOLLS_FLAIL           = 9,
                OGRES_CLUB_OF_HAVOC            = 10,
                SWORD_OF_HELLFIRE              = 11,
                TITANS_GLADIUS                 = 12,
                SHIELD_OF_THE_DWARVEN_LORDS    = 13,
                SHIELD_OF_THE_YAWNING_DEAD     = 14,
                BUCKLER_OF_THE_GNOLL_KING      = 15,
                TARG_OF_THE_RAMPAGING_OGRE     = 16,
                SHIELD_OF_THE_DAMNED           = 17,
                SENTINELS_SHIELD               = 18,
                HELM_OF_THE_ALABASTER_UNICORN  = 19,
                SKULL_HELMET                   = 20,
                HELM_OF_CHAOS                  = 21,
                CROWN_OF_THE_SUPREME_MAGI      = 22,
                HELLSTORM_HELMET               = 23,
                THUNDER_HELMET                 = 24,
                BREASTPLATE_OF_PETRIFIED_WOOD  = 25,
                RIB_CAGE                       = 26,
                SCALES_OF_THE_GREATER_BASILISK = 27,
                TUNIC_OF_THE_CYCLOPS_KING      = 28,
                BREASTPLATE_OF_BRIMSTONE       = 29,
                TITANS_CUIRASS                 = 30,
                ARMOR_OF_WONDER                = 31,
                SANDALS_OF_THE_SAINT           = 32,
                CELESTIAL_NECKLACE_OF_BLISS    = 33,
                LIONS_SHIELD_OF_COURAGE        = 34,
                SWORD_OF_JUDGEMENT             = 35,
                HELM_OF_HEAVENLY_ENLIGHTENMENT = 36,
                QUIET_EYE_OF_THE_DRAGON        = 37,
                RED_DRAGON_FLAME_TONGUE        = 38,
                DRAGON_SCALE_SHIELD            = 39,
                DRAGON_SCALE_ARMOR             = 40,
                DRAGONBONE_GREAVES             = 41,
                DRAGON_WING_TABARD             = 42,
                NECKLACE_OF_DRAGONTEETH        = 43,
                CROWN_OF_DRAGONTOOTH           = 44,
                STILL_EYE_OF_THE_DRAGON        = 45,
                CLOVER_OF_FORTUNE              = 46,
                CARDS_OF_PROPHECY              = 47,
                LADYBIRD_OF_LUCK               = 48,
                BADGE_OF_COURAGE               = 49,
                CREST_OF_VALOR                 = 50,
                GLYPH_OF_GALLANTRY             = 51,
                SPECULUM                       = 52,
                SPYGLASS                       = 53,
                AMULET_OF_THE_UNDERTAKER       = 54,
                VAMPIRES_COWL                  = 55,
                DEAD_MANS_BOOTS                = 56,
                GARNITURE_OF_INTERFERENCE      = 57,
                SURCOAT_OF_COUNTERPOISE        = 58,
                BOOTS_OF_POLARITY              = 59,
                BOW_OF_ELVEN_CHERRYWOOD        = 60,
                BOWSTRING_OF_THE_UNICORNS_MANE = 61,
                ANGEL_FEATHER_ARROWS           = 62,
                BIRD_OF_PERCEPTION             = 63,
                STOIC_WATCHMAN                 = 64,
                EMBLEM_OF_COGNIZANCE           = 65,
                STATESMANS_MEDAL               = 66,
                DIPLOMATS_RING                 = 67,
                AMBASSADORS_SASH               = 68,
                RING_OF_THE_WAYFARER           = 69,
                EQUESTRIANS_GLOVES             = 70,
                NECKLACE_OF_OCEAN_GUIDANCE     = 71,
                ANGEL_WINGS                    = 72,
                CHARM_OF_MANA                  = 73,
                TALISMAN_OF_MANA               = 74,
                MYSTIC_ORB_OF_MANA             = 75,
                COLLAR_OF_CONJURING            = 76,
                RING_OF_CONJURING              = 77,
                CAPE_OF_CONJURING              = 78,
                ORB_OF_THE_FIRMAMENT           = 79,
                ORB_OF_SILT                    = 80,
                ORB_OF_TEMPESTUOUS_FIRE        = 81,
                ORB_OF_DRIVING_RAIN            = 82,
                RECANTERS_CLOAK                = 83,
                SPIRIT_OF_OPPRESSION           = 84,
                HOURGLASS_OF_THE_EVIL_HOUR     = 85,
                TOME_OF_FIRE_MAGIC             = 86,
                TOME_OF_AIR_MAGIC              = 87,
                TOME_OF_WATER_MAGIC            = 88,
                TOME_OF_EARTH_MAGIC            = 89,
                BOOTS_OF_LEVITATION            = 90,
                GOLDEN_BOW                     = 91,
                SPHERE_OF_PERMANENCE           = 92,
                ORB_OF_VULNERABILITY           = 93,
                RING_OF_VITALITY               = 94,
                RING_OF_LIFE                   = 95,
                VIAL_OF_LIFEBLOOD              = 96,
                NECKLACE_OF_SWIFTNESS          = 97,
                BOOTS_OF_SPEED                 = 98,
                CAPE_OF_VELOCITY               = 99,
                PENDANT_OF_DISPASSION          = 100,
                PENDANT_OF_SECOND_SIGHT        = 101,
                PENDANT_OF_HOLINESS            = 102,
                PENDANT_OF_LIFE                = 103,
                PENDANT_OF_DEATH               = 104,
                PENDANT_OF_FREE_WILL           = 105,
                PENDANT_OF_NEGATIVITY          = 106,
                PENDANT_OF_TOTAL_RECALL        = 107,
                PENDANT_OF_COURAGE             = 108,
                EVERFLOWING_CRYSTAL_CLOAK      = 109,
                RING_OF_INFINITE_GEMS          = 110,
                EVERPOURING_VIAL_OF_MERCURY    = 111,
                INEXHAUSTIBLE_CART_OF_ORE      = 112,
                EVERSMOKING_RING_OF_SULFUR     = 113,
                INEXHAUSTIBLE_CART_OF_LUMBER   = 114,
                ENDLESS_SACK_OF_GOLD           = 115,
                ENDLESS_BAG_OF_GOLD            = 116,
                ENDLESS_PURSE_OF_GOLD          = 117,
                LEGS_OF_LEGION                 = 118,
                LOINS_OF_LEGION                = 119,
                TORSO_OF_LEGION                = 120,
                ARMS_OF_LEGION                 = 121,
                HEAD_OF_LEGION                 = 122,
                SEA_CAPTAINS_HAT               = 123,
                SPELLBINDERS_HAT               = 124,
                SHACKLES_OF_WAR                = 125,
                ORB_OF_INHIBITION              = 126,
                VIAL_OF_DRAGON_BLOOD           = 127,
                ARMAGEDDONS_BLADE              = 128,
                ANGELIC_ALLIANCE               = 129,
                CLOAK_OF_THE_UNDEAD_KING       = 130,
                ELIXIR_OF_LIFE                 = 131,
                ARMOR_OF_THE_DAMNED            = 132,
                STATUE_OF_LEGION               = 133,
                POWER_OF_THE_DRAGON_FATHER     = 134,
                TITANS_THUNDER                 = 135,
                ADMIRALS_HAT                   = 136,
                BOW_OF_THE_SHARPSHOOTER        = 137,
                WIZARDS_WELL                   = 138,
                RING_OF_THE_MAGI               = 139,
                CORNUCOPIA                     = 140,
            };
        }
        typedef NArtifacts::eArtifacts eArtifacts;

        namespace NSlots
        {
            enum eArtifactSlots
            {
                NONE           = -1,
                HEAD           = 0,
                SHOULDERS      = 1,
                NECK           = 2,
                RIGHT_HAND     = 3,
                LEFT_HAND      = 4,
                TORSO          = 5,
                RIGHT_RING     = 6,
                LEFT_RING      = 7,
                FEET           = 8,
                MISC1          = 9,
                MISC2          = 10,
                MISC3          = 11,
                MISC4          = 12,
                BALLISTA       = 13,
                AMMO_CART      = 14,
                FIRST_AID_TENT = 15,
                CATAPULT       = 16,
                SPELLBOOK      = 17,
                MISC5          = 18,
            };
        }
        typedef NSlots::eArtifactSlots eArtifactSlots;

        namespace NType
        {
            enum eArtifactType
            {
                SPECIAL  = 1,
                TREASURE = 2,
                MINOR    = 4,
                MAJOR    = 8,
                RELIC    = 16,
                ALL      = 30, // never special!
            };
        }
        typedef NType::eArtifactType eArtifactType;

        namespace NCombination
        {
            enum eCombinationArtifacts
            {
                NONE                       = -1,
                ANGELIC_ALLIANCE           = 0,
                CLOAK_OF_THE_UNDEAD_KING   = 1,
                ELIXIR_OF_LIFE             = 2,
                ARMOR_OF_THE_DAMNED        = 3,
                STATUE_OF_LEGION           = 4,
                POWER_OF_THE_DRAGON_FATHER = 5,
                TITANS_THUNDER             = 6,
                ADMIRALS_HAT               = 7,
                BOW_OF_THE_SHARPSHOOTER    = 8,
                WIZARDS_WELL               = 9,
                RING_OF_THE_MAGI           = 10,
                CORNUCOPIA                 = 11,
            };
        }
        typedef NCombination::eCombinationArtifacts eCombinationArtifacts;
    }

    typedef NH3Artifacts::eArtifacts            eArtifact;
    typedef NH3Artifacts::eArtifactSlots        eArtifactSlots;
    typedef NH3Artifacts::eArtifactType         eArtifactType;
    typedef NH3Artifacts::eCombinationArtifacts eCombinationArtifacts;

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemBlackMarket);
	_H3API_DECLARE_(BlackMarket);
	_H3API_DECLARE_(ArtifactMerchant);
	struct H3Main;

#pragma pack(push, 4)
	struct H3BlackMarket
	{
		INT32 artifacts[7];
	};

	struct H3ArtifactMerchant : H3BlackMarket
	{
	};

	struct H3MapitemBlackMarket
	{
		UINT id;

		_H3API_ H3BlackMarket* Get();
		_H3API_ H3BlackMarket* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemBoat);
	_H3API_DECLARE_(Boat);
	struct H3MapItem;
	struct H3Main;

#pragma pack(push, 1)
	struct H3Boat // size 0x28 from 0x4CE5C0
	{
		_H3API_SIZE_(0x28);
		INT16 x;
		INT16 y;
		INT16 z;
		INT8 visible;
		H3MapItem* item;
	protected:
		h3unk8 _f_0B;
	public:
		INT32 objectType;
		INT8 objectFlag;
	protected:
		h3unk8 _f_11[3];
	public:
		INT32 objectSetup;
		INT8 exists;
		INT8 index;
		INT8 par1;
		INT8 par2;
		INT8 owner;
	protected:
		h3unk8 _f_1D[3];
	public:
		INT32 heroId;
		BOOL8 hasHero;
	protected:
		h3unk8 _f_25[3];
	};
	_H3API_ASSERT_SIZE_(H3Boat);
#pragma pack(pop)

#pragma pack(push, 4)

	struct H3MapitemBoat
	{
		UINT32 index;

		_H3API_ H3Boat* Get();
		_H3API_ H3Boat* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Resources
    {
        enum eResource : INT32
        {
            WOOD_AND_ORE = -3,
            ALL_SPECIAL  = -2,


            WOOD    = 0,
            MERCURY = 1,
            ORE     = 2,
            SULFUR  = 3,
            CRYSTAL = 4,
            GEMS    = 5,
            GOLD    = 6,
        };
    } /* namespace NH3Resources */
    typedef NH3Resources::eResource eResource;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemCampfire);

#pragma pack(push, 4)

	struct H3MapitemCampfire
	{
		unsigned  resType : 4;
		unsigned  resValue : 28;

		_H3API_ eResource GetType();
		_H3API_ INT32 GetGold();
		_H3API_ INT32 GetResourceAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemCorpse);

#pragma pack(push, 4)

	struct H3MapitemCorpse
	{
		unsigned  id          : 5;
		unsigned _u1          : 1;
		unsigned  artifactID  : 10;
		unsigned  hasArtifact : 1;
		unsigned _u2          : 15;

		_H3API_ eArtifact GetArtifact();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Resources);

#pragma pack(push, 4)

	struct H3Resources
	{
		_H3API_SIZE_(0x1C);

		union
		{
			struct
			{
				INT32 wood;
				INT32 mercury;
				INT32 ore;
				INT32 sulfur;
				INT32 crystal;
				INT32 gems;
				INT32 gold;
			};
			INT32 asArray[7];
		};

		_H3API_ H3Resources();
		_H3API_ H3Resources(H3Resources const& other);
		_H3API_ BOOL EnoughResources(const H3Resources& cost) const;
		_H3API_ VOID RemoveResources(const H3Resources& cost);
		_H3API_ VOID GainResourcesOF(const H3Resources& gain);
		_H3API_ INT Count() const;
		_H3API_ PINT begin();
		_H3API_ PINT end();
		_H3API_ PINT cbegin() const;
		_H3API_ PINT cend() const;
		_H3API_ H3Resources& operator+=(const H3Resources& other);
		_H3API_ H3Resources& operator-=(const H3Resources& other);
		_H3API_ H3Resources& operator=(const H3Resources& other);
		_H3API_ BOOL operator>=(const H3Resources& other) const;
		_H3API_ BOOL operator>(const H3Resources& other) const;
		_H3API_ BOOL operator<(const H3Resources& other) const;
		_H3API_ BOOL operator<=(const H3Resources& other) const;
		_H3API_ INT& operator[](INT32 index);
	};
	_H3API_ASSERT_SIZE_(H3Resources);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

#if defined(_H3API_STD_CONVERSIONS_) || defined(_H3API_STD_VECTOR_)
#include <vector>
#endif

namespace h3
{
	template<typename _Elem> struct H3Vector;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<typename _Elem>
	using Vector = H3Vector<_Elem>;
#endif /*_H3API_TEMPLATE_DECLARE_*/
	_H3API_DECLARE_(IndexVector);

#pragma pack(push, 4)
	template<typename _Elem>
	struct H3Vector : H3Allocator
	{
		_H3API_SIZE_(0x10);
	protected:
		h3unk _allocator; // useless
		_Elem* m_first;
		_Elem* m_end;
		_Elem* m_capacity;

		_Elem* Allocate(UINT number);
		VOID Construct(_Elem* start, _Elem* finish);
		VOID Destruct(_Elem* start, _Elem* finish);
		VOID Deallocate();
		BOOL reserveExtra(INT32 number);

		UINT EXPAND_NUMBER(UINT minimumNeeded);
		static constexpr UINT MIN_ELEMENTS = 10;
		static constexpr UINT GROWTH_MULTIPLIER = 2 ;
	public:
		H3Vector();
		H3Vector(UINT number_elements);
		~H3Vector();

		H3Vector(const H3Vector<_Elem>& other);
		H3Vector<_Elem>& operator=(const H3Vector<_Elem>& other);

#ifdef _H3API_CPLUSPLUS11_
		H3Vector(H3Vector<_Elem>&& other);
		H3Vector<_Elem>& operator=(H3Vector<_Elem>&& other);
#endif

		void swap(H3Vector<_Elem>& other);

		_Elem* begin();
		_Elem* end();
		_Elem* begin() const;
		_Elem* end() const;

		VOID Init();
		VOID Deref();
		BOOL IsEmpty() const;
		BOOL IsFull() const;
		UINT32 Size() const;
		UINT32 Count() const;
		UINT32 CountMax() const;
		UINT32 RawSize() const;
		UINT32 RawSizeAllocated() const;
		VOID RemoveLast();
		VOID RemoveAll();
		_Elem* Add(const _Elem & item);
		_Elem* AddOne(const _Elem & item);
		VOID AddSize4(_Elem item);
		BOOL Expand();
		_Elem *First();
		const _Elem *CFirst() const;
		_Elem& RFirst();
		const _Elem& CRFirst() const;
		_Elem *Last();
		const _Elem *CLast() const;
		_Elem& RLast();
		const _Elem& CRLast() const;
		_Elem* Append(const _Elem& item);
		_Elem* Push(const _Elem& item);
		_Elem* Pop();
		_Elem* At(UINT32 pos);
		const _Elem* At(UINT32 pos) const;
		_Elem& RAt(UINT32 pos);
		const _Elem& RAt(UINT32 pos) const;
		BOOL Remove(UINT32 pos);
		BOOL Remove(UINT32 fromPos, UINT32 toPos);
		BOOL Remove(_Elem* first, _Elem* last);
		BOOL Remove(_Elem* elem);
		BOOL Reserve(UINT number);
		BOOL Resize(UINT number);

		_Elem& operator[](UINT32 pos);
		_Elem& operator[](UINT32 pos) const;
		_Elem* operator+=(const _Elem& item);

		BOOL Insert(_Elem* position, _Elem* first, _Elem* last);
		BOOL Insert(_Elem* position, const _Elem& elem);

#ifdef _H3API_CPLUSPLUS11_
		_Elem* Add(_Elem&& item);
		_Elem* Push(_Elem&& item);
		_Elem* AddOne(_Elem&& item);
		_Elem* Append(_Elem&& item);
		_Elem* operator+=(_Elem&& item);
#endif

#ifdef _H3API_STD_CONVERSIONS_
		BOOL Insert(_Elem* position, typename std::vector<_Elem>::iterator first, typename std::vector<_Elem>::iterator last);
		H3Vector(const std::vector<_Elem>& vec);
		std::vector<_Elem> to_std_vector() const;
		H3Vector<_Elem>& operator=(const std::vector<_Elem>& vec);
#endif /* _H3API_STD_CONVERSIONS_ */
	};
	_H3API_ASSERT_SIZE_(H3Vector<h3unk>);

	struct H3IndexVector
	{
		_H3API_SIZE_(0x18);
	protected:
		INT    m_minimum;
		INT    m_availableCount;
		BOOL8  m_init; // essentially H3Vector<BOOL8>
		BOOL8* m_begin;
		BOOL8* m_end;
		BOOL8* m_capacity;
	public:
		_H3API_ H3IndexVector(INT min_num, INT max_num);
		_H3API_ ~H3IndexVector();
		_H3API_ INT ChooseRandom();
		_H3API_ INT InvalidIndex();
	};
	_H3API_ASSERT_SIZE_(H3IndexVector);

#pragma pack(pop) /* align-4 */


#ifdef _H3API_STD_VECTOR_
#if defined(_MSC_VER) && (_MSC_VER >= 1800) // in VS2008, std::vector has size 20~24 which is not compatible.

#ifndef _DEBUG
#pragma pack(push, 4)
	class H3AllocatorReference
	{
		h3unk m_allocatorReference;
	};
#pragma pack(pop)
#endif

#ifdef _DEBUG // debug std::vector can be used directly as H3Vector
	template<typename T>
	struct H3StdVector : public std::vector<T, H3ObjectAllocator<T>>
#else // non-debug std::vector requires padding to use as H3Vector
	template<typename T>
	struct H3StdVector : H3AllocatorReference, public std::vector<T, H3ObjectAllocator<T>>

#endif /* _DEBUG */
	{
		_H3API_SIZE_(0x10);
	public:
		using std::vector<T, H3ObjectAllocator<T>>::vector; // inherit constructors
	};
	_H3API_ASSERT_SIZE_(H3StdVector<h3unk>);
#endif /* defined(_MSC_VER) && (_MSC_VER >= 1800) */
#endif /* _H3API_STD_VECTOR_ */

	_H3API_NAMED_STRUCT_(H3Vector<INT32>, BattleShadowHexes, 0x493EA1 + 1);

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Allocate(UINT number)
	{
		return H3ObjectAllocator< _Elem>().allocate(number);
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Construct(_Elem* start, _Elem* finish)
	{
		while (start < finish)
		{
			H3ObjectAllocator< _Elem>().construct(start);
			++start;
		}
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Destruct(_Elem* start, _Elem* finish)
	{
		while (start < finish)
		{
			H3ObjectAllocator< _Elem>().destroy(start);
			++start;
		}
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Deallocate()
	{
		H3ObjectAllocator<_Elem>().deallocate(m_first);
	}

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::reserveExtra(INT32 number)
	{
		const INT32 count = Count();
		const INT32 capacity = CountMax();
		const INT32 avail = capacity - count;
		if (avail >= number)
			return TRUE;

		return Reserve(EXPAND_NUMBER(number));
	}
	template<typename _Elem>
	inline UINT H3Vector<_Elem>::EXPAND_NUMBER(UINT minimumNeeded)
	{
		UINT cap = CountMax();
		UINT num = std::max(cap * GROWTH_MULTIPLIER, MIN_ELEMENTS);
		return std::max(num, minimumNeeded);
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(UINT number_elements) :
		m_first(nullptr),
		m_end(nullptr),
		m_capacity(nullptr)
	{
		Reserve(number_elements);
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector() :
		m_first(nullptr),
		m_end(nullptr),
		m_capacity(nullptr)
	{
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(H3Vector<_Elem>&& other) :
		m_first(other.m_first), m_end(other.m_end), m_capacity(other.m_capacity)
	{
		other.m_first    = nullptr;
		other.m_end      = nullptr;
		other.m_capacity = nullptr;
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(H3Vector<_Elem>&& other)
	{
		if (&other == this)
			return *this;
		RemoveAll();
		m_first = other.m_first;
		m_end = other.m_end;
		m_capacity = other.m_capacity;
		other.m_first = nullptr;
		other.m_end = nullptr;
		other.m_capacity = nullptr;
		return *this;
	}
	template<typename _Elem>
	inline void H3Vector<_Elem>::swap(H3Vector<_Elem>& other)
	{
		if (&other == this)
			return;

		_Elem* first = m_first;
		_Elem* last = m_end;
		_Elem* cap = m_capacity;
		m_first = other.m_first;
		m_end = other.m_end;
		m_capacity = other.m_capacity;
		other.m_first = first;
		other.m_end = last;
		other.m_capacity = cap;
	}
#endif

	template<typename _Elem>
	inline H3Vector<_Elem>::~H3Vector()
	{
		Deref();
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(const H3Vector<_Elem>& other)
	{
		UINT num = other.Size();
		Resize(num);
		for (UINT i = 0; i < num; ++i)
			(*this)[i] = other[i];
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(const H3Vector<_Elem>& other)
	{
		if (&other == this)
			return *this;
		RemoveAll();
		UINT num = other.Size();
		Resize(num);
		for (UINT i = 0; i < num; ++i)
			(*this)[i] = other[i];
		return *this;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::begin()
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::end()
	{
		return m_end;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::begin() const
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::end() const
	{
		return m_end;
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Init()
	{
		m_first = nullptr;
		m_end = nullptr;
		m_capacity = nullptr;
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Deref()
	{
		if (m_first)
		{
			Destruct(begin(), end());
			Deallocate();
		}
		m_first = nullptr;
		m_end = nullptr;
		m_capacity = nullptr;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::IsEmpty() const
	{
		if (!m_first || m_first == m_end)
			return TRUE;
		return FALSE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::IsFull() const
	{
		if (m_end == m_capacity)
			return TRUE;
		return FALSE;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::Size() const
	{
		return m_end - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::Count() const
	{
		return m_end - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::CountMax() const
	{
		return m_capacity - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::RawSize() const
	{
		return UINT32(m_end) - UINT32(m_first);
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::RawSizeAllocated() const
	{
		return UINT32(m_capacity) - UINT32(m_first);
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::RemoveLast()
	{
		Pop();
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::RemoveAll()
	{
		for (_Elem* i = begin(); i < end(); ++i)
			i->~_Elem();

		m_end = m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Add(const _Elem& item)
	{
		if (!m_first || IsFull())
		{
			if (!Expand())
				return nullptr; // failed
		}
		*m_end = item;
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::AddOne(const _Elem& item)
	{
		if (!m_first)
		{
			if (!Reserve(1))
				return nullptr;
		}
		else if (IsFull())
		{
			if (!Reserve(CountMax() + 1))
				return nullptr;
		}
		*m_end = item;
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::AddSize4(_Elem item)
	{
		THISCALL_4(VOID, 0x5FE2D0, this, m_end, 1, &item);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Expand()
	{
		if (!m_first)
			return Reserve(MIN_ELEMENTS);
		return Reserve(CountMax() * GROWTH_MULTIPLIER);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::First()
	{
		return m_first;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::CFirst() const
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RFirst()
	{
		return *m_first;
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::CRFirst() const
	{
		return *m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Last()
	{
		return m_end - 1;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::CLast() const
	{
		return m_end - 1;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RLast()
	{
		return *Last();
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::CRLast() const
	{
		return *CLast();
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Append(const _Elem& item)
	{
		return Add(item);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Push(const _Elem& item)
	{
		return Add(item);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Pop()
	{
		if (m_end > m_first)
		{
			--m_end;
			m_end->~_Elem();
		}
		return m_end;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::At(UINT32 pos)
	{
		return m_first + pos;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::At(UINT32 pos) const
	{
		return m_first + pos;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RAt(UINT32 pos)
	{
		return *At(pos);
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::RAt(UINT32 pos) const
	{
		return *At(pos);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(UINT32 pos)
	{
		return Remove(begin() + pos, begin() + pos + 1);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(UINT32 fromPos, UINT32 toPos)
	{
		return Remove(begin() + fromPos, begin() + toPos);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(_Elem* first, _Elem* last)
	{
		if (first >= last || IsEmpty())
			return FALSE;
		if (first < m_first)
			first = m_first;
		if (last > m_end)
			last = m_end;

		Destruct(first, last);
#ifdef _H3API_CPLUSPLUS11_
		_Elem* itFirst = first;
		_Elem* itLast = last;
		while (itLast < m_end)
		{
			*itFirst = std::move(*itLast);
			++itFirst;
			++itLast;
		}
#else
		memmove(PVOID(first), PVOID(last), UINT(m_end) - UINT(last));
#endif
		m_end -= last - first;

		return TRUE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(_Elem* elem)
	{
		return Remove(elem, elem + 1);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Reserve(UINT number)
	{
		UINT num = Count();
		if (number <= num)
			return TRUE;

		_Elem* t = Allocate(number);
		if (!t)
			return FALSE;

		Construct(&t[0], &t[number]);

#ifdef _H3API_CPLUSPLUS11_
		for (UINT i = 0; i < num; ++i)
			t[i] = std::move(m_first[i]);
#else
		for (UINT i = 0; i < num; ++i)
			t[i] = m_first[i];
#endif
		Destruct(begin(), end());
		Deallocate();

		m_first = t;
		m_end = m_first + num;
		m_capacity = m_first + number;

		return TRUE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Resize(UINT number)
	{
		const UINT count = Count();

		if (number == count)
		{
			m_end = m_capacity;
			return TRUE;
		}
		if (number > count)
		{
			if (!Reserve(number))
				return FALSE;
			m_end = m_capacity;
			return TRUE;
		}

		Destruct(begin() + number, end());
		m_end = m_first + number;
		_Elem* t = Allocate(number);
		if (!t)
			return FALSE;

		Construct(t, t + number);

#ifdef _H3API_CPLUSPLUS11_
		for (UINT i = 0; i < number; ++i)
			t[i] = std::move(m_first[i]);
#else
		for (UINT i = 0; i < number; ++i)
			t[i] = m_first[i];
#endif
		Destruct(begin(), end());
		Deallocate();

		m_first = t;
		m_end = m_first + number;
		m_capacity = m_end;

		return TRUE;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::operator[](UINT32 pos)
	{
		return m_first[pos];
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::operator[](UINT32 pos) const
	{
		return m_first[pos];
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::operator+=(const _Elem& item)
	{
		return Add(item);
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Add(_Elem&& item)
	{
		if (!m_first || IsFull())
		{
			if (!Expand())
				return nullptr; // failed
		}
		*m_end = std::move(item);
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Push(_Elem&& item)
	{
		return Add(std::move(item));
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::AddOne(_Elem&& item)
	{
		if (!m_first)
		{
			if (!Reserve(1))
				return nullptr;
		}
		else if (IsFull())
		{
			if (!Reserve(CountMax() + 1))
				return nullptr;
		}
		*m_end = std::move(item);
		++m_end;
		return m_end - 1;  // returns position where it was added
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Append(_Elem&& item)
	{
		return Add(std::move(item));
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::operator+=(_Elem&& item)
	{
		return Add(std::move(item));
	}
#endif /* _H3API_CPLUSPLUS11_ */

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, _Elem* first, _Elem* last)
	{
		if (UINT(first) >= UINT(last))
			return FALSE;

		const UINT32 num = last - first;
		const UINT32 currNum = Count();
		UINT32 pos = 0;
		if (!IsEmpty())
		{
			if (UINT(position) > UINT(begin()))
			{
				if (UINT(position) > UINT(end()))
					pos = currNum;
				else
					pos = position - begin();
			}
		}

		if (!reserveExtra(num))
			return FALSE;

		_Elem* origStart = begin() + pos;
		_Elem* newEnd = end() + num - 1;
		_Elem* oldEnd = end() - 1;
		if (pos < currNum)
		{
			while (oldEnd >= origStart)
			{
#ifdef _H3API_CPLUSPLUS11_
				* newEnd-- = std::move(*oldEnd--);
#else
				* newEnd-- = *oldEnd--;
#endif
			}
		}

		_Elem* it = first;
		while (it < last)
		{
			*origStart++ = *it++;
		}

		m_end += num;

		return TRUE;
	}

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, const _Elem& elem)
	{
		_Elem* first = const_cast<_Elem*>(&elem);
		_Elem* last = first + 1;
		return Insert(position, first, last);
	}

#ifdef _H3API_STD_CONVERSIONS_
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, typename std::vector<_Elem>::iterator first, typename std::vector<_Elem>::iterator last)
	{
		if (first >= last)
			return FALSE;

		const INT32 num = std::distance(first, last);
		const INT32 currNum = Count();
		INT32 pos = 0;
		if (!IsEmpty())
		{
			if (UINT(position) > UINT(begin()))
			{
				if (UINT(position) > UINT(end()))
					pos = currNum;
				else
					pos = position - begin();
			}
		}

		if (!reserveExtra(num))
			return FALSE;

		_Elem* origStart = begin() + pos;
		_Elem* newEnd = end() + num - 1;
		_Elem* oldEnd = end() - 1;
		if (pos < currNum)
		{
			while (oldEnd >= origStart)
			{
#ifdef _H3API_CPLUSPLUS11_
				* newEnd-- = std::move(*oldEnd--);
#else
				* newEnd-- = *oldEnd--;
#endif /* _H3API_CPLUSPLUS11_ */
			}
		}

		while (first < last)
		{
			*origStart++ = *first++;
		}
		m_end += num;

		return TRUE;
	}

	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(const std::vector<_Elem>& vec)
	{
		Init();
		const INT n = vec.size();
		Reserve(n);
		for (int i = 0; i < n; ++i)
			Add(const_cast<_Elem&>(vec[i]));
		return *this;
	}
	template<typename _Elem>
	inline std::vector<_Elem> H3Vector<_Elem>::to_std_vector() const
	{
		std::vector<_Elem> vec;
		for (_Elem* i = begin(); i < end(); ++i)
			vec.push_back(*i);

		return vec;
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(const std::vector<_Elem>& vec)
	{
		RemoveAll();
		const INT n = vec.size();
		Reserve(n);
		for (int i = 0; i < n; ++i)
			Add(const_cast<_Elem&>(vec[i]));
		return *this;
	}
#endif /* _H3API_STD_CONVERSIONS_ */
}

namespace h3
{
    namespace NH3Objects
    {
        namespace NObjectTypes
        {
            enum eObjectTypes : INT32
            {
                NO_OBJ                      = -1,
                ALTAR_OF_SACRIFICE          = 2,
                ANCHOR_POINT                = 3,
                ARENA                       = 4,
                ARTIFACT                    = 5,
                PANDORAS_BOX                = 6,
                BLACK_MARKET                = 7,
                BOAT                        = 8,
                BORDERGUARD                 = 9,
                KEYMASTER                   = 10,
                BUOY                        = 11,
                CAMPFIRE                    = 12,
                CARTOGRAPHER                = 13,
                SWAN_POND                   = 14,
                COVER_OF_DARKNESS           = 15,
                CREATURE_BANK               = 16,
                CREATURE_GENERATOR1         = 17,
                CREATURE_GENERATOR2         = 18,
                CREATURE_GENERATOR3         = 19,
                CREATURE_GENERATOR4         = 20,
                CURSED_GROUND               = 21,
                CORPSE                      = 22,
                MARLETTO_TOWER              = 23,
                DERELICT_SHIP               = 24,
                DRAGON_UTOPIA               = 25,
                EVENT                       = 26,
                EYE_OF_MAGI                 = 27,
                FAERIE_RING                 = 28,
                FLOTSAM                     = 29,
                FOUNTAIN_OF_FORTUNE         = 30,
                FOUNTAIN_OF_YOUTH           = 31,
                GARDEN_OF_REVELATION        = 32,
                GARRISON                    = 33,
                HERO                        = 34,
                HILL_FORT                   = 35,
                GRAIL                       = 36,
                HUT_OF_MAGI                 = 37,
                IDOL_OF_FORTUNE             = 38,
                LEAN_TO                     = 39,
                DECORATIVE                  = 40,
                LIBRARY_OF_ENLIGHTENMENT    = 41,
                LIGHTHOUSE                  = 42,
                MONOLITH_ONE_WAY_ENTRANCE   = 43,
                MONOLITH_ONE_WAY_EXIT       = 44,
                MONOLITH_TWO_WAY            = 45,
                MAGIC_PLAINS1               = 46,
                SCHOOL_OF_MAGIC             = 47,
                MAGIC_SPRING                = 48,
                MAGIC_WELL                  = 49,
                MARKET_OF_TIME              = 50,
                MERCENARY_CAMP              = 51,
                MERMAID                     = 52,
                MINE                        = 53,
                MONSTER                     = 54,
                MYSTICAL_GARDEN             = 55,
                OASIS                       = 56,
                OBELISK                     = 57,
                REDWOOD_OBSERVATORY         = 58,
                OCEAN_BOTTLE                = 59,
                PILLAR_OF_FIRE              = 60,
                STAR_AXIS                   = 61,
                PRISON                      = 62,
                PYRAMID                     = 63,
                RALLY_FLAG                  = 64,
                RANDOM_ART                  = 65,
                RANDOM_TREASURE_ART         = 66,
                RANDOM_MINOR_ART            = 67,
                RANDOM_MAJOR_ART            = 68,
                RANDOM_RELIC_ART            = 69,
                RANDOM_HERO                 = 70,
                RANDOM_MONSTER              = 71,
                RANDOM_MONSTER_L1           = 72,
                RANDOM_MONSTER_L2           = 73,
                RANDOM_MONSTER_L3           = 74,
                RANDOM_MONSTER_L4           = 75,
                RANDOM_RESOURCE             = 76,
                RANDOM_TOWN                 = 77,
                REFUGEE_CAMP                = 78,
                RESOURCE                    = 79,
                SANCTUARY                   = 80,
                SCHOLAR                     = 81,
                SEA_CHEST                   = 82,
                SEER_HUT                    = 83,
                CRYPT                       = 84,
                SHIPWRECK                   = 85,
                SHIPWRECK_SURVIVOR          = 86,
                SHIPYARD                    = 87,
                SHRINE_OF_MAGIC_INCANTATION = 88,
                SHRINE_OF_MAGIC_GESTURE     = 89,
                SHRINE_OF_MAGIC_THOUGHT     = 90,
                SIGN                        = 91,
                SIRENS                      = 92,
                SPELL_SCROLL                = 93,
                STABLES                     = 94,
                TAVERN                      = 95,
                TEMPLE                      = 96,
                DEN_OF_THIEVES              = 97,
                TOWN                        = 98,
                TRADING_POST                = 99,
                LEARNING_STONE              = 100,
                TREASURE_CHEST              = 101,
                TREE_OF_KNOWLEDGE           = 102,
                SUBTERRANEAN_GATE           = 103,
                UNIVERSITY                  = 104,
                WAGON                       = 105,
                WAR_MACHINE_FACTORY         = 106,
                SCHOOL_OF_WAR               = 107,
                WARRIORS_TOMB               = 108,
                WATER_WHEEL                 = 109,
                WATERING_HOLE               = 110,
                WHIRLPOOL                   = 111,
                WINDMILL                    = 112,
                WITCH_HUT                   = 113,
                BRUSH                       = 114,
                BUSH                        = 115,
                CACTUS                      = 116,
                CANYON                      = 117,
                CRATER                      = 118,
                DEAD_VEGETATION             = 119,
                FLOWERS                     = 120,
                FROZEN_LAKE                 = 121,
                HEDGE                       = 122,
                HILL                        = 123,
                HOLE                        = 124,
                KELP                        = 125,
                LAKE                        = 126,
                LAVA_FLOW                   = 127,
                LAVA_LAKE                   = 128,
                MUSHROOMS                   = 129,
                LOG                         = 130,
                MANDRAKE                    = 131,
                MOSS                        = 132,
                MOUND                       = 133,
                MOUNTAIN                    = 134,
                OAK_TREES                   = 135,
                OUTCROPPING                 = 136,
                PINE_TREES                  = 137,
                PLANT                       = 138,
                BLANK1                      = 139,
                BLANK2                      = 140,
                BLANK3                      = 141,
                BLANK4                      = 142,
                RIVER_DELTA                 = 143,
                BLANK5                      = 144,
                BLANK6                      = 145,
                BLANK7                      = 146,
                ROCK                        = 147,
                SAND_DUNE                   = 148,
                SAND_PIT                    = 149,
                SHRUB                       = 150,
                SKULL                       = 151,
                STALAGMITE                  = 152,
                STUMP                       = 153,
                TAR_PIT                     = 154,
                TREES                       = 155,
                VINE                        = 156,
                VOLCANIC_TENT               = 157,
                VOLCANO                     = 158,
                WILLOW_TREES                = 159,
                YUCCA_TREES                 = 160,
                REEF                        = 161,
                RANDOM_MONSTER_L5           = 162,
                RANDOM_MONSTER_L6           = 163,
                RANDOM_MONSTER_L7           = 164,
                BRUSH2                      = 165,
                BUSH2                       = 166,
                CACTUS2                     = 167,
                CANYON2                     = 168,
                CRATER2                     = 169,
                DEAD_VEGETATION2            = 170,
                FLOWERS2                    = 171,
                FROZEN_LAKE2                = 172,
                HEDGE2                      = 173,
                HILL2                       = 174,
                HOLE2                       = 175,
                KELP2                       = 176,
                LAKE2                       = 177,
                LAVA_FLOW2                  = 178,
                LAVA_LAKE2                  = 179,
                MUSHROOMS2                  = 180,
                LOG2                        = 181,
                MANDRAKE2                   = 182,
                MOSS2                       = 183,
                MOUND2                      = 184,
                MOUNTAIN2                   = 185,
                OAK_TREES2                  = 186,
                OUTCROPPING2                = 187,
                PINE_TREES2                 = 188,
                PLANT2                      = 189,
                RIVER_DELTA2                = 190,
                ROCK2                       = 191,
                SAND_DUNE2                  = 192,
                SAND_PIT2                   = 193,
                SHRUB2                      = 194,
                SKULL2                      = 195,
                STALAGMITE2                 = 196,
                STUMP2                      = 197,
                TAR_PIT2                    = 198,
                TREES2                      = 199,
                VINE2                       = 200,
                VOLCANIC_TENT2              = 201,
                VOLCANO2                    = 202,
                WILLOW_TREES2               = 203,
                YUCCA_TREES2                = 204,
                REEF2                       = 205,
                DESERT_HILLS                = 206,
                DIRT_HILLS                  = 207,
                GRASS_HILLS                 = 208,
                ROUGH_HILLS                 = 209,
                SUBTERRANEAN_ROCKS          = 210,
                SWAMP_FOLIAGE               = 211,
                BORDER_GATE                 = 212,
                FREELANCERS_GUILD           = 213,
                HERO_PLACEHOLDER            = 214,
                QUEST_GUARD                 = 215,
                RANDOM_DWELLING             = 216,
                RANDOM_DWELLING_LVL         = 217,
                RANDOM_DWELLING_FACTION     = 218,
                GARRISON2                   = 219,
                ABANDONED_MINE              = 220,
                TRADING_POST_SNOW           = 221,
                CLOVER_FIELD                = 222,
                CURSED_GROUND2              = 223,
                EVIL_FOG                    = 224,
                FAVORABLE_WINDS             = 225,
                FIERY_FIELDS                = 226,
                HOLY_GROUNDS                = 227,
                LUCID_POOLS                 = 228,
                MAGIC_CLOUDS                = 229,
                MAGIC_PLAINS2               = 230,
                ROCKLANDS                   = 231,
            };
        }
        typedef NObjectTypes::eObjectTypes eObjectTypes;

        namespace NCrBank
        {
            enum eCrBank
            {
                CYCLOPS_STOCPILE     = 0,
                DWARVEN_TREASURY     = 1,
                GRIFFIN_CONSERVATORY = 2,
                IMP_CACHE            = 3,
                MEDUA_STORES         = 4,
                NAGA_BANK            = 5,
                DRAGON_FLY_HIVE      = 6,
                SHIPWRECK            = 7,
                DERELICT_SHIP        = 8,
                CRYPT                = 9,
                DRAGON_UTOPIA        = 10,
            };
        }
        typedef NCrBank::eCrBank eCrBank;
    } /* namespace NH3Objects */
    typedef NH3Objects::eObjectTypes eObject;
    typedef NH3Objects::eCrBank      eCrBank;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CreatureBank);
	_H3API_DECLARE_(CreatureBankState);
	_H3API_DECLARE_(CreatureBankSetup);
	_H3API_DECLARE_(MapitemCreatureBank);
	struct H3Main;

#pragma pack(push, 4)

	struct H3CreatureBank
	{
		_H3API_SIZE_(0x6C);
		H3Army guardians;
		H3Resources resources;
		INT32 creatureRewardType;
		INT8 creatureRewardCount;
		H3Vector<INT32> artifacts;

		_H3API_ BOOL HasUpgradedStack();
		_H3API_ VOID SetupBank(INT32 type, INT32 level);
		_H3API_ VOID UpgradeStack(BOOL upg);
	};
	_H3API_ASSERT_SIZE_(H3CreatureBank);

	struct H3CreatureBankState
	{
		_H3API_SIZE_(0x60);
		H3Army guardians;
		H3Resources resources;
		INT32 creatureRewardType;
		INT8 creatureRewardCount;
		INT8 chance;
		INT8 upgrade;
		INT8 artifactTypeCounts[4];
	};
	_H3API_ASSERT_SIZE_(H3CreatureBankState);

	struct H3CreatureBankSetup
	{
		_H3API_GET_INFO_(0x47A3C1 + 1, H3CreatureBankSetup);

		H3String name;
		H3CreatureBankState states[4];
	};

	struct H3MapitemCreatureBank
	{
		unsigned _u1      : 5;
		unsigned  visited : 8;
		unsigned  id      : 12;
		unsigned  taken   : 1;
		unsigned _u2      : 6;

		_H3API_ H3CreatureBank* Get();
		_H3API_ H3CreatureBank* Get(H3Main* main);
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Skills
    {
        namespace NPrimarySkills
        {
            enum ePrimarySkills : INT32
            {
                ATTACK       = 0,
                DEFENSE      = 1,
                SPELL_POWER  = 2,
                KNOWLEDGE    = 3,
            };
        }
        typedef NPrimarySkills::ePrimarySkills ePrimarySkills;

        namespace NSecondarySkills
        {
            enum eSecondary : INT32
            {
                NONE         = -1,
                PATHFINDING  = 0,
                ARCHERY      = 1,
                LOGISTICS    = 2,
                SCOUTING     = 3,
                DIPLOMACY    = 4,
                NAVIGATION   = 5,
                LEADERSHIP   = 6,
                WISDOM       = 7,
                MYSTICISM    = 8,
                LUCK         = 9,
                BALLISTICS   = 10,
                EAGLE_EYE    = 11,
                NECROMANCY   = 12,
                ESTATES      = 13,
                FIRE_MAGIC   = 14,
                AIR_MAGIC    = 15,
                WATER_MAGIC  = 16,
                EARTH_MAGIC  = 17,
                SCHOLAR      = 18,
                TACTICS      = 19,
                ARTILLERY    = 20,
                LEARNING     = 21,
                OFFENSE      = 22,
                ARMORER      = 23,
                INTELLIGENCE = 24,
                SORCERY      = 25,
                RESISTANCE   = 26,
                FIRST_AID    = 27,
            };
        }
        typedef NSecondarySkills::eSecondary eSecondary;

        namespace NSecSkillLevel
        {
            enum eSecSkillLevel : INT32
            {
                NONE     = 0,
                BASIC    = 1,
                ADVANCED = 2,
                EXPERT   = 3,
            };
        }
        typedef NSecSkillLevel::eSecSkillLevel eSecSkillLevel;
    } /* namespace NH3Skills */
    typedef NH3Skills::ePrimarySkills   ePrimary;
    typedef NH3Skills::eSecondary eSecondary;
    typedef NH3Skills::eSecSkillLevel   eSecSkillLevel;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PrimarySkills);

#pragma pack(push, 4)

	struct H3PrimarySkills
	{
		union
		{
			struct
			{
				INT8 attack;
				INT8 defense;
				INT8 spellPower;
				INT8 knowledge;
			};
			INT8 priSkills[4];
		};

		_H3API_ PINT8 begin();
		_H3API_ PINT8 end();
		_H3API_ INT8& Get(ePrimary skill);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PandorasBox);
	_H3API_DECLARE_(MapitemPandorasBox);
	struct H3Main;
	struct H3SecondarySkill;

#pragma pack(push, 4)

	struct H3PandorasBox
	{
		_H3API_SIZE_(0xE4);
		H3String message;
		BOOL8 customizedGuards;
		H3Army guardians;
		BOOL8 hasMessageOrGuardians;
		INT32 experience;
		INT32 spellPoints;
		INT8 morale;
		INT8 luck;
		H3Resources resources;
		H3PrimarySkills pSkill;
		H3Vector<H3SecondarySkill> sSkills;
		H3Vector<INT32> artifacts;
		H3Vector<INT32> spells;
		H3Army creatureReward;
	};
	_H3API_ASSERT_SIZE_(H3PandorasBox);

	struct H3MapitemPandorasBox
	{
		unsigned id : 10;

		_H3API_ H3PandorasBox* Get();
		_H3API_ H3PandorasBox* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemEvent);
	_H3API_DECLARE_(Event);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Event : H3PandorasBox
	{
	};

	struct H3MapitemEvent
	{
		unsigned  id        : 10;
		unsigned  enabled   : 8;
		unsigned  aiEnabled : 1;
		unsigned  oneVisit  : 1;
		unsigned _u1        : 12;

		_H3API_ H3Event*          Get();
		_H3API_ H3Event*          Get(H3Main* main);
		_H3API_ H3PlayersBitfield EnabledPlayers();
		_H3API_ VOID              SetEnabled(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemFlotsam);

#pragma pack(push, 4)

	struct H3MapitemFlotsam
	{
		enum eType : INT32
		{
			EMPTY,
			WOOD5,
			WOOD5_GOLD200,
			WOOD10_GOLD500,
		};
		eType type;

		_H3API_ INT32 GetWood() const;
		_H3API_ INT32 GetGold() const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemFountainFortune);

#pragma pack(push, 4)

	struct H3MapitemFountainFortune
	{
		unsigned _u1       : 5;
		unsigned visited   : 8;
		  signed bonusLuck : 4;
		unsigned _u2       : 15;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemGarrison);
	_H3API_DECLARE_(Garrison);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Garrison
	{
		_H3API_SIZE_(0x40);
		INT8 owner;
		H3Army army;
		BOOL8 canRemoveCreatures;
		UINT8 x;
		UINT8 y;
		UINT8 z;
	};
	_H3API_ASSERT_SIZE_(H3Garrison);

	struct H3MapitemGarrison
	{
		UINT32 index;

		_H3API_ H3Garrison* Get();
		_H3API_ H3Garrison* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Generator);
	_H3API_DECLARE_(MapitemGenerator);
	_H3API_TYPE_DECLARE_(H3Generator, Dwelling);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Generator
	{
		_H3API_SIZE_(0x5C);
		INT8 type;
		INT8 subtype;
		INT32 creatureTypes[4];
		INT16 creatureCounts[4];
		H3Army defenders;
		UINT8 x;
		UINT8 y;
		UINT8 z;
		INT8 ownerID;
	protected:
		h3unk8 _f58;
	};
	_H3API_ASSERT_SIZE_(H3Generator);

	struct H3MapitemGenerator
	{
		INT32 id;

		_H3API_ H3Generator* Get();
		_H3API_ H3Generator* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemHero);
	struct H3Main;
	struct H3Hero;

#pragma pack(push, 4)

	struct H3MapitemHero
	{
		INT32 index;

		_H3API_ H3Hero* Get();
		_H3API_ H3Hero* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Terrain
    {
        enum eTerrainType : INT32
        {
            DIRT         = 0,
            SAND         = 1,
            GRASS        = 2,
            SNOW         = 3,
            SWAMP        = 4,
            ROUGH        = 5,
            SUBTERRANEAN = 6,
            LAVA         = 7,
            WATER        = 8,
            ROCK         = 9,
        };
    } /* namespace NH3Terrain */
    typedef NH3Terrain::eTerrainType eTerrain;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemLeanTo);

#pragma pack(push, 4)

	struct H3MapitemLeanTo
	{
		unsigned  id : 5;
		unsigned _u1 : 1;
		unsigned  resValue : 4;
		unsigned  resType : 4;
		unsigned _u2 : 18;

		_H3API_ eResource GetType();
		_H3API_ INT32     GetAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemLearningStone);

#pragma pack(push, 4)

	struct H3MapitemLearningStone
	{
		INT32 id;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMine);
	_H3API_DECLARE_(Mine);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Mine
	{
		_H3API_SIZE_(0x40);
		INT8 owner;
		INT8 type;
		BOOL8 abandoned;
		H3Army army;
		UINT8 x;
		UINT8 y;
		UINT8 z;

		_H3API_ BOOL IsAbandonned() const;
	};
	_H3API_ASSERT_SIZE_(H3Mine);

	struct H3MapitemMine
	{
		INT32 index;

		_H3API_ H3Mine* Get();
		_H3API_ H3Mine* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemLighthouse);

#pragma pack(push, 4)

	struct H3Lighthouse : H3Mine
	{
	};

	struct H3MapitemLighthouse : H3MapitemMine
	{
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Spells
    {
        namespace NSchool
        {
            enum eSchool : INT32
            {
                AIR   = 1,
                FIRE  = 2,
                WATER = 4,
                EARTH = 8,
                ALL   = AIR | FIRE | WATER | EARTH,
            };
        }
        typedef NSchool::eSchool eSchool;

        namespace NTargetType
        {
            enum eTargetType : INT32
            {
                ENEMY    = -1,
                AREA     = 0,
                FRIENDLY = 1,
            };
        }
        typedef NTargetType::eTargetType eTargetType;

        namespace NSpells
        {
            enum eSpell : INT8
            {
                NONE                  = -1,
                SUMMON_BOAT           = 0,
                SCUTTLE_BOAT          = 1,
                VISIONS               = 2,
                VIEW_EARTH            = 3,
                DISGUISE              = 4,
                VIEW_AIR              = 5,
                FLY                   = 6,
                WATER_WALK            = 7,
                DIMENSION_DOOR        = 8,
                TOWN_PORTAL           = 9,
                QUICK_SAND            = 10,
                LAND_MINE             = 11,
                FORCE_FIELD           = 12,
                FIRE_WALL             = 13,
                EARTHQUAKE            = 14,
                MAGIC_ARROW           = 15,
                ICE_BOLT              = 16,
                LIGHTNING_BOLT        = 17,
                IMPLOSION             = 18,
                CHAIN_LIGHTNING       = 19,
                FROST_RING            = 20,
                FIREBALL              = 21,
                INFERNO               = 22,
                METEOR_SHOWER         = 23,
                DEATH_RIPPLE          = 24,
                DESTROY_UNDEAD        = 25,
                ARMAGEDDON            = 26,
                SHIELD                = 27,
                AIR_SHIELD            = 28,
                FIRE_SHIELD           = 29,
                PROTECTION_FROM_AIR   = 30,
                PROTECTION_FROM_FIRE  = 31,
                PROTECTION_FROM_WATER = 32,
                PROTECTION_FROM_EARTH = 33,
                ANTI_MAGIC            = 34,
                DISPEL                = 35,
                MAGIC_MIRROR          = 36,
                CURE                  = 37,
                RESURRECTION          = 38,
                ANIMATE_DEAD          = 39,
                SACRIFICE             = 40,
                BLESS                 = 41,
                CURSE                 = 42,
                BLOODLUST             = 43,
                PRECISION             = 44,
                WEAKNESS              = 45,
                STONE_SKIN            = 46,
                DISRUPTING_RAY        = 47,
                PRAYER                = 48,
                MIRTH                 = 49,
                SORROW                = 50,
                FORTUNE               = 51,
                MISFORTUNE            = 52,
                HASTE                 = 53,
                SLOW                  = 54,
                SLAYER                = 55,
                FRENZY                = 56,
                TITANS_LIGHTNING_BOLT = 57,
                COUNTERSTRIKE         = 58,
                BERSERK               = 59,
                HYPNOTIZE             = 60,
                FORGETFULNESS         = 61,
                BLIND                 = 62,
                TELEPORT              = 63,
                REMOVE_OBSTACLE       = 64,
                CLONE                 = 65,
                FIRE_ELEMENTAL        = 66,
                EARTH_ELEMENTAL       = 67,
                WATER_ELEMENTAL       = 68,
                AIR_ELEMENTAL         = 69,
                STONE                 = 70,
                POISON                = 71,
                BIND                  = 72,
                DISEASE               = 73,
                PARALYZE              = 74,
                AGING                 = 75,
                DEATH_CLOUD           = 76,
                THUNDERBOLT           = 77,
                DRAGONFLY_DISPEL      = 78,
                DEATH_STARE           = 79,
                ACID_BREATH           = 80,
            };
        }
        typedef NSpells::eSpell eSpell;
    } /* namespace NH3Spells */
    typedef NH3Spells::eSchool     eSpellchool;
    typedef NH3Spells::eTargetType eSpellTarget;
    typedef NH3Spells::eSpell     eSpell;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMagicShrine);

#pragma pack(push, 4)

	struct H3MapitemMagicShrine
	{
		unsigned _u1    : 13;
		unsigned  spell : 10;
		unsigned _u2    : 9;

		_H3API_ eSpell GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMagicSpring);

#pragma pack(push, 4)

	struct H3MapitemMagicSpring
	{
		unsigned  id : 5;
		unsigned _u1 : 1;
		unsigned  used : 1;
		unsigned _u2 : 25;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMonolith);

#pragma pack(push, 4)

	struct H3MapitemMonolith
	{
		INT32 index;

		_H3API_ INT32 GetSubtype();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMonster);
	_H3API_DECLARE_(Monster);
	struct H3Main;
	struct H3Hero;

#pragma pack(push, 4)
	struct H3Monster
	{
		_H3API_SIZE_(0x30);
		H3String message;
		H3Resources resources;
		INT32 artifact;
	};
	_H3API_ASSERT_SIZE_(H3Monster);

	struct H3MapitemMonster
	{
		unsigned  count : 12;
		signed  aggression : 5;
		unsigned  noRun : 1;
		unsigned  noGrowth : 1;
		unsigned  setupIndex : 8;
		unsigned  growthRemainder : 4;
		unsigned  hasSetup : 1;

		_H3API_ H3Monster* Get() const;
		_H3API_ H3Monster* Get(H3Main* main) const;
		_H3API_ INT32 CreatureType() const;
		_H3API_ INT32 DiploJoinCost(H3Hero* hero) const;
	};
	struct SODSP_MapMonster
	{
		unsigned  count : 12;
		signed  aggression : 5;
		unsigned  noRun : 1;
		unsigned  noGrowth : 1;
		unsigned  setupIndex : 12;
		unsigned  hasSetup : 1;

		_H3API_ H3Monster* Get();
		_H3API_ H3Monster* Get(H3Main* main);
		_H3API_ INT32 CreatureType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemMysticGarden);

#pragma pack(push, 4)

	struct H3MapitemMysticGarden
	{
		unsigned  id      : 5;
		unsigned _u1      : 1;
		unsigned  resType : 4;
		unsigned  hasRes  : 1;
		unsigned _u2      : 21;

		_H3API_ INT32     GetAmount();
		_H3API_ eResource GetType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemObelisk);

#pragma pack(push, 4)

	struct H3MapitemObelisk
	{
		UINT32 id;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemSign);
	_H3API_DECLARE_(SignPost);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Signpost
	{
		_H3API_SIZE_(0x14);
		BOOL8    hasMessage;
		H3String message;
	};
	_H3API_ASSERT_SIZE_(H3Signpost);

	struct H3MapitemSign
	{
		INT32 id;

		_H3API_ H3Signpost* Get();
		_H3API_ H3Signpost* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemOceanBottle);

#pragma pack(push, 4)

	struct H3OceanBottle : H3Signpost
	{
	};

	struct H3MapitemOceanBottle : H3MapitemSign
	{
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemPrison);

#pragma pack(push, 4)

	struct H3MapitemPrison : H3MapitemHero
	{
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemPyramid);

#pragma pack(push, 4)

	struct H3MapitemPyramid
	{
		unsigned  available : 1;
		unsigned  id        : 4;
		unsigned  visited   : 8;
		unsigned  spell     : 8;
		unsigned _u1        : 11;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ eSpell GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Quest
    {
        namespace NQuestType
        {
            enum eQuestType
            {
                NONE             = 0,
                EXPERIENCE_LEVEL = 1,
                PRIMARY_SKILL    = 2,
                DEFEAT_HERO      = 3,
                DEFEAT_MONSTER   = 4,
                BRING_ARTIFACTS  = 5,
                BRING_CREATURES  = 6,
                BRING_RESOURCES  = 7,
                BE_HERO          = 8,
                BE_PLAYER        = 9,
            };
        }
        typedef NQuestType::eQuestType eQuestType;

        namespace NSeerReward
        {
            enum eSeerReward
            {
                NONE            = 0,
                EXPERIENCE      = 1,
                SPELL_POINTS    = 2,
                MORALE          = 3,
                LUCK            = 4,
                RESOURCE        = 5,
                PRIMARY_SKILL   = 6,
                SECONDARY_SKILL = 7,
                ARTIFACT        = 8,
                SPELL           = 9,
                CREATURE        = 10,
            };
        }
        typedef NSeerReward::eSeerReward eSeerReward;
    }
    typedef NH3Quest::eQuestType  eQuest;
    typedef NH3Quest::eSeerReward eSeer;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemQuestGuard);
	_H3API_DECLARE_(QuestGuard);
	template<typename _Elem> struct H3Vector;
	struct H3Main;
	struct H3Resources;

#pragma pack(push, 4)
	struct H3Quest
	{
		_H3API_SIZE_(0x60);
		struct QuestVector
		{
		protected:
			h3unk8 _allocator;
			INT32* first;
			INT32* last;
			INT32* capacity;
		public:
			_H3API_ INT32  Count();
			_H3API_ INT32& operator[](INT32 index);
			_H3API_ INT32* begin();
			_H3API_ INT32* end();
		};

		struct QuestVTable
		{
			h3func dtor;
			h3func aiValue;
			h3func conditionMet;
			h3func removeFromHero;
			h3func showMessage1;
			h3func showMessage2;
			h3func objectiveText;
			h3func customText;
			h3func type;
			h3func vt09;
			h3func vt10;
			h3func vt11;
			h3func vt12;
			h3func vt13;
			h3func vt14;
		}*vTable;


		BOOL hasReward;
		H3String messageProposal;
		H3String messageProgress;
		H3String messageCompletion;
		INT32 stringId;
		INT32 lastDay;
		union QuestData
		{
			INT32 achieveLevel;						// achieve level
			H3PrimarySkills achievePrimarySkill;	// have primary skills
			struct
			{
				INT32 _f_00;
				INT32 targetHero;
				INT32 successfulPlayers;
			} killHero;						// kill certain hero
			struct
			{
				INT32 _f_00;
				UINT32 packedCoords; // H3Position, error C2620 workaround use GetCoordinates()
				INT32 displayCreatureType;
				INT32 player;
			} killMonster;					// kill a monster in certain position on the map
			QuestVector getArtifacts;		// bring artifacts
			struct
			{
				QuestVector number;
				QuestVector type;
			} getCreatures;					// bring creatures
			INT getResources[7];			// bring resources
			INT32 beHero;					// visit as a certain hero
			INT32 bePlayer;					// visit as a certain player
		} data;

		_H3API_ H3Point          GetCoordinates() const;
		_H3API_ eQuest           GetQuestType() const;
		_H3API_ H3Resources&     GetResources();
		_H3API_ H3Vector<INT32>& GetArtifacts();
		_H3API_ H3Vector<INT32>& GetCreatureCounts();
		_H3API_ H3Vector<INT32>& GetCreatureTypes();
	};
	_H3API_ASSERT_SIZE_(H3Quest);

	struct H3MapitemQuestGuard
	{
		UINT id;

		_H3API_ H3QuestGuard* Get();
		_H3API_ H3QuestGuard* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)
	struct H3QuestGuard
	{
		_H3API_SIZE_(0x5);
		H3Quest* quest;
		H3PlayersBitfield playersVisited;

		_H3API_ eQuest QuestType() const;
	};
	_H3API_ASSERT_SIZE_(H3QuestGuard);
#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemRefugeeCamp);

#pragma pack(push, 4)

	struct H3MapitemRefugeeCamp
	{
		INT32 amount;

		INT32 CreatureType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapResource);
	_H3API_DECLARE_(MapitemResource);
	struct H3Main;

#pragma pack(push, 4)

	struct H3MapResource : H3MapArtifact
	{
	};

	struct H3MapitemResource
	{
		unsigned value      : 19;
		unsigned setupIndex : 12;
		unsigned hasSetup   : 1;

		_H3API_ H3MapResource* Get();
		_H3API_ H3MapResource* Get(H3Main* main);
		_H3API_ eResource      GetType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemScholar);

#pragma pack(push, 4)

	struct H3MapitemScholar
	{
		enum eType
		{
			PRIMARY_SKILL,
			SECONDARY_SKILL,
			SPELL,
		};

		unsigned  type   : 3;
		unsigned  pSkill : 3;
		unsigned  sSkill : 7;
		unsigned  spell  : 10;
		unsigned _u1     : 9;

		_H3API_ eType      GetType();
		_H3API_ ePrimary   GetPrimary();
		_H3API_ eSecondary GetSecondary();
		_H3API_ eSpell     GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemScroll);
	struct H3Main;

#pragma pack(push, 4)
	struct H3MapScroll : H3MapArtifact
	{
	};

	struct H3MapitemScroll
	{
		unsigned  type     : 8;
		unsigned _u1       : 11;
		unsigned  id       : 12;
		unsigned  hasSetup : 1;

		_H3API_ H3MapArtifact* Get();
		_H3API_ H3MapArtifact* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemSeaChest);

#pragma pack(push, 4)

	struct H3MapitemSeaChest
	{
		enum eType
		{
			EMPTY,
			GOLD1500,
			GOLD1000_ARTIFACT,
		};

		unsigned level      : 2;
		unsigned _u1        : 1;
		unsigned artifactID : 10;
		unsigned _u2        : 19;

		_H3API_ eType     GetType();
		_H3API_ eArtifact GetArtifact();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemSeerHut);

#pragma pack(push, 1)
	struct H3SeerHut : H3QuestGuard
	{
		_H3API_SIZE_(0x13);

		INT32 rewardType;
		INT32 rewardValue;
		INT32 rewardValue2;
		BYTE seerNameId;
		h3unk8 _f_12;

		_H3API_ WORD  CreatureCount() const;
		_H3API_ INT8  Luck() const;
		_H3API_ INT8  Morale() const;
		_H3API_ INT32 Primary() const;
		_H3API_ INT8  PrimaryCount() const;
	};
	_H3API_ASSERT_SIZE_(H3SeerHut);
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)

	struct H3MapitemSeerHut
	{
		UINT id;

		_H3API_ H3SeerHut* Get();
		_H3API_ H3SeerHut* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemShipwreckSurvivor);

#pragma pack(push, 4)

	struct H3MapitemShipwreckSurvivor
	{
		INT32 artifactId;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Players
    {
        namespace NPlayerColors
        {
            enum ePlayerColors : INT32
            {
                RED    = 0,
                BLUE   = 1,
                TAN    = 2,
                GREEN  = 3,
                ORANGE = 4,
                PURPLE = 5,
                TEAL   = 6,
                PINK   = 7,
            };
        }
        typedef NPlayerColors::ePlayerColors ePlayerColors;

        namespace NPlayerBit
        {
            enum ePlayerBit : UINT8
            {
                BIT_RED    = 0x01,
                BIT_BLUE   = 0x02,
                BIT_TAN    = 0x04,
                BIT_GREEN  = 0x08,
                BIT_ORANGE = 0x10,
                BIT_PURPLE = 0x20,
                BIT_TEAL   = 0x40,
                BIT_PINK   = 0x80,
            };
        }
        typedef NPlayerBit::ePlayerBit ePlayerBit;
    } /* namespace NH3Players */
    typedef NH3Players::ePlayerColors ePlayer;
    typedef NH3Players::ePlayerBit    ePlayerBit;
} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemShipyard);

#pragma pack(push, 4)

	struct H3MapitemShipyard
	{
		unsigned  owner : 8;
		unsigned  x : 8;
		unsigned  y : 8;
		unsigned _u3 : 8;

		_H3API_ ePlayer GetOwner();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemTown);
	struct H3Main;
	struct H3Town;

#pragma pack(push, 4)

	struct H3MapitemTown
	{
		INT32 id;

		_H3API_ H3Town* Get();
		_H3API_ H3Town* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemTreasureChest);

#pragma pack(push, 4)

	struct H3MapitemTreasureChest
	{
		unsigned artifactID : 10;
		unsigned hasArtifact : 1;
		unsigned bonus : 4;
		unsigned _u1 : 17;

		eArtifact GetArtifact();
		INT32     GetGold();
		INT32     GetExperience();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemTreeOfKnowledge);

#pragma pack(push, 4)

	struct H3MapitemTreeOfKnowledge
	{
		enum eType
		{
			FREE,
			GOLD2000,
			GEMS10,
		};

		unsigned  id      : 5;
		unsigned  visited : 8;
		unsigned  type    : 2;
		unsigned _u1      : 17;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ eType GetType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemUniversity);
	_H3API_DECLARE_(University);
	struct H3Main;

#pragma pack(push, 4)

	struct H3University
	{
		_H3API_SIZE_(0x10);

		INT32 sSkill[4];

		_H3API_ PINT begin();
		_H3API_ PINT end();
	};
	_H3API_ASSERT_SIZE_(H3University);

	struct H3MapitemUniversity
	{
		unsigned _u1      : 5;
		unsigned  visited : 8;
		unsigned  id      : 12;
		unsigned _u2      : 7;

		_H3API_ H3University*     Get();
		_H3API_ H3University*     Get(H3Main* main);
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemWagon);

#pragma pack(push, 4)

	struct H3MapitemWagon
	{
		unsigned  resValue    : 5;
		unsigned  visited     : 8;
		unsigned  hasBonus    : 1;
		unsigned  hasArtifact : 1;
		unsigned  artifactID  : 10;
		unsigned  resType     : 4;
		unsigned _u3          : 3;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
		_H3API_ eArtifact         GetArtifact();
		_H3API_ eResource         GetResourceType();
		_H3API_ INT32             GetResourceAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemWarriorsTomb);

#pragma pack(push, 4)

	struct H3MapitemWarriorsTomb
	{
		unsigned  hasArt : 1;
		unsigned _u1 : 4;
		unsigned  visited : 8;
		unsigned  artifactID : 10;
		unsigned _u2 : 9;

		_H3API_ eArtifact         GetArtifact();
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemWaterMill);

#pragma pack(push, 4)

	struct H3MapitemWaterMill
	{
		unsigned  bonus   : 5;
		unsigned  visited : 8;
		unsigned _u1      : 19;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ INT32 GetGold();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemWindmill);

#pragma pack(push, 4)

	struct H3MapitemWindmill
	{
		unsigned  resType  : 4;
		unsigned _u1       : 9;
		unsigned  resValue : 4;
		unsigned _u2       : 15;

		_H3API_ eResource GetType();
		_H3API_ INT32     GetAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapitemWitchHut);

#pragma pack(push, 4)

	struct H3MapitemWitchHut
	{
		unsigned _u1      : 5;
		signed    visited : 8;
		signed    sSkill  : 7;
		unsigned _u2      : 12;

		_H3API_ eSecondary        GetSkill();
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ObjectAttributes);

#pragma pack(push, 4)

	struct H3ObjectAttributes
	{
		_H3API_SIZE_(0x44);

		H3String defName;
		UINT8 width;
		UINT8 height;
		H3ObjectMask colors;
		H3ObjectMask passability;
		H3ObjectMask shadows;
		H3ObjectMask entrances;
		H3TerrainBitfield maskTerrain;
		INT32 type;
		INT32 subtype;
		BOOL8 flat;
		UINT16 defIndex;
	};
	_H3API_ASSERT_SIZE_(H3ObjectAttributes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapItem);
	_H3API_DECLARE_(ObjectDraw);

#pragma pack(push, 4)

	struct H3ObjectDraw
	{
		_H3API_SIZE_(0x4);
		UINT16 sprite;
		UINT8 tileID;
		UINT8 layer;

		_H3API_ H3ObjectDraw(UINT16 sprite, UINT8 tile_id, UINT8 layer);
	};
	_H3API_ASSERT_SIZE_(H3ObjectDraw);

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)

	struct H3MapItem
	{
		_H3API_SIZE_(0x26);

		union
		{
			UINT32                     setup;
			H3MapitemArtifact          artifact;
			H3MapitemBlackMarket       blackMarket;
			H3MapitemBoat              boat;
			H3MapitemCampfire          campfire;
			H3MapitemCorpse            corpse;
			H3MapitemCreatureBank      creatureBank;
			H3MapitemEvent             event;
			H3MapitemFlotsam           flotsam;
			H3MapitemFountainFortune   fountainFortune;
			H3MapitemGarrison          garrison;
			H3MapitemGenerator         generator;
			H3MapitemHero              hero;
			H3MapitemLeanTo            leanTo;
			H3MapitemLearningStone     learningStone;
			H3MapitemLighthouse        lighthouse;
			H3MapitemMagicShrine       magicShrine;
			H3MapitemMagicSpring       magicSpring;
			H3MapitemMine              mine;
			H3MapitemMonolith          monolith;
			H3MapitemMonster           wanderingCreature;
			H3MapitemMysticGarden      mysticGarden;
			H3MapitemObelisk           obelisk;
			H3MapitemOceanBottle       oceanBottle;
			H3MapitemPandorasBox       pandorasBox;
			H3MapitemPrison            prison;
			H3MapitemPyramid           pyramid;
			H3MapitemQuestGuard        questGuard;
			H3MapitemRefugeeCamp       refugeeCamp;
			H3MapitemResource          resource;
			H3MapitemScholar           scholar;
			H3MapitemScroll            spellScroll;
			H3MapitemSeaChest          seaChest;
			H3MapitemSeerHut           seerHut;
			H3MapitemShipwreckSurvivor shipwreckSurvivor;
			H3MapitemShipyard          shipyard;
			H3MapitemSign              signPost;
			H3MapitemTown              town;
			H3MapitemTreasureChest     treasureChest;
			H3MapitemTreeOfKnowledge   treeKnowledge;
			H3MapitemUniversity        university;
			H3MapitemWagon             wagon;
			H3MapitemWarriorsTomb      warriorsTomb;
			H3MapitemWaterMill         watermill;
			H3MapitemWindmill          windmill;
			H3MapitemWitchHut          witchHut;
			SODSP_MapMonster           sodspWanderingCreature;
		};
		INT8 land;
		INT8 landSprite;
		INT8 river;
		INT8 riverSprite;
		INT8 road;
		INT8 roadSprite;
	protected:
		h3unk16 _f_0A;
	public:
		union {
			struct {
				BOOL8 tileMirrorH  : 1; /** @brief [01]*/
				BOOL8 tileMirrorV  : 1; /** @brief [02]*/
				BOOL8 riverMirrorH : 1; /** @brief [04]*/
				BOOL8 riverMirrorV : 1; /** @brief [08]*/
				BOOL8 roadMirrorH  : 1; /** @brief [10]*/
				BOOL8 roadMirrorV  : 1; /** @brief [20]*/
				BOOL8 canDig       : 1; /** @brief [40]*/
				BOOL8 animated     : 1; /** @brief [80] (river, water or lava terrain)*/
			};
			UINT8 mirror;
		};
		union {
			struct {
				BOOL8 cannotAccess   : 1; /** @brief [01]*/
				BOOL8 waterEdge      : 1; /** @brief [02] see 0x4FEA32*/
				BOOL8 unknownAccess1 : 2;
				BOOL8 entranceTile   : 1; /** @brief [10] yellow tile in mapeditor*/
				BOOL8 unknownAccess2 : 3;
			};
			UINT8 access;
		};
		H3Vector<H3ObjectDraw> objectDrawing;
		INT16 objectType;
	protected:
		h3unk16 _f_20;
	public:
		INT16 objectSubtype;
		UINT16 drawnObjectIndex;

		_H3API_ BOOL          CanDig() const;
		_H3API_ H3University* GetUniversity();
		_H3API_ H3MapItem*    GetEntrance();
		_H3API_ INT           GetRealType() const;
		_H3API_ UINT          GetRealSetup() const;
		_H3API_ H3Point       GetCoordinates() const;
		_H3API_ BOOL          IsBlocked() const;
		_H3API_ BOOL          IsEntrance() const;
	};
	_H3API_ASSERT_SIZE_(H3MapItem);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ObjectDetails);

#pragma pack(push, 4)

	struct H3ObjectDetails
	{
		_H3API_SIZE_(0xC);
		UINT32 setup;
		UINT8 x;
		UINT8 y;
		UINT8 z;
		UINT16 num;
		UINT8 frameRandomness;
	};
	_H3API_ASSERT_SIZE_(H3ObjectDetails);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TileVision);

#pragma pack(push, 4)

	struct H3TileVision
	{
		_H3API_SIZE_(0x2);
		_H3API_GET_INFO_(0x698A48, H3TileVision);

		H3PlayersBitfield vision; // bitfield of players
		BOOL8 zoneControl; // does not exist in Demo

		_H3API_ static H3TileVision& GetTile(INT32 x, INT32 y, INT32 z);
		_H3API_ static H3TileVision& GetTile(const H3Point& p);
		_H3API_ static H3TileVision& GetTile(const H3Position& p);
		_H3API_ static BOOL CanViewTile(INT32 x, INT32 y, INT32 z, INT32 player = -1);
		_H3API_ static BOOL CanViewTile(const H3Point& p, INT32 player = -1);
		_H3API_ static BOOL CanViewTile(const H3Position& p, INT32 player = -1);
		_H3API_ static VOID RevealTile(INT32 x, INT32 y, INT32 z, INT32 player = -1);
		_H3API_ static VOID RevealTile(const H3Point& p, INT32 player = -1);
		_H3API_ static VOID RevealTile(const H3Position& p, INT32 player = -1);
		_H3API_ static H3Map<H3TileVision>     GetMap();
		_H3API_ static H3FastMap<H3TileVision> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3TileVision);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Pathfinder);
	typedef H3Pathfinder H3MovementMgr;
	struct H3PathNode;

#pragma pack(push, 4)
	struct H3Pathfinder
	{
		_H3API_SIZE_(0x70);
		_H3API_GET_INFO_(0x6992D4, H3Pathfinder);
	protected:
		h3unk8 _f_00[8];
	public:
		INT32 availableMovement;
		INT32 maxLandMovement;
		INT32 maxWaterMovement;
		h3unk8 _f_14;
		BOOL8 ddAccess;
		BOOL8 flyAccess;
		BOOL8 waterwalkAccess;
		INT32 waterwalkLevel;
		INT32 flyLevel;
	protected:
		h3unk8 _f_20[4];
	public:
		union
		{
			H3PathNode* movementInfo;
			H3PathNode* pathNodes;
		};
	protected:
		h3unk8 _f_28[8];
	public:
		INT32 mapX;
		INT32 mapY;
	protected:
		H3Vector<h3unk8[30]> _f_38;
	public:
		H3Vector<H3Position> arrowPath;
	protected:
		H3Vector<h3unk32> _f_58;
	public:
		struct BattleHexes
		{
			h3unk32 hexes[187];
		}*battleHexes;
		UINT* aiData;

		_H3API_ H3PathNode*           GetMovementInfo(UINT32 mixed_position);
		_H3API_ H3PathNode*           GetPathNode(UINT32 mixed_position);
		_H3API_ H3PathNode*           GetPathNode(const H3Position& position);
		_H3API_ H3PathNode*           GetPathNode(const H3Point& pt);
		_H3API_ H3Map<H3PathNode>     GetMap();
		_H3API_ H3FastMap<H3PathNode> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3Pathfinder);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PathNode);
	struct H3MapItem;
	typedef H3PathNode H3TileMovement;

#pragma pack(push, 1)

	struct H3PathNode
	{
		_H3API_SIZE_(0x1E);
	protected:
		H3Position mixedPosition;
	public:
		union
		{
			struct
			{
				unsigned accessible      : 1;   // 1
				unsigned teleporter      : 1;   // 2 (monolith or Subterannean gate), see 56BC7A
				unsigned isWater         : 1;   // 4 see 56BE81
				unsigned magicRestricted : 1;   // 8 ~ cursed ground or antimagic garrison
				unsigned flyableWater    : 1;	// 0x10 entrance? 56BAEF shows water+fly access
				unsigned walkableWater   : 1;	// 0x20 56BAEF shows water+waterwalk access
				unsigned unk2            : 26; 	// 0x40, 0x80, ...
			};
			UINT32 access;
		};
	protected:
		h3unk8 _f_08[16];
	public:
		UINT16 movementCost;
	protected:
		UINT16 movementCost2;
		h3unk8 _f_1C[2];
	public:
		_H3API_ UINT8 GetX() const;
		_H3API_ UINT8 GetY() const;
		_H3API_ UINT8 GetZ() const;
		_H3API_ H3Point GetCoordinates() const;
		_H3API_ BOOL ZoneControlled() const;
		_H3API_ H3MapItem* GetMapItem() const;
	};
	_H3API_ASSERT_SIZE_(H3PathNode);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SimulatedCombat);
	typedef H3SimulatedCombat H3AiFastBattle;
	struct H3SimulatedCreature;
	struct H3Hero;
	struct H3Army;

#pragma pack(push, 4)

	struct H3SimulatedCombat
	{
		_H3API_SIZE_(0x34);
		H3Vector<H3SimulatedCreature> creatures;
		INT32 specialTerrain;
		INT32 spellPoints;
		BOOL8 canCastSpells;
		INT32 armyStrength;
		INT8 tactics;
		H3Hero* hero;
		H3Army* army;
		H3Hero* opponent;
		BOOL8 turrets;
		INT16 turretsLevel;

		_H3API_ VOID DeleteCreatures();
	};
	_H3API_ASSERT_SIZE_(H3SimulatedCombat);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SimulatedCreature);
	typedef H3SimulatedCreature H3FastBattleCreature;

#pragma pack(push, 4)

	struct H3SimulatedCreature
	{
		_H3API_SIZE_(0x48);
		INT32 count;
		INT32 type;
		INT32 num1;
		INT32 num2;
		INT32 speed;
	protected:
		DOUBLE f_14;
		DOUBLE f_1C;
		DOUBLE f_24;
		h3unk8 f_2C[4];
		h3unk8 f_30[4];
		h3unk8 f_34[4];
	public:
		INT32 turretPriority;
		INT32 unitPower;
		INT32 stackPower;
	protected:
		h3unk8 f_44[4];
	};
	_H3API_ASSERT_SIZE_(H3SimulatedCreature);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SimulatedHero);
	typedef H3SimulatedHero H3AICombatInfo;

#pragma pack(push, 4)

	struct H3SimulatedHero
	{
		_H3API_SIZE_(0x28);
		INT heroAttack;
		INT heroDefence;
	protected:
		h3unk8 _f_08[4];
	public:
		INT damage[4];
		INT moveType;
		INT thisSide;
		INT enemySide;
	};
	_H3API_ASSERT_SIZE_(H3SimulatedHero);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SimulatedSpell);
	typedef H3SimulatedSpell H3AIBattleSpell;

#pragma pack(push, 4)

	struct H3SimulatedSpell
	{
		_H3API_SIZE_(0x24);
		_H3API_CTOR_DTOR_(0x4365D0, -1);
		INT32 spellId;
		INT32 skillLevel;
		INT32 spellPower;
		INT32 spellDuration;
	protected:
		h3unk8 _f_10;
		INT32 _f_14; // {-1}
		INT32 _f_18; // {-1}
		INT32 _f_1C; // {0}
		UINT8 _f_20; // {0}
	};
	_H3API_ASSERT_SIZE_(H3SimulatedSpell);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SpellCastInfo);
	struct H3Hero;
	typedef H3SpellCastInfo H3AiSpellCastInfo;

#pragma pack(push, 4)

	struct H3SpellCastInfo
	{
		_H3API_SIZE_(0x410);
		_H3API_VTABLE_(0x63B7D8);
		_H3API_CTOR_DTOR_(0x436610, 0x436880);
		VOID* vtable;
		H3Hero* hero;
		H3Hero* enemyHero;
		INT32 side;
		INT32 enemySide;
		h3unk8 _f_14[8];
		BOOL8 enemyDefeated;
		BOOL8 _f_1D;
		union
		{
			H3SimulatedHero combatInfo;
			H3SimulatedHero heroInfo;
		};
		h3unk32 _f_48;
		h3unk8 _f_4C;
		h3unk8 _f_50[960];
	};
	_H3API_ASSERT_SIZE_(H3SpellCastInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SpellData);
	typedef H3SpellData H3AiSpellData;

#pragma pack(push, 4)

	struct H3SpellData
	{
		_H3API_SIZE_(0x24);

		INT32 spellId;
		INT32 expertise;
		INT32 _f_08;
		INT32 _f_0C;
		INT32 _f_10;
		INT32 actionParameter;
		INT32 _f_18;
		INT32 spellValue;
		INT32 _f_20;
	};
	_H3API_ASSERT_SIZE_(H3SpellData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    _H3API_DECLARE_(Artifact);
    _H3API_DECLARE_(HeldArtifact);
    struct H3ArtifactSetup;

#pragma pack(push, 4)

    struct H3Artifact
    {
        _H3API_SIZE_(8);

        INT32 id;
        INT32 subtype;

        _H3API_ H3Artifact();
        _H3API_ H3Artifact(eArtifact id);
        _H3API_ H3Artifact(eSpell spell_id);
        _H3API_ H3Artifact(INT32 id, INT32 subtype);
        _H3API_ H3Artifact(const H3Artifact& other);
        _H3API_ VOID operator=(const H3Artifact& other);
        _H3API_ BOOL operator==(const H3Artifact& other) const;
        _H3API_ BOOL operator!=(const H3Artifact& other) const;
        _H3API_ VOID                   Clear();
        _H3API_ BOOL                   Empty() const;
        _H3API_ LPCSTR                 GetName() const;
        _H3API_ LPCSTR                 GetDescription() const;
        _H3API_ INT32                  GetCost() const;
        _H3API_ eArtifact              GetCombinationArtifact() const;
        _H3API_ eArtifact              GetId() const;
        _H3API_ eCombinationArtifacts  GetCombinationArtifactIndex() const;
        _H3API_ eArtifactSlots         GetSlot() const;
        _H3API_ eArtifactType          GetType() const;
        _H3API_ const H3ArtifactSetup& GetSetup() const;
        _H3API_ eSpell                 GetSpell() const;
        _H3API_ H3Artifact             Remove();
        _H3API_ eSpell                 ScrollSpell() const;
        _H3API_ VOID                   Swap(H3Artifact& other);

    };
    _H3API_ASSERT_SIZE_(H3Artifact)	;

    struct H3HeldArtifact : H3Artifact
    {
        _H3API_ static H3Artifact& Get();
    };

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    _H3API_DECLARE_(ArtifactSetup);

#pragma pack(push, 4)

    struct H3ArtifactSetup
    {
        _H3API_SIZE_(0x20);
        _H3API_GET_INFO_(0x660B68, H3ArtifactSetup);

        LPCSTR name;
        INT32 cost;
        eArtifactSlots position;
        eArtifactType type;
        LPCSTR description;
        eCombinationArtifacts comboID;
        eArtifact  combinationArtifactId;
        BOOL8 disabled;
        eSpell  newSpell;

        _H3API_ BOOL IsPartOfCombo() const;
    };
    _H3API_ASSERT_SIZE_(H3ArtifactSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	namespace limits
	{
		constexpr INT32 ARTIFACTS              = 141;
		constexpr INT32 ARTIFACT_SLOTS         = 19;
		constexpr INT32 BUILDINGS              = 44;
		constexpr INT32 COMBAT_CREATURES       = 20;  // 21st is usually excluded
		constexpr INT32 CREATURES              = 145; // up to troll
		constexpr INT32 CREATURE_BANKS         = 11;
		constexpr INT32 FORT_ELEMENTS          = 18;
		constexpr INT32 HEROES                 = 156;
		constexpr INT32 HERO_CLASSES           = 18;
		constexpr INT32 OBJECTS                = 232;
		constexpr INT32 PLAYERS                = 8;
		constexpr INT32 RESOURCES              = 7;
		constexpr INT32 SECONDARY_SKILLS       = 28;
		constexpr INT32 SPELLS                 = 70;
		constexpr INT32 TERRAIN                = 10;
		constexpr INT32 TOTAL_CREATURES        = 150;     // catapult..arrow tower
		constexpr INT32 TOTAL_COMBAT_CREATURES = 20  + 1; // 21st is usually excluded
		constexpr INT32 TOTAL_HEROES           = 156 + 7; // hidden campaign heroes
		constexpr INT32 TOTAL_HERO_CLASSES     = 18  + 2; // random hero and placeholder hero
		constexpr INT32 TOTAL_SPELLS           = 81;      // including creature spells
		constexpr INT32 TOWNS                  = 9;
		constexpr INT32 TOWNS_ON_MAP           = 48;
	}
}

namespace h3
{
	template<UINT size>	struct H3Bitset;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<UINT size>
	using Bitset = H3Bitset<size>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

	_H3API_TYPE_DECLARE_(H3Bitset<limits::ARTIFACTS>,    ArtifactBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::CREATURES>,    CreaturesBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::SPELLS>,       SpellsBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::TOWNS_ON_MAP>, VisitedTownsBitset);

#pragma pack(push, 4)
	template<UINT size>
	struct H3Bitset
	{
		static constexpr UINT RawSize();
	protected:
		static constexpr UINT m_length = (size - 1) / 32 + 1;
		UINT m_bits[m_length];

		VOID   set(UINT position, BOOL state);
		VOID   flip(UINT position);
		BOOL   get(UINT position) const;
		VOID   clear();
		UINT64 startMask();
		UINT   endMask();

	public:
		struct iterator
		{
		protected:
			H3Bitset* m_bitset;
			UINT      m_position;
		public:
			iterator(H3Bitset* bitset);
			iterator(H3Bitset* bitset, UINT position);
			iterator& operator++();
			iterator  operator++(int);
			iterator& operator*();
			iterator* operator->();
			iterator& operator~();
			operator BOOL();
			BOOL operator!();
			BOOL operator==(const iterator& other);
			BOOL operator!=(const iterator& other);
			VOID operator=(BOOL state);
			VOID Set();
			VOID Reset();
			VOID Flip();
		};
		H3Bitset();
		H3Bitset(UINT value);
		H3Bitset(UINT64 value);
		H3Bitset(const H3String& value);
		H3Bitset(const H3Bitset<size>& other);
		H3String ToString() const;
		H3String ToHexString() const;
		UINT     ToUINT() const;
		UINT64   ToUINT64() const;
		VOID Set();
		VOID Reset();
		BOOL All() const;
		BOOL Any() const;
		BOOL None() const;
		VOID Flip();
		UINT Count() const;
		BOOL Test(UINT position) const;
		UINT Size() const;
		UINT Length() const;
		BOOL Intersects(const H3Bitset<size>& other) const;
		BOOL Contains(const H3Bitset<size>& other) const;
		H3Bitset& operator=(const H3Bitset<size>& other);
		BOOL operator!=(const H3Bitset<size>& other);
		BOOL operator==(const H3Bitset<size>& other);
		BOOL operator!() const;
		BOOL operator()() const;
		BOOL operator()(UINT position) const;
		iterator begin();
		iterator end();
		iterator operator[](UINT position);
	};
#pragma pack(pop) /* align-4 */

	template<UINT size>
	inline H3Bitset<size>::iterator::iterator(H3Bitset* bitset) :
		m_bitset(bitset), m_position()
	{
	}
	template<UINT size>
	inline H3Bitset<size>::iterator::iterator(H3Bitset* bitset, UINT position) :
		m_bitset(bitset), m_position(position)
	{
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator++()
	{
		++m_position;
		return *this;
	}
	template<UINT size>
	inline typename  H3Bitset<size>::iterator H3Bitset<size>::iterator::operator++(int)
	{
		iterator it(m_bitset, m_position);
		++m_position;
		return it;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator*()
	{
		return *this;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator* H3Bitset<size>::iterator::operator->()
	{
		return this;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator~()
	{
		Flip();
		return *this;
	}
	template<UINT size>
	inline H3Bitset<size>::iterator::operator BOOL()
	{
		return m_bitset->get(m_position);
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator!()
	{
		return m_bitset->Test(m_position) == FALSE;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator==(const iterator& other)
	{
		return m_position == other.m_position;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator!=(const iterator& other)
	{
		return m_position != other.m_position;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::operator=(BOOL state)
	{
		m_bitset->set(m_position, state);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Set()
	{
		m_bitset->set(m_position, TRUE);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Reset()
	{
		m_bitset->set(m_position, FALSE);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Flip()
	{
		m_bitset->flip(m_position);
	}

	template<UINT size>
	inline constexpr UINT H3Bitset<size>::RawSize()
	{
		return ((size - 1) / 32 + 1) * sizeof(UINT);
	}

	template<UINT size>
	inline VOID H3Bitset<size>::set(UINT position, BOOL state)
	{
		if (position >= size)
			return;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		if (state)
			m_bits[index] |= value;
		else
			m_bits[index] &= ~value;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::flip(UINT position)
	{
		if (position >= size)
			return;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		m_bits[index] ^= value;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::get(UINT position) const
	{
		if (position >= size)
			return -1;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		return m_bits[index] & value;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::clear()
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = 0;
	}
	template<UINT size>
	inline UINT64 H3Bitset<size>::startMask()
	{
		if (size <= 64)
			return (1ull << size) - 1;
		return UINT64_MAX;
	}
	template<UINT size>
	inline UINT H3Bitset<size>::endMask()
	{
		return UINT((1ull << (size & 0x1F)) - 1);
	}

	template<UINT size>
	inline H3Bitset<size>::H3Bitset() :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(UINT value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		if (size < 32)
			value &= UINT(startMask());
		m_bits[0] = value;
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(UINT64 value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		switch (m_length)
		{
		case 1:
			m_bits[0] = value & UINT(startMask());
			break;
		case 2:
			*PUINT64(m_bits) = value & startMask();
			break;
		default:
			*PUINT64(m_bits) = value;
		}
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(const H3String& value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		UINT min_len = std::min(size, value.Length());
		for (UINT i = 0; i < min_len; ++i)
			if (value[i] != '0')
				set(i, TRUE);
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(const H3Bitset<size>& other)
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = other.m_bits[i];
	}

	template<UINT size>
	inline H3String H3Bitset<size>::ToString() const
	{
		H3String str;
		str.Reserve(size);
		for (UINT i = 0; i < size; ++i)
			str.Append(get(i) ? '1' : '0');
		return str;
	}

	template<UINT size>
	inline H3String H3Bitset<size>::ToHexString() const
	{
		H3String str;
		str.Reserve(size);
		for (UINT i = 0; i < m_length; ++i)
			str.PrintfAppend("%x", m_bits[i]);
		return str;
	}

	template<UINT size>
	inline UINT H3Bitset<size>::ToUINT() const
	{
		return m_bits[0];
	}

	template<UINT size>
	inline UINT64 H3Bitset<size>::ToUINT64() const
	{
		switch (m_length)
		{
		case 1:
			return m_bits[0];
		default:
			return *PUINT64(m_bits);
		}
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Set()
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			m_bits[i] = 0;
		m_bits[m_length - 1] = endMask();
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Reset()
	{
		clear();
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::All() const
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			if (m_bits[i] != UINT_MAX)
				return FALSE;
		return m_bits[m_length - 1] == UINT(endMask());
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Any() const
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			if (m_bits[i] != 0)
				return TRUE;
		return FALSE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::None() const
	{
		return !Any();
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Flip()
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = m_bits[i] ^ UINT_MAX;
		m_bits[m_length - 1] &= UINT(endMask());
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Count() const
	{
		PUINT8 const bitset_lookup_table = PUINT8(0x67729C);
		UINT count = 0;

		PUINT current = m_bits + m_length - 1;
		UINT num_iterations = m_length;

		do
		{
			for (UINT i = *current; i; i >>= 4)
				count += bitset_lookup_table[i & 0xF];
			--current;
			--num_iterations;
		} while (num_iterations > 0);

		return count;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Test(UINT position) const
	{
		return get(position);
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Size() const
	{
		return size;
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Length() const
	{
		return m_length;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Intersects(const H3Bitset<size>& other) const
	{
		for (UINT i = 0; i < m_length; ++i)
			if (m_bits[i] & other.m_bits[i] != 0)
				return TRUE;
		return FALSE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Contains(const H3Bitset<size>& other) const
	{
		for (UINT i = 0; i < m_length; ++i)
			if ((other.m_bits[i] & ~m_bits[i]) != 0)
				return FALSE;
		return TRUE;
	}

	template<UINT size>
	inline H3Bitset<size>& H3Bitset<size>::operator=(const H3Bitset<size>& other)
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = other.m_bits;
		return *this;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator!=(const H3Bitset<size>& other)
	{
		return !operator==(other);
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator==(const H3Bitset<size>& other)
	{
		for (UINT i = 0; i < m_length; ++i)
			if (m_bits[i] != other.m_bits)
				return FALSE;
		return TRUE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator()(UINT position) const
	{
		return get(position);
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator()() const
	{
		return Any();
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator!() const
	{
		return None();
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::begin()
	{
		return iterator(this, 0);
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::end()
	{
		return iterator(this, size);
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::operator[](UINT position)
	{
		return iterator(this, position);
	}
}

namespace h3
{
    _H3API_DECLARE_(ComboArtifactSetup);
    struct H3Artifact;

#pragma pack(push, 4)

    struct H3ComboArtifactSetup
    {
        _H3API_SIZE_(0x18);
        _H3API_GET_INFO_(0x4DDFF2 + 2, H3ComboArtifactSetup);

        eArtifact index;
        H3ArtifactBitset artifacts;

        _H3API_ BOOL IsPartOfCombo(eArtifact id) const;
        _H3API_ BOOL IsPartOfCombo(const H3Artifact& art) const;
    };
    _H3API_ASSERT_SIZE_(H3ComboArtifactSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace NH3Assets
    {
        namespace NAssets
        {
            enum eType
            {
                TEXTFILE         = 0x02,
                PCX8             = 0x10,
                PCX24            = 0x11,
                PCX16            = 0x12,
                WAV              = 0x20,
                SPELL            = 0x40,
                CREATURE         = 0x42,
                ADVENTURE_OBJECT = 0x43,
                HERO             = 0x44,
                TERRAIN          = 0x45,
                CURSOR           = 0x46,
                INTERFACE        = 0x47,
                COMBAT_HERO      = 0x49,
                FONT             = 0x50,
                PALETTE          = 0x60,
                PALETTE_HDMOD    = 0x61,


                DATA         = 0x01,
                SPREADSHEET  = 0x02,
                BITMAP8      = 0x10,
                BITMAP24     = 0x11,
                BITMAP16     = 0x12,
                BITMAP565    = 0x13,
                BITMAP555    = 0x14,
                BITMAP1555   = 0x21,
                MIDI         = 0x30,
                SPRITE       = 0x40,
                SPRITEDEF    = 0x41,
                ADVOBJ       = 0x43,
                TILESET      = 0x45,
                POINTER      = 0x46,
                SPRITE_FRAME = 0x48,
                X0           = 0x4A, // only "0x" for all 5 of these
                X1           = 0x4B,
                X2           = 0x4C,
                X3           = 0x4D,
                X4           = 0x4E,
                ADVMASK      = 0x4F,
            };
        }
        typedef NAssets::eType eType;

        namespace NCreatureGroups
        {
            enum eCreatureGroups
            {
                MOVING                = 0,
                MOUSE_OVER            = 1,
                STANDING              = 2,
                GETTING_HIT           = 3,
                DEFEND                = 4,
                DEATH                 = 5,
                UNUSED_DEATH          = 6,
                TURN_LEFT             = 7,
                TURN_RIGHT            = 8,
                TURN_LEFT2            = 9,
                TURN_RIGHT2           = 10,
                ATTACK_UP             = 11,
                ATTACK_STRAIGHT       = 12,
                ATTACK_DOWN           = 13,
                SHOOT_UP              = 14,
                SHOOT_STRAIGHT        = 15,
                SHOOT_DOWN            = 16,
                SPELL_ATTACK_UP       = 17,
                SPELL_ATTACK_STRAIGHT = 18,
                SPELL_ATTACK_DOWN     = 19,
                START_MOVING          = 20,
                STOP_MOVING           = 21,
            };
        } /* namespace NCreatureGroups*/
        typedef NCreatureGroups::eCreatureGroups eSpriteCreatureGroups;
    } /* namespace NH3Assets */
    typedef NH3Assets::eType eAsset;
    typedef NH3Assets::eSpriteCreatureGroups eSpriteCreatureGroups;
} /* namespace h3 */

namespace h3
{
    namespace NH3Campaign
    {
        namespace NCampaignId
        {
            enum eCampaignId
            {
                LONG_LIVE_THE_QUEEN     = 0,
                LIBERATION              = 1,
                SPOILS_OF_WAR           = 2,
                SONG_FOR_THE_FATHER     = 3,
                DUNGEONS_AND_DEVILS     = 4,
                LONG_LIVE_THE_KING      = 5,
                SEEDS_OF_DISCONTENT     = 6,
                ARMAGEDDONS_BLADE       = 7,
                DRAGONS_BLOOD           = 8,
                DRAGON_SLAYER           = 9,
                FESTIVAL_OF_LIFE        = 10,
                FOOLHARDY_WAYWARDNESS   = 11,
                PLAYING_WITH_FIRE       = 12,
                HACK_AND_SLASH          = 13,
                BIRTH_OF_A_BARBARIAN    = 14,
                NEW_BEGINNING           = 15,
                ELIXIR_OF_LIFE          = 16,
                RISE_OF_THE_NECROMANCER = 17,
                UNHOLY_ALLIANCE         = 18,
                SPECTER_OF_POWER        = 19,
            };
        }
        typedef NCampaignId::eCampaignId eCampaignId;

        namespace NCampaignType
        {
            enum eCampaignType : INT32
            {
                ROE = 5,
                AB  = 5,
                SOD = 6,
            };
        }
        typedef NCampaignType::eCampaignType eCampaignType;

        namespace NCampaignMusic
        {
            enum eCampaignMusic : INT32
            {
                CAMPAINMUSIC01  = 0,
                CAMPAINMUSIC02  = 1,
                CAMPAINMUSIC03  = 2,
                CAMPAINMUSIC04  = 3,
                CAMPAINMUSIC05  = 4,
                CAMPAINMUSIC06  = 5,
                CAMPAINMUSIC07  = 6,
                CAMPAINMUSIC08  = 7,
                CAMPAINMUSIC09  = 8,
                AITHEME0        = 9,
                AITHEME1        = 10,
                AITHEME2        = 11,
                COMBAT01        = 12,
                COMBAT02        = 13,
                COMBAT03        = 14,
                COMBAT04        = 15,
                CSTLETOWN       = 16,
                TOWERTOWN       = 17,
                RAMPART         = 18,
                INFERNOTOWN     = 19,
                NECROTOWN       = 20,
                DUNGEON         = 21,
                STRONGHOLD      = 22,
                FORTRESSTOWN    = 23,
                ELEMTOWN        = 24,
                DIRT            = 25,
                SAND            = 26,
                GRASS           = 27,
                SNOW            = 28,
                SWAMP           = 29,
                ROUGH           = 30,
                UNDERGROUND     = 31,
                LAVA            = 32,
                WATER           = 33,
                GOODTHEME       = 34,
                NEUTRALTHEME    = 35,
                EVILTHEME       = 36,
                SECRETTHEME     = 37,
                LOOPLEPR        = 38,
                MAINMENU        = 39,
                WIN_SCENARIO    = 40,
                CAMPAINMUSIC10  = 41,
                BLADEABCAMPAIGN = 42,
                BLADEDBCAMPAIGN = 43,
                BLADEDSCAMPAIGN = 44,
                BLADEFLCAMPAIGN = 45,
                BLADEFWCAMPAIGN = 46,
                BLADEPFCAMPAIGN = 47,
                CAMPAINMUSIC11  = 48,
            };
        }
        typedef NCampaignMusic::eCampaignMusic eCampaignMusic;

        namespace NCampaignMovie
        {
            enum eCampaignMovie : INT32
            {
                GOOD1_A                  = 0,
                GOOD1_B                  = 1,
                GOOD1_C                  = 2,
                EVIL1_A                  = 3,
                EVIL1_B                  = 4,
                EVIL1_C                  = 5,
                NEUTRAL1_A               = 6,
                NEUTRAL1_B               = 7,
                NEUTRAL1_C               = 8,
                GOOD2_A                  = 9,
                GOOD2_B                  = 10,
                GOOD2_C                  = 11,
                GOOD2_D                  = 12,
                EVIL2_A                  = 13,
                EVIL2AP1                 = 14,
                EVIL2_B                  = 15,
                EVIL2_C                  = 16,
                EVIL2_D                  = 17,
                GOOD3_A                  = 18,
                GOOD3_B                  = 19,
                GOOD3_C                  = 20,
                SECRET_A                 = 21,
                SECRET_B                 = 22,
                SECRET_C                 = 23,
                ARMAGEDDONSBLADE_A       = 24,
                ARMAGEDDONSBLADE_B       = 25,
                ARMAGEDDONSBLADE_C       = 26,
                ARMAGEDDONSBLADE_D       = 27,
                ARMAGEDDONSBLADE_E       = 28,
                ARMAGEDDONSBLADE_F       = 29,
                ARMAGEDDONSBLADE_G       = 30,
                ARMAGEDDONSBLADE_H       = 31,
                ARMAGEDDONSBLADE_END     = 32,
                DRAGONSBLOOD_A           = 33,
                DRAGONSBLOOD_B           = 34,
                DRAGONSBLOOD_C           = 35,
                DRAGONSBLOOD_D           = 36,
                DRAGONSBLOOD_END         = 37,
                DRAGONSLAYER_A           = 38,
                DRAGONSLAYER_B           = 39,
                DRAGONSLAYER_C           = 40,
                DRAGONSLAYER_D           = 41,
                DRAGONSLAYER_END         = 42,
                FESTIVALOFLIFE_A         = 43,
                FESTIVALOFLIFE_B         = 44,
                FESTIVALOFLIFE_C         = 45,
                FESTIVALOFLIFE_D         = 46,
                FESTIVALOFLIFE_END       = 47,
                FOOLHARDYWAYWARDNESS_A   = 48,
                FOOLHARDYWAYWARDNESS_B   = 49,
                FOOLHARDYWAYWARDNESS_C   = 50,
                FOOLHARDYWAYWARDNESS_D   = 51,
                FOOLHARDYWAYWARDNESS_END = 52,
                PLAYINGWITHFIRE_A        = 53,
                PLAYINGWITHFIRE_B        = 54,
                PLAYINGWITHFIRE_C        = 55,
                PLAYINGWITHFIRE_END      = 56,
                BIRTHOFABARBARIAN_A      = 57,
                BIRTHOFABARBARIAN_B      = 58,
                BIRTHOFABARBARIAN_C      = 59,
                BIRTHOFABARBARIAN_D      = 60,
                BIRTHOFABARBARIAN_E      = 61,
                BIRTHOFABARBARIAN_END    = 62,
                ELIXIROFLIFE_A           = 63,
                ELIXIROFLIFE_B           = 64,
                ELIXIROFLIFE_C           = 65,
                ELIXIROFLIFE_D           = 66,
                ELIXIROFLIFE_END         = 67,
                HACKANDSLASH_A           = 68,
                HACKANDSLASH_B           = 69,
                HACKANDSLASH_C           = 70,
                HACKANDSLASH_D           = 71,
                HACKANDSLASH_END         = 72,
                NEWBEGINNING_A           = 73,
                NEWBEGINNING_B           = 74,
                NEWBEGINNING_C           = 75,
                NEWBEGINNING_D           = 76,
                NEWBEGINNING_END         = 77,
                RISEOFTHENECROMANCER_A   = 78,
                RISEOFTHENECROMANCER_B   = 79,
                RISEOFTHENECROMANCER_C   = 70,
                RISEOFTHENECROMANCER_D   = 71,
                RISEOFTHENECROMANCER_END = 72,
                SPECTREOFPOWER_A         = 73,
                SPECTREOFPOWER_B         = 74,
                SPECTREOFPOWER_C         = 75,
                SPECTREOFPOWER_D         = 76,
                SPECTREOFPOWER_END       = 77,
                UNHOLYALLIANCE_A         = 78,
                UNHOLYALLIANCE_B         = 79,
                UNHOLYALLIANCE_C         = 80,
                UNHOLYALLIANCE_D         = 81,
                UNHOLYALLIANCE_E         = 82,
                UNHOLYALLIANCE_F         = 83,
                UNHOLYALLIANCE_G         = 84,
                UNHOLYALLIANCE_H         = 85,
                UNHOLYALLIANCE_I         = 86,
                UNHOLYALLIANCE_J         = 87,
                UNHOLYALLIANCE_K         = 88,
                UNHOLYALLIANCE_L         = 89,
                UNHOLYALLIANCE_END       = 90,
            };
        }
        typedef NCampaignMovie::eCampaignMovie eCampaignMovie;

        namespace NCampaignStartingBonusType
        {
            enum eCampaignStartingBonusType
            {
                SPELL            = 0x0,
                CREATURE         = 0x1,
                BUILDING         = 0x2,
                ARTIFACT         = 0x3,
                SPELL_SCROLL     = 0x4,
                PRIMARY_SKILLS   = 0x5,
                SECONDARY_SKILLS = 0x6,
                RESOURCES        = 0x7,
            };
        }
        typedef NCampaignStartingBonusType::eCampaignStartingBonusType eCampaignStartingBonusType;
    }
    typedef NH3Campaign::eCampaignId                eCampaign;
    typedef NH3Campaign::eCampaignType              eCampaignType;
    typedef NH3Campaign::eCampaignMusic             eCampaignMusic;
    typedef NH3Campaign::eCampaignMovie             eCampaignMovie;
    typedef NH3Campaign::eCampaignStartingBonusType eCampaignStartingBonusType;
} /* namespace h3 */

namespace h3
{
    namespace NH3Combat
    {
        namespace NFortElements
        {
            enum eFortElements
            {
                DRAWBRIDGE      = 0,
                DRAWBRIDGE_ROPE = 1,
                MOAT            = 2,
                MOAT_LIP        = 3,
                BACK_WALL       = 4,
                UPPER_TOWER     = 5,  // valid catapult target 0
                UPPER_WALL      = 6,  // valid catapult target 1
                UPPER_BUTTRESS  = 7,
                MID_UPPER_WALL  = 8,  // valid catapult target 2
                GATE            = 9,  // valid catapult target 3
                MID_LOWER_WALL  = 10, // valid catapult target 4
                LOWER_BUTTRESS  = 11,
                LOWER_WALL      = 12, // valid catapult target 5
                LOWER_TOWER     = 13, // valid catapult target 6
                KEEP            = 14, // valid catapult target 7
                KEEP_CVR        = 15,
                LOWER_TWR_CVR   = 16,
                UPPER_TWR_CVR   = 17,
            };
        }
        typedef NFortElements::eFortElements eFortElements;

        namespace NMissiles
        {
            enum eMissiles
            {
                UPPER_RIGHT = 0,
                RIGHT       = 1,
                LOWER_RIGHT = 2,
            };
        }
        typedef NMissiles::eMissiles eMissiles;

        namespace NBattleAction
        {
            enum eBattleAction : INT32
            {
                CANCEL         = 0,
                CAST_SPELL     = 1, // Hero casts a spell
                WALK           = 2,
                DEFEND         = 3,
                RETREAT        = 4,
                SURRENDER      = 5,
                WALK_ATTACK    = 6,
                SHOOT          = 7,
                WAIT           = 8,
                CATAPULT       = 9,
                MONSTER_SPELL  = 10,
                FIRST_AID_TENT = 11,
                NOTHING        = 12, //No action(can be to disable stack for this round)
            };
        }
        typedef NBattleAction::eBattleAction eBattleAction;

        namespace NRelativeOrientation
        {
            enum eRelativeOrientation : INT32
            {
                TOP_RIGHT      = 0,
                RIGHT          = 1,
                BOTTOM_RIGHT   = 2,
                BOTTOM_LEFT    = 3,
                LEFT           = 4,
                TOP_LEFT       = 5,
                REVERSE_TOP    = 6, // equivalent to 5 or 0 [attacker vs defender]
                REVERSE_BOTTOM = 7, // equivalent to 3 or 2 [attacker vs defender]
            };
        }
        typedef NRelativeOrientation::eRelativeOrientation eRelativeOrientation;

        namespace NSquareAccess
        {
            enum eSquareAccess : UINT8
            {
                INACCESSIBLE = 0,
                CAN_ATTACK   = 1,
                CAN_REACH    = 2,
                ACCESSIBLE   = CAN_ATTACK | CAN_REACH,
            };
        }
        typedef NSquareAccess::eSquareAccess eSquareAccess;

        constexpr INT32 COMBATSQUARE_WIDTH  = 44;
        constexpr INT32 COMBATSQUARE_HEIGHT = 42;

        namespace NMagicAnimation
        {
            enum eMagicAnimation : INT32
            {
                PRAYER                 = 0,
                LIGHTNING_BOLT         = 1,
                AIR_SHIELD             = 2,
                BACKLASH               = 3,
                ANIMATE_DEAD           = 4,
                ANTI_MAGIC             = 5,
                BLIND                  = 6,
                COUNTERSTROKE          = 7,
                DEATH_RIPPLE           = 8,
                FIREBLAST              = 9,
                DECAY                  = 10,
                FIRE_SHIELD            = 11,
                FIRESTORM              = 12,
                DISRUPTIVERAY_RAY      = 13,
                DISRUPTIVERAY_BURST    = 14,
                FEAR                   = 15,
                METEOR_SHOWER          = 16,
                FRENZY                 = 17,
                FORTUNE                = 18,
                MUCK_AND_MIRE          = 19,
                MIRTH                  = 20,
                HYPNOTIZE              = 21,
                PROTECTION_FROM_AIR    = 22,
                PROTECTION_FROM_WATER  = 23,
                PROTECTION_FROM_FIRE   = 24,
                PRECISION              = 25,
                PROTECTION_FROM_EARTH  = 26,
                SHIELD                 = 27,
                SLAYER                 = 28,
                SACRED_BREATH          = 29,
                SORROW                 = 30,
                TAIL_WIND              = 31,
                FORCEFIELD_2           = 32,
                FORCEFIELD_3           = 33,
                REMOVE_OBSTACLE        = 34,
                BERSERK                = 35,
                BLESS                  = 36,
                CHAIN_LIGHTNING_BOLT   = 37,
                CHAIN_LIGHTNING_DUST   = 38,
                CURE                   = 39,
                CURSE                  = 40,
                DISPEL                 = 41,
                FORGETFULNESS          = 42,
                FIREWALL_2             = 43,
                FIREWALL_3             = 44,
                FROSTRING              = 45,
                ICERAY_BURST           = 46,
                LAND_MINE              = 47,
                MISFORTUNE             = 48,
                LIGHTNING_DUST         = 49,
                RESURRECTION           = 50,
                SACRIFICE_SLAY         = 51,
                SACRIFICE_RESURRECT    = 52,
                SPONTANEOUS_COMBUSTION = 53,
                TOUGH_SKIN             = 54,
                QUICKSAND              = 55,
                WEAKNESS               = 56,
                LAND_MINE_EXPLOSION    = 57,
                DISPEL_QUICKSAND       = 58,
                DISPEL_LAND_MINE       = 59,
                DISPEL_FORCEFIELD_2    = 60,
                DISPEL_FORCEFIELD_3    = 61,
                DISPEL_FIREWALL_2      = 62,
                DISPEL_FIREWALL_3      = 63,
                MAGICBOLT_BURST        = 64,
                FIREWALL_1             = 65,
                DISPELFIREWALL_1       = 66,
                POISON                 = 67,
                BIND                   = 68,
                DISEASE                = 69,
                PARALYZE               = 70,
                AGE                    = 71,
                DEATH_CLOUD            = 72,
                DEATH_BLOW             = 73,
                DRAIN_LIFE             = 74,
                MAGICCHANNEL_SUCK      = 75,
                MAGICCHANNEL_SPEW      = 76,
                MAGIC_DRAIN            = 77,
                MAGIC_RESISTANCE       = 78,
                REGENERATE             = 79,
                DEATH_STARE            = 80,
                ACID_BREATH            = 81,
                POOF                   = 82,
            };
        }
        typedef NMagicAnimation::eMagicAnimation eMagicAnimation;
    }
    typedef NH3Combat::eFortElements        eCombatFortElements;
    typedef NH3Combat::eMissiles            eCombatMissiles;
    typedef NH3Combat::eBattleAction        eCombatAction;
    typedef NH3Combat::eRelativeOrientation eCombatOrientation;
    typedef NH3Combat::eSquareAccess        eCombatSquareAccess;
    typedef NH3Combat::eMagicAnimation      eCombatMagicAnimation;
} /* namespace h3 */

namespace h3
{
    namespace NH3Dlg
    {
        namespace Text
        {
            LPCSTR const TINY    = (LPCSTR(0x660CB4)); // "tiny.fnt"
            LPCSTR const SMALL   = (LPCSTR(0x65F2F8)); // "smalfont.fnt"
            LPCSTR const MEDIUM  = (LPCSTR(0x65F2EC)); // "MedFont.fnt"
            LPCSTR const BIG     = (LPCSTR(0x660B24)); // "bigfont.fnt"
            LPCSTR const VERDANA = (LPCSTR(0x6700B4)); // "Verd10B.fnt"
        } // namespace Text

        namespace NTextAlignment
        {
            enum eTextAlignment : INT32
            {
                HLEFT         = 0,
                HCENTER       = 1,
                HRIGHT        = 2,
                VTOP          = 0,
                VCENTER       = 4,
                VBOTTOM       = 8,
                BOTTOM_LEFT   = HLEFT   | VBOTTOM,
                BOTTOM_CENTER = HCENTER | VBOTTOM,
                BOTTOM_RIGHT  = HRIGHT  | VBOTTOM,
                MIDDLE_LEFT   = HLEFT   | VCENTER,
                MIDDLE_CENTER = HCENTER | VCENTER,
                MIDDLE_RIGHT  = HRIGHT  | VCENTER,
                TOP_LEFT      = HLEFT   | VTOP,
                TOP_MIDDLE    = HCENTER | VTOP,
                TOP_RIGHT     = HRIGHT  | VTOP,
            };
        } // namespace TextAlignment
        typedef NTextAlignment::eTextAlignment eTextAlignment;

        namespace NTextColor
        {
            enum eTextColor : INT32
            {
                SILVER      = 0x00,
                REGULAR     = 0x01,
                HIGHLIGHT   = 0x02,
                GOLD        = 0x03,
                WHITE       = 0x04,
                GREEN       = 0x0D,
                LIGHT_GREEN = 0x0E,
                DARK_GREEN  = 0x0F,
                BLACK       = 0x17,
                BLUE        = 0x18,
                CYAN        = 0x1A,
                RED         = 0x1B,
                PURPLE      = 0x1C,
                YELLOW      = 0x1D,
                GRAY        = 0x36,
                RED2        = 0x37,
                BLUE2       = 0x38,
                TAN         = 0x39,
                DARK_GREEN2 = 0x3A,
                ORANGE      = 0x3B,
                PURPLE2     = 0x3C,
                DARK_CYAN   = 0x3D,
                PINK        = 0x3E,
                GRAY2       = 0x3F,
                YELLOW2     = 0x57,
                DARK_YELLOW = 0x58,
                TAN2        = 0x59,
                TAN3        = 0x5A,
                TAN4        = 0x5B,
                TAN5        = 0x5C,
                CYAN2       = 0x67,
                CYAN3       = 0x68,
                CYAN4       = 0x69,
                CYAN5       = 0x6A,
            };
        } // namespace TextColor
        typedef NTextColor::eTextColor eTextColor;

        namespace Assets
        {
            LPCSTR const ARTIFACT_DEF     = (LPCSTR(0x660214));  // "artifact.def" 44x44
            LPCSTR const ARTS_ICON        = (LPCSTR(0x683178));  // AltArt.def 64x32
            LPCSTR const CREATURE_SMALL   = (LPCSTR(0x660180));  // "CPRSMALL.def" 32x32
            LPCSTR const DIBOXBACK        = (LPCSTR(0x66025C));  // "diboxback.pcx" 256x256
            LPCSTR const DLGBOX           = (LPCSTR(0x66024C));  // "dialogbox.def" 64x64
            LPCSTR const HERO_CADRE       = (LPCSTR(0x65F3DC));  // hpsyyy.pcx 48x32
            LPCSTR const PSKILL_42        = (LPCSTR(0x679D9C));  // "PSKIL42.def" 42x42
            LPCSTR const RESOURCE_DEF     = (LPCSTR(0x660224));  // "resource.def" 32x32
            LPCSTR const RESOURCE_82      = (LPCSTR(0x660114));  // "resour82.def" 82x93
            LPCSTR const SPELLS_DEF       = (LPCSTR(0x660208));  // "spells.def"78x65
            LPCSTR const SPELL_SMALL      = (LPCSTR(0x6700A4));  // "spellint.def" 48x36
            LPCSTR const SSKILL_44        = (LPCSTR(0x6601D0));  // "Secskill.def" 44x44
            LPCSTR const UN44_DEF         = (LPCSTR(0x679D90));  // "un44.def"44x44
            LPCSTR const OVBUTN3          = (LPCSTR(0x6817C4));  // "OvButn3.def" 108x16
            LPCSTR const LARGE_HERO_CADRE = (LPCSTR(0x68C45C));  // TPTavSel.pcx 62x68 ~decal by -2
            LPCSTR const CREATURE_LARGE   = (LPCSTR(0x6700C0));  // TwCrPort.def 58x64
            LPCSTR const CANCEL_BUTTON    = (LPCSTR(0x660B04));  // iCancel.def 64x30
            LPCSTR const CAST_SPELL       = (LPCSTR(0x66FFD4));  // icm005.def 48x36
            LPCSTR const MORALE_42        = (LPCSTR(0x68C6DC));  // IMRL42.def 42x38
            LPCSTR const LUCK_42          = (LPCSTR(0x68C6D0));  // ILCK42.def 42x38
            LPCSTR const CREST58          = (LPCSTR(0x6601FC));  // CREST58.def 58x64
            LPCSTR const TOWN_SMALL       = (LPCSTR(0x65F318));  // itpa.def 48x32
            LPCSTR const NO_VISION        = (LPCSTR(0x6885A0));  // SYSOPB8.def 46x32
            LPCSTR const ADVENTURE_CURSOR = (LPCSTR(0x68164C));  // cradvntr.def 40x40
            LPCSTR const ON_OFF_CHECKBOX  = (LPCSTR(0x6700F0));  // sysopchk.def 32x24
            LPCSTR const OKAY_DEF         = (LPCSTR(0x670160));  // iOkay.def 64x30
            LPCSTR const OKAY32_DEF       = (LPCSTR(0x682374));  // iOkay32.def 66x32
            LPCSTR const OKAY6432_DEF     = (LPCSTR(0x65F470));  // iOk6432.def 64x32
            LPCSTR const BOX_64_30_PCX    = (LPCSTR(0x67016C));  // Box64x30.pcx
            LPCSTR const BOX_66_32_PCX    = (LPCSTR(0x682380));  // Box66x32.pcx
            LPCSTR const CANCEL_DEF       = (LPCSTR(0x660B04));  // "iCancel.def" 64x30
            LPCSTR const VIEW_CREATURE    = (LPCSTR(0x660134));  // iViewCr.def
            LPCSTR const VIEW_MAGNIFIER   = (LPCSTR(0x68C734));  // VWMag1.def 60x32
            LPCSTR const iSAVE_DEF        = "ISAVE.DEF";         // iSave.def 64x32
            LPCSTR const BOX_64_32_PCX    = (LPCSTR(0x68C640));  // Box64x32.pcx
            LPCSTR const GAME_TYPE_DEF    = (LPCSTR(0x683568));  // 32x24
            LPCSTR const ICM005_DEF       = (LPCSTR(0x66FFD4));  // 48x36
            LPCSTR const ALTART_DEF       = (LPCSTR(0x683178));  // 64x32
            LPCSTR const VWSYMBOL_DEF     = (LPCSTR(0x68C740));  // 32x32
            LPCSTR const SYSLB_DEF        = (LPCSTR(0x670124));  // 18x36
        } // namespace Assets

        namespace HDassets
        {
            LPCSTR const DLGBLUEBOX       = "DlgBluBo.def";  // 64x64
            LPCSTR const DLGBLUEBACK      = "DlgBluBk.PCX";  // 256x256
            LPCSTR const LINE_SEPARATOR   = "stripe3d.bmp";  // 800x2
            LPCSTR const HD_STATUSBAR_PCX = "HD_TStat.pcx";  // 800x19
            LPCSTR const HERO_FRAME       = "48x32bFr.bmp";  // darken an area for 48x32 def
            LPCSTR const BACKPACK_DEF     = "bckpck.def";    // 52x36
            LPCSTR const BIG_BACKPACK     = "BkPack.bmp";    // 369x369
            LPCSTR const SCROLL_SMALL     = "def.SpScrArt";  // 44x44
            LPCSTR const FRAME_LU         = "hd_fr_lu.bmp";  // 4x4
            LPCSTR const FRAME_LD         = "hd_fr_ld.bmp";  // 4x4
            LPCSTR const FRAME_RU         = "hd_fr_ru.bmp";  // 4x4
            LPCSTR const FRAME_RD         = "hd_fr_rd.bmp";  // 4x4
            LPCSTR const FRAME_U          = "hd_fr_u.bmp";   // 4x4
            LPCSTR const FRAME_D          = "hd_fr_d.bmp";   // 4x4
            LPCSTR const FRAME_L          = "hd_fr_l.bmp";   // 4x4
            LPCSTR const FRAME_R          = "hd_fr_r.bmp";   // 4x4
        } // namespace HDassets

        namespace NPictureCategories
        {
            enum ePictureCategories
            {
                NONE                 = -1,
                WOOD                 = 0,    /**< @brief amount (int)*/
                MERCURY              = 1,    /**< @brief amount (int)*/
                ORE                  = 2,    /**< @brief amount (int)*/
                SULFUR               = 3,    /**< @brief amount (int)*/
                CRYSTAL              = 4,    /**< @brief amount (int)*/
                GEMS                 = 5,    /**< @brief amount (int)*/
                GOLD                 = 6,    /**< @brief amount (int)*/
                ARTIFACT             = 8,    /**< @brief artifact id 0..140*/
                SPELL                = 9,    /**< @brief spell id 0..69*/
                CREST                = 10,   /**< @brief player color 0..7 */
                POSITIVE_LUCK        = 11,   /**< @brief 1..3*/
                NEUTRAL_LUCK         = 12,   /**< @brief unused*/
                NEGATIVE_LUCK        = 13,   /**< @brief 1..3*/
                POSITIVE_MORALE      = 14,   /**< @brief 1..3*/
                NEUTRAL_MORALE       = 15,   /**< @brief unused*/
                NEGATIVE_MORALE      = 16,   /**< @brief 1..3*/
                EXPERIENCE           = 17,   /**< @brief amount (int)*/
                SECONDARY_SKILL      = 20,   /**< @brief skill_id * 3 + level + 2*/
                CREATURE             = 21,   /**< @brief id 0..148 (?)*/
                CASTLE_BUILDINGS     = 22,   /**< @brief 0..43*/
                RAMPART_BUILDINGS    = 23,   /**< @brief 0..43*/
                TOWER_BUILDINGS      = 24,   /**< @brief 0..43*/
                INFERNO_BUILDINGS    = 25,   /**< @brief 0..43*/
                NECROPOLIS_BUILDINGS = 26,   /**< @brief 0..43*/
                DUNGEON_BUILDINGS    = 27,   /**< @brief 0..43*/
                STRONGHOLD_BUILDINGS = 28,   /**< @brief 0..43*/
                FORTRESS_BUILDINGS   = 29,   /**< @brief 0..43*/
                CONFLUX_BUILDINGS    = 30,   /**< @brief 0..43*/
                ATTACK               = 31,   /**< @brief 0..255*/
                DEFENSE              = 32,   /**< @brief 0..255*/
                SPELL_POWER          = 33,   /**< @brief 0..255*/
                KNOWLEDGE            = 34,   /**< @brief 0..255*/
                SPELL_POINTS         = 35,   /**< @brief amount (int)*/
                MONEY                = 36,   /**< @brief amount (int)*/
            };
        }
        typedef NPictureCategories::ePictureCategories ePictureCategories;

        namespace ID
        {
            namespace MainMenu
            {
                constexpr INT32 VTABLE     = 0x63FF60;
                constexpr INT32 NEW_GAME   = 101;
                constexpr INT32 LOAD_GAME  = 102;
                constexpr INT32 HIGH_SCORE = 103;
                constexpr INT32 CREDITS    = 104;
                constexpr INT32 QUIT       = 105;
            } // namespace MainMenu

            namespace HighScore
            {
                constexpr INT32 VTABLE   = 0x63EB98;
                constexpr INT32 EXIT     = 30722;
                constexpr INT32 CAMPAIGN = 1001;
                constexpr INT32 STANDARD = 1002;
                constexpr INT32 RESET    = 1003;
            } // namespace HighScore

            namespace LoadGame
            {
                constexpr INT32 VTABLE      = 0x63E6D8;
                constexpr INT32 SINGLE      = 100;
                constexpr INT32 MULTIPLAYER = 102;
                constexpr INT32 CAMPAIGN    = 101;
                constexpr INT32 TUTORIAL    = 103;
                constexpr INT32 QUIT        = 104;
            } // namespace LoadGame

            namespace NewGame
            {
                constexpr INT32 VTABLE      = 0x63E6D8;
                constexpr INT32 SINGLE      = 100;
                constexpr INT32 MULTIPLAYER = 102;
                constexpr INT32 CAMPAIGN    = 101;
                constexpr INT32 TUTORIAL    = 103;
                constexpr INT32 QUIT        = 104;
            } // namespace NewGame

            namespace SelectScenario
            {
                constexpr INT32 SCENARIO_NAME          = 101;
                constexpr INT32 EASY_DIFFICULTY        = 107;
                constexpr INT32 NORMAL_DIFFICULTY      = 108;
                constexpr INT32 HARD_DIFFICULTY        = 109;
                constexpr INT32 EXPERT_DIFFICULTY      = 110;
                constexpr INT32 IMPOSSIBLE_DIFFICULTY  = 111;
                constexpr INT32 RED_ALLY_FLAG          = 112;
                constexpr INT32 BLUE_ALLY_FLAG         = 113;
                constexpr INT32 TAN_ALLY_FLAG          = 114;
                constexpr INT32 GREEN_ALLY_FLAG        = 115;
                constexpr INT32 ORANGE_ALLY_FLAG       = 116;
                constexpr INT32 PURPLE_ALLY_FLAG       = 117;
                constexpr INT32 TEAL_ALLY_FLAG         = 118;
                constexpr INT32 PINK_ALLY_FLAG         = 119;
                constexpr INT32 RED_ENEMY_FLAG         = 120;
                constexpr INT32 BLUE_ENEMY_FLAG        = 121;
                constexpr INT32 TAN_ENEMY_FLAG         = 122;
                constexpr INT32 GREEN_ENEMY_FLAG       = 123;
                constexpr INT32 ORANGE_ENEMY_FLAG      = 124;
                constexpr INT32 PURPLE_ENEMY_FLAG      = 125;
                constexpr INT32 TEAL_ENEMY_FLAG        = 126;
                constexpr INT32 PINK_ENEMY_FLAG        = 127;
                constexpr INT32 SHOW_SCENARIOS         = 128;
                constexpr INT32 ADVANCED_OPTIONS       = 129;
                constexpr INT32 RANDOM_MAP             = 130;
                constexpr INT32 SMALL_SIZE             = 137;
                constexpr INT32 MEDIUM_SIZE            = 138;
                constexpr INT32 LARGE_SIZE             = 139;
                constexpr INT32 XLARGE_SIZE            = 140;
                constexpr INT32 ALL_SIZE               = 141;

                constexpr INT32 MAP_INDEX_0            = 142;
                constexpr INT32 MAP_INDEX_1            = 143;
                constexpr INT32 MAP_INDEX_2            = 144;
                constexpr INT32 MAP_INDEX_3            = 145;
                constexpr INT32 MAP_INDEX_4            = 146;
                constexpr INT32 MAP_INDEX_5            = 147;
                constexpr INT32 MAP_INDEX_6            = 148;
                constexpr INT32 MAP_INDEX_7            = 149;
                constexpr INT32 MAP_INDEX_8            = 150;
                constexpr INT32 MAP_INDEX_9            = 151;
                constexpr INT32 MAP_INDEX_10           = 152;
                constexpr INT32 MAP_INDEX_11           = 153;
                constexpr INT32 MAP_INDEX_12           = 154;
                constexpr INT32 MAP_INDEX_13           = 155;
                constexpr INT32 MAP_INDEX_14           = 156;
                constexpr INT32 MAP_INDEX_15           = 157;
                constexpr INT32 MAP_INDEX_16           = 158;
                constexpr INT32 MAP_INDEX_17           = 159;
                constexpr INT32 BEGIN                  = 186;
                constexpr INT32 BACK                   = 188;
                constexpr INT32 SELECTED_SIZE          = 189;
                constexpr INT32 SORT_PLAYER            = 190;
                constexpr INT32 SORT_SIZE              = 191;
                constexpr INT32 SORT_VERSION           = 192;
                constexpr INT32 SORT_NAME              = 193;
                constexpr INT32 SORT_VICTORY           = 194;
                constexpr INT32 SORT_LOSS              = 195;
                constexpr INT32 RED_TOWN_LEFT          = 215;
                constexpr INT32 BLUE_TOWN_LEFT         = 216;
                constexpr INT32 TAN_TOWN_LEFT          = 217;
                constexpr INT32 GREEN_TOWN_LEFT        = 218;
                constexpr INT32 ORANGE_TOWN_LEFT       = 219;
                constexpr INT32 PURPLE_TOWN_LEFT       = 220;
                constexpr INT32 TEAL_TOWN_LEFT         = 221;
                constexpr INT32 PINK_TOWN_LEFT         = 222;
                constexpr INT32 RED_TOWN_RIGHT         = 223;
                constexpr INT32 BLUE_TOWN_RIGHT        = 224;
                constexpr INT32 TAN_TOWN_RIGHT         = 225;
                constexpr INT32 GREEN_TOWN_RIGHT       = 226;
                constexpr INT32 ORANGE_TOWN_RIGHT      = 227;
                constexpr INT32 PURPLE_TOWN_RIGHT      = 228;
                constexpr INT32 TEAL_TOWN_RIGHT        = 229;
                constexpr INT32 PINK_TOWN_RIGHT        = 230;
                constexpr INT32 RED_HERO_LEFT          = 231;
                constexpr INT32 BLUE_HERO_LEFT         = 232;
                constexpr INT32 TAN_HERO_LEFT          = 233;
                constexpr INT32 GREEN_HERO_LEFT        = 234;
                constexpr INT32 ORANGE_HERO_LEFT       = 235;
                constexpr INT32 PURPLE_HERO_LEFT       = 236;
                constexpr INT32 TEAL_HERO_LEFT         = 237;
                constexpr INT32 PINK_HERO_LEFT         = 238;
                constexpr INT32 RED_HERO_RIGHT         = 239;
                constexpr INT32 BLUE_HERO_RIGHT        = 240;
                constexpr INT32 TAN_HERO_RIGHT         = 241;
                constexpr INT32 GREEN_HERO_RIGHT       = 242;
                constexpr INT32 ORANGE_HERO_RIGHT      = 243;
                constexpr INT32 PURPLE_HERO_RIGHT      = 244;
                constexpr INT32 TEAL_HERO_RIGHT        = 245;
                constexpr INT32 PINK_HERO_RIGHT        = 246;
                constexpr INT32 RED_BONUS_LEFT         = 247;
                constexpr INT32 BLUE_BONUS_LEFT        = 248;
                constexpr INT32 TAN_BONUS_LEFT         = 249;
                constexpr INT32 GREEN_BONUS_LEFT       = 250;
                constexpr INT32 ORANGE_BONUS_LEFT      = 251;
                constexpr INT32 PURPLE_BONUS_LEFT      = 252;
                constexpr INT32 TEAL_BONUS_LEFT        = 253;
                constexpr INT32 PINK_BONUS_LEFT        = 254;
                constexpr INT32 RED_BONUS_RIGHT        = 255;
                constexpr INT32 BLUE_BONUS_RIGHT       = 256;
                constexpr INT32 TAN_BONUS_RIGHT        = 257;
                constexpr INT32 GREEN_BONUS_RIGHT      = 258;
                constexpr INT32 ORANGE_BONUS_RIGHT     = 259;
                constexpr INT32 PURPLE_BONUS_RIGHT     = 260;
                constexpr INT32 TEAL_BONUS_RIGHT       = 261;
                constexpr INT32 PINK_BONUS_RIGHT       = 262;
                constexpr INT32 RED_BANNER             = 263;
                constexpr INT32 BLUE_BANNER            = 264;
                constexpr INT32 TAN_BANNER             = 265;
                constexpr INT32 GREEN_BANNER           = 266;
                constexpr INT32 ORANGE_BANNER          = 267;
                constexpr INT32 PURPLE_BANNER          = 268;
                constexpr INT32 TEAL_BANNER            = 269;
                constexpr INT32 PINK_BANNER            = 270;
                constexpr INT32 RANDOM_SMALL           = 281;
                constexpr INT32 RANDOM_MEDIUM          = 282;
                constexpr INT32 RANDOM_LARGE           = 283;
                constexpr INT32 RANDOM_XLARGE          = 284;
                constexpr INT32 RANDOM_UNDERGROUND     = 285;
                constexpr INT32 RANDOM_HUMAN1          = 287;
                constexpr INT32 RANDOM_HUMAN2          = 288;
                constexpr INT32 RANDOM_HUMAN3          = 289;
                constexpr INT32 RANDOM_HUMAN4          = 290;
                constexpr INT32 RANDOM_HUMAN5          = 291;
                constexpr INT32 RANDOM_HUMAN6          = 292;
                constexpr INT32 RANDOM_HUMAN7          = 293;
                constexpr INT32 RANDOM_HUMAN8          = 294;
                constexpr INT32 RANDOM_HUMAN_RANDOM    = 295;
                constexpr INT32 RANDOM_COMPUTER0       = 307;
                constexpr INT32 RANDOM_COMPUTER1       = 308;
                constexpr INT32 RANDOM_COMPUTER2       = 309;
                constexpr INT32 RANDOM_COMPUTER3       = 310;
                constexpr INT32 RANDOM_COMPUTER4       = 311;
                constexpr INT32 RANDOM_COMPUTER5       = 312;
                constexpr INT32 RANDOM_COMPUTER6       = 313;
                constexpr INT32 RANDOM_COMPUTER7       = 314;
                constexpr INT32 RANDOM_COMPUTER_RANDOM = 315;
                constexpr INT32 RANDOM_WATER_NONE      = 326;
                constexpr INT32 RANDOM_WATER_NORMAL    = 327;
                constexpr INT32 RANDOM_WATER_ISLANDS   = 328;
                constexpr INT32 RANDOM_WATER_RANDOM    = 329;
                constexpr INT32 RANDOM_MONSTER_WEAK    = 331;
                constexpr INT32 RANDOM_MONSTER_NORMAL  = 332;
                constexpr INT32 RANDOM_MONSTER_STRONG  = 333;
                constexpr INT32 RANDOM_MONSTER_RANDOM  = 334;
                constexpr INT32 MAPS_SCROLLBAR         = 337;
                constexpr INT32 TIMER_SCROLLBAR        = 338;
                constexpr INT32 RED_NAME               = 345;
                constexpr INT32 BLUE_NAME              = 346;
                constexpr INT32 TAN_NAME               = 347;
                constexpr INT32 GREEN_NAME             = 348;
                constexpr INT32 ORANGE_NAME            = 349;
                constexpr INT32 PURPLE_NAME            = 350;
                constexpr INT32 TEAL_NAME              = 351;
                constexpr INT32 PINK_NAME              = 352;
                constexpr INT32 RED_HERO               = 362;
                constexpr INT32 BLUE_HERO              = 363;
                constexpr INT32 TAN_HERO               = 364;
                constexpr INT32 GREEN_HERO             = 365;
                constexpr INT32 ORANGE_HERO            = 366;
                constexpr INT32 PURPLE_HERO            = 367;
                constexpr INT32 TEAL_HERO              = 368;
                constexpr INT32 PINK_HERO              = 369;
                constexpr INT32 RED_TOWN               = 370;
                constexpr INT32 BLUE_TOWN              = 371;
                constexpr INT32 TAN_TOWN               = 372;
                constexpr INT32 GREEN_TOWN             = 373;
                constexpr INT32 ORANGE_TOWN            = 374;
                constexpr INT32 PURPLE_TOWN            = 375;
                constexpr INT32 TEAL_TOWN              = 376;
                constexpr INT32 PINK_TOWN              = 377;
                constexpr INT32 RED_BONUS              = 378;
                constexpr INT32 BLUE_BONUS             = 379;
                constexpr INT32 TAN_BONUS              = 380;
                constexpr INT32 GREEN_BONUS            = 381;
                constexpr INT32 ORANGE_BONUS           = 382;
                constexpr INT32 PURPLE_BONUS           = 383;
                constexpr INT32 TEAL_BONUS             = 384;
                constexpr INT32 PINK_BONUS             = 385;
                constexpr INT32 PLAYER_FLAGS           = 387;

                constexpr INT32 TIMER_STYLE     = 3005; // hdmod
                constexpr INT32 MORE_OPTIONS    = 6999;
                constexpr INT32 RANDOM_TEMPLATE = 7002;
                constexpr INT32 TEAM_ALIGNMENT  = 7005;
            }
        } // namespace ID
    } /* namespace NH3Dlg */
    typedef NH3Dlg::eTextColor         eTextColor;
    typedef NH3Dlg::eTextAlignment     eTextAlignment;
    typedef NH3Dlg::ePictureCategories ePictureCategories;
} /* namespace h3 */

namespace h3
{
	namespace NH3DlgControls
	{
		namespace NType
		{
			enum eType : UINT16
			{
				TRANSPARENT_CTRL = 0x0001,
				SCROLL_CTRL      = 0x0001,
				BUTTON_CTRL      = 0x0002,
				TEXT_CTRL        = 0x0008,
				EDIT_CTRL        = 0x0008,
				DEF_CTRL         = 0x0010,
				FRAME_CTRL       = 0x0400,
				PCX_CTRL         = 0x0800,
			};
		}
		typedef NType::eType eType;

		namespace NState
		{
			enum eState : UINT16
			{
				PRESSED  = 0x0001, /* button is pressed */
				ACTIVE   = 0x0002, /* captures messages */
				VISIBLE  = 0x0004, /* is drawn */
				SHADED   = 0x0008, /* for pcx */
				SELECTED = 0x0010, /* for buttons */
				ENABLED  = 0x0020, /* item accepts user input */
				FOCUSED  = 0x0040,
			};
			_H3API_ENUM_OPERATORS_(eState, INT16);
		}
		typedef NState::eState eState;
	} /* namespace NH3DlgControls */
	typedef NH3DlgControls::eType  eControl;
	typedef NH3DlgControls::eState eControlState;
} /* namespace h3 */

namespace h3
{
    namespace NH3Levels
    {
        constexpr INT32 LEVEL_0    = -2147483647 - 1;
        constexpr INT32 LEVEL_1    = 0;
        constexpr INT32 LEVEL_2    = 1000;
        constexpr INT32 LEVEL_3    = 2000;
        constexpr INT32 LEVEL_4    = 3200;
        constexpr INT32 LEVEL_5    = 4600;
        constexpr INT32 LEVEL_6    = 6200;
        constexpr INT32 LEVEL_7    = 8000;
        constexpr INT32 LEVEL_8    = 10000;
        constexpr INT32 LEVEL_9    = 12200;
        constexpr INT32 LEVEL_10   = 14700;
        constexpr INT32 LEVEL_11   = 17500;
        constexpr INT32 LEVEL_12   = 20600;
        constexpr INT32 LEVEL_13   = 24320;
        constexpr INT32 LEVEL_14   = 28784;
        constexpr INT32 LEVEL_15   = 34140;
        constexpr INT32 LEVEL_16   = 40567;
        constexpr INT32 LEVEL_17   = 48279;
        constexpr INT32 LEVEL_18   = 57533;
        constexpr INT32 LEVEL_19   = 68637;
        constexpr INT32 LEVEL_20   = 81961;
        constexpr INT32 LEVEL_21   = 97949;
        constexpr INT32 LEVEL_22   = 117134;
        constexpr INT32 LEVEL_23   = 140156;
        constexpr INT32 LEVEL_24   = 167782;
        constexpr INT32 LEVEL_25   = 200933;
        constexpr INT32 LEVEL_26   = 240714;
        constexpr INT32 LEVEL_27   = 288451;
        constexpr INT32 LEVEL_28   = 345735;
        constexpr INT32 LEVEL_29   = 414475;
        constexpr INT32 LEVEL_30   = 496963;
        constexpr INT32 LEVEL_31   = 595948;
        constexpr INT32 LEVEL_32   = 714730;
        constexpr INT32 LEVEL_33   = 857268;
        constexpr INT32 LEVEL_34   = 1028313;
        constexpr INT32 LEVEL_35   = 1233567;
        constexpr INT32 LEVEL_36   = 1479871;
        constexpr INT32 LEVEL_37   = 1775435;
        constexpr INT32 LEVEL_38   = 2130111;
        constexpr INT32 LEVEL_39   = 2555722;
        constexpr INT32 LEVEL_40   = 3066455;
        constexpr INT32 LEVEL_41   = 3679334;
        constexpr INT32 LEVEL_42   = 4414788;
        constexpr INT32 LEVEL_43   = 5297332;
        constexpr INT32 LEVEL_44   = 6356384;
        constexpr INT32 LEVEL_45   = 7627246;
        constexpr INT32 LEVEL_46   = 9152280;
        constexpr INT32 LEVEL_47   = 10982320;
        constexpr INT32 LEVEL_48   = 13178368;
        constexpr INT32 LEVEL_49   = 15813625;
        constexpr INT32 LEVEL_50   = 18975933;
        constexpr INT32 LEVEL_51   = 22770702;
        constexpr INT32 LEVEL_52   = 27324424;
        constexpr INT32 LEVEL_53   = 32788890;
        constexpr INT32 LEVEL_54   = 39346249;
        constexpr INT32 LEVEL_55   = 47215079;
        constexpr INT32 LEVEL_56   = 56657675;
        constexpr INT32 LEVEL_57   = 67988790;
        constexpr INT32 LEVEL_58   = 81586128;
        constexpr INT32 LEVEL_59   = 97902933;
        constexpr INT32 LEVEL_60   = 117483099;
        constexpr INT32 LEVEL_61   = 140979298;
        constexpr INT32 LEVEL_62   = 169174736;
        constexpr INT32 LEVEL_63   = 203009261;
        constexpr INT32 LEVEL_64   = 243610691;
        constexpr INT32 LEVEL_65   = 292332407;
        constexpr INT32 LEVEL_66   = 350798466;
        constexpr INT32 LEVEL_67   = 420957736;
        constexpr INT32 LEVEL_68   = 505148860;
        constexpr INT32 LEVEL_69   = 606178208;
        constexpr INT32 LEVEL_70   = 727413425;
        constexpr INT32 LEVEL_71   = 872895685;
        constexpr INT32 LEVEL_72   = 1047474397;
        constexpr INT32 LEVEL_73   = 1256968851;
        constexpr INT32 LEVEL_74   = 1508362195;
        constexpr INT32 LEVEL_88   = 1810034207;
        constexpr INT32 LEVEL_100  = 2073739175;
        constexpr INT32 LEVEL_108  = 2099639276;
        constexpr INT32 LEVEL_868  = 2144641867;
        constexpr INT32 LEVEL_3732 = 2146553679;
        constexpr INT32 LEVEL_5920 = 2146673313;
        constexpr INT32 LEVEL_6424 = 2147293156;
        constexpr INT32 LEVEL_MAX  = 2147400657;
    } /* namespace NH3Levels */
} /* namespace h3 */

namespace h3
{
    namespace NH3Heroes
    {
        namespace NHeroClasses
        {
            enum eHeroClasses : INT32
            {
                KNIGHT       = 0,
                CLERIC       = 1,
                RANGER       = 2,
                DRUID        = 3,
                ALCHEMIST    = 4,
                WIZARD       = 5,
                DEMONIAC     = 6,
                HERETIC      = 7,
                DEATH_KNIGHT = 8,
                NECROMANCER  = 9,
                OVERLORD     = 10,
                WARLOCK      = 11,
                BARBARIAN    = 12,
                BATTLE_MAGE  = 13,
                BEASTMASTER  = 14,
                WITCH        = 15,
                PLANESWALKER = 16,
                ELEMENTALIST = 17,
            };
        }
        typedef NHeroClasses::eHeroClasses eHeroClasses;

        namespace NHeroSpecialty
        {
            enum eHeroSpecialty : UINT32
            {
                SKILL           = 0,
                CREATURE_LEVEL  = 1,
                RESOURCE        = 2,
                SPELL           = 3,
                STATIC_CREATURE = 4,
                SPEED           = 5,
                CONVERSION      = 6,
                DRAGON          = 7,
            };
        }
        typedef NHeroSpecialty::eHeroSpecialty eHeroSpecialty;

        namespace NHeroIdentity
        {
            enum eHeroIdentity : INT32
            {
                MOST_POWERFUL = -3,
                RANDOM        = -1,

                ORRIN        = 0,
                VALESKA      = 1,
                EDRIC        = 2,
                SYLVIA       = 3,
                LORD_HAART   = 4,
                SORSHA       = 5,
                CHRISTIAN    = 6,
                TYRIS        = 7,

                RION         = 8,
                ADELA        = 9,
                CUTHBERT     = 10,
                ADELAIDE     = 11,
                INGHAM       = 12,
                SANYA        = 13,
                LOYNIS       = 14,
                CAITLIN      = 15,

                MEPHALA      = 16,
                UFRETIN      = 17,
                JENOVA       = 18,
                RYLAND       = 19,
                THORGRIM     = 20,
                IVOR         = 21,
                CLANCY       = 22,
                KYRRE        = 23,

                CORONIUS     = 24,
                ULAND        = 25,
                ELLESHAR     = 26,
                GEM          = 27,
                MALCOM       = 28,
                MELODIA      = 29,
                ALAGAR       = 30,
                AERIS        = 31,

                PIQUEDRAM    = 32,
                THANE        = 33,
                JOSEPHINE    = 34,
                NEELA        = 35,
                TOROSAR      = 36,
                FAFNER       = 37,
                RISSA        = 38,
                IONA         = 39,

                ASTRAL       = 40,
                HALON        = 41,
                SERENA       = 42,
                DAREMYTH     = 43,
                THEODORUS    = 44,
                SOLMYR       = 45,
                CYRA         = 46,
                AINE         = 47,

                FIONA        = 48,
                RASHKA       = 49,
                MARIUS       = 50,
                IGNATIUS     = 51,
                OCTAVIA      = 52,
                CALH         = 53,
                PYRE         = 54,
                NYMUS        = 55,

                AYDEN        = 56,
                XYRON        = 57,
                AXSIS        = 58,
                OLEMA        = 59,
                CALID        = 60,
                ASH          = 61,
                ZYDAR        = 62,
                XARFAX       = 63,

                STRAKER      = 64,
                VOKIAL       = 65,
                MOANDOR      = 66,
                CHARNA       = 67,
                TAMIKA       = 68,
                ISRA         = 69,
                CLAVIUS      = 70,
                GALTHRAN     = 71,

                SEPTIENNA    = 72,
                AISLINN      = 73,
                SANDRO       = 74,
                NIMBUS       = 75,
                THANT        = 76,
                XSI          = 77,
                VIDOMINA     = 78,
                NAGASH       = 79,

                LORELEI      = 80,
                ARLACH       = 81,
                DACE         = 82,
                AJIT         = 83,
                DAMACON      = 84,
                GUNNAR       = 85,
                SYNCA        = 86,
                SHAKTI       = 87,

                ALAMAR       = 88,
                JAEGAR       = 89,
                MALEKITH     = 90,
                JEDDITE      = 91,
                GEON         = 92,
                DEEMER       = 93,
                SEPHINROTH   = 94,
                DARKSTORN    = 95,

                YOG          = 96,
                GURNISSON    = 97,
                JABARKAS     = 98,
                SHIVA        = 99,
                GRETCHIN     = 100,
                KRELLION     = 101,
                CRAG_HACK    = 102,
                TYRAXOR      = 103,

                GIRD         = 104,
                VEY          = 105,
                DESSA        = 106,
                TEREK        = 107,
                ZUBIN        = 108,
                GUNDULA      = 109,
                ORIS         = 100,
                SAURUG       = 111,

                BRON         = 112,
                DRAKON       = 113,
                WYSTAN       = 114,
                TAZAR        = 115,
                ALKIN        = 116,
                KORBAC       = 117,
                GERWULF      = 118,
                BROGHILD     = 119,

                MIRLANDA     = 120,
                ROSIC        = 121,
                VOY          = 122,
                VERDISH      = 123,
                MERIST       = 124,
                STYG         = 125,
                ANDRA        = 126,
                TIVA         = 127,

                PASIS        = 128,
                THUNAR       = 129,
                IGNISSA      = 130,
                LACUS        = 131,
                MONERE       = 132,
                ERDAMON      = 133,
                FIUR         = 134,
                KALT         = 135,

                LUNA         = 136,
                BRISSA       = 137,
                CIELE        = 138,
                LABETHA      = 139,
                INTEUS       = 140,
                AENAIN       = 141,
                GELARE       = 142,
                GRINDAN      = 143,

                SIR_MULLICH  = 144,
                ADRIENNE     = 145,
                CATHERINE    = 146,
                DRACON       = 147,
                GELU         = 148,
                KILGOR       = 149,
                LORD_HAART2  = 150,
                MUTARE       = 151,
                ROLAND       = 152,
                MUTARE_DRAKE = 153,
                BORAGUS      = 154,
                XERON        = 155,

                GENERAL_KENDAL     = 156,
                CAMPAIGN_CHRISTIAN = 157,
                CAMPAIGN_GEM       = 158,
                FINNEAS_VILMAR     = 159,
                ORDWALD            = 160,
                CAMPAIGN_SANDRO    = 161,
                CAMPAIGN_YOG       = 162,
            };
        }
        typedef NHeroIdentity::eHeroIdentity eHeroIdentity;

        namespace NHeroRace
        {
            enum eHeroRace : INT32
            {
                DEMON      = 0,
                DWARF      = 1,
                EFREET     = 2,
                ELF        = 3,
                GENIE      = 4,
                GNOLL      = 5,
                GOBLIN     = 6,
                HUMAN      = 7,
                LICH       = 8,
                LIZARDMAN  = 9,
                MINOTAUR   = 10,
                OGRE       = 11,
                TROGLODYTE = 12,
                VAMPIRE    = 13,
            };
        }
        typedef NHeroRace::eHeroRace eHeroRace;
    } /* namespace NH3Heroes */
    typedef NH3Heroes::eHeroClasses   eHeroClass;
    typedef NH3Heroes::eHeroSpecialty eHeroSpecialty;
    typedef NH3Heroes::eHeroIdentity  eHero;
    typedef NH3Heroes::eHeroRace      eHeroRace;
} /* namespace h3 */

namespace h3
{
    namespace NH3Dispositions
    {
        enum eDisposition
        {
            COMPLIANT  = 0,
            FRIENDLY   = 1,
            AGGRESSIVE = 2,
            HOSTILE    = 3,
            SAVAGE     = 4,
        };
    }
    typedef NH3Dispositions::eDisposition eDisposition;

    namespace NH3Formats
    {
        enum eFormats
        {
            ROE = 0x0E,
            AB  = 0x15,
            SOD = 0x1C,
            CHR = 0x1D,
            WOG = 0x33,
        };
    }
    typedef NH3Dispositions::eDisposition eCreatureDisposition;
    typedef NH3Formats::eFormats          eMapFormat;
} /* namespace h3 */

namespace h3
{
	namespace NH3Messages
	{
		namespace NItemIDs
		{
			enum eItemIDs
			{
				SAVE         = 30000, /* custom value */
				OK           = 30725,
				CANCEL       = 30726,
                SELECT_RIGHT = 30729,
                SELECT_LEFT  = 30730,
			};
		}
		typedef NItemIDs::eItemIDs eItemIDs;

		namespace NMessageCommand
		{
			enum eMessageCommand
			{
				NONE           = 0,
				KEY_DOWN       = 0x0001,
				KEY_UP         = 0x0002,
				MOUSE_OVER     = 0x0004,
				LCLICK_OUTSIDE = 0x0008,
				LBUTTON_UP     = 0x0010,
				ITEM_REDRAW    = 0x0010,
				RCLICK_OUTSIDE = 0x0020,
				RBUTTON_UP     = 0x0040,
				KEY_HELD       = 0x0100,
				MOUSE_BUTTON   = 0x0200,
				ITEM_COMMAND   = 0x0200,
				WHEEL_BUTTON   = 0x0309,
				MOUSE_WHEEL    = 0x020A,

			};
		}
		typedef NMessageCommand::eMessageCommand eMessageCommand;

		namespace NMessageMsgSubtype
		{
			enum eMessageMsgSubtype
			{
				NONE                    = 0,
				END_DIALOG              = 0xA,
				LBUTTON_DOWN            = 0xC,
				LBUTTON_CLICK           = 0xD,
				RBUTTON_DOWN            = 0xE,
				MOUSE_WHEEL_BUTTON_DOWN = 0x207,
				MOUSE_WHEEL_BUTTON_UP   = 0x208,


				REPAINT           = 0x02, /* no payload */
				SET_TEXT          = 0x03, /* LPCSTR text */
				SET_FRAME         = 0x04, /* INT def frame */
				ADD_FLAGS         = 0x05, /* INT alters control state TODO */
				REMOVE_FLAGS      = 0x06, /* INT alters control state TODO */
				SET_COLOR         = 0x08, /* INT for DlgFrame */
				CLOSE_ON_CLICK    = 0x08, /* INT for DlgDef */
				SET_IMAGE         = 0x09, /* LPCSTR name, replaces existing sprite */
				SET_PALETTE       = 0x0A, /* LPCSTR name */
				SET_FRAME_GROUP   = 0x0C, /* sets def frame to 0 and group to specified type*/
				USE_PLAYER_COLOR  = 0x0D, /* INT player index */
				SET_TICK_COUNT    = 0x31, /* INT for scrollbar */
				SET_TICK_POSITION = 0x32, /* INT for scrollbar */
				SET_LENGTH        = 0x33, /* max length: Edit Control */
				SET_X             = 0x34, /* INT new x position */
				SET_Y             = 0x35, /* INT new y position */
				SET_WIDTH         = 0x3D, /* INT new width */
				CHANGE_HUE        = 0x3F, /* BOOL for DlgFrame */
			};
		}
		typedef NMessageMsgSubtype::eMessageMsgSubtype eMessageMsgSubtype;

		namespace NMessageMsgFlag
		{
			enum eMessageMsgFlag
			{
				NONE  = 0,
				SHIFT = 1,
				CTRL  = 4,
				ALT   = 32,

				CTRL_SHIFT = CTRL | SHIFT,
				SHIFT_CTRL = CTRL_SHIFT,

				CTRL_ALT   = CTRL | ALT,
				ALT_CTRL   = CTRL_ALT,

				SHIFT_ALT  = SHIFT | ALT,
				ALT_SHIFT  = SHIFT_ALT,
			};
			_H3API_ENUM_OPERATORS_(eMessageMsgFlag, INT16);
		}
		typedef NMessageMsgFlag::eMessageMsgFlag eMessageMsgFlag;

	} /* namespace NH3Messages */
	typedef NH3Messages::eItemIDs        eControlId;
	typedef NH3Messages::eMessageCommand eMsgCommand;
	typedef NH3Messages::eMessageMsgSubtype eMsgSubtype;
	typedef NH3Messages::eMessageMsgFlag    eMsgFlag;
} /* namespace h3 */

namespace h3
{
    namespace NH3Mouse
    {
        namespace NMouseCursorType
        {
            enum eMouseCursorType : INT32
            {
                DEFAULT   = 0,
                ADVENTURE = 1,
                COMBAT    = 2,
                SPELL     = 3,
                ARTIFACT  = 4,
            };
        }
        typedef NMouseCursorType::eMouseCursorType eMouseCursorType;

        namespace NAdventureMapCursorType
        {
            enum eAdventureMapCursorType
            {
                ARROWPOINTER         = 0,
                BUSY_WAIT            = 1,
                HERO                 = 2,
                TOWN                 = 3,
                HORSE                = 4,
                ATTACK               = 5,
                BOAT                 = 6,
                ANCHOR               = 7,
                HERO_MEETING         = 8,
                REARING_HORSE        = 9,
                HORSE2               = 10,
                ATTACK2              = 11,
                BOAT2                = 12,
                ANCHOR2              = 13,
                HERO_MEETING2        = 14,
                REARING_HORSE2       = 15,
                HORSE3               = 16,
                ATTACK3              = 17,
                BOAT3                = 18,
                ANCHOR3              = 19,
                HERO_MEETING3        = 20,
                REARING_HORSE3       = 21,
                HORSE4               = 22,
                ATTACK4              = 23,
                BOAT4                = 24,
                ANCHOR4              = 25,
                HERO_MEETING4        = 26,
                REARING_HORSE4       = 27,
                BOAT_1               = 28,
                BOAT_2               = 29,
                BOAT_3               = 30,
                BOAT_4               = 31,
                MAP_SCROLL_NORTH     = 32,
                MAP_SCROLL_NORTHEAST = 33,
                MAP_SCROLL_EAST      = 34,
                MAP_SCROLL_SOUTHEAST = 35,
                MAP_SCROLL_SOUTH     = 36,
                MAP_SCROLL_SOUTHWEST = 37,
                MAP_SCROLL_WEST      = 38,
                MAP_SCROLL_NORTHWEST = 39,
                ARROW_POINTER        = 40,
                DIMENSION_DOOR       = 41,
                SCUTTLE_BOAT         = 42,
            };
        }
        typedef NAdventureMapCursorType::eAdventureMapCursorType eAdventureMapCursorType;

        namespace NBattleFieldCursorType
        {
            enum eBattleFieldCursorType
            {
                NONE             = 0,
                MOVE             = 1,
                FLY              = 2,
                SHOOTING         = 3,
                HERO             = 4,
                QUESTION_MARK    = 5,
                ARROW_POINTER    = 6,
                ATTACK_NORTHEAST = 7,
                ATTACK_EAST      = 8,
                ATTACK_SOUTHEAST = 9,
                ATTACK_SOUTHWEST = 10,
                ATTACK_WEST      = 11,
                ATTACK_NORTHWEST = 12,
                ATTACK_NORTH     = 13,
                ATTACK_SOUTH     = 14,
                HALF_DAMAGE      = 15,
                ATTACK_WALL      = 16,
                HEAL             = 17,
                SACRIFICE        = 18,
                TELEPORT         = 19,
            };
        }
        typedef NBattleFieldCursorType::eBattleFieldCursorType eBattleFieldCursorType;
    }
    typedef NH3Mouse::eMouseCursorType        eCursor;
    typedef NH3Mouse::eAdventureMapCursorType eAdvCursor;
    typedef NH3Mouse::eBattleFieldCursorType  eCmbCursor;
} /* namespace h3 */

namespace h3
{
	namespace NH3Network
    {
        namespace NNetwork
        {
            enum eNetworkId // from 0x405DC0
            {
                LOAD_GAME        = 1000,
                TEXT_MSG         = 1004,
                BATTLE_INFO      = 1005,
                PLAYER_E4        = 1009,
                DROP_GAME        = 1014,
                UNK1015          = 1015,
                END_TURN         = 1016,
                DROP_MSG         = 1017,
                ADD_PLAYER       = 1018,
                END_GAME         = 1019,
                LOSE_GAME        = 1020,
                REVEAL_AREA      = 1021,
                REVEAL_AREA2     = 1022, // identical except map draw parameters
                MOVE_HERO        = 1050,
                TELEPORT_HERO    = 1051,
                CAPTURE_MINE     = 1052,
                CAPTURE_TOWN     = 1053,
                CAPTURE_DWELLING = 1054,
                CAPTURE_GARRISON = 1055,
                CAPTURE_SHIPYARD = 1056,
                ADD_BOAT         = 1057,
                DELETE_OBJECT    = 1058,
                DELETE_HERO      = 1059,
                SHOW_HERO        = 1060,
                VANQUISHED_MBOX  = 1061,
                HIDE_HERO        = 1062,
                HEROES_MEET      = 1064,
                START_TURN       = 1071,
                UNK1074          = 1074,
                ASK_GIFT         = 1075,
                CONNECTION_LOST  = 1076,
                UNK1078          = 1078,
            };
        }
        typedef NNetwork::eNetworkId eNetworkId;
    } /* namespace NH3Network */
    typedef NH3Network::eNetworkId eNetwork;
} /* namespace h3 */

namespace h3
{
    namespace NH3ReplayActions
    {
        namespace NReplayActions
        {
            enum eType
            {
                HERO_MOVE       = 1,
                HERO_TELEPORT   = 2,
                CAPTURE_MINE    = 3,
                CAPTURE_TOWN    = 4,
                BOAT_HIDE       = 5,
                BOAT_ADD        = 6,
                DELETE_OBJECT   = 7,
                HERO_DELETE     = 8,
                HERO_ADD        = 9,
                PLAYER_DEFEATED = 10, // %s has been vanquished!, seems unused except through load game
                MAP_VISION      = 11,
            };
        }
        typedef NReplayActions::eType eType;
    } /* namespace NH3ReplayActions */
    typedef NH3ReplayActions::eType eReplayAction;
} /* namespace h3 */

namespace h3
{
    namespace NH3Towns
    {
        namespace NTownType
        {
            enum eTownType
            {
                NEUTRAL    = -1,
                CASTLE     = 0,
                RAMPART    = 1,
                TOWER      = 2,
                INFERNO    = 3,
                NECROPOLIS = 4,
                DUNGEON    = 5,
                STRONGHOLD = 6,
                FORTRESS   = 7,
                CONFLUX    = 8,
            };
        }
        typedef NTownType::eTownType eTownType;

        namespace NBuildings
        {
            enum eBuildings // from ERM help
            {
                MAGE_GUILD1              = 0,
                MAGE_GUILD2              = 1,
                MAGE_GUILD3              = 2,
                MAGE_GUILD4              = 3,
                MAGE_GUILD5              = 4,
                TAVERN                   = 5,
                WHARF                    = 6,
                FORT                     = 7,
                CITADEL                  = 8,
                CASTLE                   = 9,
                VILAGE_HALL              = 10,
                TOWN_HALL                = 11,
                CITY_HALL                = 12,
                CAPITOL                  = 13,
                MARKET                   = 14,
                RESOURCE_SILO            = 15,
                BLACKSMITH               = 16,
                SPEC17                   = 17,
                HORDE1                   = 18,
                HORDE1U                  = 19,
                WHARF2                   = 20,
                SPEC21                   = 21,
                SPEC22                   = 22,
                SPEC23                   = 23,
                HORDE2                   = 24,
                HORDE2U                  = 25,
                GRAIL                    = 26,
                DECOR27                  = 27,
                DECOR28                  = 28,
                DECOR29                  = 29,
                DWELL1                   = 30,
                DWELL2                   = 31,
                DWELL3                   = 32,
                DWELL4                   = 33,
                DWELL5                   = 34,
                DWELL6                   = 35,
                DWELL7                   = 36,
                DWELL1U                  = 37,
                DWELL2U                  = 38,
                DWELL3U                  = 39,
                DWELL4U                  = 40,
                DWELL5U                  = 41,
                DWELL6U                  = 42,
                DWELL7U                  = 43,

                LIGHTHOUSE               = 17,
                STABLES                  = 21,
                BROTHERHOOD_OF_THE_SWORD = 22,

                MYSTIC_POND              = 17,
                FOUNTAIN_OF_FORTUNE      = 21,
                DWARVEN_TREASURY         = 22,

                ARTIFACT_MERCHANT        = 17, // same for Dungeon and Conflux
                LOOKOUT_TOWER            = 21,
                LIBRARY                  = 22,
                WALL_OF_KNOWLEDGE        = 23,

                BRIMSTONECLOUDS          = 21,
                CASTLE_GATE              = 22,
                ORDER_OF_FIRE            = 23,

                VEIL_OF_DARKNESS         = 17,
                NECROMANCY_AMPLIFIER     = 21,
                SKELETON_TRANSFORMER     = 22,

                MANA_VORTEX              = 21,
                PORTAL_OF_SUMMONING      = 22,
                BATTLE_ACADEMY           = 23,

                ESCAPE_TUNNEL            = 17,
                FREELANCERS_GUILD        = 21,
                BALLISTA_YARD            = 22,
                HALL_OF_VALHALLA         = 23,

                CAGE_OF_WARLORDS         = 17,
                GLYPHS_OF_FEAR           = 21,
                BLOOD_OBELISK            = 22,

                MAGIC_UNIVERSITY         = 21
            };
        }
        typedef NBuildings::eBuildings eBuildings;

        namespace NNeutralBuildings
        {
            enum eNeutralBuildings
            {
                MAGE_GUILD1      = 0,
                MAGE_GUILD2      = 1,
                MAGE_GUILD3      = 2,
                MAGE_GUILD4      = 3,
                MAGE_GUILD5      = 4,
                TAVERN           = 5,
                DOCK             = 6,
                FORT             = 7,
                CITADEL          = 8,
                CASTLE           = 9,
                VILLAGE          = 10,
                TOWN             = 11,
                CITY             = 12,
                CAPITOL          = 13,
                MARKETPLACE      = 14,
                RESOURCE_SILO    = 15,
                BLACKSMITH       = 16,
            };
        }
        typedef NNeutralBuildings::eNeutralBuildings eNeutralBuildings;

        namespace NBuildingRequirements
        {
            enum eBuildingRequirements
            {
                MAGE_GUILD1   = 0,
                MAGE_GUILD2   = 1,
                MAGE_GUILD3   = 2,
                MAGE_GUILD4   = 3,
                MAGE_GUILD5   = 4,
                TAVERN        = 5,
                WHARF         = 6,
                FORT          = 7,
                CITADEL       = 8,
                CASTLE        = 9,
                VILLAGE       = 10,
                TOWN          = 11,
                CITY          = 12,
                CAPITOL       = 13,
                MARKET        = 14,
                RESOURCE_SILO = 15,
                BLACKSMITH    = 16,
                SPEC17        = 17,
                HORDE1        = 18,
                HORDE1U       = 19,
                WHARF2        = 20,
                SPEC21        = 21,
                SPEC22        = 22,
                SPEC23        = 23,
                HORDE2        = 24,
                HORDE2U       = 25,
                GRAIL         = 26,
                DECOR27       = 27,
                DECOR28       = 28,
                DECOR29       = 29,
                DWELL1        = 30,
                DWELL2        = 31,
                DWELL3        = 32,
                DWELL4        = 33,
                DWELL5        = 34,
                DWELL6        = 35,
                DWELL7        = 36,
                DWELL1U       = 37,
                DWELL2U       = 38,
                DWELL3U       = 39,
                DWELL4U       = 40,
                DWELL5U       = 41,
                DWELL6U       = 42,
                DWELL7U       = 43,
            };
        }
        typedef NBuildingRequirements::eBuildingRequirements eBuildingRequirements;

        namespace NSpecialBuildings
        {
            enum eSpecialBuildings
            {
                LIGHTHOUSE = 0,
                GRIFFIN_HORDE,
                ROYAL_GRIFFIN_HORDE,
                UNUSED_CASTLE1,
                STABLES,
                TAVERN_UPGRADE,
                UNUSED_CASTLE2,
                UNUSED_CASTLE3,
                UNUSED_CASTLE4,

                MYSTIC_GARDEN = 0,
                DWARF_HORDE,
                BATTLE_DWARF_HORDE,
                UNUSED_RAMPART1,
                RAINBOW,
                TREASURY,
                UNUSED_RAMPART2,
                TREEFOLK_HORDE,
                BRIAR_TREEFOLK_HORDE,

                ARTIFACT_MERCHANTS_TOWER = 0,
                STONE_GARGOYLE_HORDE,
                OBSIDIAN_GARGOYLE_HORDE,
                UNUSED_TOWER1,
                WATCHTOWER,
                LIBRARY,
                WALL_OF_GLYPHIC_KNOWLEDGE,
                UNUSED_TOWER2,
                UNUSED_TOWER3,

                UNUSED_INFERNO1 = 0,
                IMP_HORDE,
                FAMILIAR_HORDE,
                UNUSED_INFERNO2,
                BRIMSTONE_STORMCLOUDS,
                CASTLE_GATE,
                ORDER_OF_FIRE,
                HELL_HOUND_HORDE,
                CERBERUS_HORDE,

                COVER_OF_DARKNESS = 0,
                SKELETON_HORDE,
                SKELETON_WARRIOR_HORDE,
                UNUSED_NECROPOLIS1,
                NECROMANCY_AMPLIFIER,
                SKELETON_TRANSFORMER,
                UNUSED_NECROPOLIS2,
                UNUSED_NECROPOLIS3,
                UNUSED_NECROPOLIS4,

                ARTIFACT_MERCHANTS_DUNGEON = 0,
                TROGLODYTE_HORDE,
                INFERNAL_TROGLODYTE_HORDE,
                UNUSED_DUNGEON1,
                MANA_VORTEX,
                PORTAL_OF_SUMMONING,
                ACADEMY_OF_BATTLE_SCHOLARS,
                UNUSED_DUNGEON2,
                UNUSED_DUNGEON3,

                ESCAPE_TUNNEL = 0,
                GOBLIN_HORDE,
                HOBGOBLIN_HORDE,
                UNUSED_STRONGHOLD1,
                FREELANCERS_GUILD,
                BALLISTA_WORKS,
                HALL_OF_VALHALLA,
                UNUSED_STRONGHOLD2,
                UNUSED_STRONGHOLD3,

                DEFENSE_CAGE = 0,
                GNOLL_HORDE,
                GNOLL_MARAUDER_HORDE,
                UNUSED_FORTRESS1,
                SIEGE_DEFENSE,
                SIEGE_ATTACK,
                UNUSED_FORTRESS2,
                UNUSED_FORTRESS3,
                UNUSED_FORTRESS4,

                ARTIFACT_MERCHANTS = 0,
                PIXIE_HORDE,
                SPRITE_HORDE,
                UNUSED_CONFLUX1,
                MAGIC_UNIVERSITY,
                UNUSED_CONFLUX2,
                UNUSED_CONFLUX3,
                UNUSED_CONFLUX4,
                UNUSED_CONFLUX5,
            };
        }
        typedef NSpecialBuildings::eSpecialBuildings eSpecialBuildings;
    } /* namespace NH3Towns */
    typedef NH3Towns::eTownType             eTown;
    typedef NH3Towns::eBuildings            eBuildings;
    typedef NH3Towns::eNeutralBuildings     eNeutralBuildings;
    typedef NH3Towns::eBuildingRequirements eBuildingRequirements;
    typedef NH3Towns::eSpecialBuildings     eSpecialBuildings;
} /* namespace h3 */

namespace h3
{
    namespace NH3Loss
    {
        enum eType : INT8
        {
            NONE         = -1,
            LOSE_TOWN    = 0,
            LOSE_HERO    = 1,
            TIME_EXPIRES = 2,
        };
    } /* namespace NH3Loss */

    namespace NH3Victory
    {
        enum eType : INT8
        {
            NONE                  = -1,
            ACQUIRE_ARTIFACT      = 0,
            ACCUMULATE_CREATURE   = 1,
            ACCUMULATE_RESOURCE   = 2,
            UPGRADE_TOWN          = 3,
            BUILD_HOLY_GRAIL      = 4,
            DEFEAT_HERO           = 5,
            CAPTURE_TOWN          = 6,
            DEFEAT_MONSTER        = 7,
            FLAG_GENERATORS       = 8,
            FLAG_MINES            = 9,
            TRANSPORT_ARTIFACT    = 10,
            FESTIVAL_OF_LIFE      = 11, // You have defeated all of the monsters plaguing this land!
            FOOLHARDY_WAYWARDNESS = 12, // You have managed to survive!
        };
    } /* namespace NH3Victory */
    typedef NH3Loss::eType    eLoss;
    typedef NH3Victory::eType eVictory;
} /* namespace h3 */

namespace h3
{
    namespace NH3VKey
    {
        enum eVirtualKeys : INT32
        {
            H3VK_ESCAPE        = 1,
            H3VK_1             = 2,
            H3VK_2             = 3,
            H3VK_3             = 4,
            H3VK_4             = 5,
            H3VK_5             = 6,
            H3VK_6             = 7,
            H3VK_7             = 8,
            H3VK_8             = 9,
            H3VK_9             = 10,
            H3VK_0             = 11,
            H3VK_MINUS         = 12,
            H3VK_PLUS          = 13,
            H3VK_BACKSPACE     = 14,
            H3VK_TAB           = 15,
            H3VK_Q             = 16,
            H3VK_W             = 17,
            H3VK_E             = 18,
            H3VK_R             = 19,
            H3VK_T             = 20,
            H3VK_Y             = 21,
            H3VK_U             = 22,
            H3VK_I             = 23,
            H3VK_O             = 24,
            H3VK_P             = 25,
            H3VK_LEFT_BRACKET  = 26,
            H3VK_RIGHT_BRACKET = 27,
            H3VK_ENTER         = 28,
            H3VK_CTRL          = 29,
            H3VK_A             = 30,
            H3VK_S             = 31,
            H3VK_D             = 32,
            H3VK_F             = 33,
            H3VK_G             = 34,
            H3VK_H             = 35,
            H3VK_J             = 36,
            H3VK_K             = 37,
            H3VK_L             = 38,
            H3VK_SEMICOLON     = 39,
            H3VK_APOSTROPHE    = 40,
            H3VK_TILDE         = 41,
            H3VK_SHIFT         = 42,
            H3VK_BACKSLASH     = 43,
            H3VK_Z             = 44,
            H3VK_X             = 45,
            H3VK_C             = 46,
            H3VK_V             = 47,
            H3VK_B             = 48,
            H3VK_N             = 49,
            H3VK_M             = 50,
            H3VK_COMMA         = 51,
            H3VK_PERIOD        = 52,
            H3VK_SLASH         = 53,
            H3VK_RIGHT_SHIFT   = 54,
            H3VK_PRINTSCREEN   = 55, // or * on numpad?
            H3VK_ALT           = 56,
            H3VK_SPACEBAR      = 57,

            H3VK_F2            = 60,
            H3VK_F3            = 61,
            H3VK_F4            = 62,
            H3VK_F5            = 63,
            H3VK_F6            = 64,
            H3VK_F7            = 65,
            H3VK_F8            = 66,
            H3VK_F9            = 67,
            H3VK_F10           = 68,
            H3VK_PAUSE         = 69,
            H3VK_SCROLL_LOCK   = 70,
            H3VK_HOME          = 71, // numpad7
            H3VK_UP            = 72, // numpad8
            H3VK_PAGE_UP       = 73, // numpad9
            H3VK_NUMPAD_MINUS  = 74,
            H3VK_LEFT          = 75, // numpad4
            H3VK_NUMPAD5       = 76,
            H3VK_RIGHT         = 77, // numpad6
            H3VK_NUMPAD_PLUS   = 78,
            H3VK_END           = 79, // numpad1
            H3VK_DOWN          = 80, // numpad2
            H3VK_PAGE_DOWN     = 81, // numpad3
            H3VK_INSERT        = 82,
            H3VK_DELETE        = 83,

            H3VK_F11           = 87,
            H3VK_F12           = 88,

            H3VK_LEFT_WIN      = 91,
            H3VK_RIGHT_WIN     = 92,
            H3VK_RIGHT_CLICK   = 93,
        };
    } /* namespace NH3VKey */
    typedef NH3VKey::eVirtualKeys eVKey;
} /* namespace h3 */

namespace h3
{
    template<typename T, UINT NilNode> struct H3Set;
#ifdef _H3API_TEMPLATE_DECLARE_
    template<typename T, UINT NilNode>
    using Set = H3Set<T, NilNode>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

#pragma pack(push, 4)
    template<typename T, UINT NilNode = 0>
    struct H3Set
    {
        _H3API_SIZE_(0x10);

        struct Node
        {
            Node* left;    /**< @brief [00] left child*/
            Node* parent;  /**< @brief [04] parent node*/
            Node* right;   /**< @brief [08] right child*/
            T     data;    /**< @brief [0C] The data for this node*/
            BOOL  isBlack; /**< @brief [0C + sizeof(T)] whether the node is black(1) or red(0)*/

            T* operator->() const { return &data; }
            T& operator*() const  { return data; }
        };
        typedef typename Node* NodePtr;
    protected:
        h3unk8 _allocator;  /**< @brief [00] default allocator, C++ requires 1 byte even if no body*/
        h3unk8 _keyCompare; /**< @brief [01] default key comparator, C++ requires 1 byte even if no body*/
        Node*  m_root;      /**< @brief [04] The anchor node of the tree*/
        BOOL8  m_multiset;  /**< @brief [08] accept duplicate keys or not*/
        UINT32 m_count;     /**< @brief [0C] The number of nodes in the tree*/

        Node* head() const;

    #ifdef _H3API_CPLUSPLUS11_
        static constexpr Node** _Nil = reinterpret_cast<Node**>(NilNode);
    #else
        _H3API_FORCEINLINE_ static Node** _Nil();
    #endif
    public:

        struct iterator
        {
        protected:
            Node* m_node;
            Node* endNode() const;
        public:
            iterator& operator++();
            iterator operator++(int);
            T& operator*() const;
            T* operator->() const;
            bool operator==(const iterator& it) const;
            bool operator!=(const iterator& it) const;
            iterator(NodePtr node);
            Node* Get() const;
        };
        iterator begin();
        iterator begin() const;
        iterator end();
        iterator end() const;

        NodePtr  Nil() const;
        UINT Count() const;
        iterator Find(const T& key) const;

    };
    _H3API_ASSERT_SIZE_(H3Set<h3unk>);
#pragma pack(pop) /* align-4 */

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::head() const
    {
        return m_root->parent;
    }

#ifndef _H3API_CPLUSPLUS11_
    template<typename T, UINT NilNode>
    inline typename _H3API_FORCEINLINE_ H3Set<T, NilNode>::Node** H3Set<T, NilNode>::_Nil()
    {
        return reinterpret_cast<Node**>(NilNode);
    }
#endif

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::NodePtr H3Set<T, NilNode>::Nil() const
    {
        return NodePtr(PtrAt(NilNode));
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::begin()
    {
        return iterator(m_root->left);
    }
    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::begin() const
    {
        return iterator(m_root->left);
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::end()
    {
        return iterator(m_root);
    }
    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::end() const
    {
        return iterator(m_root);
    }

    template<typename T, UINT NilNode>
    inline UINT H3Set<T, NilNode>::Count() const
    {
        return m_count;
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::Find(const T& key) const
    {
        NodePtr end_node = NodePtr(PtrAt(NilNode));
        NodePtr it = head();
        NodePtr result = m_root;
        while (it != end_node)
        {
            if (it->data < key)
                it = it->right;
            else
            {
                result = it;
                it = it->left;
            }
        }
        if (result == end_node)
            return end();
        if (key < result->data)
            return end();
        return iterator(result);
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::iterator::endNode() const
    {
        return NodePtr(PtrAt(NilNode));
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator& H3Set<T, NilNode>::iterator::operator++()
    {
        NodePtr end_node = endNode();
        NodePtr node = m_node->right;
        if (node != end_node)
        {
            while (node->left != end_node) // min
                node = node->left;
            m_node = node;
        }
        else
        {
            NodePtr parent = m_node->parent;
            while (parent->right == m_node)
            {
                m_node = parent;
                parent = m_node->parent;
            }
            if (m_node->right != parent)
                m_node = parent;
        }
        return *this;
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::iterator H3Set<T, NilNode>::iterator::operator++(int)
    {
        iterator it(m_node);
        ++(*this);
        return it;
    }

    template<typename T, UINT NilNode>
    inline T& H3Set<T, NilNode>::iterator::operator*() const
    {
        return m_node->data;
    }

    template<typename T, UINT NilNode>
    inline T* H3Set<T, NilNode>::iterator::operator->() const
    {
        return &m_node->data;
    }

    template<typename T, UINT NilNode>
    inline bool H3Set<T, NilNode>::iterator::operator==(const iterator& it) const
    {
        return m_node == it.m_node;
    }

    template<typename T, UINT NilNode>
    inline bool H3Set<T, NilNode>::iterator::operator!=(const iterator& it) const
    {
        return m_node != it.m_node;
    }

    template<typename T, UINT NilNode>
    inline H3Set<T, NilNode>::iterator::iterator(NodePtr node) :
        m_node(node)
    {
    }

    template<typename T, UINT NilNode>
    inline typename H3Set<T, NilNode>::Node* H3Set<T, NilNode>::iterator::Get() const
    {
        return m_node;
    }

}

namespace h3
{
	_H3API_DECLARE_(ARGB888);
	_H3API_DECLARE_(RGB888);
	struct H3RGB555;
	struct H3RGB565;
	_H3API_DECLARE_(HSV);

	typedef UINT16 RGB555;
	typedef UINT16 RGB565;

#pragma pack(push, 1)
	struct H3RGB888
	{
		_H3API_SIZE_(3);

		UINT8 r;
		UINT8 g;
		UINT8 b;

		_H3API_ VOID Darken20();
		_H3API_ VOID Darken50();
		_H3API_ VOID GrayScale();
		_H3API_ VOID Darken(const UINT8 amount);
		_H3API_ VOID Lighten(const UINT8 amount);
		_H3API_ VOID AlphaDraw(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha);
		_H3API_ static FLOAT GetHueAsNormalizedFloat(UINT8 red, UINT8 green, UINT8 blue);
		_H3API_ static DWORD Pack(UINT8 red, UINT8 green, UINT8 blue);
		_H3API_ H3RGB888();
		_H3API_ H3RGB888(DWORD color);
		_H3API_ H3RGB888(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB888(const H3RGB565& rgb);
		_H3API_ H3RGB888(const H3ARGB888& rgb);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB888& col);
	#pragma region NamedColors
		_H3API_ static H3RGB888 Regular();
		_H3API_ static H3RGB888 Highlight();
		_H3API_ static H3RGB888 H3Red();
		_H3API_ static H3RGB888 H3Cyan();
		_H3API_ static H3RGB888 H3Green();
		_H3API_ static H3RGB888 H3Blue();
		_H3API_ static H3RGB888 H3Yellow();
		_H3API_ static H3RGB888 H3Orange();
		_H3API_ static H3RGB888 H3Purple();
		_H3API_ static H3RGB888 H3Pink();
		_H3API_ static H3RGB888 AliceBlue();
		_H3API_ static H3RGB888 AntiqueWhite();
		_H3API_ static H3RGB888 Aqua();
		_H3API_ static H3RGB888 Aquamarine();
		_H3API_ static H3RGB888 Azure();
		_H3API_ static H3RGB888 Beige();
		_H3API_ static H3RGB888 Bisque();
		_H3API_ static H3RGB888 Black();
		_H3API_ static H3RGB888 BlanchedAlmond();
		_H3API_ static H3RGB888 Blue();
		_H3API_ static H3RGB888 BlueViolet();
		_H3API_ static H3RGB888 Brown();
		_H3API_ static H3RGB888 BurlyWood();
		_H3API_ static H3RGB888 CadetBlue();
		_H3API_ static H3RGB888 Chartreuse();
		_H3API_ static H3RGB888 Chocolate();
		_H3API_ static H3RGB888 Coral();
		_H3API_ static H3RGB888 CornflowerBlue();
		_H3API_ static H3RGB888 Cornsilk();
		_H3API_ static H3RGB888 Crimson();
		_H3API_ static H3RGB888 Cyan();
		_H3API_ static H3RGB888 DarkBlue();
		_H3API_ static H3RGB888 DarkCyan();
		_H3API_ static H3RGB888 DarkGoldenRod();
		_H3API_ static H3RGB888 DarkGray();
		_H3API_ static H3RGB888 DarkGrey();
		_H3API_ static H3RGB888 DarkGreen();
		_H3API_ static H3RGB888 DarkKhaki();
		_H3API_ static H3RGB888 DarkMagenta();
		_H3API_ static H3RGB888 DarkOliveGreen();
		_H3API_ static H3RGB888 Darkorange();
		_H3API_ static H3RGB888 DarkOrchid();
		_H3API_ static H3RGB888 DarkRed();
		_H3API_ static H3RGB888 DarkSalmon();
		_H3API_ static H3RGB888 DarkSeaGreen();
		_H3API_ static H3RGB888 DarkSlateBlue();
		_H3API_ static H3RGB888 DarkSlateGray();
		_H3API_ static H3RGB888 DarkSlateGrey();
		_H3API_ static H3RGB888 DarkTurquoise();
		_H3API_ static H3RGB888 DarkViolet();
		_H3API_ static H3RGB888 DeepPink();
		_H3API_ static H3RGB888 DeepSkyBlue();
		_H3API_ static H3RGB888 DimGray();
		_H3API_ static H3RGB888 DimGrey();
		_H3API_ static H3RGB888 DodgerBlue();
		_H3API_ static H3RGB888 FireBrick();
		_H3API_ static H3RGB888 FloralWhite();
		_H3API_ static H3RGB888 ForestGreen();
		_H3API_ static H3RGB888 Fuchsia();
		_H3API_ static H3RGB888 Gainsboro();
		_H3API_ static H3RGB888 GhostWhite();
		_H3API_ static H3RGB888 Gold();
		_H3API_ static H3RGB888 GoldenRod();
		_H3API_ static H3RGB888 Gray();
		_H3API_ static H3RGB888 Grey();
		_H3API_ static H3RGB888 Green();
		_H3API_ static H3RGB888 GreenYellow();
		_H3API_ static H3RGB888 HoneyDew();
		_H3API_ static H3RGB888 HotPink();
		_H3API_ static H3RGB888 IndianRed();
		_H3API_ static H3RGB888 Indigo();
		_H3API_ static H3RGB888 Ivory();
		_H3API_ static H3RGB888 Khaki();
		_H3API_ static H3RGB888 Lavender();
		_H3API_ static H3RGB888 LavenderBlush();
		_H3API_ static H3RGB888 LawnGreen();
		_H3API_ static H3RGB888 LemonChiffon();
		_H3API_ static H3RGB888 LightBlue();
		_H3API_ static H3RGB888 LightCoral();
		_H3API_ static H3RGB888 LightCyan();
		_H3API_ static H3RGB888 LightGoldenRodYellow();
		_H3API_ static H3RGB888 LightGray();
		_H3API_ static H3RGB888 LightGrey();
		_H3API_ static H3RGB888 LightGreen();
		_H3API_ static H3RGB888 LightPink();
		_H3API_ static H3RGB888 LightSalmon();
		_H3API_ static H3RGB888 LightSeaGreen();
		_H3API_ static H3RGB888 LightSkyBlue();
		_H3API_ static H3RGB888 LightSlateGray();
		_H3API_ static H3RGB888 LightSlateGrey();
		_H3API_ static H3RGB888 LightSteelBlue();
		_H3API_ static H3RGB888 LightYellow();
		_H3API_ static H3RGB888 Lime();
		_H3API_ static H3RGB888 LimeGreen();
		_H3API_ static H3RGB888 Linen();
		_H3API_ static H3RGB888 Magenta();
		_H3API_ static H3RGB888 Maroon();
		_H3API_ static H3RGB888 MediumAquaMarine();
		_H3API_ static H3RGB888 MediumBlue();
		_H3API_ static H3RGB888 MediumOrchid();
		_H3API_ static H3RGB888 MediumPurple();
		_H3API_ static H3RGB888 MediumSeaGreen();
		_H3API_ static H3RGB888 MediumSlateBlue();
		_H3API_ static H3RGB888 MediumSpringGreen();
		_H3API_ static H3RGB888 MediumTurquoise();
		_H3API_ static H3RGB888 MediumVioletRed();
		_H3API_ static H3RGB888 MidnightBlue();
		_H3API_ static H3RGB888 MintCream();
		_H3API_ static H3RGB888 MistyRose();
		_H3API_ static H3RGB888 Moccasin();
		_H3API_ static H3RGB888 NavajoWhite();
		_H3API_ static H3RGB888 Navy();
		_H3API_ static H3RGB888 OldLace();
		_H3API_ static H3RGB888 Olive();
		_H3API_ static H3RGB888 OliveDrab();
		_H3API_ static H3RGB888 Orange();
		_H3API_ static H3RGB888 OrangeRed();
		_H3API_ static H3RGB888 Orchid();
		_H3API_ static H3RGB888 PaleGoldenRod();
		_H3API_ static H3RGB888 PaleGreen();
		_H3API_ static H3RGB888 PaleTurquoise();
		_H3API_ static H3RGB888 PaleVioletRed();
		_H3API_ static H3RGB888 PapayaWhip();
		_H3API_ static H3RGB888 PeachPuff();
		_H3API_ static H3RGB888 Peru();
		_H3API_ static H3RGB888 Pink();
		_H3API_ static H3RGB888 Plum();
		_H3API_ static H3RGB888 PowderBlue();
		_H3API_ static H3RGB888 Purple();
		_H3API_ static H3RGB888 Red();
		_H3API_ static H3RGB888 RosyBrown();
		_H3API_ static H3RGB888 RoyalBlue();
		_H3API_ static H3RGB888 SaddleBrown();
		_H3API_ static H3RGB888 Salmon();
		_H3API_ static H3RGB888 SandyBrown();
		_H3API_ static H3RGB888 SeaGreen();
		_H3API_ static H3RGB888 SeaShell();
		_H3API_ static H3RGB888 Sienna();
		_H3API_ static H3RGB888 Silver();
		_H3API_ static H3RGB888 SkyBlue();
		_H3API_ static H3RGB888 SlateBlue();
		_H3API_ static H3RGB888 SlateGray();
		_H3API_ static H3RGB888 SlateGrey();
		_H3API_ static H3RGB888 Snow();
		_H3API_ static H3RGB888 SpringGreen();
		_H3API_ static H3RGB888 SteelBlue();
		_H3API_ static H3RGB888 Tan();
		_H3API_ static H3RGB888 Teal();
		_H3API_ static H3RGB888 Thistle();
		_H3API_ static H3RGB888 Tomato();
		_H3API_ static H3RGB888 Turquoise();
		_H3API_ static H3RGB888 Violet();
		_H3API_ static H3RGB888 Wheat();
		_H3API_ static H3RGB888 White();
		_H3API_ static H3RGB888 WhiteSmoke();
		_H3API_ static H3RGB888 Yellow();
		_H3API_ static H3RGB888 YellowGreen();
	#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB888);
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)
	struct H3ARGB888
	{
		_H3API_SIZE_(4);

		UINT8 b;
		UINT8 g;
		UINT8 r;
		UINT8 a;

		_H3API_ UINT Value() const;
		_H3API_ UINT operator*() const;
		_H3API_ operator DWORD () const;
		_H3API_ VOID Darken(const UINT8 amount);
		_H3API_ VOID Lighten(const UINT8 amount);
		_H3API_ VOID GrayScale();
		_H3API_ VOID Legacy();
		_H3API_ H3ARGB888();
		_H3API_ H3ARGB888(DWORD col);
		_H3API_ H3ARGB888(const H3RGB565& col);
		_H3API_ H3ARGB888(const H3RGB888& col);
		_H3API_ H3ARGB888(const H3ARGB888& col);
		_H3API_ H3ARGB888(UINT8 red, UINT8 blue, UINT8 green);
		_H3API_ DWORD GetColor() const;
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(UINT16 col);
		_H3API_ VOID operator=(UINT32 col);
		_H3API_ BOOL operator==(const H3ARGB888& col);
		_H3API_ VOID LightShadow();
		_H3API_ VOID DarkShadow();
		_H3API_ VOID Blend(const H3ARGB888& col);
	#pragma region NamedColors
		_H3API_ static H3ARGB888 Regular();
		_H3API_ static H3ARGB888 Highlight();
		_H3API_ static H3ARGB888 H3Red();
		_H3API_ static H3ARGB888 H3Cyan();
		_H3API_ static H3ARGB888 H3Green();
		_H3API_ static H3ARGB888 H3Blue();
		_H3API_ static H3ARGB888 H3Yellow();
		_H3API_ static H3ARGB888 H3Orange();
		_H3API_ static H3ARGB888 H3Purple();
		_H3API_ static H3ARGB888 H3Pink();
		_H3API_ static H3ARGB888 AliceBlue();
		_H3API_ static H3ARGB888 AntiqueWhite();
		_H3API_ static H3ARGB888 Aqua();
		_H3API_ static H3ARGB888 Aquamarine();
		_H3API_ static H3ARGB888 Azure();
		_H3API_ static H3ARGB888 Beige();
		_H3API_ static H3ARGB888 Bisque();
		_H3API_ static H3ARGB888 Black();
		_H3API_ static H3ARGB888 BlanchedAlmond();
		_H3API_ static H3ARGB888 Blue();
		_H3API_ static H3ARGB888 BlueViolet();
		_H3API_ static H3ARGB888 Brown();
		_H3API_ static H3ARGB888 BurlyWood();
		_H3API_ static H3ARGB888 CadetBlue();
		_H3API_ static H3ARGB888 Chartreuse();
		_H3API_ static H3ARGB888 Chocolate();
		_H3API_ static H3ARGB888 Coral();
		_H3API_ static H3ARGB888 CornflowerBlue();
		_H3API_ static H3ARGB888 Cornsilk();
		_H3API_ static H3ARGB888 Crimson();
		_H3API_ static H3ARGB888 Cyan();
		_H3API_ static H3ARGB888 DarkBlue();
		_H3API_ static H3ARGB888 DarkCyan();
		_H3API_ static H3ARGB888 DarkGoldenRod();
		_H3API_ static H3ARGB888 DarkGray();
		_H3API_ static H3ARGB888 DarkGrey();
		_H3API_ static H3ARGB888 DarkGreen();
		_H3API_ static H3ARGB888 DarkKhaki();
		_H3API_ static H3ARGB888 DarkMagenta();
		_H3API_ static H3ARGB888 DarkOliveGreen();
		_H3API_ static H3ARGB888 Darkorange();
		_H3API_ static H3ARGB888 DarkOrchid();
		_H3API_ static H3ARGB888 DarkRed();
		_H3API_ static H3ARGB888 DarkSalmon();
		_H3API_ static H3ARGB888 DarkSeaGreen();
		_H3API_ static H3ARGB888 DarkSlateBlue();
		_H3API_ static H3ARGB888 DarkSlateGray();
		_H3API_ static H3ARGB888 DarkSlateGrey();
		_H3API_ static H3ARGB888 DarkTurquoise();
		_H3API_ static H3ARGB888 DarkViolet();
		_H3API_ static H3ARGB888 DeepPink();
		_H3API_ static H3ARGB888 DeepSkyBlue();
		_H3API_ static H3ARGB888 DimGray();
		_H3API_ static H3ARGB888 DimGrey();
		_H3API_ static H3ARGB888 DodgerBlue();
		_H3API_ static H3ARGB888 FireBrick();
		_H3API_ static H3ARGB888 FloralWhite();
		_H3API_ static H3ARGB888 ForestGreen();
		_H3API_ static H3ARGB888 Fuchsia();
		_H3API_ static H3ARGB888 Gainsboro();
		_H3API_ static H3ARGB888 GhostWhite();
		_H3API_ static H3ARGB888 Gold();
		_H3API_ static H3ARGB888 GoldenRod();
		_H3API_ static H3ARGB888 Gray();
		_H3API_ static H3ARGB888 Grey();
		_H3API_ static H3ARGB888 Green();
		_H3API_ static H3ARGB888 GreenYellow();
		_H3API_ static H3ARGB888 HoneyDew();
		_H3API_ static H3ARGB888 HotPink();
		_H3API_ static H3ARGB888 IndianRed();
		_H3API_ static H3ARGB888 Indigo();
		_H3API_ static H3ARGB888 Ivory();
		_H3API_ static H3ARGB888 Khaki();
		_H3API_ static H3ARGB888 Lavender();
		_H3API_ static H3ARGB888 LavenderBlush();
		_H3API_ static H3ARGB888 LawnGreen();
		_H3API_ static H3ARGB888 LemonChiffon();
		_H3API_ static H3ARGB888 LightBlue();
		_H3API_ static H3ARGB888 LightCoral();
		_H3API_ static H3ARGB888 LightCyan();
		_H3API_ static H3ARGB888 LightGoldenRodYellow();
		_H3API_ static H3ARGB888 LightGray();
		_H3API_ static H3ARGB888 LightGrey();
		_H3API_ static H3ARGB888 LightGreen();
		_H3API_ static H3ARGB888 LightPink();
		_H3API_ static H3ARGB888 LightSalmon();
		_H3API_ static H3ARGB888 LightSeaGreen();
		_H3API_ static H3ARGB888 LightSkyBlue();
		_H3API_ static H3ARGB888 LightSlateGray();
		_H3API_ static H3ARGB888 LightSlateGrey();
		_H3API_ static H3ARGB888 LightSteelBlue();
		_H3API_ static H3ARGB888 LightYellow();
		_H3API_ static H3ARGB888 Lime();
		_H3API_ static H3ARGB888 LimeGreen();
		_H3API_ static H3ARGB888 Linen();
		_H3API_ static H3ARGB888 Magenta();
		_H3API_ static H3ARGB888 Maroon();
		_H3API_ static H3ARGB888 MediumAquaMarine();
		_H3API_ static H3ARGB888 MediumBlue();
		_H3API_ static H3ARGB888 MediumOrchid();
		_H3API_ static H3ARGB888 MediumPurple();
		_H3API_ static H3ARGB888 MediumSeaGreen();
		_H3API_ static H3ARGB888 MediumSlateBlue();
		_H3API_ static H3ARGB888 MediumSpringGreen();
		_H3API_ static H3ARGB888 MediumTurquoise();
		_H3API_ static H3ARGB888 MediumVioletRed();
		_H3API_ static H3ARGB888 MidnightBlue();
		_H3API_ static H3ARGB888 MintCream();
		_H3API_ static H3ARGB888 MistyRose();
		_H3API_ static H3ARGB888 Moccasin();
		_H3API_ static H3ARGB888 NavajoWhite();
		_H3API_ static H3ARGB888 Navy();
		_H3API_ static H3ARGB888 OldLace();
		_H3API_ static H3ARGB888 Olive();
		_H3API_ static H3ARGB888 OliveDrab();
		_H3API_ static H3ARGB888 Orange();
		_H3API_ static H3ARGB888 OrangeRed();
		_H3API_ static H3ARGB888 Orchid();
		_H3API_ static H3ARGB888 PaleGoldenRod();
		_H3API_ static H3ARGB888 PaleGreen();
		_H3API_ static H3ARGB888 PaleTurquoise();
		_H3API_ static H3ARGB888 PaleVioletRed();
		_H3API_ static H3ARGB888 PapayaWhip();
		_H3API_ static H3ARGB888 PeachPuff();
		_H3API_ static H3ARGB888 Peru();
		_H3API_ static H3ARGB888 Pink();
		_H3API_ static H3ARGB888 Plum();
		_H3API_ static H3ARGB888 PowderBlue();
		_H3API_ static H3ARGB888 Purple();
		_H3API_ static H3ARGB888 Red();
		_H3API_ static H3ARGB888 RosyBrown();
		_H3API_ static H3ARGB888 RoyalBlue();
		_H3API_ static H3ARGB888 SaddleBrown();
		_H3API_ static H3ARGB888 Salmon();
		_H3API_ static H3ARGB888 SandyBrown();
		_H3API_ static H3ARGB888 SeaGreen();
		_H3API_ static H3ARGB888 SeaShell();
		_H3API_ static H3ARGB888 Sienna();
		_H3API_ static H3ARGB888 Silver();
		_H3API_ static H3ARGB888 SkyBlue();
		_H3API_ static H3ARGB888 SlateBlue();
		_H3API_ static H3ARGB888 SlateGray();
		_H3API_ static H3ARGB888 SlateGrey();
		_H3API_ static H3ARGB888 Snow();
		_H3API_ static H3ARGB888 SpringGreen();
		_H3API_ static H3ARGB888 SteelBlue();
		_H3API_ static H3ARGB888 Tan();
		_H3API_ static H3ARGB888 Teal();
		_H3API_ static H3ARGB888 Thistle();
		_H3API_ static H3ARGB888 Tomato();
		_H3API_ static H3ARGB888 Turquoise();
		_H3API_ static H3ARGB888 Violet();
		_H3API_ static H3ARGB888 Wheat();
		_H3API_ static H3ARGB888 White();
		_H3API_ static H3ARGB888 WhiteSmoke();
		_H3API_ static H3ARGB888 Yellow();
		_H3API_ static H3ARGB888 YellowGreen();
	#pragma endregion
	protected:
		_H3API_ PDWORD AsDword();
		_H3API_ PDWORD AsDword() const;
	};
	_H3API_ASSERT_SIZE_(H3ARGB888);

	struct H3RGB555
	{
		_H3API_SIZE_(2);
	protected:
		RGB555 bits;
	public:
		_H3API_ UINT8 GetRed();
		_H3API_ UINT8 GetGreen();
		_H3API_ UINT8 GetBlue();
		_H3API_ DWORD UnPack();
		_H3API_ VOID SetBits(WORD color);
		_H3API_ static WORD Pack(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ static DWORD Unpack(RGB555 rgb);
		_H3API_ VOID PackRGB(UINT8 r, UINT8 g, UINT8 b);
	};
	_H3API_ASSERT_SIZE_(H3RGB555);

	struct H3RGB565
	{
		_H3API_SIZE_(2);
		_H3API_ static H3RGB565 mask25();
		_H3API_ static H3RGB565 mask50();

protected:
		RGB565 bits;
public:
		_H3API_ UINT8 GetRed() const;
		_H3API_ UINT8 GetRed8() const;
		_H3API_ UINT8 GetGreen() const;
		_H3API_ UINT8 GetGreen8() const;
		_H3API_ UINT8 GetBlue() const;
		_H3API_ UINT8 GetBlue8() const;
		_H3API_ DWORD GetRGB888() const;
		_H3API_ RGB565 GetBits() const;
		_H3API_ H3RGB565();
		_H3API_ H3RGB565(RGB565 rgb);
		_H3API_ H3RGB565(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB565(DWORD color);
		_H3API_ H3RGB565(const H3RGB888& color);
		_H3API_ H3RGB565(const H3ARGB888& color);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB565& col);
		_H3API_ operator WORD () const;
		_H3API_ WORD Value() const;
		_H3API_ VOID SetBits(WORD color);
		_H3API_ VOID PackRGB565(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ VOID Pack(H3RGB888& rgb);
		_H3API_ static WORD  Pack(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ static DWORD Unpack(RGB565 rgb);
		_H3API_ VOID Darken(UINT8 amount);
		_H3API_ VOID Lighten(UINT8 amount);
		_H3API_ VOID GrayScale();
		_H3API_ VOID LightShadow();
		_H3API_ VOID LightShadow(RGB565 mask50, RGB565 mask25);
		_H3API_ VOID DarkShadow();
		_H3API_ VOID DarkShadow(RGB565 mask);
		_H3API_ VOID Blend(const H3RGB565& col);
		_H3API_ VOID Blend(const H3RGB565& col, RGB565 mask);
#pragma region NamedColors
		_H3API_ static RGB565 Regular();
		_H3API_ static RGB565 Highlight();
		_H3API_ static RGB565 H3Red();
		_H3API_ static RGB565 H3Cyan();
		_H3API_ static RGB565 H3Green();
		_H3API_ static RGB565 H3Blue();
		_H3API_ static RGB565 H3Yellow();
		_H3API_ static RGB565 H3Orange();
		_H3API_ static RGB565 H3Purple();
		_H3API_ static RGB565 H3Pink();
		_H3API_ static RGB565 AliceBlue();
		_H3API_ static RGB565 AntiqueWhite();
		_H3API_ static RGB565 Aqua();
		_H3API_ static RGB565 Aquamarine();
		_H3API_ static RGB565 Azure();
		_H3API_ static RGB565 Beige();
		_H3API_ static RGB565 Bisque();
		_H3API_ static RGB565 Black();
		_H3API_ static RGB565 BlanchedAlmond();
		_H3API_ static RGB565 Blue();
		_H3API_ static RGB565 BlueViolet();
		_H3API_ static RGB565 Brown();
		_H3API_ static RGB565 BurlyWood();
		_H3API_ static RGB565 CadetBlue();
		_H3API_ static RGB565 Chartreuse();
		_H3API_ static RGB565 Chocolate();
		_H3API_ static RGB565 Coral();
		_H3API_ static RGB565 CornflowerBlue();
		_H3API_ static RGB565 Cornsilk();
		_H3API_ static RGB565 Crimson();
		_H3API_ static RGB565 Cyan();
		_H3API_ static RGB565 DarkBlue();
		_H3API_ static RGB565 DarkCyan();
		_H3API_ static RGB565 DarkGoldenRod();
		_H3API_ static RGB565 DarkGray();
		_H3API_ static RGB565 DarkGrey();
		_H3API_ static RGB565 DarkGreen();
		_H3API_ static RGB565 DarkKhaki();
		_H3API_ static RGB565 DarkMagenta();
		_H3API_ static RGB565 DarkOliveGreen();
		_H3API_ static RGB565 Darkorange();
		_H3API_ static RGB565 DarkOrchid();
		_H3API_ static RGB565 DarkRed();
		_H3API_ static RGB565 DarkSalmon();
		_H3API_ static RGB565 DarkSeaGreen();
		_H3API_ static RGB565 DarkSlateBlue();
		_H3API_ static RGB565 DarkSlateGray();
		_H3API_ static RGB565 DarkSlateGrey();
		_H3API_ static RGB565 DarkTurquoise();
		_H3API_ static RGB565 DarkViolet();
		_H3API_ static RGB565 DeepPink();
		_H3API_ static RGB565 DeepSkyBlue();
		_H3API_ static RGB565 DimGray();
		_H3API_ static RGB565 DimGrey();
		_H3API_ static RGB565 DodgerBlue();
		_H3API_ static RGB565 FireBrick();
		_H3API_ static RGB565 FloralWhite();
		_H3API_ static RGB565 ForestGreen();
		_H3API_ static RGB565 Fuchsia();
		_H3API_ static RGB565 Gainsboro();
		_H3API_ static RGB565 GhostWhite();
		_H3API_ static RGB565 Gold();
		_H3API_ static RGB565 GoldenRod();
		_H3API_ static RGB565 Gray();
		_H3API_ static RGB565 Grey();
		_H3API_ static RGB565 Green();
		_H3API_ static RGB565 GreenYellow();
		_H3API_ static RGB565 HoneyDew();
		_H3API_ static RGB565 HotPink();
		_H3API_ static RGB565 IndianRed();
		_H3API_ static RGB565 Indigo();
		_H3API_ static RGB565 Ivory();
		_H3API_ static RGB565 Khaki();
		_H3API_ static RGB565 Lavender();
		_H3API_ static RGB565 LavenderBlush();
		_H3API_ static RGB565 LawnGreen();
		_H3API_ static RGB565 LemonChiffon();
		_H3API_ static RGB565 LightBlue();
		_H3API_ static RGB565 LightCoral();
		_H3API_ static RGB565 LightCyan();
		_H3API_ static RGB565 LightGoldenRodYellow();
		_H3API_ static RGB565 LightGray();
		_H3API_ static RGB565 LightGrey();
		_H3API_ static RGB565 LightGreen();
		_H3API_ static RGB565 LightPink();
		_H3API_ static RGB565 LightSalmon();
		_H3API_ static RGB565 LightSeaGreen();
		_H3API_ static RGB565 LightSkyBlue();
		_H3API_ static RGB565 LightSlateGray();
		_H3API_ static RGB565 LightSlateGrey();
		_H3API_ static RGB565 LightSteelBlue();
		_H3API_ static RGB565 LightYellow();
		_H3API_ static RGB565 Lime();
		_H3API_ static RGB565 LimeGreen();
		_H3API_ static RGB565 Linen();
		_H3API_ static RGB565 Magenta();
		_H3API_ static RGB565 Maroon();
		_H3API_ static RGB565 MediumAquaMarine();
		_H3API_ static RGB565 MediumBlue();
		_H3API_ static RGB565 MediumOrchid();
		_H3API_ static RGB565 MediumPurple();
		_H3API_ static RGB565 MediumSeaGreen();
		_H3API_ static RGB565 MediumSlateBlue();
		_H3API_ static RGB565 MediumSpringGreen();
		_H3API_ static RGB565 MediumTurquoise();
		_H3API_ static RGB565 MediumVioletRed();
		_H3API_ static RGB565 MidnightBlue();
		_H3API_ static RGB565 MintCream();
		_H3API_ static RGB565 MistyRose();
		_H3API_ static RGB565 Moccasin();
		_H3API_ static RGB565 NavajoWhite();
		_H3API_ static RGB565 Navy();
		_H3API_ static RGB565 OldLace();
		_H3API_ static RGB565 Olive();
		_H3API_ static RGB565 OliveDrab();
		_H3API_ static RGB565 Orange();
		_H3API_ static RGB565 OrangeRed();
		_H3API_ static RGB565 Orchid();
		_H3API_ static RGB565 PaleGoldenRod();
		_H3API_ static RGB565 PaleGreen();
		_H3API_ static RGB565 PaleTurquoise();
		_H3API_ static RGB565 PaleVioletRed();
		_H3API_ static RGB565 PapayaWhip();
		_H3API_ static RGB565 PeachPuff();
		_H3API_ static RGB565 Peru();
		_H3API_ static RGB565 Pink();
		_H3API_ static RGB565 Plum();
		_H3API_ static RGB565 PowderBlue();
		_H3API_ static RGB565 Purple();
		_H3API_ static RGB565 Red();
		_H3API_ static RGB565 RosyBrown();
		_H3API_ static RGB565 RoyalBlue();
		_H3API_ static RGB565 SaddleBrown();
		_H3API_ static RGB565 Salmon();
		_H3API_ static RGB565 SandyBrown();
		_H3API_ static RGB565 SeaGreen();
		_H3API_ static RGB565 SeaShell();
		_H3API_ static RGB565 Sienna();
		_H3API_ static RGB565 Silver();
		_H3API_ static RGB565 SkyBlue();
		_H3API_ static RGB565 SlateBlue();
		_H3API_ static RGB565 SlateGray();
		_H3API_ static RGB565 SlateGrey();
		_H3API_ static RGB565 Snow();
		_H3API_ static RGB565 SpringGreen();
		_H3API_ static RGB565 SteelBlue();
		_H3API_ static RGB565 Tan();
		_H3API_ static RGB565 Teal();
		_H3API_ static RGB565 Thistle();
		_H3API_ static RGB565 Tomato();
		_H3API_ static RGB565 Turquoise();
		_H3API_ static RGB565 Violet();
		_H3API_ static RGB565 Wheat();
		_H3API_ static RGB565 White();
		_H3API_ static RGB565 WhiteSmoke();
		_H3API_ static RGB565 Yellow();
		_H3API_ static RGB565 YellowGreen();
#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB565);

	struct H3HSV
	{
	protected:
		UINT8 h;
		UINT8 s;
		UINT8 v;
	public:
		_H3API_ H3HSV();
		_H3API_ H3HSV(H3HSV& other);
		_H3API_ H3HSV(const H3RGB888& rgb);
		_H3API_ H3HSV& ConvertFromRgb888(const H3RGB888& rgb);
		_H3API_ H3RGB888 ConvertToRgb888() const;
		_H3API_ VOID AddSaturation(UINT8 saturation);
		_H3API_ VOID RemoveSaturation(UINT8 saturation);
		_H3API_ VOID SetHue(UINT8 hue);
		_H3API_ VOID AddValue(UINT8 value);
		_H3API_ VOID RemoveValue(UINT8 value);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ResourceItem);
	_H3API_DECLARE_(BasePalette565);
	_H3API_DECLARE_(BasePalette888);
	struct H3ResourceManager;
	struct H3ResourceManagerNode;
	struct H3WavFile;
	struct H3TextFile;
	struct H3TextTable;
	struct H3Palette565;
	struct H3Palette888;
	struct H3Palette32;
	struct H3Font;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3LoadedPcx24;
	struct H3DefFrame;
	struct H3LoadedDef;

	template <typename T> class H3BinaryLoader;

	struct _H3API_DEPRECATED_("Use H3LoadedDef::DefGroup") H3DefGroup;

	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3Font>,        FontLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedDef>,   DefLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3Palette565>,  PaletteLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedPcx>,   PcxLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedPcx16>, Pcx16Loader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3TextFile>,    TextFileLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3TextTable>,   TextTableLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3WavFile>,     WavLoader);

#pragma pack(push, 4)
	struct H3ResourceItem : H3Allocator
	{
		_H3API_SIZE_(0x1C);
		_H3API_CTOR_DTOR_(0x558970, -1);

		friend H3ResourceManager;
	protected:
		struct ResourceItemVTable
		{
			typedef H3ResourceItem* (__thiscall* VDestroy)(H3ResourceItem*, BOOL8);
			typedef VOID(__thiscall* VDeref)(H3ResourceItem*);
			typedef UINT(__thiscall* VGetSize)(H3ResourceItem*);

			VDestroy vdestroy; // 0x5589C0, called by dereference
			VDeref   vEraseFromResourceManager; // 0x55D300
			VGetSize vGetSize;
		}*vTable;
		CHAR name[12];
		UINT nameEnd; // always 0
		INT32 type; // arg3 from constructor
		INT32 ref; // the number of times it is being used
	public:
		_H3API_ H3ResourceItem* InitiateResource(LPCSTR name, INT type);
		_H3API_ VOID Dereference();
		_H3API_ VOID AddToResourceManager();
		_H3API_ VOID IncreaseReferences();
		_H3API_ INT32 References() const;
		_H3API_ LPCSTR GetName() const;
		_H3API_ ~H3ResourceItem();
	};
	_H3API_ASSERT_SIZE_(H3ResourceItem);

	struct H3BasePalette565
	{
		_H3API_SIZE_(0x21C);
	protected:
		h3align _f_00[28];

		_H3API_ H3Palette565* cast();
	public:
		union
		{
#ifdef _H3API_CPLUSPLUS11_
			H3RGB565 color[256];
#else // older VS have issues with unions and non-default constructors
			RGB565 color[256];
#endif
			struct
			{
				H3RGB565 unusedColors[254];
				H3Palette32* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(H3Palette565& source);
		_H3API_ VOID CopyPalette(H3BasePalette565& source);

		_H3API_ VOID InitiateFromPalette888(const H3BasePalette888& palette);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;
		_H3API_ H3BasePalette565();
		_H3API_ H3BasePalette565(const H3Palette888& palette);
		_H3API_ H3BasePalette565(const H3BasePalette888& palette);
		_H3API_ ~H3BasePalette565();

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette565(H3BasePalette565&& other);
		_H3API_ H3BasePalette565& operator=(H3BasePalette565&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette565);
	struct H3BasePalette888
	{
		_H3API_SIZE_(0x31C);
	protected:
		h3align _f_00[28];
	public:
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ ~H3BasePalette888();
		_H3API_ H3BasePalette888();
		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette888(H3BasePalette888&& other);
		_H3API_ H3BasePalette888& operator=(H3BasePalette888&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette888);

	template <typename T>
	class H3BinaryLoader
	{
	protected:
		T* m_binary;
	public:
		H3BinaryLoader();
		H3BinaryLoader(LPCSTR file_name);
		H3BinaryLoader(const H3String& file_name);
		H3BinaryLoader(T* binary_item);
		~H3BinaryLoader();
		void Set(T* binary);
		T* Get();
		T* Release();
		T* operator->();
		T* operator*();
		BOOL operator!();
		operator BOOL();
	};

#pragma pack(pop) /* align-4 */

	template<typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader() :
		m_binary()
	{
	}
	template <typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(LPCSTR file_name) :
		m_binary(T::Load(file_name))
	{
	}
	template <typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(const H3String& file_name) :
		m_binary(T::Load(file_name))
	{
	}
	template<typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(T* binary_item) :
		m_binary(binary_item)
	{
	}
	template<typename T>
	inline H3BinaryLoader<T>::~H3BinaryLoader()
	{
		if (m_binary)
			m_binary->Dereference();
	}
	template<typename T>
	inline void H3BinaryLoader<T>::Set(T* binary)
	{
		m_binary = binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::Get()
	{
		return m_binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::Release()
	{
		T* b = m_binary;
		m_binary = nullptr;
		return b;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::operator->()
	{
		return m_binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::operator*()
	{
		return m_binary;
	}
	template<typename T>
	inline BOOL H3BinaryLoader<T>::operator!()
	{
		return m_binary == nullptr;
	}
	template<typename T>
	inline H3BinaryLoader<T>::operator BOOL()
	{
		return m_binary != nullptr;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DefFrame);
	_H3API_TYPE_DECLARE_(H3DefFrame, SpriteFrame);

#pragma pack(push, 4)

	struct H3DefFrame : public H3ResourceItem
	{
		_H3API_SIZE_(0x48);

		INT32 rawDataSize;
		INT32 dataSize;
		INT32 compressionType;
		INT32 width;
		INT32 height;
		INT32 frameWidth;
		INT32 frameHeight;
		INT32 marginLeft;
		INT32 marginTop;
		INT32 width2;
		PUINT8 rawData;

		_H3API_ VOID DrawToPcx16(INT src_x, INT src_y, INT src_width, INT src_height,
			H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, H3Palette565* palette565,
			BOOL mirror = FALSE, BOOL no_special_colors = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3DefFrame);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Font);
	template<typename _Elem> struct H3Vector;
	struct H3String;

#pragma pack(push, 4)
	struct H3Font : public H3ResourceItem
	{
		_H3API_SIZE_(0x1260);
	protected:
		h3unk _f_1C[5];
	public:
		INT8 height;
	protected:
		h3unk _f_22[26];
	public:
		struct FontSpacing
		{
			INT32 leftMargin;
			INT32 span;
			INT32 rightMargin;
		}width[256];
		UINT32 bufferOffsets[256];
		H3BasePalette565 palette;
		PUINT8 bitmapBuffer;
		INT32 bufferSize;

		_H3API_ INT32 GetLinesCountInText(LPCSTR str, INT32 width);
		_H3API_ INT32 GetMaxLineWidth(LPCSTR str);
		_H3API_ INT32 GetMaxWordWidth(LPCSTR str);
		_H3API_ VOID  SplitTextIntoLines(LPCSTR text, INT32 textWidth, H3Vector<H3String>& stringVector);

		_H3API_ VOID TextDraw(H3LoadedPcx16* pcx, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			eTextColor colorIndex = eTextColor::REGULAR,
			eTextAlignment alignment = eTextAlignment::MIDDLE_CENTER);

		_H3API_ static H3Font* Load(LPCSTR name);

		_H3API_ PUINT8 GetChar(UINT32 character_id);
	};
	_H3API_ASSERT_SIZE_(H3Font);

	struct H3TinyFont : H3Font
	{
		_H3API_GET_INFO_(0x698A54, H3TinyFont);
	};
	struct H3SmallFont : H3Font
	{
		_H3API_GET_INFO_(0x698A58, H3SmallFont);
	};
	struct H3MediumFont : H3Font
	{
		_H3API_GET_INFO_(0x698A5C, H3MediumFont);
	};
	struct H3BigFont : H3Font
	{
		_H3API_GET_INFO_(0x698A60, H3BigFont);
	};
	struct H3CalliFont : H3Font
	{
		_H3API_GET_INFO_(0x698A64, H3CalliFont);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(LoadedDef);
	_H3API_TYPE_DECLARE_(H3LoadedDef, Sprite);

#pragma pack(push, 4)
	struct H3LoadedDef : public H3ResourceItem
	{
		_H3API_SIZE_(0x38);

		struct DefGroup
		{
			_H3API_SIZE_(0x0C);
			INT32 count;
			UINT32 spritesSize;
			H3DefFrame** frames;

			_H3API_ H3DefFrame& operator[](UINT index);
		};

		DefGroup**    groups;
		H3Palette565* palette565;
		H3Palette888* palette888;
		INT32 groupsCount;
		INT32* activeGroups;
		INT32 widthDEF;
		INT32 heightDEF;

		_H3API_ VOID AddFrameFromDef(LPCSTR source, INT32 index);
		_H3API_ VOID ColorToPlayer(INT32 id);
		_H3API_ H3DefFrame* GetGroupFrame(INT group, INT frame);
		_H3API_ VOID DrawTransparent(INT32 frame, H3LoadedPcx16* pcx, INT32 x, INT32 y, BOOL transparent = TRUE,
			BOOL mirror = FALSE, INT32 group = 0, INT32 xFromRight = 0, INT32 yFromBottom = 0);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, INT src_x, INT src_y, INT src_width, INT src_height,
			H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL mirror = FALSE, BOOL do_not_use_special_colors = TRUE);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y);

		_H3API_ VOID AddDefGroup(UINT group_id, UINT frames_in_group);
		_H3API_ VOID AddFrameToGroup(UINT group_id, H3DefFrame* frame);
		_H3API_ VOID Init(LPCSTR name, UINT type, UINT width, UINT height);

		_H3API_ DefGroup& operator[](UINT index);

		_H3API_ static H3LoadedDef* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3LoadedDef);
	_H3API_ASSERT_SIZE_(H3LoadedDef::DefGroup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(LoadedPcx);
	_H3API_TYPE_DECLARE_(H3LoadedPcx, Bitmap8);

#pragma pack(push, 4)

	struct H3LoadedPcx : public H3ResourceItem
	{
		_H3API_SIZE_(0x56C);
		_H3API_VTABLE_(0x63BA14);

		INT32 bufSize;
		INT32 bufSizeUnk;
		INT32 width;
		INT32 height;
		INT32 scanlineSize;
		PUINT8 buffer;
		H3BasePalette565 palette565;
		H3BasePalette888 palette888;

		_H3API_ VOID DrawToPcx16(int srcX, int srcY, int dx, int dy, H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx16(H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx(int src_x, int src_y, int dx, int dy, H3LoadedPcx* pcx_dest, int dest_x = 0, int dest_y = 0, BOOL copy_palette = TRUE);
		_H3API_ PUINT8 GetRow(int row) const;
		_H3API_ PUINT8 GetPixelIndex(int x, int y) const;
		_H3API_ VOID FillRectangle(INT x, INT y, INT dx, INT dy, BYTE color_index);

		_H3API_ H3LoadedPcx(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name, INT w, INT h);

		_H3API_ static H3LoadedPcx* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx* Create(LPCSTR name, INT width, INT height);
		_H3API_ VOID DrawAlpha(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
	protected:
		_H3API_ VOID drawAlpha2(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
		_H3API_ VOID drawAlpha4(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(LoadedPcx16);
	_H3API_TYPE_DECLARE_(H3LoadedPcx16, Bitmap16);

#pragma pack(push, 4)
	struct H3LoadedPcx16 : public H3ResourceItem
	{
		_H3API_SIZE_(0x38);
		_H3API_VTABLE_(0x63B9C8);

		INT32 buffSize;
	protected:
		INT32 buffSizeUnk;
	public:
		INT32 width;
		INT32 height;
		INT32 scanlineSize;
		PUINT8 buffer;
		BOOL8 keepBuffer; // see 0x44DDE0

		_H3API_ VOID CopyRegion(H3LoadedPcx16* source, INT x, INT y);
		_H3API_ H3LoadedPcx16* Construct(LPCSTR name, INT width, INT height);
		_H3API_ VOID DrawToPcx16(INT x, INT y, BOOL transparent, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		_H3API_ VOID Destroy(BOOL destroy_buffer = TRUE);
		_H3API_ VOID DrawShadow(INT x, INT y, INT dw, INT dh);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, DWORD color);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, BYTE r = 232, BYTE g = 212, BYTE b = 120);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, const H3RGB888& color);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, const H3RGB888& color);
		_H3API_ VOID DarkenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID LightenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID GrayScaleArea(INT x, INT y, INT w, INT h);
		_H3API_ VOID AdjustHueSaturation(INT x, INT y, INT w, INT h, FLOAT hue, FLOAT saturation);
		_H3API_ BOOL BackgroundRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL is_blue);
		_H3API_ BOOL SimpleFrameRegion(INT32 x, INT32 y, INT32 _width, INT32 _height);
		_H3API_ BOOL FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue);
		_H3API_ VOID SinkArea(INT32 x, INT32 y, INT32 w, INT32 h);
		_H3API_ VOID BevelArea(INT32 x, INT32 y, INT32 w, INT32 h);
		_H3API_ VOID TextDraw(H3Font* font, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			eTextColor colorIndex = eTextColor::REGULAR,
			eTextAlignment alignment = eTextAlignment::MIDDLE_CENTER);

		_H3API_ static H3LoadedPcx16* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx16* Create(LPCSTR name, INT width, INT height);
		_H3API_ static H3LoadedPcx16* Create(INT width, INT height);
		_H3API_ PUINT8 GetRow(int row);
		_H3API_ H3RGB565* GetPixel565(int x, int y);
		_H3API_ H3ARGB888* GetPixel888(int x, int y);
		_H3API_ H3ARGB888 GetPixel(int x, int y);
		_H3API_ VOID Clamp(INT& src_x, INT& src_y, INT& src_w, INT& src_h, INT& dst_x, INT& dst_y) const;
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx16);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(LoadedPcx24);

#pragma pack(push, 4)

	struct H3LoadedPcx24 : public H3ResourceItem
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x63B9F4);

		INT32 buffSize;
	protected:
		INT32 buffSizeUnk;
	public:
		INT32 width;
		INT32 height;
		PUINT8 buffer;

		_H3API_ H3LoadedPcx24* Construct(LPCSTR name, INT width, INT height, PUINT8 data, UINT32 dataSize);
		_H3API_ VOID DrawToPcx16(INT dst_x, INT dst_y, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		_H3API_ PUINT8 GetRow(int row);
		_H3API_ H3RGB888* GetPixel(int x, int y);

		_H3API_ static H3LoadedPcx24* Load(LPCSTR name, INT width, INT height);
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx24);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3Msk;
	struct H3Fnt;
	struct H3LodItem;
	struct H3LoadedMsk;
	struct H3Lod;

#pragma pack(push, 1)

	struct H3Msk
	{
		_H3API_SIZE_(0x0E);
		struct Msk
		{
			DWORD dbits;
			WORD  wbits;

			_H3API_ void operator>>(H3ObjectMask& mask) const;
		};
		UINT8 width;
		UINT8 height;
		Msk   colorMask;
		Msk   shadowMask;
	};
	_H3API_ASSERT_SIZE_(H3Msk);

	struct H3Fnt
	{
		UINT8  magic[5];
		UINT8  height;
		h3unk8 header[26];
		struct FntCharacter
		{
			INT32 leftMargin;
			INT32 width;
			INT32 rightMargin;
		}characters[256];
		UINT32 bufferOffsets[256];
		UINT8 buffer[4]; // size unset
	};
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)

	struct H3LodItem
	{
		_H3API_SIZE_(0x20);
		CHAR    name[12];
		h3unk32 nameEnd;
		PUINT8  buffer;
		UINT32  size;
		INT32   type;
		UINT32  sizeCompressed;
	};
	_H3API_ASSERT_SIZE_(H3LodItem);

	struct H3LoadedMsk
	{
		_H3API_SIZE_(0x18);

		UINT width;
		UINT height;
		H3ObjectMask colors;
		H3ObjectMask shadow;

		_H3API_ VOID operator=(const H3Msk& msk);
	};
	_H3API_ASSERT_SIZE_(H3LoadedMsk);

	struct H3Lod
	{
		_H3API_SIZE_(0x190);

		LPCSTR name;
		FILE* filePosition;
		CHAR   path[256];
		h3unk  _f_108[112];
		INT32  filesCount;
		h3unk  _f_17C[4];
		PUINT8 fileHeaders;
		h3unk  _f_184[12];

		_H3API_ H3Lod*     Create(LPCSTR fileName);
		_H3API_ VOID       Destroy();
		_H3API_ BOOL       Load(LPCSTR fileName);
		_H3API_ BOOL8      FindFileInLod(LPCSTR file);
		_H3API_ H3LodItem* LoadFileFromLod(LPCSTR file);
	};
	_H3API_ASSERT_SIZE_(H3Lod);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Palette32);

#pragma pack(push, 4)

	struct H3Palette32
	{
		H3ARGB888 colors[256];

		_H3API_ H3ARGB888& operator[](UINT index);
		_H3API_ H3ARGB888  operator[](UINT index) const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Palette565);
	_H3API_TYPE_DECLARE_(H3Palette565, Palette16);

#pragma pack(push, 4)
	struct H3Palette565 : public H3ResourceItem
	{
		_H3API_SIZE_(0x21C);
		union {
			struct {
				H3RGB565 color[256];
			};
			struct {
				H3RGB565   unusedColors[254];
				H3Palette32* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		_H3API_ H3Palette565* Initiate();
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(const H3Palette565& source);
		_H3API_ VOID CopyPalette(const H3BasePalette565& source);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

		_H3API_ VOID Init(const H3BasePalette565& palette);

		_H3API_ static H3Palette565* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3Palette565);

	_H3API_NAMED_STRUCT_(H3Palette565, PlayersPalette, 0x6AAD10);
	_H3API_NAMED_STRUCT_(H3Palette565, GamePalette, 0x6AAD18);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Palette888);
	_H3API_TYPE_DECLARE_(H3Palette888, Palette24);

#pragma pack(push, 4)
	struct H3Palette888 : public H3ResourceItem
	{
		_H3API_SIZE_(0x31C);
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ H3Palette888* Initiate();

		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;
		_H3API_ VOID Init(const H3BasePalette888& palette);

		_H3API_ H3Palette32 Convert() const;
	};
	_H3API_ASSERT_SIZE_(H3Palette888);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(QuestsText);

#pragma pack(push, 4)

	struct H3QuestsText
	{
		_H3API_GET_INFO_(0x56C72F + 2, H3QuestsText);

		struct
		{
		private:
			H3String m_unused[5];
		public:
			H3String text[44];
		private:
			H3String m_unused2;
		public:
			H3String deserted;
			H3String deadline;
		}variants[3];
	};

	_H3API_NAMED_STRUCT_(H3QuestsText, SeersText, 0x56C724 + 2);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ResourceManager);
	struct H3ResourceItem;

#pragma pack(push, 4)

	struct H3ResourceItemData
	{
		_H3API_SIZE_(0x14);
		CHAR            m_name[12];
		UINT            m_nameEnd;
		H3ResourceItem* m_item;

		_H3API_ H3ResourceItemData(LPCSTR name);
		_H3API_ BOOL8 operator<(const H3ResourceItemData& other) const;
	};
	_H3API_ASSERT_SIZE_(H3ResourceItemData);

	struct H3ResourceManager : H3Set<H3ResourceItemData, 0x69E604>
	{
		_H3API_GET_INFO_(0x55A7CE + 1, H3ResourceManager);

		_H3API_ Node* FindItem(LPCSTR name);
		_H3API_ VOID  AddItem(H3ResourceItem* item);
		_H3API_ VOID  RemoveItem(Node* node);
		_H3API_ VOID  RemoveItem(const iterator& iter);
		_H3API_ VOID  RemoveItem(LPCSTR name);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SecondarySkillText);
	_H3API_TYPE_DECLARE_(H3SecondarySkillText, SecondarySkillInfo);

#pragma pack(push, 4)

	struct H3SecondarySkillText
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x67DCF0, H3SecondarySkillText);

		LPCSTR name;
		LPCSTR description[3];
	};
	_H3API_ASSERT_SIZE_(H3SecondarySkillText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SpellbookText);

#pragma pack(push, 4)

	struct H3SpellbookText
	{
		_H3API_GET_INFO_(0x59DBB0 + 3, H3SpellbookText);
		struct TextPair
		{
			LPCSTR text;
			LPCSTR description;
		};

		TextPair previousPage;
		TextPair nextPage;
		TextPair adventureMapSpells;
		TextPair combatSpells;
		TextPair schoolSpells[5]; // air, fire, water, earth, all
		TextPair spellPoints;
		TextPair closeSpellbook;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TextFile);
	_H3API_TYPE_DECLARE_(H3TextFile, TextResource);

#pragma pack(push, 4)
	struct H3TextFile : public H3ResourceItem
	{
		_H3API_SIZE_(0x30);
	protected:
		H3Vector<LPCSTR> text;
		LPCSTR buffer;
	public:
		_H3API_ LPCSTR  GetText(UINT32 row) const;
		_H3API_ LPCSTR  GetText(UINT32 row);
		_H3API_ VOID    UnLoad();
		_H3API_ LPCSTR& operator[](UINT row);
		_H3API_ LPCSTR* begin();
		_H3API_ LPCSTR* end();

		_H3API_ static H3TextFile* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextFile);

	_H3API_NAMED_STRUCT_(H3TextFile, GeneralText,  0x6A5DC4);
	_H3API_NAMED_STRUCT_(H3TextFile, AdveventText, 0x696A68);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TextTable);
	_H3API_TYPE_DECLARE_(H3TextTable, SpreadSheetResource);

#pragma pack(push, 4)

	struct H3TextTable : public H3ResourceItem
	{
		_H3API_SIZE_(0x34);
		struct iterator
		{
		protected:
			H3Vector<LPCSTR>** data;
		public:
			_H3API_ iterator(H3Vector<LPCSTR>** vec);
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ H3Vector<LPCSTR>& operator*();
			_H3API_ H3Vector<LPCSTR>* operator->();
			_H3API_ LPCSTR operator[](UINT column);
			_H3API_ BOOL   operator==(const iterator& other);
			_H3API_ BOOL   operator!=(const iterator& other);
		};

	protected:
		H3Vector<H3Vector<LPCSTR>*> text;
		LPCSTR buffer;
		UINT bufferSize;
	public:
		_H3API_ H3Vector<H3Vector<LPCSTR>*>& GetText();
		_H3API_ H3Vector<LPCSTR>& operator[](UINT row);
		_H3API_ UINT32   CountRows() const;
		_H3API_ VOID     UnLoad();
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ static H3TextTable* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextTable);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(WavFile);

#pragma pack(push, 4)
	struct H3WavFile : public H3ResourceItem
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x6416E0);

		HANDLE hSample;
		PUINT8 buffer;
		DWORD bufferSize;
		HANDLE lockSemaphore;
		ULONG_PTR spinCount;
		PRTL_CRITICAL_SECTION_DEBUG debugInfo;

		_H3API_ static H3WavFile* Load(LPCSTR name);

		_H3API_ H3WavFile(LPCSTR name);
		_H3API_ H3WavFile(LPCSTR name, PUINT8 buffer, DWORD bufferSize);
	};
	_H3API_ASSERT_SIZE_(H3WavFile);

	_H3API_NAMED_STRUCT_(H3WavFile, ButtonWav, 0x694DF4);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpHeader);
	struct H3GzInflateBuf;
	struct H3CmpScenarioHeader;

#pragma pack(push, 4)

	struct H3CmpHeader
	{
		h3unk32                        _f_0; // set as 2 for old campaign versions
		H3String                       filename;
		eCampaignType                  type;
		INT32                          mapCount;
		H3String                       name;
		H3String                       description;
		H3Vector<H3CmpScenarioHeader*> scenarios;
		PBYTE                          rawBuffer;
		H3GzInflateBuf*                gzBuf;
		BOOL8                          canChooseDifficulty;
		eCampaignMusic                 music;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CampaignInfo);
	struct H3CmpScenarioInfo;
	struct H3Hero;

#pragma pack(push, 4)

	struct H3CmpInfo
	{
		_H3API_SIZE_(0x7C);
		BOOL8 cheater;
		BOOL8 avgMapScoreAbove350;
		INT8  campaignMapIndex;
	protected:
		h3unk8 _f_3;
	public:
		INT32 bigCampaignIndex;
	protected:
		h3unk8 _f_8[4];
	public:
		INT8 crossoverArrayIndex;
	protected:
		h3unk8 _f_D[3];
		h3unk8 _f_10[4];
		h3unk8 _f_14;
		h3unk8 _f_15[3];
		h3unk8 _f_18[4];
		h3unk8 _f_1C;
		h3unk8 _f_1D[3];
		h3unk8 _f_20[4];
	public:
		h3unk8 BigCampaignStarted[21];
	protected:
		h3unk8 _f_39[3];
		H3Vector<H3Vector<H3Hero>> crossoverHeroes;
		H3Vector<h3unk> someCrossoverArraysRef;
		H3Vector<H3CmpScenarioInfo> campaignMapInfo;
		H3Vector<h3unk> someCrossoverInfoStructs;
	};
	_H3API_ASSERT_SIZE_(H3CmpInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpPrologue);

#pragma pack(push, 4)

	struct H3CmpPrologue
	{
		_H3API_SIZE_(0x18);

		eCampaignMovie movie;
		eCampaignMusic music;
		H3String       text;
	};
	_H3API_ASSERT_SIZE_(H3CmpPrologue);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpScenarioHeader);
	struct H3CmpPrologue;
	union  H3CmpStartBoni;

#pragma pack(push, 4)

	struct H3CmpScenarioHeader
	{
		_H3API_SIZE_(0xA8);
		H3String          mapName;
		h3unk32           offset;
		INT32             deflatedDataSize;
		H3Vector<BOOL8>   requirements;
		H3String          description;
		INT8              color;
		INT8              difficulty;
		H3CmpPrologue*    prologue;
		H3CmpPrologue*    epilogue;
		BOOL8             keepExperience;
		BOOL8             keepPrimarySkills;
		BOOL8             keepSecondarySkills;
		BOOL8             keepSpells;
		BOOL8             keepArtifacts;
		h3unk32           powerPlaceholder[8];
		H3Vector<INT32>   heroIds;
		H3CreaturesBitset creatures;
		H3ArtifactBitset  artifacts;
		H3CmpStartBoni*   startingOptions;
	};
	_H3API_ASSERT_SIZE_(H3CmpScenarioHeader);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpScenarioInfo);

#pragma pack(push, 4)

	struct H3CmpScenarioInfo
	{
		_H3API_SIZE_(0x14);
		BOOL8 completed;
		INT32 days;
		INT32 score;
		INT32 corroverArrayIndex;
		INT32 completionOrder;
	};
	_H3API_ASSERT_SIZE_(H3CmpScenarioInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SecondarySkill);

#pragma pack(push, 4)

	struct H3SecondarySkill
	{

		eSecondary     type;
		eSecSkillLevel level;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpStartingBonusDetails);

#pragma pack(push, 4)
	struct H3CmpStartingBonusDetails
	{
		struct VTable
		{
			h3func dtor;
			h3func isBuilding; // only one
			h3func imageName;
			h3func spriteFrame;
			h3func description;
			h3func apply;
			h3func read; // +18
			h3func buildingId; // for buildings only, converts to game id
		}*vtable;
	};

	struct H3CmpBonusSpell : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DAA0);

		eHero  hero;
		eSpell spell;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSpell);

	struct H3CmpBonusCreatures : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x10);
		_H3API_VTABLE_(0x63DA80);

		eHero     hero;
		eCreature type;
		INT32     count;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusCreatures);

	struct H3CmpBonusBuilding : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA60);

		eTown town;
		union{
			eBuildings building;
			INT32      index;
		};
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusBuilding);

	struct H3CmpBonusArtifact : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA40);

		eHero     hero;
		eArtifact artifact;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusArtifact);

	struct H3CmpBonusSpellScroll : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA20);

		eHero hero;
		INT32 spell;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSpellScroll);

	struct H3CmpBonusPrimarySkill : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA00);

		eHero           hero;
		H3PrimarySkills skills;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusPrimarySkill);

	struct H3CmpBonusSecondarySkill : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x10);
		_H3API_VTABLE_(0x63D9E0);

		eHero		     hero;
		H3SecondarySkill skill;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSecondarySkill);

	struct H3CmpBonusResources : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63D9C0);

		eResource type;
		INT32     count;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusResources);

	struct H3CmpBonusBuildingsNames
	{
		_H3API_GET_INFO_(0x48415F + 3, H3CmpBonusBuildingsNames);

		LPCSTR names[44];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpStartingBonusOption);
	_H3API_DECLARE_(CmpHeroCrossoverOptions);
	_H3API_DECLARE_(CmpStartingHeroOption);
	struct H3CmpStartingBonusDetails;

#pragma pack(push, 4)

	struct H3CmpStartingOptionsBase
	{
		struct VTable
		{
			h3func dtor;
			h3func imgIsPcx;
			h3func numberBoni;
			h3func imageName;
			h3func getSpriteFrame;
			h3func getCrossoverObjects;
			h3func getDescription;
			h3func _f_1C; // always returns -1
			h3func getPlayerId;
			h3func read;
			h3func applyBonus;
			h3func updateOptions;
			h3func _f_30; // maybe loading save?
		}*vtable;
	};

	struct H3CmpStartingBonusOption : H3CmpStartingOptionsBase // 1
	{
		_H3API_SIZE_(0x18);
		_H3API_VTABLE_(0x63D98C);

		INT32 playerColor;
		H3Vector<H3CmpStartingBonusDetails*> boni;
	};
	_H3API_ASSERT_SIZE_(H3CmpStartingBonusOption);

	struct H3CmpHeroCrossoverOptions : H3CmpStartingOptionsBase // 2
	{
		_H3API_SIZE_(0x14);
		_H3API_VTABLE_(0x63DAD8);

		struct CrossoverHeroes
		{
			INT8 player;
			INT8 scenario;
		};

		H3Vector<CrossoverHeroes> crossoverHeroes;
	};
	_H3API_ASSERT_SIZE_(H3CmpHeroCrossoverOptions);

	struct H3CmpStartingHeroOption : H3CmpStartingOptionsBase // 3
	{
		_H3API_SIZE_(0x14);
		_H3API_VTABLE_(0x63DB0C);

		struct StartingHeroes
		{
			INT32 player;
			eHero hero; // -1 for random
		};

		H3Vector<StartingHeroes> heroes;
	};
	_H3API_ASSERT_SIZE_(H3CmpStartingHeroOption);

#ifdef _H3API_CPLUSPLUS11_
	union H3CmpStartBoni
	{
		H3CmpStartingBonusOption   bonus;
		H3CmpHeroCrossoverOptions  crossoverOptions;
		H3CmpStartingHeroOption    heroOptions;

		H3CmpStartBoni() {}
		~H3CmpStartBoni() {}
	};
#else
	typedef VOID* H3CmpStartBoni;
#endif

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CmpVideo);

#pragma pack(push, 4)

	struct H3CmpVideo
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x44D5C3 + 2, H3CmpVideo);

		LPCSTR  name;
		LPCSTR  loopName;
		BOOL8   isBink;
		BOOL8   fadein;
		BOOL8   fadeout;
		h3unk32 _f_0C[2];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(AdjacentSquares);

#pragma pack(push, 4)

	struct H3AdjacentSquares
	{
		_H3API_SIZE_(0xC);

		INT16 topRight;
		INT16 right;
		INT16 bottomRight;
		INT16 bottomLeft;
		INT16 left;
		INT16 topLeft;
	};
	_H3API_ASSERT_SIZE_(H3AdjacentSquares);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CreatureAnimation);
	typedef H3CreatureAnimation H3MonsterAnimation;

#pragma pack(push, 4)

	struct H3CreatureAnimation
	{
		_H3API_SIZE_(0x54);
		_H3API_GET_INFO_(0x50CC01 + 3, H3CreatureAnimation);

		struct H3MissileOffets
		{
			INT16 offset_x;
			INT16 offset_y;
		}missiles[3];
		INT32 missileFrameAngles[12]; // from high to low (90 to -90)
		INT32 troopCountLocationOffset;
		INT32 attackClimaxFrame;
		INT32 timeBetweenFidgets;
		INT32 walkAnimationTime;
		INT32 attackAnimationTime;
		INT32 flightAnimationTime;
	};
	_H3API_ASSERT_SIZE_(H3CreatureAnimation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CreatureInformation);

#pragma pack(push, 4)

	struct H3CreatureInformation
	{
		_H3API_SIZE_(0x74);
		_H3API_GET_INFO_(0x6747B0, H3CreatureInformation);

		INT32 town;
		INT32 level;
		LPCSTR soundName;
		LPCSTR defName;
		union
		{
			struct
			{
				unsigned doubleWide        : 1; // 1
				unsigned flyer             : 1; // 2
				unsigned shooter           : 1; // 4
				unsigned extendedAttack    : 1; // 8 ~ aka dragon breath
				unsigned alive             : 1; // 10
				unsigned destroyWalls      : 1; // 20
				unsigned siegeWeapon       : 1; // 40
				unsigned king1             : 1; // 80 ~ all creatures of 7th level and neutral dragons that do not belong to the KING2 or KING3
				unsigned king2             : 1; // 100
				unsigned king3             : 1; // 200
				unsigned mindImmunity      : 1; // 400
				unsigned shootsRay         : 1; // 800 WoG incorrectly refers to this as 'no obstacle penalty' instead it's a flag used to draw a straight line when shooting - see 0x43F23D
				unsigned noMeleePenalty    : 1; // 1000
				unsigned unk2000           : 1; // 2000
				unsigned fireImmunity      : 1; // 4000
				unsigned doubleAttack      : 1; // 8000
				unsigned noRetaliation     : 1; // 10000
				unsigned noMorale          : 1; // 20000
				unsigned undead            : 1; // 40000
				unsigned attackAllAround   : 1; // 80000
				unsigned fireballAttack    : 1; // 100000
				unsigned cannotMove        : 1; // 200000 ~21
				unsigned summon            : 1; // 400000
				unsigned clone             : 1; // 800000
				unsigned morale            : 1; // 1000000
				unsigned waiting           : 1; // 2000000 ~25
				unsigned done              : 1; // 4000000
				unsigned defending         : 1; // 8000000
				unsigned sacrificed        : 1; // 10000000
				unsigned noColoring        : 1; // 20000000
				unsigned gray              : 1; // 40000000
				unsigned dragon            : 1; // 80000000
			};
			UINT32 flags;
		};
		LPCSTR nameSingular;
		LPCSTR namePlural;
		LPCSTR description;
		H3Resources cost;
		INT32  fightValue;
		INT32  aiValue;
		INT32  grow;
		INT32  hGrow;
		INT32  hitPoints;
		INT32  speed;
		INT32  attack;
		INT32  defence;
		INT32  damageLow;
		INT32  damageHigh;
		INT32  numberShots;
		INT32  spellCharges;
		INT32  advMapLow;
		INT32  advMapHigh;

		_H3API_ LPCSTR      GetCreatureName(INT32 count) const;
		_H3API_ H3Resources UpgradeCost(H3CreatureInformation* upg, INT32 count) const;
	};
	_H3API_ASSERT_SIZE_(H3CreatureInformation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CombatCreature);
	typedef H3CombatCreature H3CombatMonster;
	struct H3LoadedDef;
	struct H3Hero;
	struct H3WavFile;

#pragma pack(push, 4)

	struct H3CombatCreature
	{
		_H3API_SIZE_(0x548);

		BOOL8   attackedAlready;
		INT32   totalPlayerStacks;
		UINT32  visibility;
		h3unk32 _f_0C;
		h3unk32 _f_10;
		h3unk32 _f_14;
		h3unk32 _f_18;
		INT32   battlefieldDestination;
		BOOL8   fireShieldAnimation;
		BOOL8   movementRelated;
		h3unk32 _f_24;
		INT32   cloneId;
		INT32   cloneDuration;
		BOOL8   skipCountDraw;
	public:
		INT32 type;
		INT32 position;
		INT32 animation;
		INT32 animationFrame;
		INT32 secondHexOrientation;
	protected:
		h3unk32 _f_048;
	public:
		INT32 numberAlive;
		INT32 previousNumber;
		INT32 numberForeverDead;
		INT32 healthLost;
		INT32 slotIndex;
		INT32 numberAtStart;
	protected:
		h3unk32 _f_064[2]; // maybe align?
	public:
		INT32 baseHP;
		INT32 isLucky;
		H3CreatureInformation info;
	protected: // these need confirmations
		BOOL8 applyFireShield;
		BOOL8 hasLosses;
		BOOL8 hasLosses2;
		BOOL8 isDead;
	public:
		INT32 spellToApply;
	protected:
		h3unk8 _f_0F0[4];
	public:
		INT32 side;
		INT32 sideIndex;
	protected:
		UINT32 lastAnimationTime;
		INT32 yOffset;
		INT32 xOffset;
		h3unk8 _f_108[8];
		H3MonsterAnimation cranim;
	public:
		H3LoadedDef* def;
	protected:
		H3LoadedDef* shootingDef;
		h3unk8 _f_16C[4];
		H3WavFile* moveSound;
		H3WavFile* attackSound;
		H3WavFile* getHitSound;
		H3WavFile* shotSound;
		H3WavFile* deathSound;
		H3WavFile* defendSound;
		H3WavFile* extraSound1;
		H3WavFile* extraSound2;
		h3unk8 _f_190[4];
	public:
		INT32 activeSpellNumber;
		INT32 activeSpellDuration[81];
		INT32 activeSpellLevel[81];
	protected:
		H3Vector<h3unk> _f_420; // size 0x400, spell related... may not be vector
		h3unk8 _f_430[36];
	public:
		INT32 retaliations;
		INT32 blessDamage;
		INT32 curseDamage;
		INT32 antiMagic;
		INT32 bloodlustEffect;
		INT32 precisionEffect;
		INT32 weaknessEffect;
		INT32 stoneSkinEffect;
	protected:
		INT32 _f_474;
	public:
		INT32 prayerEffect;
		INT32 mirthEffect;
		INT32 sorrowEffect;
		INT32 fortuneEffect;
		INT32 misfortuneEffect;
		INT32 slayerType;
		INT32 hexesTraveled;
		INT32 counterstrikeEffect;
		FLOAT frenzyMultiplier;
		FLOAT blindEffect;
		FLOAT fireShieldEffect;
	protected:
		h3unk32 _f_4A4;
	public:
		FLOAT protectionAirEffect;
		FLOAT protectionFireEffect;
		FLOAT protectionWaterEffect;
		FLOAT protectionEarthEffect;
		FLOAT shieldEffect;
		FLOAT airShieldEffect;
		BOOL8 blinded;
		BOOL8 paralyzed;
		INT32 forgetfulnessLevel;
		FLOAT slowEffect;
		INT32 hasteEffect;
		INT32 diseaseAttackEffect;
		INT32 diseaseDefenseEffect;
	protected:
		h3unk32 _f_4D8[2];
	public:
		INT32 faerieDragonSpell;
		INT32 magicMirrorEffect;
		INT32 morale;
		INT32 luck;
		BOOL8 isDone;
		BOOL8 highlightContour;
		H3Vector<H3CombatCreature*> dendroidBinder;
		H3Vector<H3CombatCreature*> dendroidBinds;
	protected:
		H3Vector<H3CombatCreature*> _f_514;
		H3Vector<H3CombatCreature*> hypnotized;
		h3unk8 _f_534[20];
	public:
		_H3API_ LPCSTR GetCreatureName() const;
		_H3API_ INT32 GetSecondSquare() const;
		_H3API_ INT32 GetStackSpeed() const;
		_H3API_ INT32 HexRelativePosition(INT32 considered_hex, INT32 relative_orientation) const;
		_H3API_ BOOL IsIncapacitated() const;
		_H3API_ BOOL IsDefending() const;
		_H3API_ BOOL IsDone() const;
		_H3API_ BOOL IsClone() const;
		_H3API_ BOOL IsSiege() const;
		_H3API_ BOOL IsSummon() const;
		_H3API_ BOOL HadMorale() const;
		_H3API_ BOOL IsWaiting() const;
		_H3API_ BOOL HasMoved() const;
		_H3API_ INT32 Index() const;
		_H3API_ VOID ShowStatsDialog(BOOL RightClick) const;
		_H3API_ INT32 GetSide() const;
		_H3API_ H3Hero* GetOwner() const;
		_H3API_ INT32 GetProtectiveSpellEffect(INT32 damage, INT32 spellID) const;
		_H3API_ INT32 MagicMirrorEffect() const;
		_H3API_ INT32 ApplyPhysicalDamage(INT32 amount);
		_H3API_ VOID  ApplySpell(INT32 spellId, INT32 spellPower, INT32 schoolLevel, H3Hero* hero);
        _H3API_ BOOL8 ApplyAfterHitSpell(H3CombatCreature* defender);
        _H3API_ VOID  ApplyAfterHitAbility(H3CombatCreature* defender, INT32 damage, INT32 killed, INT32 totalDefenderHp);
		_H3API_ BOOL8 CanReceiveSpell(INT32 spellId) const;
		_H3API_ BOOL  CanCastSpellAtEmptyHex(INT32 hexId) const;
		_H3API_ BOOL8 MoveToHex(INT32 hexId);
		_H3API_ BOOL8 UseEnchanters();
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
		_H3API_ INT32 CurrentHitPoints() const;
		_H3API_ INT32 MaxHitPoints() const;
	};
	_H3API_ASSERT_SIZE_(H3CombatCreature);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CombatSquare);
	struct H3CombatCreature;

#pragma pack(push, 4)

	struct H3CombatSquare
	{
		_H3API_SIZE_(0x70);
		INT16 x;
		INT16 y;
		INT16 left;
		INT16 top;
		INT16 right;
		INT16 bottom;
	protected: h3unk8 _f_0C[4]; public:
		union
		{
			UINT8 obstacleBits;
			struct
			{
				BOOL8 anchor        : 1; // 1
				BOOL8 localObstacle : 1; // 2
				BOOL8 quicksand     : 1; // 4
				BOOL8 landMine      : 1; // 8
				BOOL8 firewall      : 1; // 10
				BOOL8 forcefield    : 1; // 20 (also sets localObstacle -> 22)
				BOOL8 unused        : 2; // 40-80
			};
		};
		INT32 obstacleIndex;
		INT8 stackSide;
		INT8 stackIndex;
		BOOL8 twoHexMonsterSquare;
		INT32 deadStacksNumber;
		INT8 deadStackSide[14];
		INT8 deadStackIndex[14];
		BOOL8 belongsToAttacker[14];
		BOOL8 availableForLeftSquare;
		BOOL8 availableForRightSquare;
	protected:
		h3unk8 _f_4C[32];
		h3unk8 _f_6C[4];
	public:

		_H3API_ H3CombatCreature* GetMonster();
		_H3API_ H3CombatCreature* GetCreature();
	};
	_H3API_ASSERT_SIZE_(H3CombatSquare);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MagicAnimation);

#pragma pack(push, 4)

	struct H3MagicAnimation
	{
		_H3API_SIZE_(0x0C);
		_H3API_GET_INFO_(0x43F77B + 3, H3MagicAnimation);

		LPCSTR defName;
		LPCSTR name;
		INT32 type;

		_H3API_ static H3MagicAnimation* GetAnim(INT32 spellId);
	};
	_H3API_ASSERT_SIZE_(H3MagicAnimation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Obstacle);
	struct H3LoadedDef;
	struct H3ObstacleInfo;

#pragma pack(push, 4)

	struct H3Obstacle
	{
		_H3API_SIZE_(0x18);

		H3LoadedDef* def;
		H3ObstacleInfo* info;
		UINT8 anchorHex;
		INT8 ownerSide;
		h3unk8 featureTriggered;
		UINT32 featureDamage;
		UINT32 featureDuration;
		UINT32 animationIndex;
	};
	_H3API_ASSERT_SIZE_(H3Obstacle);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ObstacleInfo);

#pragma pack(push, 4)

	struct H3ObstacleInfo
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x465C1E + 3, H3ObstacleInfo);

		UINT16 landTypes;
		UINT16 specialGroundTypes;
		INT8 heightInCells;
		INT8 widthInCells;
		INT8 blockedCount;
		h3unk8 _f_7;
		INT8 relativeCells[8];
		LPCSTR defName;
	};
	_H3API_ASSERT_SIZE_(H3ObstacleInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ValidCatapultTargets);

#pragma pack(push, 4)

	struct H3ValidCatapultTargets
	{
		_H3API_SIZE_(0xC);
		_H3API_GET_INFO_(0x4929DD + 3, H3ValidCatapultTargets);

		INT32 fortElementId;
		INT16 hex;
		h3unk16 _f_06;
		INT16 x;
		INT16 y;
	public:
	};
	_H3API_ASSERT_SIZE_(H3ValidCatapultTargets);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(WallSection);

#pragma pack(push, 4)

	struct H3WallSection
	{
		_H3API_SIZE_(0x24);

		INT16 x;
		INT16 y;
		INT16 hex_id;
		LPCSTR names[5];
		INT32 name;
		INT16 hp;
	};
	_H3API_ASSERT_SIZE_(H3WallSection);

	struct H3TownFortifications
	{
		_H3API_SIZE_(0x288);
		_H3API_GET_INFO_(0x4947C0 + 3, H3TownFortifications);

		H3WallSection fortifications[h3::limits::FORT_ELEMENTS];
	};
	_H3API_ASSERT_SIZE_(H3TownFortifications);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Creature);

#pragma pack(push, 4)

	struct H3Creature
	{
		_H3API_ static INT32 GetUpgrade(INT32 id);
		_H3API_ static BOOL8 HasUpgrade(INT32 id);
		_H3API_ static LPCSTR GroupName(INT32 amount, INT32 text_variant);
	};

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)

	struct H3CreatureSlot16
	{
		_H3API_SIZE_(0x6);
		INT32 type;
		INT16 amount;
	};
	_H3API_ASSERT_SIZE_(H3CreatureSlot16);
#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GarrisonInterface);
	typedef H3GarrisonInterface H3CreatureExchange;
	struct H3Army;
	struct H3Hero;
	struct H3BaseDlg;

#pragma pack(push, 4)

	struct H3GarrisonInterface
	{
		_H3API_SIZE_(0x78);
		_H3API_CTOR_DTOR_(0x5AA030, -1);

	protected:
		h3unk8 _f_00[28]; // unused afaict
	public:
		INT32 x;
		INT32 y;
		BOOL32 isBottom;
		INT32 ownerId;
		INT32 selectedSlotIndex;
	protected:
		h3unk8 _f_30[52];
	public:
		INT32 id;
		H3BaseDlg* dlg;
		H3Army* army;
		INT32 heroPictureIndex;
		H3Hero* hero;

		_H3API_ VOID DrawHero(INT32 hero_picture);
		_H3API_ VOID DrawCreature(INT32 index, INT32 creature_portrait_index);
		_H3API_ VOID Redraw(INT32 selected_slot = -1);
	};
	_H3API_ASSERT_SIZE_(H3GarrisonInterface);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GlobalEvent);

#pragma pack(push, 4)

	struct H3GlobalEvent
	{
		_H3API_SIZE_(0x34);
		H3String message;
		H3Resources resources;
		UINT8 players;
		BOOL8 humanEnabled;
		BOOL8 computerEnabled;
		UINT16 firstDay;
		UINT16 repeatEveryXDays;
	};
	_H3API_ASSERT_SIZE_(H3GlobalEvent);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(LossCondition);

#pragma pack(push, 4)

	struct H3LossCondition
	{
		_H3API_SIZE_(0x24);

		eLoss  type;
		INT32  loseTownX;
		INT32  loseTownY;
		INT32  loseTownZ;
		INT32  loseHeroX;
		INT32  loseHeroY;
		INT32  loseHeroZ;
		INT32  loseHeroId;
		UINT16 timeExpires;
		BOOL8  lossConditionReached;
		INT8   losingPlayerId;
	};
	_H3API_ASSERT_SIZE_(H3LossCondition);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MainSetup);
	struct H3ObjectAttributes;
	struct H3ObjectDetails;
	struct H3LoadedDef;
	struct H3MapArtifact;
	struct H3Monster;
	struct H3PandorasBox;
	struct H3SeerHut;
	struct H3QuestGuard;
	struct H3GlobalEvent;
	struct H3CastleEvent;
	struct H3HeroPlaceholder;
	struct H3Quest;
	struct H3RandomDwelling;
	struct H3MapItem;
	struct H3ObjectDraw;

#pragma pack(push, 4)

	struct H3MainSetup
	{
		_H3API_SIZE_(0xF5C);
		H3Vector<H3ObjectAttributes> objectAttributes; // +00 // +01FB70
		H3Vector<H3ObjectDetails>    objectDetails;	   // +10
		H3Vector<H3LoadedDef*>       defs;			   // +20
		H3Vector<H3MapArtifact>      artifactResource; // +30
		H3Vector<H3Monster>          monsters;	       // +40
		H3Vector<H3PandorasBox>      pandoraEvents;    // +50 // +01FBC0
		H3Vector<H3SeerHut>          seerHuts;	       // +60 // +01FBD0
		H3Vector<H3QuestGuard>       questGuards;	   // +70 // +01FBE0
		H3Vector<H3GlobalEvent>      globalEvents;	   // +80
		H3Vector<H3CastleEvent>      castleEvents;	   // +90
		H3Vector<H3HeroPlaceholder*> heroPlaceholders; // +A0
		H3Vector<H3Quest*>           quests;           // +B0
		H3Vector<H3RandomDwelling>   randomDwellings;  // +C0
		H3MapItem*                   mapitems;         // +D0 // +1FC40
		INT32                        mapSize;          // +D4 // +1FC44
		BOOL8                        hasUnderground;   // +D8 // +1FC48
		H3Vector<H3ObjectAttributes> objectLists[232];

		_H3API_ H3MapItem* GetMapItem(INT32 x, INT32 y, INT32 z);
		_H3API_ VOID DrawItem(H3MapItem* mitem, H3ObjectDraw* draw);
		_H3API_ VOID AddObjectAttribute(H3ObjectAttributes* oa);
		_H3API_ H3Point GetCoordinates(H3MapItem* item);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3MainSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PlayerAttributes);
	struct H3CustomHeroData;

#pragma pack(push, 4)

	struct H3PlayerAttributes
	{
		_H3API_SIZE_(0x44);
		BOOL8 humanPlayable;
		BOOL8 computerPlayable;
		INT32 aiBehaviour;
		UINT16 availableFactionsBitset;
		BOOL8 ownsRandomTown;
		BOOL8 generateHeroAtMainTown;
		BOOL8 hasMainTown;
		BOOL32 generateHero;
		H3Position mainTownPosition;
		BOOL8 hasRandomHero;
		INT32 mainHeroId;
		INT32 mainHeroCustomPicture;
		CHAR customName[12];
		h3unk32 powerPlaceholder;
		H3Vector<H3CustomHeroData> heroesData;
	};
	_H3API_ASSERT_SIZE_(H3PlayerAttributes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(VictoryCondition);

#pragma pack(push, 4)

	struct H3VictoryCondition
	{
		_H3API_SIZE_(0x4C);

		eVictory type;
		BOOL8 allowDefeatAll;
		BOOL8 appliesToComputer;
		INT32 artifactId;
		INT32 accumulateCreaturesType;
		INT32 accumulateCreaturesAmount;
		INT32 accumulateResource;
		INT32 accumulateResourceAmount;
		INT32 townX;
		INT32 townY;
		INT32 townZ;
		INT8  villageHallLevel;
		INT8  buildFortLevel;
		INT32 defeatHeroX;
		INT32 defeatHeroY;
		INT32 defeatHeroZ;
		INT32 defeatHeroId;
		INT32 defeatMonsterX;
		INT32 defeatMonsterY;
		INT32 defeatMonsterZ;
		INT32 daysToSurvive;
		BOOL8 winConditionReached;
		INT8  winningPlayerId;
	};
	_H3API_ASSERT_SIZE_(H3VictoryCondition);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MapInfo);
	struct H3MapHeroInfo;

#pragma pack(push, 4)

	struct H3MapInfo
	{
		_H3API_SIZE_(0x304);
		INT32                mapVersion;                    /** @brief [000]*/
		BOOL8                hasPlayers;                    /** @brief [004]*/
		INT8                 mapDifficulty;                 /** @brief [005]*/
		INT8                 computerPlayableCount;         /** @brief [006]*/
		INT8                 humanOnlyCount;                /** @brief [007]*/
		h3unk8                humanOnly_8;                   /** @brief [008] unsure what distinction is with [007]*/
	protected:
		h3unk8                _f_9;
		h3unk8                _f_A;
	public:
		INT8                 maxHeroLevel;                  /** @brief [00B]*/
		BOOL8                hasTeams;                      /** @brief [00C]*/
		INT8                 playerTeam[8];                 /** @brief [00D]*/
		INT32                mapDimension;                  /** @brief [018]*/
		BOOL8                hasUnderground;                /** @brief [01C]*/
	protected:
		H3Vector<h3unk8>      _f_20; // seems to be an unused feature
	public:
		H3VictoryCondition   victory;                       /** @brief [030]*/
		H3LossCondition      loss;                          /** @brief [07C]*/
		H3PlayerAttributes   playerAttributes[8];           /** @brief [0A0]*/
		H3Set<H3MapHeroInfo> playerHeroes;                  /** @brief [2C0]*/
		H3String             mapName;                       /** @brief [2D0]*/
		H3String             mapDescription;                /** @brief [2E0]*/
		H3Bitfield           expansionHeroes[5];            /** @brief [2F0]*/
	};
	_H3API_ASSERT_SIZE_(H3MapInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SetupHero);

#pragma pack(push, 1)
	struct H3SetupHero
	{
		_H3API_SIZE_(0x334);
		INT8	   owner;                    // +0
	protected:
		h3align    _f_01[3];
	public:
		UINT32     number;                   // +4
		UINT32     id;                       // +8
		BOOL8      hasCustomName;            // +C
		CHAR       name[13];                 // +D
		BOOL8      hasCustomExperience;      // +1A
	protected:
		h3align    _f_1B;
	public:
		INT32      experience;               // +1C
		UINT8      hasCustomPicture;         // +20
		UINT8      pictureId;                // +21
		BOOL8      hasCustomSecondarySkills; // +22
	protected:
		h3align    _f_23;
	public:
		UINT32     numberSecondarySkills;    // +24
		UINT8      secondarySkills[8];       // +28
		UINT8      secondarySkillsLevels[8]; // +30
		BOOL8      hasCustomCreatures;       // +38
	protected:
		h3align    _f_39[3];
	public:
		INT32      creatureType[7];          // +3C
		INT16      creatureNumber[7];        // +58
		BOOL8      groupedFormation;         // +66 spread/grouped
		BOOL8      hasCustomArtifacts;       // +67
		H3Artifact bodyArt[19];              // +68
		H3Artifact backpackArt[64];          // +100
		UINT8      backpackCount;            // +300
		UINT16     x;                        // +301
		UINT16     y;                        // +303
		UINT8      radius;                   // +305
		BOOL8      hasCustomBiography;       // +306
	protected:
		UINT8      _f_307;
	public:
		H3String   biography;
		BOOL8      isFemale;                 // +318
	protected:
		h3align    _f_319[3];
	public:
		BOOL8      hasCustomSpells;          // +31C
	protected:
		h3align    _f_31D[3];
	public:
		H3SpellsBitset spells;               // +320
		BOOL8      hasCustomPrimarySkills;   // +32C
		INT8       pSkill[4];                // +32D
	protected:
		h3unk8     _f_331[3];
	public:
	};
	_H3API_ASSERT_SIZE_(H3SetupHero);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Hero);
	struct H3CombatCreature;

#pragma pack(push, 1)
	struct H3Hero
	{
		_H3API_SIZE_(0x492);

		INT16   x;
		INT16   y;
		INT16   z;
		BOOL8	isVisible;
		H3Position  mixedPosition;
		BOOL8	objectBelow;
		INT32   objectTypeUnder;
	protected:
		UINT32  _flag;
	public:
		UINT32  objectBelowSetup;
		INT16   spellPoints;
	public:
		INT32	id;
	protected:
		UINT	number;
	public:
		INT8	owner;
		CHAR	name[12+1];
		INT32   hero_class;
		UINT8   picture;
		INT32	dest_x;
		INT32	dest_y;
		INT32	dest_z;
	protected:
		h3unk8	_f_41[3];
	public:
		UINT8   patrol_x;
		UINT8   patrol_y;
		INT8   patrolRadius;
	protected:
		h3unk8	_f_47;
		h3unk8  _f_48;
	public:
		INT32   maxMovement;
		INT32   movement;
		INT32	experience;
		INT16   level;
	protected:
		H3Bitfield  learningStones;
		H3Bitfield  marlettoTower;
		H3Bitfield  gardenRevelation;
		H3Bitfield  mercenaryCamp;
		H3Bitfield  starAxis;
		H3Bitfield  treeKnowldge;
		H3Bitfield  libraryEnlightenment;
		H3Bitfield  arena;
		H3Bitfield  schoolMagic;
		H3Bitfield  schoolWar;
		UINT8	_f_7F[16];
	public:
		UINT8	levelSeed;
	protected:
		UINT8	_f_90;
	public:
		H3Army army;
		INT8   secSkill[28];
		INT8   secSkillPosition[28];
		INT32  secSkillCount;
		union
		{
			struct
			{
				unsigned well              : 1;
				unsigned stables           : 1;
				unsigned buoy              : 1;
				unsigned swanPond          : 1;
				unsigned idolFortuneMorale : 1;
				unsigned fountainFortune1  : 1;
				unsigned wateringHole      : 1;
				unsigned oasis             : 1;
				unsigned temple            : 1;
				unsigned shipwreck         : 1;
				unsigned crypt             : 1;
				unsigned derelectShip      : 1;
				unsigned pyramid           : 1;
				unsigned faerieRing        : 1;
				unsigned fountainOfYouth   : 1;
				unsigned mermaids          : 1;
				unsigned rallyFlag         : 1;
				unsigned inTavern          : 1;
				unsigned inBoat            : 1;
				unsigned unk80000          : 1;
				unsigned sirens            : 1;
				unsigned warriorTomb       : 1;
				unsigned luckCheat         : 1;
				unsigned moraleCheat       : 1;
				unsigned speedCheat        : 1;
				unsigned idolFortuneLuck   : 1;
				unsigned temple2           : 1;
				unsigned fountainFortune2  : 1;
				unsigned fountainFortune3  : 1;
				unsigned fountainFortune4  : 1;
				unsigned unk40000000       : 2;
			};
			UINT32 flags;
		};
		FLOAT  AI_experienceEffectiveness;
		INT8	dimDoorCastCount; // +10D
		INT32   disguisePower;  // +10E
		INT32	flyPower;
		INT32	waterwalkPower; // +116
		INT8	moraleBonus;
		INT8	luckBonus;
		BOOL8	isSleeping;
	protected:
		h3unk8  _f_11D[4];
	public:
		H3VisitedTownsBitset visitedTowns;
		INT32	visionPower; // +129
		H3Artifact bodyArtifacts[19];
	protected:
		UINT8	freeAddSlots;
	public:
		UINT8	blockedArtifacts[14];
		H3Artifact backpackArtifacts[64];
		INT8	backpackCount;
		BOOL    isFemale;
		BOOL8	customBio;
		H3String biography;
		BOOL8   learnedSpells[70];
		BOOL8   availableSpell[70];
		INT8   primarySkill[4];
		UINT   aiAggressiveness;
		UINT   aiSpellPowerEffectiveness;
		UINT   aiSpellLengthEffectiveness;
		UINT   aiKnowledgeEffectiveness;
		UINT   aiDoubleSpellPointsEffectiveness;
		UINT   aiExtraSpellPointsEffectiveness;

	public:
		_H3API_ INT32 MaxLandMovement();
		_H3API_ INT32 MaxWaterMovement();
		_H3API_ INT32 CalcMaxMovement();
		_H3API_ VOID GiveArtifact(const H3Artifact& art, INT32 slot);
		_H3API_ VOID GiveArtifact(const H3Artifact& art);
		_H3API_ VOID GiveBackpackArtifact(const H3Artifact& art, INT32 index = -1);
		_H3API_ VOID LearnSecondarySkill(INT32 id, INT32 increase);
		_H3API_ INT32 GetSpellExpertise(INT32 spell_id, INT32 special_terrain);
		_H3API_ BOOL8 HasCreatureType(INT32 type);
		_H3API_ INT32 GetSpellSpecialtyEffect(INT32 spellID, INT32 creatureLevel, INT32 baseDamage);
		_H3API_ INT32 GetSorceryEffect(INT32 spell_id, INT32 base_damage, H3CombatCreature* mon);
		_H3API_ INT32 GetRealSpellDamage(INT32 baseDamage, H3CombatCreature* mon, INT32 spellID, H3Hero* enemy);
		_H3API_ INT32 GetSpecialTerrain();
		_H3API_ INT32 GetSpecialSpellTerrain();
		_H3API_ BOOL HasSpell(INT32 spell);
		_H3API_ VOID BuildCombinationArtifact(INT32 combo_id);
		_H3API_ BOOL UnlearnSkill(INT32 id);
		_H3API_ VOID RecalculateMovement();
		_H3API_ BOOL8 CanFlyOnTile();
		_H3API_ INT32 GetMovementCost(INT32 orientation, UINT32 mixedPos);
		_H3API_ INT32 SSkillsLeftToLearn();
		_H3API_ BOOL WearsArtifact(INT id);
		_H3API_ INT32 GetHeroPrimary(INT primary);
		_H3API_ INT32 HasSimilarCreature(INT id);
		_H3API_ LPCSTR GetHeroClassName();
		_H3API_ VOID ShowDialog() const;
		_H3API_ VOID ShowDialog(BOOL32 dismissable, BOOL32 not_in_town, BOOL8 right_click);
		_H3API_ INT GetPower() const;
		_H3API_ BOOL8 CanReplaceArtifact(INT32 id, INT32 slot) const;
		_H3API_ BOOL8 CanPlaceArtifact(INT32 id, INT32 slot) const;
		_H3API_ VOID RemoveArtifact(INT32 slot);
		_H3API_ VOID RemoveBackpackArtifact(INT32 slot);
		_H3API_ VOID ShowCreatureDialog(INT32 slot, BOOL rightClick);
		_H3API_ VOID ShowSpellInfo(INT32 spell, BOOL RMB);
		_H3API_ VOID ShowSSkillInfo(INT32 skill, BOOL RMB);
		_H3API_ VOID ShowPSkillInfo(INT32 skill, BOOL RMB);
		_H3API_ BOOL HasAllCombinationParts(INT slot);
		_H3API_ VOID DisassembleCombinationArtifact(INT slot);
		_H3API_ INT32 CalculateSpellCost(INT spell, H3Army* opponentArmy, INT specialTerrain);
		_H3API_ INT32 CalculateAdventureMapSpellCost(INT spell);
		_H3API_ VOID RemoveSpellPointsAndRefresh(UINT16 spellPoints);
		_H3API_ VOID UpdateAvailableSpell();
		_H3API_ VOID Hide();
		_H3API_ VOID Show();

		_H3API_ eCreature GetNecromancyCreatureId() const;
		_H3API_ FLOAT GetNecromancyPower(BOOL8 clamp_value) const;
		_H3API_ INT32 GetSpellPointsRestored() const;
		_H3API_ INT32 GetLuckBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const;
		_H3API_ INT32 GetMoraleBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const;
		_H3API_ INT32 GetScoutingRadius() const;
		_H3API_ FLOAT GetArcheryPower() const;
		_H3API_ FLOAT GetOffensePower() const;
		_H3API_ FLOAT GetArmorerPower() const;
		_H3API_ INT32 GetGeneratedGold() const;
		_H3API_ FLOAT GetEagleEyePower() const;
		_H3API_ FLOAT GetDiplomacyPower() const;
		_H3API_ FLOAT GetResistancePower() const;
		_H3API_ FLOAT GetLearningPower() const;
		_H3API_ FLOAT GetIntelligencePower() const;
		_H3API_ FLOAT GetFirstAidPower() const;

	};
	_H3API_ASSERT_SIZE_(H3Hero);

	struct H3DialogHero : H3Hero
	{
		_H3API_GET_INFO_(0x698B70, H3Hero);
	};

#pragma pack(pop) /* align-1 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Player);
	struct H3Hero;

#pragma pack(push, 4)

	struct H3Player
	{
		_H3API_SIZE_(0x168);

		INT8 ownerID;
		INT8 numberHeroes;
		INT32  currentHero;
		INT32  heroIDs[8];
		INT32  tavernHeroL;
		INT32  tavernHeroR;
	protected:
		h3unk8 _f_30[4];
	public:
		INT32 AI_type;
		INT8 visitedObelisks;
	protected:
		h3unk8 _f_39[4];
	public:
		INT8  daysLeft;
		INT8  townsCount;
		INT8  currentTown;
		INT8  towns[48];
	protected:
		h3unk8 _f_70[4];
		INT32 topHeroIndex;
		h3unk8 _f_78[36];
	public:
		H3Resources playerResources;
		H3Bitfield magicalGardens;
		H3Bitfield magicSpring;
		H3Bitfield visitedCorpses;
		H3Bitfield visitedLeanTos;
	protected:
		h3unk8 _f_C8[4];
		CHAR player_name[21];
	public:
		BOOL8 is_human;
		BOOL8 is_human2;
	protected:
		h3unk8 _f_E3[3];
		BOOL8 human;
		h3unk8 _f_E7;
		BOOL hasComboArtifacts;
		h3unk8 _f_EC[28];
	public:
		H3Resources income;
	protected:
		h3unk8 _f_124[4];
		DOUBLE resourceImportance[7];
		h3unk8 _f_160[8];
	public:
		_H3API_ H3Hero* GetActiveHero();
	};
	_H3API_ASSERT_SIZE_(H3Player);

	_H3API_NAMED_STRUCT_(H3Player, ActivePlayer, 0x69CCFC);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PlayersInfo);

#pragma pack(push, 4)

	struct H3PlayersInfo
	{
		_H3API_SIZE_(0x1CC);
	protected:
		h3unk8 _f_000[8];
	public:
		INT8  handicap[8];
		INT32 townType[8];
		INT8  playerType[8];
		INT8  difficulty;
		CHAR  filename[251];
		CHAR  saveDirectory[100];
		BOOL8 isPlayable[8];
	protected:
		h3unk8 _f_1A0[3];
	public:
		INT8 turnDuration;
		INT32 heroMaybe[8];
	protected:
		h3unk8 _f_1C4[8];
	};
	_H3API_ASSERT_SIZE_(H3PlayersInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Main);
	struct H3MapItem;
	struct H3SetupTown;
	struct H3Town;
	struct H3Signpost;
	struct H3Mine;
	struct H3Generator;
	struct H3Garrison;
	struct H3Boat;
	struct H3University;
	struct H3CreatureBank;

	_H3API_TYPE_DECLARE_(H3Main, Game);
	_H3API_TYPE_DECLARE_(H3Main, Base);

#pragma pack(push, 4)
	struct H3Main
	{
		_H3API_SIZE_(0x4E7D0);
		_H3API_GET_INFO_(0x699538, H3Main);

	protected:
		h3unk8 _f_0000[4];
	public:
		INT8 disabledShrines[70];
		INT8 disabledSpells[70];
		BOOL8 grailDisabledMessage;
		H3Vector<H3SetupTown> townSetups;
		H3SetupHero heroSetup[156];
	protected:
		h3unk8 _f_1F454[4];
		H3CmpInfo campaignInfo;
		h3unk8 _f_1F4D4[354];
	public:
		BOOL8 isDead[8];
		struct Date
		{
			_H3API_SIZE_(6);
			UINT16 day;
			UINT16 week;
			UINT16 month;
			_H3API_ UINT32 CurrentDay() const;
		}date;
	protected:
		h3unk8 _f_1F644[32];
	public:
		H3ArtifactMerchant artifactMerchant;
		H3Vector<H3BlackMarket> blackMarkets;
		struct Grail
		{
			_H3API_SIZE_(0x8);
			UINT16 x;		// +0
			UINT16 y;		// +2
			UINT8  z;		// +4
		protected:
			h3unk8 _f_5;
		public:
			INT8 isPresent;	// +6
		}grail;
		INT32 mapKind;
		BOOL8 isCheater;
		BOOL8 inTutorial;
	protected:
		h3unk8 _f_1F69E[2];
	public:
		H3PlayersInfo playersInfo;
		H3MapInfo mapInfo;
		H3MainSetup mainSetup;
	protected:
		h3unk8 _f_20ACC[4];
	public:
		H3Player players[8];
		H3Vector<H3Town> towns;
		H3Hero heroes[156];
		INT8 heroOwner[156];
		H3Bitfield heroMayBeHiredBy[156];
		INT8 randomArtifacts[144];
		INT8 artifactsAllowed[144];
	protected:
		H3PlayersBitfield visitedBuoy;
		H3PlayersBitfield visitedSwanPond;
		H3PlayersBitfield visitedFaerieRing;
		H3PlayersBitfield visitedFountainFortune;
		H3PlayersBitfield visitedGardenRevelation;
		H3PlayersBitfield visitedLearningStones;
		H3PlayersBitfield visitedLibraryEnlightenment;
		H3PlayersBitfield visitedMarlettoTower;
		H3PlayersBitfield visitedMercenaryCamp;
		H3PlayersBitfield visitedSchoolMagic;
		H3PlayersBitfield visitSchoolWar;
		H3PlayersBitfield visitedStarAxis;
		H3PlayersBitfield visitedWitchHut;
		H3PlayersBitfield visitedFountainYouth;
		H3PlayersBitfield visitedHillFort;
		H3PlayersBitfield visitedMagicSprings;
		H3PlayersBitfield visitedMermaid;
		H3PlayersBitfield visitedRallyFlag;
		H3PlayersBitfield visitedTreeKnowledge;
		H3PlayersBitfield visitedShrines;
		H3PlayersBitfield visitedIdolFortune;
		H3PlayersBitfield visitedTemples;
		H3PlayersBitfield visitedUniversities;
		H3PlayersBitfield visitedMagicWells;
		H3PlayersBitfield visitedOasis;
		H3PlayersBitfield visitedWateringHole;
		H3PlayersBitfield visitedAltarSacrifice;
		h3unk8 field_4E361[3]; // unused
	public:
		H3PlayersBitfield keymasterVisited[8];
	protected:
		UINT16 cartographersLandReveal[3];
		H3PlayersBitfield visitedCartographers[3];
		h3unk8 _f_4E375[3]; // unused
	public:
		H3Vector<H3Signpost> signpostsBottles;
		H3Vector<H3Mine> minesLighthouses;
		H3Vector<H3Generator> dwellings;
		H3Vector<H3Garrison> garrisons;
		H3Vector<H3Boat> boats;
		H3Vector<H3University> universities;
		H3Vector<H3CreatureBank> creatureBanks;
		INT8 obeliskCount;
		UINT8 obeliskVisited[48];
	protected:
		h3unk8 _f_4E419[575];
	public:
		INT8 bannedSkills[28];
	protected:
		h3unk8 _f_4E674[4];
	public:
		H3Vector<UINT32> monolithTwoWay[8];
		H3Vector<UINT32> monolithOneWay[8];
	protected:
		h3unk8 _f_4E778[4];
	public:
		H3Vector<UINT32> whirlPools;
		H3Vector<UINT32> subterraneanGatesDestination;
		H3Vector<UINT32> subterraneanGatesID;
	protected:
		H3Vector<h3unk8*> replayActions;
		H3Vector<h3unk8*> _f_4E7BC;
		h3unk8 _f_4E7CC[4];

	public:

		_H3API_ BOOL HasUnderground() const;

		_H3API_ H3Point GetCoordinates(H3MapItem* item);
		_H3API_ H3Hero*    GetHero(INT32 id);
		_H3API_ H3MapItem* GetMapItem(UINT32 mixedPosition);
		_H3API_ H3Player*  GetPlayer();
		_H3API_ INT32      GetPlayerID();
		_H3API_ INT32      GetRandomArtifactOfLevel(INT32 level);
		_H3API_ BOOL8      IsHuman(INT32 player_id);
		_H3API_ VOID       PlaceObjectOnMap(INT32 x, INT32 y, INT32 z, INT32 type, INT32 subtype, INT32 setup = -1);
		_H3API_ VOID       RefreshMapItemAppearrance(H3MapItem* mi);
		_H3API_ VOID       ResetRandomArtifacts();
		_H3API_ VOID       SaveGame(LPCSTR save_name);
		_H3API_ VOID UpdateMapItemAppearance(H3MapItem* item);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3Main);
	_H3API_ASSERT_SIZE_(H3Main::Date);
	_H3API_ASSERT_SIZE_(H3Main::Grail);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	template<typename T> struct H3NetworkData;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<typename _Elem>
	using NetworkData = H3NetworkData<_Elem>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

	struct H3String;
	_H3API_DECLARE_(Network);

#pragma pack(push, 4)

	struct H3Network
	{
		_H3API_ static BOOL8 Multiplayer();
		_H3API_ static VOID SendMessageToPlayer(LPCSTR text, INT32 player_id);
		_H3API_ static VOID SendMessageToPlayer(const H3String& text, INT32 player_id);
	};

	template<typename T>
	struct H3NetworkData
	{
		INT32   recipientId;
		h3unk32 _f_04;
		INT     msgId;
		INT     bufferSize;
		INT     _f_10;
		T data;
		_H3API_ H3NetworkData(INT32 recipient_id, INT32 msg_id, const T& data);

		_H3API_ VOID SendData(BOOL compress_data, INT32 size = -1);
	};

#pragma pack(pop) /* align-4 */

	template<typename T>
	_H3API_ H3NetworkData<T>::H3NetworkData(INT32 recipient_id, INT32 msg_id, const T& data) :
		recipientId(recipient_id), _f_04(), msgId(msg_id), bufferSize(0x14 + sizeof(T)), _f_10(), data(data)
	{
	}

	template<typename T>
	_H3API_ VOID h3::H3NetworkData<T>::SendData(BOOL compress_data, INT32 size /*= -1*/)
	{
		if (size != -1)
			bufferSize = size;
		return FASTCALL_4(INT32, 0x5549E0, this, 127, compress_data, 1);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(RandomDwelling);
	struct H3ObjectDetails;

#pragma pack(push, 4)

	struct H3RandomDwelling
	{
		_H3API_SIZE_(0x10);

		UINT32           associatedTown;
		UINT16           availableTowns;
		INT8             owner;
		UINT8            minLevel;
		UINT8            maxLevel;
		H3ObjectDetails* objectDetails;
	};
	_H3API_ASSERT_SIZE_(H3RandomDwelling);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ScenarioMapInformation);
	struct H3Hero;

#pragma pack(push, 4)

	struct H3ScenarioMapInformation : H3MapInfo
	{
		_H3API_SIZE_(0xCA4);
		H3PlayersInfo              playersInfo;
		h3unk16                    _f_4D0;
		h3unk8                     _f_4D2[30];
		INT8                       heroOwner[156];
		CHAR                       mapNameArray[61];
		CHAR                       mapDescriptionArray[300];
		FILETIME                   fileTime;
		h3unk8                     gap700[8];
		h3unk32                    _f_708;
		h3unk8                     _f_70C[4];
		H3MapInfo                  mapinfo;
		H3PlayersInfo              playersinfo;
		h3unk8                     _f_BE0[64];
		H3Vector<H3Vector<H3Hero>> heroes;
		h3unk8                     _f_C30[16];
		H3Vector<h3unk8>            _f_C40;
		H3Vector<h3unk8>            _f_C50;
		H3String                   _f_C60;
		h3unk8                     _f_C70[8];
		BOOL8                      isPlayerAbsent[8];
		h3unk32                    _f_C80[8];
		h3unk32                    _f_CA0;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioMapInformation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Spell);

#pragma pack(push, 4)

	struct H3Spell
	{
		_H3API_SIZE_(0x88);
		_H3API_GET_INFO_(0x687FA8, H3Spell);

		eSpellTarget type;
		LPCSTR soundName;
		UINT32 animationIndex;
	public:
		union
		{
			struct
			{
				BOOL8 battlefieldSpell    : 1; // [1]
				BOOL8 mapSpell            : 1; // [2]
				BOOL8 timeScale           : 1; // [4]
				BOOL8 creatureSpell       : 1; // [8]
				BOOL8 singleTarget        : 1; // [10]
				BOOL8 singleShootingStack : 1; // [20]
				BOOL8 expertMassVersion   : 1; // [40]
				BOOL8 targetAnywhere      : 1; // [80]
				BOOL8 removeObstacle      : 1; // [100]
				BOOL8 damageSpell         : 1; // [200]
				BOOL8 mindSpell           : 1; // [400]
				BOOL8 friendlyMass        : 1; // [800]
				BOOL8 cannotTargetSiege   : 1; // [1000]
				BOOL8 spellFromArtifact   : 1; // [2000]
				BOOL8 defensive           : 1; // [4000]
				BOOL8 aiDamageSpell      : 1; // [8000]
				BOOL8 aiAreaEffect        : 1; // [10000]
				BOOL8 aiMassDamageSpell  : 1; // [20000]
				BOOL8 aiNonDamageSpell   : 1; // [40000]
				BOOL8 aiCreatures         : 1; // [80000]
				BOOL8 aiAdventureMap      : 1; // [100000]
			};
			UINT32 flags;
		};

		LPCSTR name;
		LPCSTR shortName;
		INT32 level;
		eSpellchool school;
		INT32 manaCost[4];
		INT32 spEffect;
		INT32 baseValue[4];
		INT32 chanceToGet[9];
		UINT32 aiValue[4];
		LPCSTR description[4];

		_H3API_ INT32 GetBaseEffect(INT32 level, INT32 spellPower);
		_H3API_ static BOOL8 SingleTarget(INT32 id, INT32 expertise);
	};
	_H3API_ASSERT_SIZE_(H3Spell);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TurnTimer);

#pragma pack(push, 4)

	struct H3TurnTimer
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x4AD194 + 1, H3TurnTimer);

		UINT lastShownTime;
		UINT startTimeMain;
		UINT turnLimit;
		UINT showNextPeriod;
		UINT battleStartTime;
	};
	_H3API_ASSERT_SIZE_(H3TurnTimer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CustomHeroData);

#pragma pack(push, 4)

	struct H3CustomHeroData
	{
		_H3API_SIZE_(0x14);
		INT32 heroId;
		H3String name;
	};
	_H3API_ASSERT_SIZE_(H3CustomHeroData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(HeroInfo);

#pragma pack(push, 4)

	struct H3HeroInfo
	{
		_H3API_SIZE_(0x5C);
		_H3API_GET_INFO_(0x67DCE8, H3HeroInfo);

		BOOL32           isFemale;
		eHeroRace        race;
		INT32            heroClass;
		H3SecondarySkill sskills[2];
		BOOL8            hasSpellbook;
		INT32            startingSpell;
		INT32            armyType[3];
		LPCSTR           smallPortrait;
		LPCSTR           largePortrait;
		BOOL8            roeHero;
		BOOL8            expansionHero;
		BOOL8            campaignHero;
	protected:
		UINT             _f_3C; // always 0
	public:
		LPCSTR           name;
		struct StartingCreatures
		{
			INT32 lowAmount;
			INT32 highAmount;
		}creatureAmount[3];
	};
	_H3API_ASSERT_SIZE_(H3HeroInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(HeroPlaceholder);
	struct H3ObjectDetails;

#pragma pack(push, 4)

	struct H3HeroPlaceholder
	{
		_H3API_SIZE_(0x10);
		H3ObjectDetails* objectDetails;
		INT8             owner;
		INT32            type;
		UINT8            powerRating;
	};
	_H3API_ASSERT_SIZE_(H3HeroPlaceholder);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(HeroSpecialty);

#pragma pack(push, 4)

	struct H3HeroSpecialty
	{
		_H3API_SIZE_(0x28);
		_H3API_GET_INFO_(0x679C80, H3HeroSpecialty);

		eHeroSpecialty type;
		UINT32 bonusId;
		UINT32 attackBonus;
		UINT32 defenseBonus;
		UINT32 damageBonus;
		UINT32 upgrade2;
		UINT32 upgradeTo;
		LPCSTR spShort;
		LPCSTR spFull;
		LPCSTR spDescr;

		_H3API_ BOOL   HasSpellSpec() const;
		_H3API_ eSpell GetSpell() const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ScenarioHeroInfo);

#pragma pack(push, 4)

	struct H3ScenarioHeroInfo
	{
		_H3API_SIZE_(0x1C);
		INT32    heroId;
		INT32    portraitId;
		H3String name;
		H3PlayersBitfield32 availableToPlayers;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioHeroInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SpecialBuildingCosts);
	_H3API_DECLARE_(NeutralBuildingCosts);
	_H3API_DECLARE_(DwellingBuildingCosts);

#pragma pack(push, 4)

	struct H3SpecialBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1539 + 3, H3SpecialBuildingCosts);

		H3Resources cost[9];
	};

	struct H3NeutralBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1509 + 3, H3NeutralBuildingCosts);

		H3Resources cost[17];
	};

	struct H3DwellingBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1566 + 3, H3DwellingBuildingCosts);
		H3Resources cost[2][7];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CastleEvent);

#pragma pack(push, 4)

	struct H3CastleEvent : public H3GlobalEvent
	{
		_H3API_SIZE_(0x50);
		INT32 castleNumber;
		H3BuildingsBitfield buildings;
		INT16 creatures[7];
	};
	_H3API_ASSERT_SIZE_(H3CastleEvent);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3PuzzleCoordinates
	{
		_H3API_GET_INFO_(0x52CC09 + 3, H3PuzzleCoordinates);
		INT16 x[48];
		INT16 y[48];
	};

	struct H3PuzzlePiecesOrder
	{
		_H3API_GET_INFO_(0x52CBF2 + 4, H3PuzzlePiecesOrder);
		INT16 order[48];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SetupTown);

#pragma pack(push, 4)

	struct H3SetupTown
	{
		_H3API_SIZE_(0x88);
		UINT32     id;
		INT8       owner;
		BOOL8      hasCustomBuildings;
		H3Bitfield builtBuildings[2];
		H3Bitfield disabledBuildings[2];

		BOOL8      hasFort;
		BOOL8      hasCustomGarrison;
		H3Army     garrison;
		BOOL8      hasCustomName;
		H3String   name;
		INT32      type;
		INT8       creatureFormation;
		H3Bitfield possibleSpell[3];
		H3Bitfield forcedSpells[3];
	};
	_H3API_ASSERT_SIZE_(H3SetupTown);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Town);
	struct H3Hero;
	struct H3TownCreatureTypes;

#pragma pack(push, 4)

	struct H3Town
	{
		_H3API_SIZE_(0x168);

		UINT8	number;
		INT8	owner;
		BOOL8	builtThisTurn; // +2
	protected:
		h3unk8	_f_03;
	public:
		UINT8	type;
		UINT8	x;
		UINT8	y;
		UINT8	z;
		UINT8	pos2PlaceBoatX;
		UINT8	pos2PlaceBoatY;
		INT32	garrisonHero;
		INT32	visitingHero;
		INT8	mageLevel;
	protected:
		h3unk8	_f_15;
	public:
		INT16	recruits[2][7];
	protected:
		h3unk8	_f_32;
	public:
		BOOL8	manaVortexAvailable;
		INT8	mysticPondResourceCount;
		INT32	mysticPondResourceType;
		H3CreatureSlot16 summoningPortalCreature;
		INT32	spells[5][6];
		BOOL8	magicGuild[5];
		H3String name;
	protected:
		H3SpellsBitset spellsRelated;
	public:
		H3Army guards;
	protected:
		H3Army guards0;
	public:
		H3BuildingsBitfield built;
		H3BuildingsBitfield built2;
		H3BuildingsBitfield buildableMask;

		_H3API_ BOOL                 CanBeBuilt(eBuildings id) const;
		_H3API_ H3Hero*              GetGarrisonHero() const;
		_H3API_ H3String             GetNameAndType() const;
		_H3API_ LPCSTR               GetTownTypeName() const;
		_H3API_ H3Hero*              GetVisitingHero() const;
		_H3API_ INT32                GoldIncome(BOOL count_silo = FALSE) const;
		_H3API_ H3Resources&         GetResourceSiloIncome() const;
		_H3API_ H3TownCreatureTypes& GetCreatureTypes() const;
		_H3API_ BOOL                 IsBuildingBuilt(INT32 id) const;
		_H3API_ BOOL8                IsMageGuildBuilt(INT level) const;
		_H3API_ H3Resources          TotalIncome() const;
	};
	_H3API_ASSERT_SIZE_(H3Town);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TownCreatureTypes);

#pragma pack(push, 4)

	struct H3TownCreatureTypes
	{
		_H3API_SIZE_(0x38);
		_H3API_GET_INFO_(0x47AB00 + 3, H3TownCreatureTypes);
		struct iterator
		{
		protected:
			INT32* m_base;
		public:
			_H3API_ iterator(INT32* base);

			_H3API_ iterator& operator*();
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ BOOL operator==(const iterator& other) const;
			_H3API_ BOOL operator!=(const iterator& other) const;

			_H3API_ INT32& Base();
			_H3API_ INT32& Upgraded();
		};

		INT32 base[7];
		INT32 upgrade[7];

		_H3API_ iterator begin();
		_H3API_ iterator end();
	};
	_H3API_ASSERT_SIZE_(H3TownCreatureTypes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TownDependencies);

#pragma pack(push, 4)

	struct H3TownDependencies
	{
		_H3API_GET_INFO_(0x5D6015 + 3, H3TownDependencies);

		H3BuildingsBitfield m_dependency[h3::limits::BUILDINGS];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace H3Internal
    {

        typedef H3DataArrayPointer<H3ArtifactSetup>          H3ArtifactSetup_ptr;
        typedef H3DataArrayPointer<H3CmpBonusBuildingsNames> H3CmpBonusBuildingsNames_ptr;
        typedef H3DataArrayPointer<H3CreatureBankSetup>      H3CreatureBankSetup_ptr;
        typedef H3DataArrayPointer<H3CreatureInformation>    H3CreatureInformation_ptr;
        typedef H3DataArrayPointer<H3DwellingBuildingCosts>  H3DwellingBuildingCosts_ptr;
        typedef H3DataArrayPointer<H3GlobalObjectSettings>   H3GlobalObjectSettings_ptr;
        typedef H3DataArrayPointer<H3HeroInfo>               H3HeroInfo_ptr;
        typedef H3DataArrayPointer<H3HeroSpecialty>          H3HeroSpecialty_ptr;
        typedef H3DataArrayPointer<H3ObstacleInfo>           H3ObstacleInfo_ptr;
        typedef H3DataArrayPointer<H3PuzzleCoordinates>      H3PuzzleCoordinates_ptr;
        typedef H3DataArrayPointer<H3PuzzlePiecesOrder>      H3PuzzlePiecesOrder_ptr;
        typedef H3DataArrayPointer<H3SecondarySkillInfo>     H3SecondarySkillInfo_ptr;
        typedef H3DataArrayPointer<H3SpecialBuildingCosts>   H3SpecialBuildingCosts_ptr;
        typedef H3DataArrayPointer<H3Spell>                  H3Spell_ptr;
        typedef H3DataArrayPointer<H3TownCreatureTypes>      H3TownCreatureTypes_ptr;
        typedef H3DataArrayPointer<H3TownDependencies>       H3TownDependencies_ptr;
        typedef H3DataArrayPointer<H3ValidCatapultTargets>   H3ValidCatapultTargets_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ArtifactSetup_ptr          P_ArtifactSetup;
    typedef H3Internal::H3CmpBonusBuildingsNames_ptr P_CmpBonusBuildingsNames;
    typedef H3Internal::H3CreatureBankSetup_ptr      P_CreatureBankSetup;
    typedef H3Internal::H3CreatureInformation_ptr    P_CreatureInformation;
    typedef H3Internal::H3DwellingBuildingCosts_ptr  P_DwellingBuildingCosts;
    typedef H3Internal::H3GlobalObjectSettings_ptr   P_GlobalObjectSettings;
    typedef H3Internal::H3HeroInfo_ptr               P_HeroInfo;
    typedef H3Internal::H3HeroSpecialty_ptr          P_HeroSpecialty;
    typedef H3Internal::H3ObstacleInfo_ptr           P_ObstacleInfo;
    typedef H3Internal::H3PuzzleCoordinates_ptr      P_PuzzleCoordinates;
    typedef H3Internal::H3PuzzlePiecesOrder_ptr      P_PuzzlePiecesOrder;
    typedef H3Internal::H3SecondarySkillInfo_ptr     P_SecondarySkillInfo;
    typedef H3Internal::H3SpecialBuildingCosts_ptr   P_SpecialBuildingCosts;
    typedef H3Internal::H3Spell_ptr                  P_Spell;
    typedef H3Internal::H3TownCreatureTypes_ptr      P_TownCreatureTypes;
    typedef H3Internal::H3TownDependencies_ptr       P_TownDependencies;
    typedef H3Internal::H3ValidCatapultTargets_ptr   P_ValidCatapultTargets;

    typedef P_ArtifactSetup          P_Artifacts;
    typedef P_CreatureBankSetup      P_CreatureBankTable;
    typedef P_CreatureInformation    P_Creatures;
    typedef P_GlobalObjectSettings   P_ObjectSettings;
    typedef P_ObstacleInfo           P_DefObstacleInfo;
    typedef P_TownCreatureTypes      P_TownCreatureTypes;
    typedef P_TownDependencies       P_TownDependencies;

#else

#define P_ArtifactSetup          h3::H3Internal::H3ArtifactSetup_ptr()
#define P_Artifacts              h3::H3Internal::H3ArtifactSetup_ptr()
#define P_CmpBonusBuildingsNames h3::H3Internal::H3CmpBonusBuildingsNames_ptr()
#define P_CreatureBankSetup      h3::H3Internal::H3CreatureBankSetup_ptr()
#define P_CreatureBankTable      h3::H3Internal::H3CreatureBankSetup_ptr()
#define P_CreatureInformation    h3::H3Internal::H3CreatureInformation_ptr()
#define P_Creatures              h3::H3Internal::H3CreatureInformation_ptr()
#define P_DwellingBuildingCosts  h3::H3Internal::H3DwellingBuildingCosts_ptr()
#define P_GlobalObjectSettings   h3::H3Internal::H3GlobalObjectSettings_ptr()
#define P_ObjectSettings         h3::H3Internal::H3GlobalObjectSettings_ptr()
#define P_HeroInfo               h3::H3Internal::H3HeroInfo_ptr()
#define P_HeroSpecialty          h3::H3Internal::H3HeroSpecialty_ptr()
#define P_ObstacleInfo           h3::H3Internal::H3ObstacleInfo_ptr()
#define P_DefObstacleInfo        h3::H3Internal::H3ObstacleInfo_ptr()
#define P_PuzzleCoordinates      h3::H3Internal::H3PuzzleCoordinates_ptr()
#define P_PuzzlePiecesOrder      h3::H3Internal::H3PuzzlePiecesOrder_ptr()
#define P_SecondarySkillInfo     h3::H3Internal::H3SecondarySkillInfo_ptr()
#define P_SpecialBuildingCosts   h3::H3Internal::H3SpecialBuildingCosts_ptr()
#define P_Spell                  h3::H3Internal::H3Spell_ptr()
#define P_TownCreatureTypes      h3::H3Internal::H3TownCreatureTypes_ptr()
#define P_TownCreatureTypes      h3::H3Internal::H3TownCreatureTypes_ptr()
#define P_TownDependencies       h3::H3Internal::H3TownDependencies_ptr()
#define P_TownDependencies       h3::H3Internal::H3TownDependencies_ptr()
#define P_ValidCatapultTargets   h3::H3Internal::H3ValidCatapultTargets_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(BaseDlg);
	_H3API_DECLARE_(ExtendedDlg);

	struct H3DlgItem;
	struct H3LoadedPcx16;
	struct H3Msg;
	struct H3DlgDef;
	struct H3DlgPcx;
	struct H3DlgEdit;
	struct H3DlgText;
	struct H3DlgFrame;
	struct H3DlgPcx16;
	struct H3DlgTextPcx;
	struct H3DlgDefButton;
	struct H3DlgScrollbar;
	struct H3DlgTransparentItem;
	struct H3DlgCustomButton;
	struct H3DlgCaptionButton;
	struct H3DlgScrollableText;
	struct H3ScreenlogEdit;

	typedef UINT16 RGB565;
	typedef INT32(__fastcall* H3DlgButton_proc)(H3Msg*);
	typedef INT32(__fastcall* H3DlgButtonProc)(H3Msg&);
	typedef VOID(__fastcall* H3DlgScrollbar_proc)(INT32, H3BaseDlg*);
	typedef VOID(__fastcall* H3DlgScrollbarProc)(INT32,  H3BaseDlg&);

#pragma pack(push, 4)

	struct H3DlgVTable
	{
	public:
		h3func destroyDlg;
		h3func showDlg;
		h3func hideDlg;
		h3func callProcessAction;
		h3func _nullsub;
		h3func redrawDlg;
		h3func runDlg;
		h3func initDlgItems;
		h3func activateDlg;
		h3func dlgProc;
		h3func mouseMove;
		h3func rightClick;
		h3func clickRet;
		h3func _nullsub3;
		h3func closeDlg;
	};

	struct _H3API_NOVTABLE_ H3BaseDlg : H3Allocator
	{
		_H3API_SIZE_(0x4C);
		_H3API_VTABLE_(0x643CD4);
		_H3API_CTOR_DTOR_(0x5FEFB0, 0x5FF040);

	protected:
		_H3API_ virtual H3BaseDlg* vDestroy() = 0;
		_H3API_ virtual INT        vShow(INT zorder, BOOL8 draw) = 0;
		_H3API_ virtual INT        vHide(BOOL8 redrawScreen) = 0;
		_H3API_ virtual INT        vPreProcess(H3Msg& msg) = 0;
		_H3API_ virtual VOID       vParentActivate_10(H3DlgItem* unknown) = 0;
		_H3API_ virtual BOOL8      vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId) = 0;
		_H3API_ virtual INT        vShowAndRun(BOOL8 fadeIn) = 0;
		_H3API_ virtual INT        vInitiateItems() = 0;
		_H3API_ virtual INT        vActivateItems(BOOL8 increase) = 0;

		INT32                zOrder;
		H3BaseDlg*           nextDialog;
		H3BaseDlg*           lastDialog;
		INT32                flags;
		INT32                state;
		INT32                xDlg;
		INT32                yDlg;
		INT32                widthDlg;
		INT32                heightDlg;
		H3DlgItem*           lastItem;
		H3DlgItem*           firstItem;
		H3Vector<H3DlgItem*> dlgItems;
		INT32                focusedItemId;
		H3LoadedPcx16*       pcx16;
		INT32                deactivatesCount;

		_H3API_ H3DlgItem* getDlgItem(UINT16 id, h3func vtable) const;
		template<typename ItemType>
		ItemType* get(UINT16 id) const;

	public:
		_H3API_ H3BaseDlg(INT x, INT y, INT w, INT h);
		_H3API_ INT32 GetWidth() const;
		_H3API_ INT32 GetHeight() const;
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
		_H3API_ BOOL  IsTopDialog() const;
		_H3API_ VOID AddControlState(INT32 id, eControlState state);
		_H3API_ VOID RemoveControlState(INT32 id, eControlState state);

		_H3API_ H3DlgItem* AddItem(H3DlgItem* item, BOOL initiate = TRUE);
		_H3API_ VOID       Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy); // redraw part of dialog
		_H3API_ VOID       Redraw(); // redraw whole dialog
		_H3API_ INT32      DefaultProc(H3Msg* msg);
		_H3API_ INT32      DefaultProc(H3Msg& msg);

		_H3API_ H3LoadedPcx16*        GetCurrentPcx();
		_H3API_ H3Vector<H3DlgItem*>& GetList();

		_H3API_ H3DlgItem* ItemAtPosition(H3Msg* msg);
		_H3API_ H3DlgItem* ItemAtPosition(H3Msg& msg);
		_H3API_ H3DlgItem* GetH3DlgItem(UINT16 id);

		_H3API_ VOID RedrawItem(UINT16 itemID);
		_H3API_ VOID EnableItem(UINT16 id, BOOL enable);
		_H3API_ VOID SendCommandToItem(INT32 command, UINT16 itemID, UINT32 parameter);
		_H3API_ VOID SendCommandToAllItems(INT32 command, INT32 itemID, INT32 parameter);
		_H3API_ VOID AdjustToPlayerColor(INT8 player, UINT16 itemId);

		template<typename ItemType>
		ItemType* Get(UINT16 id);

		_H3API_ H3DlgDef*             GetDef(UINT16 id) const;
		_H3API_ H3DlgPcx*             GetPcx(UINT16 id) const;
		_H3API_ H3DlgEdit*            GetEdit(UINT16 id) const;
		_H3API_ H3DlgText*            GetText(UINT16 id) const;
		_H3API_ H3DlgFrame*           GetFrame(UINT16 id) const;
		_H3API_ H3DlgPcx16*           GetPcx16(UINT16 id) const;
		_H3API_ H3DlgTextPcx*         GetTextPcx(UINT16 id) const;
		_H3API_ H3DlgDefButton*       GetDefButton(UINT16 id) const;
		_H3API_ H3DlgScrollbar*       GetScrollbar(UINT16 id) const;
		_H3API_ H3DlgTransparentItem* GetTransparent(UINT16 id) const;
		_H3API_ H3DlgCustomButton*    GetCustomButton(UINT16 id) const;
		_H3API_ H3DlgCaptionButton*   GetCaptionButton(UINT16 id) const;
		_H3API_ H3DlgScrollableText*  GetScrollableText(UINT16 id) const;

		_H3API_ H3DlgTransparentItem* CreateHidden(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id);

		_H3API_ H3DlgFrame* CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color);
		_H3API_ H3DlgFrame* CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color);
		_H3API_ H3DlgFrame* CreateFrame(H3DlgItem* target, RGB565 color, INT id = 0, BOOL around_edge = false);

		_H3API_ H3DlgDef* CreateDef(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame,
			INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ H3DlgDef* CreateDef(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 group = 0,
			INT32 mirror = FALSE, BOOL closeDialog = FALSE);

		_H3API_ H3DlgDefButton* CreateButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName,
			INT32 frame, INT32 clickFrame, BOOL closeDialog = FALSE, INT32 hotkey = NULL);
		_H3API_ H3DlgDefButton* CreateButton(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame = 0, INT32 clickFrame = 1, BOOL closeDialog = FALSE, INT32 hotkey = NULL);

		_H3API_ H3DlgDefButton* CreateOKButton(INT32 x, INT32 y);
		_H3API_ H3DlgDefButton* CreateSaveButton(INT32 x, INT32 y, LPCSTR button_name = NH3Dlg::Assets::iSAVE_DEF);
		_H3API_ H3DlgDefButton* CreateOnOffCheckbox(INT32 x, INT32 y, INT32 id, INT32 frame, INT32 clickFrame = -1);
		_H3API_ H3DlgDefButton* CreateOKButton(); // adjust for hintBar
		_H3API_ H3DlgDefButton* CreateOK32Button(INT32 x, INT32 y); // height is 32
		_H3API_ H3DlgDefButton* CreateCancelButton(); // adjust for hintBar
		_H3API_ H3DlgDefButton* CreateCancelButton(INT32 x, INT32 y);

		_H3API_ H3DlgCaptionButton* CreateCaptionButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id,
			LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame,
			INT32 group = 0, BOOL closeDialog = FALSE, INT32 hotkey = NULL, INT32 color = 0);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id,
			LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);

		_H3API_ H3DlgPcx* CreatePcx(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);
		_H3API_ H3DlgPcx* CreatePcx(INT32 x, INT32 y, INT32 id, LPCSTR pcxName);

		_H3API_ H3DlgPcx* CreateLineSeparator(INT32 x, INT32 y, INT32 width);

		_H3API_ H3DlgPcx16* CreatePcx16(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);

		_H3API_ H3DlgEdit* CreateEdit(INT32 x, INT32 y, INT32 width, INT32 height, INT32 maxLength, LPCSTR text,
			LPCSTR fontName = NH3Dlg::Text::MEDIUM, INT32 color = eTextColor::REGULAR,
			INT32 align = eTextAlignment::MIDDLE_CENTER, LPCSTR pcxName = nullptr,
			INT32 id = 0, INT32 hasBorder = FALSE, INT32 borderX = 0, INT32 borderY = 0);

		_H3API_ H3DlgText* CreateText(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName,
			INT32 color, INT32 id, eTextAlignment align = eTextAlignment::MIDDLE_CENTER, INT32 bkColor = 0);

		_H3API_ H3DlgTextPcx* CreateTextPcx(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName,
			LPCSTR pcxName, INT32 color, INT32 id, INT32 align = eTextAlignment::MIDDLE_CENTER);

		_H3API_ H3DlgScrollableText* CreateScrollableText(LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR font, INT32 color, INT32 isBlue = FALSE);

		_H3API_ H3DlgScrollbar* CreateScrollbar(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc = nullptr,
			BOOL isBlue = FALSE, INT32 stepSize = 0, BOOL arrowsEnabled = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3BaseDlg);

	struct _H3API_NOVTABLE_ H3ExtendedDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x4C); // same as H3BasicDlg
		_H3API_VTABLE_(0x643CF8);
		_H3API_CTOR_DTOR_(0x5FFC00, 0x5FF040); // dtor jump from virtual table, shared with H3BasicDlg
	protected:
		_H3API_ virtual INT   vDialogProc(H3Msg& msg) = 0;
		_H3API_ virtual BOOL8 vOnMouseMove(INT32 x, INT32 y) = 0;
		_H3API_ virtual BOOL8 vOnRightClick(INT32 id) = 0;
		_H3API_ virtual BOOL8 vOnLeftClick(INT32 id, BOOL8& closeDialog) = 0;
		_H3API_ virtual H3DlgTextPcx* vGetStatusBar() = 0;
	public:
		_H3API_ H3ExtendedDlg(INT x, INT y, INT w, INT h);
	};
	_H3API_ASSERT_SIZE_(H3ExtendedDlg);

#pragma pack(pop) /* align-4 */

	template<typename ItemType>
	inline typename ItemType* H3BaseDlg::Get(UINT16 id)
	{
		return reinterpret_cast<ItemType*>(GetH3DlgItem(id));
	}
	template<typename ItemType>
	inline typename ItemType* H3BaseDlg::get(UINT16 id) const
	{
		return reinterpret_cast<ItemType*>(getDlgItem(id, ItemType::VTABLE));
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(AdventureMgrDlg);
	struct H3ResourceBarPanel;
	struct H3DlgBasePanel;

#pragma pack(push, 4)

	struct H3AdventureMgrDlg : H3BaseDlg
	{
		_H3API_SIZE_(0xA0);
		_H3API_VTABLE_(0x63A5E4);

		H3DlgTransparentItem* minimapTransparentOverlay;
		H3DlgTransparentItem* mapTransparentOverlay;
		H3DlgText*            text;
		H3ScreenlogEdit*      screenlogEdit;
		H3ResourceBarPanel*   resourceBar;
		H3DlgTextPcx*         hintbar;
		INT32                 topHeroSlotIndex;
		h3unk32               _f_68;
		h3unk8                _f_6C;
		H3DlgPcx*             heroPcx[5];
		H3DlgPcx*             heroPcx2[5];
		H3DlgBasePanel*       panel;
		h3unk32               _f_9C;
	};
	_H3API_ASSERT_SIZE_(H3AdventureMgrDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgBasePanel);

	struct H3BaseDlg;
	struct H3DlgItem;
	struct H3LoadedPcx16;

#pragma pack(push, 4)

	struct H3DlgBasePanel : H3Allocator
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x64235C);
	protected:
		_H3API_ virtual H3DlgBasePanel* vDestroy(BOOL8 deallocate) = 0;
		_H3API_ virtual VOID            vFunc04(INT unknown) = 0;
		_H3API_ virtual VOID            vFunc08(INT unknown1, INT unknown2) = 0;
		_H3API_ virtual VOID            vDrawToWindow() = 0;

		INT32                x;
		INT32                y;
		INT32                width;
		INT32                height;
		H3Vector<H3DlgItem*> items;
		H3BaseDlg*           parent;
		INT32                largestId;
		INT32                smallestId;
		H3LoadedPcx16*       backupPcx;

		_H3API_ VOID backupScreen();
		_H3API_ VOID restoreBackupScreen();
	public:
		_H3API_ H3Vector<H3DlgItem*>& GetItems();

		_H3API_ H3DlgItem* AddItem(H3DlgItem* item);
		_H3API_ VOID Redraw();
		_H3API_ VOID Hide();
		_H3API_ VOID Show();
		_H3API_ VOID Move(INT xDest, INT yDest);
		_H3API_ VOID MoveRelative(INT xDelta, INT yDelta);

		_H3API_ INT32 GetWidth() const;
		_H3API_ INT32 GetHeight() const;
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
	};
	_H3API_ASSERT_SIZE_(H3DlgBasePanel);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3CombatBottomPanel;
	struct H3CombatMonsterPanel;
	struct H3CombatHeroPanel;
	struct H3String;

#pragma pack(push, 4)

	struct H3CombatDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x8C);
	protected:
		h3unk32               _f_4C;
		H3DlgEdit*            editText;
		H3Vector<H3String*>   combatText;
		UINT                  lastTimeStamp;
		h3unk32               _f_68;
		UINT                  timeHint;
	public:
		H3CombatBottomPanel*  bottomPanel;
		H3CombatHeroPanel*    leftHeroPopup;
		H3CombatHeroPanel*    rightHeroPopup;
		H3CombatMonsterPanel* leftMonsterPopup;
		H3CombatMonsterPanel* rightMonsterPopup;
		H3CombatMonsterPanel* bottomleftMonsterPopup;
		H3CombatMonsterPanel* bottomRightMonsterPopup;

		_H3API_ VOID ShowHint(LPCSTR hint, BOOL8 add_to_log = FALSE);
		_H3API_ H3Vector<H3String*>& GetCombatText();
	};
	_H3API_ASSERT_SIZE_(H3CombatDlg);

	struct H3CombatBottomPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x40);
	protected:
		H3DlgTextPcx*      commentBar;  /**< @brief [34]*/
		H3DlgCustomButton* commentUp;   /**< @brief [38]*/
		H3DlgCustomButton* commentDown; /**< @brief [3C]*/
	public:
	};
	_H3API_ASSERT_SIZE_(H3CombatBottomPanel);

	struct H3CombatHeroPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x5C);
	protected:
		H3DlgPcx*  background;  /**< @brief [34]*/
		H3DlgPcx*  hero;        /**< @brief [38]*/
		H3DlgText* attack;      /**< @brief [3C]*/
		H3DlgText* defense;     /**< @brief [40]*/
		H3DlgText* power;       /**< @brief [44]*/
		H3DlgText* knowledge;   /**< @brief [48]*/
		H3DlgDef*  morale;      /**< @brief [4C]*/
		H3DlgDef*  luck;        /**< @brief [50]*/
		H3DlgText* spellPoints; /**< @brief [54]*/
		BOOL8      needsRedraw; /**< @brief [58]*/
	public:
	};
	_H3API_ASSERT_SIZE_(H3CombatHeroPanel);

	struct H3CombatMonsterPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x70);
	protected:
		H3DlgPcx*  background;    /**< @brief [34]*/
		H3DlgDef*  creature;      /**< @brief [38]*/
		H3DlgText* attack;        /**< @brief [3C]*/
		H3DlgText* defense;       /**< @brief [40]*/
		H3DlgText* damage;        /**< @brief [44]*/
		H3DlgText* health;        /**< @brief [48]*/
		H3DlgDef*  morale;        /**< @brief [4C]*/
		H3DlgDef*  luck;          /**< @brief [50]*/
		H3DlgText* numberAlive;   /**< @brief [54]*/
		H3DlgDef*  spells[3];     /**< @brief [58]*/
		H3DlgText* noActiveSpell; /**< @brief [64]*/
		BOOL8      needsRedraw;   /**< @brief [68]*/
		INT32      type;          /**< @brief [6C] 1 or 2 ?*/
	public:

	};
	_H3API_ASSERT_SIZE_(H3CombatMonsterPanel);

	struct H3BattleOptionsDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x50);
		_H3API_GET_INFO_(0x694FE0, H3BattleOptionsDlg);
		_H3API_CTOR_DTOR_(0x46DF00, 0x46F250);
		_H3API_VTABLE_(0x63D448);

		BOOL8 optionsModified;
	};
	_H3API_ASSERT_SIZE_(H3BattleOptionsDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)
	struct _H3API_NOVTABLE_ H3NetworkDlg : H3ExtendedDlg
	{
		_H3API_SIZE_(0x60); // was 0x68 with 8 unknown bytes, seem only relevant to specialized dialogs
		_H3API_VTABLE_(0x63A6A8);
		_H3API_CTOR_DTOR_(0x41AFA0, 0x41B080);
	protected:
		_H3API_ virtual INT vEndDialogOnTimeExpired(H3Msg& msg) = 0;

		INT32 lastHintShowed;
		INT32 exitCommand;
		INT32 exitSubtype;
		INT32 resultItemId;
		BOOL8 networkGame;
	public:
		_H3API_ H3NetworkDlg(INT x, INT y, INT w, INT h);
	};
	_H3API_ASSERT_SIZE_(H3NetworkDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3CreatureInfoDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0xB8);

		INT32         creatureId;
		INT32         numberCreatures;
		INT32         morale;
		H3String      moraleModifiers;
		INT32         luck;
		H3String      luckModifiers;
		h3unk8        _f_90[32];
		H3DlgTextPcx* varBackPcx;
		H3DlgDef*     animation;
	};
	_H3API_ASSERT_SIZE_(H3CreatureInfoDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Dlg);
	class  H3DlgHintBar;
	struct H3LoadedDef;
	struct H3LoadedPcx;
	struct H3LoadedPcx24;
	struct H3Msg;

#pragma pack(push, 4)

#pragma warning(push)
#pragma warning(disable : 4482)
	struct H3Dlg : H3NetworkDlg
	{
		static constexpr DWORD DOUBLE_CLICK_SPEED = 400;

	protected:

		_H3API_ virtual H3Dlg* vDestroy() override;
		_H3API_ virtual INT vShow(INT zorder, BOOL8 draw) override;
		_H3API_ virtual INT vHide(BOOL8 redrawScreen) override;
		_H3API_ virtual INT vPreProcess(H3Msg& msg) override;
		_H3API_ virtual VOID vParentActivate_10(H3DlgItem* unknown) override;
		_H3API_ virtual BOOL8 vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId) override;
		_H3API_ virtual INT vShowAndRun(BOOL8 fadeIn) override;
		_H3API_ virtual INT vInitiateItems() override;
		_H3API_ virtual INT vActivateItems(BOOL8 increase) override;
		_H3API_ virtual INT vDialogProc(H3Msg& msg) override;
		_H3API_ virtual BOOL8 vOnMouseMove(INT32 x, INT32 y) override;
		_H3API_ virtual BOOL8 vOnRightClick(INT32 id) override;
		_H3API_ virtual BOOL8 vOnLeftClick(INT32 id, BOOL8& closeDialog) override;
		_H3API_ virtual H3DlgTextPcx* vGetStatusBar() override;
		_H3API_ virtual INT vEndDialogOnTimeExpired(H3Msg& msg) override;

	public:

		virtual _H3API_ VOID OnOK();
		virtual _H3API_ VOID OnCancel();
		virtual _H3API_ VOID OnClose(INT itemId);

		virtual _H3API_ BOOL OnCreate();

		virtual _H3API_ BOOL DialogProc(H3Msg& msg);
		virtual _H3API_ BOOL OnLeftClick(INT itemId, H3Msg& msg);
		virtual _H3API_ BOOL OnLeftClickOutside();
		virtual _H3API_ BOOL OnRightClick(H3DlgItem* it);
		virtual _H3API_ BOOL OnRightClickOutside();
		virtual _H3API_ BOOL OnMouseWheel(INT direction);
		virtual _H3API_ BOOL OnWheelButton(H3DlgItem* it);
		virtual _H3API_ BOOL OnMouseHover(INT32 x, INT32 y);
		virtual _H3API_ BOOL OnMouseHover(H3DlgItem* it);
		virtual _H3API_ BOOL OnKeyPress(eVKey key, eMsgFlag flag);
		virtual _H3API_ BOOL OnKeyHeld(eVKey key, eMsgFlag flag);
		virtual _H3API_ BOOL OnDoubleClick(INT itemId, H3Msg& msg);

		virtual _H3API_ BOOL OnNotify(H3DlgItem* it, H3Msg& msg);
	protected:
		BOOL           enableDoubleClick; // disabled by default, you have to enable it to use
		DWORD          lastClickTime;     // used to detect double-click
		H3DlgItem*     lastClickedItem;   // used to detect double-click
		BOOL           endDialog;
		H3LoadedPcx16* background;
		H3DlgHintBar*  hintBar;

		_H3API_ INT CheckEnd(H3Msg& msg);

	public:
		_H3API_ H3Dlg(int width, int height, int x = -1, int y = -1, BOOL statusBar = FALSE,
			BOOL makeBackground = TRUE, INT32 colorIndex = IntAt(0x69CCF4));
		_H3API_ ~H3Dlg();
		_H3API_ VOID  PlaceAtMouse();
		_H3API_ VOID  Start();
		_H3API_ VOID  Stop();
		_H3API_ VOID  RMB_Show();
		_H3API_ BOOL  AddBackground(INT32 x, INT32 y, INT32 w, INT32 h, BOOL frame,
			BOOL statusBar, INT32 colorIndex, BOOL is_blue = FALSE);
		_H3API_ BOOL  AddBackground(BOOL frame, BOOL statusBar, INT32 colorIndex);
		_H3API_ BOOL  AddBackground(H3LoadedPcx* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedPcx16* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedPcx24* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedDef* def, INT group = 0, INT frame = 0);

		_H3API_ BOOL Notify(H3DlgItem* it, H3Msg& msg);
		_H3API_ VOID EnableDoubleClick(BOOL state);
		_H3API_ H3LoadedPcx16* GetBackgroundPcx() const;
		_H3API_ BOOL BackgroundRegion(INT32 xStart, INT32 yStart, INT32 w, INT32 h, BOOL is_blue = FALSE);
		_H3API_ BOOL SimpleFrameRegion(INT32 xStart, INT32 yStart,
			INT32 width, INT32 height, H3LoadedPcx16* destination = nullptr);
		_H3API_ BOOL FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar,
			INT32 colorIndex, BOOL is_blue = FALSE);

		_H3API_ H3DlgHintBar* GetHintBar();
		_H3API_ BOOL CreateBlackBox(INT32 x, INT32 y, INT32 width, INT32 height);
		_H3API_ H3DlgHintBar* CreateHint();
		_H3API_ H3DlgHintBar* CreateHint(INT32 x, INT32 y, INT32 width, INT32 height);
	};
#pragma warning(pop)

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(HiScoreDlg);
	struct H3LoadedPcx;

#pragma pack(push, 4)

	struct H3HiScoreDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x110);
		_H3API_GET_INFO_(0x699210, H3HiScoreDlg);
		_H3API_VTABLE_(0x63EB98);
		_H3API_CTOR_DTOR_(0x4E9960, -1);

		H3DlgDef* campaignCreatureDefs[11];
		H3DlgDef* scenarioCreatureDefs[11];
		h3unk8 _f_A4[88];
		BOOL8 showingSingleScenarios;
		h3unk32 f100;
		UINT32 time;
		H3LoadedPcx* campaignPcx;
		H3LoadedPcx* scenarioPcx;

		_H3API_ static VOID Show();
	};
	_H3API_ASSERT_SIZE_(H3HiScoreDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

	_H3API_DECLARE_(Msg);
	struct H3BaseDlg;
	struct H3DlgItem;

#pragma pack(push, 4)

	struct H3Msg
	{
		_H3API_SIZE_(0x20);

		eMsgCommand command;
		eMsgSubtype subtype;
		INT32 itemId;
		eMsgFlag    flags;
		H3POINT     position;
		VOID*       parameter;
		PVOID       parentDlg;

		_H3API_ VOID       SetCommand(eMsgCommand command, eMsgSubtype subtype, INT32 item_id, eMsgFlag flags,
									  INT32 x, INT32 y, INT32 param, INT32 flags2);
		_H3API_ VOID       SetCommand(INT32 cmd, INT32 param);
		_H3API_ H3DlgItem* ItemAtPosition(H3BaseDlg* dlg) const;
		_H3API_ INT32      KeyPressed()     const;
		_H3API_ BOOL       IsKeyPress()     const;
		_H3API_ BOOL       IsKeyDown()      const;
		_H3API_ BOOL       IsKeyHeld()      const;
		_H3API_ BOOL       IsMouseOver()    const;
		_H3API_ BOOL       IsWheelButton()  const;
		_H3API_ BOOL       IsLeftClick()    const;
		_H3API_ BOOL       IsLeftDown()     const;
		_H3API_ BOOL       IsRightClick()   const;
		_H3API_ BOOL       ClickOutside()   const;
		_H3API_ BOOL       IsAltPressed()   const;
		_H3API_ BOOL       IsCtrlPressed()  const;
		_H3API_ BOOL       IsShiftPressed() const;
		_H3API_ INT32      CloseDialog();

		_H3API_ BOOL       AltPressed()    const;
		_H3API_ BOOL       CtrlPressed()   const;
		_H3API_ BOOL       ShiftPressed()  const;

		_H3API_ eMsgFlag   GetFlag()   const;
		_H3API_ eVKey      GetKey()    const;
		_H3API_ INT        GetX()      const;
		_H3API_ INT        GetY()      const;
		_H3API_ H3POINT    GetCoords() const;
		_H3API_ H3BaseDlg* GetDlg() const;

		_H3API_ INT StopProcessing();
	};
	_H3API_ASSERT_SIZE_(H3Msg);
#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(PictureCategories);
	_H3API_DECLARE_(Messagebox);
	struct H3String;
	template<typename _Elem> struct H3Vector;

	typedef H3Vector<H3PictureCategories> H3PictureVector;

#pragma pack(push, 4)

	struct H3PictureCategories
	{
		_H3API_SIZE_(8);

		_H3API_ H3PictureCategories();
		_H3API_ H3PictureCategories(ePictureCategories type, INT32 subtype);
		_H3API_ H3PictureCategories(const H3PictureCategories& other);
		_H3API_ H3PictureCategories& operator=(const H3PictureCategories& other);

		_H3API_ static H3PictureCategories Artifact(eArtifact id);
		_H3API_ static H3PictureCategories Building(eTown town_type, eBuildings building_id);
		_H3API_ static H3PictureCategories Creature(eCreature id, UINT16 amount);
		_H3API_ static H3PictureCategories Experience(INT32 amount);
		_H3API_ static H3PictureCategories Luck(INT32 amount);
		_H3API_ static H3PictureCategories Money(INT32 amount);
		_H3API_ static H3PictureCategories Morale(INT32 amount);
		_H3API_ static H3PictureCategories Player(ePlayer id);
		_H3API_ static H3PictureCategories PrimarySkill(ePrimary skill_type, INT8 amount);
		_H3API_ static H3PictureCategories Resource(eResource type, INT32 amount);
		_H3API_ static H3PictureCategories SecSkill(eSecondary skill, eSecSkillLevel level);
		_H3API_ static H3PictureCategories Spell(eSpell id);
		_H3API_ static H3PictureCategories SpellPoints(INT32 amount);

		ePictureCategories type;
		INT32              subtype;
	};
	_H3API_ASSERT_SIZE_(H3PictureCategories);

	struct H3Messagebox
	{
		_H3API_ H3Messagebox();
		_H3API_ H3Messagebox(LPCSTR message);
		_H3API_ H3Messagebox(const H3String& message);

		enum ePick
		{
			LEFT  = -1,
			NONE  = 0,
			RIGHT = 1,
		};
		_H3API_ static VOID  Display(const H3PictureVector& images, INT32 timeout = 0);
		_H3API_ static VOID  Display(LPCSTR text, const H3PictureVector& images, INT32 timeout = 0);
		_H3API_ static VOID  Display(const H3String& text, const H3PictureVector& images, INT32 timeout = 0);
		_H3API_ static VOID  Show(  const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID  Show(  LPCSTR text,
								    const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID  Show(  const H3String& text,
								    const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static BOOL  Choice(const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static BOOL  Choice(LPCSTR text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static BOOL  Choice(const H3String& text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID  RMB(	const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID  RMB(	LPCSTR text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID  RMB(	const H3String& text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static ePick Take(  const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		_H3API_ static ePick Take(  LPCSTR text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		_H3API_ static ePick Take(  const H3String& text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		_H3API_ static ePick Choose(const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		_H3API_ static ePick Choose(LPCSTR text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		_H3API_ static ePick Choose(const H3String& text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);

	protected:

		enum eButtonType
		{
			OK          = 1,
			OK_CANCEL   = 2,
			RIGHT_CLICK = 4,
			TAKE        = 7,
			OPTION      = 10,
		};

		_H3API_ static VOID show(LPCSTR text, eButtonType type,
			const H3PictureCategories& pic1 = H3PictureCategories(),
			const H3PictureCategories& pic2 = H3PictureCategories(),
			const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static BOOL choice(LPCSTR text,
			const H3PictureCategories& pic1 = H3PictureCategories(),
			const H3PictureCategories& pic2 = H3PictureCategories(),
			const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID display(LPCSTR text, const H3PictureVector& images, INT32 timeout);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(OracleDlg);
	struct H3ResourceBarPanel;
	struct H3LoadedPcx;

#pragma pack(push, 4)

	struct H3OracleDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0x12C);
		_H3API_VTABLE_(0x640610);
		_H3API_CTOR_DTOR_(0x52C6C0, 0x52CA80);

		h3unk32 _f_60;
		H3ResourceBarPanel* resourcesBar;
		H3LoadedPcx* puzzlePieces[48];
		INT32 townType;
	};
	_H3API_ASSERT_SIZE_(H3OracleDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ResourceBarPanel);
	struct H3DlgText;
	struct H3DlgPcx;

#pragma pack(push, 4)

	struct H3ResourceBarPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x78);
		_H3API_VTABLE_(0x641034);
		_H3API_CTOR_DTOR_(0x558DF0, -1);
		BOOL8      useKRESBAR;
		H3DlgText* resourceText[7];
		H3DlgItem* resourceOverlay[7];
		H3DlgPcx*  resbarPCX;
		H3DlgText* currentDayText;
	};
	_H3API_ASSERT_SIZE_(H3ResourceBarPanel);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ScreenChat);
	struct H3ScreenchatEdit;
	struct H3WavFile;
	struct H3String;

#pragma pack(push, 4)

	struct H3ScreenChat
	{
		_H3API_SIZE_(0x44);
		_H3API_GET_INFO_(0x405F27 + 1, H3ScreenChat);
		_H3API_CTOR_DTOR_(0x5525C4, 0x552640);

		struct ChatEntry
		{
			_H3API_SIZE_(0x88);
			CHAR   text[128];
			UINT32 showTime;
			BOOL8  flag;
		};
		struct UnkEntry
		{
			_H3API_SIZE_(0x7F);
			h3unk8 unk[0x7F];
		};

		ChatEntry* entries;
		INT32      firstItemShift;
		INT32      currentlyShown;
		UnkEntry*  items;
		UINT32     time;
		BOOL8      redraw;
		H3ScreenchatEdit* dlgEdit;
		INT32      maxItemNum;
		INT32      lastDrawn;
		h3unk8     field_24;
		h3unk32    sound_f_28;
		BOOL8      flag;
		H3WavFile* chatWav;
		H3WavFile* playexitWav;
		H3WavFile* sysmsgWav;
		H3WavFile* timeoverWav;
		H3WavFile* playcomeWav;

		_H3API_ BOOL8 CheckExpiry();
		_H3API_ VOID  Clear();
		_H3API_ VOID  ShowVA(LPCSTR format, ...);
		_H3API_ VOID  Show(LPCSTR text);
		_H3API_ VOID  Show(const H3String& text);
		_H3API_ VOID  CheckTimeUpdate();
		_H3API_ VOID  SetCurrentTime();
	};
	_H3API_ASSERT_SIZE_(H3ScreenChat);
	_H3API_ASSERT_SIZE_(H3ScreenChat::ChatEntry);
	_H3API_ASSERT_SIZE_(H3ScreenChat::UnkEntry);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ScenarioPlayer);

#pragma pack(push, 4)
	struct H3ScenarioPlayer
	{
		_H3API_SIZE_(0x7C);
		_H3API_CTOR_DTOR_(0x57CB10, -1);
		INT32   player;
		CHAR    name[24];
		INT32*  gameVersionPtr;
		INT32   gameVersion;
		INT32   town;
		INT32   heroesCount;
		INT32   heroes[16];
		INT32   bonusType;
		h3unk32 player2;
		h3unk32 _f_74;
		h3unk8  _f_78;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioPlayer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SelectScenarioDialog);
	struct H3LoadedDef;
	struct H3LoadedPcx;

#pragma pack(push, 4)
	struct H3SelectScenarioDialog : H3NetworkDlg
	{
		_H3API_SIZE_(0x1970);
		_H3API_VTABLE_(0x641CBC);
		_H3API_GET_INFO_(0x69FC44, H3SelectScenarioDialog);
		UINT32                     lastLeftClickTime;
		h3unk8                     isCampaignMaybe;
		h3unk8                     isLoadingMaybe;
		h3unk8                     _f_66;
		h3unk32                    _f_68;
		H3LoadedDef*               scselcDef;
		H3LoadedDef*               scnrvictDef;
		H3LoadedDef*               scnrlossDef;
		H3LoadedDef*               itpaDef;
		H3LoadedDef*               scnrstarDef;
		H3LoadedDef*               un44Def;
		h3unk32                    _f_84;
		H3LoadedPcx*               playerFlagsPcx[8];
		H3LoadedPcx*               playerInfoBarPcx[8];
		H3LoadedPcx*               heroSmallPortraitsPcx[limits::TOTAL_HEROES];
		H3LoadedPcx*               hpsrandPcx;
		h3unk8                     _f_358[4];
		H3LoadedPcx*               hpsrand0Pcx;
		H3LoadedPcx*               hpsrand1Pcx;
		h3unk32                    _f_364;
		H3LoadedPcx*               hpsrand6Pcx;
		h3unk8                     _f_36C;
		UINT32                     mapListNumberTop;
		UINT32                     selectedMapIndex;
		UINT32                     turnDuration;
		BOOL8                      mapSelectShown;
		BOOL8                      mapListShown;
		BOOL8                      rmgSettingsShown;
		h3unk8                     _f_37F;
		H3DlgEdit*                 edit380;
		h3unk32                    _f_384;
		h3unk32                    _f_388;
		H3ScenarioMapInformation   mapInfo;
		H3Vector<H3ScenarioMapInformation> vector1030;
		H3Vector<H3ScenarioMapInformation> vector1040;
		H3Vector<H3ScenarioMapInformation> mapsInformation;
		H3ScenarioMapInformation*  mapsInfoPtr;
		H3ScenarioPlayer           mapPlayersHuman[8];
		H3ScenarioPlayer           mapPlayersComputer[8];
		h3unk32                    _f_1824;
		h3unk32                    _f_1828;
		h3unk32                    _f_182C;
		h3unk32                    _f_1830;
		h3unk8                     _f_1834;
		H3DlgScrollbar*            scrollBar1838;
		H3DlgScrollbar*            scrollBar183C;
		H3DlgScrollbar*            turnDurationScroll;
		h3unk32                    _f_1844;
		H3DlgText*                 text1848;
		H3DlgText*                 text184C;
		H3DlgText*                 text1850;
		BOOL8                      newMapSelected;
		H3DlgEdit*                 edit1858;
		h3unk32                    _f_185C;
		h3unk32                    _f_1860;
		h3unk8                     _f_1864;
		h3unk8                     _f_1865;
		H3DlgDefButton*            button1868;
		h3unk8                     _f_186C;
		H3LoadedPcx16*             extendedPcx;
		CHAR                       gameVersionName[20];
		h3func*                    newGameCampaignVtable;
		h3unk8                     _f_188C[8];
		h3unk8                     _f_1894;
		INT32                      gameVersion;
		h3unk32                    _f_189C;
		UINT32                     mapDimension;
		INT32                      numberLevels;
		INT32                      numberPlayersSelected;
		h3unk32                    _f_18AC;
		INT32                      computerPlayersOnlySelected;
		h3unk32                    _f_18B4;
		INT32                      waterContentSelected;
		INT32                      monsterStrengthSelected;
		H3DlgDefButton*            humanComputerButtons[9];
		H3DlgDefButton*            humanComputerTeamsButtons[9];
		H3DlgDefButton*            computerOnlyButtons[9];
		H3DlgDefButton*            computerOnlyTeams[8];
		H3DlgDefButton*            waterContentButtons[4];
		H3DlgDefButton*            monsterStrengthButtons[4];
		H3DlgScrollableText*       textScroll;

		_H3API_ H3ScenarioMapInformation& CurrentMap();
		_H3API_ VOID UpdateForSelectedScenario(INT32 index, BOOL8 redraw);
		_H3API_ VOID Redraw();
	};
	_H3API_ASSERT_SIZE_(H3SelectScenarioDialog);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TownAlignmentDlg);

#pragma pack(push, 4)

	struct H3TownAlignmentDlg : H3Allocator
	{
		_H3API_SIZE_(0x58);
		_H3API_VTABLE_(0x641AA0);
		_H3API_CTOR_DTOR_(0x5761A0, 0x48FA10);
	private:
		H3DlgVTable* vtable;
		h3align      data[H3BaseDlg::SIZE - 4]; // -4 for vtable
		h3unk32      _f_4C;
		h3unk32      _f_50;
		BOOL8        isCampaign; // random guess
	public:
		_H3API_ H3TownAlignmentDlg(INT32 town);
		_H3API_ ~H3TownAlignmentDlg();
	};
	_H3API_ASSERT_SIZE_(H3TownAlignmentDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TownDlg);

#pragma pack(push, 4)

	struct H3TownDialog : H3BaseDlg
	{
		_H3API_SIZE_(0xB4);
		INT32      townIndex;
		RGB565*    drawBuffer;
		H3DlgDef*  creaturePortraits[8];
		H3DlgText* creaturesText[8];
		INT32      creatureTypes[8];
	};
	_H3API_ASSERT_SIZE_(H3TownDialog);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct HDDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0x74);

		typedef INT32(__stdcall* HDDlg_proc)(HDDlg*, const H3Msg&);
	protected:
		h3unk _f_60[0x10];
		HDDlg_proc hdProc;
	public:
		_H3API_ INT CallHDProc(const H3Msg& msg);
	};
	_H3API_ASSERT_SIZE_(HDDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(Manager);
	struct H3Msg;

#pragma pack(push, 4)

	struct H3Manager : public H3Uncopyable
	{
		_H3API_SIZE_(0x38);
		_H3API_CTOR_DTOR_(0x44D200, -1);

		enum eType : INT32
		{
			BASE_MANAGER      = -1,
			INPUT_MANAGER     = 0x4,
			SOUND_MANAGER     = 0x10,
			WINDOW_MANAGER    = 0x20,
			MOUSE_MANAGER     = 0x40,
			SWAP_MANAGER      = 0x100,
			COMBAT_MANAGER    = 0x200,
			ADVENTURE_MANAGER = 0x400,
			TOWN_MANAGER      = 0x800,
			RECRUIT_MANAGER   = 0x4000,
		};

		enum eStatus : INT32
		{
			DESTROYED = 0,
			ACTIVE    = 1,
			DISABLED  = 2,
		};

		struct ManagerVTable
		{
			h3func start;
			h3func stop;
			h3func processMessage;
		};
	protected:
		ManagerVTable *vtable;
	public:
		_H3API_ INT32 Start(INT32 z_order);
		_H3API_ VOID  Stop();
		_H3API_ INT32 ProcessMessage(H3Msg& msg);

		H3Manager* parent;
		H3Manager* child;
		eType      type;
		INT32      zOrder;
		CHAR       name[28];
		INT32      nameEnd;
		eStatus    status;

		_H3API_ VOID SetPreviousManager(H3Manager* prev);
		_H3API_ VOID SetNextManager(H3Manager* next);
	};
	_H3API_ASSERT_SIZE_(H3Manager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3MapItem;
	struct H3MainSetup;
	struct H3Msg;
	struct H3LoadedDef;
	struct H3WavFile;
	_H3API_DECLARE_(AdventureManager);

#pragma pack(push, 4)

	struct H3AdventureManager : public H3Manager
	{
		_H3API_SIZE_(0x3B8);
		_H3API_VTABLE_(0x63A678);
		_H3API_GET_INFO_(0x6992B8, H3AdventureManager);
		enum ePanel
		{
			PHERO = 3,
			PTOWN = 4,
		};

	protected:
		h3unk32 _f_038; // mplay object
	public:
		BOOL8 showFPS;
	protected:
		h3unk32 _f_040;
	public:
		struct H3Dlg* dlg;
		UINT16* arrowPathFrames;
	protected:
		h3unk8 _f_04C[4];
	public:
		BOOL movementCalculated;
		BOOL movementCalculated1;
	protected:
		h3unk8 _f_058[4];
	public:
		H3MainSetup* map;
		H3LoadedDef* terrainDef[10];
	protected:
		h3unk8 _f_088[4];
	public:
		H3LoadedDef* riverDef[4];
	protected:
		h3unk8 _f_09C[4];
	public:
		H3LoadedDef* roadDef[3];
		H3LoadedDef* edgDef;
		H3LoadedDef* adagDef;
		H3LoadedDef* agemulDef;
		H3LoadedDef* agemurDef;
		H3LoadedDef* agemllDef;
		H3LoadedDef* agemlrDef;
		H3LoadedDef* tshrcDef;
		H3LoadedDef* radarDef;
		H3LoadedDef* tshreDef;
		H3Vector<H3LoadedDef*> defs;
		H3LoadedDef* attackDEF;
		H3Position screenPosition;
		H3Position mousePosition;
		POINT previousMousePosition;
	protected:
		h3unk8 _f_0F4[24];
	public:
		H3LoadedDef* heroDef[18];
		H3LoadedDef* boatDef[3];
		H3LoadedDef* boatMovementDef[3];
		H3LoadedDef* heroFlags00[8];
		H3LoadedDef* heroFlags01[8];
		H3LoadedDef* heroFlags02[8];
		H3LoadedDef* heroFlags03[8];
		BOOL8 drawTransparentHero;
		INT32 terrain;
		INT32 heroDirection;
	protected:
		h3unk8 _f_1F8[4];
	public:
		INT32 heroDefGroup;
	protected:
		h3unk8 _f_200[12];
	public:
		BOOL8 centeredHero;
	protected:
		h3unk8 _f_20D[11];
	public:
		INT32 monsterTypeBattle;
		INT32 monsterCountBattle;
		INT32 monsterSideBattle;
	protected:
		h3unk8 _f_224[4];
	public:
		struct {
			INT32 loopSound; // index of looped sound
			INT32 volume;
		} currentSounds[4];
		H3WavFile* loopSounds[70];
		H3WavFile* horseXYSounds[11];
	protected:
		h3unk8 _f_38C[8];
	public:
		INT32 currentInfoPanel;
	protected:
		h3unk8 _f_398[32];
	public:

		_H3API_ H3MapItem* GetMapItem();
		_H3API_ H3MapItem* GetMapItem(UINT32 mixedPos);
		_H3API_ H3MapItem* GetMapItem(const H3Position& p);
		_H3API_ H3MapItem* GetMapItem(const H3Point& p);
		_H3API_ H3MapItem* GetMapItem(INT32 x, INT32 y, INT32 z);
		_H3API_ UINT8      GetX();
		_H3API_ UINT8      GetY();
		_H3API_ UINT8      GetZ();
		_H3API_ VOID       FullUpdate();
		_H3API_ VOID       MobilizeHero();
		_H3API_ VOID       DemobilizeHero();
		_H3API_ VOID       MovementCalculationsMouse();
		_H3API_ VOID       MovementCalculations(UINT32 mixedPosition);
		_H3API_ VOID       MakeHeroPath();
		_H3API_ VOID       ShowCoordinates(UINT32 x, UINT32 y, UINT8 z);
		_H3API_ INT        SimulateMouseOver(INT x, INT y);
		_H3API_ INT        SimulateMouseOver(POINT& p);
		_H3API_ CHAR       UpdateHintMessage();
		_H3API_ H3Point    GetCoordinates(H3MapItem* item);
		_H3API_ VOID       StopSound(H3WavFile* wav);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
		_H3API_ H3Map<UINT16>        GetPathMap();
		_H3API_ H3FastMap<UINT16>    GetPathFastMap();
		_H3API_ INT32 Close(H3Msg& msg);
	};
	_H3API_ASSERT_SIZE_(H3AdventureManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(CombatManager);
	struct H3LoadedPcx16;
	struct H3MapItem;
	struct H3Msg;
	struct H3Town;
	struct H3Hero;
	struct H3LoadedDef;
	struct H3DefFrame;
	struct H3Army;
	struct H3Obstacle;
	struct H3Spell;
	struct H3LoadedPcx;
	struct H3CombatCreature;

#pragma pack(push, 4)

	struct H3CombatManager : public H3Manager
	{
		_H3API_SIZE_(0x140EC);
		_H3API_VTABLE_(0x63D3E8);
		_H3API_GET_INFO_(0x699420, H3CombatManager);

	protected:
		h3unk8 _f_0038[4];
	public:
		eCombatAction action;
		INT32 actionParameter;
		INT32 actionTarget;
		INT32 actionParameter2;
		INT8 accessibleSquares[187];
		eCombatSquareAccess accessibleSquares2[187];
		H3CombatSquare squares[187];
		INT32 landType;
	protected:
		h3unk8 _f_5398[8];
	public:
		INT32 absoluteObstacleId;
		INT32 siegeKind;
		INT32 hasMoat;
	protected:
		h3unk8 _f_53AC[4];
	public:
		H3LoadedPcx16* drawBuffer;
	protected:
		h3unk8 _f_53B4[4];
	public:
		BOOL doNotDrawShade;
		H3MapItem* mapitem;
		INT32 specialTerrain;
		BOOL8 antiMagicGarrison;
		BOOL8 creatureBank;
		BOOL8 boatCombat;
		H3Town* town;
		H3Hero* hero[2];
		INT32 heroSpellPower[2];
	protected:
		h3unk8 _f_53DC[8];
		UINT32 HeroAnimation[2];
		UINT32 HeroAnimationFrame[2];
		h3unk8 _f_53F4[16];
		H3LoadedDef* heroDefLoaded[2];
		H3LoadedDef* heroFlagLoaded[2];
		INT32 heroFlagFrame[2];
		RECT heroUpdateRect[2];
		RECT heroFlagUpdateRect[2];
		H3Vector<INT32> eagleEyeSpell[2];
	public:
		BOOL8 massSpellTarget[2][20];
		UINT8 isNotAI[2];
		BOOL8 isHuman[2];
		INT32 heroOwner[2];
		BOOL8 artifactAutoCast[2];
		BOOL heroCasted[2];
		INT32 heroMonCount[2];
		H3Army* army[2];
		H3CombatCreature stacks[2][21];
	protected:
		h3unk8 _f_1329C[4];
	public:
		INT32 turnsSinceLastEnchanterCast[2];
		eCreature summonedMonster[2];
	protected:
		h3unk8 _f_132A8[8];
	public:
		INT32 currentMonSide;
		INT32 currentMonIndex;
		INT32 currentActiveSide;
		INT32 autoCombat;
		H3CombatCreature* activeStack;
		INT8 blueHighlight;
		INT32 creatureAtMousePos;
		INT32 mouseCoord;
		INT32 attackerCoord;
		INT32 moveType;
	protected:
		h3unk8 _f_132E0[8];
	public:
		H3LoadedDef* currentMagicAnim;
		INT32 currentMagicAnimId;
	protected:
		h3unk8 _f_132F0[4];
	public:
		INT32 siegeKind2;
		BOOL finished;
		struct H3CombatDlg* dlg;
	protected:
		h3unk8 _f_13300[352];
		BOOL8 removeDeadCreatures;
		LPCSTR backgroundPcxName;
	public:
		H3AdjacentSquares adjacentSquares[187];
	protected:
		h3unk8 _f_13D2C[12];
		RECT updateRect;
		h3unk8 _f_13D48[4];
	public:
		INT32 necromancyRaisedAmount;
		eCreature necromancyRaisedMonsters;
	protected:
		INT cmNumWinPcxLoaded;
	public:
		H3Vector<H3Obstacle> obstacleInfo;
		BOOL8 tacticsPhase;
		INT32 turn;
		INT32 tacticsDifference;
	protected:
		h3unk8 _f_13D74[4]; // spell related?
	public:
		struct TownTowerLoaded
		{
			_H3API_SIZE_(0x24);
			INT32        crType2Shot;
			H3LoadedDef* monDefLoaded;
			H3LoadedDef* shotDefLoaded;
			INT32        creatureX;
			INT32        creatureY;
			INT32        orientation;
			INT32        defGroup;
			H3DefFrame*  frame;
			INT32        stackNumber;
		}towers[3];
		BOOL32 waitPhase;
	protected:
		INT32 heroDAttack;
		INT32 heroDDefence;
		INT32 heroDSpellPower2;
		INT32 heroDSpellPoints;
	public:
		H3LoadedPcx* townSiegePcx[18][5];
		INT32 fortWallsHp[18];
		INT32 fortWallsAlive[18];
	protected:
		h3unk8 _f_13FF0[4];
	public:
		H3LoadedPcx* CCellGrdPcx;
		H3LoadedPcx* CCellShdPcx;
	protected:
		INT32 globalCardeIndex;
	public:
		BOOL8 redrawCreatureFrame[2][20];
		BOOL8 heroAnimation[2];
		BOOL8 heroFlagAnimation[2];
		BOOL8 turretAnimation[3];
		BOOL8 actionUndergoing;
		BOOL8 travelingSquares[187];
	public:
		_H3API_ VOID  SimulateMouseAtHex(INT32 hex_id);
		_H3API_ BOOL8 CanCastSpellAtCoord(INT32 spell_id, INT32 spell_expertise, INT32 coordinates);
		_H3API_ VOID  WinBattle();
		_H3API_ VOID  LoadSpell(INT32 spell_id);
		_H3API_ VOID  CastSpell(INT32 spell_id, INT32 hex_ix, INT32 cast_type_012, INT32 hex2_ix, INT32 skill_level, INT32 spell_power);
		_H3API_ INT32 SquareAtCoordinates(const H3POINT& p) const;
		_H3API_ INT32 SquareAtCoordinates(INT32 x, INT32 y) const;
		_H3API_ H3CombatCreature* GetResurrectionTarget(INT32 coordinate, INT32 caster_kind = 0);
		_H3API_ H3CombatCreature* GetAnimateDeadTarget(INT32 coordinate);
		_H3API_ INT32 NextCreatureToMove();
		_H3API_ BOOL8 IsHiddenBattle();
		_H3API_ BOOL8 IsBattleOver();
        _H3API_ VOID  ApplyAnimationToLastHitArmy(INT32 animationIndex, BOOL resetAnimationWhenDone);
		_H3API_ VOID  AddNecromancyRaisedCreature(INT32 side);
		_H3API_ VOID  Refresh();
		_H3API_ VOID  Refresh(BOOL redrawScreen, INT timeDelay, BOOL redrawBackground);
		_H3API_ VOID  RefreshCreatures();
		_H3API_ VOID  ShadeSquare(INT32 index);
		_H3API_ BOOL8 IsHumanTurn();
		_H3API_ VOID  AddStatusMessage(LPCSTR message, BOOL permanent = TRUE);
		_H3API_ VOID  PlayMagicAnimation(INT32 id, H3CombatCreature* target, INT32 timeStep, BOOL8 showTargetBeingHit);
		_H3API_ VOID  ReportDamageDone(LPCSTR attackerName, INT32 numAttackers, INT32 damageDone, H3CombatCreature* target, INT32 killedCount);
		_H3API_ BOOL8 ShouldCastSpellAfterHit(INT32 spellId, INT32 side, H3CombatCreature* target);
		_H3API_ VOID ResurrectTarget(H3CombatCreature* target, INT32 hitPoints, INT32 isTemporary);
        _H3API_ INT32 CalculateSpellDamageOnTarget(INT32 damage, INT32 spellId, H3Hero* atkHero, H3Hero* defHero, H3CombatCreature* target, BOOL showLog);
		_H3API_ H3CombatCreature* SummonCreature(INT32 side, INT32 creatureId, INT32 amount, INT32 position, INT32 redrawAnimation, BOOL redraw);
		_H3API_ H3CombatCreature* GetSummonDemonTarget(INT32 side, INT32 coordinate);
		_H3API_ VOID RaiseDemon(H3CombatCreature* caster, H3CombatCreature* target);
		_H3API_ BOOL8 CanApplyCreatureSpell(INT32 spell_id, INT32 creature_side, H3CombatCreature* target);
		_H3API_ VOID DrawRay(BOOL redraw, INT startX, INT startY, INT dstX, INT dstY, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay);
		_H3API_ VOID DrawRay(BOOL redraw, H3CombatCreature* start, H3CombatCreature* end, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay);
		_H3API_ VOID AnimateMassSpell(INT32 animation_id, BOOL8 affects_both_sides);
		_H3API_ INT32 Close(H3Msg& msg);
		_H3API_ BOOL CanSummonOrClone() const;
	};
	_H3API_ASSERT_SIZE_(H3CombatManager);
	_H3API_ASSERT_SIZE_(H3CombatManager::TownTowerLoaded);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3Manager;
	_H3API_DECLARE_(ExecutiveMgr);

#pragma pack(push, 4)
	struct H3ExecutiveMgr
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x699550, H3ExecutiveMgr);

		H3Manager* first_mgr;
		H3Manager* last_mgr;
		H3Manager* active_mgr;
	protected:
		h3unk32    _f_0C; // status?
	public:
		_H3API_ VOID RemoveManager(H3Manager* mgr);
		_H3API_ INT  AddManager(H3Manager* mgr, INT32 order);
		_H3API_ VOID StartManager(H3Manager* mgr);
	};
	_H3API_ASSERT_SIZE_(H3ExecutiveMgr);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(HiScoreManager);

#pragma pack(push, 4)

	struct H3HiScoreManager : H3Manager
	{
		_H3API_SIZE_(0x8D4);
		_H3API_VTABLE_(0x63EB8C);
		_H3API_GET_INFO_(0x69941C, H3HiScoreManager);
		struct Entry
		{
			_H3API_SIZE_(0x64);

			CHAR username[40];
			CHAR mapname[40];
			h3unk32 _f_50;
			INT32 score;
			INT32 days;
			h3unk8 _f_5C[8];
		};
		Entry scenarios[11];
		Entry campaigns[11];
		BOOL showingSingleScenarios;

		_H3API_ VOID ResetScores();
	};
	_H3API_ASSERT_SIZE_(H3HiScoreManager);
	_H3API_ASSERT_SIZE_(H3HiScoreManager::Entry);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(InputManager);

#pragma pack(push, 4)

	struct H3InputManager : public H3Manager
	{
		_H3API_SIZE_(0x960);
		_H3API_VTABLE_(0x63FE10);
		_H3API_GET_INFO_(0x6992D4, H3InputManager);

		struct InputMessages
		{
			UINT message;
			h3unk8 f_4[28]; // contents vary
		}
		messages[64];
		INT32 currentMessage;
		INT32 nextMessage;
		BOOL32  addingMessage;

	protected:
		h3unk8  _f_844[260];
		h3unk32 _f_948;
		h3unk32 _f_94C;
		h3unk32 _f_950;
		h3unk32 _f_954;
		h3unk32 _f_958;
		h3unk32 _f_95C;
	public:
		_H3API_ InputMessages& GetCurrentMessage();
		_H3API_ VOID AddMouseOverMessage();
	};
	_H3API_ASSERT_SIZE_(H3InputManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(MouseManager);
	struct H3LoadedDef;

#pragma pack(push, 4)

	struct H3MouseManager : public H3Manager
	{
		struct Cursor
		{
			INT32 type;
			INT32 frame;
		};

		_H3API_SIZE_(0x90);
		_H3API_VTABLE_(0x640038);
		_H3API_GET_INFO_(0x6992B0, H3MouseManager);

	protected:
		h3unk8 _f_38[20];
	public:
		INT32 cursorType;
		INT32 cursorFrame;
		H3LoadedDef* cursorDef;
	protected:
		h3unk32 _f_58;
		h3unk32 _f_5C;
		h3unk32 _f_60;
	public:
		BOOL8  showCursorState;
		BOOL   cursorHidden;
	protected:
		h3unk32 _f_6C;
		h3unk32 _f_70;
		h3unk32 _f_74;
		RTL_CRITICAL_SECTION criticalSection;
	public:
		_H3API_ VOID operator=(const Cursor& cursor);

		_H3API_ VOID   TurnOn();
		_H3API_ VOID   TurnOff();
		_H3API_ INT32  GetType() const;
		_H3API_ INT32  GetFrame() const;
		_H3API_ VOID   SetCursor(INT32 frame, INT32 type);
		_H3API_ VOID   SetCursor(INT32 frame, eCursor type);
		_H3API_ VOID   SetCursor(const Cursor& cursor);
		_H3API_ VOID   DefaultCursor();
		_H3API_ VOID   SetArtifactCursor(INT32 art_id);
		_H3API_ Cursor CurrentCursor() const;
	};
	_H3API_ASSERT_SIZE_(H3MouseManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(RecruitMgr);
	struct H3Army;
	struct H3Hero;
	struct H3CreatureSlot16;
	struct H3Generator;

#pragma pack(push, 4)

	struct H3RecruitMgr : H3Manager
	{
		_H3API_SIZE_(0xBC);
		_H3API_VTABLE_(0x640C80);
		_H3API_GET_INFO_(0x6AAABC, H3RecruitMgr);

		h3unk8 _f_38[16];
		INT32 objectType;
		BOOL8 teamDwelling;
		INT32 selectedType;
		INT32 selectedAmount;
		h3unk32 selectedCreatureIndex;
		INT32  types[4];
		INT16* amounts[4];
		H3Hero* hero;
		h3unk8 _f_80[4];
		INT32 goldCost;
		INT32 specialResourceIndex;
		INT32 specialResourceCost;
		h3unk32 dword90;
		h3unk8 _f_94[4];
		H3Army* army;
		BOOL8 summoningPortal;
		h3unk32 _f_A0;
		h3unk32 _f_A4;
		h3unk32 _f_A8;
		h3unk32 amountAvailable;
		h3unk32 totalGoldCost;
		h3unk32 totalResourceCost;
		h3unk32 amountToBuy;

		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1, INT32 type2, INT16& amount2);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2, INT32 type3, INT16& amount3);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, H3CreatureSlot16& slot0,
			H3CreatureSlot16& slot1, H3CreatureSlot16& slot2, H3CreatureSlot16& slot3);
		_H3API_ H3RecruitMgr(H3Army& army, H3Generator& generator);
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type, INT16& amount);
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1);
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2);
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2, INT32 type3, INT16& amount3);
		_H3API_ VOID Run();
	protected:
		_H3API_ H3RecruitMgr& initialize(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
			INT32 type2, INT16* amount2, INT32 type3, INT16* amount3);
		_H3API_ H3RecruitMgr& initialize(H3Hero* hero, INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
			INT32 type2, INT16* amount2, INT32 type3, INT16* amount3);
	};
	_H3API_ASSERT_SIZE_(H3RecruitMgr);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SoundManager);
	struct H3WavFile;

#pragma pack(push, 4)

	struct H3SoundManager : public H3Manager
	{
		_H3API_SIZE_(0xD4);
		_H3API_VTABLE_(0x63FE68);
		_H3API_GET_INFO_(0x699414, H3SoundManager);

	protected:
		UINT32 mssHandle;
		HANDLE hSamples[16];
		h3unk8 _f_80;
		INT32 clickSoundVar;
		h3unk32 _f_88;
		h3unk8 _f_8C;
		_RTL_CRITICAL_SECTION rtlSection[3];
	public:
		_H3API_ VOID ClickSound(); // modeled after sub_00456540
		_H3API_ VOID Play(H3WavFile* wav);
		_H3API_ VOID Play(LPCSTR wav_name);
		_H3API_ VOID PlaySoundAndWait(LPCSTR wav_name, INT milliseconds);
		_H3API_ static VOID PlaySoundAsync(LPCSTR wav_name, INT32 duration = -1);
        _H3API_ static INT64 PlaySoundByFileAsync(LPCSTR wav_name);
	};
	_H3API_ASSERT_SIZE_(H3SoundManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(SwapManager);
	struct H3Hero;
	struct H3SwapManagerDlg;
	struct H3LoadedPcx;

#pragma pack(push, 4)
	struct H3SwapManager : public H3Manager
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x64245C);
		_H3API_GET_INFO_(0x6A3D90, H3SwapManager);
		_H3API_CTOR_DTOR_(0x5AE850, -1);

		H3SwapManagerDlg* dlg;
		H3LoadedPcx* aTradesel_pcx;
		H3Hero* hero[2];
		INT32 heroSelected;
		INT32 heroClicked;
		INT32 clickedCreatureSlot;
		INT32 slotClicked;
	protected:
		h3unk32 _f_58;
	public:
		BOOL8 twoHumansTrade;
		BOOL8 samePlayer;
	protected:
		h3unk32 directPlayOffset_F0_60;
		h3unk32 object_10h_vt_642468_f_64;

	public:
		_H3API_ INT32 Close(H3Msg& msg);
		_H3API_ VOID UpdateLuckMorale();
		_H3API_ VOID RefreshDialog();
	};
	_H3API_ASSERT_SIZE_(H3SwapManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(TownManager);
	struct H3Town;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3LoadedDef;
	struct H3DlgTransparentItem;
	struct H3TownDialog;
	struct H3GarrisonInterface;

#pragma pack(push, 4)

	struct H3TownManager : public H3Manager
	{
		_H3API_SIZE_(0x1D8);
		_H3API_VTABLE_(0x643730);
		_H3API_GET_INFO_(0x69954C, H3TownManager);

		H3Town* town;
		H3LoadedPcx16* background;
		H3LoadedDef* creatures[7];
		struct BuildingDrawInfo
		{
			UINT numberFrames; // +0
			UINT currentFrame; // +4
			UINT xPos; // +8
			UINT yPos; // +C
			UINT width; // +10
			UINT height; // +14
			BOOL isActive; // +18
			UINT id; // +1C
			H3LoadedDef* def; // +20
			H3LoadedPcx* outline; // + 24
			H3LoadedPcx* background; // +28
			H3DlgTransparentItem* transparentOverlay; // +2C
		}*buildingDrawing[44]; // +5C
		UINT numberBuildings;
		INT townType;
	protected:
		h3unk8 _f_114[4];
	public:
		H3TownDialog* dlg;
		H3GarrisonInterface* top;
		H3GarrisonInterface* bottom;
	protected:
		h3unk8 _f_124[8];
	public:
		H3GarrisonInterface* source;
		INT32 sourcePageStack;
		H3GarrisonInterface* recipientPage;
		INT32 recipientPageStack;
	protected:
		h3unk8 _f_13C[100];
	public:
		H3BuildingsBitfield buildings;
	protected:
		h3unk32 _f_1A8[9];
	public:
		UINT8 dwellingIndexes[7];
	protected:
		h3unk32 _f_1D4;
	public:
		_H3API_ VOID Draw();
		_H3API_ VOID RefreshScreen();
		_H3API_ BOOL8 ViewTavern();
	};
	_H3API_ASSERT_SIZE_(H3TownManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(WindowManager);
	struct H3LoadedPcx16;
	struct H3BaseDlg;

#pragma pack(push, 4)

	struct H3WindowManager : public H3Manager
	{
		_H3API_SIZE_(0x60);
		_H3API_VTABLE_(0x643D5C);
		_H3API_GET_INFO_(0x6992D0, H3WindowManager);

		INT32 resultItemID;
		INT32 mouseoverItemId;
		H3LoadedPcx16* screenPcx16;
	protected:
		h3unk32 _f_44;
		BOOL8 mouseTurnedOff;
	public:
		H3LoadedPcx16* backupScreen;
		H3BaseDlg* firstDlg;
		H3BaseDlg* lastDlg;
	protected:
		h3unk32 _f_58;
		h3unk32 _f_5C;
	public:
		VOID H3Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy);
		INT32 ClickedItemID() const;
		VOID SetClickedItemId(INT32 id);
		BOOL ClickedOK() const;
		BOOL ClickedCancel() const;
		H3LoadedPcx16* GetDrawBuffer();
	};
	_H3API_ASSERT_SIZE_(H3WindowManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    namespace H3Internal
    {

        typedef H3DataPointer<H3ActivePlayer>         H3ActivePlayer_ptr;
        typedef H3DataPointer<H3AdventureManager>     H3AdventureManager_ptr;
        typedef H3DataPointer<H3AdveventText>         H3AdveventText_ptr;
        typedef H3DataPointer<H3BattleOptionsDlg>     H3BattleOptionsDlg_ptr;
        typedef H3DataPointer<H3BigFont>              H3BigFont_ptr;
        typedef H3DataPointer<H3ButtonWav>            H3ButtonWav_ptr;
        typedef H3DataPointer<H3CalliFont>            H3CalliFont_ptr;
        typedef H3DataPointer<H3CombatManager>        H3CombatManager_ptr;
        typedef H3DataPointer<H3DialogHero>           H3DialogHero_ptr;
        typedef H3DataPointer<H3ExecutiveMgr>         H3ExecutiveMgr_ptr;
        typedef H3DataPointer<H3GamePalette>          H3GamePalette_ptr;
        typedef H3DataPointer<H3GeneralText>          H3GeneralText_ptr;
        typedef H3DataPointer<H3InputManager>         H3InputManager_ptr;
        typedef H3DataPointer<H3Main>                 H3Main_ptr;
        typedef H3DataPointer<H3MediumFont>           H3MediumFont_ptr;
        typedef H3DataPointer<H3MouseManager>         H3MouseManager_ptr;
        typedef H3DataPointer<H3Pathfinder>           H3Pathfinder_ptr;
        typedef H3DataPointer<H3PlayersPalette>       H3PlayersPalette_ptr;
        typedef H3DataPointer<H3QuestsText>           H3QuestsText_ptr;
        typedef H3DataPointer<H3ResourceManager>      H3ResourceManager_ptr;
        typedef H3DataPointer<H3ScreenChat>           H3ScreenChat_ptr;
        typedef H3DataPointer<H3SeersText>            H3SeersText_ptr;
        typedef H3DataPointer<H3SelectScenarioDialog> H3SelectScenarioDialog_ptr;
        typedef H3DataPointer<H3SmallFont>            H3SmallFont_ptr;
        typedef H3DataPointer<H3SoundManager>         H3SoundManager_ptr;
        typedef H3DataPointer<H3SpellbookText>        H3SpellbookText_ptr;
        typedef H3DataPointer<H3TinyFont>             H3TinyFont_ptr;
        typedef H3DataPointer<H3TownManager>          H3TownManager_ptr;
        typedef H3DataPointer<H3TurnTimer>            H3TurnTimer_ptr;
        typedef H3DataPointer<H3WindowManager>        H3WindowManager_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ActivePlayer_ptr         P_ActivePlayer;
    typedef H3Internal::H3AdventureManager_ptr     P_AdventureManager;
    typedef H3Internal::H3AdveventText_ptr         P_AdveventText;
    typedef H3Internal::H3BattleOptionsDlg_ptr     P_BattleOptionsDlg;
    typedef H3Internal::H3BigFont_ptr              P_BigFont;
    typedef H3Internal::H3ButtonWav_ptr            P_ButtonWav;
    typedef H3Internal::H3CalliFont_ptr            P_CalliFont;
    typedef H3Internal::H3CombatManager_ptr        P_CombatManager;
    typedef H3Internal::H3DialogHero_ptr           P_DialogHero;
    typedef H3Internal::H3ExecutiveMgr_ptr         P_ExecutiveMgr;
    typedef H3Internal::H3GamePalette_ptr          P_GamePalette;
    typedef H3Internal::H3GeneralText_ptr          P_GeneralText;
    typedef H3Internal::H3InputManager_ptr         P_InputManager;
    typedef H3Internal::H3Main_ptr                 P_Main;
    typedef H3Internal::H3MediumFont_ptr           P_MediumFont;
    typedef H3Internal::H3MouseManager_ptr         P_MouseManager;
    typedef H3Internal::H3Pathfinder_ptr           P_Pathfinder;
    typedef H3Internal::H3PlayersPalette_ptr       P_PlayersPalette;
    typedef H3Internal::H3QuestsText_ptr           P_QuestsText;
    typedef H3Internal::H3ResourceManager_ptr      P_ResourceManager;
    typedef H3Internal::H3ScreenChat_ptr           P_ScreenChat;
    typedef H3Internal::H3SeersText_ptr            P_SeersText;
    typedef H3Internal::H3SelectScenarioDialog_ptr P_SelectScenarioDialog;
    typedef H3Internal::H3SmallFont_ptr            P_SmallFont;
    typedef H3Internal::H3SoundManager_ptr         P_SoundManager;
    typedef H3Internal::H3SpellbookText_ptr        P_SpellbookText;
    typedef H3Internal::H3TinyFont_ptr             P_TinyFont;
    typedef H3Internal::H3TownManager_ptr          P_TownManager;
    typedef H3Internal::H3TurnTimer_ptr            P_TurnTimer;
    typedef H3Internal::H3WindowManager_ptr        P_WindowManager;

    typedef P_AdventureManager     P_AdventureMgr;
    typedef P_CombatManager        P_CombatMgr;
    typedef P_Main                 P_Game;
    typedef P_Main                 P_Base;
    typedef P_MouseManager         P_MouseMgr;
    typedef P_Pathfinder           P_MovementMgr;
    typedef P_ResourceManager      P_ResourceMgr;
    typedef P_SoundManager         P_SoundMgr;
    typedef P_TownManager          P_TownMgr;
    typedef P_WindowManager        P_WindowMgr;

#else

#define P_ActivePlayer         h3::H3Internal::H3ActivePlayer_ptr()
#define P_AdventureManager     h3::H3Internal::H3AdventureManager_ptr()
#define P_AdventureMgr         h3::H3Internal::H3AdventureManager_ptr()
#define P_AdveventText         h3::H3Internal::H3AdveventText_ptr()
#define P_BattleOptionsDlg     h3::H3Internal::H3BattleOptionsDlg_ptr()
#define P_BigFont              h3::H3Internal::H3BigFont_ptr()
#define P_ButtonWav            h3::H3Internal::H3ButtonWav_ptr()
#define P_CalliFont            h3::H3Internal::H3CalliFont_ptr()
#define P_CombatManager        h3::H3Internal::H3CombatManager_ptr()
#define P_CombatMgr            h3::H3Internal::H3CombatManager_ptr()
#define P_DialogHero           h3::H3Internal::H3DialogHero_ptr()
#define P_ExecutiveMgr         h3::H3Internal::H3ExecutiveMgr_ptr()
#define P_GamePalette          h3::H3Internal::H3GamePalette_ptr()
#define P_GeneralText          h3::H3Internal::H3GeneralText_ptr()
#define P_InputManager         h3::H3Internal::H3InputManager_ptr()
#define P_Main                 h3::H3Internal::H3Main_ptr()
#define P_Game                 h3::H3Internal::H3Main_ptr()
#define P_Base                 h3::H3Internal::H3Main_ptr()
#define P_MediumFont           h3::H3Internal::H3MediumFont_ptr()
#define P_MouseManager         h3::H3Internal::H3MouseManager_ptr()
#define P_MouseMgr             h3::H3Internal::H3MouseManager_ptr()
#define P_Pathfinder           h3::H3Internal::H3Pathfinder_ptr()
#define P_MovementMgr          h3::H3Internal::H3Pathfinder_ptr()
#define P_PlayersPalette       h3::H3Internal::H3PlayersPalette_ptr()
#define P_QuestsText           h3::H3Internal::H3QuestsText_ptr()
#define P_ResourceManager      h3::H3Internal::H3ResourceManager_ptr()
#define P_ResourceMgr          h3::H3Internal::H3ResourceManager_ptr()
#define P_ScreenChat           h3::H3Internal::H3ScreenChat_ptr()
#define P_SeersText            h3::H3Internal::H3SeersText_ptr()
#define P_SelectScenarioDialog h3::H3Internal::H3SelectScenarioDialog_ptr()
#define P_SmallFont            h3::H3Internal::H3SmallFont_ptr()
#define P_SoundManager         h3::H3Internal::H3SoundManager_ptr()
#define P_SoundMgr             h3::H3Internal::H3SoundManager_ptr()
#define P_SpellbookText        h3::H3Internal::H3SpellbookText_ptr()
#define P_TinyFont             h3::H3Internal::H3TinyFont_ptr()
#define P_TownManager          h3::H3Internal::H3TownManager_ptr()
#define P_TownMgr              h3::H3Internal::H3TownManager_ptr()
#define P_TurnTimer            h3::H3Internal::H3TurnTimer_ptr()
#define P_WindowManager        h3::H3Internal::H3WindowManager_ptr()
#define P_WindowMgr            h3::H3Internal::H3WindowManager_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */

namespace h3
{

    _H3API_DECLARE_(AnimationSpeed);
    _H3API_DECLARE_(CastleName);
    _H3API_DECLARE_(CmpVoiceover);
    _H3API_DECLARE_(DwellingNames1);
    _H3API_DECLARE_(DwellingNames4);
    _H3API_DECLARE_(HeroDefaultBiography);
    _H3API_DECLARE_(MineNames);
    _H3API_DECLARE_(ObjectName);
    _H3API_DECLARE_(PlayerColor);
    _H3API_DECLARE_(PrimarySkillName);
    _H3API_DECLARE_(RandomSignText);
    _H3API_DECLARE_(ResourceName);
    _H3API_DECLARE_(SecondarySkillLevel);
    _H3API_DECLARE_(TentColors);
    _H3API_DECLARE_(TerrainName);
    _H3API_DECLARE_(TownNames);

    struct H3AnimationSpeed
    {
        static constexpr h3::ADDRESS ADDRESS = 0x43F255 + 3;
        static FLOAT* Get() { return ValueAt<FLOAT*>(0x43F255 + 3); }
        typedef FLOAT* VALUE_TYPE;
    };
    struct H3CastleName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40C9A8 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40C9A8 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3CmpVoiceover
    {
        static constexpr h3::ADDRESS ADDRESS = 0x44D5C3 + 2;
        static  LPCSTR* Get() { return ValueAt< LPCSTR*>(0x44D5C3 + 2); }
        typedef  LPCSTR* VALUE_TYPE;
    };
    struct H3DwellingNames1
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B514 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B514 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3DwellingNames4
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B556 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B556 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3HeroDefaultBiography
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4D92B7 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4D92B7 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3MineNames
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40D60B + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40D60B + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3ObjectName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B184 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B184 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3PlayerColor
    {
        static constexpr h3::ADDRESS ADDRESS = 0x406A7B + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x406A7B + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3PrimarySkillName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x460CED + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x460CED + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3RandomSignText
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A97E9 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4A97E9 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3ResourceName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x406A14 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x406A14 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3SecondarySkillLevel
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4847B1 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4847B1 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TentColors
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B268 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B268 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TerrainName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x413963 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x413963 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TownNames
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5C1854 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x5C1854 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };

    namespace H3Internal
    {

        typedef H3PrimitiveArrayPointer<H3AnimationSpeed>       H3AnimationSpeed_ptr;
        typedef H3PrimitiveArrayPointer<H3CastleName>           H3CastleName_ptr;
        typedef H3PrimitiveArrayPointer<H3CmpVoiceover>         H3CmpVoiceover_ptr;
        typedef H3PrimitiveArrayPointer<H3DwellingNames1>       H3DwellingNames1_ptr;
        typedef H3PrimitiveArrayPointer<H3DwellingNames4>       H3DwellingNames4_ptr;
        typedef H3PrimitiveArrayPointer<H3HeroDefaultBiography> H3HeroDefaultBiography_ptr;
        typedef H3PrimitiveArrayPointer<H3MineNames>            H3MineNames_ptr;
        typedef H3PrimitiveArrayPointer<H3ObjectName>           H3ObjectName_ptr;
        typedef H3PrimitiveArrayPointer<H3PlayerColor>          H3PlayerColor_ptr;
        typedef H3PrimitiveArrayPointer<H3PrimarySkillName>     H3PrimarySkillName_ptr;
        typedef H3PrimitiveArrayPointer<H3RandomSignText>       H3RandomSignText_ptr;
        typedef H3PrimitiveArrayPointer<H3ResourceName>         H3ResourceName_ptr;
        typedef H3PrimitiveArrayPointer<H3SecondarySkillLevel>  H3SecondarySkillLevel_ptr;
        typedef H3PrimitiveArrayPointer<H3TentColors>           H3TentColors_ptr;
        typedef H3PrimitiveArrayPointer<H3TerrainName>          H3TerrainName_ptr;
        typedef H3PrimitiveArrayPointer<H3TownNames>            H3TownNames_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3AnimationSpeed_ptr       P_AnimationSpeed;
    typedef H3Internal::H3CastleName_ptr           P_CastleName;
    typedef H3Internal::H3CmpVoiceover_ptr         P_CmpVoiceover;
    typedef H3Internal::H3DwellingNames1_ptr       P_DwellingNames1;
    typedef H3Internal::H3DwellingNames4_ptr       P_DwellingNames4;
    typedef H3Internal::H3HeroDefaultBiography_ptr P_HeroDefaultBiography;
    typedef H3Internal::H3MineNames_ptr            P_MineNames;
    typedef H3Internal::H3ObjectName_ptr           P_ObjectName;
    typedef H3Internal::H3PlayerColor_ptr          P_PlayerColor;
    typedef H3Internal::H3PrimarySkillName_ptr     P_PrimarySkillName;
    typedef H3Internal::H3RandomSignText_ptr       P_RandomSignText;
    typedef H3Internal::H3ResourceName_ptr         P_ResourceName;
    typedef H3Internal::H3SecondarySkillLevel_ptr  P_SecondarySkillLevel;
    typedef H3Internal::H3TentColors_ptr           P_TentColors;
    typedef H3Internal::H3TerrainName_ptr          P_TerrainName;
    typedef H3Internal::H3TownNames_ptr            P_TownNames;

#else

#define P_AnimationSpeed       h3::H3Internal::H3AnimationSpeed_ptr()
#define P_CastleName           h3::H3Internal::H3CastleName_ptr()
#define P_CmpVoiceover         h3::H3Internal::H3CmpVoiceover_ptr()
#define P_DwellingNames1       h3::H3Internal::H3DwellingNames1_ptr()
#define P_DwellingNames4       h3::H3Internal::H3DwellingNames4_ptr()
#define P_HeroDefaultBiography h3::H3Internal::H3HeroDefaultBiography_ptr()
#define P_MineNames            h3::H3Internal::H3MineNames_ptr()
#define P_ObjectName           h3::H3Internal::H3ObjectName_ptr()
#define P_PlayerColor          h3::H3Internal::H3PlayerColor_ptr()
#define P_PrimarySkillName     h3::H3Internal::H3PrimarySkillName_ptr()
#define P_RandomSignText       h3::H3Internal::H3RandomSignText_ptr()
#define P_ResourceName         h3::H3Internal::H3ResourceName_ptr()
#define P_SecondarySkillLevel  h3::H3Internal::H3SecondarySkillLevel_ptr()
#define P_TentColors           h3::H3Internal::H3TentColors_ptr()
#define P_TerrainName          h3::H3Internal::H3TerrainName_ptr()
#define P_TownNames            h3::H3Internal::H3TownNames_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */

namespace h3
{

    _H3API_DECLARE_(ActivePlayerBitset);
    _H3API_DECLARE_(ArtifactCount);
    _H3API_DECLARE_(AutoSolo);
    _H3API_DECLARE_(BitMode);
    _H3API_DECLARE_(BlueMask);
    _H3API_DECLARE_(BootsOfSpeedBonus);
    _H3API_DECLARE_(CreatureCount);
    _H3API_DECLARE_(CurrentAnimationSpeed);
    _H3API_DECLARE_(CurrentPlayerID);
    _H3API_DECLARE_(EquestriansGlovesBonus);
    _H3API_DECLARE_(GameEdgeHorizontal);
    _H3API_DECLARE_(GameEdgeVertical);
    _H3API_DECLARE_(GameHeight);
    _H3API_DECLARE_(GameWidth);
    _H3API_DECLARE_(GreenMask);
    _H3API_DECLARE_(HeroCount);
    _H3API_DECLARE_(HeroRetreated);
    _H3API_DECLARE_(HeroSurrendered);
    _H3API_DECLARE_(HumanID);
    _H3API_DECLARE_(Hwnd);
    _H3API_DECLARE_(Instance);
    _H3API_DECLARE_(IsCampaignGame);
    _H3API_DECLARE_(MapSize);
    _H3API_DECLARE_(Module);
    _H3API_DECLARE_(NecklaceOceanGuidanceBonus);
    _H3API_DECLARE_(RedMask);
    _H3API_DECLARE_(SeaCaptainsHatBonus);
    _H3API_DECLARE_(SpellCount);
    _H3API_DECLARE_(StablesBonus);
    _H3API_DECLARE_(TextDlgMaxHeight);
    _H3API_DECLARE_(TextDlgMaxWidth);
    _H3API_DECLARE_(TownCount);

    struct H3ActivePlayerBitset
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69CD10;
        static UINT8 Get() { return ValueAt<UINT8>(0x69CD10); }
        typedef UINT8 VALUE_TYPE;
    };
    struct H3ArtifactCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x44D1A8 + 2;
        static INT32 Get() { return ValueAt<INT32>(0x44D1A8 + 2); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3AutoSolo
    {
        static constexpr h3::ADDRESS ADDRESS = 0x691259;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x691259); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3BitMode
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5FA228 + 3;
        static UINT8 Get() { return ValueAt<UINT8>(0x5FA228 + 3); }
        typedef UINT8 VALUE_TYPE;
    };
    struct H3BlueMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB4;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3BootsOfSpeedBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B50;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B50); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CreatureCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5C8046 + 1;
        static UINT32 Get() { return ValueAt<UINT32>(0x5C8046 + 1); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CurrentAnimationSpeed
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69883C;
        static UINT32 Get() { return ValueAt<UINT32>(0x69883C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CurrentPlayerID
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69CCF4;
        static UINT32 Get() { return ValueAt<UINT32>(0x69CCF4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3EquestriansGlovesBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B4C;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B4C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3GameEdgeHorizontal
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A8FBE + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A8FBE + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3GameEdgeVertical
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A8FC3 + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A8FC3 + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3GameHeight
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4033FB + 1;
        static INT32 Get() { return ValueAt<INT32>(0x4033FB + 1); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3GameWidth
    {
        static constexpr h3::ADDRESS ADDRESS = 0x403400 + 1;
        static INT32 Get() { return ValueAt<INT32>(0x403400 + 1); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3GreenMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB0;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB0); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3HeroCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4BD144 + 1;
        static UINT32 Get() { return ValueAt<UINT32>(0x4BD144 + 1); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3HeroRetreated
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6985F3;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x6985F3); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3HeroSurrendered
    {
        static constexpr h3::ADDRESS ADDRESS = 0x697794;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x697794); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3HumanID
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6995A4;
        static UINT32 Get() { return ValueAt<UINT32>(0x6995A4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3Hwnd
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699650;
        static HWND Get() { return ValueAt<HWND>(0x699650); }
        typedef HWND VALUE_TYPE;
    };
    struct H3Instance
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699604;
        static HINSTANCE Get() { return ValueAt<HINSTANCE>(0x699604); }
        typedef HINSTANCE VALUE_TYPE;
    };
    struct H3IsCampaignGame
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69779C;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x69779C); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3MapSize
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6783C8;
        static UINT32 Get() { return ValueAt<UINT32>(0x6783C8); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3Module
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699604;
        static HMODULE Get() { return ValueAt<HMODULE>(0x699604); }
        typedef HMODULE VALUE_TYPE;
    };
    struct H3NecklaceOceanGuidanceBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B54;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B54); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3RedMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB8;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB8); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3SeaCaptainsHatBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B5C;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B5C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3SpellCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A2741 + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A2741 + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3StablesBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698AE4;
        static UINT32 Get() { return ValueAt<UINT32>(0x698AE4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TextDlgMaxHeight
    {
        static constexpr h3::ADDRESS ADDRESS = 0x415AC1 + 2;
        static UINT32 Get() { return ValueAt<UINT32>(0x415AC1 + 2); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TextDlgMaxWidth
    {
        static constexpr h3::ADDRESS ADDRESS = 0x415AAB + 2;
        static UINT32 Get() { return ValueAt<UINT32>(0x415AAB + 2); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TownCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5BE36E + 3;
        static INT32 Get() { return ValueAt<INT32>(0x5BE36E + 3); }
        typedef INT32 VALUE_TYPE;
    };

    namespace H3Internal
    {

        typedef H3PrimitivePointer<H3ActivePlayerBitset>         H3ActivePlayerBitset_ptr;
        typedef H3PrimitivePointer<H3ArtifactCount>              H3ArtifactCount_ptr;
        typedef H3PrimitivePointer<H3AutoSolo>                   H3AutoSolo_ptr;
        typedef H3PrimitivePointer<H3BitMode>                    H3BitMode_ptr;
        typedef H3PrimitivePointer<H3BlueMask>                   H3BlueMask_ptr;
        typedef H3PrimitivePointer<H3BootsOfSpeedBonus>          H3BootsOfSpeedBonus_ptr;
        typedef H3PrimitivePointer<H3CreatureCount>              H3CreatureCount_ptr;
        typedef H3PrimitivePointer<H3CurrentAnimationSpeed>      H3CurrentAnimationSpeed_ptr;
        typedef H3PrimitivePointer<H3CurrentPlayerID>            H3CurrentPlayerID_ptr;
        typedef H3PrimitivePointer<H3EquestriansGlovesBonus>     H3EquestriansGlovesBonus_ptr;
        typedef H3PrimitivePointer<H3GameEdgeHorizontal>         H3GameEdgeHorizontal_ptr;
        typedef H3PrimitivePointer<H3GameEdgeVertical>           H3GameEdgeVertical_ptr;
        typedef H3PrimitivePointer<H3GameHeight>                 H3GameHeight_ptr;
        typedef H3PrimitivePointer<H3GameWidth>                  H3GameWidth_ptr;
        typedef H3PrimitivePointer<H3GreenMask>                  H3GreenMask_ptr;
        typedef H3PrimitivePointer<H3HeroCount>                  H3HeroCount_ptr;
        typedef H3PrimitivePointer<H3HeroRetreated>              H3HeroRetreated_ptr;
        typedef H3PrimitivePointer<H3HeroSurrendered>            H3HeroSurrendered_ptr;
        typedef H3PrimitivePointer<H3HumanID>                    H3HumanID_ptr;
        typedef H3PrimitivePointer<H3Hwnd>                       H3Hwnd_ptr;
        typedef H3PrimitivePointer<H3Instance>                   H3Instance_ptr;
        typedef H3PrimitivePointer<H3IsCampaignGame>             H3IsCampaignGame_ptr;
        typedef H3PrimitivePointer<H3MapSize>                    H3MapSize_ptr;
        typedef H3PrimitivePointer<H3Module>                     H3Module_ptr;
        typedef H3PrimitivePointer<H3NecklaceOceanGuidanceBonus> H3NecklaceOceanGuidanceBonus_ptr;
        typedef H3PrimitivePointer<H3RedMask>                    H3RedMask_ptr;
        typedef H3PrimitivePointer<H3SeaCaptainsHatBonus>        H3SeaCaptainsHatBonus_ptr;
        typedef H3PrimitivePointer<H3SpellCount>                 H3SpellCount_ptr;
        typedef H3PrimitivePointer<H3StablesBonus>               H3StablesBonus_ptr;
        typedef H3PrimitivePointer<H3TextDlgMaxHeight>           H3TextDlgMaxHeight_ptr;
        typedef H3PrimitivePointer<H3TextDlgMaxWidth>            H3TextDlgMaxWidth_ptr;
        typedef H3PrimitivePointer<H3TownCount>                  H3TownCount_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ActivePlayerBitset_ptr         P_ActivePlayerBitset;
    typedef H3Internal::H3ArtifactCount_ptr              P_ArtifactCount;
    typedef H3Internal::H3AutoSolo_ptr                   P_AutoSolo;
    typedef H3Internal::H3BitMode_ptr                    P_BitMode;
    typedef H3Internal::H3BlueMask_ptr                   P_BlueMask;
    typedef H3Internal::H3BootsOfSpeedBonus_ptr          P_BootsOfSpeedBonus;
    typedef H3Internal::H3CreatureCount_ptr              P_CreatureCount;
    typedef H3Internal::H3CurrentAnimationSpeed_ptr      P_CurrentAnimationSpeed;
    typedef H3Internal::H3CurrentPlayerID_ptr            P_CurrentPlayerID;
    typedef H3Internal::H3EquestriansGlovesBonus_ptr     P_EquestriansGlovesBonus;
    typedef H3Internal::H3GameEdgeHorizontal_ptr         P_GameEdgeHorizontal;
    typedef H3Internal::H3GameEdgeVertical_ptr           P_GameEdgeVertical;
    typedef H3Internal::H3GameHeight_ptr                 P_GameHeight;
    typedef H3Internal::H3GameWidth_ptr                  P_GameWidth;
    typedef H3Internal::H3GreenMask_ptr                  P_GreenMask;
    typedef H3Internal::H3HeroCount_ptr                  P_HeroCount;
    typedef H3Internal::H3HeroRetreated_ptr              P_HeroRetreated;
    typedef H3Internal::H3HeroSurrendered_ptr            P_HeroSurrendered;
    typedef H3Internal::H3HumanID_ptr                    P_HumanID;
    typedef H3Internal::H3Hwnd_ptr                       P_Hwnd;
    typedef H3Internal::H3Instance_ptr                   P_Instance;
    typedef H3Internal::H3IsCampaignGame_ptr             P_IsCampaignGame;
    typedef H3Internal::H3MapSize_ptr                    P_MapSize;
    typedef H3Internal::H3Module_ptr                     P_Module;
    typedef H3Internal::H3NecklaceOceanGuidanceBonus_ptr P_NecklaceOceanGuidanceBonus;
    typedef H3Internal::H3RedMask_ptr                    P_RedMask;
    typedef H3Internal::H3SeaCaptainsHatBonus_ptr        P_SeaCaptainsHatBonus;
    typedef H3Internal::H3SpellCount_ptr                 P_SpellCount;
    typedef H3Internal::H3StablesBonus_ptr               P_StablesBonus;
    typedef H3Internal::H3TextDlgMaxHeight_ptr           P_TextDlgMaxHeight;
    typedef H3Internal::H3TextDlgMaxWidth_ptr            P_TextDlgMaxWidth;
    typedef H3Internal::H3TownCount_ptr                  P_TownCount;

#else

#define P_ActivePlayerBitset         h3::H3Internal::H3ActivePlayerBitset_ptr()
#define P_ArtifactCount              h3::H3Internal::H3ArtifactCount_ptr()
#define P_AutoSolo                   h3::H3Internal::H3AutoSolo_ptr()
#define P_BitMode                    h3::H3Internal::H3BitMode_ptr()
#define P_BlueMask                   h3::H3Internal::H3BlueMask_ptr()
#define P_BootsOfSpeedBonus          h3::H3Internal::H3BootsOfSpeedBonus_ptr()
#define P_CreatureCount              h3::H3Internal::H3CreatureCount_ptr()
#define P_CurrentAnimationSpeed      h3::H3Internal::H3CurrentAnimationSpeed_ptr()
#define P_CurrentPlayerID            h3::H3Internal::H3CurrentPlayerID_ptr()
#define P_EquestriansGlovesBonus     h3::H3Internal::H3EquestriansGlovesBonus_ptr()
#define P_GameEdgeHorizontal         h3::H3Internal::H3GameEdgeHorizontal_ptr()
#define P_GameEdgeVertical           h3::H3Internal::H3GameEdgeVertical_ptr()
#define P_GameHeight                 h3::H3Internal::H3GameHeight_ptr()
#define P_GameWidth                  h3::H3Internal::H3GameWidth_ptr()
#define P_GreenMask                  h3::H3Internal::H3GreenMask_ptr()
#define P_HeroCount                  h3::H3Internal::H3HeroCount_ptr()
#define P_HeroRetreated              h3::H3Internal::H3HeroRetreated_ptr()
#define P_HeroSurrendered            h3::H3Internal::H3HeroSurrendered_ptr()
#define P_HumanID                    h3::H3Internal::H3HumanID_ptr()
#define P_Hwnd                       h3::H3Internal::H3Hwnd_ptr()
#define P_Instance                   h3::H3Internal::H3Instance_ptr()
#define P_IsCampaignGame             h3::H3Internal::H3IsCampaignGame_ptr()
#define P_MapSize                    h3::H3Internal::H3MapSize_ptr()
#define P_Module                     h3::H3Internal::H3Module_ptr()
#define P_NecklaceOceanGuidanceBonus h3::H3Internal::H3NecklaceOceanGuidanceBonus_ptr()
#define P_RedMask                    h3::H3Internal::H3RedMask_ptr()
#define P_SeaCaptainsHatBonus        h3::H3Internal::H3SeaCaptainsHatBonus_ptr()
#define P_SpellCount                 h3::H3Internal::H3SpellCount_ptr()
#define P_StablesBonus               h3::H3Internal::H3StablesBonus_ptr()
#define P_TextDlgMaxHeight           h3::H3Internal::H3TextDlgMaxHeight_ptr()
#define P_TextDlgMaxWidth            h3::H3Internal::H3TextDlgMaxWidth_ptr()
#define P_TownCount                  h3::H3Internal::H3TownCount_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgItem);
	struct H3DlgFrame;
	struct H3DlgDef;
	struct H3DlgDefButton;
	struct H3DlgCaptionButton;
	struct H3DlgCustomButton;
	struct H3DlgPcx;
	struct H3DlgPcx16;
	struct H3DlgEdit;
	struct H3DlgText;
	struct H3DlgTextPcx;
	class  H3DlgHintBar;
	struct H3DlgScrollableText;
	struct H3DlgScrollbar;
	struct H3DlgTextScrollbar;
	struct H3BaseDlg;
	struct H3Font;
	struct H3LoadedDef;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3Msg;
	struct H3RGB565;
	struct H3RGB888;

	typedef UINT16 RGB565;

#pragma pack(push, 4)

	struct H3DlgItem : H3Allocator
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x643CA0);
		enum eVTables
		{
			VT_EDITTEXT_HISCORE_NAME = 0x63EBF4, // see 4E9760
		};

	protected:

		_H3API_ virtual H3DlgItem* vDestroy(BOOL8 deallocate) = 0;
		_H3API_ virtual BOOL       vInitiate(INT16 zorder, H3BaseDlg* parent) = 0;
		_H3API_ virtual INT        vProcessMsg(H3Msg& msg) = 0;
		_H3API_ virtual VOID       vDrawPcx8(PWORD buffer, RGB565 color) = 0;
		_H3API_ virtual VOID       vDrawToWindow() = 0;
		_H3API_ virtual INT        vGetHeight() const = 0;
		_H3API_ virtual INT        vGetWidth() const = 0;
		_H3API_ virtual VOID       vCallParent() const = 0;
		_H3API_ virtual VOID       vDarkenArea() const = 0;
		_H3API_ virtual VOID       vEnable(BOOL8 state) = 0;
		_H3API_ virtual VOID       vGetFocus() = 0;
		_H3API_ virtual VOID       vLoseFocus() = 0;
		_H3API_ virtual VOID       vNullsub(INT unknown) const = 0;

		H3BaseDlg*    parent;
		H3DlgItem*    nextDlgItem;
		H3DlgItem*    previousDlgItem;
		UINT16        id;
		INT16         zOrder;
		eControl      type;
		eControlState state;
		INT16         xPos;
		INT16         yPos;
		UINT16        widthItem;
		UINT16        heightItem;
		LPCSTR        hint;
		LPCSTR        rightClickHint;
		BOOL8         hintsAreAllocated;
		INT32         deactivatesCount;

		_H3API_ BOOL NotifyParent(H3Msg& msg);
		_H3API_ BOOL TranslateUnprocessedMessage(H3Msg& msg);

	public:
		_H3API_ VOID       EnableItem(BOOL enable);
		_H3API_ VOID       Enable();
		_H3API_ VOID       Disable();
		_H3API_ INT16      GetX() const;
		_H3API_ INT16      GetY() const;
		_H3API_ INT32      GetAbsoluteX() const;
		_H3API_ INT32      GetAbsoluteY() const;
		_H3API_ BOOL       IsEnabled() const;
		_H3API_ BOOL       IsActive() const;
		_H3API_ VOID       SetX(UINT16 x);
		_H3API_ VOID       SetY(UINT16 y);
		_H3API_ INT32      GetHeight() const;
		_H3API_ INT32      GetWidth() const;
		_H3API_ VOID       SetWidth(UINT16 w);
		_H3API_ VOID       SetHeight(UINT16 h);
		_H3API_ VOID       Draw(); // draw new contents through vTable
		_H3API_ VOID       Refresh(); // refresh screen through parent dlg
		_H3API_ H3DlgItem* Hide();
		_H3API_ VOID       HideDeactivate();
		_H3API_ VOID       ShowActivate();
		_H3API_ H3DlgItem* Show();
		_H3API_ VOID       Shade();
		_H3API_ VOID       UnShade();
		_H3API_ H3DlgItem* Activate();   // allows processing of H3Msg
		_H3API_ H3DlgItem* DeActivate(); // prevents processing of H3Msg
		_H3API_ BOOL       IsVisible() const;
		_H3API_ BOOL       IsSet(eControlState state) const;
		_H3API_ VOID       AddState(eControlState state);
		_H3API_ VOID       RemoveState(eControlState state);
		_H3API_ LPCSTR     GetHint() const;
		_H3API_ VOID       SetHint(LPCSTR msg);
		_H3API_ UINT16     GetID() const;
		_H3API_ VOID       ParentRedraw(); // redraw through parent
		_H3API_ VOID       ColorToPlayer(INT8 player);
		_H3API_ VOID       SendCommand(INT32 command, INT32 parameter);
		_H3API_ VOID       SetHints(LPCSTR shortTipText, LPCSTR rightClickHint, BOOL allocateMemory);
		_H3API_ VOID       DrawTempFrame(INT thickness, BYTE r, BYTE g, BYTE b) const;
		_H3API_ VOID       DrawTempFrame(INT thickness, const H3RGB888& color) const;

		_H3API_ H3BaseDlg* GetParent() const;
		_H3API_ H3DlgItem* GetNextItem() const;
		_H3API_ H3DlgItem* GetPreviousItem() const;

		template<typename ItemType>
		ItemType* Cast();
	};
	_H3API_ASSERT_SIZE_(H3DlgItem);

#pragma pack(pop) /* align-4 */

	template<typename ItemType>
	inline typename ItemType* H3DlgItem::Cast()
	{
		return reinterpret_cast<ItemType*>(this);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgDefButton);

#pragma pack(push, 4)

	struct H3DlgDefButton : public H3DlgItem
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x63BB54);
	protected:
		H3LoadedDef*    loadedDef;
		INT32           defFrame;
		INT32           defFrameOnClick;
		INT32           mirror;
		h3unk32         _f_40;
		BOOL8           closeDialog;
		H3Vector<INT32> hotkeys;
		H3String        caption;

	public:
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey);
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey);
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 clickFrame);

		_H3API_ VOID         AddHotkey(INT32 key);
		_H3API_ VOID         SetFrame(INT32 frame);
		_H3API_ INT          ToggleFrame();
		_H3API_ INT32        GetFrame() const;
		_H3API_ INT32        GetClickFrame() const;
		_H3API_ VOID         ColorDefToPlayer(INT32 id);
		_H3API_ VOID         SetClickFrame(INT32 clickFrame);
		_H3API_ H3LoadedDef* GetDef();
	};
	_H3API_ASSERT_SIZE_(H3DlgDefButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgCaptionButton);
	struct H3Font;

#pragma pack(push, 4)

		struct H3DlgCaptionButton : public H3DlgDefButton
	{
		_H3API_SIZE_(0x70);
		_H3API_VTABLE_(0x63BB88);
	protected:
		H3Font* loadedFont;
		INT32   color;
	public:

		_H3API_ static H3DlgCaptionButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group,
			BOOL closeDialog, INT32 a13, INT32 color);
		_H3API_ static H3DlgCaptionButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 a13, INT32 color);
	};
	_H3API_ASSERT_SIZE_(H3DlgCaptionButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgCustomButton);
	typedef INT32(__fastcall* H3DlgButton_proc)(H3Msg*);
	typedef INT32(__fastcall* H3DlgButtonProc)(H3Msg&);

#pragma pack(push, 4)

	struct H3DlgCustomButton : public H3DlgDefButton
	{
		_H3API_SIZE_(0x6C);
		_H3API_VTABLE_(0x63BBBC);
	protected:
		H3DlgButton_proc customButtonProc; /**< @brief [68]*/
	public:

		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ VOID ToggleMsgFlag(BOOL& flag);
	};
	_H3API_ASSERT_SIZE_(H3DlgCustomButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgDef);

#pragma pack(push, 4)

	struct H3DlgDef : public H3DlgItem
	{
		_H3API_SIZE_(0x48);
		_H3API_VTABLE_(0x63EC48);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;

	protected:
		H3LoadedDef* loadedDef;
		INT32        defFrame;
		INT32        defGroup;
		INT32        mirror;
		INT32        _f_40;
		BOOL8        closeDialog;
	public:

		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, INT32 width,
			INT32 height, INT32 id, LPCSTR defName, INT32 frame = 0,
			INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame = 0, INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, LPCSTR defName,
			INT32 frame = 0, INT32 group = 0);
		_H3API_ VOID         SetFrame(INT32 frame);
		_H3API_ INT32        GetFrame() const;
		_H3API_ INT32        GetGroup() const;
		_H3API_ VOID         SetGroup(INT32 group);
		_H3API_ VOID         ColorDefToPlayer(INT32 id);
		_H3API_ H3LoadedDef* GetDef();
	};
	_H3API_ASSERT_SIZE_(H3DlgDef);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgText);
	struct H3Font;

#pragma pack(push, 4)

	struct H3DlgText : public H3DlgItem
	{
		_H3API_SIZE_(0x50);
		_H3API_VTABLE_(0x642DC0);

	protected:
		_H3API_ virtual VOID vSetText(LPCSTR text) const = 0;

	protected:
		H3String text;
		H3Font*  font;
		INT32    color;
		INT32    bkColor;
		eTextAlignment alignment;
	public:
		_H3API_ static H3DlgText* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR text, LPCSTR fontName = NH3Dlg::Text::SMALL,	INT32 color = eTextColor::REGULAR,
			INT32 id = 0, INT32 align = eTextAlignment::MIDDLE_CENTER, INT32 bkColor = 0);
		_H3API_ H3String& GetH3String();
		_H3API_ VOID SetText(LPCSTR text);
		_H3API_ VOID SetText(const H3String& text);
		_H3API_ VOID SetAlignment(eTextAlignment align);
	};
	_H3API_ASSERT_SIZE_(H3DlgText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgEdit);
	_H3API_DECLARE_(ScreenchatEdit);
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3Msg;

#pragma pack(push, 4)

	struct H3DlgEdit : public H3DlgText
	{
		_H3API_SIZE_(0x70);
		_H3API_VTABLE_(0x642D50);
		_H3API_CTOR_DTOR_(0x5BACD0, -1);
	protected:
		_H3API_ virtual VOID  vSetFocus(BOOL8 focused) const = 0;
		_H3API_ virtual INT   vProcessKey(H3Msg &msg) = 0;
		_H3API_ virtual BOOL8 vIsTabEscEnter(H3Msg &msg) const = 0;
		_H3API_ virtual VOID  vLoadPcx16Special(BOOL8 redraw) const = 0;
		_H3API_ virtual VOID  vPcx16FromBuffer() const = 0;

	protected:
		H3LoadedPcx*   loadedPcx;
		H3LoadedPcx16* loadedPcx16;
		UINT16         caretPos;
		UINT16         maxLength;
		UINT16         fieldSizeX;
		UINT16         fieldSizeY;
		UINT16         fieldX;
		UINT16         fieldY;
		INT16          _f_64;
		INT16          hasBorder;
		INT16          _f_68;
		INT16          _f_6A;
		h3unk          _f_6C;
		BOOL8          focused;
		BOOL8          autoRedraw;
	public:
		_H3API_ static H3DlgEdit* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align,
			LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY);
		_H3API_ LPCSTR    GetText() const;
		_H3API_ H3String* GetString();
		_H3API_ VOID      SetText(LPCSTR text);
		_H3API_ VOID      DecreaseCaret();
		_H3API_ VOID      IncreaseCaret();
		_H3API_ UINT      GetCaret() const;
		_H3API_ BOOL      SetCaret(UINT pos);
		_H3API_ VOID      SetAutoredraw(BOOL on);
		_H3API_ VOID      SetFocus(BOOL on = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3DlgEdit);

	struct H3ScreenchatEdit : H3DlgEdit
	{
		_H3API_SIZE_(0x74);
		BOOL8 enteringText;
	};
	_H3API_ASSERT_SIZE_(H3ScreenchatEdit);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgFrame);
	struct H3RGB565;

#pragma pack(push, 4)

	struct H3DlgFrame : public H3DlgItem
	{
		_H3API_SIZE_(0x38);
		_H3API_VTABLE_(0x63BA5C);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0; /**< @ brief [v34]*/

	protected:
		RGB565   color565;
		h3align  _f_32[2];
		BOOL8    changeHue;
	public:
		_H3API_ static H3DlgFrame* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color);
		_H3API_ static H3DlgFrame* Create(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color);
		_H3API_ static H3DlgFrame* Create(H3DlgItem* target, RGB565 color, INT id = 0, BOOL around_edge = false);

		_H3API_ VOID      ChangeColor(RGB565 color);
		_H3API_ VOID      HideHue();
		_H3API_ VOID      ShowHue();
		_H3API_ VOID      ToggleHue();
		_H3API_ H3RGB565& GetColor();
	};
	_H3API_ASSERT_SIZE_(H3DlgFrame);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	class H3DlgHighlightable;

	struct H3DlgItem;
	struct H3Msg;

#pragma pack(push, 4)

	class H3DlgHighlightable
	{
	protected:
		struct Highlighter
		{
			H3DlgItem* m_item;
			H3ARGB888  m_highlight;
			UINT       m_thickness;
			_H3API_ Highlighter();
			_H3API_ Highlighter(H3DlgItem* item, const H3ARGB888& color, UINT thickness);
			_H3API_ Highlighter(H3DlgItem* item, BYTE r, BYTE g, BYTE b, UINT thickness);
		};

		H3Vector<Highlighter> m_highlightableItems;
		mutable H3DlgItem* m_currentHighlight;
		_H3API_ BOOL unhighlightSelection() const;
	public:
		_H3API_ H3DlgHighlightable();
		_H3API_ VOID AddItem(H3DlgItem* dlgItem, BYTE red, BYTE green, BYTE blue, UINT frame_thickness);
		_H3API_ VOID AddItem(H3DlgItem* dlgItem, const H3ARGB888& color, UINT frame_thickness);
		_H3API_ BOOL HighlightItem(H3DlgItem* dlgItem) const;
		_H3API_ BOOL HighlightItem(const H3Msg& msg) const;
		_H3API_ VOID Clear();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgTextPcx);

#pragma pack(push, 4)

	struct H3DlgTextPcx : public H3DlgText
	{
		_H3API_SIZE_(0x54);
		_H3API_VTABLE_(0x642DF8);
	protected:
		H3LoadedPcx* loadedPcx;
	public:

		_H3API_ static H3DlgTextPcx* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR text, LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id = 0,
			INT32 align = eTextAlignment::MIDDLE_CENTER);
		_H3API_ static H3DlgTextPcx* Create(INT32 x, INT32 y, LPCSTR text, LPCSTR fontName,
			LPCSTR pcxName, INT32 color, INT32 align);
	};
	_H3API_ASSERT_SIZE_(H3DlgTextPcx);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	class  H3DlgHintBar;
	struct H3BaseDlg;
	struct H3Msg;

#pragma pack(push, 4)
	class H3DlgHintBar : public H3DlgTextPcx
	{
		H3DlgItem* lastHint;
		public:
		_H3API_ VOID   ShowHint(H3Msg* msg);
		_H3API_ VOID   ShowMessage(LPCSTR msg);
		_H3API_ static H3DlgHintBar* Create(H3BaseDlg* dlg);
		_H3API_ static H3DlgHintBar* Create(H3BaseDlg* dlg, INT32 x, INT32 y, INT32 w, INT32 h);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgPcx);
	struct H3LoadedPcx;

#pragma pack(push, 4)

	struct H3DlgPcx : public H3DlgItem
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x63BA94);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;

	protected:
		H3LoadedPcx* loadedPcx;
	public:
		_H3API_ static H3DlgPcx* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);
		_H3API_ static H3DlgPcx* Create(INT32 x, INT32 y, INT32 id, LPCSTR pcxName);
		_H3API_ static H3DlgPcx* Create(INT32 x, INT32 y, LPCSTR pcxName);
		_H3API_ VOID         SetPcx(H3LoadedPcx* pcx);
		_H3API_ VOID         AdjustColor(INT player);
		_H3API_ H3LoadedPcx* GetPcx();
		_H3API_ H3LoadedPcx* GetPcx() const;
	};
	_H3API_ASSERT_SIZE_(H3DlgPcx);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgPcx16);
	struct H3LoadedPcx16;

#pragma pack(push, 4)

	struct H3DlgPcx16 : public H3DlgItem
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x63BACC);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;
	protected:
		H3LoadedPcx16* loadedPcx16;
	public:
		_H3API_ static H3DlgPcx16* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);
		_H3API_ static H3DlgPcx16* Create(INT32 x, INT32 y, INT32 id, LPCSTR pcxName);
		_H3API_ static H3DlgPcx16* Create(INT32 x, INT32 y, LPCSTR pcxName);
		_H3API_ VOID SetPcx(H3LoadedPcx16* pcx16);
		_H3API_ H3LoadedPcx16* GetPcx();
		_H3API_ VOID SinkArea(INT32 x, INT32 y, INT32 w, INT32 h);
		_H3API_ VOID BevelArea(INT32 x, INT32 y, INT32 w, INT32 h);
		_H3API_ VOID SinkArea(H3DlgItem* it);
		_H3API_ VOID BevelArea(H3DlgItem* it);
	};
	_H3API_ASSERT_SIZE_(H3DlgPcx16);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgScrollableText);
	struct H3String;
	struct H3LoadedPcx16;

#pragma pack(push, 4)

	struct H3DlgScrollableText : public H3DlgItem
	{
		_H3API_SIZE_(0x5C);
		_H3API_VTABLE_(0x642D1C);
	protected:
		LPCSTR               font;
		H3Vector<H3String>   textLines;
		H3Vector<H3DlgText*> textItems;
		H3DlgTextScrollbar*  scrollBar;
		H3LoadedPcx16*       canvas;
	public:
		_H3API_ static H3DlgScrollableText* Create(LPCSTR text, INT32 x, INT32 y,
			INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue);
	};
	_H3API_ASSERT_SIZE_(H3DlgScrollableText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgScrollbar);
	struct H3LoadedPcx;
	struct H3LoadedDef;
	typedef VOID(__fastcall* H3DlgScrollbar_proc)(INT32, H3BaseDlg*);
	typedef VOID(__fastcall* H3DlgScrollbarProc)(INT32, H3BaseDlg&);

#pragma pack(push, 4)

	struct H3DlgScrollbar : public H3DlgItem
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x641D60);
		_H3API_CTOR_DTOR_(0x5963C0, -1);
	protected:
		_H3API_ virtual VOID vSetTickCount(INT tick) const = 0;
		_H3API_ virtual VOID vChangeTickPosition(INT change) = 0;
		_H3API_ virtual VOID vDecreaseTickPosition(INT change) = 0;
		_H3API_ virtual VOID vScrollCallOwner() const = 0;

	protected:
		H3LoadedDef*        loadedBtnDef;
		H3LoadedPcx*        loadedPcx;
		INT32               previousTick;
		INT32               tick;
		INT32               btnPosition;
		INT32               sizeFree;
		INT32               ticksCount;
		INT32               sizeMax;
		INT32               bigStepSize;
		INT32               btnSize2;
		h3unk32             _f_58;
		BOOL8               catchKeys;
		BOOL8               focused;
		h3unk32             _f_60;
		H3DlgScrollbar_proc callBack;

		VOID loadButton(LPCSTR buttonName);

	public:
		_H3API_ static H3DlgScrollbar* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc, BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled);
		_H3API_ INT32 GetTick() const;
		_H3API_ VOID  SetTick(INT32 index);
		_H3API_ VOID  SetBigStep(INT32 step);
		_H3API_ VOID  SetButtonPosition();
		_H3API_ BOOL  IsHorizontal() const;
		_H3API_ INT32 GetRightButtonX() const; // for horizontal scrollbar only!
		_H3API_ INT32 GetHorizontalY() const;
		_H3API_ INT32 GetBackgroundWidth() const;
		_H3API_ INT32 GetBackgroundX() const;
		_H3API_ INT32 GetSliderX() const;
		_H3API_ H3LoadedPcx* GetPcx();
	};
	_H3API_ASSERT_SIZE_(H3DlgScrollbar);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgTextScrollbar);
	struct H3DlgScrollableText;

#pragma pack(push, 4)
	struct H3DlgTextScrollbar : public H3DlgScrollbar
	{
		_H3API_SIZE_(0x6C);
		_H3API_VTABLE_(0x642CD8);
	protected:
		H3DlgScrollableText* owner;
	public:

	};
	_H3API_ASSERT_SIZE_(H3DlgTextScrollbar);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(DlgTransparentItem);

#pragma pack(push, 4)

	struct H3DlgTransparentItem : H3DlgItem
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x63BA24);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;
	public:
		_H3API_ static H3DlgTransparentItem* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id);
	};
	_H3API_ASSERT_SIZE_(H3DlgTransparentItem);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GzFile);
	struct H3GzStream;
	struct H3String;

#pragma pack(push, 4)

	struct H3GzFile : H3Allocator
	{
		_H3API_SIZE_(8);
	protected:
		struct
		{
			h3func dtor;
			h3func read;
			h3func write;
		}*vtable;
		H3GzStream* gzStream;
		_H3API_ UINT32 write(VOID* src, UINT32 size);
		_H3API_ UINT32 read(VOID* dst, UINT32 size);

	public:
		_H3API_ H3GzFile(LPCSTR file_name, LPCSTR mode);
		_H3API_ ~H3GzFile();
		_H3API_ BOOL ReadString16(H3String& string);
		_H3API_ BOOL Read(H3String& string);
		_H3API_ BOOL Write(const H3String& string);
		_H3API_ BOOL WriteString16(const H3String& string);
		template<typename Type, UINT32 Size>
		BOOL Write(const Type(&src)[Size]);
		template<typename Type, UINT32 Size>
		BOOL Read(Type(&dst)[Size]);
		template<typename Type>
		BOOL Write(const Type& src);
		template<typename Type>
		BOOL Read(Type& dst);
	};
	_H3API_ASSERT_SIZE_(H3GzFile);

#pragma pack(pop) /* align-4 */

	template<typename Type, UINT32 Size>
	BOOL H3GzFile::Write(const Type(&src)[Size])
	{
		UINT32 total_size = sizeof(Type) * Size;
		return write(PVOID(src), total_size) == total_size;
	}
	template<typename Type>
	BOOL H3GzFile::Write(const Type& src)
	{
		return write(PVOID(&src), sizeof(Type)) == sizeof(Type);
	}
	template<typename Type, UINT32 Size>
	BOOL H3GzFile::Read(Type(&dst)[Size])
	{
		UINT32 total_size = sizeof(Type) * Size;
		return read(PVOID(dst), total_size) == total_size;
	}
	template<typename Type>
	BOOL H3GzFile::Read(Type& dst)
	{
		return read(PVOID(&dst), sizeof(Type)) == sizeof(Type);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(ZStream);

#pragma pack(push, 4)

	struct H3ZStream
	{
		_H3API_SIZE_(0x38);
		BYTE* nextIn;        /* next input byte */
		UINT  availIn;       /* number of bytes available at next_in */
		UINT  totalIn;       /* total nb of input bytes read so far */
		BYTE* nextOut;       /* next output byte should be put there */
		UINT  availOut;      /* remaining free space at next_out */
		UINT  totalOut;      /* total nb of bytes output so far */
		PCHAR msg;           /* last error message, NULL if no error */
		INT*  internalState; /* not visible by applications */
		VOID* zalloc;        /* used to allocate the internal state */
		VOID* zfree;         /* used to free the internal state */
		VOID* opaque;        /* private data object passed to zalloc and zfree */
		INT   dataType;      /* best guess about the data type: ascii or binary */
		UINT  adler;         /* adler32 value of the uncompressed data */
		UINT  reserved;      /* reserved for future use */
	};
	_H3API_ASSERT_SIZE_(H3ZStream);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GzInflateBuf);
	_H3API_DECLARE_(GzInflateBufFile);
	struct H3String;

#pragma pack(push, 4)
	struct H3GzInflateBuf
	{
		_H3API_SIZE_(0x84);
		_H3API_VTABLE_(0x63E710);
		_H3API_CTOR_DTOR_(0x4D6260, 0x4D6A80);
	protected:
		struct
		{
			h3func dtor;
			h3func overflow;
			h3func pbackfail;
			h3func showmanyc;
			h3func underflow;
			h3func uflow;
			h3func xsgetn; /* v18 */
			h3func xsputn; /* v1C */
			h3func seekoff;
			h3func seekpos;
			h3func setbuf;
			h3func sync;
			h3func imbue;
		}*vtable;
		CHAR*     gbeg;
		CHAR*     pbeg;
		CHAR**    igbeg;
		CHAR**    ipbeg;
		CHAR*     gnext;
		CHAR*     pnext;
		CHAR**    ignext;
		CHAR**    ipnext;
		INT       gcnt;
		INT       pcnt;
		INT*      igcnt;
		INT*      ipcnt;
		PVOID     locale; // basic_streambuf end
		PVOID     strstreambuf; // vt 645680
		H3ZStream zstream;
		PVOID     buffer;
		PVOID     bufferEnd;
		h3unk32   _f_7C;
		h3unk8    _f_80; // related to zstrm
		h3unk8    _f_81; // related to strstreambuf
		h3unk8    _f_82; // related to zstrm

		_H3API_ UINT32 read(PVOID dst, UINT32 size);
		_H3API_ UINT32 write(PVOID src, UINT32 size);
	public:
	};
	_H3API_ASSERT_SIZE_(H3GzInflateBuf);

	struct H3GzInflateBufFile
	{
		_H3API_SIZE_(8);
		_H3API_VTABLE_(0x63DACC);
	protected:
		struct
		{
			h3func dtor;
			h3func read;
			h3func write;
		}*vtable;
		H3GzInflateBuf* inflatebuf;

		_H3API_ UINT32 read(PVOID dst, UINT32 size);
		_H3API_ UINT32 write(PVOID src, UINT32 size);
	public:
		_H3API_ H3String* Read(H3String& string);
	};
	_H3API_ASSERT_SIZE_(H3GzInflateBufFile);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	_H3API_DECLARE_(GzStream);

#pragma pack(push, 4)

	struct H3GZStream : H3Allocator
	{
		_H3API_SIZE_(0x64);
		H3ZStream zstrm;
		INT       zError;           /* error code for last stream operation */
		INT       zEof;             /* set if end of input file */
		FILE*     file;             /* .gz file */
		BYTE*     inbuf;            /* input buffer */
		BYTE*     outbuf;           /* output buffer */
		UINT32    crc;              /* crc32 of uncompressed data */
		PCHAR     msg;              /* error message */
		PCHAR     path;             /* path name for debugging only */
		INT       transparent;      /* 1 if input file is not a .gz file */
		CHAR      mode;             /* 'w' or 'r' */
		INT       startPos;         /* start of compressed data in file (header skipped) */
	};
	_H3API_ASSERT_SIZE_(H3GZStream);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgGroundTile
	{
		_H3API_SIZE_(4);
		unsigned  landType    : 5; /**< @brief [00]*/
		unsigned _b6          : 1; /**< @brief [05]*/
		unsigned  landSprite  : 7; /**< @brief [06]*/
		unsigned _b14         : 1; /**< @brief [13]*/
		unsigned  riverType   : 3; /**< @brief [14]*/
		unsigned _b18         : 1; /**< @brief [17]*/
		unsigned  riverSprite : 7; /**< @brief [18]*/
		unsigned _b26         : 1; /**< @brief [25]*/
		unsigned  roadType    : 3; /**< @brief [26]*/
		unsigned _b30         : 3; /**< @brief [29]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgGroundTile);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgGroundTileData
	{
		_H3API_SIZE_(4);
		unsigned  roadSprite    : 7;
		unsigned _b8            : 5;	//
		unsigned  orientation   : 3;	// bit 13 [0x0000 1000] ~ monster position 0~7, see 0x5437E2 & 0x54E117
		unsigned  mirrorLandV   : 1;	// bit 16 [0x0000 8000]
		unsigned  mirrorLandH   : 1;	// bit 17 [0x0001 0000]
		unsigned  mirrorRiverV  : 1;	// bit 18 [0x0002 0000]
		unsigned  mirrorRiverH  : 1;	// bit 19 [0x0004 0000]
		unsigned  mirrorRoadV   : 1;	// bit 20 [0x0008 0000]
		unsigned  mirrorRoadH   : 1;	// bit 21 [0x0010 0000]
		unsigned  shore         : 1;	// bit 22 [0x0020 0000]~ unsure, written to h3m at 0x532E42
		unsigned  hasObject     : 1;	// bit 23 [0x0040 0000] ~ see 0x547EB8
		unsigned _b24           : 1;	// bit 24 [0x0080 0000]
		unsigned _b25           : 1;	// bit 25 [0x0100 0000]
		unsigned  mustBeBlocked : 1;	// bit 26 [0x0200 0000] checks if not rock after 0x537F10
		unsigned  isEntrance    : 1;	// bit 27 [0x0400 0000] set when yellow entrance tile
		unsigned  isBlocked     : 1;    // bit 28 [0x0800 0000] ~ if this is not set, roads are allowed to go everywhere!
		unsigned _b29           : 1;	// bit 29 [0x1000 0000] ~ water related ?
		unsigned _b30           : 1;	// bit 30 [0x2000 0000]
		unsigned _b31           : 1;	// bit 31 [0x4000 0000]
		unsigned _b32           : 1;	// bit 32 [0x8000 0000]
	};
	_H3API_ASSERT_SIZE_(H3RmgGroundTileData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    struct H3RmgMapItem;

#pragma pack(push, 4)

	struct H3RmgMap
	{
		_H3API_SIZE_(0x18);
		h3func*      mapitemsVTable; /**< @brief [00]*/
		UINT8        mapItemsRef;    /**< @brief [04] probably auto_ptr<RMG_MapItem>*/
		H3RmgMapItem* mapItems;       /**< @brief [08]*/
		INT32        mapWidth;       /**< @brief [0C]*/
		INT32        mapHeight;      /**< @brief [10]*/
		INT32        numberLevels;   /**< @brief [14] 1..2*/

		_H3API_ H3RmgMapItem* GetMapItem(INT x, INT y, INT z);
		_H3API_ H3RmgMapItem* GetMapItem(const H3Point& coordinates);
		_H3API_ H3RmgMapItem* begin();
		_H3API_ H3RmgMapItem* end();
		_H3API_ H3Point GetCoordinates(H3RmgMapItem* item);
		_H3API_ H3Map<H3RmgMapItem>     GetMap();
		_H3API_ H3FastMap<H3RmgMapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3RmgMap);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    struct H3RmgObject;

#pragma pack(push, 4)

	struct H3RmgLocalMap : public H3RmgMap
	{
		_H3API_SIZE_(0x38);
		h3unk _f_18[16];
		H3Vector<H3RmgObject*> localObjects; /**< @brief [28]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgLocalMap);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    struct H3RmgMapItem;
    struct H3RmgRandomMapGenerator;

#pragma pack(push, 4)

	struct H3RmgMapInfo
	{
		_H3API_SIZE_(0x18);
		h3func*      vTable;         /**< @brief [00]*/
		BOOL8        hasMap;         /**< @brief [04] possibly auto_ptr*/
		H3RmgMapItem* undergroundMap; /**< @brief [08]*/
		INT32        width;          /**< @brief [0C]*/
		INT32        height;         /**< @brief [10]*/
		BOOL32       underground;    /**< @brief [14]*/
	public:
		_H3API_ H3RmgMapInfo(H3RmgRandomMapGenerator* main, BOOL underground = TRUE);
		_H3API_ ~H3RmgMapInfo();
	};
	_H3API_ASSERT_SIZE_(H3RmgMapInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgMovementCost
	{
		_H3API_SIZE_(4);
		unsigned  cost : 16;
		unsigned _b17  : 16;
	};
	_H3API_ASSERT_SIZE_(H3RmgMovementCost);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgZoneData
	{
		_H3API_SIZE_(4);
		unsigned _b1    : 16;
		unsigned  zone1 : 8;
		unsigned  zone2 : 8;
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgObject;
	typedef H3Point RMG_Coordinates;

#pragma pack(push, 4)

	struct H3RmgMapItem
	{
		_H3API_SIZE_(0x30);
		H3Vector<H3RmgObject*> objects;      /**< @brief [00]*/
		RMG_Coordinates       previousTile;	/**< @brief [10]*/
		H3RmgMovementCost      movement;     /**< @brief [1C]*/
		H3RmgZoneData          zone;
		H3RmgGroundTile        tile;         /**< @brief [24]*/
		H3RmgGroundTileData    tileData;     /**< @brief [28]*/
		h3unk32               _f_2C;        /**< @brief [2C]*/

		_H3API_ INT GetLand() const;
		_H3API_ INT GetLandSprite() const;
		_H3API_ INT GetRiver() const;
		_H3API_ INT GetRiverSprite() const;
		_H3API_ INT GetRoad() const;
		_H3API_ INT GetRoadSprite() const;
	};
	_H3API_ASSERT_SIZE_(H3RmgMapItem);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgObjectPropsRef;

#pragma pack(push, 4)

	struct H3RmgObject
	{
		_H3API_SIZE_(0x1C);

		struct VTable
		{
			h3func dtor;     // virtual dtor
			h3func unk;      // usually nullsub
			h3func someBool; // returns bool 1 most of the time
			h3func write;    // write to stream
		}*vTable;
		H3RmgObjectPropsRef* properties;
		H3Point             coordinates;
		h3unk32             _f_14;
		h3unk8              _f_18;

		_H3API_ h3func GetVTable() const;
	};
	_H3API_ASSERT_SIZE_(H3RmgObject);

	struct H3RmgObjectGenerator
	{
		_H3API_SIZE_(0x14);
		struct VTable
		{
			h3func createObject;
			h3func getValue;
			h3func someBool;
		}*vTable;
		INT32   type;
		INT32   subtype;
		INT32   value;
		INT32   density;
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectGenerator);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgObjectMonster : public H3RmgObject
	{
		_H3API_SIZE_(0x2C);
		INT32 indexOnMap; /**< @brief [1C]*/
		INT32 count;      /**< @brief [20]*/
		h3unk _f_24[8];   /**< @brief [24]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectMonster);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgObjectProperties
	{
		_H3API_SIZE_(0x4C);
		INT32        defNumber;   /**< @brief [00]*/
		H3ObjectMask passable;    /**< @brief [04]*/
		H3ObjectMask enterable;   /**< @brief [0C]*/
		H3Bitfield   land;        /**< @brief [14]*/
		H3Bitfield   landpage;    /**< @brief [18]*/
		INT32        type;        /**< @brief [1C]*/
		INT32        subtype;     /**< @brief [20]*/
		INT32        page;        /**< @brief [24]*/
		BOOL8        flat;        /**< @brief [28]*/
		BOOL8        hasEntrance; /**< @brief [29]*/
		INT32        enterX;      /**< @brief [2C]*/
		INT32        enterY;      /**< @brief [30]*/
		INT32        width;       /**< @brief [34]*/
		INT32        height;      /**< @brief [38]*/
		H3ObjectMask colors;      /**< @brief [3C]*/
		H3ObjectMask shadows;     /**< @brief [44]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectProperties);

	struct H3RmgObjectPropsRef // size E8
	{
		_H3API_SIZE_(0xE8);
		H3RmgObjectProperties* prototype;		 /**< @brief [00]*/
		h3unk32          _f_4;			 /**< @brief [04]*/
		UINT32           refCount;		 /**< @brief [08]*/
		INT32            prototypeIndex; /**< @brief [0C]*/
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgObjectSeer : public H3RmgObject
	{
		_H3API_SIZE_(0x34);
		INT32 artifactId;           /**< @brief [1C]*/
		INT32 experienceAmount;     /**< @brief [20]*/
		INT32 resourceId;           /**< @brief [24]*/
		INT32 resourceAmount;       /**< @brief [28]*/
		INT32 creatureRewardType;   /**< @brief [2C]*/
		INT32 creatureRewardNumber; /**< @brief [30]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectSeer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgObjectTown : public H3RmgObject
	{
		_H3API_SIZE_(0x28);
		INT32 indexOnMap; /**< @brief [1C]*/
		INT32 owner;      /**< @brief [20]*/
		BOOL8 hasFort;    /**< @brief [24]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectTown);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgParameters
	{
		_H3API_SIZE_(0x50);
		BOOL8  isHuman[8];      /**< @brief [00]*/
		INT32  townId[8];       /**< @brief [08]*/
		INT32  width;           /**< @brief [28]*/
		INT32  height;          /**< @brief [2C]*/
		BOOL32 hasUnderground;  /**< @brief [30]*/
		INT32  humanCount;      /**< @brief [34]*/
		INT32  humanTeams;      /**< @brief [38]*/
		INT32  computerCount;   /**< @brief [3C]*/
		INT32  computerTeams;   /**< @brief [40]*/
		INT32  waterAmount;     /**< @brief [44]*/
		INT32  monsterStrength; /**< @brief [48]*/
		INT32  gameVersion;     /**< @brief [4C]*/

		_H3API_ VOID Validate();
	};
	_H3API_ASSERT_SIZE_(H3RmgParameters);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    struct H3RmgObjectProperties;
    struct H3RmgObject;
    struct H3RmgTemplate;
    struct H3RmgZoneGenerator;
    struct H3RmgObjectGenerator;
    struct H3GzFile;
    struct H3RmgParameters;

#pragma pack(push, 4)

    struct H3RmgRandomMapGenerator
    {
        _H3API_SIZE_(0x14E0);
        h3func*                        vTable;                 /**< @brief [00]*/
        UINT32                         randomSeed;             /**< @brief [04]*/
        INT32                          gameVersion;            /**< @brief [08]*/
        H3RmgMap                        map;                    /**< @brief [0C]*/
        H3Vector<H3RmgObjectProperties>      objectsTxt;             /**< @brief [24] all of the the object properties*/
        H3Vector<H3RmgObjectProperties**>    objectPrototypes[232];  /**< @brief [34] object properties classified by type*/
        H3Vector<h3unk*>               _f_0EB4;                /**< @brief [EB4]*/
        H3Vector<H3RmgObject*>          positions;              /**< @brief [EC4]*/
        h3unk32                        progress;               /**< @brief [ED4]*/
        BOOL8                          isHuman[8];             /**< @brief [ED8]*/
        INT32                          playerOwner[8];         /**< @brief [EE0]*/
        h3unk                          _f_f00[36];             /**< @brief [F00]*/
        INT32                          playerTown[8];          /**< @brief [F24]*/
        INT32                          monsterOrObjectCount;   /**< @brief [F44]*/
        INT32                          humanCount;             /**< @brief [F48]*/
        INT32                          humanTeams;             /**< @brief [F4C]*/
        INT32                          computerCount;          /**< @brief [F50]*/
        INT32                          computerTeams;          /**< @brief [F54]*/
        h3unk                          _f_f58[8];              /**< @brief [F58]*/
        INT32                          townsCount;             /**< @brief [F60]*/
        h3unk                          _f_f64[4];              /**< @brief [F64]*/
        h3unk                          _f_f68[32];             /**< @brief [F68]*/
        BOOL8                          bannedHeroes[156];      /**< @brief [F88]*/
        BOOL8                          bannedArtifacts[144];   /**< @brief [1024]*/
        h3unk                          _f_10B4[4];             /**< @brief [10B4]*/
        INT32                          waterAmount;            /**< @brief [10B8]*/
        INT32                          monsterStrength;        /**< @brief [10BC]*/
        H3String                       templateName;           /**< @brief [10C0]*/
        H3Vector<H3RmgTemplate*>        randomTemplates;        /**< @brief [10D0]*/
        H3Vector<H3RmgZoneGenerator*>   zoneGenerators;         /**< @brief [10E0]*/
        H3Vector<H3RmgObjectGenerator*> objectGenerators;       /**< @brief [10F0]*/
        H3Vector<h3unk*>               _f_1100;                /**< @brief [1100]*/
        INT32                          objectCountByType[232]; /**< @brief [1110]*/
        H3Vector<H3Point>              roadTargets;            /**< @brief [14B0]*/
        H3Vector<H3RmgObject*>          monolithsOneWay;        /**< @brief [14C0]*/
        H3Vector<H3RmgObject*>          monolithsTwoWay;        /**< @brief [14D0]*/

        _H3API_ H3RmgRandomMapGenerator(/* not const*/ H3RmgParameters& p, PVOID progress);
        _H3API_ ~H3RmgRandomMapGenerator();
        _H3API_ BOOL8 GenerateMap();
        _H3API_ BOOL8 WriteMap(H3GzFile& stream);
    };
    _H3API_ASSERT_SIZE_(H3RmgRandomMapGenerator);

    typedef H3RmgRandomMapGenerator RMG_Main;

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	struct H3RmgTemplate
	{
		_H3API_SIZE_(0x38);
		H3String            name;      /**< @brief [00]*/
		H3Vector<H3RmgZone*> zones;     /**< @brief [10]*/
		h3unk8              _f_20[16]; /**< @brief [20]*/
		INT32               minSize;   /**< @brief [30]*/
		INT32               maxSize;   /**< @brief [34]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgTemplate);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgZoneConnection;

#pragma pack(push, 4)

	struct H3RmgZone
	{
		_H3API_SIZE_(0xD4);
		struct Treasure
		{
			INT32 lowValue;
			INT32 highValue;
			INT32 density;
		};
		typedef H3Vector<H3RmgZoneConnection> ZoneConnectionVec;

		INT32             id;                      /**< @brief [00]*/
		INT32             type;                    /**< @brief [04] 0..3 human-computer-treasure-junction*/
		INT32             baseSize;                /**< @brief [08]*/
		INT32             minHumanPositions;       /**< @brief [0C]*/
		INT32             maxHumanPositions;       /**< @brief [10]*/
		INT32             minTotalPositions;       /**< @brief [14]*/
		INT32             maxTotalPositions;       /**< @brief [18]*/
		INT32             townsOwner;              /**< @brief [1C]*/
		INT32             minPlayerTowns;          /**< @brief [20]*/
		INT32             minPlayerCastles;        /**< @brief [24]*/
		INT32             playerTownDensity;       /**< @brief [28]*/
		INT32             playerCastleDensity;     /**< @brief [2C]*/
		INT32             minNeutralTowns;         /**< @brief [30]*/
		INT32             minNeutralCastles;       /**< @brief [34]*/
		INT32             neutralTownsDensity;     /**< @brief [38]*/
		INT32             neutralCastlesDensity;   /**< @brief [3C]*/
		BOOL8             townsAreSameType;        /**< @brief [40]*/
		BOOL8             townTypes[9];            /**< @brief [41]*/
		INT32             minMines[7];             /**< @brief [4C]*/
		INT32             minesDensity[7];         /**< @brief [68]*/
		BOOL8             terrainMatchesTown;      /**< @brief [84]*/
		BOOL8             allowedTerrains[8];      /**< @brief [85]*/
		INT32             monsterStrength;         /**< @brief [90] 0/2/3/4 non/weak/average/strong*/
		BOOL8             monstersMatchTown;       /**< @brief [94]*/
		BOOL8             monstersAllowNeutrals;   /**< @brief [95]*/
		INT8              monstersAllowedTowns[9]; /**< @brief [96]*/
		Treasure      treasures[3];            /**< @brief [A0]*/
		ZoneConnectionVec connections;             /**< @brief [C4]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZone);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	struct H3RmgZoneConnection
	{
		_H3API_SIZE_(0x1C);
		H3RmgZone* zone;                  /**< @brief [00]*/
		INT32     value;                 /**< @brief [04]*/
		BOOL8     wide;                  /**< @brief [08]*/
		BOOL8     borderGuard;           /**< @brief [09]*/
		BOOL8     created;               /**< @brief [0A]*/
		INT32     minimumHumanPositions; /**< @brief [0C]*/
		INT32     maximumHumanPositions; /**< @brief [10]*/
		INT32     minimumTotalPositions; /**< @brief [14]*/
		INT32     maximumTotalPositions; /**< @brief [18]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneConnection);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	struct H3RmgZoneGenerator
	{
		_H3API_SIZE_(0x414);
		H3RmgZone*        zoneInfo;         /**< @brief [00]*/
		INT32            townType;         /**< @brief [04]*/
		INT32            townType2;        /**< @brief [08]*/
		INT32            ground;           /**< @brief [0C]*/
		INT32            x;                /**< @brief [10]*/
		INT32            y;                /**< @brief [14]*/
		INT32            z;                /**< @brief [18]*/
		INT32            size;             /**< @brief [1C]*/
		h3unk8           _f_20[4];         /**< @brief [20]*/
		h3unk8           _f_24[4];         /**< @brief [24]*/
		INT32            width;            /**< @brief [28]*/
		INT32            height;           /**< @brief [2C]*/
		h3unk8           _f_30[12];        /**< @brief [30]*/
		h3unk8           _f_3C[8];         /**< @brief [3C]*/
		INT32            objectCount[232]; /**< @brief [44]*/
		H3Vector<h3unk*> _f_3E4;           /**< @brief [3E4]*/
		H3Vector<h3unk*> _f_3F4;           /**< @brief [3F4]*/
		H3Vector<h3unk*> _f_404;           /**< @brief [404]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneGenerator);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
	struct H3Hero;
	struct H3MapitemMonster;

	struct H3Diplomacy
	{
		enum eDiploType
		{
			NO_HERO   = -3,
			FLEE      = -2,
			FIGHT     = -1,
			JOIN_FREE = 0,
		};

		_H3API_ static INT32 GetPowerFactor(FLOAT k);
		_H3API_ static INT32 DiplomacyJoinCost(H3Hero* hero, const H3MapitemMonster& creature);
	};
} /* namespace h3 */

namespace h3
{
	struct H3String;
	struct H3LoadedPcx16;
	class  H3Bitmap;

	class H3Bitmap
	{
	public:
		_H3API_ BOOL Create(const H3LoadedPcx16& pcx);
		_H3API_ BOOL Save(LPCSTR file_name);
		_H3API_ BOOL Save(const H3String& file_name);

	private:
		_H3API_ INT  height();
		_H3API_ BOOL init(INT width, INT height);

		BITMAPFILEHEADER  m_header;
		BITMAPINFOHEADER  m_info;
		UINT              m_scanline;
		UINT              m_dynamicSize;
		H3UniquePtr<BYTE> m_pixels;
	};

}

#if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND)

#include <eh.h>
#include <exception>
#include <Psapi.h>

namespace h3
{
	struct H3String;
	class  H3Exception;
	class  H3SEHandler;

	class H3Exception : public std::exception
	{
	public:
		_H3API_ H3Exception(LPCSTR message);
		_H3API_ H3Exception(const H3String& message);
		_H3API_ VOID ShowInGame(LPCSTR precursor_text = nullptr) const;
		_H3API_ BOOL ShowInGameLog(LPCSTR precursor_text = nullptr) const;
		_H3API_ VOID ShowMessagebox(LPCSTR precursor_text = nullptr) const;
		_H3API_ BOOL ShowMessageboxLog(LPCSTR precursor_text = nullptr) const;
		_H3API_ VOID LogError(LPCSTR path) const;
		_H3API_ VOID LogError(const H3String& path) const;

		_H3API_ static VOID ShowInGame(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static BOOL ShowInGameLog(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static VOID ShowMessagebox(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static BOOL ShowMessageboxLog(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static VOID LogError(const std::exception& e, LPCSTR path);
		_H3API_ static VOID LogError(const std::exception& e, const H3String& path);
	};

	class H3SEHandler
	{
		const _se_translator_function m_oldTranslator;
	public:
		_H3API_ H3SEHandler();
		_H3API_ ~H3SEHandler();
	};

}

#endif /* if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND) */

namespace h3
{
    template<typename T> class H3Tree;

    template<typename T>
    class H3Tree
    {
    private:
        class H3Node : public H3Allocator
        {
            friend class H3Tree;

            H3Node*    m_left;
            H3Node*    m_parent;
            H3Node*    m_right;
            T          m_data;
            BOOL8       m_black;

            H3Node* Next();
            H3Node* Previous();
            H3Node* LeftMost();

        public:
            H3Node();
            H3Node(const T& data);
        };

        H3Node  m_anchor;
        H3Node* m_begin;
        H3Node* m_end;
        UINT    m_size;

    public:
        class iterator
        {
            friend class H3Tree;
        public:
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);
            T& operator*() const;
            T* operator->() const;
            BOOL8 operator==(const iterator& it) const;
            BOOL8 operator!=(const iterator& it) const;
            iterator(H3Node* node);
        private:
            H3Node* m_ptr;
        };
        class const_iterator
        {
            friend class H3Tree;
        public:
            const_iterator& operator++();
            const_iterator operator++(int);
            const_iterator& operator--();
            const_iterator operator--(int);
            const T& operator*() const;
            const T* operator->() const;
            BOOL8 operator==(const const_iterator& it) const;
            BOOL8 operator!=(const const_iterator& it) const;
            const_iterator(H3Node* node);
        private:
            H3Node* m_ptr;
        };

        H3Tree();
        ~H3Tree();
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
        VOID Clear();
        BOOL8 Insert(const T& data);
        BOOL8 Erase(const T& data);
        BOOL8 Erase(iterator& it);
        iterator Find(const T& data);
        const_iterator Find(const T& data) const;
        UINT Size() const;

    private:
        H3Node* find(const T& data);
        BOOL8 erase(const T& data);
        BOOL8 erase(iterator& it);
        BOOL8 insert(const T& data);
        VOID insertionBalance(H3Node* node);
        VOID erasureBalance(H3Node* node, H3Node* parent);
        VOID rotateLeft(H3Node* node);
        VOID rotateRight(H3Node* node);
        VOID insertAt(H3Node* dst, H3Node* src);
    };

    template<typename T>
    inline H3Tree<T>::H3Node::H3Node() :
        m_data(), m_black(true), m_parent(), m_left(), m_right()
    {
    }

    template<typename T>
    inline H3Tree<T>::H3Node::H3Node(const T& data) :
        m_data(data), m_black(true), m_parent(), m_left(), m_right()
    {
    }

    template<typename T>
    inline typename H3Tree<T>::H3Node* H3Tree<T>::H3Node::Next()
    {
        H3Node* node;
        if (node = m_right)
        {
            while (node->m_left)
                node = node->m_left;
            return node;
        }
        node = this;
        H3Node* parent = m_parent;
        while (parent->m_left != node)
        {
            node = parent;
            parent = node->m_parent;
        }
        return parent;
    }

    template<typename T>
    inline typename H3Tree<T>::H3Node* H3Tree<T>::H3Node::Previous()
    {
        H3Node* node;
        if (node = m_left)
        {
            while (node->m_right)
                node = node->m_right;
            return node;
        }
        node = this;
        H3Node* parent = node->m_parent;
        while (parent->m_right != node)
        {
            node = parent;
            parent = node->m_parent;
        }
        return parent;
    }

    template<typename T>
    inline typename H3Tree<T>::H3Node* H3Tree<T>::H3Node::LeftMost()
    {
        H3Node* node = this;
        while (node->m_left)
            node = node->m_left;
        return node;
    }

    template<typename T>
    inline typename H3Tree<T>::iterator& H3Tree<T>::iterator::operator++()
    {
        m_ptr = m_ptr->Next();
        return *this;
    }

    template<typename T>
    inline typename H3Tree<T>::iterator H3Tree<T>::iterator::operator++(int)
    {
        iterator it(m_ptr);
        m_ptr = m_ptr->Next();
        return it;
    }

    template<typename T>
    inline typename H3Tree<T>::iterator& H3Tree<T>::iterator::operator--()
    {
        m_ptr = m_ptr->Previous();
        return *this;
    }

    template<typename T>
    inline typename H3Tree<T>::iterator H3Tree<T>::iterator::operator--(int)
    {
        iterator it(m_ptr);
        m_ptr = m_ptr->Previous();
        return it;
    }

    template<typename T>
    inline typename T& H3Tree<T>::iterator::operator*() const
    {
        return m_ptr->m_data;
    }

    template<typename T>
    inline typename T* H3Tree<T>::iterator::operator->() const
    {
        return &m_ptr->m_data;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::iterator::operator==(const iterator& it) const
    {
        return m_ptr == it.m_ptr;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::iterator::operator!=(const iterator& it) const
    {
        return m_ptr != it.m_ptr;
    }

    template<typename T>
    inline H3Tree<T>::iterator::iterator(H3Node* node) :
        m_ptr(node)
    {
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator& h3::H3Tree<T>::const_iterator::operator++()
    {
        m_ptr = next(m_ptr);
        return *this;
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::const_iterator::operator++(int)
    {
        const_iterator it(m_ptr);
        m_ptr = next(m_ptr);
        return it;
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator& H3Tree<T>::const_iterator::operator--()
    {
        m_ptr = previous(m_ptr);
        return *this;
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::const_iterator::operator--(int)
    {
        const_iterator it(m_ptr);
        m_ptr = previous(m_ptr);
        return it;
    }

    template<typename T>
    inline const T& H3Tree<T>::const_iterator::operator*() const
    {
        return m_ptr->m_data;
    }

    template<typename T>
    inline const T* H3Tree<T>::const_iterator::operator->() const
    {
        return &m_ptr->m_data;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::const_iterator::operator==(const const_iterator& it) const
    {
        return m_ptr == it.m_ptr;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::const_iterator::operator!=(const const_iterator& it) const
    {
        return m_ptr != it.m_ptr;
    }

    template<typename T>
    inline H3Tree<T>::const_iterator::const_iterator(H3Node* node) :
        m_ptr(node)
    {
    }

    template<typename T>
    inline H3Tree<T>::H3Tree() :
        m_anchor(), m_begin(m_end), m_end(&m_anchor), m_size(0)
    {
        m_anchor.m_parent = m_end;
    }

    template<typename T>
    inline H3Tree<T>::~H3Tree()
    {
        Clear();
    }

    template<typename T>
    inline typename H3Tree<T>::iterator H3Tree<T>::begin()
    {
        return iterator(m_begin);
    }

    template<typename T>
    inline typename H3Tree<T>::iterator H3Tree<T>::end()
    {
        return iterator(m_end);
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::begin() const
    {
        return const_iterator(m_begin);
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::end() const
    {
        return const_iterator(m_end);
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::cbegin() const
    {
        return const_iterator(m_begin);
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::cend() const
    {
        return const_iterator(m_end);
    }

    template<typename T>
    inline VOID H3Tree<T>::Clear()
    {
        for (H3Node* it = m_begin; it != m_end; )
        {
            H3Node* curr = it;
            it = it->Next();
            delete curr;
        }

        m_size = 0;
        m_begin = m_end;
        m_end = &m_anchor;
        m_anchor.m_parent = m_end;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::Insert(const T& data)
    {
        return insert(data);
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::Erase(const T& data)
    {
        return erase(data);
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::Erase(iterator& it)
    {
        return erase(it);
    }

    template<typename T>
    inline typename H3Tree<T>::iterator H3Tree<T>::Find(const T& data)
    {
        return iterator(find(data));
    }

    template<typename T>
    inline typename H3Tree<T>::const_iterator H3Tree<T>::Find(const T& data) const
    {
        return const_iterator(find(data));
    }

    template<typename T>
    inline UINT H3Tree<T>::Size() const
    {
        return m_size;
    }

    template<typename T>
    inline typename H3Tree<T>::H3Node* H3Tree<T>::find(const T& data)
    {
        H3Node* root = m_end;
        H3Node* node = m_end->m_left;

        while (node)
        {
            if (node->m_data < data)
                node = node->m_right;
            else
            {
                root = node;
                node = node->m_left;
            }
        }

        if (root == m_end || data < root->m_data)
            return m_end;
        return root;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::erase(const T& data)
    {
        return erase(find(data));
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::erase(iterator& it)
    {
        if (it == end())
            return false;

        H3Node* node = it.m_ptr;
        H3Node* root;
        H3Node* parent;
        H3Node* temp = node;
        BOOL8 yblack = temp->m_black;

        if (!node->m_left)
        {
            root = node->m_right;
            if (node == m_begin)
                m_begin = node->Next();
            insertAt(node, node->m_right);
            parent = temp->m_parent;
        }
        else if (!node->m_right)
        {
            root = node->m_left;
            insertAt(node, node->m_left);
            parent = temp->m_parent;
        }
        else
        {
            temp = node->LeftMost();
            yblack = temp->m_black;
            root = temp->m_right;
            if (temp->m_parent != node)
            {
                insertAt(temp, temp->m_right);
                temp->m_right = node->m_right;
                temp->m_right->m_parent = temp;
                parent = temp->m_parent;
            }
            else
                parent = temp;
            insertAt(node, temp);
            temp->m_left = node->m_left;
            temp->m_left->m_parent = temp;
            temp->m_black = node->m_black;
        }

        if (yblack)
            erasureBalance(root, parent);

        --m_size;
        delete node;
    }

    template<typename T>
    inline BOOL8 H3Tree<T>::insert(const T& data)
    {
        H3Node* left = m_end->m_left;
        H3Node* node = m_end;
        BOOL8 is_smaller = true;
        while (left)
        {
            node = left;
            is_smaller = data < left->m_data;
            left = is_smaller ? left->m_left : left->m_right;
        }

        H3Node* right = node;
        if (is_smaller) // left
        {
            if (node == m_end) // tree is empty, set new root
            {
                H3Node* new_node = new H3Node(data);
                ++m_size;
                m_begin = new_node;
                m_end->m_left = new_node;
                m_end->m_right = new_node;
                new_node->m_parent = m_end;
                insertionBalance(new_node);
                return true;
            }
            else if (node == m_begin)
            {
                H3Node* new_node = new H3Node(data);
                ++m_size;

                m_begin = new_node;
                node->m_left = new_node;
                new_node->m_parent = node;

                insertionBalance(new_node);
                return true;
            }
            else
            {
                H3Node* parent = right->m_parent;
                while (right != parent->m_right)
                {
                    right = parent;
                    parent = right->m_parent;
                }
                right = parent;

                if (right->m_data < data)
                {
                    H3Node* new_node = new H3Node(data);
                    ++m_size;

                    node->m_left = new_node;
                    new_node->m_parent = node;

                    insertionBalance(new_node);
                    return true;
                }
                return false;
            }
        }

        if (right->m_data < data)
        {
            H3Node* new_node = new H3Node(data);
            ++m_size;
            node->m_right = new_node;
            new_node->m_parent = node;
            insertionBalance(new_node);
            return true;
        }
        return false;
    }

    template<typename T>
    inline VOID H3Tree<T>::insertionBalance(H3Node* node)
    {
        H3Node* uncle;

        node->m_black = false;

        while (!node->m_parent->m_black)
        {
            if (node->m_parent == node->m_parent->m_parent->m_left)
            {
                uncle = node->m_parent->m_parent->m_right;

                if (uncle && !uncle->m_black)
                {
                    node->m_parent->m_black = true;
                    uncle->m_black = true;
                    node->m_parent->m_parent->m_black = false;
                    node = node->m_parent->m_parent;
                }
                else {
                    if (node == node->m_parent->m_right)
                    {
                        node = node->m_parent;
                        rotateLeft(node);
                    }
                    node->m_parent->m_black = true;
                    node->m_parent->m_parent->m_black = false;

                    rotateRight(node->m_parent->m_parent);
                }
            }
            else {
                uncle = node->m_parent->m_parent->m_left;
                if (uncle && !uncle->m_black)
                {
                    node->m_parent->m_black = true;
                    uncle->m_black = true;
                    node->m_parent->m_parent->m_black = false;
                    node = node->m_parent->m_parent;
                }
                else
                {
                    if (node == node->m_parent->m_left)
                    {
                        node = node->m_parent;
                        rotateRight(node);
                    }
                    node->m_parent->m_black = true;
                    node->m_parent->m_parent->m_black = false;

                    rotateLeft(node->m_parent->m_parent);
                }
            }
        }
        m_end->m_left->m_black = true;
    }

    template<typename T>
    inline VOID H3Tree<T>::erasureBalance(H3Node* node, H3Node* parent)
    {
        while (node != m_end->m_left && (!node || node->m_black))
        {
            if (node == parent->m_left)
            {
                H3Node* sibling = parent->m_right;
                if (!sibling->m_black)
                {
                    sibling->m_black = true;
                    parent->m_black = false;
                    rotateLeft(parent);
                    sibling = parent->m_right;
                }
                if ((!sibling->m_left || sibling->m_left->m_black) && (!sibling->m_right || sibling->m_right->m_black))
                {
                    sibling->m_black = false;
                    node = parent;
                    parent = parent->m_parent;
                }
                else {
                    if (!sibling->m_right || sibling->m_right->m_black)
                    {
                        if (sibling->m_left)
                            sibling->m_left->m_black = true;
                        sibling->m_black = false;
                        rotateRight(sibling);
                        sibling = parent->m_right;
                    }
                    sibling->m_black = parent->m_black;
                    parent->m_black = true;
                    if (sibling->m_right)
                        sibling->m_right->m_black = true;
                    rotateLeft(parent);
                    node = m_end->m_left;
                }
            }
            else {
                H3Node* sibling = parent->m_left;
                if (!sibling->m_black)
                {
                    sibling->m_black = true;
                    parent->m_black = false;
                    rotateRight(parent);
                    sibling = parent->m_left;
                }
                if ((!sibling->m_left || sibling->m_left->m_black) && (!sibling->m_right || sibling->m_right->m_black))
                {
                    sibling->m_black = false;
                    node = parent;
                    parent = parent->m_parent;
                }
                else
                {
                    if (!sibling->m_left || sibling->m_left->m_black)
                    {
                        if (sibling->m_right)
                            sibling->m_right->m_black = true;
                        sibling->m_black = false;
                        rotateLeft(sibling);
                        sibling = parent->m_left;
                    }
                    sibling->m_black = parent->m_black;
                    parent->m_black = true;
                    if (sibling->m_left)
                        sibling->m_left->m_black = true;
                    rotateRight(parent);
                    node = m_end->m_left;
                }
            }
        }
        if (node)
            node->m_black = true;
    }

    template<typename T>
    inline VOID H3Tree<T>::rotateLeft(H3Node* node)
    {
        H3Node* tmp = node->m_right;

        node->m_right = tmp->m_left;
        if (tmp->m_left)
            tmp->m_left->m_parent = node;

        tmp->m_parent = node->m_parent;

        if (node->m_parent == m_end)
        {
            m_end->m_left = tmp;
            m_end->m_right = tmp;
            tmp->m_parent = m_end;
        }
        else if (node == node->m_parent->m_left)
            node->m_parent->m_left = tmp;
        else
            node->m_parent->m_right = tmp;

        tmp->m_left = node;
        node->m_parent = tmp;
    }

    template<typename T>
    inline VOID H3Tree<T>::rotateRight(H3Node* node)
    {
        H3Node* tmp = node->m_left;
        node->m_left = tmp->m_right;
        if (tmp->m_right)
            tmp->m_right->m_parent = node;

        tmp->m_parent = node->m_parent;
        if (node->m_parent == m_end)
        {
            m_end->m_left = tmp;
            m_end->m_right = tmp;
            tmp->m_parent = m_end;
        }
        else if (node == node->m_parent->m_right)
            node->m_parent->m_right = tmp;
        else
            node->m_parent->m_left = tmp;

        tmp->m_right = node;
        node->m_parent = tmp;
    }

    template<typename T>
    inline VOID H3Tree<T>::insertAt(H3Node* dst, H3Node* node)
    {
        if (dst->m_parent == m_end)
        {
            m_end->m_left = node;
            m_end->m_right = node;
        }
        else if (dst == dst->m_parent->m_left)
            dst->m_parent->m_left = node;
        else
            dst->m_parent->m_right = node;

        if (node)
            node->m_parent = dst->m_parent;
    }
}

namespace h3
{
	struct HDIniEntry;
	struct HDIni;
	class  H3Ini;
	class  H3IniLine;
	class  H3IniSection;
	class  H3Ini;

#pragma pack(push, 1)
	struct HDIniEntry
	{
		_H3API_ENUM_ eType : BYTE
		{
			INI_VALUE = 2,
			INI_TEXT  = 3,
			INI_KEY   = 4
		};

		union
		{
			LPCSTR text;
			UINT32 value;
		}data;              /**< @brief [00] integer if INI_VALUE, otherwise LPCSTR*/
		eType  entryType;   /**< @brief [04]*/
		DWORD  entryCount;  /**< @brief [05] how many values are associated to this key*/
		LPCSTR uselessText; /**< @brief [09] linking characters in between entries like " = "*/

		_H3API_ LPCSTR GetText();
	};
#pragma pack(pop)

#pragma pack(push, 4)
	struct HDIni
	{
		HDIniEntry** entries;     /**< @brief [00] pointer to array of entry pointers*/
		UINT         lineEntries; /**< @brief [04] how many entries are available*/
		h3unk        _f_08[4];    /**< @brief [08]*/
		CHAR         name[8];     /**< @brief [0C] unknown length, 8 as placeholder*/

		struct iterator
		{
		protected:
			HDIniEntry** m_entry;
		public:
			_H3API_ iterator(HDIniEntry** entries);
			_H3API_ HDIniEntry* operator->();
			_H3API_ iterator&   operator++();
			_H3API_ iterator    operator++(int);
			_H3API_ iterator&   operator*();
			_H3API_ BOOL8       operator==(const iterator& other) const;
			_H3API_ BOOL8       operator!=(const iterator& other) const;
			_H3API_ HDIniEntry* operator[](UINT index);
		};

		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ iterator FindEntry(LPCSTR key);
	};

	class H3IniLine
	{
	public:
		friend class H3Ini;
		friend class H3IniSection;

		enum LineType : UINT
		{
			EMPTY    = 0,
			COMMENT  = 1,
			SECTION  = 2,
			KEY      = 4,
			SEARCHED = 8,
			ALL      = EMPTY | COMMENT | SECTION | KEY,
		};
	private:
		UINT     m_type;
		H3String m_content;
		H3String m_value;

		_H3API_ INT matches(const H3String& key);
		_H3API_ INT matches(LPCSTR key);
		_H3API_ BOOL8 write(H3String& new_ini);

	public:
		_H3API_ H3IniLine();
#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3IniLine(LineType type, H3String&& content);
		_H3API_ H3IniLine(H3String&& content, H3String&& value);
#else
		_H3API_ H3IniLine(LineType type, const H3String& content);
		_H3API_ H3IniLine(const H3String& content, const H3String& value);
#endif
		_H3API_ INT      GetInteger(INT default_value);
		_H3API_ bool     GetBool(bool default_value);
		_H3API_ FLOAT    GetFloat(FLOAT default_value);
		_H3API_ DOUBLE   GetDouble(DOUBLE default_value);
		_H3API_ H3String GetString(const H3String& default_value);
		_H3API_ UINT     GetHex(UINT default_value);
		_H3API_ BOOL8 SetBool(bool value);
		_H3API_ BOOL8 SetInteger(INT value);
		_H3API_ BOOL8 SetFloat(FLOAT value);
		_H3API_ BOOL8 SetDouble(DOUBLE value);
		_H3API_ BOOL8 SetString(const H3String& value);
		_H3API_ BOOL8 SetHex(UINT value);
	};

	class H3IniSection
	{
		friend class H3Ini;

	public:
		class iterator
		{
		public:
			_H3API_ iterator(H3IniLine** key);
			_H3API_ H3IniLine& operator*();
			_H3API_ H3IniLine* operator->();
			_H3API_ BOOL8      operator!=(const iterator& other);
			_H3API_ BOOL8      operator==(const iterator& other);
			_H3API_ iterator&  operator++();
			_H3API_ iterator   operator++(int);

		private:
			H3IniLine** data;
		};

		_H3API_ H3IniSection();
		_H3API_ H3IniSection(const H3IniLine* associated_line);

		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ iterator Get(LPCSTR key);
		_H3API_ iterator operator[](LPCSTR key);
		_H3API_ BOOL8 SetBool(LPCSTR key, bool value);
		_H3API_ BOOL8 SetInteger(LPCSTR key, INT value);
		_H3API_ BOOL8 SetString(LPCSTR key, const H3String& value);
		_H3API_ BOOL8 SetFloat(LPCSTR key, FLOAT value);
		_H3API_ BOOL8 SetDouble(LPCSTR key, DOUBLE value);
		_H3API_ BOOL8 SetHex(LPCSTR key, UINT value);
		_H3API_ bool     GetBool(LPCSTR key, bool default_value);
		_H3API_ INT      GetInteger(LPCSTR key, INT default_value);
		_H3API_ FLOAT    GetFloat(LPCSTR key, FLOAT default_value);
		_H3API_ DOUBLE   GetDouble(LPCSTR key, DOUBLE default_value);
		_H3API_ H3String GetString(LPCSTR key, const H3String& default_value);
		_H3API_ UINT     GetHex(LPCSTR key, UINT default_value);

	private:
		const H3String*      m_name;
		H3Vector<H3IniLine*> m_keys;
		BOOL                 m_searched;
	};

	class H3Ini
	{
	public:
		class iterator
		{
		public:
			_H3API_ iterator(H3IniSection* section);
			_H3API_ H3IniSection& operator*();
			_H3API_ H3IniSection* operator->();
			_H3API_ BOOL8 operator!=(const iterator& other);
			_H3API_ BOOL8 operator==(const iterator& other);
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ H3IniSection::iterator operator[](LPCSTR key);
		private:
			H3IniSection* data;
		};
		_H3API_ BOOL8 Open(LPCSTR file);
		_H3API_ BOOL8 Save(LPCSTR file, BOOL utf8);
		_H3API_ iterator Get(LPCSTR section);
		_H3API_ iterator operator[](LPCSTR section);
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ bool     GetBool(LPCSTR section, LPCSTR key, bool default_value);
		_H3API_ INT      GetInteger(LPCSTR section, LPCSTR key, INT default_value);
		_H3API_ FLOAT    GetFloat(LPCSTR section, LPCSTR key, FLOAT default_value);
		_H3API_ DOUBLE   GetDouble(LPCSTR section, LPCSTR key, DOUBLE default_value);
		_H3API_ H3String GetString(LPCSTR section, LPCSTR key, const H3String& default_value);
		_H3API_ UINT     GetHex(LPCSTR section, LPCSTR key, UINT default_value);
		_H3API_ BOOL8 SetBool(LPCSTR section, LPCSTR key, bool value);
		_H3API_ BOOL8 SetInteger(LPCSTR section, LPCSTR key, INT value);
		_H3API_ BOOL8 SetFloat(LPCSTR section, LPCSTR key, FLOAT value);
		_H3API_ BOOL8 SetDouble(LPCSTR section, LPCSTR key, DOUBLE value);
		_H3API_ BOOL8 SetString(LPCSTR section, LPCSTR key, const H3String& value);
		_H3API_ BOOL8 SetHex(LPCSTR section, LPCSTR key, UINT value);

	private:
		H3Vector<H3IniLine>     m_lines;
		H3Vector<H3IniSection>  m_sections;
	};
#pragma pack(pop)

}

namespace h3
{
	class  H3Protect;
	struct H3DLL;

	class H3Protect
	{
		UINT32 m_address;
		UINT32 m_size;
		DWORD  m_oldProtect;
		BOOL   m_protectEdited;
	public:
		_H3API_ H3Protect(UINT32 address, UINT32 size);
		_H3API_ ~H3Protect();
		_H3API_ BOOL CanWrite();
	};

	namespace H3Patcher
	{
		_H3API_ VOID Breakpoint();

		enum mnemonics
		{
			INC_EAX    = 0x40,
			INC_ECX    = 0x41,
			INC_EDX    = 0x42,
			INC_EBX    = 0x43,
			INC_ESP    = 0x44,
			INC_EBP    = 0x45,
			INC_ESI    = 0x46,
			INC_EDI    = 0x47,
			DEC_EAX    = 0x48,
			DEC_ECX    = 0x49,
			DEC_EDX    = 0x4A,
			DEC_EBX    = 0x4B,
			DEC_ESP    = 0x4C,
			DEC_EBP    = 0x4D,
			DEC_ESI    = 0x4E,
			DEC_EDI    = 0x4F,
			PUSH_EAX   = 0x50,
			PUSH_ECX   = 0x51,
			PUSH_EDX   = 0x52,
			PUSH_EBX   = 0x53,
			PUSH_ESP   = 0x54,
			PUSH_EBP   = 0x55,
			PUSH_ESI   = 0x56,
			PUSH_EDI   = 0x57,
			POP_EAX    = 0x58,
			POP_ECX    = 0x59,
			POP_EDX    = 0x5A,
			POP_EBX    = 0x5B,
			POP_ESP    = 0x5C,
			POP_EBP    = 0x5D,
			POP_ESI    = 0x5E,
			POP_EDI    = 0x5F,
			PUSHAD     = 0x60,
			POPAD      = 0x61,
			PUSH_DWORD = 0x68,
			PUSH_BYTE  = 0x6A,
			SHORT_JO   = 0x70,
			SHORT_JNO  = 0x71,
			SHORT_JB   = 0x72,
			SHORT_JNB  = 0x73,
			SHORT_JZ   = 0x74,
			SHORT_JNZ  = 0x75,
			SHORT_JNA  = 0x76,
			SHORT_JA   = 0x77,
			SHORT_JS   = 0x78,
			SHORT_JNS  = 0x79,
			SHORT_JP   = 0x7A,
			SHORT_JNP  = 0x7B,
			SHORT_JL   = 0x7C,
			SHORT_JGE  = 0x7D, // JNL
			SHORT_JNG  = 0x7E,
			SHORT_JG   = 0x7F,
			NOP        = 0x90,
			PUSHFD     = 0x9C,
			POPFD      = 0x9D,
			CALL       = 0xE8,
			JMP        = 0xE9,
			SHORT_JMP  = 0xEB,
			_RETN_     = 0xC3,
			_RETNX_    = 0xC2,

			FAR_JO     = 0x0F80,
			FAR_JNO    = 0x0F81,
			FAR_JB     = 0x0F82,
			FAR_JNB    = 0x0F83,
			FAR_JZ     = 0x0F84,
			FAR_JNZ    = 0x0F85,
			FAR_JNA    = 0x0F86,
			FAR_JA     = 0x0F87,
			FAR_JS     = 0x0F88,
			FAR_JNS    = 0x0F89,
			FAR_JP     = 0x0F8A,
			FAR_JNP    = 0x0F8B,
			FAR_JL     = 0x0F8C,
			FAR_JNL    = 0x0F8D,
			FAR_JNG    = 0x0F8E,
			FAR_JG     = 0x0F8F,
			CALL_DWORD = 0x15FF,
		};

		_H3API_ PUCHAR Memmem(PUCHAR haystack, size_t hlen, PUCHAR needle, size_t nlen);
		_H3API_ UINT32 FindByNeedle(PUINT8 address, UINT32 max_search_length, PUINT8 needle, INT32 needle_length, INT32 offset);

#ifndef _H3API_NAKED_FUNCTION_
#define _H3API_NAKED_FUNCTION_ VOID __declspec(naked)
#endif

		_H3API_ BOOL NakedHook5(UINT32 address, H3NakedFunction function);
		_H3API_ BOOL NakedHook(UINT32 address, H3NakedFunction function, UINT32 total_bytes);
		template<typename T>
		BOOL WriteValue(ADDRESS address, const T value);

		template<typename T, size_t size>
		BOOL WriteValues(const UINT address, const T(&value)[size]);

		template<typename T>
		BOOL AddressOfPatch(const UINT address, const T& data);
		template<typename Type, size_t size>
		inline BOOL AddressOfPatch(const ADDRESS(&address)[size], const Type& data);
		template<typename T>
		BOOL ObjectPatch(T& reference, T data);
		template<size_t size>
		BOOL HexPatch(const UINT address, const BYTE(&value)[size]);

		_H3API_ BOOL BytePatch(ADDRESS address, UINT8 value);
		_H3API_ BOOL CharPatch(ADDRESS address, INT8 value);
		_H3API_ BOOL WordPatch(ADDRESS address, UINT16 value);
		_H3API_ BOOL ShortPatch(ADDRESS address, INT16 value);
		_H3API_ BOOL DwordPatch(ADDRESS address, UINT32 value);
		_H3API_ BOOL IntPatch(ADDRESS address, INT32 value);
		_H3API_ BOOL FloatPatch(ADDRESS address, FLOAT value);
		_H3API_ BOOL DoublePatch(ADDRESS address, DOUBLE value);

		template<ADDRESS _Address, typename Type>
		class ScopedPatch
		{
		public:
			ScopedPatch(Type new_value);
			~ScopedPatch();
		private:
			Type m_oldValue;
		};
	}
	template<ADDRESS _Address, typename Type>
	class H3ValueBackup
	{
	public:
		H3ValueBackup();
		H3ValueBackup(Type new_value);
		~H3ValueBackup();
		VOID operator=(Type new_value);
		Type operator*();
		BOOL operator==(Type value);
		Type operator+=(Type value);
		Type operator-=(Type value);
		Type operator++();
		Type operator++(int);
		Type operator--();
		Type operator--(int);
	private:
		Type& get();
		Type m_originalValue;
	};

	struct H3DLL
	{
		PUINT8 code;
		UINT32 size;
		LPCSTR dllName;
		PUINT8 rdata;
		UINT32 rdataSize;
		PUINT8 data;
		UINT32 dataSize;

		_H3API_ H3DLL();
		_H3API_ H3DLL(LPCSTR dll_name);

	protected:
		_H3API_ VOID needleNotFound(PUINT8 needle, INT32 needle_size, BOOL in_code = TRUE) const;
		_H3API_ VOID needleUnexpectedCode(UINT32 address, PUINT8 needle, INT32 needle_size, PUINT8 expected_code, INT32 expected_size) const;
		_H3API_ VOID processNotFound() const;
	public:
		_H3API_ BOOL GetDLLInfo(LPCSTR name);
		_H3API_ UINT32 NeedleSearch(PUINT8 needle, INT32 needle_size, INT32 offset);
		_H3API_ UINT32 NeedleSearchAround(PUINT8 needle, INT32 needle_size, INT32 radius, PUINT8 needle2, INT32 needle_size2);
		_H3API_ UINT32 NeedleSearchAfter(UINT32 after, const PUINT8 needle, INT32 needle_size, INT32 offset) const;
		_H3API_ UINT32 NeedleSearchConfirm(PUINT8 needle, INT32 needle_size, INT32 offset, PUINT8 expected_code, INT32 expected_size);
		_H3API_ UINT32 NeedleSearchRData(PUINT8 needle, INT32 needle_size) const;
		_H3API_ UINT32 NeedleSearchData(PUINT8 needle, INT32 needle_size) const;
		template <INT32 sz>
		UINT32 NeedleSearch(const UINT8(&needle)[sz], INT32 offset);
		template <INT32 sz, INT32 sz2>
		UINT32 NeedleSearchAround(const UINT8(&needle)[sz], INT32 radius, const UINT8(&needle2)[sz2]);
		template <INT32 sz>
		UINT32 NeedleSearchAfter(UINT32 after, const UINT8(&needle)[sz], INT32 offset);
		template <INT32 sz, INT32 sz2>
		UINT32 NeedleSearchConfirm(const UINT8(&needle)[sz], INT32 offset, const UINT8(&expected_code)[sz2]);
		template <INT32 sz>
		UINT32 NeedleSearchRData(const UINT8(&needle)[sz]);
		template <INT32 sz>
		UINT32 NeedleSearchData(const UINT8(&needle)[sz]);
	};

	template<typename T>
	inline BOOL H3Patcher::WriteValue(ADDRESS address, const T value)
	{
		H3Protect protect(address, sizeof(T));
		if (!protect.CanWrite())
			return FALSE;
		ValueAt<T>(address) = value;
		return TRUE;
	}

	template<typename T, size_t size>
	BOOL H3Patcher::WriteValues(const UINT address, const T(&value)[size])
	{
		H3Protect protect(address, sizeof(T) * size);
		if (!protect.CanWrite())
			return FALSE;
		for (size_t i = 0; i < size; ++i)
			ValueAt<T>(address + i) = value[i];
		return TRUE;
	}
	template<typename T>
	BOOL H3Patcher::AddressOfPatch(const UINT address, const T& data)
	{
		return DwordPatch(address, AddressOf(data));
	}
	template<typename Type, size_t size>
	inline BOOL H3Patcher::AddressOfPatch(const ADDRESS(&address)[size], const Type& data)
	{
		for (size_t i = 0; i < size; ++i)
			if (!DwordPatch(address[i], AddressOf(data)))
				return FALSE;
		return TRUE;
	}
	template<typename T>
	BOOL H3Patcher::ObjectPatch(T& reference, T data)
	{
		return WriteValue<T>(AddressOf(reference), data);
	}
	template<size_t size>
	inline BOOL H3Patcher::HexPatch(const UINT address, const BYTE(&value)[size])
	{
		return WriteValues<BYTE, size>(address, value);
	}
	template<ADDRESS _Address, typename Type>
	inline H3Patcher::ScopedPatch<_Address, Type>::ScopedPatch(Type new_value) :
		m_oldValue(ValueAt<Type>(_Address))
	{
		WriteValue<Type>(_Address, new_value);
	}
	template<ADDRESS _Address, typename Type>
	inline H3Patcher::ScopedPatch<_Address, Type>::~ScopedPatch()
	{
		WriteValue<Type>(_Address, m_oldValue);
	}
	template<INT32 sz>
	inline UINT32 H3DLL::NeedleSearch(const UINT8(&needle)[sz], INT32 offset)
	{
		return NeedleSearch(PUINT8(needle), sz, offset);
	}
	template<INT32 sz, INT32 sz2>
	inline UINT32 H3DLL::NeedleSearchAround(const UINT8(&needle)[sz], INT32 radius, const UINT8(&needle2)[sz2])
	{
		return NeedleSearchAround(PUINT8(needle), sz, radius, PUINT8(needle2), sz2);
	}
	template<INT32 sz>
	inline UINT32 H3DLL::NeedleSearchAfter(UINT32 after, const UINT8(&needle)[sz], INT32 offset)
	{
		return NeedleSearchAfter(after, PUINT8(needle), sz, offset);
	}
	template<INT32 sz, INT32 sz2>
	inline UINT32 H3DLL::NeedleSearchConfirm(const UINT8(&needle)[sz], INT32 offset, const UINT8(&expectedCode)[sz2])
	{
		return NeedleSearchConfirm(PUINT8(needle), sz, offset, &expectedCode, sz2);
	}
	template<INT32 sz>
	inline UINT32 H3DLL::NeedleSearchRData(const UINT8(&needle)[sz])
	{
		return NeedleSearchRData(PUINT8(needle), sz);
	}
	template<INT32 sz>
	inline UINT32 H3DLL::NeedleSearchData(const UINT8(&needle)[sz])
	{
		return NeedleSearchData(PUINT8(needle), sz);
	}

	template<ADDRESS _Address, typename Type>
	H3ValueBackup<_Address, Type>::H3ValueBackup() :
		m_originalValue(get())
	{
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator--(int)
	{
		Type value = get();
		--(*this);
		return value;
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator--()
	{
		return (*this) -= static_cast<Type>(1);
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator++(int)
	{
		Type value = get();
		++(*this);
		return value;
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator++()
	{
		return (*this) += static_cast<Type>(1);
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator-=(Type value)
	{
		get() -= value;
		return get();
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator+=(Type value)
	{
		get() += value;
		return get();
	}
	template<ADDRESS _Address, typename Type>
	BOOL H3ValueBackup<_Address, Type>::operator==(Type value)
	{
		return get() == value;
	}
	template<ADDRESS _Address, typename Type>
	Type H3ValueBackup<_Address, Type>::operator*()
	{
		return get();
	}
	template<ADDRESS _Address, typename Type>
	VOID H3ValueBackup<_Address, Type>::operator=(Type new_value)
	{
		get() = new_value;
	}
	template<ADDRESS _Address, typename Type>
	H3ValueBackup<_Address, Type>::~H3ValueBackup()
	{
		get() = m_originalValue;
	}
	template<ADDRESS _Address, typename Type>
	H3ValueBackup<_Address, Type>::H3ValueBackup(Type new_value) :
		m_originalValue(get())
	{
		get() = new_value;
	}
	template<ADDRESS _Address, typename Type>
	Type& H3ValueBackup<_Address, Type>::get()
	{
		return ValueAt<Type>(_Address);
	}
}

namespace h3
{
	class H3Path;
	class H3DirectoryChanger;
	class H3DirectoryTraveler;

	class H3Path
	{
	public:
		_H3API_ static BOOL     IsDirectory(LPCSTR name);
		_H3API_ static BOOL     IsDirectory(DWORD attribute);
		_H3API_ static BOOL     IsFile(LPCSTR name);
		_H3API_ static BOOL     IsFile(DWORD attribute);
		_H3API_ static BOOL     IsValid(LPCSTR name);
		_H3API_ static BOOL     IsValid(DWORD attribute);
		_H3API_ static BOOL     FileExists(LPCSTR name);
		_H3API_ static BOOL     FileExists(DWORD attribute);
		_H3API_ static BOOL     CreateDir(const H3String& dir);
		_H3API_ static DWORD    GetAttributes(LPCSTR name);
		_H3API_ static H3String CurrentDirectory();
		_H3API_ static H3String ProcessPath();
		_H3API_ static H3String ModulePath(HMODULE hmodule);
		_H3API_ static H3String GetDir(const H3String& path);
		_H3API_ static H3String DirUp(const H3String& dir);
		_H3API_ static H3String GetPathName(const H3String& file);
		_H3API_ static H3String GetPathName(LPCSTR file);
		_H3API_ static LPCSTR   Extension(LPCSTR file_name);
		_H3API_ static LPCSTR   Extension(const H3String& file_name);
		_H3API_ static INT32    GetModuleFileNameA(HMODULE hmodule, PCHAR buf, INT buf_len);
		_H3API_ static H3String GetModuleFileNameA(HMODULE hmodule);

		class iterator
		{
		public:
			_H3API_ iterator(const H3String& filename);
			_H3API_ iterator(HANDLE handle);
			_H3API_ ~iterator();
			_H3API_ iterator& operator*();
			_H3API_ iterator& operator++();
			_H3API_ LPCSTR    Extension() const;
			_H3API_ H3String  FilePath() const;
			_H3API_ LPCSTR    FileName() const;
			_H3API_ DWORD     Attributes() const;
			_H3API_ DWORD     FilseSize() const;
			_H3API_ BOOL      IsDirectory() const;
			_H3API_ BOOL      IsFile() const;
			_H3API_ BOOL      IsValid() const;
			_H3API_ BOOL      FileExists() const;
			_H3API_ BOOL      operator==(const iterator& other) const;
			_H3API_ BOOL      operator!=(const iterator& other) const;
		private:
			HANDLE m_handle;
			WIN32_FIND_DATAA m_data;
		};

	public:
		_H3API_ H3Path(const H3Path& path);
		_H3API_ H3Path(const H3String& path);
		_H3API_ H3Path(LPCSTR path);

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3Path(H3Path&& path);
		_H3API_ H3Path& operator=(H3Path&& path);
#endif
		_H3API_ iterator begin() const;
		_H3API_ iterator end() const;

		_H3API_ H3Path&  operator=(const H3Path& path);
		_H3API_ H3Path&  operator+=(const H3Path& path);
		_H3API_ H3Path   operator/(const H3Path& path);
		_H3API_ H3Path&  operator/=(const H3Path& path);
		_H3API_ BOOL     operator!=(const H3Path& path) const;
		_H3API_ BOOL     operator==(const H3Path& path) const;
		_H3API_ H3Path&  Append(const H3Path& path);
		_H3API_ BOOL     IsValid() const;
		_H3API_ BOOL     IsDirectory() const;
		_H3API_ BOOL     IsFile() const;
		_H3API_ BOOL     IsRoot() const;
		_H3API_ BOOL     CreateDir() const;
		_H3API_ BOOL     FileExists() const;
		_H3API_ BOOL     ReplaceExtension(const H3String& ext);
		_H3API_ H3String GetExtension() const;
		_H3API_ operator LPCSTR() const;
		_H3API_ const H3String& GetPath() const;
	private:
		H3String m_path;
		DWORD    m_attributes;
	};

	class H3DirectoryChanger
	{
	public:
		_H3API_ H3DirectoryChanger(LPCSTR dir);
		_H3API_ H3DirectoryChanger(const H3String& dir);
		_H3API_ H3DirectoryChanger(const H3Path& dir);
		_H3API_ ~H3DirectoryChanger();
		_H3API_ BOOL Status() const;
	private:
		H3String m_oldDir;
		BOOL     m_status;
	};

	class H3DirectoryTraveler
	{
	public:
		class iterator
		{
		public:
			_H3API_ iterator();
			_H3API_ iterator(LPCSTR filename, H3DirectoryTraveler* parent);
			_H3API_ ~iterator();

			_H3API_ iterator& operator++();
			_H3API_ iterator& operator*();
			_H3API_ LPCSTR    Extension() const;
			_H3API_ H3String  FilePath() const;
			_H3API_ LPCSTR    FileName() const;
			_H3API_ DWORD     Attributes() const;
			_H3API_ DWORD     FilseSize() const;
			_H3API_ BOOL      IsDirectory() const;
			_H3API_ BOOL      IsFile() const;
			_H3API_ BOOL      IsValid() const;
			_H3API_ BOOL      FileExists() const;
			_H3API_ BOOL8     operator==(const iterator& other) const;
			_H3API_ BOOL8     operator!=(const iterator& other) const;
		protected:
			_H3API_ BOOL32 isNotRelativeDir() const;
			_H3API_ BOOL32 next();

		private:
			HANDLE               m_handle;
			WIN32_FIND_DATAA     m_data;
			H3DirectoryTraveler* m_parent;
		};

		_H3API_ H3DirectoryTraveler(const H3String& file_type = "", INT32 max_depth = -1);
		_H3API_ H3DirectoryTraveler(const H3Path& directory, const H3String& file_type, INT32 max_depth);
		_H3API_ ~H3DirectoryTraveler();

		_H3API_ iterator begin();
		_H3API_ iterator end();

	protected:
		_H3API_ H3String& currentDir() const;
		_H3API_ BOOL32    remainingDirectories() const;
		_H3API_ BOOL32    setDirectory(const H3String& directory);
		_H3API_ VOID      addDirectory(LPCSTR filename);
		_H3API_ VOID      decreaseDepth();
		_H3API_ VOID      newDepthCheck();
		_H3API_ HANDLE    nextDirectoryIteration(WIN32_FIND_DATAA& data);
	private:
		H3String           m_startDirectory;
		H3String           m_type;
		H3Vector<H3String> m_directories;
		UINT32             m_index;
		UINT32             m_nextDepthIndex;
		INT32              m_maxDepth;
	};

}

#ifdef _H3API_PLUGINS_

namespace h3
{
	struct H3LoadedPcx;
	struct H3WavFile;
	struct H3LoadedDef;
	struct H3LoadedPcx16;
	struct H3String;
	template<typename _Elem> struct H3Vector;

namespace H3Plugin
{
	namespace AssetLoader
	{
		class H3AssetLoader
		{
		public:
			virtual INT NumberAdded() = 0;
			virtual LPCSTR GetLastError() = 0;
			virtual H3LoadedPcx* LoadPcxFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;
			virtual H3WavFile* LoadWavFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;

			virtual H3LoadedDef* LoadDefFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;
		};

		inline H3AssetLoader* GetAssetLoader()
		{
			if (HMODULE h = LoadLibraryA("H3.AssetLoader.dll"))
				if (FARPROC f = GetProcAddress(h, "GetAssetLoader_"))
					return STDCALL_0(H3AssetLoader*, f);
			return nullptr;
		}
	} /* namespace AssetLoader */

	namespace ImageLoader
	{
		class H3ImageLoader
		{
		public:
			virtual INT NumberAdded() = 0;
			virtual LPCSTR GetLastError() = 0;
			virtual H3LoadedPcx16* LoadImageToPcx16(LPCSTR filepath, LPCSTR h3name, INT width = -1, INT height = -1) = 0;
		};

		inline H3ImageLoader* GetImageLoader()
		{
			if (HMODULE h = LoadLibraryA("H3.ImageLoader.dll"))
				if (FARPROC f = GetProcAddress(h, "GetImageLoader_"))
					return STDCALL_0(H3ImageLoader*, f);
			return NULL;
		}
	} /* namespace ImageLoader */

	namespace TextColor
	{
		class H3TextColorInformation
		{
		public:
			virtual UINT GetNumberColors() = 0;
			virtual const H3Vector<H3String>* GetColorNames() = 0;
			virtual VOID DeleteColorNames() = 0;
			virtual VOID AddColor(LPCSTR name, UINT8 red, UINT8 green, UINT8 blue) = 0;
			VOID AddColor(LPCSTR name, DWORD rgb_color)
			{
				AddColor(name, (rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
			}
		};

		inline H3TextColorInformation* GetTextColor()
		{
			if (HMODULE h = LoadLibraryA("H3.TextColor.dll"))
				if (FARPROC f = GetProcAddress(h, "GetTextColor_"))
					return STDCALL_0(H3TextColorInformation*, f);
			return nullptr;
		}
	} /* namespace TextColor */

} /* namespace H3Plugin */
} /* namespace h3 */

#endif /* _H3API_PLUGINS_ */

namespace h3
{
	_H3API_DECLARE_(Random);

#pragma pack(push, 4)

	struct H3Random
	{
	public:
		_H3API_ static VOID SetRandomSeed();
		_H3API_ static VOID SetRandomSeed(UINT seed);
		_H3API_ static INT32 Random(INT32 high);
		_H3API_ static INT32 RandBetween(INT32 low, INT32 high);
		_H3API_ static INT32 MultiplayerRandom(INT32 min_value, INT32 max_value);
		_H3API_ static INT32 PeekRand();
		_H3API_ static INT32 PeekRand(INT32 low, INT32 high);
		_H3API_ static INT32 Rand();
		_H3API_ static INT32 Rand(INT32 low, INT32 high);
		_H3API_ static VOID Srand(UINT32 seed);
	public:
		struct ThreadLocalSingleton
		{
		public:
			_H3API_SIZE_(0x74);
		private:

			UINT32 currentThreadId;
			h3unk32 _f_04[2];
			DWORD   lastError;
			h3unk32 _f_10;
			UINT32 currentSeedValue;
			h3unk8 _f_18[56];
			h3unk8* _f_50;
			h3unk8 _f_54[32];
		public:
			_H3API_ UINT32  CurrentSeed() const;
			_H3API_ VOID    SetSeed(UINT32 value);
			_H3API_ DWORD   GetLastError() const;
			_H3API_ VOID    SetLastError(DWORD error);
			_H3API_ static  ThreadLocalSingleton& Get();
		};

		class SeedRestore
		{
		public:
			_H3API_ SeedRestore();
			_H3API_ ~SeedRestore();
		private:
			ThreadLocalSingleton& m_tls;
			UINT32 m_oldSeed;
		};
	};
	_H3API_ASSERT_SIZE_(H3Random::ThreadLocalSingleton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */

namespace h3
{
    template<typename Type>	class H3Range;

    template<typename Type>
    class H3Range
    {
    public:
        struct iterator
        {
            iterator(Type value) : m_value(value) {}
            Type operator*() { return m_value; }
            iterator& operator++() { m_value += static_cast<Type>(1); return *this; }
            bool operator!=(const iterator& it) { return m_value < it.m_value; }
        private:
            Type m_value;
        };

        iterator begin() { return m_begin; }
        iterator end() { return m_end; }

        H3Range(Type end) : m_begin(static_cast<Type>(0)), m_end(end) {}
        H3Range(Type begin, Type end) : m_begin(Type(begin)), m_end(end) {}
    private:
        iterator m_begin;
        iterator m_end;
    };

    template<typename Type>
    typename H3Range<Type> Range(Type upper_bound)
    {
        return H3Range<Type>(upper_bound);
    }
    template<typename Type>
    typename H3Range<Type> Range(Type lower_bound, Type upper_bound)
    {
        return H3Range<Type>(lower_bound, upper_bound);
    }

} /* namespace h3 */

namespace h3
{
	class H3Stream;
	class H3File;
	class H3SpreadSheet;

	class H3Stream
	{
		enum StreamModeValues
		{
			MV_READ   = 1,
			MV_WRITE  = 2,
			MV_APPEND = 4,
			MV_UPDATE = 8,
			MV_BINARY = 16,
		};

	public:
		_H3API_ENUM_ StreamMode
		{
			SM_INVALID              = 0,
			SM_READ                 = MV_READ,
			SM_READ_BINARY          = MV_READ | MV_BINARY,
			SM_WRITE                = MV_WRITE,
			SM_WRITE_BINARY         = MV_WRITE | MV_BINARY,
			SM_APPEND               = MV_APPEND,
			SM_APPEND_BINARY        = MV_APPEND | MV_BINARY,
			SM_READ_UPDATE          = MV_READ | MV_UPDATE,
			SM_READ_UPDATE_BINARY   = SM_READ_UPDATE | MV_BINARY,
			SM_WRITE_UPDATE         = MV_WRITE | MV_UPDATE,
			SM_WRITE_UPDATE_BINARY  = SM_WRITE_UPDATE | MV_BINARY,
			SM_APPEND_UPDATE        = MV_APPEND | MV_UPDATE,
			SM_APPEND_UPDATE_BINARY = SM_APPEND_UPDATE | MV_BINARY,
		};
		_H3API_ENUM_ StreamStatus
		{
			SS_OK,
			SS_NOT_LOADED,
			SS_INVALID,
		};

		_H3API_ H3Stream(LPCSTR filename, StreamMode read_write_mode, BOOL read_to_buffer = FALSE);
		_H3API_ H3Stream(LPCSTR filename, LPCSTR read_write_mode, BOOL read_to_buffer = FALSE);
		_H3API_ ~H3Stream();

		_H3API_ H3Stream& hex();
		_H3API_ H3Stream& decimal();
		_H3API_ H3Stream& new_lines();
		_H3API_ H3Stream& no_new_lines();
		_H3API_ H3Stream& endl();

		_H3API_ BOOL IsReady() const;
		_H3API_ StreamStatus GetStatus() const;
		_H3API_ StreamMode GetMode() const;
		_H3API_ BOOL Copy(LPCSTR destination);
		_H3API_ BOOL Copy(const H3String& destination);

#ifdef _H3API_CPLUSPLUS11_
		template<typename ... Args>
		H3Stream& Write(LPCSTR format, Args ... args);
#else
		_H3API_ H3Stream& Write(LPCSTR format, ...);
#endif

		_H3API_ H3Stream& operator<<(const int number);
		_H3API_ H3Stream& operator<<(const unsigned int number);
		_H3API_ H3Stream& operator<<(const FLOAT number);
		_H3API_ H3Stream& operator<<(const DOUBLE number);
		_H3API_ H3Stream& operator<<(const CHAR character);
		_H3API_ H3Stream& operator<<(LPCSTR text);
		_H3API_ H3Stream& operator<<(const H3String& str);
		template<INT32 sz>
		H3Stream& operator<<(const CHAR(&expression)[sz]);
		_H3API_ H3Stream& operator>>(H3String& line);
		_H3API_ H3Stream& operator>>(H3Vector<H3String>& lines);

		_H3API_ BOOL ReadFile(DWORD size_to_read);

	protected:
		FILE*        m_file;
		DWORD        m_size;
		StreamMode   m_mode;
		BOOL         m_writeHex;
		BOOL         m_writeNewLines;
		StreamStatus m_status;
		BYTE*        m_buffer;
		DWORD        m_bufferSize;
		DWORD        m_bufferPosition;

		_H3API_ LPCSTR getModeFormat();
		template<typename T>
		inline VOID printf(LPCSTR format, T value);
		_H3API_ VOID writeNewLine();
		_H3API_ BOOL canWrite();
		_H3API_ BOOL canRead();
		_H3API_ static StreamMode getMode(LPCSTR read_write_mode);
	public:
		_H3API_ static INT32  fclose(FILE* f);
		_H3API_ static INT32  fgetpos(FILE* f, fpos_t& pos);
		_H3API_ static FILE*  fopen(LPCSTR filename, LPCSTR mode);
		_H3API_ static INT32  fputc(CHAR c, FILE* f);
		_H3API_ static BOOL   fread(PVOID buffer, size_t size, size_t count, FILE* f);
		_H3API_ static INT32  fseek(FILE* f, INT32 offset, INT32 origin);
		_H3API_ static INT32  fsetpos(FILE* f, const fpos_t& pos);
		_H3API_ static DWORD  ftell(FILE* f);
		_H3API_ static UINT32 fwrite(const VOID* buffer, UINT32 size, UINT32 count, FILE* f);
		_H3API_ static DWORD  GetFileSize(FILE* f);
	};

	class H3File
	{
	protected:
		HANDLE m_handle;
		DWORD  m_fileSize;
		PBYTE  m_buffer;
		DWORD  m_pointer;
		HANDLE m_save;

		_H3API_ void getSize();
		_H3API_ void clear();
		_H3API_ void close();
		_H3API_ BOOL read(const PVOID buffer, DWORD sizeToRead);
		_H3API_ BOOL write(const PVOID buffer, DWORD sizeToWrite);
		_H3API_ BOOL exists(LPCSTR filepath);
	public:
		_H3API_ H3File();
		_H3API_ ~H3File();
		_H3API_ VOID Close();

		_H3API_ BOOL Open(LPCSTR const file);
		_H3API_ BOOL Open(const H3String& file);
		_H3API_ BOOL Read(PVOID buffer, DWORD sizeToRead);
		_H3API_ BOOL ReadToBuffer(); // read whole file to memory
		_H3API_ H3String GetLine();
		_H3API_ H3Vector<H3String> GetLines(BOOL includeEmptyLines = FALSE);
		_H3API_ BOOL Read(PVOID data, size_t data_len);
		template<typename T>
		inline  BOOL Read(const T& data);
		_H3API_ BOOL SetPointer(UINT pos);
		_H3API_ UINT Pointer() const;
		_H3API_ BOOL Skip(UINT numBytes);
		_H3API_ const PBYTE Buffer() const;
		_H3API_ PBYTE ReleaseBuffer();
		_H3API_ PBYTE begin();
		_H3API_ PBYTE begin() const;
		_H3API_ PBYTE end();
		_H3API_ PBYTE end() const;
		_H3API_ UINT Size() const;

		_H3API_ BOOL Save(LPCSTR const file);
		_H3API_ BOOL Write(PVOID data, size_t data_len);
		_H3API_ BOOL Write(const H3String& string);
		_H3API_ BOOL Write(LPCSTR string);
		template<typename T>
		inline BOOL Write(const T& data);

	public:

		_H3API_ static BOOL   CloseHandle(HANDLE handle);
		_H3API_ static HANDLE CreateFileA(LPCSTR file, BOOL open_existing);
		_H3API_ static DWORD  GetFileSize(HANDLE handle);
		_H3API_ static BOOL   ReadFile(HANDLE handle, PVOID data, DWORD bytes_to_read);
		_H3API_ static DWORD  SetFilePointer(HANDLE handle, LONG position, DWORD source);
		_H3API_ static BOOL   WriteFile(HANDLE handle, PVOID buffer, DWORD bytes_to_write);
	};

	class H3SpreadSheet
	{
	public:
		_H3API_ VOID Clear();
		_H3API_ VOID NewLine();
		_H3API_ VOID NewColumn();
		_H3API_ H3SpreadSheet& Hex();
		_H3API_ H3SpreadSheet& Dec();
		_H3API_ BOOL Save(LPCSTR const file);
		_H3API_ BOOL Save(const H3String& file);
		_H3API_ BOOL InsertLine(const H3String& line, UINT row = static_cast<UINT>(-1));
		_H3API_ H3SpreadSheet& operator<<(const H3SpreadSheet&);
		_H3API_ H3SpreadSheet& operator<<(LPCSTR text);
		_H3API_ H3SpreadSheet& operator<<(INT32 value);
		_H3API_ H3SpreadSheet& operator<<(UINT32 value);
		_H3API_ H3SpreadSheet& operator<<(FLOAT value);
		_H3API_ H3SpreadSheet& operator<<(DOUBLE value);
		_H3API_ H3SpreadSheet& operator<<(CHAR ch);
		_H3API_ H3SpreadSheet& operator<<(const H3String& line);

	private:
		_H3API_ VOID addTab();

		H3String           m_currentLine;
		H3Vector<H3String> m_lines;
		BOOL               m_hexMode;
	};

#ifdef _H3API_CPLUSPLUS11_
	template<typename ...Args>
	inline H3Stream& H3Stream::Write(LPCSTR format, Args ...args)
	{
		if (IsReady() && canWrite())
			CDECL_VA2(int, 0x61A031, m_file, format, args ...);
		return *this;
	}
	template<INT32 sz>
	inline H3Stream& H3Stream::operator<<(const CHAR(&expression)[sz])
	{
		if (IsReady() && canWrite())
			fwrite(reinterpret_cast<PVOID>(&expression), 1, sz, m_file);
		return *this;
	}
	template<typename T>
	inline VOID H3Stream::printf(LPCSTR format, T value)
	{
		if (IsReady() && canWrite())
			CDECL_3(int, 0x61A031, m_file, format, value);
	}
#endif

	template<typename T>
	inline BOOL h3::H3File::Read(const T& data)
	{
		return read(PVOID(&data), sizeof(T));
	}
	template<typename T>
	inline BOOL H3File::Write(const T& data)
	{
		return write(PVOID(&data), sizeof(T));
	}
}

#define _H3API_VERSION_MAJOR_ 1
#define _H3API_VERSION_MINOR_ 6
#define _H3API_VERSION_BUILD_ 1

#define _H3API_VERSION_ (_H3API_VERSION_MAJOR_ * 10000 | _H3API_VERSION_MINOR_ * 100 | _H3API_VERSION_BUILD_)
#define _H3API_VERSION_TEXT_ "H3API version " _H3API_STR_(_H3API_VERSION_MAJOR_) "." _H3API_STR_(_H3API_VERSION_MINOR_) "." _H3API_STR_(_H3API_VERSION_BUILD_)

namespace h3
{
	_H3API_ H3Version::H3Version()
	{
		PIMAGE_DOS_HEADER pDOSHeader = PIMAGE_DOS_HEADER(0x400000);
		PIMAGE_NT_HEADERS pNTHeaders = PIMAGE_NT_HEADERS(PBYTE(pDOSHeader) + pDOSHeader->e_lfanew);
		DWORD entry                  = pNTHeaders->OptionalHeader.AddressOfEntryPoint;

		switch (entry)
		{
		case 0x19A0AE: // 1.0
			m_version = GameVersion::ROE;
			break;
		case 0x21A884:
			m_version = GameVersion::SOD;
			break;
		case 0x21AB84:
			m_version = GameVersion::SOD_POLISH_GOLD;
			break;
		case 0x239C00:
			m_version = GameVersion::HOTA;
			break;
		case 0x301000:
			m_version = GameVersion::ERA;
			break;
		case 0x3017B0:
			m_version = GameVersion::WOG;
			break;
		default:
			m_version = GameVersion::UNKNOWN;
		}
	}
	_H3API_ H3Version::GameVersion H3Version::version() const
	{
		return m_version;
	}
	_H3API_ BOOL H3Version::roe()  const
	{
		return version() == GameVersion::ROE;
	}
	_H3API_ BOOL H3Version::sod()  const
	{
		return version() == GameVersion::SOD;
	}
	_H3API_ BOOL H3Version::hota() const
	{
		return version() == GameVersion::HOTA;
	}
	_H3API_ BOOL H3Version::era()  const
	{
		return version() == GameVersion::ERA;
	}
	_H3API_ BOOL H3Version::wog()  const
	{
		return version() == GameVersion::WOG;
	}
	_H3API_ INT32 H3Numbers::AddCommas(INT32 num, CHAR* out)
	{
		char buffer[64] = { 0 };
		char *src = buffer;
		char *dst = out;

		INT32 num_len = libc::sprintf(buffer, "%d", num);

		if (*src == '-')
		{
			*dst++ = *src++;
			num_len--;
		}

		for (INT32 commas = 2 - num_len % 3; *src; commas = (commas + 1) % 3)
		{
			*dst++ = *src++;
			if (commas == 1)
				*dst++ = ',';
		}
		*--dst = 0;

		return dst - out;
	}
	_H3API_ INT32 H3Numbers::MakeReadable(INT32 num, CHAR * out, INT32 decimals)
	{
		constexpr INT32 RN_MIN_VALUE = 10000;
		INT32 power;

		char buffer[64] = {0};

		INT64 m;
		if (num != INT_MIN)
			m = Abs(num);
		else
			m = INT64(INT_MAX) + 1;

		if (m < RN_MIN_VALUE)
		{
			const INT32 r = libc::sprintf(out, "%d", num);
			return r;
		}

		INT32 dec  = std::min(decimals, 3);
		INT32 plus = 500;
		INT32 div  = 1000;
		for (INT32 i = 0; i < dec; i++)
		{
			plus /= 10;
			div  /= 10;
		}
		INT32 d = power = 0;
		while (m >= 1000)
		{
			d = INT32(m);
			m /= 1000;
			power++;
		}
		d = (d + plus) / div * div;

		INT32 len = libc::sprintf(buffer, "%d", d);
		INT32 c = 2 - len % 3;

		CHAR *dst = out;
		CHAR *src = buffer;

		if (num < 0)
			*dst++ = '-';

		while (*src)
		{
			*dst++ = *src++;
			if (c == 1)
			{
				if (dec)
				{
					*dst++ = '.';
					for (INT32 i = 0; i < dec; i++)
						*dst++ = *src++;
				}
				break;
			}
			c = (c + 1) % 3;
		}
		constexpr CHAR scale[] = { 0, 'k', 'M', 'B' };
		*dst++ = scale[power];
		*dst = 0;

		return dst - out;
	}

	_H3API_ VOID H3Error::ShowError(LPCSTR message, LPCSTR title)
	{
		MessageBoxA(nullptr, message, title, MB_OK | MB_ICONERROR);
	}
	_H3API_ BOOL H3Error::ShowErrorChoice(LPCSTR message, LPCSTR title)
	{
		return MessageBoxA(nullptr, message, title, MB_OKCANCEL | MB_ICONERROR) == IDOK;
	}
	_H3API_ VOID H3Error::ShowErrorW(LPCWSTR message, LPCWSTR title)
	{
		MessageBoxW(nullptr, message, title, MB_OK | MB_ICONERROR);
	}
	_H3API_ BOOL H3Error::ShowErrorChoiceW(LPCWSTR message, LPCWSTR title)
	{
		return MessageBoxW(nullptr, message, title, MB_OKCANCEL | MB_ICONERROR);
	}
	_H3API_ H3Point::H3Point() :
		x(), y(), z()
	{
	}
	_H3API_ H3Point::H3Point(INT32 x, INT32 y, INT32 z) :
		x(x), y(y), z(z)
	{
	}
	_H3API_ H3Point::H3Point(const H3Point& pt) :
		x(pt.x), y(pt.y), z(pt.z)
	{
	}
	_H3API_ H3Point::H3Point(const H3Position& pos) :
		x(pos.GetX()), y(pos.GetY()), z(pos.GetZ())
	{
	}
	_H3API_ UINT32 H3Point::Pack() const
	{
		return H3Position::Pack(*this);
	}
	_H3API_ VOID H3Point::Clamp(INT32 map_size)
	{
		x = h3::Clamp(0, x, map_size);
		y = h3::Clamp(0, y, map_size);
	}
	_H3API_ VOID H3Point::Clamp()
	{
		INT32 map_size = H3MapSize::Get();
		x = h3::Clamp(0, x, map_size);
		y = h3::Clamp(0, y, map_size);
	}
	_H3API_ H3Point& H3Point::IncX(INT32 dx /*= 1*/)
	{
		x += dx;
		return *this;
	}
	_H3API_ H3Point& H3Point::IncY(INT32 dy /*= 1*/)
	{
		y += dy;
		return *this;
	}
	_H3API_ H3Point& H3Point::DecX(INT32 dx /*= 1*/)
	{
		x -= dx;
		return *this;
	}
	_H3API_ H3Point& H3Point::DecY(INT32 dy /*= 1*/)
	{
		y -= dy;
		return *this;
	}
	_H3API_ H3Point& H3Point::operator=(const H3Position& pos)
	{
		*this = pos.Unpack();
		return *this;
	}
	_H3API_ H3Point& H3Point::operator=(const H3Point& pt)
	{
		x = pt.x;
		y = pt.y;
		z = pt.z;
		return *this;
	}
	_H3API_ BOOL H3Point::operator==(const H3Point& pt) const
	{
		return x == pt.x && y == pt.y && z == pt.z;
	}
	_H3API_ BOOL H3Point::operator==(const H3Position& pos) const
	{
		H3Point p = pos.Unpack();
		return *this == p;
	}
	_H3API_ BOOL H3Point::operator!=(const H3Point& pt) const
	{
		return x != pt.x || y != pt.y || z != pt.z;
	}
	_H3API_ BOOL H3Point::operator!=(const H3Position& pos) const
	{
		H3Point p = pos.Unpack();
		return *this != p;
	}
	_H3API_ H3POINT::H3POINT() :
		x(), y()
	{
	}
	_H3API_ H3POINT::H3POINT(INT32 x, INT32 y) :
		x(x), y(y)
	{
	}
	_H3API_ H3POINT::H3POINT(const H3POINT& other) :
		x(other.x), y(other.y)
	{
	}
	_H3API_ H3POINT::H3POINT(const ::POINT& point) :
		x(point.x), y(point.y)
	{
	}
	_H3API_ H3POINT& H3POINT::operator=(const ::POINT& point)
	{
		x = point.x;
		y = point.y;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::IncX(INT32 dx /*= 1*/)
	{
		x += dx;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::IncY(INT32 dy /*= 1*/)
	{
		y += dy;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::DecX(INT32 dx /*= 1*/)
	{
		x -= dx;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::DecY(INT32 dy /*= 1*/)
	{
		y -= dy;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::operator+(const H3POINT& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	_H3API_ H3POINT& H3POINT::operator-(const H3POINT& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	_H3API_ VOID H3POINT::Clamp()
	{
		Clamp(INT32(H3MapSize::Get()));
	}
	_H3API_ VOID H3POINT::Clamp(INT32 map_size)
	{
		x = h3::Clamp(0, x, map_size);
		y = h3::Clamp(0, y, map_size);
	}
	_H3API_ H3POINT& H3POINT::GetCurrentCursorPosition()
	{
		GetCursorPosition(x, y);
		return *this;
	}
	_H3API_ H3POINT H3POINT::GetCursorPosition()
	{
		H3POINT pt;
		pt.GetCurrentCursorPosition();
		return pt;
	}
	_H3API_ VOID H3POINT::GetCursorPosition(INT32& x, INT32& y)
	{
		STDCALL_2(VOID, 0x50D700, &x, &y);
	}
	_H3API_ VOID H3POINT::GetCursorPosition(H3POINT& p)
	{
		GetCursorPosition(p.x, p.y);
	}
	_H3API_ H3POINT& H3POINT::operator=(const H3POINT& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	_H3API_ BOOL H3POINT::operator!=(const H3POINT& other) const
	{
		return x != other.x || y != other.y;
	}
	_H3API_ BOOL H3POINT::operator==(const H3POINT& other) const
	{
		return x == other.x && y == other.y;
	}
	_H3API_ H3Position::H3Position(const H3Point& pt) :
		pos(Pack(pt))
	{
	}
	_H3API_ BOOL H3Position::operator!=(const H3Point& other) const
	{
		return other != *this;
	}
	_H3API_ BOOL H3Position::operator==(const H3Point& other) const
	{
		return other == *this;
	}
	_H3API_ UINT H3Position::Pack(const H3Point& pt)
	{
		return Pack(pt.x, pt.y, pt.z);
	}
	_H3API_ VOID H3Position::operator=(const H3Point& pt)
	{
		pos = Pack(pt);
	}
	_H3API_ H3Position::H3Position() :
		pos()
	{
	}
	_H3API_ H3Position::H3Position(INT16 x, INT16 y, INT8 z)
	{
		THISCALL_4(H3Position&, 0x419210, this, x, y, z);
	}
	_H3API_ H3Position::H3Position(UINT32 mixed_position) :
		pos(mixed_position)
	{
	}
	_H3API_ H3Position::H3Position(const H3Position& other) :
		pos(other.pos)
	{
	}
	_H3API_ VOID H3Position::operator=(UINT32 mixed_position)
	{
		pos = mixed_position;
	}
	_H3API_ VOID H3Position::operator=(const H3Position& other)
	{
		pos = *other;
	}
	_H3API_ BOOL H3Position::operator==(const H3Position& other) const
	{
		return GetX() == other.GetX() && GetY() == other.GetY() && GetZ() == other.GetZ();
	}
	_H3API_ BOOL H3Position::operator!=(const H3Position& other) const
	{
		return GetX() != other.GetX() || GetY() != other.GetY() || GetZ() != other.GetZ();
	}
	_H3API_ UINT32 H3Position::operator*() const
	{
		return pos;
	}
	_H3API_ H3Position::operator UINT() const
	{
		return pos;
	}
	_H3API_ UINT H3Position::Mixed() const
	{
		return pos;
	}
	_H3API_ UINT H3Position::GetX() const
	{
		return UnpackX(pos);
	}
	_H3API_ UINT H3Position::GetY() const
	{
		return UnpackY(pos);
	}
	_H3API_ UINT8 H3Position::GetZ() const
	{
		return UnpackZ(pos);
	}
	_H3API_ VOID H3Position::GetXYZ(INT& x, INT& y, INT& z) const
	{
		UnpackXYZ(pos, x, y, z);
	}
	_H3API_ VOID H3Position::SetX(INT16 x)
	{
		pos &= ~0x3FF;
		pos |= (x & 0x3FF);
	}
	_H3API_ VOID H3Position::SetY(INT16 y)
	{
		pos &= ~0x03FF0000;
		pos |= ((y & 0x3FF) << 16);
	}
	_H3API_ VOID H3Position::SetZ(INT16 z)
	{
		pos &= ~0x04000000;
		pos |= ((z & 1) << 26);
	}
	_H3API_ VOID H3Position::SetXYZ(INT x, INT y, INT z)
	{
		pos = Pack(x, y, z);
	}
	_H3API_ H3Point H3Position::Unpack() const
	{
		INT x, y, z;
		UnpackXYZ(pos, x, y, z);
		return H3Point(x, y, z);
	}
	_H3API_ UINT H3Position::Pack(INT x, INT y, INT z)
	{
		return ((x & 0x3FF) | ((y & 0x3FF) << 0x10) | ((z & 1) << 0x1A));
	}
	_H3API_ VOID H3Position::UnpackXYZ(UINT coord, INT& x, INT& y, INT& z)
	{
		x = UnpackX(coord);
		y = UnpackY(coord);
		z = UnpackZ(coord);
	}
	_H3API_ UINT H3Position::UnpackX(UINT coord)
	{
		return coord & 0x3FF;
	}
	_H3API_ UINT H3Position::UnpackY(UINT coord)
	{
		return (coord >> 16) & 0x3FF;
	}
	_H3API_ UINT8 H3Position::UnpackZ(UINT coord)
	{
		return (coord >> 26) & 1;
	}
}

namespace h3
{
	_H3API_ PVOID H3Realloc(PVOID obj, UINT new_size)
	{
		return CDECL_2(PVOID, 0x619890, obj, new_size);
	}
	_H3API_ PVOID H3Calloc(UINT count, UINT size)
	{
		return CDECL_2(PVOID, 0x61AA61, count, size);
	}
	_H3API_ PVOID H3Malloc(UINT size)
	{
		return CDECL_1(PVOID, 0x617492, size);
	}
	_H3API_ VOID H3Free(PVOID obj)
	{
		if (obj)
			CDECL_1(VOID, 0x60B0F0, obj);
	}
	_H3API_ PVOID H3Allocator::operator new(const size_t sz)
	{
		return H3Malloc(sz);
	}
	_H3API_ VOID H3Allocator::operator delete(PVOID block)
	{
		H3Free(block);
	}
	_H3API_ PVOID H3Allocator::operator new[](const size_t sz)
	{
		return H3Malloc(sz);
	}
	_H3API_ VOID H3Allocator::operator delete[](PVOID block)
	{
		H3Free(block);
	}
}

namespace h3
{
	_H3API_ BOOL H3Bitfield::GetState(UINT32 position) const
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		return ((&m_bf)[index]) & value;
	}
	_H3API_ VOID H3Bitfield::SetState(UINT32 position, BOOL state)
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		if (state)
			((&m_bf)[index]) |= value;
		else
			((&m_bf)[index]) &= ~value;
	}
	_H3API_ VOID h3::H3Bitfield::Set(UINT32 value)
	{
		m_bf = value;
	}
	_H3API_ UINT h3::H3Bitfield::Get() const
	{
		return m_bf;
	}
	_H3API_ VOID H3Bitfield::Flip(UINT32 position)
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		((&m_bf)[index]) ^= value;
	}
	_H3API_ H3Bitfield::reference H3Bitfield::operator[](UINT32 position)
	{
		return reference(this, position);
	}
	_H3API_ BOOL H3Bitfield::operator()(UINT position)
	{
		return GetState(position);
	}
	_H3API_ UINT H3Bitfield::Mask(UINT number_bits)
	{
		return UINT((1ull << (number_bits & 0x1F)) - 1);
	}
	_H3API_ VOID H3ObjectMask::operator=(const H3ObjectMask& other)
	{
		m_bitsPacked = other.m_bitsPacked;
	}
	_H3API_ VOID H3ObjectMask::operator=(UINT64 value)
	{
		m_bitsPacked = value;
	}
	_H3API_ H3Bitfield& H3ObjectMask::operator[](UINT index)
	{
		return m_bits[index];
	}
	_H3API_ const H3Bitfield& H3ObjectMask::operator[](UINT index) const
	{
		return m_bits[index];
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::begin()
	{
		return iterator(this, 0);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::end()
	{
		return iterator(this, 48);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::operator()(UINT8 index)
	{
		return iterator(this, index);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::operator()(UINT8 column, UINT8 row)
	{
		return iterator(this, (row << 3) + column); // row * 8 + column
	}
	_H3API_ H3Bitfield::reference::reference(H3Bitfield* bitfield) :
		m_bitfield(bitfield), m_position()
	{
	}
	_H3API_ H3Bitfield::reference::reference(H3Bitfield* bitfield, UINT position) :
		m_bitfield(bitfield), m_position(position)
	{
	}
	_H3API_ H3Bitfield::reference& H3Bitfield::reference::operator++()
	{
		++m_position;
		return *this;
	}
	_H3API_ H3Bitfield::reference H3Bitfield::reference::operator++(int)
	{
		reference ref(m_bitfield, m_position);
		++m_position;
		return ref;
	}
	_H3API_ H3Bitfield::reference& H3Bitfield::reference::operator~()
	{
		Flip();
		return *this;
	}
	_H3API_ H3Bitfield::reference::operator BOOL()
	{
		return m_bitfield->GetState(m_position);
	}
	_H3API_ BOOL H3Bitfield::reference::operator!()
	{
		return m_bitfield->GetState(m_position) == FALSE;
	}
	_H3API_ VOID H3Bitfield::reference::operator=(BOOL state)
	{
		m_bitfield->SetState(m_position, state);
	}
	_H3API_ VOID H3Bitfield::reference::Set()
	{
		m_bitfield->SetState(m_position, TRUE);
	}
	_H3API_ VOID H3Bitfield::reference::Reset()
	{
		m_bitfield->SetState(m_position, FALSE);
	}
	_H3API_ VOID H3Bitfield::reference::Flip()
	{
		m_bitfield->Flip(m_position);
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield() :
		bits()
	{
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield(UINT8 player_bits) :
		bits(player_bits)
	{
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield(const H3PlayersBitfield& other) :
		bits(other.bits)
	{
	}
	_H3API_ VOID H3PlayersBitfield::operator|=(UINT8 value)
	{
		bits |= value;
	}
	_H3API_ VOID H3PlayersBitfield::operator=(UINT8 value)
	{
		bits = value;
	}
	_H3API_ VOID H3PlayersBitfield::operator=(const H3PlayersBitfield& other)
	{
		bits = other.bits;
	}
	_H3API_ VOID H3PlayersBitfield::Set(UINT32 player, BOOL8 state)
	{
		state ? Reveal(player) : Hide(player);
	}
	_H3API_ BOOL H3PlayersBitfield::Status(UINT32 player) const
	{
		return bits & (1 << player);
	}
	_H3API_ VOID H3PlayersBitfield::Reveal(UINT32 player)
	{
		bits |= (1 << player);
	}
	_H3API_ VOID H3PlayersBitfield::Hide(UINT32 player)
	{
		bits &= ~(1 << player);
	}
	_H3API_ H3PlayersBitfield::operator UINT8() const
	{
		return bits;
	}
	_H3API_ H3ObjectMask::iterator::iterator(const iterator& it) :
		m_mask(it.m_mask), m_position(it.m_position)
	{
	}
	_H3API_ H3ObjectMask::iterator::iterator(H3ObjectMask* mask) :
		m_mask(mask), m_position(0)
	{
	}
	_H3API_ H3ObjectMask::iterator::iterator(H3ObjectMask* mask, UINT32 index) :
		m_mask(mask), m_position(index)
	{
	}
	_H3API_ H3ObjectMask::iterator& H3ObjectMask::iterator::operator++()
	{
		++m_position;
		return *this;
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::iterator::operator++(INT32)
	{
		iterator it(*this);
		++(*this);
		return it;
	}
	_H3API_ H3ObjectMask::iterator& H3ObjectMask::iterator::operator~()
	{
		Flip();
		return *this;
	}
	_H3API_ H3ObjectMask::iterator::operator BOOL() const
	{
		return GetState();
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator!() const
	{
		return GetState() == FALSE;
	}
	_H3API_ VOID H3ObjectMask::iterator::operator=(BOOL state)
	{
		SetState(state);
	}
	_H3API_ BOOL H3ObjectMask::iterator::GetState() const
	{
		return m_mask->m_bits->GetState(m_position);
	}
	_H3API_ VOID H3ObjectMask::iterator::SetState(BOOL state)
	{
		m_mask->m_bits->SetState(m_position, state);
	}
	_H3API_ VOID H3ObjectMask::iterator::Set()
	{
		SetState(TRUE);
	}
	_H3API_ VOID H3ObjectMask::iterator::Reset()
	{
		SetState(FALSE);
	}
	_H3API_ VOID H3ObjectMask::iterator::Flip()
	{
		m_mask->m_bits->Flip(m_position);
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator==(const iterator& it)
	{
		return m_position == it.m_position;
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator!=(const iterator& it)
	{
		return m_position != it.m_position;
	}
}

namespace h3
{
	namespace libc
	{
		_H3API_ INT32 strlen(LPCSTR text)
		{
			return CDECL_1(INT32, 0x61ACD0, text);
		}
		_H3API_ LPCSTR strtok(LPCSTR text, LPCSTR delimiters)
		{
			return CDECL_2(LPCSTR, 0x617FBB, text, delimiters);
		}
		_H3API_ INT32 strcspn(LPCSTR text, LPCSTR keys)
		{
			return CDECL_2(INT32, 0x618690, text, keys);
		}
		_H3API_ PCHAR strncpy(PCHAR destination, LPCSTR source, UINT32 number)
		{
			return CDECL_3(PCHAR, 0x618FE0, destination, source, number);
		}
		_H3API_ LPCSTR strrchr(LPCSTR text, CHAR last_char)
		{
			return CDECL_2(LPCSTR, 0x619270, text, last_char);
		}
		_H3API_ INT32 strcmp(LPCSTR str1, LPCSTR str2)
		{
			return CDECL_2(INT32, 0x61CF80, str1, str2);
		}
		_H3API_ INT32 strncmp(LPCSTR str1, LPCSTR str2, UINT32 number)
		{
			return CDECL_3(INT32, 0x61CF80, str1, str2, number);
		}
		_H3API_ INT32 strnicmp(LPCSTR str1, LPCSTR str2, UINT32 number)
		{
			return CDECL_3(INT32, 0x626680, str1, str2, number);
		}
		_H3API_ INT32 strcmpi(LPCSTR str1, LPCSTR str2)
		{
			return CDECL_2(INT32, 0x6197C0, str1, str2);
		}
		_H3API_ PCHAR strdup(LPCSTR string)
		{
			return CDECL_1(PCHAR, 0x627648, string);
		}
		_H3API_ LPCSTR strchr(LPCSTR string, INT32 character)
		{
			return CDECL_2(LPCSTR, 0x6197C0, string, character);
		}
		_H3API_ PCHAR strstr(LPCSTR string, LPCSTR substring)
		{
			return CDECL_2(PCHAR, 0x619B30, string, substring);
		}
		_H3API_ INT32 strtol(LPCSTR text, CHAR** endptr, INT32 base)
		{
			return CDECL_3(INT32, 0x619BF8, text, endptr, base);
		}
		_H3API_ UINT32 strtoul(LPCSTR text, CHAR** endptr, INT32 base)
		{
			return CDECL_3(UINT32, 0x619E14, text, endptr, base);
		}
		_H3API_ DOUBLE strtod(LPCSTR text, CHAR** endptr)
		{
			return CDECL_2(DOUBLE, 0x61C049, text, endptr);
		}
		_H3API_ PCHAR strrev(PCHAR text)
		{
			return CDECL_1(PCHAR, 0x627690, text);
		}
		_H3API_ PCHAR strupr(PCHAR text)
		{
			return CDECL_1(PCHAR, 0x6276C0, text);
		}
		_H3API_ INT32 atoi(LPCSTR text)
		{
			return CDECL_1(INT32, 0x6184D9, text);
		}
		_H3API_ UINT atol(LPCSTR text)
		{
			return CDECL_1(UINT, 0x61844E, text);
		}
		_H3API_ DOUBLE atof(LPCSTR text)
		{
			return CDECL_1(DOUBLE, 0x619366, text);
		}
		_H3API_ UINT32 wcslen(LPCWSTR string)
		{
			return CDECL_1(UINT32, 0x61CCE0, string);
		}
		_H3API_ INT32 CompareStringW(LCID locale, DWORD flags, LPCWSTR str1, INT32 str1_length,
			LPCWSTR str2, INT32 str2_length)
		{
			return STDCALL_6(INT32, PtrAt(0x63A214), locale, flags, str1, str1_length, str2, str2_length);
		}
		_H3API_ VOID memcpy(PVOID dst, PVOID src, UINT32 len)
		{
			CDECL_3(VOID, 0x61AD70, dst, src, len);
		}
		_H3API_ VOID memset(PVOID dest, INT32 value, const UINT len)
		{
			CDECL_3(VOID, 0x61B7E0, dest, value, len);
		}
		_H3API_ INT32 vsprintf(PCHAR buffer, LPCSTR format, va_list args)
		{
			return CDECL_3(INT32, 0x6190DE, buffer, format, args);
		}
		_H3API_ INT32 sprintf(PCHAR buffer, LPCSTR format, ...)
		{
			va_list args;
			va_start(args, format);
			const INT32 r = libc::vsprintf(buffer, format, args);
			va_end(args);
			return r;
		}
		_H3API_ DWORD GetFullPathNameA(LPCSTR file, DWORD buffer_length, PCHAR buffer, PCHAR* file_part)
		{
			return STDCALL_4(DWORD, PtrAt(0x63A1B8), file, buffer_length, buffer, file_part);
		}
		_H3API_ INT32 MultiByteToWideChar(UINT code_page, DWORD flags, LPCSTR string,
			INT32 string_length, WCHAR* buffer, INT32 buffer_length)
		{
			return STDCALL_6(INT32, PtrAt(0x63A1CC), code_page, flags , string, string_length, buffer, buffer_length);
		}
		_H3API_ INT32 WideCharToMultiByte(UINT code_page, DWORD flags, LPCWSTR string, INT32 string_length,
			PCHAR buffer, INT32 buffer_length, PCHAR default_char, BOOL* default_used)
		{
			return STDCALL_8(UINT, PtrAt(0x63A1C4), code_page, flags, string, string_length,
				buffer,	buffer_length, default_char, default_used);
		}

	} /* namespace libc */

	_H3API_ VOID WaitFor(DWORD milliseconds)
	{
		THISCALL_1(VOID, 0x4F8980, milliseconds);
	}
	_H3API_ DWORD GetTime()
	{
		return STDCALL_0(DWORD, PtrAt(0x63A354));
	}
	_H3API_ INT32 Clamp(INT32 min_value, INT32 value, INT32 max_value)
	{
		return FASTCALL_3(INT32&, 0x4E6800, &min_value, &value, &max_value);
	}
	_H3API_ H3UniquePtr<WCHAR> H3Encoding::Utf8ToUnicode(LPCSTR utf8)
	{
		if (!utf8)
			return WCHARPtr();
		UINT32 len = libc::strlen(utf8);
		if (!len)
			return WCHARPtr();
		INT req_len = libc::MultiByteToWideChar(CP_UTF8, 0, utf8, len, 0, 0);
		WCHARPtr ptr(H3ObjectAllocator<WCHAR>().allocate(req_len));
		if (ptr)
			libc::MultiByteToWideChar(CP_UTF8, 0, utf8, len, ptr.Get(), req_len);
		return ptr;
	}
	_H3API_ H3UniquePtr<WCHAR> H3Encoding::AnsiToUnicode(LPCSTR ansi, UINT code_page)
	{
		if (!ansi)
			return WCHARPtr();
		UINT32 len = libc::strlen(ansi);
		if (!len)
			return WCHARPtr();
		INT req_len = libc::MultiByteToWideChar(code_page, 0, ansi, len, 0, 0);
		WCHARPtr ptr(H3ObjectAllocator<WCHAR>().allocate(req_len));
		if (ptr)
			libc::MultiByteToWideChar(code_page, 0, ansi, len, ptr.Get(), req_len);
		return ptr;
	}
	_H3API_ H3UniquePtr<CHAR> H3Encoding::UnicodeToAnsi(LPCWSTR unicode, UINT code_page)
	{
		if (!unicode)
			return CHARPtr();
		UINT32 len = libc::wcslen(unicode);
		if (!len)
			return CHARPtr();
		INT req_len = libc::WideCharToMultiByte(code_page, 0, unicode, len, NULL, 0, NULL, NULL);
		CHARPtr ptr(CharAllocator().allocate(req_len));
		if (ptr)
			libc::WideCharToMultiByte(code_page, 0, unicode, len, ptr.Get(), req_len, NULL, NULL);
		return ptr;
	}
	_H3API_ H3UniquePtr<CHAR> H3Encoding::UnicodeToUtf8(LPCWSTR unicode)
	{
		if (!unicode)
			return CHARPtr();
		UINT32 len = libc::wcslen(unicode);
		if (!len)
			return CHARPtr();
		INT req_len = libc::WideCharToMultiByte(CP_UTF8, 0, unicode, len, NULL, 0, NULL, NULL);
		CHARPtr ptr(CharAllocator().allocate(req_len));
		if (ptr)
			libc::WideCharToMultiByte(CP_UTF8, 0, unicode, len, ptr.Get(), req_len, NULL, NULL);
		return ptr;
	}

}

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3String::Deref()
	{
		m_string = nullptr;
		m_length = 0;
		m_capacity = 0;
	}
	_H3API_ VOID H3String::NullTerminate()
	{
		*End() = 0;
	}
	_H3API_ BOOL H3String::Realloc(UINT new_size)
	{
		return THISCALL_2(BOOL, 0x404B80, this, new_size);
	}
	_H3API_ VOID H3String::ClearUnused()
	{
		const UINT to_clear = m_capacity - m_length;
		libc::memset(PVOID(m_string + m_length), 0, to_clear);
	}
	_H3API_ BOOL H3String::CompareChars(LPCSTR chars, UINT num_chars, UINT pos, BOOL is_true) const
	{
		for (UINT i = 0; i < num_chars; ++i)
			if (m_string[pos] == chars[i])
				return is_true;

		return !is_true;
	}
	_H3API_ UINT H3String::CompareFirstOf(LPCSTR chars, UINT num_chars, BOOL is_true) const
	{
		if (Empty())
			return npos;

		for (UINT i = 0; i < m_length; ++i)
			if (CompareChars(chars, num_chars, i, is_true))
				return i;
		return npos;
	}
	_H3API_ UINT H3String::CompareLastOf(LPCSTR chars, UINT num_chars, BOOL is_true) const
	{
		if (!m_string || !m_length)
			return npos;

		for (UINT i = m_length; i > 0; --i)
			if (CompareChars(chars, num_chars, i - 1, is_true))
				return i - 1;
		return npos;
	}

	_H3API_ LPCSTR H3String::nullstring() const
	{
		return reinterpret_cast<LPCSTR>(&m_string);
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3String& H3String::move(H3String&& other)
	{
		if (this == &other)
			return *this;
		Dereference();
		m_string   = other.m_string;
		m_length   = other.m_length;
		m_capacity = other.m_capacity;
		other.Deref();
		return *this;
	}
#endif

	_H3API_ H3String::H3String() :
		m_string(nullptr),
		m_length(0),
		m_capacity(0)
	{
	}
	_H3API_ H3String::H3String(LPCSTR msg) :
		m_string(nullptr),
		m_length(0),
		m_capacity(0)
	{
		Assign(msg);
	}
	_H3API_ H3String::H3String(LPCSTR msg, UINT len) :
		m_string(),
		m_length(0),
		m_capacity(0)
	{
		Assign(msg, len);
	}

	_H3API_ H3String::H3String(const H3String& other) :
		m_string(nullptr),
		m_length(0),
		m_capacity(0)
	{
		Assign(other);
	}
	_H3API_ H3String::H3String(CHAR ch) :
		m_string(nullptr),
		m_length(0),
		m_capacity(0)
	{
		Assign(ch);
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3String::H3String(H3String&& other) noexcept :
		m_string(other.m_string),
		m_length(other.m_length),
		m_capacity(other.m_capacity)
	{
		other.Deref();
	}
#endif

	_H3API_ H3String::~H3String()
	{
		Dereference();
	}
	_H3API_ VOID H3String::Init()
	{
		THISCALL_2(VOID, 0x404130, this, 0);
	}
	_H3API_ VOID H3String::Dereference()
	{
		THISCALL_1(VOID, 0x4040F0, this);
	}
	_H3API_ BOOL H3String::Empty() const
	{
		if (m_string == nullptr || m_length == 0)
			return TRUE;
		return FALSE;
	}
	_H3API_ UINT H3String::Length() const
	{
		return m_length;
	}
	_H3API_ UINT H3String::MaxLength() const
	{
		return m_capacity;
	}
	_H3API_ LPCSTR H3String::String() const
	{
		return m_string ? m_string : nullstring();
	}
	_H3API_ CHAR* H3String::begin()
	{
		return m_string ? m_string : PCHAR(nullstring());
	}
	_H3API_ const CHAR* H3String::begin() const
	{
		return m_string ? m_string : nullstring();
	}
	_H3API_ CHAR* H3String::end()
	{
		return m_string ? m_string + m_length : PCHAR(nullstring());
	}
	_H3API_ const CHAR* H3String::end() const
	{
		return m_string ? m_string + m_length : nullstring();
	}
	_H3API_ VOID H3String::swap(H3String& other)
	{
		PCHAR s          = m_string;
		UINT l           = m_length;
		UINT c           = m_capacity;
		m_string         = other.m_string;
		m_length         = other.m_length;
		m_capacity       = other.m_capacity;
		other.m_string   = s;
		other.m_length   = l;
		other.m_capacity = c;
	}
	_H3API_ PCHAR H3String::Begin()
	{
		return m_string ? m_string : PCHAR(&m_string);
	}
	_H3API_ PCHAR H3String::End()
	{
		return m_string ? m_string + m_length : PCHAR(&m_string);
	}
	_H3API_ CHAR H3String::Last() const
	{
		if (Empty())
			return '\0';
		return m_string[m_length - 1];
	}
	_H3API_ H3String& H3String::Assign(LPCSTR mes, UINT len)
	{
		if (mes)
			return THISCALL_3(H3String&, 0x404180, this, mes, len);
		return *this;
	}
	_H3API_ H3String& H3String::Assign(LPCSTR mes)
	{
		return Assign(mes, libc::strlen(mes));
	}
	_H3API_ H3String& H3String::Assign(CHAR ch)
	{
		if (ch == '\0')
			return *this;
		return Assign(&ch, 1);
	}
	_H3API_ H3String& H3String::Assign(const H3String& other)
	{
		if (other.m_string)
			return Assign(other.String(), other.Length());
		return *this;
	}
	_H3API_ H3String& H3String::Assign(INT32 number)
	{
		char buffer[16]; // more than enough considering number can only be 12 digits [-1234567890\0]
		INT32 len = libc::sprintf(buffer, "%d", number);
		Assign(buffer, UINT(len));
		return *this;
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3String& H3String::Assign(H3String&& other)
	{
		return move(std::move(other));
	}
#endif

	_H3API_ BOOL H3String::Reserve(UINT new_size)
	{
		return Realloc(new_size);
	}
	_H3API_ BOOL H3String::SetLength(UINT len)
	{
		if (len > m_capacity)
			return Realloc(len);
		m_length = len;
		NullTerminate();
		return TRUE;
	}
	_H3API_ VOID H3String::ShrinkToFit()
	{
		if (m_capacity == 0)
			return;
		UINT min_len = m_length + 2;
		if (min_len >= m_capacity)
			return;

		PCHAR tmp = CharAllocator().allocate(min_len);
		libc::memcpy(tmp, m_string - 1, min_len);
		CharAllocator().deallocate(m_string - 1);
		m_string = tmp - 1;
		m_capacity = min_len - 1;
	}
	_H3API_ H3String& H3String::Append(LPCSTR mes, UINT len)
	{
		if (mes && len)
			return THISCALL_3(H3String&, 0x41B2A0, this, mes, len);
		return *this;
	}
	_H3API_ H3String& H3String::Append(const H3String&  other)
	{
		return Append(other.String(), other.Length());
	}
	_H3API_ H3String& H3String::Append(INT32 number)
	{
		char buffer[16]; // more than enough considering number can only be 12 digits [-1234567890\0]
		const INT32 len = libc::sprintf(buffer, "%d", number);
		return Append(buffer, UINT(len));
	}
	_H3API_ H3String& H3String::Append(UINT32 number)
	{
		char buffer[16]; // more than enough considering number can only be 13 digits [0x1234567890\0]
		const UINT32 len = libc::sprintf(buffer, "0x%X", number);
		return Append(buffer, UINT(len));
	}
	_H3API_ H3String& H3String::Append(LPCSTR mes)
	{
		if (mes)
			return Append(mes, libc::strlen(mes));
		return *this;
	}
	_H3API_ H3String& H3String::Append(CHAR ch)
	{
		if (ch == '\0')
			return *this;
		return Append(&ch, 1);
	}
	_H3API_ LPCSTR H3String::FindFirst(CHAR ch)
	{
		PCHAR f = Begin();
		UINT pos = 0;
		UINT len = Length();
		while (*f && pos < len)
		{
			if (*f == ch)
				return f;
			++f;
			++pos;
		}
		return nullptr;
	}
	_H3API_ LPCSTR H3String::FindFirst(LPCSTR substr) const
	{
		if (m_string)
			return libc::strstr(String(), substr);
		return nullptr;
	}
	_H3API_ UINT H3String::FindFirstOf(LPCSTR chars, UINT num_chars) const
	{
		return CompareFirstOf(chars, num_chars, TRUE);
	}
	_H3API_ UINT H3String::FindFirstOf(LPCSTR chars) const
	{
		return FindFirstOf(chars, libc::strlen(chars));
	}
	_H3API_ UINT H3String::FindFirstOf(const H3String& chars) const
	{
		return FindFirstOf(chars.String(), chars.Length());
	}
	_H3API_ UINT H3String::FindFirstOf(const CHAR ch) const
	{
		return CompareFirstOf(&ch, 1, TRUE);
	}
	_H3API_ UINT H3String::FindFirstNotOf(LPCSTR chars, UINT num_chars) const
	{
		return CompareFirstOf(chars, num_chars, FALSE);
	}
	_H3API_ UINT H3String::FindFirstNotOf(LPCSTR chars) const
	{
		return FindFirstNotOf(chars, libc::strlen(chars));
	}
	_H3API_ UINT H3String::FindFirstNotOf(const H3String& chars) const
	{
		return FindFirstNotOf(chars.String(), chars.Length());
	}
	_H3API_ UINT H3String::FindFirstNotOf(const CHAR ch) const
	{
		return FindFirstNotOf(&ch, 1);
	}
	_H3API_ UINT H3String::FindLastOf(LPCSTR chars, UINT num_chars) const
	{
		return CompareLastOf(chars, num_chars, TRUE);
	}
	_H3API_ UINT H3String::FindLastOf(LPCSTR chars) const
	{
		return CompareLastOf(chars, libc::strlen(chars), TRUE);
	}
	_H3API_ UINT H3String::FindLastOf(const H3String& chars) const
	{
		return CompareLastOf(chars.String(), chars.Length(), TRUE);
	}
	_H3API_ UINT H3String::FindLastOf(const CHAR ch) const
	{
		return CompareLastOf(&ch, 1, TRUE);
	}
	_H3API_ UINT H3String::FindLastNotOf(LPCSTR chars, UINT num_chars) const
	{
		return CompareLastOf(chars, num_chars, FALSE);
	}
	_H3API_ UINT H3String::FindLastNotOf(LPCSTR chars) const
	{
		return FindLastNotOf(chars, libc::strlen(chars));
	}
	_H3API_ UINT H3String::FindLastNotOf(const H3String& chars) const
	{
		return FindLastNotOf(chars.String(), chars.Length());
	}
	_H3API_ UINT H3String::FindLastNotOf(const CHAR ch) const
	{
		return FindLastNotOf(&ch, 1);
	}
	_H3API_ H3String& H3String::Trim()
	{
		if (Empty())
			return *this;
		constexpr CHAR whitespace[] = { ' ', '\t' };
		UINT str_start = FindFirstNotOf(whitespace, 2);
		if (str_start != npos)
			Erase(0, str_start);
		UINT str_end = FindLastNotOf(whitespace, 2);
		if (str_end != npos)
			Erase(str_end + 1, npos);
		return *this;
	}
	_H3API_ PCHAR H3String::At(UINT pos)
	{
		if (m_string)
			return m_string + std::min(pos, Length());
		return nullptr;
	}
	_H3API_ CHAR H3String::GetCharAt(UINT pos) const
	{
		if (m_string)
			return m_string[std::min(pos, Length())];
		return 0;
	}
	_H3API_ H3String& H3String::Remove(CHAR ch)
	{
		return Remove(&ch, 1);
	}
	_H3API_ H3String& H3String::Remove(LPCSTR substr)
	{
		return Remove(substr, libc::strlen(substr));
	}
	_H3API_ H3String& H3String::Remove(LPCSTR substr, UINT sublen)
	{
		PCHAR s, copy_end;
		if (!m_string)
			return *this;
		if (nullptr == (s = libc::strstr(m_string, substr)))
			return *this; // no match

		PCHAR copyFrom = s + sublen;
		while (nullptr != (copy_end = libc::strstr(copyFrom, substr)))
		{
			memmove(s, copyFrom, copy_end - copyFrom);
			s += copy_end - copyFrom;
			copyFrom = copy_end + sublen;
		}
		memmove(s, copyFrom, 1 + libc::strlen(copyFrom));
		m_length = libc::strlen(m_string);
		return *this;
	}
	_H3API_ H3String& H3String::Remove(UINT start, UINT end)
	{
		return Erase(start, end);
	}
	_H3API_ H3String & H3String::Erase(UINT pos)
	{
		return Erase(pos, pos + 1);
	}
	_H3API_ H3String & H3String::Erase(UINT first, UINT last)
	{
		if (first > m_length || first >= last)
			return *this;
		if (last > m_length)
		{
			Truncate(first);
			return *this;
		}
		PCHAR dst = begin() + first;
		PCHAR src = begin() + last;
		UINT  len = Length() - last; // copy length
		for (UINT i = 0; i < len; ++i)
			dst[i] = src[i];
		m_length -= last - first;
		m_string[m_length] = 0;
		return *this;
	}
	_H3API_ H3String & H3String::Erase(PCHAR first, PCHAR last)
	{
		return Erase(UINT(first - begin()), UINT(last - begin()));
	}
	_H3API_ BOOL H3String::Split(CHAR ch, H3String& out)
	{
		UINT pos = FindFirstOf(ch);
		if (pos == npos)
			return FALSE;
		if (pos == Length() - 1)
		{
			Truncate(pos);
			return TRUE;
		}

		out.Assign(begin() + pos + 1, Length() - pos - 1);
		Truncate(pos);
		return TRUE;
	}
	_H3API_ VOID H3String::Erase()
	{
		libc::memset(Begin(), 0, Length());
		m_length = 0;
	}
	_H3API_ BOOL H3String::Equals(LPCSTR msg, UINT len) const
	{
		if (!msg || Length() != len)
			return FALSE;

		return memcmp(msg, String(), Length()) == 0;
	}
	_H3API_ BOOL H3String::Equals(LPCSTR msg) const
	{
		if (!msg)
			return npos;
		return Equals(msg, libc::strlen(msg));
	}
	_H3API_ BOOL H3String::Equals(const H3String& other) const
	{
		return Equals(other.String(), other.Length());
	}
	_H3API_ BOOL H3String::Equals_i(LPCSTR msg, UINT len) const
	{
		if (Length() != len)
			return FALSE;
		return (libc::strcmpi(msg, String()) == 0);
	}
	_H3API_ BOOL H3String::Equals_i(LPCSTR msg) const
	{
		if (!msg)
			return FALSE;
		return Equals_i(msg, libc::strlen(msg));
	}
	_H3API_ BOOL H3String::Equals_i(const H3String& other) const
	{
		return Equals_i(other.String(), other.Length());
	}
	_H3API_ H3String& H3String::Insert(UINT pos, LPCSTR msg, UINT len)
	{
		if (len == 0 || msg == nullptr)
			return *this;
		if (pos >= Length()) // trying to insert at or after end
			return Append(msg, len);
		if (!Reserve(Length() + len))
			return *this;
		UINT copylen = Length() - pos;
		H3String temp; // simpler than malloc + free
		temp.Assign(m_string + pos, copylen);
		Truncate(pos); // temporarily cut out
		Append(msg, len); // insert msg
		Append(temp); // insert original end

		return *this;
	}
	_H3API_ H3String& H3String::Insert(UINT pos, LPCSTR msg)
	{
		if (msg)
			return Insert(pos, msg, libc::strlen(msg));
		return *this;
	}
	_H3API_ H3String& H3String::Insert(UINT pos, const H3String& to_insert)
	{
		return Insert(pos, to_insert.String(), to_insert.Length());
	}
	_H3API_ H3String& H3String::Insert(UINT pos, CHAR ch)
	{
		return Insert(pos, &ch, 1);
	}
	_H3API_ INT H3String::Compare(LPCSTR other) const
	{
		return libc::strcmp(String(), other);
	}
	_H3API_ INT H3String::Compare(const H3String & other) const
	{
		return Compare(other.String());
	}
	_H3API_ INT H3String::Comparei(LPCSTR other) const
	{
		return libc::strcmpi(String(), other);
	}
	_H3API_ INT H3String::Comparei(const H3String & other) const
	{
		return libc::strcmpi(String(), other.String());
	}
	_H3API_ BOOL H3String::operator<(const H3String& other) const
	{
		return libc::strcmp(String(), other.String()) < 0;
	}
	_H3API_ BOOL H3String::Truncate(UINT position)
	{
		if (position == npos)
			return FALSE;
		if (position < Length() && m_string)
		{
			m_length = position;
			m_string[m_length] = 0;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ UINT H3String::Occurrences(CHAR ch) const
	{
		if (Empty())
			return 0;
		UINT n = 0;
		for (UINT i = 0; i < m_length; ++i)
			if (m_string[i] == ch)
				++n;
		return n;
	}
	_H3API_ H3String& H3String::operator=(const H3String& other)
	{
		return Assign(other);
	}
	_H3API_ H3String& H3String::operator=(LPCSTR msg)
	{
		return Assign(msg);
	}
	_H3API_ H3String& H3String::operator=(CHAR ch)
	{
		return Assign(ch);
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3String& H3String::operator=(H3String&& other) noexcept
	{
		if (&other == this)
			return *this;

		m_string   = other.m_string;
		m_length   = other.m_length;
		m_capacity = other.m_capacity;
		other.Deref();

		return *this;
	}
#endif

	_H3API_ H3String& H3String::operator+=(const H3String& other)
	{
		return Append(other);
	}
	_H3API_ H3String& H3String::operator+=(LPCSTR msg)
	{
		return Append(msg);
	}
	_H3API_ H3String& H3String::operator+=(CHAR ch)
	{
		return Append(ch);
	}
	_H3API_ H3String& H3String::operator+=(const INT32 number)
	{
		return Append(number);
	}
	_H3API_ H3String& H3String::operator+=(UINT32 number)
	{
		return Append(number);
	}
	_H3API_ H3WString H3String::ToH3WString(UINT code_page) const
	{
		UINT req_len = libc::MultiByteToWideChar(code_page, 0, m_string, -1, 0, 0);
		H3WString wstring;
		wstring.Reserve(req_len);

		libc::MultiByteToWideChar( code_page, 0, m_string, -1, wstring.Begin(), req_len);
		wstring.m_length = req_len - 1; // wstring is null-terminated by MultiByteToWideChar
		return wstring;
	}
	_H3API_ BOOL H3String::operator==(const H3String& h3str) const
	{
		return Compare(h3str.String()) == 0;
	}
	_H3API_ BOOL H3String::operator==(LPCSTR str) const
	{
		return Compare(str) == 0;
	}
	_H3API_ BOOL H3String::operator!=(const H3String& h3str) const
	{
		return Compare(h3str.String()) != 0;
	}
	_H3API_ BOOL H3String::operator!=(LPCSTR str) const
	{
		return Compare(str) != 0;
	}
	_H3API_ CHAR H3String::operator[](UINT32 pos) const
	{
		return m_string[pos];
	}
	_H3API_ CHAR& H3String::operator[](UINT32 pos)
	{
		return m_string[pos];
	}
	_H3API_ INT8 H3String::References() const
	{
		if (m_string)
			return m_string[-1];
		return 0;
	}
	_H3API_ VOID H3String::IncreaseReferences()
	{
		if (m_string)
			++m_string[-1];
	}
	_H3API_ BOOL H3String::FormattedNumber(INT32 number)
	{
		if (!m_string && !Reserve())
			return FALSE;
		m_length = H3Numbers::AddCommas(number, m_string);

		return TRUE;
	}
	_H3API_ BOOL H3String::ScaledNumber(INT32 number, INT32 decimals)
	{
		if (!m_string && !Reserve())
			return FALSE;
		m_length = H3Numbers::MakeReadable(number, m_string, decimals);
		return TRUE;
	}
	_H3API_ H3String H3String::PrintfH3(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		CDECL_3(void, 0x6190DE, 0x69971C, format, args);
		va_end(args);
		return H3String(PCHAR(0x69971C));
	}
	_H3API_ H3String & H3String::PrintfAppendH3(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		CDECL_3(void, 0x6190DE, 0x69971C, format, args);
		va_end(args);
		return Append(PCHAR(0x69971C));
	}
	_H3API_ INT32 H3String::ToSigned() const
	{
		return libc::atoi(String());
	}
	_H3API_ UINT32 H3String::ToUnsigned() const
	{
		return libc::atol(String());
	}
	_H3API_ DOUBLE H3String::ToDouble() const
	{
		return libc::atof(String());
	}
	_H3API_ INT32 H3String::HexToSigned() const
	{
		return libc::strtol(String(), nullptr, 16);
	}
	_H3API_ UINT32 H3String::HexToUnsigned() const
	{
		return libc::strtoul(String(), nullptr, 16);
	}
	_H3API_ H3String H3String::GetLocalTime()
	{
		SYSTEMTIME time;
		STDCALL_1(VOID, PtrAt(0x63A248), &time);
		H3String str;
		str.Printf("%04d.%02d.%02d - %02dh%02dm%02ds",
			time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
		return str;
	}
	_H3API_ H3String H3String::FormatNumber(INT32 number)
	{
		H3String str;
		str.Reserve(15);
		CHAR buffer[16];
		INT32 num_len = libc::sprintf(buffer, "%d", number);
		INT32 len = num_len;
		PCHAR dst = str.Begin();
		PCHAR src = buffer;
		if (*src == '-')
		{
			*dst++ = *src++;
			--num_len;
		}
		for (INT32 commas = 2 - num_len % 3; *src; commas = (commas + 1) % 3)
		{
			*dst++ = *src++;
			if (commas == 1)
				*dst++ = ',';
		}
		*--dst = 0;
		str.m_length = dst - str.m_string;
		return str;
	}
	_H3API_ H3String H3String::ShortScale(INT32 num, INT32 decimals)
	{
		constexpr INT32 RN_MIN_VALUE = 10000;
		INT32 power;
		char buffer[16];
		H3String str;

		INT64 m;
		if (num != INT_MIN)
			m = Abs(num);
		else
			m = INT64(INT_MAX) + 1;

		if (m < RN_MIN_VALUE)
		{
			str.Append(num);
			return str;
		}

		INT32 dec  = std::min(decimals, 3);
		INT32 plus = 500;
		INT32 div  = 1000;
		for (INT32 i = 0; i < dec; i++)
		{
			plus /= 10;
			div  /= 10;
		}
		INT32 d = power = 0;
		while (m >= 1000)
		{
			d  = INT32(m);
			m /= 1000;
			power++;
		}
		d = (d + plus) / div * div;

		INT32 len = libc::sprintf(buffer, "%d", d);
		INT32 c = 2 - len % 3;
		str.Reserve(15);
		CHAR *dst = str.m_string;
		CHAR *src = buffer;

		if (num < 0)
			*dst++ = '-';

		while (*src)
		{
			*dst++ = *src++;
			if (c == 1)
			{
				if (dec)
				{
					*dst++ = '.';
					for (INT32 i = 0; i < dec; i++)
						*dst++ = *src++;
				}
				break;
			}
			c = (c + 1) % 3;
		}
		constexpr CHAR scale[] = { 0, 'k', 'M', 'B' };
		*dst++ = scale[power];
		*dst = 0;

		str.m_length = dst - str.m_string - (power == 0);

		return str;
	}
	_H3API_ H3String H3String::Format(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		H3String str = Format(format, args);
		va_end(args);
		return str;
	}
	_H3API_ H3String H3String::Format(LPCSTR format, va_list args)
	{
		H3String str;
		INT32 len = _vsnprintf(nullptr, 0, format, args);
		if (len > 0 && str.Reserve(len + 1))
		{
			len = libc::vsprintf(str.Begin(), format, args);
			str.m_length = len;
		}
		return str;
	}

	_H3API_ H3String& H3String::Printf(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		Assign(Format(format, args));
		va_end(args);
		return *this;
	}
	_H3API_ H3String& H3String::PrintfAppend(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		Append(Format(format, args));
		va_end(args);
		return *this;
	}

#ifdef _H3API_STD_CONVERSIONS_
	_H3API_ H3String::H3String(const std::string& str) :
		m_string(nullptr),
		m_length(0),
		m_capacity(0)
	{
		Assign(str);
	}
	_H3API_ INT H3String::operator==(const std::string& str) const
	{
		return Compare(str.c_str());
	}
	_H3API_ H3String& H3String::operator+=(const std::string& str)
	{
		return Append(str);
	}
	_H3API_ H3String& H3String::operator=(const std::string& str)
	{
		return Assign(str);
	}
	_H3API_ H3String& H3String::Assign(const std::string& str)
	{
		return Assign(str.c_str(), str.length());
	}
	_H3API_ H3String& H3String::Append(const std::string& str)
	{
		Append(str.c_str(), str.length());
		return *this;
	}
	_H3API_ std::string H3String::to_std_string() const
	{
		return std::string(String(), Length());
	}
#endif /* _H3API_STD_CONVERSIONS_ */

	_H3API_ VOID H3WString::Destroy()
	{
		if (m_string)
		{
			ByteAllocator().destroy(base());
			deref();
		}
	}
	_H3API_ VOID H3WString::tidy(BOOL8 dereference /*= TRUE*/)
	{
		THISCALL_2(VOID, 0x612988, this, dereference);
	}
	_H3API_ VOID H3WString::deref()
	{
		m_string = nullptr;
		m_length = 0;
		m_capacity = 0;
	}
	_H3API_ BOOL8 H3WString::grow(UINT32 size, BOOL8 trim /*= FALSE*/)
	{
		return THISCALL_3(BOOL8, 0x6128FF, this, size, trim);
	}
	_H3API_ UINT8& H3WString::references()
	{
		return *(reinterpret_cast<PUINT8>(m_string) - 1);
	}
	_H3API_ PBYTE H3WString::base()
	{
		return m_string ? PBYTE(PBYTE(m_string) - 2) : nullptr;
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3WString& H3WString::move(H3WString&& other)
	{
		if (this == &other)
			return *this;
		tidy(TRUE);
		m_string   = other.m_string;
		m_length   = other.m_length;
		m_capacity = other.m_capacity;
		other.deref();
		return *this;
	}
#endif

	_H3API_ H3WString::H3WString() :
		m_string(), m_length(), m_capacity()
	{
	}
	_H3API_ H3WString::H3WString(const H3WString& other) :
		m_string(), m_length(), m_capacity()
	{
		Assign(other);
	}
	_H3API_ H3WString::H3WString(LPCWSTR text) :
		m_string(), m_length(), m_capacity()
	{
		Assign(text);
	}
	_H3API_ H3WString::H3WString(WCHAR character) :
		m_string(), m_length(), m_capacity()
	{
		Assign(character);
	}
	_H3API_ H3WString::H3WString(LPCWSTR text, UINT32 length)
	{
		Assign(text, length);
	}
	_H3API_ H3WString::~H3WString()
	{
		tidy(TRUE);
	}
	_H3API_ H3WString& H3WString::Append(LPCWSTR text, UINT32 length)
	{
		if (length == 0)
			return *this;
		const UINT size = m_length + length;
		if (size >= max_len)
			STDCALL_0(VOID, 0x60B0FB); // string too long exception

		if (size >= m_capacity && !grow(size))
			return *this;

		WCHAR* dst = m_string + m_length;
		LPCWSTR src = text;
		const UINT extra_length = length;
		while (length > 0)
		{
			*dst++ = *src++;
			--length;
		}
		*dst = 0;
		m_length += extra_length;

		return *this;
	}
	_H3API_ H3WString& H3WString::Append(LPCWSTR text)
	{
		return Append(text, libc::wcslen(text));
	}
	_H3API_ H3WString& H3WString::Append(WCHAR character)
	{
		return Append(&character, 1);
	}
	_H3API_ H3WString& H3WString::Append(const H3WString& other)
	{
		return Append(other, 0, other.Length());
	}
	_H3API_ H3WString& H3WString::Append(const H3WString& other, UINT32 start_position, UINT32 end_position)
	{
		return THISCALL_4(H3WString&, 0x612B0C, this, other, start_position, end_position);
	}
#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3WString& H3WString::Assign(H3WString&& other)
	{
		return move(std::move(other));
	}
#endif

	_H3API_ H3WString& H3WString::Assign(LPCWSTR text, UINT32 length)
	{
		return THISCALL_3(H3WString&, 0x6126F3, this, text, length);
	}
	_H3API_ H3WString& H3WString::Assign(LPCWSTR text)
	{
		return Assign(text, libc::wcslen(text));
	}
	_H3API_ H3WString& H3WString::Assign(const H3WString& other)
	{
		return Assign(other.String(), other.Length());
	}
	_H3API_ H3WString& H3WString::SoftCopy(const H3WString& other)
	{
		return THISCALL_4(H3WString&, 0x612615, this, &other, 0, other.Length());
	}
	_H3API_ H3WString& H3WString::Assign(WCHAR character)
	{
		return Assign(&character, 1);
	}
	_H3API_ UINT32 H3WString::Size() const
	{
		return m_length;
	}
	_H3API_ UINT32 H3WString::Length() const
	{
		return m_length;
	}
	_H3API_ BOOL32 H3WString::IsEmpty() const
	{
		return m_length == 0;
	}
	_H3API_ LPCWSTR H3WString::String() const
	{
		return m_string ? m_string : reinterpret_cast<LPCWSTR>(&m_string);
	}
	_H3API_ VOID H3WString::Insert(UINT32 start_position, UINT32 end_position, WCHAR character)
	{
		THISCALL_4(VOID, 0x61278D, this, start_position, end_position, character);
	}
	_H3API_ H3WString& H3WString::Insert(UINT32 start_position, LPCWSTR text)
	{
		return Insert(start_position, libc::wcslen(text));
	}
	_H3API_ H3WString& H3WString::Insert(UINT32 start_position, LPCWSTR text, UINT length)
	{
		if (length == 0 || text == nullptr)
			return *this;
		if (start_position >= Length())
			return Append(text, length);

		if (!Reserve(Length() + length))
			return *this;

		UINT copylen = Length() - start_position;
		H3WString temp;
		temp.Assign(m_string + start_position, copylen);
		m_string[start_position] = WCHAR(0);
		m_length = start_position;
		Append(text, length);
		Append(temp);
		return *this;
	}
	_H3API_ H3WString& H3WString::Insert(UINT32 start_position, WCHAR text)
	{
		return Insert(start_position, &text, 1);
	}
	_H3API_ H3WString& H3WString::Insert(UINT32 start_position, const H3WString& other)
	{
		return Insert(start_position, other.String(), other.Length());
	}
	_H3API_ PWCHAR H3WString::Begin()
	{
		return m_string ? m_string : PWCHAR(&m_string);
	}
	_H3API_ LPCWSTR H3WString::begin()
	{
		return m_string ? m_string : PWCHAR(&m_string);
	}
	_H3API_ LPCWSTR H3WString::begin() const
	{
		return m_string ? m_string : PWCHAR(&m_string);
	}
	_H3API_ LPCWSTR H3WString::end()
	{
		return m_string ? m_string + m_length : PWCHAR(&m_string);
	}
	_H3API_ LPCWSTR H3WString::end() const
	{
		return m_string ? m_string + m_length : PWCHAR(&m_string);
	}
	_H3API_ BOOL8 H3WString::Reserve(UINT32 length)
	{
		return grow(length);
	}
	_H3API_ UINT8 H3WString::References() const
	{
		return *(reinterpret_cast<PUINT8>(m_string) - 1);
	}
	_H3API_ VOID H3WString::IncreaseReferences()
	{
		UINT8& ref = references();
		if (ref != frozen)
			++ref;
	}
	_H3API_ VOID H3WString::DecreaseReferences()
	{
		UINT8& ref = references();
		if (ref && ref != frozen)
			--ref;
	}
	_H3API_ H3WString& H3WString::Erase(UINT32 start_position, UINT32 end_position)
	{
		return THISCALL_3(H3WString&, 0x612867, this, start_position, end_position);
	}
	_H3API_ H3WString& H3WString::Erase()
	{
		return Erase(0, npos);
	}
	_H3API_ INT32 H3WString::Compare(LPCWSTR string, UINT32 length) const
	{
		return libc::CompareStringW(LOCALE_NEUTRAL, 0, String(), Length(), string, length) - CSTR_EQUAL;
	}
	_H3API_ INT32 H3WString::Compare(LPCWSTR string) const
	{
		return Compare(string, libc::wcslen(string));
	}
	_H3API_ INT32 H3WString::Compare(const H3WString& other) const
	{
		return Compare(other.String(), other.Length());
	}
	_H3API_ INT32 H3WString::Compare(WCHAR character) const
	{
		return Compare(&character, 1);
	}
	_H3API_ BOOL H3WString::Equals(LPCWSTR string, UINT32 length) const
	{
		if (Length() != length)
			return FALSE;
		return Compare(string, length) == 0;
	}
	_H3API_ BOOL H3WString::Equals(LPCWSTR string) const
	{
		return Equals(string, libc::wcslen(string));
	}
	_H3API_ BOOL H3WString::Equals(const H3WString& other) const
	{
		return Equals(other.String(), other.Length());
	}
	_H3API_ BOOL H3WString::Equals(WCHAR character) const
	{
		return Equals(&character, 1);
	}
	_H3API_ WCHAR H3WString::operator[](UINT position) const
	{
		return m_string[position];
	}
	_H3API_ WCHAR& H3WString::operator[](UINT position)
	{
		return m_string[position];
	}
	_H3API_ BOOL H3WString::operator==(const H3WString& other)
	{
		return Equals(other);
	}
	_H3API_ BOOL H3WString::operator==(LPCWSTR msg)
	{
		return Equals(msg);
	}
	_H3API_ BOOL H3WString::operator==(WCHAR ch)
	{
		return Equals(ch);
	}
	_H3API_ H3WString& H3WString::operator+=(WCHAR ch)
	{
		return Append(ch);
	}
	_H3API_ H3WString& H3WString::operator+=(LPCWSTR msg)
	{
		return Append(msg);
	}
	_H3API_ H3WString& H3WString::operator+=(const H3WString& other)
	{
		return Append(other);
	}
	_H3API_ H3String H3WString::ToH3String(UINT code_page) const
	{
		UINT req_len = libc::WideCharToMultiByte(code_page, 0, m_string, -1, NULL, 0, NULL, NULL);
		H3String string;
		string.Reserve(req_len);

		libc::WideCharToMultiByte(code_page, 0, m_string, -1, string.Begin(), req_len, NULL, NULL);
		string.m_length = req_len - 1; // string is null-terminated by WideCharToMultiByte
		return string;
	}
	_H3API_ H3WString& H3WString::operator=(WCHAR ch)
	{
		return Assign(ch);
	}
	_H3API_ H3WString& H3WString::operator=(LPCWSTR msg)
	{
		return Assign(msg);
	}
	_H3API_ H3WString& H3WString::operator=(const H3WString& other)
	{
		return Assign(other);
	}
}//////////////////////////////////////////////////////////////////////

namespace h3
{
	_H3API_ H3Army::iterator::iterator(INT32* type) :
		m_type(type)
	{
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator*()
	{
		return *this;
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator++()
	{
		++m_type;
		return *this;
	}
	_H3API_ H3Army::iterator H3Army::iterator::operator++(int)
	{
		iterator it(m_type);
		++m_type;
		return it;
	}
	_H3API_ BOOL H3Army::iterator::operator==(const iterator& other)
	{
		return m_type == other.m_type;
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator=(const iterator& other)
	{
		Type() = other.Type();
		Count() = other.Count();
		return *this;
	}
	_H3API_ BOOL H3Army::iterator::operator!=(const iterator& other)
	{
		return m_type != other.m_type;
	}
	_H3API_ BOOL H3Army::iterator::operator!() const
	{
		return *m_type == -1;
	}
	_H3API_ INT32& H3Army::iterator::Type()
	{
		return *m_type;
	}
	_H3API_ INT32 H3Army::iterator::Type() const
	{
		return *m_type;
	}
	_H3API_ INT32& H3Army::iterator::Count()
	{
		return m_type[7];
	}
	_H3API_ INT32 H3Army::iterator::Count() const
	{
		return m_type[7];
	}
	_H3API_ H3Army::H3Army()
	{
		THISCALL_1(H3Army&, 0x44A750, this);
	}
	_H3API_ H3Army::H3Army(const H3Army& other)
	{
		(*this) = other;
	}
	_H3API_ BOOL H3Army::AddStack(INT32 type, INT32 amount, INT32 slot)
	{
		return THISCALL_4(BOOL, 0x44A9B0, this, type, amount, slot);
	}
	_H3API_ VOID H3Army::SplitFromStackToStack(INT32 fromStack, INT32 toStack, INT32 fraction)
	{
		INT32 num = count[fromStack] / fraction;
		count[fromStack] -= num;
		AddStack(type[fromStack], num, toStack);
	}
	_H3API_ INT32 H3Army::FirstFreeSlot()
	{
		INT32 r = 0;
		for (INT32 i = 0; i < 7; i++)
		{
			if (type[i] != -1)
				r++;
			else
				return r;
		}
		return -1;
	}
	_H3API_ INT32 H3Army::FindExistingByIndex(INT32 index)
	{
		if (index >= 0 && index < 7)
		{
			INT32 j = 0;
			for (INT32 i = 0; i < 7; i++)
			{
				if (type[i] != -1)
					j++;
				if (j == index)
					return i;
			}
		}
		return -1;
	}
	_H3API_ INT32 H3Army::GetStackCount()
	{
		return THISCALL_1(INT32, 0x44A990, this);
	}
	_H3API_ INT32 H3Army::GetCreaturesCount()
	{
		return THISCALL_1(INT32, 0x44AA70, this);
	}
	_H3API_ BOOL8 H3Army::HasCreatureType(INT32 cre)
	{
		return THISCALL_2(BOOL8, 0x44A850, this, cre);
	}
	_H3API_ BOOL H3Army::HasCreatures()
	{
		return THISCALL_1(BOOL, 0x449370, this);
	}
	_H3API_ VOID H3Army::Clear()
	{
		THISCALL_1(VOID, 0x44A750, this);
	}
	_H3API_ VOID H3Army::Clear(INT stack)
	{
		THISCALL_2(VOID, 0x44A830, this, stack);
	}
	_H3API_ VOID H3Army::ClearAndGive(INT type, INT count)
	{
		THISCALL_3(VOID, 0x44A770, this, type, count);
	}
	_H3API_ BOOL8 H3Army::IsUndeadArmy()
	{
		return THISCALL_1(BOOL8, 0x44A7F0, this);
	}
	_H3API_ INT32 H3Army::NumberAlignments(INT8(&towns)[9])
	{
		return THISCALL_2(INT32, 0x44A880, this, &towns);
	}
	_H3API_ INT32 H3Army::GetArmyValue()
	{
		return THISCALL_1(INT32, 0x44A950, this);
	}
	_H3API_ H3Army::iterator H3Army::begin()
	{
		return iterator(type);
	}
	_H3API_ H3Army::iterator H3Army::end()
	{
		return iterator(type + 7);
	}
	_H3API_ H3Army& H3Army::operator=(const H3Army& other)
	{
		for (INT32 i = 0; i < 7; ++i)
		{
			count[i] = other.count[i];
			type[i]  = other.type[i];
		}
		return *this;
	}
	_H3API_ H3Army::iterator H3Army::operator[](UINT index)
	{
		return iterator(type + index);
	}
	_H3API_ VOID H3Army::Swap(UINT from, UINT to)
	{
		std::swap(type[from], type[to]);
		std::swap(count[from], count[to]);
	}

	_H3API_ H3Army H3Army::SplitCreatures(const H3Point& p, H3Hero* hero, INT32 type0, INT32 amount0, INT32 type1 /*= -1*/, INT32 amount1 /*= 0*/, INT32 stacks1 /*= 0*/, INT32 type2 /*= -1*/, INT32 amount2 /*= 0*/, INT32 stacks2 /*= 0*/)
	{
		H3Army split;
		DOUBLE hero_power = hero ? DOUBLE(hero->army.GetArmyValue()) : 0.0;
		INT32 ai_value    = H3CreatureInformation::Get()[type0].aiValue * amount0;
		if (type1 != -1)
			ai_value += H3CreatureInformation::Get()[type1].aiValue * amount1;
		if (type2 != -1)
			ai_value += H3CreatureInformation::Get()[type2].aiValue * amount2;
		INT32 stacks_count = 7;
		DOUBLE* thresholds = reinterpret_cast<DOUBLE*>(0x677708);
		DOUBLE* limit      = reinterpret_cast<DOUBLE*>(0x6776E0);
		DOUBLE ratio       = hero_power / DOUBLE(ai_value);
		do
		{
			if (ratio < *thresholds)
				break;
			--stacks_count;
			--thresholds;
		} while (thresholds > limit);

		H3Random::SeedRestore restore;
		UINT seed = 0x3C907 * p.x + 0x4386D * p.y + 0x4BB5F * p.z + 0x25EA7;
		THISCALL_1(VOID, FuncAt(0x4AC2D6), seed); // catches hdmod's custom seed function if it's there
		INT32 extra_stack = H3Random::Rand(1, 100);
		if (extra_stack <= 20)
			--stacks_count;
		if (extra_stack >= 80 && stacks_count < 7)
			++stacks_count;
		if (type1 != -1)
			stacks_count -= stacks1;
		if (type2 != -1)
			stacks_count -= stacks2;
		if (stacks_count > amount0)
			stacks_count = amount0;
		if (stacks_count < 1)
			stacks_count = 1;

		if (stacks_count > 0)
		{
			INT32 mid_point    = amount0 % stacks_count;
			INT32 stack_amount = amount0 / stacks_count;
			for (INT32 i = 0; i < stacks_count; ++i)
			{
				split.count[i] = stack_amount + (mid_point > i);
				split.type[i]  = type0;
			}
		}
		INT32 upgrade = H3Random::Rand(1, 100);
		if (H3Creature::HasUpgrade(type0) && stacks_count > 1 && upgrade <= 50 && type1 == -1 && type2 == -1)
			split.type[stacks_count >> 1] = H3Creature::GetUpgrade(type0);
		if (type1 != -1 && stacks1)
		{
			int mid_point = amount1 % stacks1 + stacks_count;
			int count1    = amount1 / stacks1;
			for (INT32 i = stacks_count; i < stacks_count + stacks1; ++i)
			{
				split.count[i] = count1 + (mid_point > i);
				split.type[i]  = type1;
			}
		}
		if (type2 != -1 && stacks2)
		{
			int mid_point = amount2 % stacks2 + stacks_count + stacks1;
			int count2 = amount2 / stacks2;
			for (INT32 i = stacks_count + stacks1; i < stacks_count + stacks1 + stacks2; ++i)
			{
				split.count[i] = count2 + (mid_point > i);
				split.type[i] = type2;
			}
		}
		if (type1 != -1 || type2 != -1)
		{
			H3Army copy(split);
			typedef INT SplitOrder[7];
			typedef SplitOrder Type2SplitOrder[7];
			SplitOrder& order = reinterpret_cast<Type2SplitOrder*>(0x63DF94)[stacks_count][stacks2];
			for (INT32 i = 0; i < 7; ++i)
			{
				split.count[i] = copy.count[order[i]];
				split.type[i]  = copy.type[order[i]];
			}
		}
		return split;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapArtifact* H3MapitemArtifact::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3MapArtifact* H3MapitemArtifact::Get(H3Main* main)
	{
		return hasSetup ? &main->mainSetup.artifactResource[id] : nullptr;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3BlackMarket* H3MapitemBlackMarket::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3BlackMarket* H3MapitemBlackMarket::Get(H3Main* main)
	{
		return &main->blackMarkets[id];
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3Boat* H3MapitemBoat::Get()
    {
        return Get(H3Main::Get());
    }
    _H3API_ H3Boat* H3MapitemBoat::Get(H3Main* main)
    {
        return &main->boats[index];
    }

} /* namespace h3 */

namespace h3
{
	_H3API_ eResource H3MapitemCampfire::GetType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemCampfire::GetGold()
	{
		return GetResourceAmount() * 100;
	}
	_H3API_ INT32 H3MapitemCampfire::GetResourceAmount()
	{
		return resValue;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ eArtifact H3MapitemCorpse::GetArtifact()
	{
		return eArtifact(artifactID);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Resources::H3Resources() :
		wood(0),
		mercury(0),
		ore(0),
		sulfur(0),
		crystal(0),
		gems(0),
		gold(0)
	{
	}
	_H3API_ H3Resources::H3Resources(H3Resources const& other) :
		wood(other.wood),
		mercury(other.mercury),
		ore(other.ore),
		sulfur(other.sulfur),
		crystal(other.crystal),
		gems(other.gems),
		gold(other.gold)
	{
	}
	_H3API_ BOOL H3Resources::EnoughResources(const H3Resources& cost) const
	{
		return *this >= cost;
	}
	_H3API_ VOID H3Resources::RemoveResources(const H3Resources& cost)
	{
		operator-=(cost);
	}
	_H3API_ VOID H3Resources::GainResourcesOF(const H3Resources& gain)
	{
		operator+=(gain);
	}
	_H3API_ INT H3Resources::Count() const
	{
		INT r = 0;
		for (INT32 i = 0; i < 7; ++i)
			if (asArray[i] != 0)
				++r;
		return r;
	}
	_H3API_ PINT H3Resources::begin()
	{
		return asArray;
	}
	_H3API_ PINT H3Resources::end()
	{
		return &asArray[7];
	}
	_H3API_ PINT H3Resources::cbegin() const
	{
		return PINT(this);
	}
	_H3API_ PINT H3Resources::cend() const
	{
		return PINT(&asArray[7]);
	}
	_H3API_ H3Resources& H3Resources::operator+=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
			if (asArray[i] > 0) // positive
			{
				asArray[i] += other.asArray[i]; // add resources

				if (other.asArray[i] > 0) // check if there was overflow
				{
					if (asArray[i] <= 0)
						asArray[i] = INT_MAX;
				}
				else if (asArray[i] < 0) // no negative resources from subtraction
					asArray[i] = 0;
			}
			else // gain normally
				asArray[i] += other.asArray[i];
		return *this;
	}
	_H3API_ H3Resources& H3Resources::operator-=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
		{
			if (asArray[i] >= 0)
				asArray[i] = std::max(0, asArray[i] - other.asArray[i]);
			else
				asArray[i] -= other.asArray[i];
		}
		return *this;
	}
	_H3API_ H3Resources& H3Resources::operator=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
			asArray[i] = other.asArray[i];
		return *this;

	}
	_H3API_ BOOL H3Resources::operator>=(const H3Resources& other) const
	{
		return !(*this < other);
	}
	_H3API_ BOOL H3Resources::operator>(const H3Resources& other) const
	{
		return other < *this;
	}
	_H3API_ BOOL H3Resources::operator<(const H3Resources& other) const
	{
		for (INT32 i = 0; i < 7; ++i)
			if (other.asArray[i] > asArray[i])
				return TRUE;
		return FALSE;
	}
	_H3API_ BOOL H3Resources::operator<=(const H3Resources& other) const
	{
		return !(*this > other);
	}
	_H3API_ INT& H3Resources::operator[](INT32 index)
	{
		return asArray[index];
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3IndexVector::H3IndexVector(INT min_num, INT max_num)
	{
		THISCALL_3(H3IndexVector*, 0x50C8D0, this, min_num, max_num);
	}
	_H3API_ H3IndexVector::~H3IndexVector()
	{
		H3ObjectAllocator<BOOL8>().deallocate(m_begin);
	}
	_H3API_ INT H3IndexVector::ChooseRandom()
	{
		return THISCALL_1(INT, 0x50C930, this);
	}
	_H3API_ INT H3IndexVector::InvalidIndex()
	{
		return m_minimum - 1;
	}
} /* namespace h3 *///////////////////////////////////////////////////////////////////////

namespace h3
{
	_H3API_ BOOL H3CreatureBank::HasUpgradedStack()
	{
		return guardians.type[0] != guardians.type[2];
	}
	_H3API_ VOID H3CreatureBank::SetupBank(INT32 type, INT32 level)
	{
		H3CreatureBankState* cbs = &H3CreatureBankSetup::Get()[type].states[level];
		guardians = cbs->guardians;
		resources = cbs->resources;
		creatureRewardType = cbs->creatureRewardType;
		creatureRewardCount = cbs->creatureRewardCount;

		const INT32 stacks = guardians.GetStackCount();
		INT32 stack_to_split;
		INT32 first_free_slot;
		INT32 fractions;
		switch (stacks)
		{
		case 1:
			fractions = 5;
			stack_to_split = 0;
			while (fractions > 1)
			{
				first_free_slot = guardians.FirstFreeSlot();
				if (first_free_slot != -1)
					guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
				fractions--;
			}
			break;
		case 2:
			stack_to_split = 1;
			fractions = 2;
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);

			fractions = 3;
			stack_to_split = 0;
			while (fractions > 1)
			{
				first_free_slot = guardians.FirstFreeSlot();
				if (first_free_slot != -1)
					guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
				fractions--;
			}
			break;
		case 3:
			fractions = 2; // split in 2
			stack_to_split = 1; // stack 1 is first split
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);

			stack_to_split = 0; // then stack 0 is split
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
			break;
		default:
			break;
		}
	}
	_H3API_ VOID H3CreatureBank::UpgradeStack(BOOL upg)
	{
		if (upg) // in code there are additional checks for game type (RoE) and creature (4 Elementals)
		{
			if (THISCALL_1(char, 0x47AA50, guardians.type[0])) // creature has upgrade?
				guardians.type[2] = THISCALL_1(INT32, 0x47AAD0, guardians.type[0]);
		}
		else
			guardians.type[2] = guardians.type[0];
	}
	_H3API_ H3CreatureBank* H3MapitemCreatureBank::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3CreatureBank* H3MapitemCreatureBank::Get(H3Main* main)
	{
		return &main->creatureBanks[id];
	}
	_H3API_ H3PlayersBitfield H3MapitemCreatureBank::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemCreatureBank::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ INT8& H3PrimarySkills::Get(ePrimary skill)
	{
		return priSkills[static_cast<INT>(skill)];
	}
	_H3API_ PINT8 H3PrimarySkills::begin()
	{
		return &priSkills[0];
	}
	_H3API_ PINT8 H3PrimarySkills::end()
	{
		return &priSkills[4];
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3PandorasBox* H3MapitemPandorasBox::Get()
	{
		return Get(H3Main::Get());
	}

	_H3API_ H3PandorasBox* H3MapitemPandorasBox::Get(H3Main* main)
	{
		return &main->mainSetup.pandoraEvents[id];
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Event* H3MapitemEvent::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Event* H3MapitemEvent::Get(H3Main* main)
	{
		return reinterpret_cast<H3Event*>(&main->mainSetup.pandoraEvents[id]);
	}
	_H3API_ H3PlayersBitfield H3MapitemEvent::EnabledPlayers()
	{
		return H3PlayersBitfield(enabled);
	}
	_H3API_ VOID H3MapitemEvent::SetEnabled(const H3PlayersBitfield& players)
	{
		enabled = players.bits;
	}
} /* namespace h3 */

namespace h3
{

	_H3API_ INT32 H3MapitemFlotsam::GetWood() const
	{
		switch (type)
		{
		case WOOD5:
		case WOOD5_GOLD200:
			return 5;
		case WOOD10_GOLD500:
			return 10;
		default:
			return 0;
		}
	}
	_H3API_ INT32 H3MapitemFlotsam::GetGold() const
	{
		switch (type)
		{
		case WOOD5_GOLD200:
			return 200;
		case WOOD10_GOLD500:
			return 500;
		default:
			return 0;
		}
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemFountainFortune::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemFountainFortune::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Garrison* H3MapitemGarrison::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Garrison* H3MapitemGarrison::Get(H3Main* main)
	{
		return &main->garrisons[index];
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3Generator* H3MapitemGenerator::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Generator* H3MapitemGenerator::Get(H3Main* main)
	{
		return &main->dwellings[id];
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Hero* H3MapitemHero::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Hero* H3MapitemHero::Get(H3Main* main)
	{
		return main->GetHero(index);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ eResource H3MapitemLeanTo::GetType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemLeanTo::GetAmount()
	{
		return resValue;
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3Mine* H3MapitemMine::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Mine* H3MapitemMine::Get(H3Main* main)
	{
		return &main->minesLighthouses[index];
	}
	_H3API_ BOOL H3Mine::IsAbandonned() const
	{
		return abandoned;
	}

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ eSpell H3MapitemMagicShrine::GetSpell()
	{
		return eSpell(spell);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ INT32 H3MapitemMonolith::GetSubtype()
	{
		return reinterpret_cast<H3MapItem*>(this)->objectSubtype;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Monster* H3MapitemMonster::Get() const
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Monster* H3MapitemMonster::Get(H3Main* main) const
	{
		return hasSetup ? &main->mainSetup.monsters[setupIndex] : nullptr;
	}
	_H3API_ INT32 H3MapitemMonster::CreatureType() const
	{
		return reinterpret_cast<H3MapItem*>(const_cast<H3MapitemMonster*>(this))->objectSubtype;
	}
	_H3API_ INT32 H3MapitemMonster::DiploJoinCost(H3Hero* hero) const
	{
		return H3Diplomacy::DiplomacyJoinCost(hero, *this);
	}
	_H3API_ H3Monster* SODSP_MapMonster::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Monster* SODSP_MapMonster::Get(H3Main* main)
	{
		return hasSetup ? &main->mainSetup.monsters[setupIndex] : nullptr;
	}
	_H3API_ INT32 SODSP_MapMonster::CreatureType()
	{
		return reinterpret_cast<H3MapItem*>(this)->objectSubtype;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ INT32 H3MapitemMysticGarden::GetAmount()
	{
		return GetType() == eResource::GOLD ? 500 : 5;
	}
	_H3API_ eResource H3MapitemMysticGarden::GetType()
	{
		return eResource(resType);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3Signpost* H3MapitemSign::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Signpost* H3MapitemSign::Get(H3Main* main)
	{
		return &main->signpostsBottles[id];
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemPyramid::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemPyramid::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ eSpell H3MapitemPyramid::GetSpell()
	{
		return eSpell(spell);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3QuestGuard* H3MapitemQuestGuard::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3QuestGuard* H3MapitemQuestGuard::Get(H3Main* main)
	{
		return &main->mainSetup.questGuards[id];
	}
	_H3API_ INT32 H3Quest::QuestVector::Count()
	{
		return last - first;
	}
	_H3API_ INT32& H3Quest::QuestVector::operator[](INT32 index)
	{
		return first[index];
	}
	_H3API_ INT32* H3Quest::QuestVector::begin()
	{
		return first;
	}
	_H3API_ INT32* H3Quest::QuestVector::end()
	{
		return last;
	}
	_H3API_ H3Point H3Quest::GetCoordinates() const
	{
		H3Position pos(data.killMonster.packedCoords);
		return pos.Unpack();
	}
	_H3API_ eQuest H3Quest::GetQuestType() const
	{
		return THISCALL_1(eQuest, vTable->type, this);
	}
	_H3API_ H3Resources& H3Quest::GetResources()
	{
		return *reinterpret_cast<H3Resources*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetArtifacts()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetCreatureCounts()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetCreatureTypes()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data.getCreatures.type);
	}
	_H3API_ eQuest H3QuestGuard::QuestType() const
	{
		return quest ? quest->GetQuestType() : eQuest::NONE;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ INT32 H3MapitemRefugeeCamp::CreatureType()
	{
		return reinterpret_cast<H3MapItem*>(this)->objectSubtype;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapResource* H3MapitemResource::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3MapResource* H3MapitemResource::Get(H3Main* main)
	{
		return hasSetup ? reinterpret_cast<H3MapResource*>(&main->mainSetup.artifactResource[setupIndex]) : nullptr;
	}
	_H3API_ eResource H3MapitemResource::GetType()
	{
		return eResource(reinterpret_cast<H3MapItem*>(this)->objectSubtype);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapitemScholar::eType H3MapitemScholar::GetType()
	{
		return eType(type);
	}
	_H3API_ ePrimary H3MapitemScholar::GetPrimary()
	{
		return ePrimary(pSkill);
	}
	_H3API_ eSecondary H3MapitemScholar::GetSecondary()
	{
		return eSecondary(sSkill);
	}
	_H3API_ eSpell H3MapitemScholar::GetSpell()
	{
		return eSpell(spell);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapArtifact* H3MapitemScroll::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3MapArtifact* H3MapitemScroll::Get(H3Main* main)
	{
		return hasSetup ? &main->mainSetup.artifactResource[id] : nullptr;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapitemSeaChest::eType H3MapitemSeaChest::GetType()
	{
		return eType(level);
	}
	_H3API_ eArtifact H3MapitemSeaChest::GetArtifact()
	{
		return eArtifact(artifactID);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ WORD H3SeerHut::CreatureCount() const
	{
		return rewardValue2;
	}
	_H3API_ INT8 H3SeerHut::Luck() const
	{
		return INT8(rewardValue);
	}
	_H3API_ INT8 H3SeerHut::Morale() const
	{
		return INT8(rewardValue);
	}
	_H3API_ INT32 H3SeerHut::Primary() const
	{
		return rewardValue;
	}
	_H3API_ INT8 H3SeerHut::PrimaryCount() const
	{
		return INT8(rewardValue2);
	}
	_H3API_ H3SeerHut* H3MapitemSeerHut::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3SeerHut* H3MapitemSeerHut::Get(H3Main* main)
	{
		return &main->mainSetup.seerHuts[id];
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ ePlayer H3MapitemShipyard::GetOwner()
	{
		return ePlayer(owner);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Town* H3MapitemTown::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Town* H3MapitemTown::Get(H3Main* main)
	{
		return &main->towns[id];
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ eArtifact H3MapitemTreasureChest::GetArtifact()
	{
		return eArtifact(artifactID);
	}
	_H3API_ INT32 H3MapitemTreasureChest::GetGold()
	{
		return 500 * bonus;
	}
	_H3API_ INT32 H3MapitemTreasureChest::GetExperience()
	{
		return GetGold() - 500;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemTreeOfKnowledge::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemTreeOfKnowledge::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ H3MapitemTreeOfKnowledge::eType H3MapitemTreeOfKnowledge::GetType()
	{
		return eType(type);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3University* H3MapitemUniversity::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3University* H3MapitemUniversity::Get(H3Main* main)
	{
		return &main->universities[id];
	}
	_H3API_ PINT H3University::begin()
	{
		return &sSkill[0];
	}
	_H3API_ PINT H3University::end()
	{
		return &sSkill[4];
	}
	_H3API_ H3PlayersBitfield H3MapitemUniversity::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemUniversity::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemWagon::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemWagon::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ eArtifact H3MapitemWagon::GetArtifact()
	{
		return eArtifact(artifactID);
	}
	_H3API_ eResource H3MapitemWagon::GetResourceType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemWagon::GetResourceAmount()
	{
		return resValue;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemWarriorsTomb::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ eArtifact H3MapitemWarriorsTomb::GetArtifact()
	{
		return eArtifact(artifactID);
	}
	_H3API_ VOID H3MapitemWarriorsTomb::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemWaterMill::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemWaterMill::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ INT32 H3MapitemWaterMill::GetGold()
	{
		return bonus * 500;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ eResource H3MapitemWindmill::GetType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemWindmill::GetAmount()
	{
		return resValue;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ eSecondary H3MapitemWitchHut::GetSkill()
	{
		return eSecondary(sSkill);
	}
	_H3API_ H3PlayersBitfield H3MapitemWitchHut::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemWitchHut::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3ObjectDraw::H3ObjectDraw(UINT16 sprite, UINT8 tile_id, UINT8 layer) :
		sprite(sprite),
		tileID(tile_id),
		layer(layer)
	{
	}
	_H3API_ H3University* H3MapItem::GetUniversity()
	{
		return STDCALL_1(H3University*, 0x405DA0, this);
	}
	_H3API_ H3MapItem* H3MapItem::GetEntrance()
	{
		return THISCALL_1(H3MapItem*, 0x4FD0F0, this);
	}
	_H3API_ BOOL H3MapItem::IsEntrance() const
	{
		return access & 0x10;
	}
	_H3API_ BOOL H3MapItem::IsBlocked() const
	{
		return access & 0x01;
	}
	_H3API_ BOOL H3MapItem::CanDig() const
	{
		return access & 0x40;
	}
	_H3API_ INT H3MapItem::GetRealType() const
	{
		if (objectType != eObject::HERO)
			return objectType;
		H3Hero* hero = H3Main::Get()->GetHero(setup);
		if (!hero || !hero->objectBelow)
			return objectType;
		return hero->objectTypeUnder;
	}
	_H3API_ UINT H3MapItem::GetRealSetup() const
	{
		if (objectType != eObject::HERO)
			return setup;
		H3Hero* hero = H3Main::Get()->GetHero(setup);
		if (!hero || !hero->objectBelow)
			return setup;
		return hero->objectBelowSetup;
	}
	_H3API_ H3Point H3MapItem::GetCoordinates() const
	{
		H3MainSetup& setup = H3Main::Get()->mainSetup;
		return ReverseCoordinates(this, setup.mapitems, static_cast<UINT32>(setup.mapSize));
	}
}

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3TileVision& H3TileVision::GetTile(INT32 x, INT32 y, INT32 z)
    {
        return FASTCALL_3(H3TileVision&, 0x4F8070, x, y, z);
    }

    _H3API_ H3TileVision& H3TileVision::GetTile(const H3Point& p)
    {
        return GetTile(p.x, p.y, p.z);
    }

    _H3API_ H3TileVision& H3TileVision::GetTile(const H3Position& p)
    {
        return GetTile(p.Unpack());
    }

    _H3API_ BOOL H3TileVision::CanViewTile(INT32 x, INT32 y, INT32 z, INT32 player /*= -1*/)
    {
        if (player < 0)
            player = H3CurrentPlayerID::Get();
        return GetTile(x, y, z).vision.bits & (1 << player);
    }

    _H3API_ BOOL H3TileVision::CanViewTile(const H3Point& p, INT32 player /*= -1*/)
    {
        return CanViewTile(p.x, p.y, p.z, player);
    }

    _H3API_ BOOL H3TileVision::CanViewTile(const H3Position& p, INT32 player /*= -1*/)
    {
        return CanViewTile(p.Unpack(), player);
    }

    _H3API_ VOID H3TileVision::RevealTile(INT32 x, INT32 y, INT32 z, INT32 player /*= -1*/)
    {
        if (player < 0)
            player = H3CurrentPlayerID::Get();
        GetTile(x, y, z).vision.bits |= (1 << player);
    }

    _H3API_ VOID H3TileVision::RevealTile(const H3Point& p, INT32 player /*= -1*/)
    {
        RevealTile(p.x, p.y, p.z, player);
    }

    _H3API_ VOID H3TileVision::RevealTile(const H3Position& p, INT32 player /*= -1*/)
    {
        RevealTile(p.Unpack(), player);
    }

    _H3API_ H3Map<H3TileVision> H3TileVision::GetMap()
    {
        return H3Map<H3TileVision>(Get(), H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
    }

    _H3API_ H3FastMap<H3TileVision> H3TileVision::GetFastMap()
    {
        return H3FastMap<H3TileVision>(Get(), H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3PathNode* H3Pathfinder::GetMovementInfo(UINT32 mixed_position)
	{
        return GetPathNode(mixed_position);
	}
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(UINT32 mixed_position)
    {
        return THISCALL_3(H3PathNode*, 0x42ECC0, this, mixed_position, 0);
    }
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(const H3Position& position)
    {
        return GetPathNode(position.Mixed());
    }
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(const H3Point& pt)
    {
        return GetPathNode(pt.Pack());
    }
	_H3API_ H3Map<H3PathNode> H3Pathfinder::GetMap()
	{
		return H3Map<H3PathNode>(pathNodes, H3MapSize::Get(), H3Main::Get()->HasUnderground());
	}
	_H3API_ H3FastMap<H3PathNode> H3Pathfinder::GetFastMap()
	{
		return H3FastMap<H3PathNode>(pathNodes, H3MapSize::Get(), H3Main::Get()->HasUnderground());
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ UINT8 H3PathNode::GetX() const
	{
		return mixedPosition.GetX();
	}
	_H3API_ UINT8 H3PathNode::GetY() const
	{
		return mixedPosition.GetY();
	}
	_H3API_ UINT8 H3PathNode::GetZ() const
	{
		return mixedPosition.GetZ();
	}
	_H3API_ BOOL H3PathNode::ZoneControlled() const
	{
        return H3TileVision::GetTile(mixedPosition).zoneControl;
	}
	_H3API_ H3MapItem* H3PathNode::GetMapItem() const
	{
		return H3AdventureManager::Get()->GetMapItem(mixedPosition);
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3SimulatedCombat::DeleteCreatures()
	{
		THISCALL_2(VOID, 0x424880, this, 1);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3Artifact::H3Artifact() :
        id(-1), subtype(-1)
    {
    }

    _H3API_ H3Artifact::H3Artifact(eArtifact id) :
        id(id), subtype(-1)
    {
    }

    _H3API_ H3Artifact::H3Artifact(eSpell spell_id) :
        id(eArtifact::SPELL_SCROLL), subtype(spell_id)
    {
    }

    _H3API_ H3Artifact::H3Artifact(INT32 id, INT32 subtype) :
        id(id), subtype(subtype)
    {
    }

    _H3API_ H3Artifact::H3Artifact(const H3Artifact& other) :
        id(other.id), subtype(other.subtype)
    {
    }

    _H3API_ VOID H3Artifact::operator=(const H3Artifact& other)
    {
        id = other.id;
        subtype = other.subtype;
    }

    _H3API_ BOOL H3Artifact::operator==(const H3Artifact& other) const
    {
        return id == other.id && subtype == other.subtype;
    }

    _H3API_ BOOL H3Artifact::operator!=(const H3Artifact& other) const
    {
        return id != other.id || subtype != other.subtype;
    }

    _H3API_ VOID H3Artifact::Clear()
    {
        id = eArtifact::NONE;
        subtype = -1;
    }

    _H3API_ H3Artifact H3Artifact::Remove()
    {
        H3Artifact art(*this);
        Clear();
        return art;
    }

    _H3API_ VOID H3Artifact::Swap(H3Artifact& other)
    {
        std::swap(id, other.id);
        std::swap(subtype, other.subtype);
    }

    _H3API_ LPCSTR H3Artifact::GetName() const
    {
        return GetSetup().name;
    }

    _H3API_ LPCSTR H3Artifact::GetDescription() const
    {
        return GetSetup().description;
    }

    _H3API_ INT32 H3Artifact::GetCost() const
    {
        return GetSetup().cost;
    }

    _H3API_ eArtifact H3Artifact::GetCombinationArtifact() const
    {
        return GetSetup().combinationArtifactId;
    }

    _H3API_ eArtifact H3Artifact::GetId() const
    {
        return eArtifact(id);
    }

    _H3API_ eCombinationArtifacts H3Artifact::GetCombinationArtifactIndex() const
    {
        return GetSetup().comboID;
    }

    _H3API_ eArtifactSlots H3Artifact::GetSlot() const
    {
        return GetSetup().position;
    }

    _H3API_ eArtifactType H3Artifact::GetType() const
    {
        return GetSetup().type;
    }

    _H3API_ const H3ArtifactSetup& H3Artifact::GetSetup() const
    {
        return H3ArtifactSetup::Get()[id];
    }

    _H3API_ eSpell H3Artifact::GetSpell() const
    {
        return GetSetup().newSpell;
    }

    _H3API_ eSpell H3Artifact::ScrollSpell() const
    {
        return eSpell(subtype);
    }
    _H3API_ BOOL H3Artifact::Empty() const
    {
        return id == eArtifact::NONE;
    }
    _H3API_ H3Artifact& H3HeldArtifact::Get()
    {
        return ValueAt<H3Artifact>(0x698AD8);
    }

} /* namespace h3 */

namespace h3
{
	_H3API_ BOOL H3ArtifactSetup::IsPartOfCombo() const
	{
		return combinationArtifactId != eArtifact::NONE;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ BOOL H3ComboArtifactSetup::IsPartOfCombo(eArtifact id) const
    {
        return artifacts.Test(id);
    }
    _H3API_ BOOL H3ComboArtifactSetup::IsPartOfCombo(const H3Artifact& art) const
    {
        return IsPartOfCombo(art.GetId());
    }

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3RGB888::Darken20()
	{
		r = ((r & 0xFE) >> 1) | (r & 0x80);
		g = ((g & 0xFE) >> 1) | (g & 0x80);
		b = ((b & 0xFE) >> 1) | (b & 0x80);
	}
	_H3API_ VOID H3RGB888::Darken50()
	{
		r = ((r & 0xFE) >> 1);
		g = ((g & 0xFE) >> 1);
		b = ((b & 0xFE) >> 1);
	}
	_H3API_ VOID H3RGB888::GrayScale()
	{
		const int c = std::max(r, std::max(g, b));
		int dr = c - r;
		int dg = c - g;
		int db = c - b;

		dr = (dr << 2) / 5;
		dg = (dg << 2) / 5;
		db = (db << 2) / 5;

		r += dr;
		g += dg;
		b += db;
	}
	_H3API_ VOID H3RGB888::Darken(const UINT8 amount)
	{
		H3HSV hsv(*this);
		hsv.RemoveValue(amount);
		*this = hsv.ConvertToRgb888();
	}
	_H3API_ VOID H3RGB888::Lighten(const UINT8 amount)
	{
		H3HSV hsv(*this);
		hsv.AddValue(amount);
		*this = hsv.ConvertToRgb888();
	}
	_H3API_ VOID H3RGB888::AlphaDraw(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha)
	{
		if (alpha == 0)
			return;
		if (alpha == 255)
		{
			r = red;
			g = green;
			b = blue;
			return;
		}
		const int dest_weight = 255 - alpha;

		const int weighted_r = alpha * red + dest_weight * r;
		r = weighted_r / 255;

		const int weighted_g = alpha * green + dest_weight * g;
		g = weighted_g / 255;

		const int weighted_b = alpha * blue + dest_weight * b;
		b = weighted_b / 255;
	}
	_H3API_ FLOAT H3RGB888::GetHueAsNormalizedFloat(UINT8 red, UINT8 green, UINT8 blue)
	{
		int c_min = std::min(std::min(red, green), blue);
		int c_max = std::max(std::max(red, green), blue);
		if (c_min == c_max)
			return 0.0f;
		FLOAT hue;
		if (c_max == red)
			hue = FLOAT(green - blue) / FLOAT(c_max - c_min);
		else if (c_max == green)
			hue = 2.0f + FLOAT(blue - red) / FLOAT(c_max - c_min);
		else
			hue = 4.0f + FLOAT(red - green) / FLOAT(c_max - c_min);

		hue /= 6.0f;

		if (hue < 0.0f)
			hue += 1.0f;

		return hue;
	}
	_H3API_ DWORD H3RGB888::Pack(UINT8 red, UINT8 green, UINT8 blue)
	{
		return 0xFF000000 + blue + (green << 8) + (red << 16);
	}
	_H3API_ H3RGB888::H3RGB888()
	{
	}
	_H3API_ H3RGB888::H3RGB888(DWORD color) :
		r((color >> 16) & 0xFF),
		g((color >> 8) & 0xFF),
		b(color & 0xFF)
	{
	}
	_H3API_ H3RGB888::H3RGB888(UINT8 r, UINT8 g, UINT8 b) :
		r(r),
		g(g),
		b(b)
	{
	}
	_H3API_ H3RGB888::H3RGB888(const H3RGB565& rgb) :
		r(rgb.GetRed8()),
		g(rgb.GetGreen8()),
		b(rgb.GetBlue8())
	{
	}
	_H3API_ H3RGB888::H3RGB888(const H3ARGB888& rgb) :
		r(rgb.r),
		g(rgb.g),
		b(rgb.b)
	{
	}
	_H3API_ VOID H3RGB888::operator=(const H3RGB565& col)
	{
		r = col.GetRed8();
		g = col.GetGreen8();
		b = col.GetBlue8();
	}
	_H3API_ VOID H3RGB888::operator=(const H3RGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
	}
	_H3API_ VOID H3RGB888::operator=(const H3ARGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
	}
	_H3API_ VOID H3RGB888::operator=(const UINT16 col)
	{
		operator=(H3RGB565(col));
	}
	_H3API_ VOID H3RGB888::operator=(const UINT32 col)
	{
		operator=(H3ARGB888(col));
	}
	_H3API_ BOOL H3RGB888::operator==(const H3RGB888& col)
	{
		return b == col.b && g == col.b && r == col.r;
	}
	_H3API_ UINT H3ARGB888::Value() const
	{
		return PtrAt(this);
	}
	_H3API_ H3RGB888 H3RGB888::Regular()
	{
		return H3RGB888(248, 240, 216);
	}
	_H3API_ H3RGB888 H3RGB888::Highlight()
	{
		return H3RGB888(232, 212, 120);
	}
	_H3API_ H3RGB888 H3RGB888::H3Red()
	{
		return H3RGB888(248, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Cyan()
	{
		return H3RGB888(0, 252, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Green()
	{
		return H3RGB888(0, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Blue()
	{
		return H3RGB888(0, 0, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Yellow()
	{
		return H3RGB888(248, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Orange()
	{
		return H3RGB888(248, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Purple()
	{
		return H3RGB888(248, 0, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Pink()
	{
		return H3RGB888(192, 120, 136);
	}
	_H3API_ H3RGB888 H3RGB888::AliceBlue()
	{
		return H3RGB888(240, 248, 255);
	}
	_H3API_ H3RGB888 H3RGB888::AntiqueWhite()
	{
		return H3RGB888(250, 235, 215);
	}
	_H3API_ H3RGB888 H3RGB888::Aqua()
	{
		return H3RGB888(0, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Aquamarine()
	{
		return H3RGB888(127, 255, 212);
	}
	_H3API_ H3RGB888 H3RGB888::Azure()
	{
		return H3RGB888(240, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Beige()
	{
		return H3RGB888(245, 245, 220);
	}
	_H3API_ H3RGB888 H3RGB888::Bisque()
	{
		return H3RGB888(255, 228, 196);
	}
	_H3API_ H3RGB888 H3RGB888::Black()
	{
		return H3RGB888(0, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::BlanchedAlmond()
	{
		return H3RGB888(255, 235, 205);
	}
	_H3API_ H3RGB888 H3RGB888::Blue()
	{
		return H3RGB888(0, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::BlueViolet()
	{
		return H3RGB888(138, 43, 226);
	}
	_H3API_ H3RGB888 H3RGB888::Brown()
	{
		return H3RGB888(165, 42, 42);
	}
	_H3API_ H3RGB888 H3RGB888::BurlyWood()
	{
		return H3RGB888(222, 184, 135);
	}
	_H3API_ H3RGB888 H3RGB888::CadetBlue()
	{
		return H3RGB888(95, 158, 160);
	}
	_H3API_ H3RGB888 H3RGB888::Chartreuse()
	{
		return H3RGB888(127, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::Chocolate()
	{
		return H3RGB888(210, 105, 30);
	}
	_H3API_ H3RGB888 H3RGB888::Coral()
	{
		return H3RGB888(255, 127, 80);
	}
	_H3API_ H3RGB888 H3RGB888::CornflowerBlue()
	{
		return H3RGB888(100, 149, 237);
	}
	_H3API_ H3RGB888 H3RGB888::Cornsilk()
	{
		return H3RGB888(255, 248, 220);
	}
	_H3API_ H3RGB888 H3RGB888::Crimson()
	{
		return H3RGB888(220, 20, 60);
	}
	_H3API_ H3RGB888 H3RGB888::Cyan()
	{
		return H3RGB888(0, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::DarkBlue()
	{
		return H3RGB888(0, 0, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkCyan()
	{
		return H3RGB888(0, 139, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGoldenRod()
	{
		return H3RGB888(184, 134, 11);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGray()
	{
		return H3RGB888(169, 169, 169);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGrey()
	{
		return H3RGB888(169, 169, 169);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGreen()
	{
		return H3RGB888(0, 100, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkKhaki()
	{
		return H3RGB888(189, 183, 107);
	}
	_H3API_ H3RGB888 H3RGB888::DarkMagenta()
	{
		return H3RGB888(139, 0, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkOliveGreen()
	{
		return H3RGB888(85, 107, 47);
	}
	_H3API_ H3RGB888 H3RGB888::Darkorange()
	{
		return H3RGB888(255, 140, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkOrchid()
	{
		return H3RGB888(153, 50, 204);
	}
	_H3API_ H3RGB888 H3RGB888::DarkRed()
	{
		return H3RGB888(139, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSalmon()
	{
		return H3RGB888(233, 150, 122);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSeaGreen()
	{
		return H3RGB888(143, 188, 143);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateBlue()
	{
		return H3RGB888(72, 61, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateGray()
	{
		return H3RGB888(47, 79, 79);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateGrey()
	{
		return H3RGB888(47, 79, 79);
	}
	_H3API_ H3RGB888 H3RGB888::DarkTurquoise()
	{
		return H3RGB888(0, 206, 209);
	}
	_H3API_ H3RGB888 H3RGB888::DarkViolet()
	{
		return H3RGB888(148, 0, 211);
	}
	_H3API_ H3RGB888 H3RGB888::DeepPink()
	{
		return H3RGB888(255, 20, 147);
	}
	_H3API_ H3RGB888 H3RGB888::DeepSkyBlue()
	{
		return H3RGB888(0, 191, 255);
	}
	_H3API_ H3RGB888 H3RGB888::DimGray()
	{
		return H3RGB888(105, 105, 105);
	}
	_H3API_ H3RGB888 H3RGB888::DimGrey()
	{
		return H3RGB888(105, 105, 105);
	}
	_H3API_ H3RGB888 H3RGB888::DodgerBlue()
	{
		return H3RGB888(30, 144, 255);
	}
	_H3API_ H3RGB888 H3RGB888::FireBrick()
	{
		return H3RGB888(178, 34, 34);
	}
	_H3API_ H3RGB888 H3RGB888::FloralWhite()
	{
		return H3RGB888(255, 250, 240);
	}
	_H3API_ H3RGB888 H3RGB888::ForestGreen()
	{
		return H3RGB888(34, 139, 34);
	}
	_H3API_ H3RGB888 H3RGB888::Fuchsia()
	{
		return H3RGB888(255, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Gainsboro()
	{
		return H3RGB888(220, 220, 220);
	}
	_H3API_ H3RGB888 H3RGB888::GhostWhite()
	{
		return H3RGB888(248, 248, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Gold()
	{
		return H3RGB888(255, 215, 0);
	}
	_H3API_ H3RGB888 H3RGB888::GoldenRod()
	{
		return H3RGB888(218, 165, 32);
	}
	_H3API_ H3RGB888 H3RGB888::Gray()
	{
		return H3RGB888(128, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Grey()
	{
		return H3RGB888(128, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Green()
	{
		return H3RGB888(0, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::GreenYellow()
	{
		return H3RGB888(173, 255, 47);
	}
	_H3API_ H3RGB888 H3RGB888::HoneyDew()
	{
		return H3RGB888(240, 255, 240);
	}
	_H3API_ H3RGB888 H3RGB888::HotPink()
	{
		return H3RGB888(255, 105, 180);
	}
	_H3API_ H3RGB888 H3RGB888::IndianRed()
	{
		return H3RGB888(205, 92, 92);
	}
	_H3API_ H3RGB888 H3RGB888::Indigo()
	{
		return H3RGB888(75, 0, 130);
	}
	_H3API_ H3RGB888 H3RGB888::Ivory()
	{
		return H3RGB888(255, 255, 240);
	}
	_H3API_ H3RGB888 H3RGB888::Khaki()
	{
		return H3RGB888(240, 230, 140);
	}
	_H3API_ H3RGB888 H3RGB888::Lavender()
	{
		return H3RGB888(230, 230, 250);
	}
	_H3API_ H3RGB888 H3RGB888::LavenderBlush()
	{
		return H3RGB888(255, 240, 245);
	}
	_H3API_ H3RGB888 H3RGB888::LawnGreen()
	{
		return H3RGB888(124, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::LemonChiffon()
	{
		return H3RGB888(255, 250, 205);
	}
	_H3API_ H3RGB888 H3RGB888::LightBlue()
	{
		return H3RGB888(173, 216, 230);
	}
	_H3API_ H3RGB888 H3RGB888::LightCoral()
	{
		return H3RGB888(240, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::LightCyan()
	{
		return H3RGB888(224, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::LightGoldenRodYellow()
	{
		return H3RGB888(250, 250, 210);
	}
	_H3API_ H3RGB888 H3RGB888::LightGray()
	{
		return H3RGB888(211, 211, 211);
	}
	_H3API_ H3RGB888 H3RGB888::LightGrey()
	{
		return H3RGB888(211, 211, 211);
	}
	_H3API_ H3RGB888 H3RGB888::LightGreen()
	{
		return H3RGB888(144, 238, 144);
	}
	_H3API_ H3RGB888 H3RGB888::LightPink()
	{
		return H3RGB888(255, 182, 193);
	}
	_H3API_ H3RGB888 H3RGB888::LightSalmon()
	{
		return H3RGB888(255, 160, 122);
	}
	_H3API_ H3RGB888 H3RGB888::LightSeaGreen()
	{
		return H3RGB888(32, 178, 170);
	}
	_H3API_ H3RGB888 H3RGB888::LightSkyBlue()
	{
		return H3RGB888(135, 206, 250);
	}
	_H3API_ H3RGB888 H3RGB888::LightSlateGray()
	{
		return H3RGB888(119, 136, 153);
	}
	_H3API_ H3RGB888 H3RGB888::LightSlateGrey()
	{
		return H3RGB888(119, 136, 153);
	}
	_H3API_ H3RGB888 H3RGB888::LightSteelBlue()
	{
		return H3RGB888(176, 196, 222);
	}
	_H3API_ H3RGB888 H3RGB888::LightYellow()
	{
		return H3RGB888(255, 255, 224);
	}
	_H3API_ H3RGB888 H3RGB888::Lime()
	{
		return H3RGB888(0, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::LimeGreen()
	{
		return H3RGB888(50, 205, 50);
	}
	_H3API_ H3RGB888 H3RGB888::Linen()
	{
		return H3RGB888(250, 240, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Magenta()
	{
		return H3RGB888(255, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Maroon()
	{
		return H3RGB888(128, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::MediumAquaMarine()
	{
		return H3RGB888(102, 205, 170);
	}
	_H3API_ H3RGB888 H3RGB888::MediumBlue()
	{
		return H3RGB888(0, 0, 205);
	}
	_H3API_ H3RGB888 H3RGB888::MediumOrchid()
	{
		return H3RGB888(186, 85, 211);
	}
	_H3API_ H3RGB888 H3RGB888::MediumPurple()
	{
		return H3RGB888(147, 112, 216);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSeaGreen()
	{
		return H3RGB888(60, 179, 113);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSlateBlue()
	{
		return H3RGB888(123, 104, 238);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSpringGreen()
	{
		return H3RGB888(0, 250, 154);
	}
	_H3API_ H3RGB888 H3RGB888::MediumTurquoise()
	{
		return H3RGB888(72, 209, 204);
	}
	_H3API_ H3RGB888 H3RGB888::MediumVioletRed()
	{
		return H3RGB888(199, 21, 133);
	}
	_H3API_ H3RGB888 H3RGB888::MidnightBlue()
	{
		return H3RGB888(25, 25, 112);
	}
	_H3API_ H3RGB888 H3RGB888::MintCream()
	{
		return H3RGB888(245, 255, 250);
	}
	_H3API_ H3RGB888 H3RGB888::MistyRose()
	{
		return H3RGB888(255, 228, 225);
	}
	_H3API_ H3RGB888 H3RGB888::Moccasin()
	{
		return H3RGB888(255, 228, 181);
	}
	_H3API_ H3RGB888 H3RGB888::NavajoWhite()
	{
		return H3RGB888(255, 222, 173);
	}
	_H3API_ H3RGB888 H3RGB888::Navy()
	{
		return H3RGB888(0, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::OldLace()
	{
		return H3RGB888(253, 245, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Olive()
	{
		return H3RGB888(128, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::OliveDrab()
	{
		return H3RGB888(107, 142, 35);
	}
	_H3API_ H3RGB888 H3RGB888::Orange()
	{
		return H3RGB888(255, 165, 0);
	}
	_H3API_ H3RGB888 H3RGB888::OrangeRed()
	{
		return H3RGB888(255, 69, 0);
	}
	_H3API_ H3RGB888 H3RGB888::Orchid()
	{
		return H3RGB888(218, 112, 214);
	}
	_H3API_ H3RGB888 H3RGB888::PaleGoldenRod()
	{
		return H3RGB888(238, 232, 170);
	}
	_H3API_ H3RGB888 H3RGB888::PaleGreen()
	{
		return H3RGB888(152, 251, 152);
	}
	_H3API_ H3RGB888 H3RGB888::PaleTurquoise()
	{
		return H3RGB888(175, 238, 238);
	}
	_H3API_ H3RGB888 H3RGB888::PaleVioletRed()
	{
		return H3RGB888(216, 112, 147);
	}
	_H3API_ H3RGB888 H3RGB888::PapayaWhip()
	{
		return H3RGB888(255, 239, 213);
	}
	_H3API_ H3RGB888 H3RGB888::PeachPuff()
	{
		return H3RGB888(255, 218, 185);
	}
	_H3API_ H3RGB888 H3RGB888::Peru()
	{
		return H3RGB888(205, 133, 63);
	}
	_H3API_ H3RGB888 H3RGB888::Pink()
	{
		return H3RGB888(255, 192, 203);
	}
	_H3API_ H3RGB888 H3RGB888::Plum()
	{
		return H3RGB888(221, 160, 221);
	}
	_H3API_ H3RGB888 H3RGB888::PowderBlue()
	{
		return H3RGB888(176, 224, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Purple()
	{
		return H3RGB888(128, 0, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Red()
	{
		return H3RGB888(255, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::RosyBrown()
	{
		return H3RGB888(188, 143, 143);
	}
	_H3API_ H3RGB888 H3RGB888::RoyalBlue()
	{
		return H3RGB888(65, 105, 225);
	}
	_H3API_ H3RGB888 H3RGB888::SaddleBrown()
	{
		return H3RGB888(139, 69, 19);
	}
	_H3API_ H3RGB888 H3RGB888::Salmon()
	{
		return H3RGB888(250, 128, 114);
	}
	_H3API_ H3RGB888 H3RGB888::SandyBrown()
	{
		return H3RGB888(244, 164, 96);
	}
	_H3API_ H3RGB888 H3RGB888::SeaGreen()
	{
		return H3RGB888(46, 139, 87);
	}
	_H3API_ H3RGB888 H3RGB888::SeaShell()
	{
		return H3RGB888(255, 245, 238);
	}
	_H3API_ H3RGB888 H3RGB888::Sienna()
	{
		return H3RGB888(160, 82, 45);
	}
	_H3API_ H3RGB888 H3RGB888::Silver()
	{
		return H3RGB888(192, 192, 192);
	}
	_H3API_ H3RGB888 H3RGB888::SkyBlue()
	{
		return H3RGB888(135, 206, 235);
	}
	_H3API_ H3RGB888 H3RGB888::SlateBlue()
	{
		return H3RGB888(106, 90, 205);
	}
	_H3API_ H3RGB888 H3RGB888::SlateGray()
	{
		return H3RGB888(112, 128, 144);
	}
	_H3API_ H3RGB888 H3RGB888::SlateGrey()
	{
		return H3RGB888(112, 128, 144);
	}
	_H3API_ H3RGB888 H3RGB888::Snow()
	{
		return H3RGB888(255, 250, 250);
	}
	_H3API_ H3RGB888 H3RGB888::SpringGreen()
	{
		return H3RGB888(0, 255, 127);
	}
	_H3API_ H3RGB888 H3RGB888::SteelBlue()
	{
		return H3RGB888(70, 130, 180);
	}
	_H3API_ H3RGB888 H3RGB888::Tan()
	{
		return H3RGB888(210, 180, 140);
	}
	_H3API_ H3RGB888 H3RGB888::Teal()
	{
		return H3RGB888(0, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Thistle()
	{
		return H3RGB888(216, 191, 216);
	}
	_H3API_ H3RGB888 H3RGB888::Tomato()
	{
		return H3RGB888(255, 99, 71);
	}
	_H3API_ H3RGB888 H3RGB888::Turquoise()
	{
		return H3RGB888(64, 224, 208);
	}
	_H3API_ H3RGB888 H3RGB888::Violet()
	{
		return H3RGB888(238, 130, 238);
	}
	_H3API_ H3RGB888 H3RGB888::Wheat()
	{
		return H3RGB888(245, 222, 179);
	}
	_H3API_ H3RGB888 H3RGB888::White()
	{
		return H3RGB888(255, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::WhiteSmoke()
	{
		return H3RGB888(245, 245, 245);
	}
	_H3API_ H3RGB888 H3RGB888::Yellow()
	{
		return H3RGB888(255, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::YellowGreen()
	{
		return H3RGB888(154, 205, 50);
	}

	_H3API_ H3ARGB888 H3ARGB888::Regular()
	{
		return H3ARGB888(248, 240, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::Highlight()
	{
		return H3ARGB888(232, 212, 120);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Red()
	{
		return H3ARGB888(248, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Cyan()
	{
		return H3ARGB888(0, 252, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Green()
	{
		return H3ARGB888(0, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Blue()
	{
		return H3ARGB888(0, 0, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Yellow()
	{
		return H3ARGB888(248, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Orange()
	{
		return H3ARGB888(248, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Purple()
	{
		return H3ARGB888(248, 0, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Pink()
	{
		return H3ARGB888(192, 120, 136);
	}
	_H3API_ H3ARGB888 H3ARGB888::AliceBlue()
	{
		return H3ARGB888(240, 248, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::AntiqueWhite()
	{
		return H3ARGB888(250, 235, 215);
	}
	_H3API_ H3ARGB888 H3ARGB888::Aqua()
	{
		return H3ARGB888(0, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Aquamarine()
	{
		return H3ARGB888(127, 255, 212);
	}
	_H3API_ H3ARGB888 H3ARGB888::Azure()
	{
		return H3ARGB888(240, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Beige()
	{
		return H3ARGB888(245, 245, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::Bisque()
	{
		return H3ARGB888(255, 228, 196);
	}
	_H3API_ H3ARGB888 H3ARGB888::Black()
	{
		return H3ARGB888(0, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::BlanchedAlmond()
	{
		return H3ARGB888(255, 235, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::Blue()
	{
		return H3ARGB888(0, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::BlueViolet()
	{
		return H3ARGB888(138, 43, 226);
	}
	_H3API_ H3ARGB888 H3ARGB888::Brown()
	{
		return H3ARGB888(165, 42, 42);
	}
	_H3API_ H3ARGB888 H3ARGB888::BurlyWood()
	{
		return H3ARGB888(222, 184, 135);
	}
	_H3API_ H3ARGB888 H3ARGB888::CadetBlue()
	{
		return H3ARGB888(95, 158, 160);
	}
	_H3API_ H3ARGB888 H3ARGB888::Chartreuse()
	{
		return H3ARGB888(127, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::Chocolate()
	{
		return H3ARGB888(210, 105, 30);
	}
	_H3API_ H3ARGB888 H3ARGB888::Coral()
	{
		return H3ARGB888(255, 127, 80);
	}
	_H3API_ H3ARGB888 H3ARGB888::CornflowerBlue()
	{
		return H3ARGB888(100, 149, 237);
	}
	_H3API_ H3ARGB888 H3ARGB888::Cornsilk()
	{
		return H3ARGB888(255, 248, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::Crimson()
	{
		return H3ARGB888(220, 20, 60);
	}
	_H3API_ H3ARGB888 H3ARGB888::Cyan()
	{
		return H3ARGB888(0, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkBlue()
	{
		return H3ARGB888(0, 0, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkCyan()
	{
		return H3ARGB888(0, 139, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGoldenRod()
	{
		return H3ARGB888(184, 134, 11);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGray()
	{
		return H3ARGB888(169, 169, 169);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGrey()
	{
		return H3ARGB888(169, 169, 169);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGreen()
	{
		return H3ARGB888(0, 100, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkKhaki()
	{
		return H3ARGB888(189, 183, 107);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkMagenta()
	{
		return H3ARGB888(139, 0, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkOliveGreen()
	{
		return H3ARGB888(85, 107, 47);
	}
	_H3API_ H3ARGB888 H3ARGB888::Darkorange()
	{
		return H3ARGB888(255, 140, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkOrchid()
	{
		return H3ARGB888(153, 50, 204);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkRed()
	{
		return H3ARGB888(139, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSalmon()
	{
		return H3ARGB888(233, 150, 122);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSeaGreen()
	{
		return H3ARGB888(143, 188, 143);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateBlue()
	{
		return H3ARGB888(72, 61, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateGray()
	{
		return H3ARGB888(47, 79, 79);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateGrey()
	{
		return H3ARGB888(47, 79, 79);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkTurquoise()
	{
		return H3ARGB888(0, 206, 209);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkViolet()
	{
		return H3ARGB888(148, 0, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::DeepPink()
	{
		return H3ARGB888(255, 20, 147);
	}
	_H3API_ H3ARGB888 H3ARGB888::DeepSkyBlue()
	{
		return H3ARGB888(0, 191, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::DimGray()
	{
		return H3ARGB888(105, 105, 105);
	}
	_H3API_ H3ARGB888 H3ARGB888::DimGrey()
	{
		return H3ARGB888(105, 105, 105);
	}
	_H3API_ H3ARGB888 H3ARGB888::DodgerBlue()
	{
		return H3ARGB888(30, 144, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::FireBrick()
	{
		return H3ARGB888(178, 34, 34);
	}
	_H3API_ H3ARGB888 H3ARGB888::FloralWhite()
	{
		return H3ARGB888(255, 250, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::ForestGreen()
	{
		return H3ARGB888(34, 139, 34);
	}
	_H3API_ H3ARGB888 H3ARGB888::Fuchsia()
	{
		return H3ARGB888(255, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gainsboro()
	{
		return H3ARGB888(220, 220, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::GhostWhite()
	{
		return H3ARGB888(248, 248, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gold()
	{
		return H3ARGB888(255, 215, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::GoldenRod()
	{
		return H3ARGB888(218, 165, 32);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gray()
	{
		return H3ARGB888(128, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Grey()
	{
		return H3ARGB888(128, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Green()
	{
		return H3ARGB888(0, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::GreenYellow()
	{
		return H3ARGB888(173, 255, 47);
	}
	_H3API_ H3ARGB888 H3ARGB888::HoneyDew()
	{
		return H3ARGB888(240, 255, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::HotPink()
	{
		return H3ARGB888(255, 105, 180);
	}
	_H3API_ H3ARGB888 H3ARGB888::IndianRed()
	{
		return H3ARGB888(205, 92, 92);
	}
	_H3API_ H3ARGB888 H3ARGB888::Indigo()
	{
		return H3ARGB888(75, 0, 130);
	}
	_H3API_ H3ARGB888 H3ARGB888::Ivory()
	{
		return H3ARGB888(255, 255, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::Khaki()
	{
		return H3ARGB888(240, 230, 140);
	}
	_H3API_ H3ARGB888 H3ARGB888::Lavender()
	{
		return H3ARGB888(230, 230, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::LavenderBlush()
	{
		return H3ARGB888(255, 240, 245);
	}
	_H3API_ H3ARGB888 H3ARGB888::LawnGreen()
	{
		return H3ARGB888(124, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::LemonChiffon()
	{
		return H3ARGB888(255, 250, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightBlue()
	{
		return H3ARGB888(173, 216, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightCoral()
	{
		return H3ARGB888(240, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightCyan()
	{
		return H3ARGB888(224, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGoldenRodYellow()
	{
		return H3ARGB888(250, 250, 210);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGray()
	{
		return H3ARGB888(211, 211, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGrey()
	{
		return H3ARGB888(211, 211, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGreen()
	{
		return H3ARGB888(144, 238, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightPink()
	{
		return H3ARGB888(255, 182, 193);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSalmon()
	{
		return H3ARGB888(255, 160, 122);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSeaGreen()
	{
		return H3ARGB888(32, 178, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSkyBlue()
	{
		return H3ARGB888(135, 206, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSlateGray()
	{
		return H3ARGB888(119, 136, 153);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSlateGrey()
	{
		return H3ARGB888(119, 136, 153);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSteelBlue()
	{
		return H3ARGB888(176, 196, 222);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightYellow()
	{
		return H3ARGB888(255, 255, 224);
	}
	_H3API_ H3ARGB888 H3ARGB888::Lime()
	{
		return H3ARGB888(0, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::LimeGreen()
	{
		return H3ARGB888(50, 205, 50);
	}
	_H3API_ H3ARGB888 H3ARGB888::Linen()
	{
		return H3ARGB888(250, 240, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Magenta()
	{
		return H3ARGB888(255, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Maroon()
	{
		return H3ARGB888(128, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumAquaMarine()
	{
		return H3ARGB888(102, 205, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumBlue()
	{
		return H3ARGB888(0, 0, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumOrchid()
	{
		return H3ARGB888(186, 85, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumPurple()
	{
		return H3ARGB888(147, 112, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSeaGreen()
	{
		return H3ARGB888(60, 179, 113);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSlateBlue()
	{
		return H3ARGB888(123, 104, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSpringGreen()
	{
		return H3ARGB888(0, 250, 154);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumTurquoise()
	{
		return H3ARGB888(72, 209, 204);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumVioletRed()
	{
		return H3ARGB888(199, 21, 133);
	}
	_H3API_ H3ARGB888 H3ARGB888::MidnightBlue()
	{
		return H3ARGB888(25, 25, 112);
	}
	_H3API_ H3ARGB888 H3ARGB888::MintCream()
	{
		return H3ARGB888(245, 255, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::MistyRose()
	{
		return H3ARGB888(255, 228, 225);
	}
	_H3API_ H3ARGB888 H3ARGB888::Moccasin()
	{
		return H3ARGB888(255, 228, 181);
	}
	_H3API_ H3ARGB888 H3ARGB888::NavajoWhite()
	{
		return H3ARGB888(255, 222, 173);
	}
	_H3API_ H3ARGB888 H3ARGB888::Navy()
	{
		return H3ARGB888(0, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::OldLace()
	{
		return H3ARGB888(253, 245, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Olive()
	{
		return H3ARGB888(128, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::OliveDrab()
	{
		return H3ARGB888(107, 142, 35);
	}
	_H3API_ H3ARGB888 H3ARGB888::Orange()
	{
		return H3ARGB888(255, 165, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::OrangeRed()
	{
		return H3ARGB888(255, 69, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::Orchid()
	{
		return H3ARGB888(218, 112, 214);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleGoldenRod()
	{
		return H3ARGB888(238, 232, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleGreen()
	{
		return H3ARGB888(152, 251, 152);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleTurquoise()
	{
		return H3ARGB888(175, 238, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleVioletRed()
	{
		return H3ARGB888(216, 112, 147);
	}
	_H3API_ H3ARGB888 H3ARGB888::PapayaWhip()
	{
		return H3ARGB888(255, 239, 213);
	}
	_H3API_ H3ARGB888 H3ARGB888::PeachPuff()
	{
		return H3ARGB888(255, 218, 185);
	}
	_H3API_ H3ARGB888 H3ARGB888::Peru()
	{
		return H3ARGB888(205, 133, 63);
	}
	_H3API_ H3ARGB888 H3ARGB888::Pink()
	{
		return H3ARGB888(255, 192, 203);
	}
	_H3API_ H3ARGB888 H3ARGB888::Plum()
	{
		return H3ARGB888(221, 160, 221);
	}
	_H3API_ H3ARGB888 H3ARGB888::PowderBlue()
	{
		return H3ARGB888(176, 224, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Purple()
	{
		return H3ARGB888(128, 0, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Red()
	{
		return H3ARGB888(255, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::RosyBrown()
	{
		return H3ARGB888(188, 143, 143);
	}
	_H3API_ H3ARGB888 H3ARGB888::RoyalBlue()
	{
		return H3ARGB888(65, 105, 225);
	}
	_H3API_ H3ARGB888 H3ARGB888::SaddleBrown()
	{
		return H3ARGB888(139, 69, 19);
	}
	_H3API_ H3ARGB888 H3ARGB888::Salmon()
	{
		return H3ARGB888(250, 128, 114);
	}
	_H3API_ H3ARGB888 H3ARGB888::SandyBrown()
	{
		return H3ARGB888(244, 164, 96);
	}
	_H3API_ H3ARGB888 H3ARGB888::SeaGreen()
	{
		return H3ARGB888(46, 139, 87);
	}
	_H3API_ H3ARGB888 H3ARGB888::SeaShell()
	{
		return H3ARGB888(255, 245, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::Sienna()
	{
		return H3ARGB888(160, 82, 45);
	}
	_H3API_ H3ARGB888 H3ARGB888::Silver()
	{
		return H3ARGB888(192, 192, 192);
	}
	_H3API_ H3ARGB888 H3ARGB888::SkyBlue()
	{
		return H3ARGB888(135, 206, 235);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateBlue()
	{
		return H3ARGB888(106, 90, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateGray()
	{
		return H3ARGB888(112, 128, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateGrey()
	{
		return H3ARGB888(112, 128, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::Snow()
	{
		return H3ARGB888(255, 250, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::SpringGreen()
	{
		return H3ARGB888(0, 255, 127);
	}
	_H3API_ H3ARGB888 H3ARGB888::SteelBlue()
	{
		return H3ARGB888(70, 130, 180);
	}
	_H3API_ H3ARGB888 H3ARGB888::Tan()
	{
		return H3ARGB888(210, 180, 140);
	}
	_H3API_ H3ARGB888 H3ARGB888::Teal()
	{
		return H3ARGB888(0, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Thistle()
	{
		return H3ARGB888(216, 191, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::Tomato()
	{
		return H3ARGB888(255, 99, 71);
	}
	_H3API_ H3ARGB888 H3ARGB888::Turquoise()
	{
		return H3ARGB888(64, 224, 208);
	}
	_H3API_ H3ARGB888 H3ARGB888::Violet()
	{
		return H3ARGB888(238, 130, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::Wheat()
	{
		return H3ARGB888(245, 222, 179);
	}
	_H3API_ H3ARGB888 H3ARGB888::White()
	{
		return H3ARGB888(255, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::WhiteSmoke()
	{
		return H3ARGB888(245, 245, 245);
	}
	_H3API_ H3ARGB888 H3ARGB888::Yellow()
	{
		return H3ARGB888(255, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::YellowGreen()
	{
		return H3ARGB888(154, 205, 50);
	}

	_H3API_ RGB565 H3RGB565::Regular()
	{
		return 0xFF9B;
	}
	_H3API_ RGB565 H3RGB565::Highlight()
	{
		return 0xEEAF;
	}
	_H3API_ RGB565 H3RGB565::H3Red()
	{
		return 0xF800;
	}
	_H3API_ RGB565 H3RGB565::H3Cyan()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::H3Green()
	{
		return 0x7E0;
	}
	_H3API_ RGB565 H3RGB565::H3Blue()
	{
		return 0x1F;
	}
	_H3API_ RGB565 H3RGB565::H3Yellow()
	{
		return 0xFFE0;
	}
	_H3API_ RGB565 H3RGB565::H3Orange()
	{
		return 0xFC00;
	}
	_H3API_ RGB565 H3RGB565::H3Purple()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::H3Pink()
	{
		return 0xC3D1;
	}
	_H3API_ RGB565 H3RGB565::AliceBlue()
	{
		return 0xF7DF;
	}
	_H3API_ RGB565 H3RGB565::AntiqueWhite()
	{
		return 0xFF5A;
	}
	_H3API_ RGB565 H3RGB565::Aqua()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::Aquamarine()
	{
		return 0x7FFA;
	}
	_H3API_ RGB565 H3RGB565::Azure()
	{
		return 0xF7FF;
	}
	_H3API_ RGB565 H3RGB565::Beige()
	{
		return 0xF7BB;
	}
	_H3API_ RGB565 H3RGB565::Bisque()
	{
		return 0xFF38;
	}
	_H3API_ RGB565 H3RGB565::Black()
	{
		return 0x0;
	}
	_H3API_ RGB565 H3RGB565::BlanchedAlmond()
	{
		return 0xFF59;
	}
	_H3API_ RGB565 H3RGB565::Blue()
	{
		return 0x1F;
	}
	_H3API_ RGB565 H3RGB565::BlueViolet()
	{
		return 0x895C;
	}
	_H3API_ RGB565 H3RGB565::Brown()
	{
		return 0xA145;
	}
	_H3API_ RGB565 H3RGB565::BurlyWood()
	{
		return 0xDDD0;
	}
	_H3API_ RGB565 H3RGB565::CadetBlue()
	{
		return 0x5CF4;
	}
	_H3API_ RGB565 H3RGB565::Chartreuse()
	{
		return 0x7FE0;
	}
	_H3API_ RGB565 H3RGB565::Chocolate()
	{
		return 0xD343;
	}
	_H3API_ RGB565 H3RGB565::Coral()
	{
		return 0xFBEA;
	}
	_H3API_ RGB565 H3RGB565::CornflowerBlue()
	{
		return 0x64BD;
	}
	_H3API_ RGB565 H3RGB565::Cornsilk()
	{
		return 0xFFDB;
	}
	_H3API_ RGB565 H3RGB565::Crimson()
	{
		return 0xD8A7;
	}
	_H3API_ RGB565 H3RGB565::Cyan()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::DarkBlue()
	{
		return 0x11;
	}
	_H3API_ RGB565 H3RGB565::DarkCyan()
	{
		return 0x451;
	}
	_H3API_ RGB565 H3RGB565::DarkGoldenRod()
	{
		return 0xBC21;
	}
	_H3API_ RGB565 H3RGB565::DarkGray()
	{
		return 0xAD55;
	}
	_H3API_ RGB565 H3RGB565::DarkGrey()
	{
		return 0xAD55;
	}
	_H3API_ RGB565 H3RGB565::DarkGreen()
	{
		return 0x320;
	}
	_H3API_ RGB565 H3RGB565::DarkKhaki()
	{
		return 0xBDAD;
	}
	_H3API_ RGB565 H3RGB565::DarkMagenta()
	{
		return 0x8811;
	}
	_H3API_ RGB565 H3RGB565::DarkOliveGreen()
	{
		return 0x5345;
	}
	_H3API_ RGB565 H3RGB565::Darkorange()
	{
		return 0xFC60;
	}
	_H3API_ RGB565 H3RGB565::DarkOrchid()
	{
		return 0x9999;
	}
	_H3API_ RGB565 H3RGB565::DarkRed()
	{
		return 0x8800;
	}
	_H3API_ RGB565 H3RGB565::DarkSalmon()
	{
		return 0xECAF;
	}
	_H3API_ RGB565 H3RGB565::DarkSeaGreen()
	{
		return 0x8DF1;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateBlue()
	{
		return 0x49F1;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateGray()
	{
		return 0x2A69;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateGrey()
	{
		return 0x2A69;
	}
	_H3API_ RGB565 H3RGB565::DarkTurquoise()
	{
		return 0x67A;
	}
	_H3API_ RGB565 H3RGB565::DarkViolet()
	{
		return 0x901A;
	}
	_H3API_ RGB565 H3RGB565::DeepPink()
	{
		return 0xF8B2;
	}
	_H3API_ RGB565 H3RGB565::DeepSkyBlue()
	{
		return 0x5FF;
	}
	_H3API_ RGB565 H3RGB565::DimGray()
	{
		return 0x6B4D;
	}
	_H3API_ RGB565 H3RGB565::DimGrey()
	{
		return 0x6B4D;
	}
	_H3API_ RGB565 H3RGB565::DodgerBlue()
	{
		return 0x1C9F;
	}
	_H3API_ RGB565 H3RGB565::FireBrick()
	{
		return 0xB104;
	}
	_H3API_ RGB565 H3RGB565::FloralWhite()
	{
		return 0xFFDE;
	}
	_H3API_ RGB565 H3RGB565::ForestGreen()
	{
		return 0x2444;
	}
	_H3API_ RGB565 H3RGB565::Fuchsia()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::Gainsboro()
	{
		return 0xDEFB;
	}
	_H3API_ RGB565 H3RGB565::GhostWhite()
	{
		return 0xFFDF;
	}
	_H3API_ RGB565 H3RGB565::Gold()
	{
		return 0xFEA0;
	}
	_H3API_ RGB565 H3RGB565::GoldenRod()
	{
		return 0xDD24;
	}
	_H3API_ RGB565 H3RGB565::Gray()
	{
		return 0x8410;
	}
	_H3API_ RGB565 H3RGB565::Grey()
	{
		return 0x8410;
	}
	_H3API_ RGB565 H3RGB565::Green()
	{
		return 0x400;
	}
	_H3API_ RGB565 H3RGB565::GreenYellow()
	{
		return 0xAFE5;
	}
	_H3API_ RGB565 H3RGB565::HoneyDew()
	{
		return 0xF7FE;
	}
	_H3API_ RGB565 H3RGB565::HotPink()
	{
		return 0xFB56;
	}
	_H3API_ RGB565 H3RGB565::IndianRed()
	{
		return 0xCAEB;
	}
	_H3API_ RGB565 H3RGB565::Indigo()
	{
		return 0x4810;
	}
	_H3API_ RGB565 H3RGB565::Ivory()
	{
		return 0xFFFE;
	}
	_H3API_ RGB565 H3RGB565::Khaki()
	{
		return 0xF731;
	}
	_H3API_ RGB565 H3RGB565::Lavender()
	{
		return 0xE73F;
	}
	_H3API_ RGB565 H3RGB565::LavenderBlush()
	{
		return 0xFF9E;
	}
	_H3API_ RGB565 H3RGB565::LawnGreen()
	{
		return 0x7FE0;
	}
	_H3API_ RGB565 H3RGB565::LemonChiffon()
	{
		return 0xFFD9;
	}
	_H3API_ RGB565 H3RGB565::LightBlue()
	{
		return 0xAEDC;
	}
	_H3API_ RGB565 H3RGB565::LightCoral()
	{
		return 0xF410;
	}
	_H3API_ RGB565 H3RGB565::LightCyan()
	{
		return 0xE7FF;
	}
	_H3API_ RGB565 H3RGB565::LightGoldenRodYellow()
	{
		return 0xFFDA;
	}
	_H3API_ RGB565 H3RGB565::LightGray()
	{
		return 0xD69A;
	}
	_H3API_ RGB565 H3RGB565::LightGrey()
	{
		return 0xD69A;
	}
	_H3API_ RGB565 H3RGB565::LightGreen()
	{
		return 0x9772;
	}
	_H3API_ RGB565 H3RGB565::LightPink()
	{
		return 0xFDB8;
	}
	_H3API_ RGB565 H3RGB565::LightSalmon()
	{
		return 0xFD0F;
	}
	_H3API_ RGB565 H3RGB565::LightSeaGreen()
	{
		return 0x2595;
	}
	_H3API_ RGB565 H3RGB565::LightSkyBlue()
	{
		return 0x867F;
	}
	_H3API_ RGB565 H3RGB565::LightSlateGray()
	{
		return 0x7453;
	}
	_H3API_ RGB565 H3RGB565::LightSlateGrey()
	{
		return 0x7453;
	}
	_H3API_ RGB565 H3RGB565::LightSteelBlue()
	{
		return 0xB63B;
	}
	_H3API_ RGB565 H3RGB565::LightYellow()
	{
		return 0xFFFC;
	}
	_H3API_ RGB565 H3RGB565::Lime()
	{
		return 0x7E0;
	}
	_H3API_ RGB565 H3RGB565::LimeGreen()
	{
		return 0x3666;
	}
	_H3API_ RGB565 H3RGB565::Linen()
	{
		return 0xFF9C;
	}
	_H3API_ RGB565 H3RGB565::Magenta()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::Maroon()
	{
		return 0x8000;
	}
	_H3API_ RGB565 H3RGB565::MediumAquaMarine()
	{
		return 0x6675;
	}
	_H3API_ RGB565 H3RGB565::MediumBlue()
	{
		return 0x19;
	}
	_H3API_ RGB565 H3RGB565::MediumOrchid()
	{
		return 0xBABA;
	}
	_H3API_ RGB565 H3RGB565::MediumPurple()
	{
		return 0x939B;
	}
	_H3API_ RGB565 H3RGB565::MediumSeaGreen()
	{
		return 0x3D8E;
	}
	_H3API_ RGB565 H3RGB565::MediumSlateBlue()
	{
		return 0x7B5D;
	}
	_H3API_ RGB565 H3RGB565::MediumSpringGreen()
	{
		return 0x7D3;
	}
	_H3API_ RGB565 H3RGB565::MediumTurquoise()
	{
		return 0x4E99;
	}
	_H3API_ RGB565 H3RGB565::MediumVioletRed()
	{
		return 0xC0B0;
	}
	_H3API_ RGB565 H3RGB565::MidnightBlue()
	{
		return 0x18CE;
	}
	_H3API_ RGB565 H3RGB565::MintCream()
	{
		return 0xF7FF;
	}
	_H3API_ RGB565 H3RGB565::MistyRose()
	{
		return 0xFF3C;
	}
	_H3API_ RGB565 H3RGB565::Moccasin()
	{
		return 0xFF36;
	}
	_H3API_ RGB565 H3RGB565::NavajoWhite()
	{
		return 0xFEF5;
	}
	_H3API_ RGB565 H3RGB565::Navy()
	{
		return 0x410;
	}
	_H3API_ RGB565 H3RGB565::OldLace()
	{
		return 0xFFBC;
	}
	_H3API_ RGB565 H3RGB565::Olive()
	{
		return 0x8400;
	}
	_H3API_ RGB565 H3RGB565::OliveDrab()
	{
		return 0x6C64;
	}
	_H3API_ RGB565 H3RGB565::Orange()
	{
		return 0xFD20;
	}
	_H3API_ RGB565 H3RGB565::OrangeRed()
	{
		return 0xFA20;
	}
	_H3API_ RGB565 H3RGB565::Orchid()
	{
		return 0xDB9A;
	}
	_H3API_ RGB565 H3RGB565::PaleGoldenRod()
	{
		return 0xEF55;
	}
	_H3API_ RGB565 H3RGB565::PaleGreen()
	{
		return 0x9FD3;
	}
	_H3API_ RGB565 H3RGB565::PaleTurquoise()
	{
		return 0xAF7D;
	}
	_H3API_ RGB565 H3RGB565::PaleVioletRed()
	{
		return 0xDB92;
	}
	_H3API_ RGB565 H3RGB565::PapayaWhip()
	{
		return 0xFF7A;
	}
	_H3API_ RGB565 H3RGB565::PeachPuff()
	{
		return 0xFED7;
	}
	_H3API_ RGB565 H3RGB565::Peru()
	{
		return 0xCC27;
	}
	_H3API_ RGB565 H3RGB565::Pink()
	{
		return 0xFE19;
	}
	_H3API_ RGB565 H3RGB565::Plum()
	{
		return 0xDD1B;
	}
	_H3API_ RGB565 H3RGB565::PowderBlue()
	{
		return 0xB71C;
	}
	_H3API_ RGB565 H3RGB565::Purple()
	{
		return 0x8010;
	}
	_H3API_ RGB565 H3RGB565::Red()
	{
		return 0xF800;
	}
	_H3API_ RGB565 H3RGB565::RosyBrown()
	{
		return 0xBC71;
	}
	_H3API_ RGB565 H3RGB565::RoyalBlue()
	{
		return 0x435C;
	}
	_H3API_ RGB565 H3RGB565::SaddleBrown()
	{
		return 0x8A22;
	}
	_H3API_ RGB565 H3RGB565::Salmon()
	{
		return 0xFC0E;
	}
	_H3API_ RGB565 H3RGB565::SandyBrown()
	{
		return 0xF52C;
	}
	_H3API_ RGB565 H3RGB565::SeaGreen()
	{
		return 0x2C4A;
	}
	_H3API_ RGB565 H3RGB565::SeaShell()
	{
		return 0xFFBD;
	}
	_H3API_ RGB565 H3RGB565::Sienna()
	{
		return 0xA285;
	}
	_H3API_ RGB565 H3RGB565::Silver()
	{
		return 0xC618;
	}
	_H3API_ RGB565 H3RGB565::SkyBlue()
	{
		return 0x867D;
	}
	_H3API_ RGB565 H3RGB565::SlateBlue()
	{
		return 0x6AD9;
	}
	_H3API_ RGB565 H3RGB565::SlateGray()
	{
		return 0x7412;
	}
	_H3API_ RGB565 H3RGB565::SlateGrey()
	{
		return 0x7412;
	}
	_H3API_ RGB565 H3RGB565::Snow()
	{
		return 0xFFDF;
	}
	_H3API_ RGB565 H3RGB565::SpringGreen()
	{
		return 0x7EF;
	}
	_H3API_ RGB565 H3RGB565::SteelBlue()
	{
		return 0x4416;
	}
	_H3API_ RGB565 H3RGB565::Tan()
	{
		return 0xD5B1;
	}
	_H3API_ RGB565 H3RGB565::Teal()
	{
		return 0x410;
	}
	_H3API_ RGB565 H3RGB565::Thistle()
	{
		return 0xDDFB;
	}
	_H3API_ RGB565 H3RGB565::Tomato()
	{
		return 0xFB08;
	}
	_H3API_ RGB565 H3RGB565::Turquoise()
	{
		return 0x471A;
	}
	_H3API_ RGB565 H3RGB565::Violet()
	{
		return 0xEC1D;
	}
	_H3API_ RGB565 H3RGB565::Wheat()
	{
		return 0xF6F6;
	}
	_H3API_ RGB565 H3RGB565::White()
	{
		return 0xFFFF;
	}
	_H3API_ RGB565 H3RGB565::WhiteSmoke()
	{
		return 0xF7BE;
	}
	_H3API_ RGB565 H3RGB565::Yellow()
	{
		return 0xFFE0;
	}
	_H3API_ RGB565 H3RGB565::YellowGreen()
	{
		return 0x9E66;
	}

	_H3API_ UINT H3ARGB888::operator*() const
	{
		return Value();
	}

	_H3API_ H3ARGB888::operator DWORD() const
	{
		return Value();
	}
	_H3API_ VOID H3ARGB888::Darken(const UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Darken(amount);
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::Lighten(const UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Lighten(amount);
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::GrayScale()
	{
		H3RGB888 rgb(*this);
		rgb.GrayScale();
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::Legacy()
	{
		const UINT8 tmp = a;
		a = b;
		b = g;
		g = tmp;
	}
	_H3API_ H3ARGB888::H3ARGB888()
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(DWORD col)
	{
		*AsDword() = col;
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3RGB565& col) :
		b(col.GetBlue8()),
		g(col.GetGreen8()),
		r(col.GetRed8()),
		a(0xFF)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3RGB888& col) :
		b(col.b),
		g(col.g),
		r(col.r),
		a(0xFF)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3ARGB888& col) :
		b(col.b),
		g(col.g),
		r(col.r),
		a(col.a)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(UINT8 red, UINT8 green, UINT8 blue) :
		b(blue),
		g(green),
		r(red),
		a(0xFF)
	{
	}
	_H3API_ DWORD H3ARGB888::GetColor() const
	{
		return *AsDword();
	}
	_H3API_ VOID H3ARGB888::operator=(const H3RGB565& col)
	{
		r = col.GetRed8();
		g = col.GetGreen8();
		b = col.GetBlue8();
		a = 0xFF;
	}
	_H3API_ VOID H3ARGB888::operator=(const H3RGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
		a = 0xFF;
	}
	_H3API_ VOID H3ARGB888::operator=(const H3ARGB888& col)
	{
		*AsDword() = col.Value();
	}
	_H3API_ VOID H3ARGB888::operator=(UINT16 col)
	{
		*this = H3RGB565(col);
	}
	_H3API_ VOID H3ARGB888::operator=(UINT32 col)
	{
		*AsDword() = col;
	}
	_H3API_ BOOL H3ARGB888::operator==(const H3ARGB888& col)
	{
		return r == col.r && g == col.g && b == col.b && a == col.a;
	}
	_H3API_ VOID H3ARGB888::LightShadow()
	{
		*AsDword() = ((*AsDword() >> 1) & 0x7F7F7F) | ((*AsDword() >> 2) & 0x3F3F3F);
	}
	_H3API_ VOID H3ARGB888::DarkShadow()
	{
		*AsDword() = (*AsDword() >> 1) & 0x7F7F7F;
	}
	_H3API_ VOID H3ARGB888::Blend(const H3ARGB888& col)
	{
		*AsDword() = ((*AsDword() >> 1) & 0x7F7F7F) | ((*col.AsDword() >> 1) & 0x7F7F7F);
	}
	_H3API_ PDWORD H3ARGB888::AsDword()
	{
		return PDWORD(this);
	}
	_H3API_ PDWORD H3ARGB888::AsDword() const
	{
		return PDWORD(this);
	}
	_H3API_ UINT8 H3RGB555::GetRed()
	{
		return (bits & 0x7C00) >> 10;
	}
	_H3API_ UINT8 H3RGB555::GetGreen()
	{
		return (bits & 0x3E0) >> 5;
	}
	_H3API_ UINT8 H3RGB555::GetBlue()
	{
		return bits & 0x1F;
	}
	_H3API_ DWORD H3RGB555::UnPack()
	{
		return GetRed() << 16 | GetGreen() << 8 | GetBlue();
	}
	_H3API_ VOID H3RGB555::SetBits(WORD color)
	{
		bits = color;
	}
	_H3API_ WORD H3RGB555::Pack(UINT8 r, UINT8 g, UINT8 b)
	{
		return ((r / 8) & 0x1F) << 10 | ((g / 8) & 0x1F) << 5 | ((b / 8) & 0x1F);
	}
	_H3API_ DWORD H3RGB555::Unpack(RGB555 rgb)
	{
		return (((((rgb & 0x7C00) >> 10) * 255 + 15) / 31) << 16) + (((((rgb & 0x3E0) >> 5) * 255 + 31) / 63) << 8) + (((rgb & 0x1F) * 255 + 15) / 31);
	}
	_H3API_ VOID H3RGB555::PackRGB(UINT8 r, UINT8 g, UINT8 b)
	{
		bits = Pack(r, g, b);
	}
	_H3API_ UINT8 H3RGB565::GetRed() const
	{
		return (bits & 0xF800) >> 11;
	}
	_H3API_ UINT8 H3RGB565::GetRed8() const
	{
		return (GetRed() * 255 + 15) / 31;
	}
	_H3API_ UINT8 H3RGB565::GetGreen() const
	{
		return (bits & 0x7E0) >> 5;
	}
	_H3API_ UINT8 H3RGB565::GetGreen8() const
	{
		return (GetGreen() * 255 + 31) / 63;
	}
	_H3API_ UINT8 H3RGB565::GetBlue() const
	{
		return bits & 0x1F;
	}
	_H3API_ UINT8 H3RGB565::GetBlue8() const
	{
		return (GetBlue() * 255 + 15) / 31;
	}
	_H3API_ DWORD H3RGB565::GetRGB888() const
	{
		return (GetRed8() << 16 | GetGreen8() << 8 | GetBlue8());
	}
	_H3API_ RGB565 H3RGB565::GetBits() const
	{
		return bits;
	}
	_H3API_ H3RGB565::H3RGB565() :
		bits()
	{
	}
	_H3API_ H3RGB565::H3RGB565(RGB565 rgb) :
		bits(rgb)
	{
	}
	_H3API_ H3RGB565::H3RGB565(UINT8 r, UINT8 g, UINT8 b) :
		bits(Pack(r, g, b))
	{
	}
	_H3API_ H3RGB565::H3RGB565(DWORD color)
	{
		PackRGB565((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	}
	_H3API_ H3RGB565::H3RGB565(const H3RGB888& color)
	{
		PackRGB565(color.r, color.g, color.b);
	}
	_H3API_ H3RGB565::H3RGB565(const H3ARGB888& color)
	{
		PackRGB565(color.r, color.g, color.b);
	}
	_H3API_ VOID H3RGB565::operator=(const H3RGB565& col)
	{
		bits = col.bits;
	}
	_H3API_ VOID H3RGB565::operator=(const H3RGB888& col)
	{
		bits = Pack(col.r, col.g, col.b);
	}
	_H3API_ VOID H3RGB565::operator=(const H3ARGB888& col)
	{
		bits = Pack(col.r, col.g, col.b);
	}
	_H3API_ VOID H3RGB565::operator=(const UINT16 col)
	{
		bits = col;
	}
	_H3API_ VOID H3RGB565::operator=(const UINT32 col)
	{
		operator=(H3ARGB888(col));
	}
	_H3API_ BOOL H3RGB565::operator==(const H3RGB565& col)
	{
		return bits == col.bits;
	}
	_H3API_ H3RGB565::operator WORD() const
	{
		return Value();
	}
	_H3API_ WORD H3RGB565::Value() const
	{
		return bits;
	}
	_H3API_ VOID H3RGB565::SetBits(WORD color)
	{
		bits = color;
	}
	_H3API_ VOID H3RGB565::PackRGB565(UINT8 r, UINT8 g, UINT8 b)
	{
		bits = Pack(r, g, b);
	}
	_H3API_ VOID H3RGB565::Pack(H3RGB888& rgb)
	{
		bits = Pack(rgb.r, rgb.g, rgb.b);
	}
	_H3API_ WORD H3RGB565::Pack(UINT8 r, UINT8 g, UINT8 b)
	{
		return ((r / 8) & 0x1F) << 11 | ((g / 4) & 0x3F) << 5 | ((b / 8) & 0x1F);
	}
	_H3API_ DWORD H3RGB565::Unpack(RGB565 rgb)
	{
		return (((((rgb & 0xF800) >> 11) * 255 + 15) / 31) << 16) + (((((rgb & 0x7E0) >> 5) * 255 + 31) / 63) << 8) + (((rgb & 0x1F) * 255 + 15) / 31);
	}
	_H3API_ VOID H3RGB565::Darken(UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Darken(amount);
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::Lighten(UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Lighten(amount);
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::GrayScale()
	{
		H3RGB888 rgb(*this);
		rgb.GrayScale();
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::LightShadow()
	{
		LightShadow(H3RGB565::mask50(), H3RGB565::mask25());
	}
	_H3API_ VOID H3RGB565::LightShadow(RGB565 mask50, RGB565 mask25)
	{
		bits = ((bits >> 1) & mask50) | ((bits >> 2) & mask25);
	}
	_H3API_ VOID H3RGB565::DarkShadow()
	{
		DarkShadow(H3RGB565::mask50());
	}
	_H3API_ VOID H3RGB565::DarkShadow(RGB565 mask50)
	{
		bits = (bits >> 1) & mask50;
	}
	_H3API_ VOID H3RGB565::Blend(const H3RGB565& col)
	{
		Blend(col, H3RGB565::mask50());
	}
	_H3API_ VOID H3RGB565::Blend(const H3RGB565& col, RGB565 mask)
	{
		bits = ((bits >> 1) & mask) | ((col.bits >> 1) & mask);
	}
	_H3API_ H3HSV::H3HSV() :
		h(),
		s(),
		v()
	{
	}
	_H3API_ H3HSV::H3HSV(H3HSV& other) :
		h(other.h),
		s(other.s),
		v(other.v)
	{
	}
	_H3API_ H3HSV::H3HSV(const H3RGB888& rgb)
	{
		ConvertFromRgb888(rgb);
	}
	_H3API_ H3HSV& H3HSV::ConvertFromRgb888(const H3RGB888& rgb)
	{
		const UINT8 rgb_min = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
		const UINT8 rgb_max = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

		v = rgb_max;
		if (v == 0)
		{
			h = 0;
			s = 0;
			return *this;
		}

		s = 255 * long(rgb_max - rgb_min) / v;
		if (s == 0)
		{
			h = 0;
			return *this;
		}

		if (rgb_max == rgb.r)
			h = 0 + 43 * (rgb.g - rgb.b) / (rgb_max - rgb_min);
		else if (rgb_max == rgb.g)
			h = 85 + 43 * (rgb.b - rgb.r) / (rgb_max - rgb_min);
		else
			h = 171 + 43 * (rgb.r - rgb.g) / (rgb_max - rgb_min);

		return *this;
	}
	_H3API_ H3RGB888 H3HSV::ConvertToRgb888() const
	{
		H3RGB888 rgb;

		if (s == 0)
		{
			rgb.r = v;
			rgb.g = v;
			rgb.b = v;
			return rgb;
		}

		const UINT8 region = h / 43;
		const UINT8 remainder = (h - (region * 43)) * 6;

		const UINT8 p = (v * (255 - s)) >> 8;
		const UINT8 q = (v * (255 - ((s * remainder) >> 8))) >> 8;
		const UINT8 t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

		switch (region)
		{
		case 0:
			rgb.r = v; rgb.g = t; rgb.b = p;
			break;
		case 1:
			rgb.r = q; rgb.g = v; rgb.b = p;
			break;
		case 2:
			rgb.r = p; rgb.g = v; rgb.b = t;
			break;
		case 3:
			rgb.r = p; rgb.g = q; rgb.b = v;
			break;
		case 4:
			rgb.r = t; rgb.g = p; rgb.b = v;
			break;
		default:
			rgb.r = v; rgb.g = p; rgb.b = q;
			break;
		}
		return rgb;
	}
	_H3API_ VOID H3HSV::AddSaturation(UINT8 saturation)
	{
		s = std::min(255, s + saturation);
	}
	_H3API_ VOID H3HSV::RemoveSaturation(UINT8 saturation)
	{
		s = std::max(0, s - saturation);
	}
	_H3API_ VOID H3HSV::SetHue(UINT8 hue)
	{
		h = hue;
	}
	_H3API_ VOID H3HSV::AddValue(UINT8 value)
	{
		v = std::min(255, v + value);
	}
	_H3API_ VOID H3HSV::RemoveValue(UINT8 value)
	{
		v = std::max(0, v - value);
	}
	_H3API_ H3RGB565 H3RGB565::mask25()
	{
		return WordAt(0x6968FA);
	}
	_H3API_ H3RGB565 H3RGB565::mask50()
	{
		return WordAt(0x6968F4);
	}
}

namespace h3
{
	_H3API_ H3ResourceItem* H3ResourceItem::InitiateResource(LPCSTR name, INT type)
	{
		return THISCALL_3(H3ResourceItem*, 0x558970, this, name, type);
	}
	_H3API_ VOID H3ResourceItem::Dereference()
	{
		vTable->vEraseFromResourceManager(this);
	}
	_H3API_ VOID H3ResourceItem::AddToResourceManager()
	{
		H3ResourceManager::Get()->AddItem(this);
	}
	_H3API_ VOID H3ResourceItem::IncreaseReferences()
	{
		++ref;
	}
	_H3API_ INT32 H3ResourceItem::References() const
	{
		return ref;
	}
	_H3API_ LPCSTR H3ResourceItem::GetName() const
	{
		return name;
	}
	_H3API_ H3ResourceItem::~H3ResourceItem()
	{
		Dereference();
	}
	_H3API_ H3Palette565* H3BasePalette565::cast()
	{
		return reinterpret_cast<H3Palette565*>(this);
	}
	_H3API_ VOID H3BasePalette565::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x6003E0, color, id);
	}
	_H3API_ VOID H3BasePalette565::RotateColors(INT min_index, INT max_index, INT count)
	{
		THISCALL_4(VOID, 0x522E40, this, min_index, max_index, count);
	}
	_H3API_ H3Palette32* H3BasePalette565::Get32bitColors()
	{
		return cast()->Get32bitColors();
	}
	_H3API_ VOID H3BasePalette565::CopyPalette(H3Palette565& source)
	{
		cast()->CopyPalette(source);
	}
	_H3API_ VOID H3BasePalette565::CopyPalette(H3BasePalette565& source)
	{
		cast()->CopyPalette(source);
	}
	_H3API_ VOID H3BasePalette565::InitiateFromPalette888(const H3BasePalette888& palette)
	{
		THISCALL_8(void, 0x522BC0, this, &palette, IntAt(0x69E5DC), IntAt(0x69E5E4), IntAt(0x69E5D0), IntAt(0x69E5E0), IntAt(0x69E5F0), IntAt(0x69E5D8));
	}
	_H3API_	H3RGB565& H3BasePalette565::operator[](UINT index)
	{
		return reinterpret_cast<H3RGB565*>(color)[index]; // required cast for VS2008
	}
	_H3API_ H3RGB565 H3BasePalette565::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3BasePalette565::H3BasePalette565()
	{
	}
	_H3API_ H3BasePalette565::H3BasePalette565(const H3Palette888& palette)
	{
		InitiateFromPalette888(*(H3BasePalette888*)&palette);
	}

	_H3API_ H3BasePalette565::H3BasePalette565(const H3BasePalette888& palette)
	{
		InitiateFromPalette888(palette);
	}

	_H3API_ H3BasePalette565::~H3BasePalette565()
	{
		THISCALL_1(void, 0x522E30, this);
	}
	_H3API_ H3Palette32 H3BasePalette565::Convert() const
	{
		return PH3Palette565(this)->Convert();
	}
#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3BasePalette565::H3BasePalette565(H3BasePalette565&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		other.palette32 = nullptr; // for safety
	}

	_H3API_ H3BasePalette565& H3BasePalette565::operator=(H3BasePalette565&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		other.palette32 = nullptr; // for safety
		return *this;
	}
	_H3API_ H3BasePalette888::H3BasePalette888(H3BasePalette888&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
	}

	_H3API_ H3BasePalette888& H3BasePalette888::operator=(H3BasePalette888&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		return *this;
	}
#endif

	_H3API_ VOID H3BasePalette888::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x600400, this, id);
	}
	_H3API_ H3BasePalette888::~H3BasePalette888()
	{
		THISCALL_1(void, 0x523450, this);
	}
	_H3API_ H3BasePalette888::H3BasePalette888()
	{
	}
	_H3API_ H3RGB888& H3BasePalette888::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ const H3RGB888& H3BasePalette888::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3Palette32 H3BasePalette888::Convert() const
	{
		return PH3Palette888(this)->Convert();
	}
	_H3API_ H3ResourceItemData::H3ResourceItemData(LPCSTR name) :
		m_nameEnd(),
		m_item()
	{
		libc::strncpy(m_name, name, sizeof(m_name));
	}
	_H3API_ BOOL8 H3ResourceItemData::operator<(const H3ResourceItemData& other) const
	{
		return libc::strcmpi(m_name, other.m_name) < 0;
	}
}

namespace h3
{
    _H3API_ VOID H3DefFrame::DrawToPcx16(INT src_x, INT src_y, INT src_width, INT src_height,
        H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, H3Palette565* palette565, BOOL mirror, BOOL do_not_use_special_colors)
    {
        THISCALL_14(VOID, 0x47BE90, this, src_x, src_y, src_width, src_height, pcx16->buffer,
            dst_x, dst_y, pcx16->width, pcx16->height, pcx16->scanlineSize, palette565, mirror, do_not_use_special_colors);
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ INT32 H3Font::GetLinesCountInText(LPCSTR str, INT32 width)
	{
		return THISCALL_3(INT32, 0x4B5580, this, str, width);
	}
	_H3API_ INT32 H3Font::GetMaxLineWidth(LPCSTR str)
	{
		return THISCALL_2(INT32, 0x4B56F0, this, str);
	}
	_H3API_ INT32 H3Font::GetMaxWordWidth(LPCSTR str)
	{
		return THISCALL_2(INT32, 0x4B5770, this, str);
	}
	_H3API_ VOID H3Font::SplitTextIntoLines(LPCSTR text, INT32 textWidth, H3Vector<H3String>& stringVector)
	{
		THISCALL_4(VOID, 0x4B58F0, this, text, textWidth, &stringVector);
	}
	_H3API_ VOID H3Font::TextDraw(H3LoadedPcx16* pcx, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, eTextColor colorIndex, eTextAlignment alignment)
	{
		pcx->TextDraw(this, text, x, y, width, height, colorIndex, alignment);
	}
	_H3API_ H3Font* H3Font::Load(LPCSTR name)
	{
		return THISCALL_1(H3Font*, 0x55BD10, name);
	}
	_H3API_ PUINT8 H3Font::GetChar(UINT32 character_id)
	{
		return bitmapBuffer + bufferOffsets[character_id];
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3LoadedDef* H3LoadedDef::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedDef*, 0x55C9C0, name);
    }
    _H3API_ VOID H3LoadedDef::AddFrameFromDef(LPCSTR source, INT32 index)
    {
        H3DefLoader src(source);
        if (!src.Get())
            return;
        H3DefFrame* frm = src->groups[0]->frames[0];
        DefGroup*   grp = groups[0];

        H3DefFrame* frame = H3ObjectAllocator<H3DefFrame>().allocate(1);
        if (frame)
        {
            libc::memcpy(frame, frm, sizeof(H3DefFrame)); // copy frame data
            frame->rawData = ByteAllocator().allocate(frame->rawDataSize);
            libc::memcpy(frame->rawData, frm->rawData, frame->rawDataSize); // copy data buffer

            const int n_frames = grp->count;

            if (n_frames < index + 1) // add room for frame
            {
                H3DefFrame** new_list = reinterpret_cast<H3DefFrame**>(H3Realloc(grp->frames, (index + 1) * 4));
                if (new_list)
                {
                    new_list[index] = frame;
                    grp->count = index + 1;
                    grp->spritesSize = index + 1;
                    grp->frames = new_list;
                }
            }
            else
                grp->frames[index] = frame;
        }
    }
    _H3API_ VOID H3LoadedDef::ColorToPlayer(INT32 id)
    {
        if (palette565)
            palette565->ColorToPlayer(id);
        palette888->ColorToPlayer(id);
    }
    _H3API_ H3DefFrame* H3LoadedDef::GetGroupFrame(INT group, INT frame)
    {
        return groups[group]->frames[frame];
    }
    _H3API_ VOID H3LoadedDef::DrawTransparent(INT32 frame, H3LoadedPcx16* pcx, INT32 x, INT32 y,
        BOOL transparent, BOOL mirror, INT32 group, INT32 xFromRight, INT32 yFromBottom)
    {
        THISCALL_15(VOID, 0x47BA90, this, group, frame, xFromRight, yFromBottom, widthDEF, heightDEF,
            pcx->buffer, x, y, pcx->width, pcx->height, pcx->scanlineSize, mirror, transparent);
    }
    _H3API_ VOID H3LoadedDef::DrawToPcx16(INT group, INT frame, INT src_x, INT src_y, INT src_width,
        INT src_height, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL mirror, BOOL do_not_use_special_colors)
    {
        GetGroupFrame(group, frame)->DrawToPcx16(src_x, src_y, src_width, src_height,
            pcx16, dst_x, dst_y, palette565, mirror, do_not_use_special_colors);
    }
    _H3API_ VOID H3LoadedDef::DrawToPcx16(INT group, INT frame, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y)
    {
        DrawToPcx16(group, frame, 0, 0, widthDEF, heightDEF, pcx16, dst_x, dst_y);
    }
    _H3API_ VOID H3LoadedDef::AddDefGroup(UINT group_id, UINT frames_in_group)
    {
        THISCALL_3(VOID, 0x47B410, this, group_id, frames_in_group);
    }
    _H3API_ VOID H3LoadedDef::AddFrameToGroup(UINT group_id, H3DefFrame* frame)
    {
        THISCALL_3(VOID, 0x47B480, this, group_id, frame);
    }
    _H3API_ VOID H3LoadedDef::Init(LPCSTR name, UINT type, UINT width, UINT height)
    {
        THISCALL_5(void, 0x47B240, this, name, type, width, height);
    }
    _H3API_ H3LoadedDef::DefGroup& H3LoadedDef::operator[](UINT index)
    {
        return *groups[index];
    }
    _H3API_ H3DefFrame& H3LoadedDef::DefGroup::operator[](UINT index)
    {
        return *frames[index];
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3LoadedPcx::DrawToPcx16(int srcX, int srcY, int dx, int dy, H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors)
    {
        THISCALL_9(VOID, 0x44FA80, this, srcX, srcY, dx, dy, dest, destX, destY, skip_transparent_colors);
    }
    _H3API_ VOID H3LoadedPcx::DrawToPcx16(H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors)
    {
        THISCALL_9(VOID, 0x44FA80, this, 0, 0, width, height, dest, destX, destY, skip_transparent_colors);
    }
    _H3API_ VOID H3LoadedPcx::DrawToPcx(int src_x, int src_y, int dx, int dy, H3LoadedPcx* pcx_dest, int dest_x, int dest_y, BOOL copy_palette)
    {
        if (pcx_dest == nullptr || dx <= 0 || dy <= 0)
            return;

        if (src_x < 0)
            src_x = 0;
        if (src_y < 0)
            src_y = 0;
        if (dest_x < 0)
            dest_x = 0;
        if (dest_y < 0)
            dest_y = 0;

        const int w = std::min(dx, std::min(width - src_x, pcx_dest->width - dest_x));
        const int h = std::min(dy, std::min(height - src_y, pcx_dest->height - dest_y));

        if (w <= 0 || h <= 0)
            return;

        PUINT8 p_src = GetPixelIndex(src_x, src_y);
        PUINT8 p_dest = pcx_dest->GetPixelIndex(dest_x, dest_y);

        for (int j = 0; j < h; ++j)
        {
            PUINT8 dst = p_dest;
            PUINT8 src = p_src;
            for (int i = 0; i < w; ++i, ++dst, ++src)
                *dst = *src;
            p_dest += pcx_dest->scanlineSize;
            p_src  += scanlineSize;
        }

        if (copy_palette)
        {
            pcx_dest->palette565.CopyPalette(palette565);
            libc::memcpy(pcx_dest->palette888.color, palette888.color, sizeof(palette888.color));
        }
    }
    _H3API_ H3LoadedPcx* H3LoadedPcx::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedPcx*, 0x55AA10, name);
    }
    _H3API_ H3LoadedPcx* H3LoadedPcx::Create(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx* pcx = H3ObjectAllocator<H3LoadedPcx>().allocate(1);
        if (!pcx)
            return nullptr;

        pcx->InitiateResource(name, 16); // see 0x44F5CC
        pcx->vTable = reinterpret_cast<ResourceItemVTable*>(0x63BA14);
        pcx->width = width;
        pcx->height = height;
        pcx->scanlineSize = ((width + 3) >> 2) << 2;
        pcx->bufSize = height * pcx->scanlineSize;
        pcx->bufSizeUnk = pcx->bufSize;
        pcx->buffer = ByteAllocator().allocate(pcx->bufSize);
        if (!pcx->buffer)
        {
            H3ObjectAllocator<H3LoadedPcx>().deallocate(pcx);
            return nullptr;
        }
        PH3Palette565(&pcx->palette565)->Initiate();
        PH3Palette888(&pcx->palette888)->Initiate();

        return pcx;
    }
    _H3API_ VOID H3LoadedPcx::DrawAlpha(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        pcx16->Clamp(x, y, w, h, dst_x, dst_y);
        if (H3BitMode::Get() == 2)
            drawAlpha2(x, y, w, h, pcx16, dst_x, dst_y, skip_transparent);
        else
            drawAlpha4(x, y, w, h, pcx16, dst_x, dst_y, skip_transparent);
    }

    _H3API_ VOID H3LoadedPcx::drawAlpha2(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        PUINT8    row_src = GetPixelIndex(x, y);
        H3RGB565* row_dst = pcx16->GetPixel565(dst_x, dst_y);
        PUINT8 src = row_src;

        for (INT j = 0; j < h; ++j)
        {
            for (INT i = 0; i < w; ++i)
            {
                UINT8 pixel = src[i];
                if (pixel == 0 && skip_transparent)
                    continue;
                row_dst[i].Blend(palette565[pixel]);
            }
            src += scanlineSize;
            row_dst += (pcx16->scanlineSize >> 1);
        }
    }
    _H3API_ VOID H3LoadedPcx::drawAlpha4(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        H3Palette32& pal32 = *palette565.palette32;
        PUINT8     row_src = GetPixelIndex(x, y);
        H3ARGB888* row_dst = pcx16->GetPixel888(dst_x, dst_y);
        PUINT8 src = row_src;

        for (INT j = 0; j < h; ++j)
        {
            for (INT i = 0; i < w; ++i)
            {
                UINT8 pixel = src[i];
                if (pixel == 0 && skip_transparent)
                    continue;
                row_dst[i].Blend(pal32[pixel]);
            }
            src += scanlineSize;
            row_dst += (pcx16->scanlineSize >> 2);
        }
    }
    _H3API_ PUINT8 H3LoadedPcx::GetRow(int row) const
    {
        return buffer + row * scanlineSize;
    }
    _H3API_ PUINT8 H3LoadedPcx::GetPixelIndex(int x, int y) const
    {
        return GetRow(y) + x;
    }
    _H3API_ VOID H3LoadedPcx::FillRectangle(INT x, INT y, INT dx, INT dy, BYTE color_index)
    {
        const INT l_x = std::max(x, 0);
        const INT l_y = std::max(y, 0);
        if (dx < 0)
            dx = 0;
        if (dy < 0)
            dy = 0;
        dx = std::min(width - l_x, dx);
        dy = std::min(width - l_y, dy);

        PUINT8 start = GetPixelIndex(l_x, l_y);

        for (int j = 0; j < dy; ++j)
        {
            PUINT8 pixel = start;
            for (int i = 0; i < dx; ++i, ++pixel)
                *pixel = color_index;
            start += scanlineSize;
        }
    }
    _H3API_ H3LoadedPcx::H3LoadedPcx(LPCSTR name) :
        bufSize(),
        bufSizeUnk(),
        width(),
        height(),
        scanlineSize(),
        buffer()
    {
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
    }
    _H3API_ VOID H3LoadedPcx::Init(LPCSTR name)
    {
        bufSize = 0;
        bufSizeUnk = 0;
        width = 0;
        height = 0;
        scanlineSize = 0;
        buffer = nullptr;
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
    }
    _H3API_ VOID H3LoadedPcx::Init(LPCSTR name, INT w, INT h)
    {
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
        scanlineSize = ((w + 3) >> 2) << 2;
        bufSize = scanlineSize * h;
        bufSizeUnk = bufSize;
        width  = w;
        height = h;
        buffer = nullptr;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3LoadedPcx16::CopyRegion(H3LoadedPcx16* source, INT x, INT y)
    {
        THISCALL_7(VOID, 0x44E0C0, this, source->buffer, x, y, source->width, source->height, source->scanlineSize);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Construct(LPCSTR name, INT width, INT height)
    {
        return THISCALL_4(H3LoadedPcx16*, 0x44DD20, this, name, width, height);
    }
    _H3API_ VOID H3LoadedPcx16::DrawToPcx16(INT x, INT y, BOOL transparent, H3LoadedPcx16* dest, INT srcX, INT srcY)
    {
        return THISCALL_12(VOID, 0x44DF80, this, srcX, srcY, width, height, dest->buffer, x, y, dest->width, dest->height, dest->scanlineSize, transparent);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedPcx16*, 0x55B1E0, name);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Create(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx16* pcx16 = H3ObjectAllocator<H3LoadedPcx16>().allocate(1);
        if (!pcx16)
            return nullptr;
        return pcx16->Construct(name, width, height);
    }
	_H3API_ H3LoadedPcx16* H3LoadedPcx16::Create(INT width, INT height)
	{
        return Create(h3_NullString, width, height);
	}
	_H3API_ VOID H3LoadedPcx16::Destroy(BOOL destroy_buffer)
    {
        THISCALL_2(VOID, 0x44DCF0, this, destroy_buffer);
    }
    _H3API_ VOID H3LoadedPcx16::DrawShadow(INT x, INT y, INT dw, INT dh)
    {
        THISCALL_5(VOID, 0x44E2C0, this, x, y, dw, dh);
    }
    _H3API_ VOID H3LoadedPcx16::FillRectangle(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT _w = std::min(w, width - x);
        INT _h = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888 color(r, g, b);
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < _h; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    *rgb = color;

                rgb_row = reinterpret_cast<H3ARGB888*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;
            H3RGB565 color(r, g, b);
            for (int j = 0; j < _h; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->SetBits(color.GetBits());

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::FillRectangle(INT x, INT y, INT w, INT h, DWORD color)
    {
        FillRectangle(x, y, w, h, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    }
    _H3API_ VOID H3LoadedPcx16::DrawFrame(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b)
    {
        DrawThickFrame(x, y, w, h, 1, r, g, b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawFrame(INT x, INT y, INT w, INT h, const H3RGB888& color)
    {
        DrawFrame(x, y, w, h, color.r, color.g, color.b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, BYTE r, BYTE g, BYTE b)
    {
        FillRectangle(x, y, w, thickness, r, g, b);
        FillRectangle(x, y + thickness, thickness, h - thickness - thickness, r, g, b);
        FillRectangle(x + w - thickness, y + thickness, thickness, h - thickness - thickness, r, g, b);
        FillRectangle(x, y + h - thickness, w, thickness, r, g, b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, const H3RGB888& color)
    {
        DrawThickFrame(x, y, w, h, thickness, color.r, color.g, color.b);
    }
    _H3API_ VOID H3LoadedPcx16::DarkenArea(INT x, INT y, INT w, INT h, UINT8 amount)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT w_ = std::min(w, width - x);
        INT h_ = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < h_; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Darken(amount);

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < h_; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Darken(amount);

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::LightenArea(INT x, INT y, INT w, INT h, UINT8 amount)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT w_ = std::min(w, width - x);
        INT h_ = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < h_; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Lighten(amount);

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < h_; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Lighten(amount);

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::GrayScaleArea(INT x, INT y, INT w, INT h)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT _w = std::min(w, width - x);
        INT _h = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < _h; ++j)
            {
                H3ARGB888* rgb = rgb_row;
                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->GrayScale();

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < _h; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->GrayScale();

                rgb_row = reinterpret_cast<H3RGB565*>(reinterpret_cast<PUINT8>(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::AdjustHueSaturation(INT x, INT y, INT w, INT h, FLOAT hue, FLOAT saturation)
    {
        THISCALL_7(VOID, 0x44E610, this, x, y, w, h, hue, saturation);
    }
    _H3API_ BOOL H3LoadedPcx16::BackgroundRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL is_blue)
    {
        H3PcxLoader back(is_blue ? NH3Dlg::HDassets::DLGBLUEBACK : NH3Dlg::Assets::DIBOXBACK);

        if (back.Get() == nullptr)
            return FALSE;

        int _y = y;
        int _h = h;

        while (_h > 0)
        {
            int _x = x;
            int dh = std::min(256, _h);
            int _w = w;
            while (_w > 0)
            {
                back.Get()->DrawToPcx16(0, 0, _w, dh, this, _x, _y, FALSE);
                _x += 256;
                _w -= 256;
            }
            _y += 256;
            _h -= 256;
        }

        return TRUE;
    }
    _H3API_ BOOL H3LoadedPcx16::SimpleFrameRegion(INT32 x, INT32 y, INT32 _width, INT32 _height)
    {
        INT32 dX = _width;
        INT32 dY = _height;
        INT32 xEnd = x + _width;
        INT32 yEnd = y + _height;
        if (dX < 4 || dY < 4)
            return FALSE;

        struct Frames
        {
            enum
            {
                up,
                down,
                left,
                right,
                tl,
                tr,
                bl,
                br
            };

            H3PcxLoader m_up;
            H3PcxLoader m_down;
            H3PcxLoader m_left;
            H3PcxLoader m_right;
            H3PcxLoader m_tl;
            H3PcxLoader m_tr;
            H3PcxLoader m_bl;
            H3PcxLoader m_br;
            H3LoadedPcx16* m_tgt;

            Frames(H3LoadedPcx16* bg) :
                m_tgt(bg),
                m_up(NH3Dlg::HDassets::FRAME_U),
                m_down(NH3Dlg::HDassets::FRAME_D),
                m_left(NH3Dlg::HDassets::FRAME_L),
                m_right(NH3Dlg::HDassets::FRAME_R),
                m_tl(NH3Dlg::HDassets::FRAME_LU),
                m_tr(NH3Dlg::HDassets::FRAME_RU),
                m_bl(NH3Dlg::HDassets::FRAME_LD),
                m_br(NH3Dlg::HDassets::FRAME_RD)
            {
            }

            H3PcxLoader* begin() { return &m_up; }
            H3PcxLoader* end() { return &begin()[8]; }

            BOOL AllLoaded()
            {
                for (int i = 0; i < 8; ++i)
                    if (begin()[i].Get() == nullptr)
                        return FALSE;
                return TRUE;
            }

            VOID Draw(const INT x, const INT y, const INT frame)
            {
                begin()[frame].Get()->DrawToPcx16(0, 0, 4, 4, m_tgt, x, y, FALSE);
            }
        };

        Frames frames(this);
        if (!frames.AllLoaded())
            return FALSE;

        while (dX >= 4)
        {
            dX -= 4;
            frames.Draw(x + dX, y, frames.up);
            frames.Draw(x + dX, yEnd - 4, frames.down);
        }

        while (dY >= 4)
        {
            dY -= 4;
            frames.Draw(x, y + dY, frames.left);
            frames.Draw(xEnd - 4, y + dY, frames.right);
        }

        frames.Draw(x, y, frames.tl);
        frames.Draw(x, yEnd - 4, frames.bl);
        frames.Draw(xEnd - 4, y, frames.tr);
        frames.Draw(xEnd - 4, yEnd - 4, frames.br);

        return TRUE;
    }
    _H3API_ BOOL H3LoadedPcx16::FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
    {
        enum BoxFrames
        {
            BF_tl,
            BF_tr,
            BF_bl,
            BF_br,
            BF_ml,
            BF_mr,
            BF_tm,
            BF_bm,
            BF_blstat,
            BF_brstat,
            BF_bmstat
        };

        H3DefLoader box(is_blue ? NH3Dlg::HDassets::DLGBLUEBOX : NH3Dlg::Assets::DLGBOX);

        if (box.Get() == nullptr)
            return FALSE;

        H3BasePalette565 pal565;
        H3Palette565* pal;
        if (!is_blue)
        {
            pal565.CopyPalette(*box->palette565);
            pal565.ColorToPlayer(colorIndex);
            pal = PH3Palette565(&pal565);
        }
        else
            pal = box->palette565;

        INT f_bl, f_br, f_bm;
        if (statusBar)
        {
            f_bl = BoxFrames::BF_blstat;
            f_br = BoxFrames::BF_brstat;
            f_bm = BoxFrames::BF_bmstat;
        }
        else
        {
            f_bl = BoxFrames::BF_bl;
            f_br = BoxFrames::BF_br;
            f_bm = BoxFrames::BF_bm;
        }

        int _w = w - 64 - 64;
        H3DefFrame* tm = box->GetGroupFrame(0, BoxFrames::BF_tm);
        H3DefFrame* bm = box->GetGroupFrame(0, f_bm);
        while (_w > 0)
        {
            tm->DrawToPcx16(0, 0, 64, 64, this, x + _w, y, pal);
            bm->DrawToPcx16(0, 0, 64, 64, this, x + _w, y + h - 64, pal);
            _w -= 64;
        }

        int _h = h - 64 - 64;
        H3DefFrame* ml = box->GetGroupFrame(0, BoxFrames::BF_ml);
        H3DefFrame* mr = box->GetGroupFrame(0, BoxFrames::BF_mr);
        while (_h > 0)
        {
            ml->DrawToPcx16(0, 0, 64, 64, this, x, y + _h, pal);
            mr->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y + _h, pal);
            _h -= 64;
        }

        box->GetGroupFrame(0, BoxFrames::BF_tl)->DrawToPcx16(0, 0, 64, 64, this, x, y, pal);
        box->GetGroupFrame(0, BoxFrames::BF_tr)->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y, pal);
        box->GetGroupFrame(0, f_bl)->DrawToPcx16(0, 0, 64, 64, this, x, y + h - 64, pal);
        box->GetGroupFrame(0, f_br)->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y + h - 64, pal);

        return TRUE;
    }
    _H3API_ VOID H3LoadedPcx16::SinkArea(INT32 x, INT32 y, INT32 w, INT32 h)
    {
        if (x >= width - 2 || y >= height - 2 || w <= 2 || h <= 2)
            return;
        int _x = std::max(x, 0);
        int _y = std::max(y, 0);
        int _w = std::min(w, width - _x);
        int _h = std::min(h, height - _y);

        DarkenArea(_x, _y, _w - 1, 1, 50);
        DarkenArea(_x, _y + 1, 1, _h - 2, 50);
        LightenArea(_x + 1, _y + _h - 1, _w - 1, 1, 50);
        LightenArea(_x + _w - 1, _y + 1, 1, _h - 2, 50);
    }
    _H3API_ VOID H3LoadedPcx16::BevelArea(INT32 x, INT32 y, INT32 w, INT32 h)
    {
        if (x >= width - 2 || y >= height - 2 || w <= 2 || h <= 2)
            return;
        int _x = std::max(x, 0);
        int _y = std::max(y, 0);
        int _w = std::min(w, width - _x);
        int _h = std::min(h, height - _y);

        LightenArea(_x, _y, _w, 1, 50);
        LightenArea(_x, _y + 1, 1, _y + _h - 2, 50);
        DarkenArea(_x + 1, _y + _h - 1, _w - 1, 1, 50);
        DarkenArea(_x + _w, _y + 1, 1, _h - 2, 50);
    }
    _H3API_ VOID H3LoadedPcx16::TextDraw(H3Font* font, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, eTextColor colorIndex, eTextAlignment alignment)
    {
        THISCALL_10(VOID, 0x4B51F0, font, text, this, x, y, width, height, colorIndex, alignment, -1);
    }
    _H3API_ PUINT8 H3LoadedPcx16::GetRow(int row)
    {
        return buffer + row * scanlineSize;
    }
    _H3API_ H3RGB565* H3LoadedPcx16::GetPixel565(int x, int y)
    {
        return (H3RGB565*)GetRow(y) + x;
    }
    _H3API_ H3ARGB888* H3LoadedPcx16::GetPixel888(int x, int y)
    {
        return (H3ARGB888*)GetRow(y) + x;
    }
    _H3API_ H3ARGB888 H3LoadedPcx16::GetPixel(int x, int y)
    {
        if (H3BitMode::Get() == 4)
            return *GetPixel888(x, y);
        else
            return H3ARGB888(*GetPixel565(x, y));
    }
    _H3API_ VOID H3LoadedPcx16::Clamp(INT& src_x, INT& src_y, INT& src_w, INT& src_h, INT& dst_x, INT& dst_y) const
    {
        if (src_x < 0)
            src_x = 0;
        if (src_x >= width)
            src_x = width - 1;
        if (src_y < 0)
            src_y = 0;
        if (src_y >= height)
            src_y = height - 1;
        if (src_w < 0)
            src_w = 0;
        if (src_w > width - src_x)
            src_w = width - src_x;
        if (src_h < 0)
            src_h = 0;
        if (src_h > height - src_y)
            src_h = height - src_y;
        if (dst_x < 0)
            dst_x = 0;
        if (dst_x > width)
            dst_x = width - 1;
        if (dst_y < 0)
            dst_y = 0;
        if (dst_y > height)
            dst_y = height - 1;
        if (src_x + src_w > width - dst_x)
            src_w = width - dst_x - src_x;
        if (src_y + src_h > height - dst_y)
            src_h = height - dst_y - src_y;
    }

} /* namespace h3 */

namespace h3
{
    _H3API_ H3LoadedPcx24* H3LoadedPcx24::Construct(LPCSTR name, INT width, INT height, PUINT8 data, UINT32 dataSize)
    {
        return THISCALL_6(H3LoadedPcx24*, 0x44EA20, this, name, width, height, data, dataSize);
    }
    _H3API_ VOID H3LoadedPcx24::DrawToPcx16(INT dst_x, INT dst_y, H3LoadedPcx16* dest, INT srcX, INT srcY)
    {
        return THISCALL_11(VOID, 0x44ECE0, this, srcX, srcY, width, height, dest->buffer, dst_x, dst_y, dest->width, dest->height, dest->scanlineSize);
    }
    _H3API_ H3LoadedPcx24* H3LoadedPcx24::Load(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx24* pcx = H3ObjectAllocator<H3LoadedPcx24>().allocate(1);
        UINT32 data_size = width * height * sizeof(H3RGB888);
        PBYTE buffer = ByteAllocator().allocate(data_size);
        pcx->Construct(name, width, height, buffer, data_size);
        return pcx;
    }
    _H3API_ PUINT8 H3LoadedPcx24::GetRow(int row)
    {
        return buffer + row * sizeof(H3RGB888) * width;
    }
    _H3API_ H3RGB888* H3LoadedPcx24::GetPixel(int x, int y)
    {
        return (H3RGB888*)GetRow(y) + x;
    }
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Lod* H3Lod::Create(LPCSTR fileName)
	{
		return THISCALL_2(H3Lod*, 0x559420, this, fileName);
	}
	_H3API_ VOID H3Lod::Destroy()
	{
		THISCALL_1(VOID, 0x559460, this);
	}
	_H3API_ BOOL H3Lod::Load(LPCSTR fileName)
	{
		return THISCALL_3(BOOL, 0x4FAF30, &filePosition, fileName, 1); // 1 means read-only
	}
	_H3API_ BOOL8 H3Lod::FindFileInLod(LPCSTR file)
	{
		return THISCALL_2(BOOL8, 0x4FB100, &filePosition, file);
	}
	_H3API_ H3LodItem* H3Lod::LoadFileFromLod(LPCSTR file)
	{
		return THISCALL_2(H3LodItem*, 0x4FACA0, &filePosition, file);
	}
	_H3API_ VOID H3LoadedMsk::operator=(const H3Msk& msk)
	{
		width = msk.width;
		height = msk.height;
		msk.colorMask >> colors;
		msk.shadowMask >> shadow;
	}
	_H3API_ void H3Msk::Msk::operator>>(H3ObjectMask& mask) const
	{
		mask[0].Set(dbits);
		mask[1].Set(wbits);
	}
}

namespace h3
{
	_H3API_ H3ARGB888& H3Palette32::operator[](UINT index)
	{
		return colors[index];
	}
	_H3API_ H3ARGB888 H3Palette32::operator[](UINT index) const
	{
		return colors[index];
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3Palette565::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x6003E0, color, id);
	}
	_H3API_ VOID H3Palette565::RotateColors(INT min_index, INT max_index, INT count)
	{
		THISCALL_4(VOID, 0x522E40, this, min_index, max_index, count);
	}
	_H3API_ H3Palette565* H3Palette565::Initiate()
	{
		return THISCALL_1(H3Palette565*, 0x522B40, this);
	}
	_H3API_ H3Palette32* H3Palette565::Get32bitColors()
	{
		if (type == 0x61)
			return palette32;
		return nullptr;
	}
	_H3API_ VOID H3Palette565::CopyPalette(const H3Palette565& source)
	{
		THISCALL_2(VOID, 0x522DD0, this, &source);
	}
	_H3API_ VOID H3Palette565::CopyPalette(const H3BasePalette565& source)
	{
		THISCALL_2(VOID, 0x522DD0, this, &source);
	}
	_H3API_ H3RGB565& H3Palette565::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ H3RGB565 H3Palette565::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3Palette32 H3Palette565::Convert() const
	{
		H3Palette32 p;

		for (UINT i = 0; i < 256; ++i)
			p.colors[i] = color[i];

		return p;
	}
	_H3API_ VOID H3Palette565::Init(const H3BasePalette565& palette)
	{
		THISCALL_2(VOID, 0x522DD0, this, &palette);
	}
	_H3API_ H3Palette565* H3Palette565::Load(LPCSTR name)
	{
		return THISCALL_1(H3Palette565*, 0x55B5F0, name); // adds to resource manager directly, alt. 55B270
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3Palette888::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x600400, this, id);
	}
	_H3API_ H3Palette888* H3Palette888::Initiate()
	{
		return THISCALL_1(H3Palette888*, 0x523320, this);
	}
	_H3API_	H3RGB888& H3Palette888::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ const H3RGB888& H3Palette888::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ VOID H3Palette888::Init(const H3BasePalette888& palette)
	{
		THISCALL_2(void, 0x5233F0, this, &palette);
	}
	_H3API_ H3Palette32 H3Palette888::Convert() const
	{
		H3Palette32 p;

		for (UINT i = 0; i < 256; ++i)
			p.colors[i] = color[i];

		return p;
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3ResourceManager::Node* H3ResourceManager::FindItem(LPCSTR name)
    {
        iterator it = Find(name);
        if (it == end())
            return nullptr;
        return it.Get();
    }
    _H3API_ VOID H3ResourceManager::AddItem(H3ResourceItem* item)
    {
        H3ResourceItemData res(item->GetName());
        struct returnValues /* std::pair<Node*, bool>*/
        {
            Node* node;
            BOOL8 inserted;
        }retValues;

        THISCALL_3(returnValues&, 0x55DDF0, this, &retValues, &res);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(Node* node)
    {
        Node* temp;
        THISCALL_3(VOID, 0x55DF20, this, &temp, node);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(LPCSTR name)
    {
        if (!name)
            return;
        Node* node = FindItem(name);
        if (node == m_root)
            return;
        if (libc::strcmpi(node->data.m_name, name))
            return;
        RemoveItem(node);
    }
    _H3API_ VOID H3ResourceManager::RemoveItem(const iterator& iter)
    {
        if (iter != end())
            RemoveItem(iter.Get());
    }
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ LPCSTR H3TextFile::GetText(UINT32 row) const
	{
		return text[row - 1];
	}
	_H3API_ LPCSTR H3TextFile::GetText(UINT32 row)
	{
		return text[row - 1];
	}
	_H3API_ H3TextFile* H3TextFile::Load(LPCSTR name)
	{
		return THISCALL_1(H3TextFile*, 0x55BDA0, name);
	}
	_H3API_ VOID H3TextFile::UnLoad()
	{
		vTable->vEraseFromResourceManager(this);
	}
	_H3API_ LPCSTR& H3TextFile::operator[](UINT row)
	{
		return text[row];
	}
	_H3API_ LPCSTR* H3TextFile::begin()
	{
		return text.begin();
	}
	_H3API_ LPCSTR* H3TextFile::end()
	{
		return text.end();
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3Vector<H3Vector<LPCSTR>*>& H3TextTable::GetText()
    {
        return text;
    }
    _H3API_ UINT32 H3TextTable::CountRows() const
    {
        return text.Count();
    }
    _H3API_ H3TextTable* H3TextTable::Load(LPCSTR name)
    {
        return THISCALL_1(H3TextTable*, 0x55C2B0, name);
    }
    _H3API_ VOID H3TextTable::UnLoad()
    {
        vTable->vEraseFromResourceManager(this);
    }
    _H3API_ H3Vector<LPCSTR>& H3TextTable::operator[](UINT row)
    {
        return *text[row];
    }
    _H3API_ H3TextTable::iterator H3TextTable::begin()
    {
        return iterator(text.begin());
    }
    _H3API_ H3TextTable::iterator H3TextTable::end()
    {
        return iterator(text.end());
    }
    _H3API_ H3TextTable::iterator::iterator(H3Vector<LPCSTR>** vec) :
        data(vec)
    {
    }
    _H3API_ H3TextTable::iterator& H3TextTable::iterator::operator++()
    {
        ++data;
        return *this;
    }
    _H3API_ H3TextTable::iterator H3TextTable::iterator::operator++(int)
    {
        iterator it(data);
        ++data;
        return it;
    }
    _H3API_ H3Vector<LPCSTR>& H3TextTable::iterator::operator*()
    {
        return **data;
    }
    _H3API_ H3Vector<LPCSTR>* H3TextTable::iterator::operator->()
    {
        return *data;
    }
    _H3API_ LPCSTR H3TextTable::iterator::operator[](UINT column)
    {
        return (**data)[column];
    }
    _H3API_ BOOL H3TextTable::iterator::operator==(const iterator& other)
    {
        return data == other.data;
    }
    _H3API_ BOOL H3TextTable::iterator::operator!=(const iterator& other)
    {
        return data != other.data;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3WavFile* H3WavFile::Load(LPCSTR name)
    {
        return THISCALL_1(H3WavFile*, 0x55C930, name);
    }
    _H3API_ H3WavFile::H3WavFile(LPCSTR name) :
        hSample(0),
        buffer(),
        bufferSize(),
        lockSemaphore(HANDLE(0)),
        spinCount(127),
        debugInfo(PRTL_CRITICAL_SECTION_DEBUG(1)) // RTL_RESOURCE_TYPE
    {
        InitiateResource(name, 32);
        PtrAt(this) = VTABLE;
    }
    _H3API_ H3WavFile::H3WavFile(LPCSTR name, PUINT8 buffer, DWORD bufferSize) :
        hSample(0),
        buffer(buffer),
        bufferSize(bufferSize),
        lockSemaphore(HANDLE(0)),
        spinCount(127),
        debugInfo(PRTL_CRITICAL_SECTION_DEBUG(1)) // RTL_RESOURCE_TYPE
    {
        InitiateResource(name, 32);
        PtrAt(this) = VTABLE;
    }
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ LPCSTR H3CreatureInformation::GetCreatureName(INT32 count) const
    {
        return count > 1 ? namePlural : nameSingular;
    }
    _H3API_ H3Resources H3CreatureInformation::UpgradeCost(H3CreatureInformation* upg, INT32 count) const
    {
        H3Resources res = upg->cost;
        res.RemoveResources(cost);
        for (INT32* it = res.begin(); it != res.end(); ++it)
            *it *= count;
        return res;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_	LPCSTR H3CombatCreature::GetCreatureName() const
    {
        return info.GetCreatureName(numberAlive);
    }
    _H3API_ INT32 H3CombatCreature::GetSecondSquare() const
    {
        return THISCALL_1(INT32, 0x4463C0, this);
    }
    _H3API_ INT32 H3CombatCreature::GetStackSpeed() const
    {
        return THISCALL_1(INT32, 0x4489F0, this);
    }
    _H3API_ INT32 H3CombatCreature::HexRelativePosition(INT32 considered_hex, INT32 relative_orientation) const
    {
        return THISCALL_3(INT32, 0x524280, this, considered_hex, relative_orientation);
    }
    _H3API_ BOOL H3CombatCreature::IsIncapacitated() const
    {
        return activeSpellDuration[eSpell::BLIND]
            || activeSpellDuration[eSpell::STONE]
            || activeSpellDuration[eSpell::PARALYZE]
            || info.cannotMove;
    }
    _H3API_ BOOL H3CombatCreature::IsDefending() const
    {
        return info.defending;
    }
    _H3API_ BOOL H3CombatCreature::IsDone() const
    {
        return info.done;
    }
    _H3API_ BOOL H3CombatCreature::IsClone() const
    {
        return info.clone;
    }
    _H3API_ BOOL H3CombatCreature::IsSiege() const
    {
        return info.siegeWeapon;
    }
    _H3API_ BOOL H3CombatCreature::IsSummon() const
    {
        return info.summon;
    }
    _H3API_ BOOL H3CombatCreature::HadMorale() const
    {
        return info.morale;
    }
    _H3API_ BOOL H3CombatCreature::IsWaiting() const
    {
        return info.waiting;
    }
    _H3API_ BOOL H3CombatCreature::HasMoved() const
    {
        return info.done;
    }
    _H3API_ INT32 H3CombatCreature::Index() const
    {
        return sideIndex + 21 * side;
    }
    _H3API_ VOID H3CombatCreature::ShowStatsDialog(BOOL right_click) const
    {
        THISCALL_3(VOID, 0x468440, H3CombatManager::Get(), this, right_click);
    }
    _H3API_ INT32 H3CombatCreature::GetSide() const
    {
        return THISCALL_1(INT, 0x43FE60, this);
    }
    _H3API_ H3Hero* H3CombatCreature::GetOwner() const
    {
        return THISCALL_1(H3Hero*, 0x4423B0, this);
    }
    _H3API_ INT32 H3CombatCreature::GetProtectiveSpellEffect(INT32 damage, INT32 spellID) const
    {
        return STDCALL_3(INT32, 0x5A7EC0, damage, spellID, this);
    }
    _H3API_ INT32 H3CombatCreature::MagicMirrorEffect() const
    {
        return THISCALL_1(INT32, 0x448510, this);
    }
    _H3API_ INT32 H3CombatCreature::ApplyPhysicalDamage(INT32 amount)
    {
        return THISCALL_2(INT32, 0x443DB0, this, amount);
    }
    _H3API_ VOID H3CombatCreature::ApplySpell(INT32 spellId, INT32 spellPower, INT32 schoolLevel, H3Hero* hero)
    {
        return THISCALL_5(VOID, 0x444610, this, spellId, spellPower, schoolLevel, hero);
    }
    _H3API_ BOOL8 H3CombatCreature::ApplyAfterHitSpell(H3CombatCreature* defender)
    {
        return THISCALL_2(BOOL8, 0x440220, this, defender);
    }
    _H3API_ VOID H3CombatCreature::ApplyAfterHitAbility(H3CombatCreature* defender, INT32 damage, INT32 killed, INT32 totalDefenderHp)
    {
        THISCALL_5(VOID, 0x4408E0, this, defender, damage, killed, totalDefenderHp);
    }
    _H3API_ BOOL8 H3CombatCreature::CanReceiveSpell(INT32 spellId) const
    {
        return FASTCALL_2(BOOL8, 0x4477A0, spellId, this);
    }
    _H3API_ BOOL H3CombatCreature::CanCastSpellAtEmptyHex(INT32 hexId) const
    {
        return THISCALL_2(BOOL, 0x4470F0, this, hexId);
    }
    _H3API_ BOOL8 H3CombatCreature::MoveToHex(INT32 hexId)
    {
        return THISCALL_3(BOOL8, 0x445A30, this, hexId, 0);
    }
    _H3API_ BOOL8 H3CombatCreature::UseEnchanters()
    {
        return THISCALL_1(BOOL8, 0x447D00, this);
    }
    _H3API_ INT32 H3CombatCreature::GetX() const
    {
        return THISCALL_1(INT32, 0x446380, this);
    }
    _H3API_ INT32 H3CombatCreature::GetY() const
    {
        return THISCALL_1(INT32, 0x446350, this);
    }
	_H3API_ INT32 H3CombatCreature::CurrentHitPoints() const
	{
        return info.hitPoints - healthLost;
	}
	_H3API_ INT32 H3CombatCreature::MaxHitPoints() const
	{
        return info.hitPoints;
	}

} /* namespace h3 */

namespace h3
{
    _H3API_ H3CombatCreature* H3CombatSquare::GetMonster()
	{
		return GetCreature();
	}
    _H3API_ H3CombatCreature* H3CombatSquare::GetCreature()
    {
        return THISCALL_1(H3CombatCreature*, 0x4E7230, this);
    }
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MagicAnimation* H3MagicAnimation::GetAnim(INT32 spellId)
	{
		H3Spell* spellInfo = &H3Spell::Get()[spellId];
		if (spellInfo->animationIndex < 0)
		{
			return nullptr;
		}
		H3MagicAnimation* animTable = H3MagicAnimation::Get();
		return &animTable[spellInfo->animationIndex];
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ INT32 H3Creature::GetUpgrade(INT32 id)
    {
        return THISCALL_1(INT32, 0x47AAD0, id);
    }
    _H3API_ BOOL8 H3Creature::HasUpgrade(INT32 id)
    {
        if (!H3Main::Get()->mapKind) /* roe */
        {
            if (
                id == eCreature::AIR_ELEMENTAL  ||
                id == eCreature::EARTH_ELEMENTAL||
                id == eCreature::FIRE_ELEMENTAL ||
                id == eCreature::WATER_ELEMENTAL
               )
                return FALSE;
        }
        return THISCALL_1(BOOL8, 0x47AA50, id);
    }
    _H3API_ LPCSTR H3Creature::GroupName(INT32 amount, INT32 text_variant)
    {
        return FASTCALL_2(LPCSTR, 0x44AAB0, amount, text_variant);
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3GarrisonInterface::DrawHero(INT32 hero_picture)
    {
        THISCALL_2(VOID, 0x5AA370, this, hero_picture);
    }
    _H3API_ VOID H3GarrisonInterface::DrawCreature(INT32 index, INT32 creature_portrait_index)
    {
        THISCALL_3(VOID, 0x5AA540, this, index, creature_portrait_index);
    }
    _H3API_ VOID H3GarrisonInterface::Redraw(INT32 selected_slot)
    {
        THISCALL_2(VOID, 0x5AA090, this, selected_slot);
    }

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapItem* H3MainSetup::GetMapItem(INT32 x, INT32 y, INT32 z)
	{
		return THISCALL_4(H3MapItem*, 0x4086D0, this, x, y, z);
	}

	_H3API_ VOID H3MainSetup::DrawItem(H3MapItem* mitem, H3ObjectDraw* draw)
	{
		THISCALL_3(VOID, 0x505880, this, mitem, draw);
	}

	_H3API_ VOID H3MainSetup::AddObjectAttribute(H3ObjectAttributes* oa)
	{
		H3Vector<H3ObjectAttributes>* list = &objectLists[oa->type];
		THISCALL_4(VOID, 0x4D15F0, list, list->end(), 1, oa);
	}

	_H3API_ H3Point H3MainSetup::GetCoordinates(H3MapItem* item)
	{
		H3Point coordinates;
		UINT delta    = item - mapitems;
		coordinates.x = delta % mapSize;
		delta        /= mapSize;
		coordinates.y = delta % mapSize;
		coordinates.z = delta / mapSize;
		return coordinates;
	}

	_H3API_ H3Map<H3MapItem> H3MainSetup::GetMap()
	{
		return H3Map<H3MapItem>(mapitems, static_cast<UINT>(mapSize), hasUnderground);
	}

	_H3API_ H3FastMap<H3MapItem> H3MainSetup::GetFastMap()
	{
		return H3FastMap<H3MapItem>(mapitems, static_cast<UINT>(mapSize), hasUnderground);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ INT32 H3Hero::MaxLandMovement()
	{
		return THISCALL_2(INT32, 0x4E4C00, this, 0);
	}
	_H3API_ INT32 H3Hero::MaxWaterMovement()
	{
		return THISCALL_2(INT32, 0x4E4C00, this, 1);
	}
	_H3API_ INT32 H3Hero::CalcMaxMovement()
	{
		return THISCALL_1(INT32, 0x4E5000, this);
	}
	_H3API_ VOID H3Hero::GiveArtifact(const H3Artifact& art, INT32 slot)
	{
		THISCALL_3(VOID, 0x4E2C70, this, &art, slot);
	}
	_H3API_ VOID H3Hero::GiveArtifact(const H3Artifact& art)
	{
		THISCALL_4(void, 0x4E32E0, this, &art, 0, 0);
	}
	_H3API_ VOID H3Hero::GiveBackpackArtifact(const H3Artifact& art, INT32 index)
	{
		THISCALL_3(void, 0x4E3200, this, &art, index);
	}
	_H3API_ VOID H3Hero::LearnSecondarySkill(INT32 id, INT32 increase)
	{
		return THISCALL_3(VOID, 0x4E2540, this, id, increase);
	}
	_H3API_ INT32 H3Hero::GetSpellExpertise(INT32 spell_id, INT32 special_terrain)
	{
		return THISCALL_3(INT32, 0x4E52F0, this, spell_id, special_terrain);
	}
	_H3API_ BOOL8 H3Hero::HasCreatureType(INT32 type)
	{
		return army.HasCreatureType(type);
	}
	_H3API_ INT32 H3Hero::GetSpellSpecialtyEffect(INT32 spell_id, INT32 creature_level, INT32 base_damage)
	{
		return THISCALL_4(INT32, 0x4E6260, this, spell_id, creature_level, base_damage);
	}
	_H3API_ INT32 H3Hero::GetSorceryEffect(INT32 spell_id, INT32 base_damage, H3CombatCreature* mon)
	{
		return THISCALL_4(INT32, 0x4E59D0, this, spell_id, base_damage, mon);
	}
	_H3API_ INT32 H3Hero::GetRealSpellDamage(INT32 base_damage, H3CombatCreature* mon, INT32 spell_id, H3Hero* enemy)
	{
		INT32 dmg = GetSorceryEffect(spell_id, base_damage, mon);
		dmg = FASTCALL_3(INT32, 0x44B180, dmg, spell_id, mon->type); // golem-style resistance
		return mon->GetProtectiveSpellEffect(dmg, spell_id);
	}
	_H3API_ INT32 H3Hero::GetSpecialTerrain()
	{
		return THISCALL_1(INT32, 0x4E5130, this);
	}
	_H3API_ INT32 H3Hero::GetSpecialSpellTerrain()
	{
		return THISCALL_1(INT32, 0x4E5210, this);
	}
	_H3API_ BOOL H3Hero::HasSpell(INT32 spell)
	{
		return learnedSpells[spell] | availableSpell[spell];
	}
	_H3API_ VOID H3Hero::BuildCombinationArtifact(INT32 combo_id)
	{
		THISCALL_3(VOID, 0x4DC1A0, this, combo_id, -1);
	}
	_H3API_ BOOL H3Hero::UnlearnSkill(INT32 id)
	{
		if (secSkill[id])
		{
			secSkill[id] = 0;
			INT32 pos = secSkillPosition[id];
			secSkillPosition[id] = 0;
			for (INT32 i = 0; i < 28; i++)
			{
				if (secSkillPosition[i] > pos)
					secSkillPosition[i] -= 1;
			}
			secSkillCount -= 1;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ VOID H3Hero::RecalculateMovement()
	{
		H3AdventureManager* adv = H3AdventureManager::Get();
		adv->movementCalculated = 0;
		adv->movementCalculated1 = 0;
		if (dest_x != -1)
		{
			adv->MovementCalculations(H3Position::Pack(dest_x, dest_y, dest_z));
			adv->MakeHeroPath();
		}
	}
	_H3API_ BOOL8 H3Hero::CanFlyOnTile()
	{
		return THISCALL_1(BOOL8, 0x4E5F50, this);
	}
	_H3API_ INT32 H3Hero::GetMovementCost(INT32 orientation, UINT32 mixedPos)
	{
		return FASTCALL_4(INT32, 0x4B1620, this, orientation, mixedPos, movement);
	}
	_H3API_ INT32 H3Hero::SSkillsLeftToLearn()
	{
		INT32 known_skills = 0;
		for (INT32 i = 0; i < 28; i++)
			known_skills += secSkill[i];

		INT32 maxSkills = 3 * ByteAt(0x4E256A); // usually 3 * 8

		if (known_skills >= maxSkills)
			return 0;

		INT32 skills_can_be_learned = 0;

		INT32 sslevel;
		H3Main* main = H3Main::Get();

		for (INT32 i = 0; i < 28; i++)
		{
			sslevel = secSkill[i];
			if (!main->bannedSkills[i] || sslevel > 0)
				skills_can_be_learned += 3 - sslevel;
		}
		if (hero_class != eHeroClass::NECROMANCER && hero_class != eHeroClass::DEATH_KNIGHT && secSkill[eSecondary::NECROMANCY] == 0 && !main->bannedSkills[eSecondary::NECROMANCY])
			skills_can_be_learned -= 3;
		if ((hero_class == eHeroClass::NECROMANCER || hero_class == eHeroClass::DEATH_KNIGHT) && secSkill[eSecondary::LEADERSHIP] == 0 && !main->bannedSkills[eSecondary::LEADERSHIP])
			skills_can_be_learned -= 3;
		if ((hero_class == eHeroClass::OVERLORD || hero_class == eHeroClass::WARLOCK) && secSkill[eSecondary::WATER_MAGIC] == 0 && !main->bannedSkills[eSecondary::WATER_MAGIC])
			skills_can_be_learned -= 3;
		if ((hero_class == eHeroClass::RANGER || hero_class == eHeroClass::DRUID) && secSkill[eSecondary::FIRE_MAGIC] == 0 && !main->bannedSkills[eSecondary::FIRE_MAGIC])
			skills_can_be_learned -= 3;

		skills_can_be_learned = std::min(maxSkills - known_skills, skills_can_be_learned);
		skills_can_be_learned = std::max(skills_can_be_learned, 1);
		return skills_can_be_learned - 1; // -1 because it's already included in formula for level to go to
	}
	_H3API_ BOOL H3Hero::WearsArtifact(INT id)
	{
		return THISCALL_2(BOOL, 0x4D9460, this, id);
	}
	_H3API_ INT32 H3Hero::GetHeroPrimary(INT primary)
	{
		return THISCALL_2(INT32, 0x5BE240, this, primary);
	}
	_H3API_ INT32 H3Hero::HasSimilarCreature(INT id)
	{
		return FASTCALL_2(INT32, 0x4A7230, this, id);
	}
	_H3API_ LPCSTR H3Hero::GetHeroClassName()
	{
		return THISCALL_1(LPCSTR, 0x4D91E0, this);
	}
	_H3API_ VOID H3Hero::ShowDialog() const
	{
		return FASTCALL_4(VOID, 0x4E1A70, id, 0, 1, 1);
	}
	_H3API_ VOID H3Hero::ShowDialog(BOOL32 dismissable, BOOL32 not_in_town, BOOL8 right_click)
	{
		return FASTCALL_4(VOID, 0x4E1A70, id, dismissable, not_in_town, right_click);
	}
	_H3API_ INT H3Hero::GetPower() const
	{
		return THISCALL_1(INT32, 0x427650, this);
	}
	_H3API_ BOOL8 H3Hero::CanReplaceArtifact(INT32 id, INT32 slot) const
	{
		return THISCALL_3(BOOL8, 0x4E2AB0, this, id, slot);
	}
	_H3API_ BOOL8 H3Hero::CanPlaceArtifact(INT32 id, INT32 slot) const
	{
		return THISCALL_3(BOOL8, 0x4E27C0, this, id, slot);
	}
	_H3API_ VOID H3Hero::RemoveArtifact(INT32 slot)
	{
		THISCALL_2(VOID, 0x4E2E40, this, slot);
	}
	_H3API_ VOID H3Hero::RemoveBackpackArtifact(INT32 slot)
	{
		THISCALL_2(VOID, 0x4E2FC0, this, slot);
	}
	_H3API_ VOID H3Hero::ShowCreatureDialog(INT32 slot, BOOL rightClick)
	{
		THISCALL_9(VOID, 0x4C6910, H3Main::Get(), &army, slot, this, 0, 119, 20, 0, rightClick);
	}
	_H3API_ VOID H3Hero::ShowSpellInfo(INT32 spell, BOOL RMB)
	{
		INT32 expertise = GetSpellExpertise(spell, GetSpecialSpellTerrain());
		LPCSTR desc = H3Spell::Get()[spell].description[expertise];
		if (RMB)
			H3Messagebox::RMB(desc, H3PictureCategories::Spell(eSpell(spell)));
		else
			H3Messagebox::Show(desc, H3PictureCategories::Spell(eSpell(spell)));
	}
	_H3API_ VOID H3Hero::ShowSSkillInfo(INT32 skill, BOOL RMB)
	{
		INT32 lvl = secSkill[skill];
		if (lvl == 0)
			lvl = 1;
		LPCSTR desc = H3SecondarySkillInfo::Get()[skill].description[lvl];
		if (RMB)
			H3Messagebox::RMB(desc, H3PictureCategories::SecSkill(eSecondary(skill), eSecSkillLevel(lvl)));
		else
			H3Messagebox::Show(desc, H3PictureCategories::SecSkill(eSecondary(skill), eSecSkillLevel(lvl)));
	}
	_H3API_ VOID H3Hero::ShowPSkillInfo(INT32 skill, BOOL RMB)
	{
		INT32 value = GetHeroPrimary(skill) | 0x100000; // removes the '+' in front of number
		FASTCALL_12(VOID, 0x4F6C00, StrAt(0x6A75A8 + 4 * skill),
			RMB ? 4 : 1, -1, -1, 34, value, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ BOOL H3Hero::HasAllCombinationParts(INT slot)
	{

		INT32 artId = bodyArtifacts[slot].id;
		if (id == -1)
			return FALSE;

		H3ArtifactSetup* art_setups = H3ArtifactSetup::Get();

		INT32 comboId = art_setups[artId].comboID;
		if (comboId != -1) // it's already a combination artifact
			return FALSE;
		comboId = art_setups[artId].combinationArtifactId;
		if (comboId == -1) // not part of a combination
			return FALSE;

		INT32 numArts = H3ArtifactCount::Get();

		for (INT32 i = 0; i < numArts; ++i)
		{
			if (art_setups[i].combinationArtifactId == comboId)
			{
				if (!WearsArtifact(i))
					return FALSE;
			}
		}

		return TRUE;
	}
	_H3API_ VOID H3Hero::DisassembleCombinationArtifact(INT slot)
	{
		INT32 artId = bodyArtifacts[slot].id;
		if (artId == -1)
			return;
		H3ArtifactSetup* art_setups = H3ArtifactSetup::Get();
		INT32 comboId = art_setups[artId].comboID;
		if (comboId == -1) // not a combo artifact
			return;
		RemoveArtifact(slot);
		INT32 numArts = H3ArtifactCount::Get();
		for (INT32 i = 0; i < numArts; ++i)
		{
			if (art_setups[i].combinationArtifactId == comboId)
			{
				H3Artifact art(i, -1);
				GiveArtifact(art);
			}
		}
	}
	_H3API_ INT32 H3Hero::CalculateSpellCost(INT spell, H3Army* opponentArmy, INT specialTerrain)
	{
		return THISCALL_4(INT32, 0x4E54B0, this, spell, opponentArmy, specialTerrain);
	}
	_H3API_ INT32 H3Hero::CalculateAdventureMapSpellCost(INT spell)
	{
		return CalculateSpellCost(spell, nullptr, GetSpecialSpellTerrain());
	}
	_H3API_ VOID H3Hero::RemoveSpellPointsAndRefresh(UINT16 spellPoints)
	{
		THISCALL_2(VOID, 0x4D9540, this, spellPoints);
	}
	_H3API_ VOID H3Hero::UpdateAvailableSpell()
	{
		THISCALL_1(VOID, 0x4D9840, this);
	}
	_H3API_ VOID H3Hero::Hide()
	{
		THISCALL_1(VOID, 0x4D7950, this);
	}
	_H3API_ VOID H3Hero::Show()
	{
		THISCALL_3(VOID, 0x4D7840, this, NH3Objects::eObjectTypes::HERO, id);
	}

	_H3API_ eCreature H3Hero::GetNecromancyCreatureId() const
	{
		return THISCALL_1(eCreature, 0x4E3ED0, this);
	}

	_H3API_ FLOAT H3Hero::GetNecromancyPower(BOOL8 clamp_value) const
	{
		return THISCALL_2(FLOAT, 0x4E3F40, this, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetSpellPointsRestored() const
	{
		return THISCALL_1(INT32, 0x4E41B0, this);
	}

	_H3API_ INT32 H3Hero::GetLuckBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const
	{
		return THISCALL_4(INT32, 0x4E3930, this, enemy_hero, is_cursed_ground, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetMoraleBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const
	{
		return THISCALL_4(INT32, 0x4E3C20, this, enemy_hero, is_cursed_ground, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetScoutingRadius() const
	{
		return THISCALL_1(INT32, 0x4E42E0, this);
	}

	_H3API_ FLOAT H3Hero::GetArcheryPower() const
	{
		return THISCALL_1(FLOAT, 0x4E43D0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetOffensePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4520, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetArmorerPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4580, this); // loads to FPU
	}

	_H3API_ INT32 H3Hero::GetGeneratedGold() const
	{
		return THISCALL_1(INT32, 0x4E4600, this);
	}

	_H3API_ FLOAT H3Hero::GetEagleEyePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4690, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetDiplomacyPower() const
	{
		return THISCALL_1(FLOAT, 0x4E47F0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetResistancePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4950, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetLearningPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4AB0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetIntelligencePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4B20, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetFirstAidPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4B90, this); // loads to FPU
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3Hero* H3Player::GetActiveHero()
	{
		return H3Main::Get()->GetHero(currentHero);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ UINT32 H3Main::Date::CurrentDay() const
	{
		return 28 * (month - 1) + 7 * (week - 1) + day - 1;
	}

	_H3API_ BOOL H3Main::HasUnderground() const
	{
		return mainSetup.hasUnderground;
	}
	_H3API_	H3MapItem* H3Main::GetMapItem(UINT32 mixedPosition)
	{
		return THISCALL_2(H3MapItem*, 0x42ED80, this, mixedPosition);
	}
	_H3API_ H3Player* H3Main::GetPlayer()
	{
		return THISCALL_1(H3Player*, 0x4CE670, this);
	}
	_H3API_ INT32 H3Main::GetPlayerID()
	{
		return THISCALL_1(INT32, 0x4CE6E0, this);
	}
	_H3API_ H3Hero* H3Main::GetHero(INT32 id)
	{
		return THISCALL_2(H3Hero*, 0x4317D0, this, id);
	}
	_H3API_ VOID H3Main::ResetRandomArtifacts()
	{
		libc::memset(randomArtifacts, 0, sizeof(randomArtifacts));
	}
	_H3API_ INT32 H3Main::GetRandomArtifactOfLevel(INT32 level)
	{
		return THISCALL_2(INT32, 0x4C9190, this, level);
	}
	_H3API_ VOID H3Main::SaveGame(LPCSTR save_name)
	{
		THISCALL_6(VOID, 0x4BEB60, this, save_name, 1, 1, 1, 0);
	}
	_H3API_ VOID H3Main::PlaceObjectOnMap(INT32 x, INT32 y, INT32 z, INT32 type, INT32 subtype, INT32 setup)
	{
		{ THISCALL_7(VOID, 0x4C9550, this, x, y, z, type, subtype, setup); }
	}
	_H3API_ VOID H3Main::RefreshMapItemAppearrance(H3MapItem* mi)
	{
		{ THISCALL_2(VOID, 0x4C9650, this, mi); }
	}
	_H3API_ H3Point H3Main::GetCoordinates(H3MapItem* item)
	{
		return mainSetup.GetCoordinates(item);
	}
	_H3API_ BOOL8 H3Main::IsHuman(INT32 player_id)
	{
		return THISCALL_2(BOOL8, 0x4CE600, this, player_id);
	}
	_H3API_ VOID H3Main::UpdateMapItemAppearance(H3MapItem* item)
	{
		THISCALL_2(VOID, 0x4C9650, this, item);
	}
	_H3API_ H3Map<H3MapItem> H3Main::GetMap()
	{
		return mainSetup.GetMap();
	}
	_H3API_ H3FastMap<H3MapItem> H3Main::GetFastMap()
	{
		return mainSetup.GetFastMap();
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ BOOL8 H3Network::Multiplayer()
	{
		return STDCALL_0(BOOL8, 0x4CE950);
	}

	_H3API_ VOID H3Network::SendMessageToPlayer(LPCSTR text, INT32 player_id)
	{
		FASTCALL_2(VOID, 0x554BB0, text, player_id);
	}

	_H3API_ VOID H3Network::SendMessageToPlayer(const H3String& text, INT32 player_id)
	{
		SendMessageToPlayer(text.String(), player_id);
	}

}

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ INT32 H3Spell::GetBaseEffect(INT32 level, INT32 spellPower)
	{
		return baseValue[level] + spellPower * spEffect;
	}
	_H3API_ BOOL8 H3Spell::SingleTarget(INT32 id, INT32 expertise)
	{
		return FASTCALL_2(BOOL8, 0x59E360, id, expertise);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ BOOL H3HeroSpecialty::HasSpellSpec() const
	{
		return type == eHeroSpecialty::SPEED;
	}
	_H3API_ eSpell H3HeroSpecialty::GetSpell() const
	{
		return eSpell(bonusId);
	}

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ BOOL H3Town::IsBuildingBuilt(INT32 id) const
	{
		return THISCALL_3(BOOL, 0x4305A0, this, id, id >= 32 ? 1 : 0);
	}
	_H3API_ LPCSTR H3Town::GetTownTypeName() const
	{
		return THISCALL_1(LPCSTR, 0x5C1850, this);
	}
	_H3API_ H3Hero* H3Town::GetGarrisonHero() const
	{
		return H3Main::Get()->GetHero(garrisonHero);
	}
	_H3API_ H3Hero* H3Town::GetVisitingHero() const
	{
		return H3Main::Get()->GetHero(visitingHero);
	}
	_H3API_ BOOL8 H3Town::IsMageGuildBuilt(INT level) const
	{
		return magicGuild[level];
	}
	_H3API_ H3String H3Town::GetNameAndType() const
	{
		H3String str(this->name);
		str.Append(", ").Append(GetTownTypeName());
		return str;
	}
	_H3API_ INT32 H3Town::GoldIncome(BOOL count_silo) const
	{
		return THISCALL_2(INT32, 0x5BFA00, this, count_silo ? 1 : 0);
	}
	_H3API_ H3Resources& H3Town::GetResourceSiloIncome() const
	{
		return THISCALL_1(H3Resources&, 0x5C1680, this);
	}
	_H3API_ H3TownCreatureTypes& H3Town::GetCreatureTypes() const
	{
		return H3TownCreatureTypes::Get()[type];
	}
	_H3API_ BOOL H3Town::CanBeBuilt(eBuildings id) const
	{
		return buildableMask.bitfield->GetState(int(id));
	}
	_H3API_ H3Resources H3Town::TotalIncome() const
	{
		H3Resources total;
		total.gold = GoldIncome(TRUE);
		total += GetResourceSiloIncome();
		return total;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ INT32& H3TownCreatureTypes::iterator::Base()
	{
		return *m_base;
	}
	_H3API_ H3TownCreatureTypes::iterator::iterator(INT32* base) :
		m_base(base)
	{
	}
	_H3API_ INT32& H3TownCreatureTypes::iterator::Upgraded()
	{
		return m_base[7];
	}
	_H3API_ H3TownCreatureTypes::iterator& H3TownCreatureTypes::iterator::operator*()
	{
		return *this;
	}
	_H3API_ H3TownCreatureTypes::iterator& H3TownCreatureTypes::iterator::operator++()
	{
		++m_base;
		return *this;
	}
	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::iterator::operator++(int)
	{
		iterator it(m_base);
		++m_base;
		return it;
	}
	_H3API_ BOOL H3TownCreatureTypes::iterator::operator==(const iterator& other) const
	{
		return m_base == other.m_base;
	}
	_H3API_ BOOL H3TownCreatureTypes::iterator::operator!=(const iterator& other) const
	{
		return m_base != other.m_base;
	}

	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::begin()
	{
		return iterator(base);
	}
	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::end()
	{
		return iterator(base + 7);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3BaseDlg::H3BaseDlg(INT x, INT y, INT w, INT h) :
		zOrder(-1), nextDialog(), lastDialog(), flags(0x12), state(),
		xDlg(x), yDlg(y), widthDlg(w), heightDlg(h), lastItem(), firstItem(),
		focusedItemId(-1), pcx16(), deactivatesCount()
	{
	}
	_H3API_ VOID H3BaseDlg::Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy)
	{
		H3WindowManager::Get()->H3Redraw(xDlg + x, yDlg + y, dx, dy);
	}
	_H3API_ VOID H3BaseDlg::Redraw()
	{
		vRedraw(TRUE, -65535, 65535);
	}
	_H3API_ INT32 H3BaseDlg::DefaultProc(H3Msg* msg)
	{
		return DefaultProc(*msg);
	}
	_H3API_ INT32 H3BaseDlg::DefaultProc(H3Msg& msg)
	{
		return THISCALL_2(INT32, 0x41B120, this, &msg);
	}
	_H3API_ H3DlgItem* H3BaseDlg::getDlgItem(UINT16 id, h3func vtable) const
	{
		H3DlgItem* it = firstItem;
		if (it == nullptr)
			return it;
		do
		{
			if ((it->GetID() == id) && (*reinterpret_cast<h3func*>(it) == vtable))
				break;
		} while (it = it->GetNextItem());

		return it;
	}
	_H3API_ INT32 H3BaseDlg::GetWidth() const
	{
		return widthDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetHeight() const
	{
		return heightDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetX() const
	{
		return xDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetY() const
	{
		return yDlg;
	}
	_H3API_ BOOL H3BaseDlg::IsTopDialog() const
	{
		return nextDialog == nullptr;
	}
	_H3API_ VOID H3BaseDlg::AddControlState(INT32 id, eControlState state)
	{
		THISCALL_3(VOID, 0x5FF490, this, id, state);
	}
	_H3API_ VOID H3BaseDlg::RemoveControlState(INT32 id, eControlState state)
	{
		THISCALL_3(VOID, 0x5FF520, this, id, state);
	}
	_H3API_ H3DlgItem* H3BaseDlg::AddItem(H3DlgItem* item, BOOL initiate /*= TRUE*/)
	{
		dlgItems += item;
		if (initiate)
			return THISCALL_3(H3DlgItem*, 0x5FF270, this, item, -1); // LoadItem
		else
			return item;
	}
	_H3API_ H3DlgDef* H3BaseDlg::GetDef(UINT16 id) const
	{
		return get<H3DlgDef>(id);
	}
	_H3API_ H3DlgPcx* H3BaseDlg::GetPcx(UINT16 id) const
	{
		return get<H3DlgPcx>(id);
	}
	_H3API_ H3DlgEdit* H3BaseDlg::GetEdit(UINT16 id) const
	{
		return get<H3DlgEdit>(id);
	}
	_H3API_ H3DlgText* H3BaseDlg::GetText(UINT16 id) const
	{
		return get<H3DlgText>(id);
	}
	_H3API_ H3DlgFrame* H3BaseDlg::GetFrame(UINT16 id) const
	{
		return get<H3DlgFrame>(id);
	}
	_H3API_ H3DlgPcx16* H3BaseDlg::GetPcx16(UINT16 id) const
	{
		return get<H3DlgPcx16>(id);
	}
	_H3API_ H3DlgTextPcx* H3BaseDlg::GetTextPcx(UINT16 id) const
	{
		return get<H3DlgTextPcx>(id);
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::GetDefButton(UINT16 id) const
	{
		return get<H3DlgDefButton>(id);
	}
	_H3API_ H3DlgScrollbar* H3BaseDlg::GetScrollbar(UINT16 id) const
	{
		return get<H3DlgScrollbar>(id);
	}
	_H3API_ H3DlgTransparentItem* H3BaseDlg::GetTransparent(UINT16 id) const
	{
		return get<H3DlgTransparentItem>(id);
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::GetCustomButton(UINT16 id) const
	{
		return get<H3DlgCustomButton>(id);
	}
	_H3API_ H3DlgCaptionButton* H3BaseDlg::GetCaptionButton(UINT16 id) const
	{
		return get<H3DlgCaptionButton>(id);
	}
	_H3API_ H3DlgScrollableText* H3BaseDlg::GetScrollableText(UINT16 id) const
	{
		return get<H3DlgScrollableText>(id);
	}
	_H3API_ H3DlgTransparentItem* H3BaseDlg::CreateHidden(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id)
	{
		H3DlgTransparentItem* it = H3DlgTransparentItem::Create(x, y, width, height, id);
		if (it)
			AddItem(it);
		return it;
	}
	_H3API_ H3LoadedPcx16* H3BaseDlg::GetCurrentPcx()
	{
		return pcx16;
	}
	_H3API_ H3DlgItem* H3BaseDlg::ItemAtPosition(H3Msg* msg)
	{
		return ItemAtPosition(*msg);
	}
	_H3API_ H3DlgItem* H3BaseDlg::ItemAtPosition(H3Msg& msg)
	{
		return THISCALL_3(H3DlgItem*, 0x5FF9A0, this, msg.GetX(), msg.GetY());
	}
	_H3API_ H3Vector<H3DlgItem*>& H3BaseDlg::GetList()
	{
		return dlgItems;
	}
	_H3API_ H3DlgItem* H3BaseDlg::GetH3DlgItem(UINT16 id)
	{
		return THISCALL_2(H3DlgItem*, 0x5FF5B0, this, id);
	}
	_H3API_ VOID H3BaseDlg::RedrawItem(UINT16 itemID)
	{
		if (H3DlgItem* it = GetH3DlgItem(itemID))
			it->Refresh();
	}
	_H3API_ VOID H3BaseDlg::EnableItem(UINT16 id, BOOL enable)
	{
		H3DlgItem* it = GetH3DlgItem(id);
		if (it)
			it->EnableItem(enable);
	}
	_H3API_ VOID H3BaseDlg::SendCommandToItem(INT32 command, UINT16 itemID, UINT32 parameter)
	{
		THISCALL_5(VOID, 0x5FF400, this, 0x200, command, itemID, parameter);
	}
	_H3API_ VOID H3BaseDlg::SendCommandToAllItems(INT32 command, INT32 itemID, INT32 parameter)
	{
		H3Msg msg;
		msg.SetCommand(eMsgCommand::ITEM_COMMAND, eMsgSubtype(command), itemID, eMsgFlag::NONE, 0, 0, parameter, 0);
		THISCALL_2(VOID, 0x5FF3A0, this, &msg);
	}
	_H3API_ VOID H3BaseDlg::AdjustToPlayerColor(INT8 player, UINT16 itemId)
	{
		if (H3DlgItem* it = GetH3DlgItem(itemId))
			it->ColorToPlayer(player);
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(x, y, width, height, id, color);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(x, y, width, height, 0, color);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(H3DlgItem* target, RGB565 color, INT id, BOOL around_edge)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(target, color, id, around_edge);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgDef* H3BaseDlg::CreateDef(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 group, INT32 mirror, BOOL closeDialog)
	{
		H3DlgDef* def = H3DlgDef::Create(x, y, width, height, id, defName, frame, group, mirror, closeDialog);
		if (def)
			AddItem(def);
		return def;
	}
	_H3API_ H3DlgDef* H3BaseDlg::CreateDef(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 group, INT32 mirror, BOOL closeDialog)
	{
		H3DlgDef* def = H3DlgDef::Create(x, y, id, defName, frame, group, mirror, closeDialog);
		if (def)
			AddItem(def);
		return def;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
	{
		H3DlgDefButton* but = H3DlgDefButton::Create(x, y, width, height, id, defName, frame, clickFrame, closeDialog, hotkey);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateButton(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
	{
		H3DlgDefButton* but = CreateButton(x, y, 0, 0, id, defName, frame, clickFrame, closeDialog, hotkey);
		if (but)
		{
			H3LoadedDef* def = but->GetDef();
			if (def)
			{
				but->SetWidth(def->widthDEF);
				but->SetHeight(def->heightDEF);
			}
		}
		return but;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOKButton(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::OK), NH3Dlg::Assets::OKAY_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateSaveButton(INT32 x, INT32 y, LPCSTR button_name)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::SAVE), button_name, 0, 1, FALSE, NH3VKey::H3VK_S);
		if (button)
		{
			AddItem(H3DlgFrame::Create(button, H3RGB565::Highlight(), 0, TRUE));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOnOffCheckbox(INT32 x, INT32 y, INT32 id, INT32 frame, INT32 clickFrame)
	{
		if (clickFrame == -1)
			clickFrame = 1 - frame;
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, id, NH3Dlg::Assets::ON_OFF_CHECKBOX, frame, clickFrame, 0, 0);
		if (button)
			AddItem(button);
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOKButton()
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(25, heightDlg - 50, int(eControlId::OK), NH3Dlg::Assets::OKAY_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(25 - 1, heightDlg - 50 - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOK32Button(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::OK), NH3Dlg::Assets::OKAY32_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_66_32_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateCancelButton()
	{
		return CreateCancelButton(widthDlg - 25 - 64, heightDlg - 50);
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateCancelButton(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, eControlId::CANCEL, NH3Dlg::Assets::CANCEL_DEF, 0, 1, TRUE, NH3VKey::H3VK_ESCAPE);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}

	_H3API_ H3DlgCaptionButton* H3BaseDlg::CreateCaptionButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* but = H3DlgCaptionButton::Create(x, y, width, height, id, defName, text, font, frame, group, closeDialog, hotkey, color);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		H3DlgCustomButton* but = H3DlgCustomButton::Create(x, y, width, height, id, defName, customProc, frame, clickFrame);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		H3DlgCustomButton* but = H3DlgCustomButton::Create(x, y, id, defName, customProc, frame, clickFrame);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		return CreateCustomButton(x, y, 0, defName, customProc, frame, clickFrame);
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreatePcx(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* pcx = H3DlgPcx::Create(x, y, width, height, id, pcxName);
		if (pcx)
			AddItem(pcx);
		return pcx;
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreatePcx(INT32 x, INT32 y, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* pcx = CreatePcx(x, y, 0, 0, id, pcxName);
		if (pcx && pcx->GetPcx())
		{
			H3LoadedPcx* p = pcx->GetPcx();
			pcx->SetWidth(p->width);
			pcx->SetHeight(p->height);
		}
		return pcx;
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreateLineSeparator(INT32 x, INT32 y, INT32 width)
	{
		return CreatePcx(x, y, width, 2, 0, NH3Dlg::HDassets::LINE_SEPARATOR);
	}
	_H3API_ H3DlgPcx16* H3BaseDlg::CreatePcx16(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx16* pcx = H3DlgPcx16::Create(x, y, width, height, id, pcxName);
		if (pcx)
			AddItem(pcx);
		return pcx;
	}
	_H3API_ H3DlgEdit* H3BaseDlg::CreateEdit(INT32 x, INT32 y, INT32 width, INT32 height, INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align, LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY)
	{
		H3DlgEdit* ed = H3DlgEdit::Create(x, y, width, height, maxLength, text, fontName, color, align, pcxName, id, hasBorder, borderX, borderY);
		if (ed)
			AddItem(ed);
		return ed;
	}
	_H3API_ H3DlgText* H3BaseDlg::CreateText(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName, INT32 color, INT32 id, eTextAlignment align, INT32 bkColor)
	{
		H3DlgText* tx = H3DlgText::Create(x, y, width, height, text, fontName, color, id, align, bkColor);
		if (tx)
			AddItem(tx);
		return tx;
	}
	_H3API_ H3DlgTextPcx* H3BaseDlg::CreateTextPcx(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id, INT32 align)
	{
		H3DlgTextPcx* tx = H3DlgTextPcx::Create(x, y, width, height, text, fontName, pcxName, color, id, align);
		if (tx)
			AddItem(tx);
		return tx;
	}
	_H3API_ H3DlgScrollableText* H3BaseDlg::CreateScrollableText(LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue)
	{
		H3DlgScrollableText* sc = H3DlgScrollableText::Create(text, x, y, width, height, font, color, isBlue);
		if (sc)
			AddItem(sc);
		return sc;
	}
	_H3API_ H3DlgScrollbar* H3BaseDlg::CreateScrollbar(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc, BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled)
	{
		H3DlgScrollbar* sc = H3DlgScrollbar::Create(x, y, width, height, id, ticksCount, scrollbarProc, isBlue, stepSize, arrowsEnabled);
		if (sc)
			AddItem(sc);
		return sc;
	}
	_H3API_ H3ExtendedDlg::H3ExtendedDlg(INT x, INT y, INT w, INT h) :
		H3BaseDlg(x, y, w, h)
	{
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3DlgBasePanel::backupScreen()
	{
		THISCALL_1(VOID, 0x5AA870, this);
	}
	_H3API_ VOID H3DlgBasePanel::restoreBackupScreen()
	{
		THISCALL_1(VOID, 0x5AA920, this);
	}

	_H3API_ H3Vector<H3DlgItem*>& H3DlgBasePanel::GetItems()
	{
		return items;
	}
	_H3API_ H3DlgItem* H3DlgBasePanel::AddItem(H3DlgItem* item)
	{
		item->HideDeactivate();
		items += item;
		return THISCALL_3(H3DlgItem*, 0x5AA7B0, this, item, -1);
	}
	_H3API_ VOID H3DlgBasePanel::Redraw()
	{
		for (H3DlgItem** i = items.begin(); i != items.end(); ++i)
		{
			H3DlgItem* it = *i;
			if (it->IsVisible())
				it->Draw();
		}
		H3WindowManager::Get()->H3Redraw(x + parent->GetX(), y + parent->GetY(), width, height);
	}
	_H3API_ VOID H3DlgBasePanel::Hide()
	{
		for (H3DlgItem** it = items.begin(); it != items.end(); ++it)
			(*it)->HideDeactivate();
		restoreBackupScreen();
	}
	_H3API_ VOID H3DlgBasePanel::Show()
	{
		if (backupPcx)
			return;
		backupScreen();
		for (H3DlgItem** it = items.begin(); it != items.end(); ++it)
			(*it)->ShowActivate();
		Redraw();
	}
	_H3API_ VOID H3DlgBasePanel::Move(INT xDest, INT yDest)
	{
		if (items.IsEmpty())
			return;

		const BOOL shown = backupPcx != nullptr;
		if (shown)
			Hide();

		const int dx = xDest - x;
		const int dy = yDest - y;
		x = xDest;
		y = yDest;

		for (H3DlgItem** i = items.begin(); i != items.end(); ++i)
		{
			H3DlgItem* it = *i;
			it->SetX(it->GetX() + dx);
			it->SetY(it->GetY() + dy);
		}

		if (shown)
			Show();
	}
	_H3API_ VOID H3DlgBasePanel::MoveRelative(INT xDest, INT yDest)
	{
		xDest -= parent->GetX();
		yDest -= parent->GetY();
		Move(xDest, yDest);
	}
	_H3API_ INT32 H3DlgBasePanel::GetWidth() const
	{
		return width;
	}
	_H3API_ INT32 H3DlgBasePanel::GetHeight() const
	{
		return height;
	}
	_H3API_ INT32 H3DlgBasePanel::GetX() const
	{
		return x;
	}
	_H3API_ INT32 H3DlgBasePanel::GetY() const
	{
		return y;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3CombatDlg::ShowHint(LPCSTR hint, BOOL8 add_to_log)
	{
		THISCALL_4(VOID, 0x4729D0, this, hint, add_to_log, 0);
	}
	_H3API_ H3Vector<H3String*>& H3CombatDlg::GetCombatText()
	{
		return combatText;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3NetworkDlg::H3NetworkDlg(INT x, INT y, INT w, INT h) :
		H3ExtendedDlg(x, y, w, h), lastHintShowed(-1),
		exitCommand(512), exitSubtype(10), resultItemId(30721), networkGame(FALSE)
	{
		struct unkNetwork
		{
			h3unk _f_00[0xF0];
			BYTE* data;
		};
		if (IntAt(0x69959C))
		{
			unkNetwork* net = *(unkNetwork**)0x69D858;
			if (net->data)
			{
				if (net->data[4])
					networkGame = TRUE;
				net->data[4] = 1;
			}
		}
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ INT H3Dlg::CheckEnd(H3Msg& msg)
	{
		if (endDialog)
			return msg.CloseDialog();
		return 0;
	}
	_H3API_ H3Dlg::H3Dlg(int width, int height, int x, int y, BOOL statusBar, BOOL makeBackground, INT32 colorIndex) :
		H3NetworkDlg(x, y, width, height),
		enableDoubleClick(FALSE), lastClickTime(), lastClickedItem(nullptr),
		endDialog(FALSE), background(nullptr), hintBar(nullptr)
	{
		STDCALL_0(VOID, 0x597AA0); // stop video animation
		if (x == -1)
			xDlg = (H3GameWidth::Get() - width) >> 1;
		if (y == -1)
			yDlg = (H3GameHeight::Get() - height) >> 1;

		if (makeBackground)
			AddBackground(TRUE, statusBar, colorIndex);
		if (statusBar)
			hintBar = CreateHint();
	}
	_H3API_ H3Dlg::~H3Dlg()
	{
		THISCALL_1(VOID, 0x5FFAD0, this); // destroy all dlg items
		if (background)
			this->background->Destroy(); // destroy background
		vDestroy();
		STDCALL_0(VOID, 0x597B50); // resume video animation
	}
	_H3API_ VOID H3Dlg::PlaceAtMouse()
	{
		H3POINT p = H3POINT::GetCursorPosition();
		xDlg = Clamp(0, p.x, H3GameWidth::Get() - widthDlg - 200);  // 200 is width of adventure bar on right
		yDlg = Clamp(0, p.y, H3GameHeight::Get() - heightDlg - 48); // 48 is height of resource bar on bottom
	}
	_H3API_ VOID H3Dlg::Start()
	{
		if (!OnCreate())
			return;

		H3MouseManager* mmgr   = H3MouseManager::Get();
		const INT32 mouseType  = mmgr->GetType();
		const INT32 mouseFrame = mmgr->GetFrame();
		mmgr->DefaultCursor();
		vShowAndRun(FALSE);
		mmgr->SetCursor(mouseFrame, mouseType); // restore previous cursor
	}
	_H3API_ VOID H3Dlg::Stop()
	{
		endDialog = TRUE;
	}
	_H3API_ VOID H3Dlg::RMB_Show()
	{
		THISCALL_1(VOID, 0x5F4B90, this);
	}
	_H3API_ BOOL H3Dlg::AddBackground(INT32 x, INT32 y, INT32 w, INT32 h, BOOL frame, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
	{
		if (this->background)
			return FALSE;

		if (frame && (w < 64 || h < 64))
			return FALSE;

		H3LoadedPcx16* pcx = H3LoadedPcx16::Create(h3_NullString, widthDlg, heightDlg);
		if (!pcx)
			return FALSE;

		H3DlgPcx16* bg = H3DlgPcx16::Create(x, y, w, h, 0, nullptr);
		if (!bg)
		{
			pcx->Destroy();
			return FALSE;
		}

		this->background = pcx;

		BackgroundRegion(x, y, w, h, is_blue);
		if (frame)
			FrameRegion(x, y, w, h, statusBar, colorIndex, is_blue);

		bg->SetPcx(pcx);
		AddItem(bg);
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(BOOL frame, BOOL statusBar, INT32 colorIndex)
	{
		return AddBackground(0, 0, widthDlg, heightDlg, frame, statusBar, colorIndex);
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx* pcx)
	{
		if (!pcx || background)
			return FALSE;
		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, pcx->width, pcx->height, background, 0, 0, FALSE);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx16* pcx)
	{
		if (!pcx || background)
			return FALSE;
		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, FALSE, background);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx24* pcx)
	{
		if (!pcx || background)
			return FALSE;

		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, background);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedDef* def, INT group, INT frame)
	{
		if (background || !def || def->groupsCount < group || !def->activeGroups[group])
			return FALSE;
		H3LoadedDef::DefGroup* grp = def->groups[group];
		if (grp->count < frame)
			return FALSE;

		H3DefFrame* fr = grp->frames[frame];

		background = H3LoadedPcx16::Create(h3_NullString, fr->frameWidth, fr->frameHeight);
		if (!background)
			return FALSE;

		fr->DrawToPcx16(0, 0, fr->frameWidth, fr->frameHeight, background, 0, 0, def->palette565);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, fr->frameWidth, fr->frameHeight, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::Notify(H3DlgItem* it, H3Msg& msg)
	{
		return OnNotify(it, msg);
	}
	_H3API_ VOID H3Dlg::EnableDoubleClick(BOOL state)
	{
		enableDoubleClick = state;
	}
	_H3API_ H3Dlg* H3Dlg::vDestroy()
	{
		THISCALL_1(VOID, 0x41B080, this);
		return this;
	}
	_H3API_ INT H3Dlg::vShow(INT zorder, BOOL8 draw)
	{
		return THISCALL_3(INT, 0x5FF0A0, this, zorder, draw);
	}
	_H3API_ INT H3Dlg::vHide(BOOL8 redrawScreen)
	{
		return THISCALL_2(INT, 0x5FF220, this, redrawScreen);
	}
	_H3API_ INT H3Dlg::vPreProcess(H3Msg& msg)
	{
		return vDialogProc(msg);
	}
	_H3API_ VOID H3Dlg::vParentActivate_10(H3DlgItem* unknown)
	{
	}
	_H3API_ BOOL8 H3Dlg::vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId)
	{
		return THISCALL_4(BOOL8, 0x5FF5E0, this, redrawScreen, minItemId, maxItemId);
	}
	_H3API_ INT H3Dlg::vShowAndRun(BOOL8 fadeIn)
	{
		return THISCALL_2(INT, 0x5FFA20, this, fadeIn);
	}
	_H3API_ INT H3Dlg::vInitiateItems()
	{
		return THISCALL_1(INT, 0x5FFB30, this);
	}
	_H3API_ INT H3Dlg::vActivateItems(BOOL8 increase)
	{
		return THISCALL_2(INT, 0x5FFBB0, this, increase);
	}
	_H3API_ BOOL8 H3Dlg::vOnMouseMove(INT32 x, INT32 y)
	{
		return THISCALL_3(BOOL8, 0x5FFCA0, this, x, y);
	}
	_H3API_ BOOL8 H3Dlg::vOnRightClick(INT32 id)
	{
		return THISCALL_2(BOOL8, 0x5FFD50, this, id);
	}
	_H3API_ BOOL8 H3Dlg::vOnLeftClick(INT32 id, BOOL8& closeDialog)
	{
		closeDialog = FALSE;
		return FALSE; // same as original function 0x5FFE90
	}
	_H3API_ H3DlgTextPcx* H3Dlg::vGetStatusBar()
	{
		return nullptr; // same as original 0x4842C0
	}
	_H3API_ INT H3Dlg::vEndDialogOnTimeExpired(H3Msg& msg)
	{
		return THISCALL_2(INT, 0x41B0F0, this, &msg);
	}
	_H3API_ H3LoadedPcx16* H3Dlg::GetBackgroundPcx() const
	{
		return background;
	}
	_H3API_ BOOL H3Dlg::BackgroundRegion(INT32 xStart, INT32 yStart, INT32 w, INT32 h, BOOL is_blue)
	{
		if (!background || w <= 0 || h <= 0)
			return FALSE;
		return background->BackgroundRegion(xStart, yStart, w, h, is_blue);
	}
	_H3API_ BOOL H3Dlg::SimpleFrameRegion(INT32 xStart, INT32 yStart, INT32 _width, INT32 _height, H3LoadedPcx16* destination)
	{
		H3LoadedPcx16* target = destination ? destination : background;
		if (!target)
			return FALSE;
		return target->SimpleFrameRegion(xStart, yStart, _width, _height);
	}
	_H3API_ BOOL H3Dlg::FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
	{
		if (!background)
			return FALSE;
		if (w < 64 || h < 64)
			return FALSE;
		return background->FrameRegion(x, y, w, h, statusBar, colorIndex, is_blue);
	}
	_H3API_ H3DlgHintBar* H3Dlg::GetHintBar()
	{
		return hintBar;
	}
	_H3API_ BOOL H3Dlg::CreateBlackBox(INT32 x, INT32 y, INT32 width, INT32 height)
	{
		if (!background)
			return FALSE;

		background->FillRectangle(x, y, width, height, 0, 0, 0);
		return TRUE;
	}
	_H3API_ H3DlgHintBar* H3Dlg::CreateHint()
	{
		H3DlgHintBar* h = H3DlgHintBar::Create(this);
		if (h)
			AddItem(h);
		return h;
	}
	_H3API_ H3DlgHintBar* H3Dlg::CreateHint(INT32 x, INT32 y, INT32 width, INT32 height)
	{
		H3DlgHintBar* h = H3DlgHintBar::Create(this, x, y, width, height);
		if (h)
			AddItem(h);
		return h;
	}
	_H3API_ INT H3Dlg::vDialogProc(H3Msg& msg)
	{
		H3DlgItem* it = nullptr;

		switch (msg.command)
		{
		case eMsgCommand::KEY_UP:
			if (OnKeyPress(msg.GetKey(), msg.GetFlag()))
				break;
			return CheckEnd(msg);
		case eMsgCommand::MOUSE_OVER:
			if (!OnMouseHover(msg.GetX(), msg.GetY()))
				return CheckEnd(msg);
			it = ItemAtPosition(msg);
			if (!it)
				break;

			if (hintBar && it->GetHint())
				hintBar->ShowMessage(it->GetHint());

			if (OnMouseHover(it))
				break;
			return CheckEnd(msg);
		case eMsgCommand::LCLICK_OUTSIDE:
			if (OnLeftClickOutside())
				break;
			return CheckEnd(msg);
		case eMsgCommand::RCLICK_OUTSIDE:
			if (OnRightClickOutside())
				break;
			return CheckEnd(msg);
		case eMsgCommand::KEY_HELD:
			if (OnKeyHeld(msg.GetKey(), msg.GetFlag()))
				break;
			return CheckEnd(msg);
		case eMsgCommand::MOUSE_BUTTON:
			switch (msg.subtype)
			{
			case eMsgSubtype::END_DIALOG:
				switch (msg.itemId)
				{
				case eControlId::OK:
					OnOK();
					break;
				case eControlId::CANCEL:
					OnCancel();
					break;
				default:
					OnClose(msg.itemId);
					break;
				}
				break;
			case eMsgSubtype::LBUTTON_CLICK:
			{
				it = ItemAtPosition(msg);
				if (enableDoubleClick)
				{
					DWORD curr_time = GetTime();
					if (it == lastClickedItem && (curr_time - lastClickTime < DOUBLE_CLICK_SPEED))
					{
						lastClickTime = curr_time;
						lastClickedItem = it;
						if (OnDoubleClick(msg.itemId, msg))
							break;
						return CheckEnd(msg);
					}
					lastClickTime = curr_time;
					lastClickedItem = it;
				}

				if (OnLeftClick(msg.itemId, msg))
					break;
				return CheckEnd(msg);
			}
			case eMsgSubtype::RBUTTON_DOWN:
				it = ItemAtPosition(msg);
				if (!it)
					break;
				if (OnRightClick(it))
					break;
				return CheckEnd(msg);
			default:
				break;
			}
			break;
		case eMsgCommand::MOUSE_WHEEL:
			if (OnMouseWheel(msg.subtype))
				break;
			return CheckEnd(msg);
		case eMsgCommand::WHEEL_BUTTON:
			if (msg.subtype == eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN)
			{
				it = ItemAtPosition(msg);
				if (!it)
					break;
				if (OnWheelButton(it))
					break;
				return CheckEnd(msg);
			}
			break;
		default:
			break;
		}

		if (endDialog)
			return msg.CloseDialog();

		if (DialogProc(msg))
			return DefaultProc(msg);

		return CheckEnd(msg);
	}
	_H3API_ VOID H3Dlg::OnOK()
	{
	}
	_H3API_ VOID H3Dlg::OnCancel()
	{
	}
	_H3API_ VOID H3Dlg::OnClose(INT itemId)
	{
	}
	_H3API_ BOOL H3Dlg::OnNotify(H3DlgItem* it, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::DialogProc(H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnLeftClick(INT itemId, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnLeftClickOutside()
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnRightClick(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnRightClickOutside()
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseWheel(INT direction)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnWheelButton(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseHover(INT32 x, INT32 y)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseHover(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnKeyPress(eVKey key, eMsgFlag flag)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnKeyHeld(eVKey key, eMsgFlag flag)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnDoubleClick(INT itemId, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnCreate()
	{
		return TRUE;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3HiScoreDlg::Show()
	{
		STDCALL_0(VOID, 0x4E91D0);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3Msg::SetCommand(eMsgCommand command, eMsgSubtype subtype, INT32 item_id, eMsgFlag flags, INT32 x, INT32 y, INT32 param, INT32 flags2)
	{
		this->command    = command;
		this->subtype    = subtype;
		this->itemId    = item_id;
		this->flags      = flags;
		this->position.x = x;
		this->position.y = y;
		this->parameter  = PVOID(param);
		this->parentDlg  = PVOID(flags2);
	}
	_H3API_ VOID H3Msg::SetCommand(INT32 cmd, INT32 param)
	{
		SetCommand(eMsgCommand::ITEM_COMMAND, eMsgSubtype(cmd), 0, eMsgFlag::NONE, 0, 0, param, 0);
	}
	_H3API_ H3DlgItem* H3Msg::ItemAtPosition(H3BaseDlg* dlg) const
	{
		return THISCALL_3(H3DlgItem*, 0x5FF9A0, dlg, position.x, position.y);
	}
	_H3API_ INT32 H3Msg::KeyPressed() const
	{
		return subtype;
	}
	_H3API_ BOOL H3Msg::IsKeyPress() const
	{
		return command == eMsgCommand::KEY_UP;
	}
	_H3API_ BOOL H3Msg::IsKeyDown() const
	{
		return command == eMsgCommand::KEY_DOWN;
	}
	_H3API_ BOOL H3Msg::IsKeyHeld() const
	{
		return command == eMsgCommand::KEY_HELD;
	}
	_H3API_ BOOL H3Msg::IsMouseOver() const
	{
		return command == eMsgCommand::MOUSE_OVER;
	}
	_H3API_ BOOL H3Msg::IsWheelButton() const
	{
		return command == eMsgCommand::WHEEL_BUTTON && subtype == eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::IsLeftClick() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::LBUTTON_CLICK;
	}
	_H3API_ BOOL H3Msg::IsLeftDown() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::LBUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::IsRightClick() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::RBUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::ClickOutside() const
	{
		return command == eMsgCommand::RCLICK_OUTSIDE || command == eMsgCommand::LCLICK_OUTSIDE;
	}
	_H3API_ BOOL H3Msg::IsAltPressed() const
	{
		return flags == eMsgFlag::ALT;
	}
	_H3API_ BOOL H3Msg::IsCtrlPressed() const
	{
		return flags == eMsgFlag::CTRL;
	}
	_H3API_ BOOL H3Msg::IsShiftPressed() const
	{
		return flags == eMsgFlag::SHIFT;
	}
	_H3API_ INT32 H3Msg::CloseDialog()
	{
		return STDCALL_1(INT32, 0x491640, this);
	}
	_H3API_ BOOL H3Msg::AltPressed() const
	{
		return flags & INT32(eMsgFlag::ALT);
	}
	_H3API_ BOOL H3Msg::CtrlPressed() const
	{
		return flags & INT32(eMsgFlag::CTRL);
	}
	_H3API_ BOOL H3Msg::ShiftPressed() const
	{
		return flags & INT32(eMsgFlag::SHIFT);
	}
	_H3API_ eMsgFlag H3Msg::GetFlag() const
	{
		return eMsgFlag(flags);
	}
	_H3API_ eVKey H3Msg::GetKey() const
	{
		return eVKey(subtype);
	}
	_H3API_ INT H3Msg::GetX() const
	{
		return position.x;
	}
	_H3API_ INT H3Msg::GetY() const
	{
		return position.y;
	}
	_H3API_ H3POINT H3Msg::GetCoords() const
	{
		return position;
	}
	_H3API_ H3BaseDlg* H3Msg::GetDlg() const
	{
		return reinterpret_cast<H3BaseDlg*>(parentDlg);
	}
	_H3API_ INT H3Msg::StopProcessing()
	{
		command = eMsgCommand::NONE;
		subtype = eMsgSubtype::NONE;
		return 2;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3Messagebox::Show(const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::Show(LPCSTR text, const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::OK, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::Show(const H3String& text, const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(text.String(), pic1, pic2, pic3);
	}
	_H3API_ H3Messagebox::H3Messagebox(LPCSTR message)
	{
		Show(message);
	}
	_H3API_ H3Messagebox::H3Messagebox(const H3String& message)
	{
		Show(message.String());
	}
	_H3API_ H3Messagebox::H3Messagebox()
	{
		Show();
	}
	_H3API_ VOID H3Messagebox::Display(const H3PictureVector& images, INT32 timeout /*= 0*/)
	{
		display(h3_TextBuffer, images, timeout);
	}
	_H3API_ VOID H3Messagebox::Display(LPCSTR text, const H3PictureVector& images, INT32 timeout)
	{
		display(text, images, timeout);
	}
	_H3API_ VOID H3Messagebox::Display(const H3String& text, const H3PictureVector& images, INT32 timeout)
	{
		display(text.String(), images, timeout);
	}
	_H3API_ BOOL H3Messagebox::Choice(const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return Choice(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ BOOL H3Messagebox::Choice(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return choice(text, pic1, pic2, pic3);
	}
	_H3API_ BOOL H3Messagebox::Choice(const H3String& text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return Choice(text.String(), pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::RIGHT_CLICK, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(const H3String& text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(text.String(), pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::show(LPCSTR text, eButtonType type, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		FASTCALL_12(VOID, 0x4F6C00, text,
			static_cast<INT32>(type), -1, -1,
			static_cast<INT32>(pic1.type), pic1.subtype,
			static_cast<INT32>(pic2.type), pic2.subtype,
			static_cast<INT32>(pic3.type), pic3.subtype,
			-1, 0);
	}
	_H3API_ VOID H3Messagebox::display(LPCSTR text, const H3PictureVector& images, INT32 timeout)
	{
		FASTCALL_5(VOID, 0x4F7D20, text, &images, -1, -1, timeout);
	}
	_H3API_ BOOL H3Messagebox::choice(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::OK_CANCEL, pic1, pic2, pic3);
		return H3WindowManager::Get()->ClickedOK();
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(LPCSTR text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		show(text, eButtonType::TAKE, pic1, pic2);
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_LEFT)
			return ePick::LEFT;
		return ePick::RIGHT; // no option for NONE in this mode
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(const H3String& text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Take(text.String(), pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Take(h3_TextBuffer, pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(LPCSTR text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		show(text, eButtonType::OPTION, pic1, pic2);
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_LEFT)
			return ePick::LEFT;
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_RIGHT)
			return ePick::RIGHT;
		return ePick::NONE; // clicked cancel
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(const H3String& text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Choose(text.String(), pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Choose(h3_TextBuffer, pic1, pic2);
	}
	_H3API_ H3PictureCategories::H3PictureCategories() :
		type(ePictureCategories::NONE), subtype(0)
	{
	}
	_H3API_ H3PictureCategories::H3PictureCategories(const H3PictureCategories& other) :
		type(other.type), subtype(other.subtype)
	{
	}
	_H3API_ H3PictureCategories::H3PictureCategories(ePictureCategories type, INT32 subtype) :
		type(type), subtype(subtype)
	{
	}
	_H3API_ H3PictureCategories H3PictureCategories::Resource(eResource type, INT32 amount)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(type), amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Artifact(eArtifact id)
	{
		return H3PictureCategories(ePictureCategories::ARTIFACT, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Spell(eSpell id)
	{
		return H3PictureCategories(ePictureCategories::SPELL, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Player(ePlayer id)
	{
		return H3PictureCategories(ePictureCategories::CREST, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Luck(INT32 amount)
	{
		if (amount < 0)
			return H3PictureCategories(ePictureCategories::NEUTRAL_LUCK, -amount);
		if (amount > 0)
			return H3PictureCategories(ePictureCategories::POSITIVE_LUCK, amount);
		return H3PictureCategories(ePictureCategories::NEUTRAL_LUCK, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Morale(INT32 amount)
	{
		if (amount < 0)
			return H3PictureCategories(ePictureCategories::NEUTRAL_MORALE, -amount);
		if (amount > 0)
			return H3PictureCategories(ePictureCategories::POSITIVE_MORALE, amount);
		return H3PictureCategories(ePictureCategories::NEUTRAL_MORALE, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Experience(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::EXPERIENCE, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::SecSkill(eSecondary skill, eSecSkillLevel level)
	{
		return H3PictureCategories(ePictureCategories::SECONDARY_SKILL,
			static_cast<INT32>(skill) * 3 + static_cast<INT32>(level) + 2);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Creature(eCreature id, UINT16 amount)
	{
		return H3PictureCategories(ePictureCategories::CREATURE, static_cast<UINT16>(id) | (amount << 16));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Building(eTown town_type, eBuildings building_id)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(static_cast<INT32>(town_type) +
			static_cast<INT32>(ePictureCategories::CASTLE_BUILDINGS)), building_id);
	}
	_H3API_ H3PictureCategories H3PictureCategories::PrimarySkill(ePrimary skill_type, INT8 amount)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(static_cast<INT32>(skill_type) +
			static_cast<INT32>(ePictureCategories::ATTACK)), amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::SpellPoints(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::SPELL_POINTS, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Money(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::MONEY, amount);
	}
	_H3API_ H3PictureCategories& H3PictureCategories::operator=(const H3PictureCategories& other)
	{
		type = other.type;
		subtype = other.subtype;
		return *this;
	}
}

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ BOOL8 H3ScreenChat::CheckExpiry()
	{
		return THISCALL_1(BOOL8, 0x5541B0, this);
	}
	_H3API_ VOID H3ScreenChat::Clear()
	{
		THISCALL_1(VOID, 0x5544B0, this);
	}
	_H3API_ VOID H3ScreenChat::ShowVA(LPCSTR format, ...)
	{
		va_list args;
		va_start(args, format);
		CDECL_VA(VOID, 0x553C40, format, args);
		va_end(args);
	}
	_H3API_ VOID H3ScreenChat::Show(LPCSTR text)
	{
		CDECL_3(VOID, 0x553C40, this, "%s", text);
	}
	_H3API_ VOID H3ScreenChat::Show(const H3String& text)
	{
		Show(text.String());
	}
	_H3API_ VOID H3ScreenChat::CheckTimeUpdate()
	{
		THISCALL_1(VOID, 0x5541F0, this);
	}
	_H3API_ VOID H3ScreenChat::SetCurrentTime()
	{
		THISCALL_1(VOID, 0x554450, this);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ H3ScenarioMapInformation& H3SelectScenarioDialog::CurrentMap()
	{
		return mapsInformation[selectedMapIndex];
	}
	_H3API_ VOID H3SelectScenarioDialog::UpdateForSelectedScenario(INT32 index, BOOL8 redraw)
	{
		THISCALL_3(VOID, 0x5857D0, this, index, redraw);
	}
	_H3API_ VOID H3SelectScenarioDialog::Redraw()
	{
		THISCALL_1(VOID, 0x584820, this);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3TownAlignmentDlg::H3TownAlignmentDlg(INT32 town)
	{
		THISCALL_2(H3TownAlignmentDlg&, CONSTRUCTOR, this, 1);
		INT32 frame = 2 * town + 2;
		H3DefLoader def(NH3Dlg::Assets::TOWN_SMALL);
		THISCALL_4(BOOL8, 0x5761C0, this, *def, frame, town);
		THISCALL_2(VOID, vtable->runDlg, this, 0); // no fade-in
	}
	_H3API_ H3TownAlignmentDlg::~H3TownAlignmentDlg()
	{
		THISCALL_1(VOID, DESTRUCTOR, this);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ INT HDDlg::CallHDProc(const H3Msg& msg)
	{
		return hdProc(this, msg);
	}
} /* namespace h3 */

namespace h3
{

	_H3API_ INT32 H3Manager::Start(INT32 z_order)
	{
		return THISCALL_2(INT32, vtable->start, this, z_order);
	}
	_H3API_ VOID H3Manager::Stop()
	{
		THISCALL_1(VOID, vtable->stop, this);
	}
	_H3API_ INT32 H3Manager::ProcessMessage(H3Msg& msg)
	{
		return THISCALL_2(INT32, vtable->processMessage, this, &msg);
	}
	_H3API_ VOID H3Manager::SetPreviousManager(H3Manager* prev)
	{
		parent = prev;
	}
	_H3API_ VOID H3Manager::SetNextManager(H3Manager* next)
	{
		child = next;
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem()
	{
		return THISCALL_2(H3MapItem*, 0x412B30, this, mousePosition.Mixed());
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(UINT32 mixedPos)
	{
		return THISCALL_2(H3MapItem*, 0x412B30, this, mixedPos);
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(INT32 x, INT32 y, INT32 z)
	{
		return THISCALL_4(H3MapItem*, 0x4086D0, map, x, y, z);
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(const H3Position& p)
	{
		return GetMapItem(p.Mixed());
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(const H3Point& p)
	{
		return GetMapItem(p.Pack());
	}
	_H3API_ UINT8 H3AdventureManager::GetX()
	{
		return mousePosition.GetX();
	}
	_H3API_ UINT8 H3AdventureManager::GetY()
	{
		return mousePosition.GetY();
	}
	_H3API_ UINT8 H3AdventureManager::GetZ()
	{
		return mousePosition.GetZ();
	}
	_H3API_ VOID H3AdventureManager::FullUpdate()
	{
		THISCALL_3(VOID, 0x417380, this, 1, 0);
	}
	_H3API_ VOID H3AdventureManager::MobilizeHero()
	{
		THISCALL_4(VOID, 0x417540, this, 0, 0, 0);
	}
	_H3API_ VOID H3AdventureManager::DemobilizeHero()
	{
		THISCALL_3(VOID, 0x4175E0, this, 0, 0);
	}
	_H3API_ VOID H3AdventureManager::MovementCalculationsMouse()
	{
		THISCALL_2(VOID, 0x419400, this, mousePosition.Mixed());
	}
	_H3API_ VOID H3AdventureManager::MovementCalculations(UINT32 mixedPosition)
	{
		THISCALL_2(VOID, 0x419400, this, mixedPosition);
	}
	_H3API_ VOID H3AdventureManager::MakeHeroPath()
	{
		THISCALL_4(VOID, 0x418D30, this, 1, 1, 1);
	}
	_H3API_ VOID H3AdventureManager::ShowCoordinates(UINT32 x, UINT32 y, UINT8 z)
	{
		if (x < H3MapSize::Get() && y < H3MapSize::Get())
		{
			UINT edge_x = H3GameEdgeHorizontal::Get();
			UINT edge_y = H3GameEdgeVertical::Get();
			UINT dx = x - (screenPosition.GetX() - edge_x);
			UINT dy = y - (screenPosition.GetY() - edge_y);
			DemobilizeHero();
			screenPosition.SetXYZ(edge_x + x, edge_y + y, z);
			FullUpdate(); // force immediate redraw
			mousePosition.SetXYZ(mousePosition.GetX() + dx, mousePosition.GetY() + dy, z); // update cursor position
		}
	}
	_H3API_ INT H3AdventureManager::SimulateMouseOver(INT x, INT y)
	{
		return THISCALL_3(int, 0x40E2C0, this, x, y);
	}
	_H3API_ INT H3AdventureManager::SimulateMouseOver(POINT& p)
	{
		return SimulateMouseOver(p.x, p.y);
	}
	_H3API_ CHAR H3AdventureManager::UpdateHintMessage()
	{
		return THISCALL_5(CHAR, 0x40B0B0, this, GetMapItem(), GetX(), GetY(), GetZ());
	}
	_H3API_ H3Point H3AdventureManager::GetCoordinates(H3MapItem* item)
	{
		return map->GetCoordinates(item);
	}
	_H3API_ VOID H3AdventureManager::StopSound(H3WavFile* wav)
	{
		THISCALL_2(VOID, 0x59A180, this, wav->hSample);
	}
	_H3API_ H3Map<H3MapItem> H3AdventureManager::GetMap()
	{
		return map->GetMap();
	}
	_H3API_ H3FastMap<H3MapItem> H3AdventureManager::GetFastMap()
	{
		return map->GetFastMap();
	}
	_H3API_ H3Map<UINT16> H3AdventureManager::GetPathMap()
	{
		return H3Map<UINT16>(arrowPathFrames, H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
	}
	_H3API_ H3FastMap<UINT16> H3AdventureManager::GetPathFastMap()
	{
		return H3FastMap<UINT16>(arrowPathFrames, H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
	}

	_H3API_ INT32 H3AdventureManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(1);
		return 2;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3CombatManager::SimulateMouseAtHex(INT32 hex_id)
	{
		return THISCALL_2(VOID, 0x477550, this, hex_id);
	}
	_H3API_ BOOL8 H3CombatManager::CanCastSpellAtCoord(INT32 spell_id, INT32 spell_expertise, INT32 coordinates)
	{
		return THISCALL_7(BOOL8, 0x5A3CD0, this, spell_id, spell_expertise, coordinates, currentActiveSide, 1, 0);
	}
	_H3API_ VOID H3CombatManager::WinBattle()
	{
		return THISCALL_2(VOID, 0x468F80, this, 1 - currentActiveSide);
	}
	_H3API_ VOID H3CombatManager::LoadSpell(INT32 spell_id)
	{
		return THISCALL_3(VOID, 0x59EF60, this, spell_id, 0);
	}
	_H3API_ VOID H3CombatManager::CastSpell(INT32 spell_id, INT32 hex_ix, INT32 cast_type_012, INT32 hex2_ix, INT32 skill_level, INT32 spell_power)
	{
		THISCALL_7(VOID, 0x5A0140, this, spell_id, hex_ix, cast_type_012, hex2_ix, skill_level, spell_power);
	}
	_H3API_ INT32 H3CombatManager::SquareAtCoordinates(const H3POINT& p) const
	{
		return SquareAtCoordinates(p.x, p.y);
	}
	_H3API_ INT32 H3CombatManager::SquareAtCoordinates(INT32 x, INT32 y) const
	{
		return THISCALL_3(INT32, 0x464380, this, x, y);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetResurrectionTarget(INT32 coordinate, INT32 caster_kind)
	{
		return THISCALL_4(H3CombatMonster*, 0x5A3FD0, this, currentActiveSide, coordinate, caster_kind);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetAnimateDeadTarget(INT32 coordinate)
	{
		return THISCALL_3(H3CombatMonster*, 0x5A4260, this, currentActiveSide, coordinate);
	}
	_H3API_ INT32 H3CombatManager::NextCreatureToMove()
	{
		return THISCALL_2(int, 0x464C60, this, 1);
	}
	_H3API_ BOOL8 H3CombatManager::IsHiddenBattle()
	{
		return THISCALL_1(BOOL8, 0x46A080, this);
	}
	_H3API_ BOOL8 H3CombatManager::IsBattleOver()
	{
		return THISCALL_1(BOOL8, 0x465410, this);
    }
    _H3API_ VOID H3CombatManager::ApplyAnimationToLastHitArmy(INT32 animationIndex, BOOL resetAnimationWhenDone)
    {
        THISCALL_3(BOOL8, 0x468570, this, animationIndex, resetAnimationWhenDone);
    }
	_H3API_ VOID H3CombatManager::AddNecromancyRaisedCreature(INT32 side)
	{
		THISCALL_2(VOID, 0x469B00, this, side);
	}
	_H3API_ VOID H3CombatManager::Refresh()
	{
		Refresh(1, 0, 1);
	}
	_H3API_ VOID H3CombatManager::Refresh(BOOL redrawScreen, INT timeDelay, BOOL redrawBackground)
	{
		THISCALL_7(VOID, 0x493FC0, this, redrawScreen, 0, 0, timeDelay, redrawBackground, 0);
	}
	_H3API_ VOID H3CombatManager::RefreshCreatures()
	{
		THISCALL_1(VOID, 0x495770, this);
	}
	_H3API_ VOID H3CombatManager::ShadeSquare(INT32 index)
	{
		if (index < 0 || index > 187)
			return;
		H3CombatSquare* sq = &squares[index];
		CCellShdPcx->DrawToPcx16(0, 0, 0x2D, 0x34, drawBuffer, sq->left, sq->top, TRUE); // copied from 0x4935B9 and below
	}
	_H3API_ BOOL8 H3CombatManager::IsHumanTurn()
	{
		return isHuman[currentActiveSide];
	}
	_H3API_ VOID H3CombatManager::AddStatusMessage(LPCSTR message, BOOL permanent)
	{
		THISCALL_4(VOID, 0x4729D0, dlg, message, permanent, 0);
	}
	_H3API_ VOID H3CombatManager::PlayMagicAnimation(INT32 id, H3CombatCreature* target, INT32 timeStep, BOOL8 show_hit)
	{
		THISCALL_5(VOID, 0x4963C0, this, id, target, timeStep, show_hit);
	}
    _H3API_ VOID H3CombatManager::ReportDamageDone(LPCSTR attackerName, INT32 numAttackers, INT32 damageDone, H3CombatCreature* target, INT32 killedCount)
	{
        THISCALL_6(VOID, 0x469670, this, attackerName, numAttackers, damageDone, target, killedCount);
	}
	_H3API_ BOOL8 H3CombatManager::ShouldCastSpellAfterHit(INT32 spellId, INT32 side, H3CombatCreature* target)
	{
		return THISCALL_6(BOOL8, 0x5A8950, this, spellId, side, target, 1, 1);
	}
	_H3API_ VOID H3CombatManager::ResurrectTarget(H3CombatCreature* target, INT32 hitPoints, INT32 isTemporary)
	{
		THISCALL_4(VOID, 0x5A7870, this, target, hitPoints, isTemporary);
    }
    _H3API_ INT32 H3CombatManager::CalculateSpellDamageOnTarget(INT32 damage, INT32 spellId, H3Hero* atkHero, H3Hero* defHero, H3CombatCreature* target, BOOL showLog)
    {
        return THISCALL_7(INT32, 0x5A7BF0, this, damage, spellId, atkHero, defHero, target, showLog);
    }
	_H3API_ H3CombatMonster* H3CombatManager::SummonCreature(INT32 side, INT32 creatureId, INT32 amount, INT32 position, INT32 redrawAnimation, BOOL redraw)
	{
		return THISCALL_7(H3CombatMonster*, 0x479A30, this, side, creatureId, amount, position, redrawAnimation, redraw);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetSummonDemonTarget(INT32 side, INT32 coordinate)
	{
		return THISCALL_3(H3CombatMonster*, 0x5A4150, this, side, coordinate);
	}
	_H3API_ VOID H3CombatManager::RaiseDemon(H3CombatCreature* caster, H3CombatCreature* target)
	{
		THISCALL_3(VOID, 0x5A76A0, this, caster, target);
	}
	_H3API_ BOOL8 H3CombatManager::CanApplyCreatureSpell(INT32 spell_id, INT32 creature_side, H3CombatCreature* target)
	{
		return THISCALL_6(BOOL8, 0x5A8950, this, spell_id, creature_side, target, 1, 1); // the last 2 parameters are always 1 and 1
	}
	_H3API_ VOID H3CombatManager::DrawRay(BOOL redraw, INT startX, INT startY, INT dstX, INT dstY, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay)
	{
		THISCALL_18(VOID, 0x5A5F30, this, redraw, startX, startY, dstX, dstY, allowBranches, randomnessRange, startThickness, endThickness, color565, amplitude, arching, rayStraightness, smoothness, pathRandomness, timeDelay, 0);
	}
	_H3API_ VOID H3CombatManager::DrawRay(BOOL redraw, H3CombatCreature* start, H3CombatCreature* end, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay)
	{
		DrawRay(redraw, start->GetX(), start->GetY(), end->GetX(), end->GetY(), allowBranches, randomnessRange, startThickness, endThickness, color565, amplitude, arching, rayStraightness, smoothness, pathRandomness, timeDelay);
	}
	_H3API_ VOID H3CombatManager::AnimateMassSpell(INT32 animation_id, BOOL8 affects_both_sides)
	{
		THISCALL_4(VOID, 0x5A6AD0, this, massSpellTarget, animation_id, affects_both_sides);
	}
	_H3API_ INT32 H3CombatManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(1);
		return 2;
	}

	_H3API_ BOOL H3CombatManager::CanSummonOrClone() const
	{
		INT i = 0;
		const H3CombatMonster* mon = stacks[currentActiveSide];
		while (mon->type != eCreature::UNDEFINED)
		{
			if (!mon->numberAlive && mon->info.cannotMove && mon->IsSummon())
				break;
			++mon;
			if (++i >= 20)
				return FALSE;
		}
		return TRUE;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3ExecutiveMgr::RemoveManager(H3Manager* mgr)
	{
		THISCALL_2(VOID, 0x4B0950, this, mgr);
	}
	_H3API_ INT H3ExecutiveMgr::AddManager(H3Manager* mgr, INT32 order)
	{
		return THISCALL_3(INT, 0x4B0880, this, mgr, order);
	}
	_H3API_ VOID H3ExecutiveMgr::StartManager(H3Manager* mgr)
	{
		THISCALL_2(VOID, 0x4B0770, this, mgr);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3HiScoreManager::ResetScores()
	{
		THISCALL_1(VOID, 0x4E9070, this);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3InputManager::InputMessages& H3InputManager::GetCurrentMessage()
	{
		return messages[currentMessage];
	}
	_H3API_ VOID H3InputManager::AddMouseOverMessage()
	{
		return THISCALL_1(VOID, 0x4ECD00, this);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3MouseManager::operator=(const Cursor& cursor)
	{
		SetCursor(cursor);
	}
	_H3API_ VOID H3MouseManager::TurnOn()
	{
		THISCALL_2(VOID, 0x50D7B0, this, 1);
	}
	_H3API_ VOID H3MouseManager::TurnOff()
	{
		THISCALL_2(VOID, 0x50D7B0, this, 0);
	}
	_H3API_ INT32 H3MouseManager::GetType() const
	{
		return cursorType;
	}
	_H3API_ INT32 H3MouseManager::GetFrame() const
	{
		return cursorFrame;
	}
	_H3API_ VOID H3MouseManager::SetCursor(INT32 frame, INT32 type)
	{
		THISCALL_3(VOID, 0x50CEA0, this, frame, type);
	}
	_H3API_ VOID H3MouseManager::SetCursor(const Cursor& cursor)
	{
		SetCursor(cursor.frame, cursor.type);
	}
	_H3API_ VOID H3MouseManager::SetCursor(INT32 frame, eCursor type)
	{
		THISCALL_3(VOID, 0x50CEA0, this, frame, type);
	}
	_H3API_ VOID H3MouseManager::DefaultCursor()
	{
		SetCursor(0, 0);
	}
	_H3API_ VOID H3MouseManager::SetArtifactCursor(INT32 art_id)
	{
		SetCursor(art_id, eCursor::ARTIFACT);
	}
	_H3API_ H3MouseManager::Cursor H3MouseManager::CurrentCursor() const
	{
		Cursor cursor;
		cursor.type = cursorType;
		cursor.frame = cursorFrame;
		return cursor;
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0)
	{
		initialize(army, is_summoning_portal, type0, &amount0, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1, INT32 type2, INT16& amount2)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, type2, &amount2, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1, INT32 type2, INT16& amount2, INT32 type3, INT16& amount3)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, type2, &amount2, type3, &amount3);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0)
	{
		initialize(hero, type0, &amount0, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1)
	{
		initialize(hero, type0, &amount0, type1, &amount1, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
		INT32 type2, INT16& amount2)
	{
		initialize(hero, type0, &amount0, type1, &amount1, type2, &amount2, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
		INT32 type2, INT16& amount2, INT32 type3, INT16& amount3)
	{
		initialize(hero, type0, &amount0, type1, &amount1, type2, &amount2, type3, &amount3);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, H3CreatureSlot16& slot0,
		H3CreatureSlot16& slot1, H3CreatureSlot16& slot2, H3CreatureSlot16& slot3)
	{
		initialize(army, is_summoning_portal, slot0.type, &slot0.amount, slot1.type, &slot1.amount,
			slot2.type, &slot2.amount, slot3.type, &slot3.amount);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, H3Generator& g)
	{
		initialize(army, FALSE, g.creatureTypes[0], &g.creatureCounts[0], g.creatureTypes[1], &g.creatureCounts[1],
			g.creatureTypes[2], &g.creatureCounts[2], g.creatureTypes[3], &g.creatureCounts[3]);
	}
	_H3API_ VOID H3RecruitMgr::Run()
	{
		H3ExecutiveMgr::Get()->StartManager(this);
	}
	_H3API_ H3RecruitMgr& H3RecruitMgr::initialize(H3Army& army, BOOL8 is_summoning_portal,
		INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
		INT32 type2, INT16* amount2, INT32 type3, INT16* amount3)
	{
		return THISCALL_11(H3RecruitMgr&, 0x551750, this, &army, is_summoning_portal, type0, amount0,
			type1, amount1, type2, amount2, type3, amount3);
	}
	_H3API_ H3RecruitMgr& H3RecruitMgr::initialize(H3Hero* hero, INT32 type0, INT16* amount0, INT32 type1,
		INT16* amount1, INT32 type2, INT16* amount2, INT32 type3, INT16* amount3)
	{
		return THISCALL_10(H3RecruitMgr&, 0x551860, this, hero, type0, amount0,
			type1, amount1, type2, amount2, type3, amount3);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3SoundManager::ClickSound()
	{
		INT32 backup = clickSoundVar;
		H3WavFile* button_wav = H3ButtonWav::Get();
		button_wav->spinCount = 64;
		button_wav->debugInfo = PRTL_CRITICAL_SECTION_DEBUG(1);
		button_wav->lockSemaphore = HANDLE(HANDLE_FLAG_PROTECT_FROM_CLOSE | HANDLE_FLAG_INHERIT);
		THISCALL_2(VOID, 0x59A510, this, button_wav);
		clickSoundVar = backup;
	}
#pragma push_macro("PlaySound")
#ifdef PlaySound
#undef PlaySound
#endif

	_H3API_ VOID H3SoundManager::Play(H3WavFile* wav)
	{
		THISCALL_2(VOID, 0x59A510, this, wav);
	}
	_H3API_ VOID H3SoundManager::Play(LPCSTR wav_name)
	{
		H3WavLoader wav(wav_name);
		if (wav)
			Play(*wav);
	}
	_H3API_ VOID H3SoundManager::PlaySoundAndWait(LPCSTR wav_name, INT milliseconds)
	{
		H3WavLoader wav(wav_name);
		if (!wav)
			return;
		Play(*wav);
		THISCALL_3(VOID, 0x59A7C0, milliseconds, *wav, wav->hSample);
	}

	_H3API_ VOID H3SoundManager::PlaySoundAsync(LPCSTR wav_name, INT32 duration /*= -1*/)
	{
		FASTCALL_3(VOID, 0x59A890, wav_name, duration, 3);
    }

    _H3API_ INT64 H3SoundManager::PlaySoundByFileAsync(LPCSTR wav_name)
    {
        return FASTCALL_1(INT64, 0x59A770, wav_name);
    }

#pragma pop_macro("PlaySound")
} /* namespace h3 */

namespace h3
{
	_H3API_ INT32 H3SwapManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(4);
		return 2;
	}
	_H3API_ VOID H3SwapManager::UpdateLuckMorale()
	{
		THISCALL_1(VOID, 0x5AE900, this);
	}
	_H3API_ VOID H3SwapManager::RefreshDialog()
	{
		THISCALL_1(VOID, 0x5B1200, this);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3TownManager::Draw()
	{
		THISCALL_1(VOID, 0x5D5930, this);
	}
	_H3API_ VOID H3TownManager::RefreshScreen()
	{
		THISCALL_1(VOID, 0x5D5810, this);
	}
	_H3API_ BOOL8 H3TownManager::ViewTavern()
	{
		return THISCALL_1(BOOL8, 0x5D82C0, this);
	}
} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3WindowManager::H3Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy)
	{
		THISCALL_5(VOID, 0x603190, this, x, y, dx, dy);
	}
	_H3API_ INT32 H3WindowManager::ClickedItemID() const
	{
		return resultItemID;
	}
	_H3API_ VOID H3WindowManager::SetClickedItemId(INT32 id)
	{
		resultItemID = id;
	}
	_H3API_ BOOL H3WindowManager::ClickedOK() const
	{
		return resultItemID == eControlId::OK;
	}
	_H3API_ BOOL H3WindowManager::ClickedCancel() const
	{
		return resultItemID == eControlId::CANCEL;
	}
	_H3API_ H3LoadedPcx16* H3WindowManager::GetDrawBuffer()
	{
		return screenPcx16;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ BOOL H3DlgItem::NotifyParent(H3Msg& msg)
    {
        return reinterpret_cast<H3Dlg*>(parent)->Notify(this, msg);
    }
    _H3API_ BOOL H3DlgItem::TranslateUnprocessedMessage(H3Msg& msg)
    {
        switch (msg.command)
        {
        case eMsgCommand::WHEEL_BUTTON:
            if (msg.subtype != eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN ||
                msg.subtype != eMsgSubtype::MOUSE_WHEEL_BUTTON_UP)
                break;
        case eMsgCommand::MOUSE_WHEEL:
        {
            if (deactivatesCount > 0)
                break;
            if (!IsActive())
                break;
            const int x = msg.GetX() - parent->GetX();
            const int y = msg.GetY() - parent->GetY();
            if ((x < GetX()) || (y < GetY()) || (x >= GetX() + GetWidth()) || (y >= GetY() + GetHeight()))
                break;
            return NotifyParent(msg);
        }
        default:
            break;
        }
        return FALSE;
    }

    _H3API_ VOID H3DlgItem::EnableItem(BOOL enable)
    {
        vEnable(enable);
    }
    _H3API_ VOID H3DlgItem::Enable()
    {
        EnableItem(TRUE);
    }
    _H3API_ VOID H3DlgItem::Disable()
    {
        EnableItem(FALSE);
    }
    _H3API_ INT16 H3DlgItem::GetX() const
    {
        return xPos;
    }
    _H3API_ INT16 H3DlgItem::GetY() const
    {
        return yPos;
    }
    _H3API_ INT32 H3DlgItem::GetAbsoluteX() const
    {
        return xPos + parent->GetX();
    }
    _H3API_ INT32 H3DlgItem::GetAbsoluteY() const
    {
        return yPos + parent->GetY();
    }
    _H3API_ BOOL H3DlgItem::IsEnabled() const
    {
        return !(state & 0x20);
    }
    _H3API_ BOOL H3DlgItem::IsActive() const
    {
        return state & eControlState::ACTIVE;
    }
    _H3API_ VOID H3DlgItem::SetX(UINT16 x)
    {
        xPos = x;
    }
    _H3API_ VOID H3DlgItem::SetY(UINT16 y)
    {
        yPos = y;
    }
    _H3API_ INT32 H3DlgItem::GetHeight() const
    {
        return heightItem;
    }
    _H3API_ INT32 H3DlgItem::GetWidth() const
    {
        return widthItem;
    }
    _H3API_ VOID H3DlgItem::SetWidth(UINT16 w)
    {
        widthItem = w;
    }
    _H3API_ VOID H3DlgItem::SetHeight(UINT16 h)
    {
        heightItem = h;
    }
    _H3API_ VOID H3DlgItem::Draw()
    {
        vDrawToWindow();
    }
    _H3API_ VOID H3DlgItem::Refresh()
    {
        parent->Redraw(xPos, yPos, widthItem, heightItem);
    }
    _H3API_ H3DlgItem* H3DlgItem::Hide()
    {
        RemoveState(eControlState::VISIBLE);
        return this;
    }
    _H3API_ VOID H3DlgItem::HideDeactivate()
    {
        RemoveState(eControlState::ACTIVE | eControlState::VISIBLE);
    }
    _H3API_ VOID H3DlgItem::ShowActivate()
    {
        AddState(eControlState::ACTIVE | eControlState::VISIBLE);
    }
    _H3API_ H3DlgItem* H3DlgItem::Show()
    {
        AddState(eControlState::VISIBLE);
        return this;
    }
    _H3API_ VOID H3DlgItem::Shade()
    {
        AddState(eControlState::SHADED);
    }
    _H3API_ VOID H3DlgItem::UnShade()
    {
        RemoveState(eControlState::SHADED);
    }
    _H3API_ H3DlgItem* H3DlgItem::Activate()
    {
        AddState(eControlState::ACTIVE);
        return this;
    }
    _H3API_ H3DlgItem* H3DlgItem::DeActivate()
    {
        RemoveState(eControlState::ACTIVE);
        return this;
    }
    _H3API_ BOOL H3DlgItem::IsVisible() const
    {
        return IsSet(eControlState::VISIBLE);
    }
    _H3API_ BOOL H3DlgItem::IsSet(eControlState state) const
    {
        return this->state & state;
    }
    _H3API_ VOID H3DlgItem::AddState(eControlState state)
    {
        this->state |= state;
    }
    _H3API_ VOID H3DlgItem::RemoveState(eControlState state)
    {
        this->state &= eControlState(~state);
    }
    _H3API_ LPCSTR H3DlgItem::GetHint() const
    {
        return hint;
    }
    _H3API_ VOID H3DlgItem::SetHint(LPCSTR msg)
    {
        hint = msg;
    }
    _H3API_ UINT16 H3DlgItem::GetID() const
    {
        return id;
    }
    _H3API_ VOID H3DlgItem::ParentRedraw()
    {
        parent->Redraw(xPos, yPos, widthItem, heightItem);
    }
    _H3API_ VOID H3DlgItem::ColorToPlayer(INT8 player)
    {
        THISCALL_2(VOID, 0x4501D0, this, player);
    }
    _H3API_ VOID H3DlgItem::SendCommand(INT32 command, INT32 parameter)
    {
        THISCALL_3(VOID, 0x5FED80, this, command, parameter);
    }
    _H3API_ VOID H3DlgItem::SetHints(LPCSTR shortTipText, LPCSTR rightClickHint, BOOL allocateMemory)
    {
        THISCALL_4(void, 0x5FEE00, this, shortTipText, rightClickHint, allocateMemory);
    }
    _H3API_ VOID H3DlgItem::DrawTempFrame(INT thickness, BYTE r, BYTE g, BYTE b) const
    {
        H3LoadedPcx16* pcx = H3WindowManager::Get()->GetDrawBuffer();
        if (!pcx)
            return;
        pcx->DrawThickFrame(GetAbsoluteX(), GetAbsoluteY(), GetWidth(), GetHeight(), thickness, r, g, b);
    }
    _H3API_ VOID H3DlgItem::DrawTempFrame(INT thickness, const H3RGB888& color) const
    {
        DrawTempFrame(thickness, color.r, color.g, color.b);
    }
    _H3API_ H3BaseDlg* H3DlgItem::GetParent() const
    {
        return parent;
    }
    _H3API_ H3DlgItem* H3DlgItem::GetNextItem() const
    {
        return nextDlgItem;
    }
    _H3API_ H3DlgItem* H3DlgItem::GetPreviousItem() const
    {
        return previousDlgItem;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ INT H3DlgDefButton::ToggleFrame()
    {
        std::swap(defFrame, defFrameOnClick);
        return defFrame;
    }
    _H3API_ INT32 H3DlgDefButton::GetFrame() const
    {
        return defFrame;
    }
    _H3API_ INT32 H3DlgDefButton::GetClickFrame() const
    {
        return defFrameOnClick;
    }
    _H3API_ VOID H3DlgDefButton::ColorDefToPlayer(INT32 id)
    {
        loadedDef->ColorToPlayer(id);
    }
    _H3API_	VOID H3DlgDefButton::SetFrame(INT32 frame)
    {
        defFrame = frame;
    }
    _H3API_ VOID H3DlgDefButton::SetClickFrame(INT32 clickFrame)
    {
        defFrameOnClick = clickFrame;
    }
    _H3API_ H3LoadedDef* H3DlgDefButton::GetDef()
    {
        return loadedDef;
    }
    _H3API_ VOID H3DlgDefButton::AddHotkey(INT32 key)
    {
        hotkeys.Add(key);
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
    {
        H3DlgDefButton* b = H3ObjectAllocator<H3DlgDefButton>().allocate(1);
        if (b)
            THISCALL_12(H3DlgDefButton*, 0x455BD0, b, x, y, width, height, id, defName, frame, clickFrame, closeDialog, hotkey, 2);
        return b;
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
    {
        H3DlgDefButton* b = Create(x, y, 0, 0, id, defName, frame, clickFrame, closeDialog, hotkey);
        if (b && b->loadedDef)
        {
            b->widthItem  = b->loadedDef->widthDEF;
            b->heightItem = b->loadedDef->heightDEF;
        }
        return b;
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 clickFrame)
    {
        return Create(x, y, 0, defName, frame, clickFrame, 0, 0);
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgCaptionButton* H3DlgCaptionButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* b = H3ObjectAllocator<H3DlgCaptionButton>().allocate(1);
		if (b)
			THISCALL_15(H3DlgCaptionButton*, 0x456730, b, x, y, width, height, id, defName, text, font, frame, group, closeDialog, hotkey, 2, color);
		return b;
	}
	_H3API_ H3DlgCaptionButton* H3DlgCaptionButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* b = Create(x, y, 0, 0, id, defName, text, font, frame, group, closeDialog, hotkey, color);
		if (b && b->loadedDef)
		{
			b->widthItem = b->loadedDef->widthDEF;
			b->heightItem = b->loadedDef->heightDEF;
		}
		return b;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        H3DlgCustomButton* b = H3ObjectAllocator<H3DlgCustomButton>().allocate(1);
        if (b)
            THISCALL_10(H3DlgCustomButton*, 0x456A10, b, x, y, width, height, id, defName, customProc, frame, clickFrame);
        return b;
    }
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        H3DlgCustomButton* b = Create(x, y, 0, 0, id, defName, customProc, frame, clickFrame);
        if (b && b->loadedDef)
        {
            b->widthItem = b->loadedDef->widthDEF;
            b->heightItem = b->loadedDef->heightDEF;
        }
        return b;
    }
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        return Create(x, y, 0, defName, customProc, frame, clickFrame);
    }
    _H3API_ VOID H3DlgCustomButton::ToggleMsgFlag(BOOL& flag)
    {
        defFrame = !defFrame;
        defFrameOnClick = !defFrameOnClick;
        flag = !flag;
        Draw();
        Refresh();
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 secondFrame, INT32 mirror, BOOL closeDialog)
    {
        H3DlgDef* d = H3ObjectAllocator<H3DlgDef>().allocate(1);
        if (d)
            THISCALL_12(H3DlgDef*, 0x4EA800, d, x, y, width, height, id, defName, frame, secondFrame, mirror, closeDialog, 0x10);
        return d;
    }
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 secondFrame, INT32 mirror, BOOL closeDialog)
    {
        H3DlgDef* d = Create(x, y, 0, 0, id, defName, frame, secondFrame, mirror, closeDialog);
        if (d && d->loadedDef)
        {
            d->widthItem = d->loadedDef->widthDEF;
            d->heightItem = d->loadedDef->heightDEF;
        }
        return d;
    }
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 group)
    {
        H3DlgDef* d = Create(x, y, 0, 0, 0, defName, frame, group, 0, 0);
        if (d && d->loadedDef)
        {
            d->widthItem = d->loadedDef->widthDEF;
            d->heightItem = d->loadedDef->heightDEF;
        }
        return d;
    }
    _H3API_ VOID H3DlgDef::SetFrame(INT32 frame)
    {
        defFrame = frame;
    }
    _H3API_ INT32 H3DlgDef::GetFrame() const
    {
        return defFrame;
    }
    _H3API_ INT32 H3DlgDef::GetGroup() const
    {
        return defGroup;
    }
    _H3API_ VOID H3DlgDef::SetGroup(INT32 group)
    {
        defGroup = group;
    }
    _H3API_ VOID H3DlgDef::ColorDefToPlayer(INT32 id)
    {
        loadedDef->ColorToPlayer(id);
    }
    _H3API_ H3LoadedDef* H3DlgDef::GetDef()
    {
        return loadedDef;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgText* H3DlgText::Create(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text,
                        LPCSTR fontName, INT32 color, INT32 id, INT32 align, INT32 bkColor)
    {
        H3DlgText* t = H3ObjectAllocator<H3DlgText>().allocate(1);
        if (t)
            THISCALL_12(H3DlgText*, 0x5BC6A0, t, x, y, width, height, text, fontName,
                        color, id, align, bkColor, 8);
        return t;
    }
    _H3API_ H3String& H3DlgText::GetH3String()
    {
        return text;
    }
    _H3API_ VOID H3DlgText::SetText(LPCSTR text)
    {
        vSetText(text);
    }
    _H3API_ VOID H3DlgText::SetText(const H3String& text)
    {
        vSetText(text.String());
    }
    _H3API_ VOID H3DlgText::SetAlignment(eTextAlignment align)
    {
        alignment = align;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgEdit* H3DlgEdit::Create(INT32 x, INT32 y, INT32 width, INT32 height,
                INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align,
                LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY)
    {
        H3DlgEdit* e = H3ObjectAllocator<H3DlgEdit>().allocate(1);
        if (e)
            THISCALL_17(H3DlgEdit*, 0x5BACD0, e, x, y, width, height, maxLength, text,
                fontName, color, align, pcxName, 0, id, 0, hasBorder, borderX, borderY);
        return e;
    }
    _H3API_ LPCSTR H3DlgEdit::GetText() const
    {
        return text.String();
    }
    _H3API_ H3String* H3DlgEdit::GetString()
    {
        return &text;
    }
    _H3API_ VOID H3DlgEdit::SetText(LPCSTR text)
    {
        vSetText(text);
    }
    _H3API_ VOID H3DlgEdit::DecreaseCaret()
    {
        if (caretPos > 0)
            --caretPos;
    }
    _H3API_ VOID H3DlgEdit::IncreaseCaret()
    {
        if (caretPos < text.Length())
            ++caretPos;
    }
    _H3API_ UINT H3DlgEdit::GetCaret() const
    {
        return caretPos;
    }
    _H3API_ BOOL H3DlgEdit::SetCaret(UINT pos)
    {
        if (pos == caretPos || pos > text.Length())
            return FALSE;
        caretPos = pos;
        return TRUE;
    }
    _H3API_ VOID H3DlgEdit::SetAutoredraw(BOOL on)
    {
        autoRedraw = on;
    }
    _H3API_ VOID H3DlgEdit::SetFocus(BOOL on)
    {
        vSetFocus(on);
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgFrame* H3DlgFrame::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color)
	{
		H3DlgFrame* f = H3ObjectAllocator<H3DlgFrame>().allocate(1);
		if (f)
			THISCALL_8(H3DlgFrame*, 0x44FE00, f, x, y, width, height, id, color, 0x400);
		return f;
	}
	_H3API_ H3DlgFrame* H3DlgFrame::Create(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color)
	{
		return Create(x, y, width, height, 0, color);
	}
	_H3API_ H3DlgFrame* H3DlgFrame::Create(H3DlgItem* target, RGB565 color, INT id, BOOL around_edge)
	{
		if (!target)
			return nullptr;
		if (around_edge)
			return Create(target->GetX() - 1, target->GetY() - 1, target->GetWidth() + 2, target->GetHeight() + 2, id, color);
		else
			return Create(target->GetX(), target->GetY(), target->GetWidth(), target->GetHeight(), id, color);
	}
	_H3API_ VOID H3DlgFrame::ChangeColor(RGB565 color)
	{
		color565 = color;
	}
	_H3API_ VOID H3DlgFrame::HideHue()
	{
		changeHue = FALSE;
	}
	_H3API_ VOID H3DlgFrame::ShowHue()
	{
		changeHue = TRUE;
	}
	_H3API_ VOID H3DlgFrame::ToggleHue()
	{
		changeHue = !changeHue;
	}
	_H3API_ H3RGB565& H3DlgFrame::GetColor()
	{
		return *reinterpret_cast<H3RGB565*>(&color565);
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ BOOL H3DlgHighlightable::unhighlightSelection() const
	{
		if (m_currentHighlight)
		{
			m_currentHighlight->Draw();
			m_currentHighlight->Refresh();
			m_currentHighlight = nullptr;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ H3DlgHighlightable::H3DlgHighlightable() :
		m_currentHighlight()
	{
	}
	_H3API_ VOID H3DlgHighlightable::AddItem(H3DlgItem* dlgItem, BYTE red,
        BYTE green, BYTE blue, UINT frame_thickness)
	{
		AddItem(dlgItem, H3ARGB888(red, green, blue), frame_thickness);
	}
	_H3API_ VOID H3DlgHighlightable::AddItem(H3DlgItem* dlgItem, const H3ARGB888& color, UINT frame_thickness)
	{
		Highlighter highlight(dlgItem, color, frame_thickness);
		m_highlightableItems += highlight;
	}
	_H3API_ BOOL H3DlgHighlightable::HighlightItem(H3DlgItem* dlgItem) const
	{
		if (!dlgItem)
			return unhighlightSelection();

        if (dlgItem == m_currentHighlight)
            return FALSE;
        unhighlightSelection();
        for (Highlighter* it = m_highlightableItems.begin(); it != m_highlightableItems.end(); ++it)
        {
            if (it->m_item == dlgItem)
            {
                it->m_item->DrawTempFrame(it->m_thickness, it->m_highlight);
                it->m_item->Refresh();
                m_currentHighlight = it->m_item;
                return TRUE;
            }
        }

		return FALSE;
	}
	_H3API_ BOOL H3DlgHighlightable::HighlightItem(const H3Msg& msg) const
	{
		if (m_highlightableItems.IsEmpty())
			return FALSE;
		if (!msg.IsMouseOver())
			return FALSE;
		return HighlightItem(msg.ItemAtPosition(m_highlightableItems[0].m_item->GetParent()));
	}
	_H3API_ VOID H3DlgHighlightable::Clear()
	{
		m_currentHighlight = nullptr;
		m_highlightableItems.RemoveAll();
	}
	H3DlgHighlightable::Highlighter::Highlighter() :
		m_item(), m_highlight(), m_thickness()
	{
	}
	_H3API_ H3DlgHighlightable::Highlighter::Highlighter(H3DlgItem* item, const H3ARGB888& color, UINT thickness) :
		m_item(item), m_highlight(color), m_thickness(thickness)
	{
	}
	_H3API_ H3DlgHighlightable::Highlighter::Highlighter(H3DlgItem* item, BYTE r, BYTE g, BYTE b, UINT thickness) :
		m_item(item), m_highlight(r, g, b), m_thickness(thickness)
	{
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgTextPcx* H3DlgTextPcx::Create(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text,
        LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id, INT32 align)
    {
        H3DlgTextPcx* t = H3ObjectAllocator<H3DlgTextPcx>().allocate(1);
        if (t)
            THISCALL_12(H3DlgTextPcx*, 0x5BCB70, t, x, y, width, height, text, fontName,
                pcxName, color, id, align, 8);
        return t;
    }
    _H3API_ H3DlgTextPcx* H3DlgTextPcx::Create(INT32 x, INT32 y, LPCSTR text, LPCSTR fontName,
        LPCSTR pcxName, INT32 color, INT32 align)
    {
        H3DlgTextPcx* t = Create(x, y, 0, 0, text, fontName, pcxName, color, 0, align);
        if (t && t->loadedPcx)
        {
            t->widthItem = t->loadedPcx->width;
            t->heightItem = t->loadedPcx->height;
        }
        return t;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3DlgHintBar::ShowHint(H3Msg* msg)
    {
        if (msg->command == eMsgCommand::MOUSE_OVER)
        {
            H3DlgItem* di = msg->ItemAtPosition(parent);
            if (di && di != lastHint)
            {
                lastHint = di;
                if (di->GetHint())
                    SetText(di->GetHint());
                else
                    SetText(h3_NullString);
                Draw();
                Refresh();
            }
        }
    }
    _H3API_ VOID H3DlgHintBar::ShowMessage(LPCSTR msg)
    {
        SetText(msg);
        Draw();
        Refresh();
    }
    _H3API_ H3DlgHintBar* H3DlgHintBar::Create(H3BaseDlg* dlg)
    {
        H3DlgHintBar* hint = (H3DlgHintBar*)H3DlgTextPcx::Create(8, dlg->GetHeight() - 26,
            dlg->GetWidth() - 16, 19, h3_NullString, NH3Dlg::Text::SMALL,
            NH3Dlg::HDassets::HD_STATUSBAR_PCX, eTextColor::REGULAR);
        if (hint)
            hint->lastHint = nullptr;
        return hint;
    }
    _H3API_ H3DlgHintBar* H3DlgHintBar::Create(H3BaseDlg* dlg, INT32 x, INT32 y, INT32 w, INT32 h)
    {
        H3DlgHintBar* hint = (H3DlgHintBar*)H3DlgTextPcx::Create(x, y, w, h, h3_NullString,
            NH3Dlg::Text::SMALL, NH3Dlg::HDassets::HD_STATUSBAR_PCX, eTextColor::REGULAR);
        if (hint)
            hint->lastHint = nullptr;
        return hint;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgPcx* H3DlgPcx::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* p = H3ObjectAllocator<H3DlgPcx>().allocate(1);
		if (p)
			THISCALL_8(H3DlgPcx*, 0x44FFA0, p, x, y, width, height, id, pcxName, 0x800);
		return p;
	}
	_H3API_ H3DlgPcx* H3DlgPcx::Create(INT32 x, INT32 y, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* p = Create(x, y, 0, 0, id, pcxName);
		if (p && p->loadedPcx)
		{
			p->widthItem = p->loadedPcx->width;
			p->heightItem = p->loadedPcx->height;
		}
		return p;
	}
	_H3API_ H3DlgPcx* H3DlgPcx::Create(INT32 x, INT32 y, LPCSTR pcxName)
	{
		return Create(x, y, 0, pcxName);
	}
	_H3API_ VOID H3DlgPcx::SetPcx(H3LoadedPcx* pcx)
	{
		loadedPcx = pcx;
	}
	_H3API_ VOID H3DlgPcx::AdjustColor(INT player)
	{
		THISCALL_2(VOID, 0x4501D0, this, player);
	}
	_H3API_ H3LoadedPcx* H3DlgPcx::GetPcx()
	{
		return loadedPcx;
	}
	_H3API_ H3LoadedPcx* H3DlgPcx::GetPcx() const
	{
		return loadedPcx;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgPcx16* H3DlgPcx16::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx16* p = H3ObjectAllocator<H3DlgPcx16>().allocate(1);
		if (p)
			THISCALL_8(H3DlgPcx16*, 0x450340, p, x, y, width, height, id, pcxName, 0x800);
		return p;
	}
	_H3API_ H3DlgPcx16* H3DlgPcx16::Create(INT32 x, INT32 y, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx16* p = Create(x, y, 0, 0, id, pcxName);
		if (p && p->loadedPcx16)
		{
			p->widthItem = p->loadedPcx16->width;
			p->heightItem = p->loadedPcx16->height;
		}
		return p;
	}
	_H3API_ H3DlgPcx16* H3DlgPcx16::Create(INT32 x, INT32 y, LPCSTR pcxName)
	{
		return Create(x, y, 0, 0, 0, pcxName);
	}
	_H3API_ VOID H3DlgPcx16::SetPcx(H3LoadedPcx16* pcx16)
	{
		loadedPcx16 = pcx16;
	}
	_H3API_ H3LoadedPcx16* H3DlgPcx16::GetPcx()
	{
		return loadedPcx16;
	}
	_H3API_ VOID H3DlgPcx16::SinkArea(INT32 x, INT32 y, INT32 w, INT32 h)
	{
		loadedPcx16->SinkArea(x, y, w, h);
	}
	_H3API_ VOID H3DlgPcx16::BevelArea(INT32 x, INT32 y, INT32 w, INT32 h)
	{
		loadedPcx16->BevelArea(x, y, w, h);
	}
	_H3API_ VOID H3DlgPcx16::SinkArea(H3DlgItem* it)
	{
		SinkArea(it->GetX() - 1, it->GetY() - 1, it->GetWidth() + 2, it->GetHeight() + 2);
	}
	_H3API_ VOID H3DlgPcx16::BevelArea(H3DlgItem* it)
	{
		BevelArea(it->GetX() - 1, it->GetY() - 1, it->GetWidth() + 2, it->GetHeight() + 2);
	}
} /* namespace h3 */

namespace h3
{
     _H3API_ H3DlgScrollableText* H3DlgScrollableText::Create(LPCSTR text, INT32 x, INT32 y,
        INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue)
    {
        H3DlgScrollableText* s = H3ObjectAllocator<H3DlgScrollableText>().allocate(1);
        if (s)
            THISCALL_9(H3DlgScrollableText*, 0x5BA360, s, text, x, y, width, height, font, color, isBlue);
        return s;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3DlgScrollbar::loadButton(LPCSTR buttonName)
    {
        THISCALL_2(VOID, 0x596340, this, buttonName);
    }

    _H3API_ H3DlgScrollbar* H3DlgScrollbar::Create(INT32 x, INT32 y, INT32 width,
        INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc,
        BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled)
    {
        H3DlgScrollbar* s = H3ObjectAllocator<H3DlgScrollbar>().allocate(1);
        if (s)
            THISCALL_11(H3DlgScrollbar*, 0x5963C0, s, x, y, width, height, id, ticksCount,
                scrollbarProc, isBlue, stepSize, arrowsEnabled);
        return s;
    }
    _H3API_ INT32 H3DlgScrollbar::GetTick() const
    {
        return tick;
    }
    _H3API_ VOID H3DlgScrollbar::SetTick(INT32 index)
    {
        tick = index;
    }
    _H3API_ VOID H3DlgScrollbar::SetBigStep(INT32 step)
    {
        bigStepSize = step;
    }
    _H3API_ VOID H3DlgScrollbar::SetButtonPosition()
    {
        btnPosition = sizeFree * tick / (ticksCount - 1) + btnSize2;
    }
    _H3API_ BOOL H3DlgScrollbar::IsHorizontal() const
    {
        return widthItem > heightItem;
    }
    _H3API_ INT32 H3DlgScrollbar::GetRightButtonX() const
    {
        return parent->GetX() + xPos + sizeMax - btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetHorizontalY() const
    {
        return parent->GetY() + yPos;
    }
    _H3API_ INT32 H3DlgScrollbar::GetBackgroundWidth() const
    {
        return sizeMax - 2 * btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetBackgroundX() const
    {
        return parent->GetX() + xPos + btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetSliderX() const
    {
        return parent->GetX() + xPos + btnPosition;
    }
    _H3API_ H3LoadedPcx* H3DlgScrollbar::GetPcx()
    {
        return loadedPcx;
    }
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3DlgTransparentItem* H3DlgTransparentItem::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id)
    {
        H3DlgTransparentItem* d = H3ObjectAllocator<H3DlgTransparentItem>().allocate(1);
        if (d)
            THISCALL_7(H3DlgTransparentItem*, 0x44FBE0, d, x, y, width, height, id, 1);
        return d;
    }
} /* namespace h3 */

namespace h3
{
	_H3API_ UINT32 H3GzFile::write(VOID* src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->write, this, src, size);
	}
	_H3API_ UINT32 H3GzFile::read(VOID* dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->read, this, dst, size);
	}
	_H3API_ H3GzFile::H3GzFile(LPCSTR file_name, LPCSTR mode)
	{
		THISCALL_3(H3GzFile&, 0x4D6EB0, this, file_name, mode);
	}
	_H3API_ H3GzFile::~H3GzFile()
	{
		THISCALL_1(VOID, 0x4D6FC0, this);
	}
	_H3API_ BOOL H3GzFile::ReadString16(H3String& string)
	{
		return FASTCALL_2(INT32, 0x4BB650, this, &string) != 0;
	}
	_H3API_ BOOL H3GzFile::Read(H3String& string)
	{
		return FASTCALL_2(INT32, 0x4C5CD0, this, &string) != 0;
	}
	_H3API_ BOOL H3GzFile::Write(const H3String& string)
	{
		if (!Write(string.Length()))
			return FALSE;
		return write(PVOID(string.String()), string.Length()) == string.Length();
	}
	_H3API_ BOOL H3GzFile::WriteString16(const H3String& string)
	{
		return FASTCALL_2(UINT32, 0x4BB820, this, &string) != 0;
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ UINT32 H3GzInflateBuf::read(PVOID dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->xsgetn, this, dst, size);
	}
	_H3API_ UINT32 H3GzInflateBuf::write(PVOID src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->xsputn, this, src, size);
	}
	_H3API_ UINT32 H3GzInflateBufFile::read(PVOID dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->read, this, dst, size);
	}
	_H3API_ UINT32 H3GzInflateBufFile::write(PVOID src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->write, this, src, size);
	}
	_H3API_ H3String* H3GzInflateBufFile::Read(H3String& string)
	{
		return FASTCALL_2(H3String*, 0x4858B0, &string, this);
	}

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3RmgMapItem* H3RmgMap::GetMapItem(INT x, INT y, INT z)
    {
        return THISCALL_4(H3RmgMapItem*, 0x537DD0, this, x, y, z);
    }
    _H3API_ H3RmgMapItem* H3RmgMap::begin()
    {
        return mapItems;
    }
    _H3API_ H3RmgMapItem* H3RmgMap::end()
    {
        return &mapItems[mapHeight * mapWidth * numberLevels];
    }
    _H3API_ H3Point H3RmgMap::GetCoordinates(H3RmgMapItem* item)
    {
        return ReverseCoordinates<H3RmgMapItem>(item, mapItems, mapWidth);
    }
    _H3API_ H3Map<H3RmgMapItem> H3RmgMap::GetMap()
    {
        return H3Map<H3RmgMapItem>(mapItems, static_cast<UINT>(mapWidth), numberLevels - 1);
    }
    _H3API_ H3FastMap<H3RmgMapItem> H3RmgMap::GetFastMap()
    {
        return H3FastMap<H3RmgMapItem>(mapItems, static_cast<UINT>(mapWidth), numberLevels - 1);
    }
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ H3RmgMapInfo::H3RmgMapInfo(H3RmgRandomMapGenerator* main, BOOL underground) :
		vTable((h3func*)0x6409DC),
		hasMap(0),
		undergroundMap(nullptr),
		width(main->map.mapWidth),
		height(main->map.mapHeight),
		underground(underground)
	{
		undergroundMap = &main->map.mapItems[width * height];
	}
	_H3API_ H3RmgMapInfo::~H3RmgMapInfo()
	{
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ INT H3RmgMapItem::GetLand() const
	{
		return tile.landType;
	}
	_H3API_ INT H3RmgMapItem::GetLandSprite() const
	{
		return tile.landSprite;
	}
	_H3API_ INT H3RmgMapItem::GetRiver() const
	{
		return tile.riverType;
	}
	_H3API_ INT H3RmgMapItem::GetRiverSprite() const
	{
		return tile.riverSprite;
	}
	_H3API_ INT H3RmgMapItem::GetRoad() const
	{
		return tile.roadType;
	}
	_H3API_ INT H3RmgMapItem::GetRoadSprite() const
	{
		return tileData.roadSprite;
	}
} /* namespace h3 */

namespace h3
{
    _H3API_ h3func H3RmgObject::GetVTable() const
	{
		return h3func(vTable);
	}
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ VOID H3RmgParameters::Validate()
    {
        monsterStrength += 3;
        if (monsterStrength < 1)
            monsterStrength = 1;
        else if (monsterStrength > 5)
            monsterStrength = 5;

        if (computerCount + humanCount < 2)
        {
            computerCount = 1;
            humanCount = 1;
        }
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ H3RmgRandomMapGenerator::H3RmgRandomMapGenerator(H3RmgParameters& p, PVOID progress)
    {
        p.Validate();
        THISCALL_12(H3RmgRandomMapGenerator*, 0x538000, this, p.width, p.height, p.hasUnderground, p.humanCount, p.humanTeams,
            p.computerCount, p.computerTeams, p.waterAmount, p.monsterStrength, progress, p.gameVersion);
        for (INT i = 0; i < 8; ++i)
        {
            if (p.isHuman[i])
                isHuman[i] = TRUE;
            playerTown[i] = p.townId[i];
        }
    }
    _H3API_ H3RmgRandomMapGenerator::~H3RmgRandomMapGenerator()
    {
        THISCALL_1(VOID, 0x5382E0, this);
    }
    _H3API_ BOOL8 H3RmgRandomMapGenerator::GenerateMap()
    {
        return THISCALL_1(BOOL8, 0x549E20, this);
    }
    _H3API_ BOOL8 H3RmgRandomMapGenerator::WriteMap(H3GzFile& stream)
    {
        return THISCALL_2(BOOL8, 0x54B0E0, this, &stream);
    }
} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{

} /* namespace h3 */

namespace h3
{
    _H3API_ INT32 H3Diplomacy::GetPowerFactor(FLOAT k)
    {
        return STDCALL_1(INT32, 0x4A7330, k);
    }
    _H3API_ INT32 H3Diplomacy::DiplomacyJoinCost(H3Hero* hero, const H3MapitemMonster& creature)
    {
        if (!hero)
            return eDiploType::NO_HERO;

        INT32 type = creature.CreatureType();
        H3CreatureInformation& info = H3CreatureInformation::Get()[type];
        INT32 sympathy = hero->HasSimilarCreature(type);
        FLOAT hero_power = FLOAT(hero->GetPower());
        FLOAT creature_power = FLOAT(info.aiValue * creature.count);
        FLOAT ratio = hero_power / creature_power;
        INT32 power_factor = GetPowerFactor(ratio);
        INT32 difficulty_bonus = H3Main::Get()->playersInfo.difficulty == 0;
        INT32 diplo_lvl = hero->secSkill[eSecondary::DIPLOMACY] + difficulty_bonus;
        diplo_lvl = std::min(3, diplo_lvl);
        INT32 charisma = power_factor + diplo_lvl + sympathy;
        INT32 aggression = creature.aggression;

        if (aggression > charisma)
            return eDiploType::FIGHT;
        if (aggression <= sympathy + diplo_lvl + 1)
            return eDiploType::JOIN_FREE;
        if (aggression <= sympathy + 2 * diplo_lvl + 1)
            return info.cost.gold * creature.count;
        if (creature.noRun || aggression == charisma)
            return eDiploType::FIGHT;
        return eDiploType::FLEE;
    }
} /* namespace h3 */

namespace h3
{
    _H3API_ BOOL H3Bitmap::Create(const H3LoadedPcx16& pcx)
    {
        if (!init(pcx.width, pcx.height))
            return FALSE;

        if (H3BitMode::Get() == 2)
        {
            H3RGB565* src  = reinterpret_cast<H3RGB565*>(pcx.buffer);
            RGBTRIPLE* dst = reinterpret_cast<RGBTRIPLE*>(m_pixels.Get());

            for (INT y = 0; y < pcx.height; ++y)
            {
                for (INT x = 0; x < pcx.width; ++x)
                {
                    H3RGB888 rgb     = src[x]; // rgb565 to rgb888
                    dst[x].rgbtRed   = rgb.r;
                    dst[x].rgbtGreen = rgb.g;
                    dst[x].rgbtBlue  = rgb.b;
                }
                src = reinterpret_cast<H3RGB565*>(reinterpret_cast<PUINT8>(src) + pcx.scanlineSize);
                dst = reinterpret_cast<PRGBTRIPLE>(reinterpret_cast<PUINT8>(dst) + m_scanline);
            }
        }
        else
        {
            PH3ARGB888 src = reinterpret_cast<PH3ARGB888>(pcx.buffer);
            PRGBTRIPLE dst = reinterpret_cast<PRGBTRIPLE>(m_pixels.Get());

            for (INT y = 0; y < pcx.height; ++y)
            {
                for (INT x = 0; x < pcx.width; ++x)
                {
                    dst[x].rgbtRed   = src[x].r;
                    dst[x].rgbtGreen = src[x].g;
                    dst[x].rgbtBlue  = src[x].b;
                }
                src = reinterpret_cast<PH3ARGB888>(reinterpret_cast<PUINT8>(src) + pcx.scanlineSize);
                dst = reinterpret_cast<PRGBTRIPLE>(reinterpret_cast<PUINT8>(dst) + m_scanline);
            }
        }

        m_info.biHeight = -m_info.biHeight;

        return TRUE;
    }
    _H3API_ BOOL H3Bitmap::Save(LPCSTR file_name)
    {
        if (!m_pixels)
            return FALSE;
        H3File f;
        if (!f.Save(file_name))
            return FALSE;
        if (!f.Write(m_header))
            return FALSE;
        if (!f.Write(m_info))
            return FALSE;
        return f.Write(m_pixels.Get(), m_dynamicSize);
    }
    _H3API_ BOOL H3Bitmap::Save(const H3String& file_name)
    {
        return Save(file_name.String());
    }
    _H3API_ INT H3Bitmap::height()
    {
        return m_info.biHeight < 0 ? -m_info.biHeight : m_info.biHeight;
    }
    _H3API_ BOOL H3Bitmap::init(INT width, INT height)
    {
        m_scanline             = ((width * 3 + 3) >> 2) << 2; // padding to multiple of 4
        m_dynamicSize          = m_scanline * height;
        m_pixels.Set(ByteAllocator().allocate(m_dynamicSize));
        if (!m_pixels)
            return FALSE;

        m_header.bfType        = 0x4D42;
        m_header.bfOffBits     = sizeof(m_header) + sizeof(m_info);
        m_header.bfSize        = sizeof(m_header) + sizeof(m_info) + m_dynamicSize;

        m_info.biSize          = sizeof(m_info);
        m_info.biWidth         = width;
        m_info.biHeight        = height;
        m_info.biPlanes        = 1;
        m_info.biBitCount      = 8 * 3;
        m_info.biCompression   = BI_RGB;
        m_info.biSizeImage     = 0;
        m_info.biXPelsPerMeter = 3780;
        m_info.biYPelsPerMeter = 3780;
        m_info.biClrUsed       = 0;
        m_info.biClrImportant  = 0;

        return TRUE;
    }
}//////////////////////////////////////////////////////////////////////

#if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND)

namespace h3
{
	namespace H3Internal
	{
		CHAR const CONTEXT_FORMAT[] = "\n\
Context:\n\
EAX   = 0x%08X\n\
ECX   = 0x%08X\n\
EDX   = 0x%08X\n\
EBX   = 0x%08X\n\
ESP   = 0x%08X\n\
EBP   = 0x%08X\n\
ESI   = 0x%08X\n\
EDI   = 0x%08X\n\
Flags = 0x%08X";

		_H3API_ VOID     _h3TransFunction(UINT code, EXCEPTION_POINTERS* ep);
		_H3API_ LPCSTR   _opDescription(const ULONG opcode);
		_H3API_ LPCSTR   _seDescription(const UINT& code);
		_H3API_ H3String _exInformation(_EXCEPTION_POINTERS* ep, UINT code = 0);

		_H3API_ VOID _h3TransFunction(UINT code, EXCEPTION_POINTERS* ep)
		{
			throw H3Exception(_exInformation(ep, code));
		}
		_H3API_ LPCSTR _opDescription(const ULONG opcode)
		{
			switch (opcode)
			{
			case 0:
				return "read";
			case 1:
				return "write";
			case 8:
				return "user-mode data execution prevention (DEP) violation";
			default:
				return "unknown";
			}
		}
		_H3API_ LPCSTR _seDescription(const UINT& code)
		{
			switch (code)
			{
			case EXCEPTION_ACCESS_VIOLATION:
				return "EXCEPTION_ACCESS_VIOLATION [0xC0000005]";
			case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
				return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED [0xC000008C]";
			case EXCEPTION_BREAKPOINT:
				return "EXCEPTION_BREAKPOINT [0x80000003]";
			case EXCEPTION_DATATYPE_MISALIGNMENT:
				return "EXCEPTION_DATATYPE_MISALIGNMENT [0x80000002]";
			case EXCEPTION_FLT_DENORMAL_OPERAND:
				return "EXCEPTION_FLT_DENORMAL_OPERAND [0xC000008D]";
			case EXCEPTION_FLT_DIVIDE_BY_ZERO:
				return "EXCEPTION_FLT_DIVIDE_BY_ZERO [0xC000008E]";
			case EXCEPTION_FLT_INEXACT_RESULT:
				return "EXCEPTION_FLT_INEXACT_RESULT [0xC000008F]";
			case EXCEPTION_FLT_INVALID_OPERATION:
				return "EXCEPTION_FLT_INVALID_OPERATION [0xC0000090]";
			case EXCEPTION_FLT_OVERFLOW:
				return "EXCEPTION_FLT_OVERFLOW [0xC0000091]";
			case EXCEPTION_FLT_STACK_CHECK:
				return "EXCEPTION_FLT_STACK_CHECK [0xC0000092]";
			case EXCEPTION_FLT_UNDERFLOW:
				return "EXCEPTION_FLT_UNDERFLOW [0xC0000093]";
			case EXCEPTION_ILLEGAL_INSTRUCTION:
				return "EXCEPTION_ILLEGAL_INSTRUCTION [0xC000001D]";
			case EXCEPTION_IN_PAGE_ERROR:
				return "EXCEPTION_IN_PAGE_ERROR [0xC0000006]";
			case EXCEPTION_INT_DIVIDE_BY_ZERO:
				return "EXCEPTION_FLT_DIVIDE_BY_ZERO [0xC000008E]";
			case EXCEPTION_INT_OVERFLOW:
				return "EXCEPTION_INT_OVERFLOW [0xC0000095]";
			case EXCEPTION_INVALID_DISPOSITION:
				return "EXCEPTION_INVALID_DISPOSITION [0xC0000026]";
			case EXCEPTION_NONCONTINUABLE_EXCEPTION:
				return "EXCEPTION_NONCONTINUABLE_EXCEPTION [0xC0000025]";
			case EXCEPTION_PRIV_INSTRUCTION:
				return "EXCEPTION_PRIV_INSTRUCTION [0xC0000096]";
			case EXCEPTION_SINGLE_STEP:
				return "EXCEPTION_SINGLE_STEP [0x80000004]";
			case EXCEPTION_STACK_OVERFLOW:
				return "EXCEPTION_STACK_OVERFLOW [0xC00000FD]";
			case EXCEPTION_INVALID_HANDLE:
				return "EXCEPTION_INVALID_HANDLE [0xC0000008]";
			case EXCEPTION_GUARD_PAGE:
				return "EXCEPTION_GUARD_PAGE [0x80000001]";
			default:
				return "UNKNOWN EXCEPTION";
			}
		}
		_H3API_ H3String _exInformation(_EXCEPTION_POINTERS* ep, UINT code)
		{
			H3String error;
			HMODULE hm;
			GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, LPCSTR(ep->ExceptionRecord->ExceptionAddress), &hm);

			DWORD base_of_code = DWORD(hm); // gives address relative to base instead of code start

			H3String module_name = H3Path::GetModuleFileNameA(hm);
			UINT pos = module_name.FindLastOf("/\\");
			LPCSTR short_name = pos == H3String::npos ? module_name.String() : module_name.At(pos + 1);

			error.Printf("SE %s at address offset 0x%08X inside %s.\n",
				_seDescription(code),
				(DWORD)ep->ExceptionRecord->ExceptionAddress - base_of_code,
				short_name);

			if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_IN_PAGE_ERROR)
			{
				error.PrintfAppend("Invalid operation: %s at address 0x%08X.\n",
					_opDescription(ep->ExceptionRecord->ExceptionInformation[0]),
					ep->ExceptionRecord->ExceptionInformation[1]);
			}

			if (code == EXCEPTION_IN_PAGE_ERROR)
			{
				error.PrintfAppend("Underlying NTSTATUS code that resulted in the exception %08X.\n",
					ep->ExceptionRecord->ExceptionInformation[2]);
			}

			PCONTEXT ctx = ep->ContextRecord;
			error.PrintfAppend(H3Internal::CONTEXT_FORMAT,
				ctx->Eax, ctx->Ecx, ctx->Edx, ctx->Ebx, ctx->Esp, ctx->Ebp, ctx->Esi, ctx->Edi, ctx->ContextFlags);

			return error;
		}
	}
	_H3API_ H3Exception::H3Exception(LPCSTR message) :
		std::exception(message)
	{
	}
	_H3API_ H3Exception::H3Exception(const H3String& message) :
		std::exception(message.String())
	{
	}
	_H3API_ VOID H3Exception::ShowInGame(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			H3Messagebox::Show(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		H3Messagebox::Show(msg);
	}
	_H3API_ VOID H3Exception::ShowInGame(LPCSTR precursor_text) const
	{
		ShowInGame(*this, precursor_text);
	}
	_H3API_ BOOL H3Exception::ShowInGameLog(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			return H3Messagebox::Choice(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		return H3Messagebox::Choice(msg);
	}
	_H3API_ BOOL H3Exception::ShowInGameLog(LPCSTR precursor_text) const
	{
		return ShowInGameLog(*this, precursor_text);
	}
	_H3API_ VOID H3Exception::ShowMessagebox(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			H3Error::ShowError(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		H3Error::ShowError(msg.String());
	}
	_H3API_ VOID H3Exception::ShowMessagebox(LPCSTR precursor_text) const
	{
		ShowMessagebox(*this, precursor_text);
	}
	_H3API_ BOOL H3Exception::ShowMessageboxLog(const std::exception& e, LPCSTR precursor_text)
	{
		return H3Error::ShowErrorChoice(e.what());
	}
	_H3API_ BOOL H3Exception::ShowMessageboxLog(LPCSTR precursor_text) const
	{
		return ShowMessageboxLog(*this, precursor_text);
	}
	_H3API_ VOID H3Exception::LogError(const std::exception& e, LPCSTR path)
	{
		H3File f;
		if (!f.Save(path))
			return;
		f.Write(PVOID(e.what()), libc::strlen(e.what()));
	}
	_H3API_ VOID H3Exception::LogError(const std::exception& e, const H3String & path)
	{
		LogError(e, path.String());
	}
	_H3API_ VOID H3Exception::LogError(LPCSTR path) const
	{
		LogError(*this, path);
	}
	_H3API_ VOID H3Exception::LogError(const H3String& path) const
	{
		LogError(*this, path);
	}
	_H3API_ H3SEHandler::H3SEHandler() :
		m_oldTranslator(_set_se_translator(H3Internal::_h3TransFunction))
	{
	}
	_H3API_ H3SEHandler::~H3SEHandler()
	{
		_set_se_translator(m_oldTranslator);
	}
}

#endif /* #if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND) */

#ifdef _H3API_EXCEPTION_

#endif

namespace h3
{
	constexpr CHAR NEW_LINE[]     = "\r\n";
	constexpr CHAR INI_COMMENT    = '#';
	constexpr CHAR SECTION_START  = '[';
	constexpr CHAR SECTION_END    = ']';
	constexpr CHAR KEY_EQUALS[]   = " = ";
	constexpr CHAR BOM_HEADER[]   = "\xEF\xBB\xBF";

#pragma warning(push)
#pragma warning(disable:4482)
	_H3API_ LPCSTR HDIniEntry::GetText()
	{
		if (entryType == eType::INI_VALUE)
			return h3_NullString;
		return data.text;
	}
	_H3API_ HDIni::iterator HDIni::begin()
	{
		return iterator(entries);
	}
	_H3API_ HDIni::iterator HDIni::end()
	{
		return iterator(entries + lineEntries);
	}
	_H3API_ HDIni::iterator HDIni::FindEntry(LPCSTR key)
	{
		for (iterator it = begin(); it != end(); it++)
		{
			if (it->entryType == HDIniEntry::eType::INI_KEY)
			{
				if (libc::strcmpi(key, it->data.text) == 0)
					return it;
			}
			else
				break;
		}

		return end();
	}
#pragma warning(pop)
	_H3API_ HDIni::iterator::iterator(HDIniEntry ** entries) :
		m_entry(entries)
	{
	}
	_H3API_ HDIniEntry * HDIni::iterator::operator->()
	{
		return *m_entry;
	}
	_H3API_ HDIni::iterator& HDIni::iterator::operator++()
	{
		m_entry += (*m_entry)->entryCount + 1;
		return *this;
	}
	_H3API_ HDIni::iterator HDIni::iterator::operator++(int)
	{
		iterator iter(this->m_entry);
		operator++();
		return iter;
	}
	_H3API_ HDIni::iterator & HDIni::iterator::operator*()
	{
		return *this;
	}
	_H3API_ BOOL8 HDIni::iterator::operator==(const iterator & other) const
	{
		return m_entry == other.m_entry;
	}
	_H3API_ BOOL8 HDIni::iterator::operator!=(const iterator & other) const
	{
		return m_entry != other.m_entry;
	}
	_H3API_ HDIniEntry * HDIni::iterator::operator[](UINT index)
	{
		return m_entry[index + 1];
	}

	_H3API_ INT H3IniLine::matches(const h3::H3String & key)
	{
		return m_content.Compare(key.String());
	}

	_H3API_ INT H3IniLine::matches(LPCSTR key)
	{
		return m_content.Compare(key);
	}

	_H3API_ BOOL8 H3IniLine::write(H3String & new_ini)
	{
		switch (m_type & LineType::ALL)
		{
		case LineType::EMPTY:
			break;
		case LineType::COMMENT:
			new_ini.Append(m_content);
			break;
		case LineType::SECTION:
			new_ini.Append(SECTION_START);
			new_ini.Append(m_content);
			new_ini.Append(SECTION_END);
			break;
		case LineType::KEY:
			new_ini.Append(m_content);
			new_ini.AppendA(KEY_EQUALS);
			new_ini.Append(m_value);
			break;
		default:
			return FALSE;
		}
		new_ini.AppendA(NEW_LINE);
		return TRUE;
	}

	_H3API_ H3IniLine::H3IniLine() :
		m_type(LineType::EMPTY)
	{
	}

#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3IniLine::H3IniLine(h3::H3String && content, h3::H3String && value) :
		m_type(LineType::KEY), m_content(std::move(content)), m_value(std::move(value))
	{
	}
	_H3API_ H3IniLine::H3IniLine(LineType type, h3::H3String && content) :
		m_type(type), m_content(std::move(content))
	{
	}
#else
	H3IniLine::H3IniLine(LineType type, const H3String & content) :
		m_type(type), m_content(content)
	{
	}
	_H3API_ H3IniLine::H3IniLine(const H3String& content, const H3String& value) :
		m_content(content), m_value(value)
	{
	}
#endif
	_H3API_ FLOAT H3IniLine::GetFloat(FLOAT default_value)
	{
		if (m_value.Empty())
			return default_value;
		return FLOAT(libc::atof(m_value.String()));
	}
	_H3API_ DOUBLE H3IniLine::GetDouble(DOUBLE default_value)
	{
		if (m_value.Empty())
			return default_value;
		return libc::atof(m_value.String());
	}
	_H3API_ H3String H3IniLine::GetString(const H3String & default_value)
	{
		if (m_value.Empty())
			return default_value;
		return m_value;
	}
	_H3API_ UINT H3IniLine::GetHex(UINT default_value)
	{
		char* end_ptr;
		if (m_value.Empty())
			return default_value;
		if (m_value.Length() > 2)
		{

			if (m_value[0] == '0' && (m_value[1] == 'x' || m_value[1] == 'X'))
				return libc::strtoul(m_value.begin() + 2, &end_ptr, 0x10);
		}
		return libc::strtoul(m_value.String(), &end_ptr, 0x10);
	}
	_H3API_ bool H3IniLine::GetBool(bool default_value)
	{
		if (m_value.Empty())
			return default_value;
		switch (m_value[0])
		{
		case '1': // 1
		case 't': // true
		case 'T': // True
		case 'y': // yes
		case 'Y': // Yes
			return true;
		case '0': // 0
		case 'f': // false
		case 'F': // FALSE
		case 'n': // no
		case 'N': // No
			return false;
		case 'o': // on / off
		case 'O': // On / Off
		{
			char nf = m_value[1];
			if (nf == 'n' || nf == 'N')
				return true;
			if (nf == 'f' || nf == 'F')
				return false;
			return default_value;
		}
		default:
			return default_value;
		}
	}
	_H3API_ INT H3IniLine::GetInteger(INT default_value)
	{
		if (m_value.Empty())
			return default_value;
		return libc::atoi(m_value.String());
	}
	_H3API_ BOOL8 H3IniLine::SetBool(bool value)
	{
		m_value.Assign(value ? '1' : '0');
		return TRUE;
	}
	_H3API_ BOOL8 H3IniLine::SetInteger(INT value)
	{
		m_value.Assign(value);
		return TRUE;
	}
	_H3API_ BOOL8 H3IniLine::SetFloat(FLOAT value)
	{
		m_value.Printf("%f", value);
		return TRUE;
	}
	_H3API_ BOOL8 H3IniLine::SetDouble(DOUBLE value)
	{
		m_value.Printf("%f", value);
		return TRUE;
	}
	_H3API_ BOOL8 H3IniLine::SetString(const H3String & value)
	{
		m_value.Assign(value);
		return TRUE;
	}
	_H3API_ BOOL8 H3IniLine::SetHex(UINT value)
	{
		m_value.Printf("0x%X", value);
		return TRUE;
	}

	_H3API_ H3IniSection::iterator::iterator(H3IniLine ** key) :
		data(key)
	{
	}

	_H3API_ H3IniLine & H3IniSection::iterator::operator*()
	{
		return **data;
	}

	_H3API_ H3IniLine * H3IniSection::iterator::operator->()
	{
		return *data;
	}

	_H3API_ BOOL8 H3IniSection::iterator::operator!=(const iterator & other)
	{
		return data != other.data;
	}

	_H3API_ BOOL8 H3IniSection::iterator::operator==(const iterator & other)
	{
		return data == other.data;
	}

	_H3API_ H3IniSection::iterator& H3IniSection::iterator::operator++()
	{
		++data;
		return *this;
	}

	_H3API_ H3IniSection::iterator H3IniSection::iterator::operator++(int)
	{
		iterator it(data);
		++data;
		return it;
	}

	_H3API_ H3IniSection::H3IniSection() :
		m_name(), m_searched()
	{
	}

	_H3API_ H3IniSection::H3IniSection(const H3IniLine * associated_line) :
		m_name(&associated_line->m_content), m_searched()
	{
	}

	_H3API_ H3IniSection::iterator H3IniSection::begin()
	{
		return iterator(m_keys.begin());
	}

	_H3API_ H3IniSection::iterator H3IniSection::end()
	{
		return iterator(m_keys.end() - 1);
	}

	_H3API_ H3IniSection::iterator H3IniSection::Get(LPCSTR key)
	{
		if (!m_searched)
		{
			UINT num = m_keys.Count();
			UINT left = 0;
			UINT right = num - 2; // last is empty line
			while (right >= left)
			{
				UINT mid = (left + right) / 2;
				H3IniLine** line = m_keys.begin() + mid;
				INT comp = (*line)->m_content.Compare(key);
				if (comp == 0)
					return iterator(line);
				if (comp < 0)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		else
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (it->m_type & H3IniLine::LineType::SEARCHED)
					continue;
				if (it->m_content.Compare(key) == 0)
				{
					it->m_type |= H3IniLine::LineType::SEARCHED;
					return it;
				}
			}
		}
		return end();
	}

	_H3API_ H3IniSection::iterator H3IniSection::operator[](LPCSTR key)
	{
		return Get(key);
	}

	_H3API_ BOOL8 H3IniSection::SetBool(LPCSTR key, bool value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetBool(value);
	}

	_H3API_ BOOL8 H3IniSection::SetInteger(LPCSTR key, INT value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetInteger(value);
	}

	_H3API_ BOOL8 H3IniSection::SetString(LPCSTR key, const H3String & value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetString(value);
	}

	_H3API_ BOOL8 H3IniSection::SetFloat(LPCSTR key, FLOAT value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetFloat(value);
	}

	_H3API_ BOOL8 H3IniSection::SetDouble(LPCSTR key, DOUBLE value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetDouble(value);
	}

	_H3API_ BOOL8 H3IniSection::SetHex(LPCSTR key, UINT value)
	{
		iterator it = Get(key);
		if (it == end())
			return FALSE;
		return it->SetHex(value);
	}

	_H3API_ bool H3IniSection::GetBool(LPCSTR key, bool default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetBool(default_value);
	}

	_H3API_ INT H3IniSection::GetInteger(LPCSTR key, INT default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetInteger(default_value);
	}

	_H3API_ FLOAT H3IniSection::GetFloat(LPCSTR key, FLOAT default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetFloat(default_value);
	}

	_H3API_ DOUBLE H3IniSection::GetDouble(LPCSTR key, DOUBLE default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetDouble(default_value);
	}

	_H3API_ H3String H3IniSection::GetString(LPCSTR key, const H3String & default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetString(default_value);
	}

	_H3API_ UINT H3IniSection::GetHex(LPCSTR key, UINT default_value)
	{
		iterator it = Get(key);
		if (it == end())
			return default_value;
		return it->GetHex(default_value);
	}

	_H3API_ H3Ini::iterator::iterator(H3IniSection * section) :
		data(section)
	{
	}

	_H3API_ H3IniSection& H3Ini::iterator::operator*()
	{
		return *data;
	}
	_H3API_ H3IniSection* H3Ini::iterator::operator->()
	{
		return data;
	}
	_H3API_ BOOL8 H3Ini::iterator::operator!=(const iterator& other)
	{
		return data != other.data;
	}
	_H3API_ BOOL8 H3Ini::iterator::operator==(const iterator & other)
	{
		return data == other.data;
	}
	_H3API_ H3Ini::iterator& H3Ini::iterator::operator++()
	{
		++data;
		return *this;
	}
	_H3API_ H3Ini::iterator H3Ini::iterator::operator++(int)
	{
		iterator it(data);
		++data;
		return it;
	}

	_H3API_ H3IniSection::iterator H3Ini::iterator::operator[](LPCSTR key)
	{
		return data->Get(key);
	}

	_H3API_ H3Ini::iterator H3Ini::begin()
	{
		return iterator(m_sections.begin());
	}
	_H3API_ H3Ini::iterator H3Ini::end()
	{
		return iterator(m_sections.end() - 1);
	}

	_H3API_ BOOL8 H3Ini::Open(LPCSTR file)
	{
		H3File f;
		if (!f.Open(file) || (!f.ReadToBuffer()))
#ifdef _H3API_EXCEPTION_
			throw H3Exception("Unable to open ini file.");
#else
			return FALSE;
#endif

		H3Vector<H3String> lines = f.GetLines(TRUE);
		m_lines.Reserve(lines.Count() + 1);

		H3IniSection* currentSection = nullptr;

		for (H3String* iter = lines.begin(); iter != lines.end(); ++iter)
		{
			H3String& it = *iter;
			it.Trim();
			if (it.Empty())
				m_lines.Add(H3IniLine());
			else
			{
				switch (it[0])
				{
				case INI_COMMENT:
#ifdef _H3API_CPLUSPLUS11_
					m_lines.Add(H3IniLine(H3IniLine::LineType::COMMENT, std::move(it)));
#else
					m_lines.Add(H3IniLine(H3IniLine::LineType::COMMENT, it));
#endif
					break;
				case SECTION_START:
				{
					if (it.Last() != SECTION_END)
					{
#ifdef _H3API_EXCEPTION_
						H3String error("Invalid section: ");
						error += it;
						throw H3Exception(error);
#else
						return FALSE;
#endif
					}
					it.Erase(it.Length() - 1);
					it.Erase(0);

					for (H3IniSection* s = m_sections.begin(); s != m_sections.end(); ++s)
					{
						if (*s->m_name == it)
						{
							currentSection = s;
							break;
						}
					}
#ifdef _H3API_CPLUSPLUS11_
					H3IniLine* added = m_lines.Add(H3IniLine(H3IniLine::LineType::SECTION, std::move(it)));
#else
					H3IniLine* added = m_lines.Add(H3IniLine(H3IniLine::LineType::SECTION, it));
#endif
					currentSection = m_sections.Add(H3IniSection(added));
				}
					break;
				default: // key = value candidate
				{
					if (currentSection == nullptr)
					{
#ifdef _H3API_EXCEPTION_
						H3String error("Key line entry does not belong to a section: ");
						error += it;
						throw H3Exception(error);
#else
						return FALSE;
#endif
					}
					H3String value;
					if (!it.Split('=', value))
					{
#ifdef _H3API_EXCEPTION_
						H3String error("Key line does not have matching value: ");
						error += it;
						throw H3Exception(error);
#else
						return FALSE;
#endif
					}
					it.Trim();
					value.Trim();

#ifdef _H3API_CPLUSPLUS11_
					H3IniLine* added = m_lines.Add(H3IniLine(std::move(it), std::move(value)));
#else
					H3IniLine* added = m_lines.Add(H3IniLine(it, value));
#endif
					currentSection->m_keys.Add(added);
				}
					break;
				}
			}
		}

		H3IniLine* emptyLine = m_lines.Add(H3IniLine());
		for (H3IniSection* section = m_sections.begin(); section != m_sections.end(); ++section)
			section->m_keys.Add(emptyLine);

		m_sections.Add(H3IniSection());

		return TRUE;
	}
	_H3API_ BOOL8 H3Ini::Save(LPCSTR file, BOOL utf8)
	{
		H3File f;
		if (!f.Save(file))
			return FALSE;

		H3String new_ini;
		if (utf8)
			new_ini.AssignA(BOM_HEADER);

		for (H3IniLine* iter = m_lines.begin(); iter != m_lines.end() - 1; ++iter)
		{
			if (!iter->write(new_ini))
				return FALSE;
		}
		return f.Write(new_ini);
	}
	_H3API_ H3Ini::iterator H3Ini::Get(LPCSTR section)
	{
		for (H3IniSection* it = m_sections.begin(); it != m_sections.end() - 1; ++it)
		{
			if (it->m_searched)
				continue;
			if (it->m_name->Compare(section) == 0)
			{
				it->m_searched = TRUE;
				return iterator(it);
			}
		}
		return end();
	}
	_H3API_ bool H3Ini::GetBool(LPCSTR section, LPCSTR key, bool default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetBool(key, default_value);
	}
	_H3API_ INT H3Ini::GetInteger(LPCSTR section, LPCSTR key, INT default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetInteger(key, default_value);
	}
	_H3API_ FLOAT H3Ini::GetFloat(LPCSTR section, LPCSTR key, FLOAT default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetFloat(key, default_value);
	}
	_H3API_ DOUBLE H3Ini::GetDouble(LPCSTR section, LPCSTR key, DOUBLE default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetDouble(key, default_value);
	}
	_H3API_ H3String H3Ini::GetString(LPCSTR section, LPCSTR key, const H3String & default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetString(key, default_value);
	}
	_H3API_ UINT H3Ini::GetHex(LPCSTR section, LPCSTR key, UINT default_value)
	{
		iterator it = Get(section);
		if (it == end())
			return default_value;
		return it->GetHex(key, default_value);
	}
	_H3API_ BOOL8 H3Ini::SetBool(LPCSTR section, LPCSTR key, bool value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetBool(key, value);
	}
	_H3API_ BOOL8 H3Ini::SetInteger(LPCSTR section, LPCSTR key, INT value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetInteger(key, value);
	}
	_H3API_ BOOL8 H3Ini::SetFloat(LPCSTR section, LPCSTR key, FLOAT value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetFloat(key, value);
	}
	_H3API_ BOOL8 H3Ini::SetDouble(LPCSTR section, LPCSTR key, DOUBLE value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetDouble(key, value);
	}
	_H3API_ BOOL8 H3Ini::SetString(LPCSTR section, LPCSTR key, const H3String & value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetString(key, value);
	}
	_H3API_ BOOL8 H3Ini::SetHex(LPCSTR section, LPCSTR key, UINT value)
	{
		iterator it = Get(section);
		if (it == end())
			return FALSE;
		return it->SetHex(key, value);
	}
	_H3API_ H3Ini::iterator H3Ini::operator[](LPCSTR section)
	{
		return Get(section);
	}
}

namespace h3
{
	_H3API_ H3Protect::H3Protect(UINT32 address, UINT32 size) :
		m_address(address),
		m_size(size),
		m_oldProtect()
	{
		m_protectEdited = VirtualProtect(reinterpret_cast<LPVOID>(m_address), m_size, PAGE_EXECUTE_WRITECOPY, &m_oldProtect);
	}
	_H3API_ H3Protect::~H3Protect()
	{
		if (m_protectEdited)
			VirtualProtect(reinterpret_cast<LPVOID>(m_address), m_size, m_oldProtect, &m_oldProtect);
	}
	_H3API_ BOOL H3Protect::CanWrite()
	{
		return m_protectEdited;
	}

	_H3API_ VOID H3Patcher::Breakpoint()
	{
		if (IsDebuggerPresent())
			__asm int 3;
	}

	_H3API_ PUCHAR H3Patcher::Memmem(PUCHAR haystack, size_t hlen, PUCHAR needle, size_t nlen)
	{
		PUCHAR p = haystack;
		size_t plen = hlen;

		if (!nlen)
			return nullptr;

		const UCHAR needle_first = *static_cast<unsigned char*>(needle);

		while (plen >= nlen && ((p = static_cast<unsigned char*>(memchr(p, needle_first, plen - nlen + 1)))))
		{
			if (!memcmp(p, needle, nlen))
				return p;
			p++;
			plen = hlen - (p - haystack);
		}

		return nullptr;
	}
	_H3API_ UINT32 H3Patcher::FindByNeedle(PUINT8 address, UINT32 max_search_length, PUINT8 needle, INT32 needle_length, INT32 offset)
	{
		if (!address)
			return NULL;

		UINT32 p = reinterpret_cast<UINT32>(H3Patcher::Memmem(address, max_search_length, needle, needle_length));
		if (p)
			p += offset;
		return p;
	}

	_H3API_ BOOL H3Patcher::NakedHook5(UINT32 address, H3NakedFunction function)
	{
		H3Protect protect(address, 5);
		if (protect.CanWrite())
		{
			ByteAt(address)      = H3Patcher::JMP;
			DwordAt(address + 1) = reinterpret_cast<UINT32>(function) - address - 5;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ BOOL H3Patcher::NakedHook(UINT32 address, H3NakedFunction function, UINT32 total_bytes)
	{
		if (total_bytes < 5)
			return FALSE;
		H3Protect protect(address, total_bytes);
		if (protect.CanWrite())
		{
			ByteAt(address)      = H3Patcher::JMP;
			DwordAt(address + 1) = reinterpret_cast<UINT32>(function) - address - 5;
			for (UINT32 i = 5; i < total_bytes; ++i)
				ByteAt(address + i) = H3Patcher::NOP;
			return TRUE;
		}
		return FALSE;
	}

	_H3API_ BOOL H3Patcher::BytePatch(ADDRESS address, UINT8 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::CharPatch(ADDRESS address, INT8 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::WordPatch(ADDRESS address, UINT16 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::ShortPatch(ADDRESS address, INT16 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::DwordPatch(ADDRESS address, UINT32 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::IntPatch(ADDRESS address, INT32 value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::FloatPatch(ADDRESS address, FLOAT value)
	{
		return WriteValue(address, value);
	}

	_H3API_ BOOL H3Patcher::DoublePatch(ADDRESS address, DOUBLE value)
	{
		return WriteValue(address, value);
	}

	_H3API_ H3DLL::H3DLL() :
		code(),
		size(),
		dllName(),
		rdata(),
		rdataSize(),
		data(),
		dataSize()
	{
	}
	_H3API_ H3DLL::H3DLL(LPCSTR dll_name) :
		code(),
		size(),
		dllName(dll_name),
		rdata(),
		rdataSize(),
		data(),
		dataSize()
	{
		GetDLLInfo(dll_name);
	}
	_H3API_ VOID H3DLL::needleNotFound(PUINT8 needle, INT32 needle_size, BOOL in_code) const
	{
		H3String needleBuffer, message;
		for (int i = 0; i < needle_size; i++)
			needleBuffer.PrintfAppend("%02X ", needle[i]);

		if (in_code)
			message.Printf("Could not find needle:\n\n%s\n\nIn module: \"%s\".\n\nCode start: 0x%08X\n\nDLL size: 0x%08X",
				needleBuffer.String(), dllName, (UINT32)code, size);
		else
			message.Printf("Could not find needle:\n\n%s\n\nIn data of module: \"%s\".\n\nData start: 0x%08X\n\nDLL data size: 0x%08X",
				needleBuffer.String(), dllName, (UINT32)rdata, rdataSize);
		H3Error::ShowError(message.String(), "Needle not found!");
	}
	_H3API_ VOID H3DLL::needleUnexpectedCode(UINT32 address, PUINT8 needle, INT32 needle_size, PUINT8 expected_code, INT32 expected_size) const
	{
		H3String message;
		H3String needle_buffer, expected_buffer, found_buffer;
		for (int i = 0; i < needle_size; i++)
			needle_buffer.PrintfAppend("%02X ", needle[i]);

		PCHAR adr = reinterpret_cast<PCHAR>(address);
		for (int i = 0; i < expected_size; i++)
		{
			expected_buffer.PrintfAppend("%02X ", expected_code[i]);
			found_buffer.PrintfAppend("%02X ", adr[i]);
		}
		message.Printf("Found needle:\n\n%s\n\nIn Module \"%s\".\n\nHowever, expected code...\n\n%s\n\n...does not match existing code:\n\n%s",
			needle_buffer.String(), dllName, expected_buffer.String(), found_buffer.String());
		H3Error::ShowError(message.String(), "Needle not found!");
	}
	_H3API_ VOID H3DLL::processNotFound() const
	{
		H3String message;
		message.Printf("Module \"%s\" could not be found!", dllName);
		H3Error::ShowError(message.String(), "DLL not found!");
	}
	_H3API_ BOOL H3DLL::GetDLLInfo(LPCSTR name)
	{
		dllName = name;
		HMODULE hm = GetModuleHandleA(name);
		if (!hm)
		{
#ifdef _H3DLL_DEBUG_
			processNotFound();
#endif
			return FALSE;
		}
		IMAGE_DOS_HEADER* pDOSHeader = reinterpret_cast<IMAGE_DOS_HEADER*>(hm);
		IMAGE_NT_HEADERS* pNTHeaders = reinterpret_cast<IMAGE_NT_HEADERS*>(reinterpret_cast<BYTE*>(pDOSHeader) + pDOSHeader->e_lfanew);
		code = PUINT8(reinterpret_cast<DWORD>(hm) + pNTHeaders->OptionalHeader.BaseOfCode);
		size = UINT32(pNTHeaders->OptionalHeader.SizeOfCode);

		IMAGE_SECTION_HEADER* pSectionHdr = reinterpret_cast<IMAGE_SECTION_HEADER*>(pNTHeaders + 1);

		for (int i = 0; i < pNTHeaders->FileHeader.NumberOfSections; i++, pSectionHdr++)
		{
			const LPCSTR l_name = reinterpret_cast<LPCSTR>(pSectionHdr->Name);
			if (!memcmp(l_name, ".rdata", sizeof(".rdata"))) // no -1 to sizeof() to include \0 null terminator
			{
				rdata = reinterpret_cast<PUINT8>(reinterpret_cast<DWORD>(hm) + pSectionHdr->VirtualAddress);
				rdataSize = pSectionHdr->Misc.VirtualSize;
			}
			if (!memcmp(l_name, ".data", sizeof(".data"))) // no -1 to sizeof() to include \0 null terminator
			{
				data = reinterpret_cast<PUINT8>(reinterpret_cast<DWORD>(hm) + pSectionHdr->VirtualAddress);
				dataSize = pSectionHdr->Misc.VirtualSize;
			}
		}
		return TRUE;
	}
	_H3API_ UINT32 H3DLL::NeedleSearch(PUINT8 needle, INT32 needle_size, INT32 offset)
	{
		UINT32 p = H3Patcher::FindByNeedle(code, size, needle, needle_size, offset);
#ifdef _H3DLL_DEBUG_
		if (!p)
			needleNotFound(needle, needle_size);
#endif
		return p;
	}
	_H3API_ UINT32 H3DLL::NeedleSearchAround(PUINT8 needle, INT32 needle_size, INT32 radius, PUINT8 needle2, INT32 needle_size2)
	{
		UINT32 p = NeedleSearch(needle, needle_size, 0);
		if (p)
		{
			UINT32 low = std::max(reinterpret_cast<UINT32>(code), p - radius);
			UINT32 searchLength = std::min(static_cast<UINT32>(2 * radius), size - (p - (UINT32)code));
			p = H3Patcher::FindByNeedle(reinterpret_cast<PUINT8>(low), searchLength, needle2, needle_size2, 0);
#ifdef _H3DLL_DEBUG_
			if (!p)
				needleNotFound(needle2, needle_size2);
#endif
		}
		return p;
	}
	_H3API_ UINT32 H3DLL::NeedleSearchAfter(UINT32 after, const PUINT8 needle, INT32 needle_size, INT32 offset) const
	{
		UINT32 p = H3Patcher::FindByNeedle(reinterpret_cast<PUINT8>(after), size - (after - reinterpret_cast<UINT32>(code)), needle, needle_size, offset);
#ifdef _H3DLL_DEBUG_
		if (!p)
			needleNotFound(needle, needle_size);
#endif
		return p;
	}
	_H3API_ UINT32 H3DLL::NeedleSearchConfirm(PUINT8 needle, INT32 needle_size, INT32 offset, PUINT8 expected_code, INT32 expected_size)
	{
		UINT32 p = NeedleSearch(needle, needle_size, offset);
		if (p)
		{
			if (memcmp(reinterpret_cast<PVOID>(p), expected_code, expected_size) != 0)
			{
#ifdef _H3DLL_DEBUG_
				needleUnexpectedCode(p, needle, needle_size, expected_code, expected_size);
#endif
				p = 0;
			}
		}
		return p;
	}
	_H3API_ UINT32 H3DLL::NeedleSearchRData(PUINT8 needle, INT32 needle_size) const
	{
		UINT32 p = H3Patcher::FindByNeedle(rdata, rdataSize, needle, needle_size, 0);
#ifdef _H3DLL_DEBUG_
		if (!p)
			needleNotFound(needle, needle_size, FALSE);
#endif
		return p;
	}
	_H3API_ UINT32 H3DLL::NeedleSearchData(PUINT8 needle, INT32 needle_size) const
	{
		UINT32 p = H3Patcher::FindByNeedle(data, dataSize, needle, needle_size, 0);
#ifdef _H3DLL_DEBUG_
		if (!p)
			needleNotFound(needle, needle_size, FALSE);
#endif
		return p;
	}
}

namespace h3
{
    _H3API_ H3Path::iterator::iterator(const H3String & filename) :
        m_handle(FindFirstFileA(filename.String(), &m_data))
    {
    }
    _H3API_ H3Path::iterator::iterator(HANDLE handle) :
        m_handle(handle), m_data()
    {
    }
    _H3API_ H3Path::iterator::~iterator()
    {
        if (m_handle && m_handle != INVALID_HANDLE_VALUE)
            FindClose(m_handle);
    }
    _H3API_ H3Path::iterator& H3Path::iterator::operator*()
    {
        return *this;
    }
    _H3API_ H3Path::iterator& H3Path::iterator::operator++()
    {
        if (m_handle && m_handle != INVALID_HANDLE_VALUE)
        {
            if (!FindNextFileA(m_handle, &m_data))
            {
                FindClose(m_handle);
                m_handle = INVALID_HANDLE_VALUE;
            }
        }
        return *this;
    }
    _H3API_ LPCSTR H3Path::iterator::Extension() const
    {
        return H3Path::Extension(m_data.cFileName);
    }
    _H3API_ H3String H3Path::iterator::FilePath() const
    {
        return GetPathName(FileName());
    }
    _H3API_ LPCSTR H3Path::iterator::FileName() const
    {
        return m_data.cFileName;
    }
    _H3API_ DWORD H3Path::iterator::Attributes() const
    {
        return m_data.dwFileAttributes;
    }
    _H3API_ DWORD H3Path::iterator::FilseSize() const
    {
        return m_data.nFileSizeLow;
    }
    _H3API_ BOOL H3Path::iterator::IsDirectory() const
    {
        return H3Path::IsDirectory(Attributes());
    }
    _H3API_ BOOL H3Path::iterator::IsFile() const
    {
        return H3Path::IsFile(Attributes());
    }

    _H3API_ BOOL H3Path::iterator::IsValid() const
    {
        return H3Path::IsValid(Attributes());
    }

    _H3API_ BOOL H3Path::iterator::FileExists() const
    {
        return H3Path::FileExists(Attributes());
    }

    _H3API_ BOOL H3Path::iterator::operator==(const iterator & other) const
    {
        if (this == &other)
            return TRUE;
        return m_handle == other.m_handle;
    }

    _H3API_ BOOL H3Path::iterator::operator!=(const iterator & other) const
    {
        return !(*this == other);
    }

    _H3API_ BOOL H3Path::IsDirectory(LPCSTR name)
    {
        return IsDirectory(GetAttributes(name));
    }
    _H3API_ BOOL H3Path::IsFile(LPCSTR name)
    {
        return IsFile(GetAttributes(name));
    }
    _H3API_ BOOL H3Path::IsValid(LPCSTR name)
    {
        return IsValid(GetAttributes(name));
    }
    _H3API_ BOOL H3Path::FileExists(LPCSTR name)
    {
        return FileExists(GetAttributes(name));
    }
    _H3API_ BOOL H3Path::IsDirectory(DWORD attribute)
    {
        return IsValid(attribute) && attribute & FILE_ATTRIBUTE_DIRECTORY;
    }
    _H3API_ BOOL H3Path::IsFile(DWORD attribute)
    {
        return IsValid(attribute) && !(attribute & FILE_ATTRIBUTE_DIRECTORY);
    }
    _H3API_ BOOL H3Path::IsValid(DWORD attribute)
    {
        return attribute != INVALID_FILE_ATTRIBUTES;
    }
    _H3API_ BOOL H3Path::FileExists(DWORD attribute)
    {
        return IsValid(attribute) && (attribute & FILE_ATTRIBUTE_ARCHIVE);
    }
    _H3API_ DWORD H3Path::GetAttributes(LPCSTR name)
    {
        return GetFileAttributesA(name);
    }
    _H3API_ H3String H3Path::CurrentDirectory()
    {
        char tmp[MAX_PATH];
        if (GetCurrentDirectoryA(MAX_PATH, tmp))
        {
            H3String dir(tmp);
            dir += '\\';
            return dir;
        }
        return H3String();
    }
    _H3API_ H3String H3Path::ProcessPath()
    {
        return ModulePath(NULL);
    }
    _H3API_ H3String H3Path::ModulePath(HMODULE hmodule)
    {
        char tmp[MAX_PATH];
        if (GetModuleFileNameA(hmodule, tmp, MAX_PATH))
        {
            H3String path(tmp);
            return GetDir(path);
        }
        return H3String();
    }
    _H3API_ H3String H3Path::GetDir(const H3String & path)
    {
        if (path.Empty() || path.Length() < 3)
            return H3String();

        INT32 len = path.Length() - 1;

        while (len >= 3)
        {
            if (path[len] == '/' || path[len] == '\\')
                return H3String(path.String(), len + 1);

            --len;
        }
        return H3String();
    }
    _H3API_ H3String H3Path::DirUp(const H3String & dir)
    {
        if (dir.Empty() || dir.Length() < 3)
            return H3String();

        INT32 len = dir.Length() - 1;
        BOOL first = TRUE;
        while (len >= 3)
        {
            if (dir[len] == '/' || dir[len] == '\\')
            {
                if (!first)
                    return H3String(dir.String(), len + 1);
                first = FALSE;
            }
            --len;
        }
        return H3String();
    }
    _H3API_ BOOL H3Path::CreateDir(const H3String & dir)
    {
        if (dir.Empty())
            return false;

        if (CreateDirectoryA(dir.String(), 0))
            return true;

        if (!CreateDir(DirUp(dir))) // recursively create upper directories
            return false;

        return CreateDirectoryA(dir.String(), 0);
    }

    _H3API_ H3DirectoryChanger::H3DirectoryChanger(LPCSTR dir) :
#ifdef _H3API_CPLUSPLUS11_
        m_oldDir(std::move(H3Path::CurrentDirectory())),
#else
        m_oldDir(H3Path::CurrentDirectory()),
#endif
        m_status()
    {
        if (!m_oldDir.Empty())
            m_status = SetCurrentDirectoryA(dir);
    }
    _H3API_ H3DirectoryChanger::~H3DirectoryChanger()
    {
        if (!m_oldDir.Empty())
            SetCurrentDirectoryA(m_oldDir.String());
    }
    _H3API_ BOOL H3DirectoryChanger::Status() const
    {
        return m_status;
    }

    _H3API_ H3String H3Path::GetPathName(const H3String& file)
    {
        return GetPathName(file.String());
    }

    _H3API_ H3String H3Path::GetPathName(LPCSTR file)
    {
        CHAR tmp[MAX_PATH + 1];
        if (libc::GetFullPathNameA(file, MAX_PATH, tmp, nullptr))
            return H3String(tmp);
        return H3String();
    }

    _H3API_ LPCSTR H3Path::Extension(LPCSTR file_name)
    {
        LPCSTR ext = libc::strrchr(file_name, '.');
        return ext ? ext + 1 : ext;
    }

    _H3API_ LPCSTR H3Path::Extension(const H3String& file_name)
    {
        UINT32 len = file_name.Length();
        if (len == 0)
            return file_name.String();
        --len;
        while (len > 0)
        {
            if (file_name[len] == '.')
                return file_name.String() + len - 1;
            --len;
        }
        return file_name.String() + len;
    }

    _H3API_ INT32 H3Path::GetModuleFileNameA(HMODULE hmodule, PCHAR buf, INT buf_len)
    {
        return STDCALL_3(INT, IntAt(0x63A100), hmodule, buf, buf_len);
    }

    _H3API_ H3String H3Path::GetModuleFileNameA(HMODULE hmodule)
    {
        CHAR buffer[MAX_PATH];
        INT32 len = GetModuleFileNameA(hmodule, buffer, MAX_PATH);
        buffer[len] = 0; // for winXP
        return H3String(buffer, len);
    }

    _H3API_ H3Path::H3Path(const H3Path& path) :
        m_path(path.m_path), m_attributes(path.m_attributes)
    {
    }
    _H3API_ H3Path::H3Path(const H3String & path) :
        m_path(path), m_attributes(GetAttributes(path.String()))
    {
        if (IsDirectory())
        {
            CHAR last = m_path.Last();
            if (last != '/' && last != '\\')
                m_path += '/';
        }
    }
    _H3API_ H3Path::H3Path(LPCSTR path) :
        m_path(path), m_attributes(GetAttributes(path))
    {
    }
#ifdef _H3API_CPLUSPLUS11_
    _H3API_ H3Path::H3Path(H3Path&& path) :
        m_path(std::move(path.m_path)), m_attributes(path.m_attributes)
    {
    }
    _H3API_ H3Path & H3Path::operator=(H3Path && path)
    {
        m_path.Dereference();
        m_path = std::move(path.m_path);
        m_attributes = path.m_attributes;
        return *this;
    }
#endif
    _H3API_ H3Path::iterator H3Path::begin() const
    {
        if (IsDirectory())
        {
            H3String p(m_path);
            p += '*';
            return iterator(p);
        }
        return iterator(m_path);
    }
    _H3API_ H3Path::iterator H3Path::end() const
    {
        return iterator(INVALID_HANDLE_VALUE);
    }
    _H3API_ H3Path & H3Path::operator=(const H3Path & path)
    {
        m_path.Dereference();
        m_path = path.m_path;
        m_attributes = path.m_attributes;
        return *this;
    }
    _H3API_ H3Path & H3Path::operator+=(const H3Path & path)
    {
        m_path += path.m_path;
        m_attributes = GetAttributes(m_path.String());
        return *this;
    }
    _H3API_ H3Path H3Path::operator/(const H3Path & path)
    {
        H3String tmp(m_path);
        if (!(tmp.Last() == '/' || tmp.Last() == '\\'))
            tmp += '/';
        tmp += path.m_path;
        return H3Path(tmp);
    }
    _H3API_ H3Path & H3Path::operator/=(const H3Path & path)
    {
        if (!(m_path.Last() == '/' || m_path.Last() == '\\'))
            m_path += '/';
        m_path += path.m_path;
        m_attributes = GetAttributes(m_path.String());
        return *this;
    }
    _H3API_ BOOL H3Path::operator!=(const H3Path & path) const
    {
        return !(m_path == path.m_path);
    }
    _H3API_ BOOL H3Path::operator==(const H3Path & path) const
    {
        return m_path == path.m_path;
    }
    _H3API_ H3Path & H3Path::Append(const H3Path & path)
    {
        return operator/=(path);
    }
    _H3API_ BOOL H3Path::IsValid() const
    {
        return IsValid(m_attributes);
    }
    _H3API_ BOOL H3Path::IsDirectory() const
    {
        return IsDirectory(m_attributes);
    }
    _H3API_ BOOL H3Path::IsFile() const
    {
        return IsFile(m_attributes);
    }
    _H3API_ BOOL H3Path::IsRoot() const
    {
        if (m_path.Length() == 1 && m_path[0] == '/')
            return true;
        return m_path.Length() == 3 && m_path[1] == ':';
    }
    _H3API_ BOOL H3Path::CreateDir() const
    {
        return CreateDir(m_path);
    }
    _H3API_ BOOL H3Path::FileExists() const
    {
        return FileExists(m_attributes);
    }
    _H3API_ BOOL H3Path::ReplaceExtension(const H3String & ext)
    {
        if (ext.Empty())
            return FALSE;

        H3String currExt = GetExtension();
        if (currExt.Empty())
            return FALSE;
        INT dot = 0;
        if (ext[0] == '.')
            dot = 1;
        m_path.SetLength(m_path.Length() - currExt.Length() - dot);
        m_path += ext;
        return TRUE;
    }
    _H3API_ H3String H3Path::GetExtension() const
    {
        if (!IsFile())
            return H3String();

        INT32 pos = m_path.FindLastOf('.');
        if (pos == H3String::npos)
            return H3String();

        return H3String(m_path.String() + pos + 1);
    }
    _H3API_ const H3String& H3Path::GetPath() const
    {
        return m_path;
    }
    _H3API_ H3Path::operator LPCSTR() const
    {
        return m_path.String();
    }

    _H3API_ H3DirectoryChanger::H3DirectoryChanger(const H3String& dir) :
#ifdef _H3API_CPLUSPLUS11_
        m_oldDir(std::move(H3Path::CurrentDirectory())),
#else
        m_oldDir(H3Path::CurrentDirectory()),
#endif
        m_status()
    {
        if (!m_oldDir.Empty())
            m_status = SetCurrentDirectoryA(dir.String());
    }

    _H3API_ H3DirectoryChanger::H3DirectoryChanger(const H3Path& dir)  :
#ifdef _H3API_CPLUSPLUS11_
        m_oldDir(std::move(H3Path::CurrentDirectory())),
#else
        m_oldDir(H3Path::CurrentDirectory()),
#endif
        m_status()
    {
        if (!m_oldDir.Empty())
            m_status = SetCurrentDirectoryA(dir.GetPath().String());
    }

    _H3API_ H3DirectoryTraveler::iterator::iterator() :
        m_handle(INVALID_HANDLE_VALUE), m_data(), m_parent()
    {
    }

    _H3API_ H3DirectoryTraveler::iterator::iterator(LPCSTR filename, H3DirectoryTraveler* parent) :
        m_handle(FindFirstFileA(filename, &m_data)), m_parent(parent)
    {
    }

    _H3API_ H3DirectoryTraveler::iterator::~iterator()
    {
        if (m_handle && m_handle != INVALID_HANDLE_VALUE)
            FindClose(m_handle);
    }

    _H3API_ H3DirectoryTraveler::iterator& H3DirectoryTraveler::iterator::operator++()
    {
        while (!next())
        {
            if (!m_handle || m_handle == INVALID_HANDLE_VALUE)
                break;
        }
        return *this;
    }

    _H3API_ H3DirectoryTraveler::iterator& H3DirectoryTraveler::iterator::operator*()
    {
        return *this;
    }

    _H3API_ LPCSTR H3DirectoryTraveler::iterator::Extension() const
    {
        return H3Path::Extension(m_data.cFileName);
    }

    _H3API_ H3String H3DirectoryTraveler::iterator::FilePath() const
    {
        return H3Path::GetPathName(FileName());
    }

    _H3API_ LPCSTR H3DirectoryTraveler::iterator::FileName() const
    {
        return m_data.cFileName;
    }

    _H3API_ DWORD H3DirectoryTraveler::iterator::Attributes() const
    {
        return m_data.dwFileAttributes;
    }

    _H3API_ DWORD H3DirectoryTraveler::iterator::FilseSize() const
    {
        return m_data.nFileSizeLow;
    }

    _H3API_ BOOL H3DirectoryTraveler::iterator::IsDirectory() const
    {
        return H3Path::IsDirectory(Attributes());
    }

    _H3API_ BOOL H3DirectoryTraveler::iterator::IsFile() const
    {
        return H3Path::IsFile(Attributes());
    }

    _H3API_ BOOL H3DirectoryTraveler::iterator::IsValid() const
    {
        return H3Path::IsValid(Attributes());
    }

    _H3API_ BOOL H3DirectoryTraveler::iterator::FileExists() const
    {
        return H3Path::FileExists(Attributes());
    }

    _H3API_ BOOL8 H3DirectoryTraveler::iterator::operator==(const iterator& other) const
    {
        if (this == &other)
            return TRUE;
        return m_handle == other.m_handle;
    }

    _H3API_ BOOL8 H3DirectoryTraveler::iterator::operator!=(const iterator& other) const
    {
        return !(*this == other);
    }

    _H3API_ BOOL32 H3DirectoryTraveler::iterator::isNotRelativeDir() const
    {
        return libc::strcmp(FileName(), ".") && libc::strcmp(FileName(), "..");
    }

    _H3API_ BOOL32 H3DirectoryTraveler::iterator::next()
    {
        if (!m_handle || m_handle == INVALID_HANDLE_VALUE)
            return FALSE;

        if (!FindNextFileA(m_handle, &m_data))
        {
            if (m_parent->remainingDirectories())
            {
                FindClose(m_handle);
                m_handle = m_parent->nextDirectoryIteration(m_data);
            }
            else
            {
                FindClose(m_handle);
                m_handle = INVALID_HANDLE_VALUE;
                return false;
            }
        }
        if (IsDirectory() && isNotRelativeDir())
            m_parent->addDirectory(FileName());

        if (m_parent->m_type.Empty())
            return TRUE;
        return m_parent->m_type.Equals_i(Extension());
    }

    _H3API_ H3DirectoryTraveler::H3DirectoryTraveler(const H3String& file_type /*= ""*/, INT32 max_depth /*= -1*/) :
        m_startDirectory(H3Path::CurrentDirectory()), m_type(file_type), m_directories(), m_index(0u), m_nextDepthIndex(1u), m_maxDepth(max_depth)
    {
        m_directories.Add(m_startDirectory);
    }

    _H3API_ H3DirectoryTraveler::H3DirectoryTraveler(const H3Path& directory, const H3String& file_type, INT32 max_depth) :
        m_startDirectory(H3Path::CurrentDirectory()), m_type(file_type), m_directories(), m_index(0u), m_nextDepthIndex(1u), m_maxDepth(max_depth)
    {
        if (directory.IsDirectory())
        {
            m_directories.Add(directory.GetPath());
            setDirectory(directory.GetPath());
        }
    }

    _H3API_ H3DirectoryTraveler::~H3DirectoryTraveler()
    {
        if (!m_directories.IsEmpty())
            setDirectory(m_startDirectory);
    }

    _H3API_ H3DirectoryTraveler::iterator H3DirectoryTraveler::begin()
    {
        if (m_directories.IsEmpty())
            return iterator();
        return iterator("*", this);
    }

    _H3API_ H3DirectoryTraveler::iterator H3DirectoryTraveler::end()
    {
        return iterator();
    }

    _H3API_ H3String& H3DirectoryTraveler::currentDir() const
    {
        return m_directories[m_index];
    }

    _H3API_ BOOL32 H3DirectoryTraveler::remainingDirectories() const
    {
        return m_directories.Size() > m_index + 1;
    }

    _H3API_ BOOL32 H3DirectoryTraveler::setDirectory(const H3String& directory)
    {
        return SetCurrentDirectoryA(directory.String());
    }

    _H3API_ VOID H3DirectoryTraveler::addDirectory(LPCSTR filename)
    {
        if (m_maxDepth == 0)
            return;
        m_directories.Add(currentDir() + '\\' + filename);
    }

    _H3API_ VOID H3DirectoryTraveler::decreaseDepth()
    {
        if (m_maxDepth > 0)
            --m_maxDepth;
    }

    _H3API_ VOID H3DirectoryTraveler::newDepthCheck()
    {
        if (m_index >= m_nextDepthIndex)
        {
            m_nextDepthIndex = m_directories.Size();
            decreaseDepth();
        }
    }

    _H3API_ HANDLE H3DirectoryTraveler::nextDirectoryIteration(WIN32_FIND_DATAA& data)
    {
        ++m_index;
        newDepthCheck();
        if (!setDirectory(currentDir()))
            return INVALID_HANDLE_VALUE;
        return FindFirstFileA("*", &data);
    }

}

namespace h3
{

} /* namespace h3 */

namespace h3
{
	_H3API_ VOID H3Random::SetRandomSeed(UINT seed)
	{
		srand(seed);
	}
	_H3API_ VOID H3Random::SetRandomSeed()
	{
		SetRandomSeed(GetTime());
	}
	_H3API_ INT32 H3Random::Random(INT32 high)
	{
		const INT32 num_bins = high + 1;
		const INT32 num_rand = RAND_MAX + 1;
		const INT32 bin_size = num_rand / num_bins;
		const INT32 defect   = num_rand % num_bins;

		INT32 x;
		do { x = rand(); } while (num_rand - defect <= x);

		return x / bin_size;
	}
	_H3API_ INT32 H3Random::RandBetween(INT32 low, INT32 high)
	{
		return H3Random::Random(high - low) + low;
	}
	_H3API_ INT32 H3Random::MultiplayerRandom(INT32 min_value, INT32 max_value)
	{
		return FASTCALL_2(INT, 0x50B3C0, min_value, max_value);
	}

	_H3API_ INT32 H3Random::PeekRand()
	{
		SeedRestore restore;
		return Rand();
	}
	_H3API_ INT32 H3Random::PeekRand(INT32 low, INT32 high)
	{
		SeedRestore restore;
		return Rand(low, high);
	}
	_H3API_ INT32 H3Random::Rand()
	{
		return STDCALL_0(INT32, 0x61842C);
	}
	_H3API_ INT32 H3Random::Rand(INT32 low, INT32 high)
	{
		return FASTCALL_2(INT32, 0x50C7C0, low, high);
	}
	_H3API_ VOID H3Random::Srand(UINT32 seed)
	{
		CDECL_1(VOID, 0x61841F, seed);
	}
	_H3API_ UINT32 H3Random::ThreadLocalSingleton::CurrentSeed() const
	{
		return currentSeedValue;
	}
	_H3API_ VOID H3Random::ThreadLocalSingleton::SetSeed(UINT32 value)
	{
		currentSeedValue = value;
	}
	_H3API_ DWORD H3Random::ThreadLocalSingleton::GetLastError() const
	{
		return lastError;
	}
	_H3API_ VOID H3Random::ThreadLocalSingleton::SetLastError(DWORD error)
	{
		THISCALL_2(VOID, 0x619E2B, this, error);
	}
	_H3API_ H3Random::ThreadLocalSingleton& H3Random::ThreadLocalSingleton::Get()
	{
		return STDCALL_0(H3Random::ThreadLocalSingleton&, 0x61D8C3);
	}
	_H3API_ H3Random::SeedRestore::SeedRestore() :
		m_tls(H3Random::ThreadLocalSingleton::Get()),
		m_oldSeed(m_tls.CurrentSeed())
	{
	}
	_H3API_ H3Random::SeedRestore::~SeedRestore()
	{
		m_tls.SetSeed(m_oldSeed);
	}

} /* namespace h3 */

namespace h3
{
	_H3API_ H3Stream::H3Stream(LPCSTR filename, StreamMode read_write_mode, BOOL read_to_buffer) :
		m_file(nullptr),
		m_size(0),
		m_mode(read_write_mode),
		m_writeHex(FALSE),
		m_writeNewLines(FALSE),
		m_status(StreamStatus::SS_NOT_LOADED),
		m_buffer(nullptr),
		m_bufferSize(0),
		m_bufferPosition(0)
	{
		LPCSTR mode = getModeFormat();
		if (mode)
		{
			if ((m_file = fopen(filename, mode)))
			{
				m_status = StreamStatus::SS_OK;
				m_size = GetFileSize(m_file);
			}
			if (read_to_buffer && m_size && canRead())
				ReadFile(m_size);
		}
	}
	_H3API_ H3Stream::H3Stream(LPCSTR filename, LPCSTR read_write_mode, BOOL read_to_buffer) :
		m_file(nullptr),
		m_size(0),
		m_mode(StreamMode::SM_INVALID),
		m_writeHex(FALSE),
		m_writeNewLines(FALSE),
		m_status(StreamStatus::SS_NOT_LOADED),
		m_buffer(nullptr),
		m_bufferSize(0),
		m_bufferPosition(0)
	{
		m_mode = getMode(read_write_mode);

		if (m_mode != StreamMode::SM_INVALID)
		{
			if ((m_file = fopen(filename, read_write_mode)))
			{
				m_status = StreamStatus::SS_OK;
				m_size = GetFileSize(m_file);
			}
			if (read_to_buffer && m_size && canRead())
				ReadFile(m_size);
		}
	}
	_H3API_ H3Stream::~H3Stream()
	{
		if (m_file)
		{
			fclose(m_file);
			m_file = nullptr;
		}
		if (m_buffer)
		{
			ByteAllocator().deallocate(m_buffer);
			m_buffer = nullptr;
		}
	}
	_H3API_ H3Stream& H3Stream::hex()
	{
		m_writeHex = TRUE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::decimal()
	{
		m_writeHex = FALSE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::new_lines()
	{
		m_writeNewLines = TRUE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::no_new_lines()
	{
		m_writeNewLines = FALSE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::endl()
	{
		if (IsReady() && canWrite())
			CDECL_3(int, 0x61A031, m_file, "%s", "\r\n");
		return *this;
	}
	_H3API_ BOOL H3Stream::IsReady() const
	{
		return m_status == StreamStatus::SS_OK;
	}
	_H3API_ H3Stream::StreamStatus H3Stream::GetStatus() const
	{
		return m_status;
	}
	_H3API_ H3Stream::StreamMode H3Stream::GetMode() const
	{
		return m_mode;
	}
	_H3API_ BOOL H3Stream::Copy(LPCSTR destination)
	{
		if (!(int(m_mode) & (MV_READ | MV_UPDATE)))
			return FALSE;

		if ((!m_bufferSize || !m_buffer) && !ReadFile(m_size))
			return FALSE;

		fread(m_buffer, 1, m_size, m_file);

		H3Stream dest(destination, StreamMode::SM_WRITE_BINARY);
		if (dest.GetStatus() == StreamStatus::SS_OK)
			fwrite(m_buffer, 1, m_size, dest.m_file);

		return TRUE;
	}
	_H3API_ BOOL H3Stream::Copy(const H3String& destination)
	{
		if (destination.String() && destination.Length())
			return Copy(destination.String());
		return FALSE;
	}
#ifndef _H3API_CPLUSPLUS11_
	_H3API_	H3Stream& H3Stream::Write(LPCSTR format, ...)
	{
		if (IsReady() && canWrite())
		{
			va_list args;
			va_start(args, format);
#pragma warning(push)
#pragma warning(disable : 4996)
			INT32 len = _vsnprintf(nullptr, 0, format, args);
#pragma warning(pop)
			H3String buffer;
			if (len > 0 && buffer.Reserve(len + 1))
			{
				len = libc::vsprintf(buffer.Begin(), format, args);
				buffer.Truncate(len);
				operator<<(buffer);
			}
			va_end(args);
			writeNewLine();
	}
		return *this;
	}
#endif

	_H3API_	H3Stream& H3Stream::operator<<(const int number)
	{
		if (IsReady() && canWrite())
		{
			if (m_writeHex)
				CDECL_3(int, 0x61A031, m_file, "0x%X", number);
			else
				CDECL_3(int, 0x61A031, m_file, "%d", number);
			writeNewLine();
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const unsigned int number)
	{
		if (IsReady())
		{
			if (m_writeHex)
				CDECL_3(int, 0x61A031, m_file, "0x%X", number);
			else
				CDECL_3(int, 0x61A031, m_file, "%u", number);
			writeNewLine();
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const FLOAT number)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%f", number);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const DOUBLE number)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%f", number);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const CHAR character)
	{
		if (IsReady() && canWrite())
		{
			fputc(character, m_file);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(LPCSTR text)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%s", text);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const H3String& str)
	{
		if (IsReady() && str.String() && str.Length())
		{
			fwrite(str.String(), 1, str.Length(), m_file);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator>>(H3String& line)
	{
		line.Truncate(0);

		if (IsReady() && m_buffer && m_bufferPosition < m_bufferSize)
		{
			if (m_bufferPosition == 0 && m_bufferSize >= 3)
			{
				if (m_buffer[0] == 0xEF && m_buffer[1] == 0xBB && m_buffer[2] == 0xBF)
				{
					m_bufferPosition += 3;
				}
			}

			int len = 0;
			BYTE* start = m_buffer + m_bufferPosition;
			BYTE* current = start;
			while (m_bufferPosition < m_bufferSize && *current)
			{
				if (*current == '\n')
				{
					if (len && *(current - 1) == '\r')
						len--;
					++m_bufferPosition;
					break;
				}
				++len;
				++current;
				++m_bufferPosition;
			}
			if (len)
				line.Assign(LPCSTR(start), len);
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator>>(H3Vector<H3String>& lines)
	{
		if (!IsReady() || !m_buffer || m_bufferPosition >= m_bufferSize)
			return *this;
		lines.Deref();

		while (m_bufferPosition < m_bufferSize)
		{
			H3String line;
			operator>>(line);
			lines += line;
		}

		return *this;
	}
	_H3API_	BOOL H3Stream::ReadFile(DWORD size_to_read)
	{
		if (!IsReady() || !canRead())
			return FALSE;

		const DWORD sz = std::min(m_size, size_to_read);

		if (m_bufferSize < sz)
		{
			ByteAllocator().deallocate(m_buffer);
			m_bufferSize = sz;
			m_buffer = static_cast<PBYTE>(H3Calloc(m_bufferSize));
		}

		m_bufferPosition = 0;

		return fread(m_buffer, 1, m_bufferSize, m_file) == m_bufferSize;
	}
	_H3API_	LPCSTR H3Stream::getModeFormat()
	{
		switch (m_mode)
		{
		case StreamMode::SM_READ:
			return "r";
		case StreamMode::SM_READ_BINARY:
			return "rb";
		case StreamMode::SM_WRITE:
			return "w";
		case StreamMode::SM_WRITE_BINARY:
			return "wb";
		case StreamMode::SM_APPEND:
			return "a";
		case StreamMode::SM_APPEND_BINARY:
			return "ab";
		case StreamMode::SM_READ_UPDATE:
			return "r+";
		case StreamMode::SM_READ_UPDATE_BINARY:
			return "r+b";
		case StreamMode::SM_WRITE_UPDATE:
			return "w+";
		case StreamMode::SM_WRITE_UPDATE_BINARY:
			return "w+b";
		case StreamMode::SM_APPEND_UPDATE:
			return "a+";
		case StreamMode::SM_APPEND_UPDATE_BINARY:
			return "a+b";
		default:
			return nullptr;
		}
	}
	_H3API_	VOID H3Stream::writeNewLine()
	{
		if (m_writeNewLines)
			endl();
	}
	_H3API_	BOOL H3Stream::canWrite()
	{
		return int(m_mode) & (MV_WRITE | MV_APPEND | MV_UPDATE);
	}
	_H3API_	BOOL H3Stream::canRead()
	{
		return int(m_mode) & (MV_READ | MV_UPDATE);
	}

	_H3API_ H3Stream::StreamMode H3Stream::getMode(LPCSTR read_write_mode)
	{
		StreamMode mode = StreamMode::SM_INVALID;

		if (!read_write_mode)
			return mode;

		switch (read_write_mode[0])
		{
		case 'r':
			mode = StreamMode(MV_READ);
			break;
		case 'w':
			mode = StreamMode(MV_WRITE);
			break;
		case 'a':
			mode = StreamMode(MV_APPEND);
			break;
		default:
			break;
		}

		if (!read_write_mode[1])
			return mode;

		switch (read_write_mode[1])
		{
		case 'r':
			mode = StreamMode(int(mode) | int(StreamMode(MV_READ)));
			break;
		case 'w':
			mode = StreamMode(int(mode) | int(StreamMode(MV_WRITE)));
			break;
		case 'a':
			mode = StreamMode(int(mode) | int(StreamMode(MV_APPEND)));
			break;
		case '+':
			mode = StreamMode(int(mode) | int(StreamMode(MV_UPDATE)));
			break;
		case 'b':
			mode = StreamMode(int(mode) | int(StreamMode(MV_BINARY)));
			break;
		default:
			break;
		}

		if (!read_write_mode[2])
			return mode;

		switch (read_write_mode[2])
		{
		case 'r':
			mode = StreamMode(int(mode) | int(StreamMode(MV_READ)));
			break;
		case 'w':
			mode = StreamMode(int(mode) | int(StreamMode(MV_WRITE)));
			break;
		case 'a':
			mode = StreamMode(int(mode) | int(StreamMode(MV_APPEND)));
			break;
		case '+':
			mode = StreamMode(int(mode) | int(StreamMode(MV_UPDATE)));
			break;
		case 'b':
			mode = StreamMode(int(mode) | int(StreamMode(MV_BINARY)));
			break;
		default:
			break;
		}
		return mode;
	}

	_H3API_ INT32 H3Stream::fclose(FILE* f)
	{
		return CDECL_1(int, 0x618F5E, f);
	}
	_H3API_ INT32 H3Stream::fgetpos(FILE* f, fpos_t& pos)
	{
		return CDECL_2(INT, 0x618C56, f, &pos);
	}
	_H3API_ FILE* H3Stream::fopen(LPCSTR filename, LPCSTR mode)
	{
		return CDECL_2(FILE*, 0x619691, filename, mode);
	}
	_H3API_ INT32 H3Stream::fputc(CHAR c, FILE* f)
	{
		return CDECL_2(INT, 0x618B53, c, f);
	}
	_H3API_ BOOL H3Stream::fread(PVOID buffer, size_t size, size_t count, FILE* f)
	{
		return CDECL_4(BOOL, 0x6196A4, buffer, size, count, f);
	}
	_H3API_ INT32 H3Stream::fseek(FILE* f, INT32 offset, INT32 origin)
	{
		return CDECL_3(INT, 0x618C78, f, offset, origin);
	}
	_H3API_ INT32 H3Stream::fsetpos(FILE* f, const fpos_t& pos)
	{
		return CDECL_2(INT, 0x618D31, f, &pos);
	}
	_H3API_ DWORD H3Stream::ftell(FILE* f)
	{
		return CDECL_1(DWORD, 0x6194DD, f);
	}
	_H3API_ UINT32 H3Stream::fwrite(const VOID* buffer, UINT32 size, UINT32 count, FILE* f)
	{
		return CDECL_4(size_t, 0x618A1A, buffer, size, count, f);
	}
	_H3API_ DWORD H3Stream::GetFileSize(FILE* f)
	{
		fseek(f, 0, SEEK_END);
		DWORD size = ftell(f);
		fseek(f, 0, SEEK_SET);
		return size;
	}
	_H3API_ void H3File::getSize()
	{
		m_fileSize = GetFileSize(m_handle);
	}
	_H3API_ void H3File::clear()
	{
		if (m_buffer)
		{
			ByteAllocator().deallocate(m_buffer);
			m_buffer = nullptr;
		}
	}
	_H3API_ void H3File::close()
	{
		if (m_handle)
		{
			CloseHandle(m_handle);
			m_handle = NULL;
		}
		if (m_save)
		{
			CloseHandle(m_save);
			m_save = NULL;
		}
	}
	_H3API_ BOOL H3File::read(PVOID buffer, DWORD sizeToRead)
	{
		if (m_pointer + sizeToRead > m_fileSize)
			return FALSE;

		if (!ReadFile(m_handle, buffer, sizeToRead))
			return FALSE;
		m_pointer += sizeToRead;
		return TRUE;
	}
	_H3API_ BOOL H3File::write(const PVOID buffer, DWORD sizeToWrite)
	{
		return WriteFile(m_save, buffer, sizeToWrite);
	}
	_H3API_ H3File::H3File() :
		m_handle(),
		m_fileSize(),
		m_buffer(),
		m_pointer(),
		m_save()
	{
	}
	_H3API_ H3File::~H3File()
	{
		close();
		clear();
	}
	_H3API_ BOOL H3File::Open(LPCSTR const file)
	{
		if (!exists(file))
			return FALSE;
		getSize();
		return TRUE;
	}

	_H3API_ BOOL H3File::Open(const H3String& file)
	{
		return Open(file.String());
	}

	_H3API_ BOOL H3File::Read(const PVOID buffer, DWORD sizeToRead)
	{
		return read(buffer, sizeToRead);
	}
	_H3API_ BOOL H3File::ReadToBuffer()
	{
		if (m_buffer)
			return TRUE;

		m_buffer = ByteAllocator().allocate(m_fileSize);
		return read(m_buffer, m_fileSize);
	}
	_H3API_ BOOL H3File::Save(LPCSTR const file)
	{
		m_save = CreateFileA(file, FALSE);
		return m_save != INVALID_HANDLE_VALUE;
	}
	_H3API_ UINT H3File::Size() const
	{
		return m_fileSize;
	}
	_H3API_ const PBYTE H3File::Buffer() const
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::ReleaseBuffer()
	{
		PBYTE buffer = m_buffer;
		m_buffer = nullptr;
		return buffer;
	}
	_H3API_ BOOL H3File::SetPointer(UINT pos)
	{
		if (pos >= m_fileSize)
			return FALSE;
		m_pointer = pos;
		SetFilePointer(m_handle, m_pointer, FILE_BEGIN);
		return TRUE;
	}
	_H3API_ UINT H3File::Pointer() const
	{
		return m_pointer;
	}
	_H3API_ BOOL H3File::Skip(UINT numBytes)
	{
		if (m_pointer + numBytes >= m_fileSize)
			return FALSE;
		m_pointer += numBytes;
		SetFilePointer(m_handle, m_pointer, FILE_CURRENT);
		return TRUE;
	}
	_H3API_ PBYTE H3File::begin()
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::begin() const
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::end()
	{
		return m_buffer + m_fileSize;
	}
	_H3API_ PBYTE H3File::end() const
	{
		return m_buffer + m_fileSize;
	}
	_H3API_ VOID H3File::Close()
	{
		close();
	}
	_H3API_ BOOL H3File::Read(PVOID data, size_t data_len)
	{
		return read(data, data_len);
	}
	_H3API_ BOOL H3File::Write(PVOID data, size_t data_len)
	{
		return write(data, data_len);
	}
	_H3API_ BOOL H3File::Write(const H3String & string)
	{
		return write(PVOID(string.String()), string.Length());
	}
	_H3API_ BOOL H3File::Write(LPCSTR string)
	{
		return write(PVOID(string), libc::strlen(string));
	}

	_H3API_ H3String H3File::GetLine()
	{
		H3String line;
		if (m_pointer < m_fileSize)
		{
			if (m_pointer == 0 && m_fileSize >= 3)
			{
				if (m_buffer[0] == 0xEF && m_buffer[1] == 0xBB && m_buffer[2] == 0xBF)
				{
					m_pointer += 3;
				}
			}

			UINT len = 0;
			PCHAR start = reinterpret_cast<PCHAR>(m_buffer + m_pointer);
			PCHAR current = start;
			while (m_pointer < m_fileSize && *current)
			{
				if (*current == '\n')
				{
					if (len && *(current - 1) == '\r')
						len--;
					++m_pointer;
					break;
				}
				++len;
				++current;
				++m_pointer;
			}
			if (len)
				line.Assign(start, len);
		}
		return line;
	}
	_H3API_ H3Vector<H3String> H3File::GetLines(BOOL includeEmptyLines)
	{
		H3Vector<H3String> result;

		m_pointer = 0;
		while (m_pointer < m_fileSize)
		{
			H3String line = GetLine();
			if (includeEmptyLines || !line.Empty())
				result += line;
		}

		return result;
	}
	_H3API_ BOOL H3File::exists(LPCSTR filepath)
	{
		m_handle = CreateFileA(filepath, TRUE);
		if (m_handle == INVALID_HANDLE_VALUE)
			return FALSE;
		return TRUE;
	}
	_H3API_ VOID H3SpreadSheet::Clear()
	{
		m_lines.RemoveAll();
	}
	_H3API_ VOID H3SpreadSheet::NewLine()
	{
		m_currentLine.AppendA("\r\n");
		m_lines += m_currentLine;
		m_currentLine.Erase();
	}
	_H3API_ VOID H3SpreadSheet::NewColumn()
	{
		m_currentLine.Append('\t');
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::Hex()
	{
		m_hexMode = TRUE;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::Dec()
	{
		m_hexMode = FALSE;
		return *this;
	}
	_H3API_ BOOL H3SpreadSheet::Save(LPCSTR const file)
	{
		H3File f;
		if (!f.Save(file))
			return FALSE;
		for (UINT i = 0; i < m_lines.Size(); ++i)
		{
			if (!f.Write(m_lines[i]))
				return FALSE;
		}
		return TRUE;
	}
	_H3API_ BOOL H3SpreadSheet::Save(const H3String& file)
	{
		return Save(file.String());
	}

	_H3API_ BOOL H3SpreadSheet::InsertLine(const H3String& line, UINT row)
	{
		if (row == static_cast<UINT>(-1))
		{
			H3String* l = m_lines.Append(line);
			if (!l)
				return FALSE;
			l->AppendA("\r\n");
			return TRUE;
		}
		else
		{
			H3String l = line;
			l.AppendA("\r\n");
			return m_lines.Insert(m_lines.begin() + row, l);
		}
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(const H3SpreadSheet&)
	{
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(LPCSTR text)
	{
		addTab();
		m_currentLine += text;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(INT32 value)
	{
		addTab();
		m_currentLine.Append(value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(UINT32 value)
	{
		addTab();
		if (!m_hexMode)
		{
			m_currentLine.PrintfAppend("%u", value);
		}
		else
		{
			m_currentLine.PrintfAppend("%X", value);
		}
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(FLOAT value)
	{
		addTab();
		m_currentLine.PrintfAppend("%f", value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(DOUBLE value)
	{
		addTab();
		m_currentLine.PrintfAppend("%f", value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(CHAR ch)
	{
		addTab();
		m_currentLine += ch;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(const H3String& line)
	{
		addTab();
		m_currentLine += line;
		return *this;
	}
	_H3API_ BOOL H3File::CloseHandle(HANDLE handle)
	{
		return STDCALL_1(BOOL, PtrAt(0x63A0C8), handle);
	}
	_H3API_ HANDLE H3File::CreateFileA(LPCSTR file, BOOL open_existing)
	{
		return ::CreateFileA(file, open_existing ? GENERIC_READ : GENERIC_WRITE, 0, LPSECURITY_ATTRIBUTES(NULL),
			open_existing ? OPEN_EXISTING : CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, HANDLE(NULL));
	}
	_H3API_ DWORD H3File::GetFileSize(HANDLE handle)
	{
		DWORD file_size = 0;
		if (handle)
		{
			DWORD pos = ::SetFilePointer(handle, 0, NULL, FILE_CURRENT);
			file_size = ::SetFilePointer(handle, 0, NULL, FILE_END);
			::SetFilePointer(handle, pos, NULL, FILE_BEGIN);
		}
		return file_size;
	}
	_H3API_ BOOL H3File::ReadFile(HANDLE handle, PVOID data, DWORD bytes_to_read)
	{
		DWORD szRead;

		if (!::ReadFile(handle, data, bytes_to_read, &szRead, NULL))
			return FALSE;
		return szRead == bytes_to_read;
	}
	_H3API_ DWORD H3File::SetFilePointer(HANDLE handle, LONG position, DWORD source)
	{
		return ::SetFilePointer(handle, position, NULL, source);
	}
	_H3API_ BOOL H3File::WriteFile(HANDLE handle, PVOID buffer, DWORD bytes_to_write)
	{
		DWORD szWritten;
		if (!::WriteFile(handle, buffer, bytes_to_write, &szWritten, NULL))
			return FALSE;
		return szWritten == bytes_to_write;
	}
	_H3API_ VOID H3SpreadSheet::addTab()
	{
		if (!m_currentLine.Empty())
			m_currentLine += '\t';
	}
}

#undef _H3API_CPLUSPLUS98_
#undef _H3API_CPLUSPLUS11_
#undef _H3API_CPLUSPLUS14_
#undef _H3API_CPLUSPLUS17_
#undef _H3API_ENUM_
#undef _H3API_ENUM_OPERATORS_
#undef _H3API_DEPRECATED_
#undef _H3API_NOVTABLE_
#undef _H3API_FORCEINLINE_
#undef _H3API_DECLARE_
#undef _H3API_TEMPLATE_DECLARE_
#undef _H3API_STR_EXPAND_
#undef _H3API_STR_
#undef _H3API_SIZE_
#undef _H3API_GET_INFO_
#undef _H3API_NAMED_STRUCT_
#undef _H3API_TYPE_DECLARE_
#undef _H3API_CTOR_DTOR_
#undef _H3API_VTABLE_
#undef _H3API_STATIC_ASSERT_
#undef _H3API_CONCATENATE2_
#undef _H3API_CONCATENATE1_
#undef _H3API_CONCATENATE_
#undef _H3API_ASSERT_SIZE_
#undef _H3API_ASSERT_OFFSET_
#undef _H3API_VERSION_MAJOR_
#undef _H3API_VERSION_MINOR_
#undef _H3API_VERSION_BUILD_
#undef _H3API_
#undef _H3API_LIBRARY_

#ifdef _H3API_PATCHER_X86_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// library library patcher_x86.dll
// spread freely (free of charge)
// copyright: Barinov Alexander (baratorch), e-mail: baratorch@yandex.ru
// the form of implementation of low-level hooks (LoHook) is partly borrowed from Berserker (from ERA)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <utility>

#define _byte_ unsigned __int8
#define _word_ unsigned __int16
#define _dword_ unsigned __int32

#ifndef _bool_
#define _bool_ __int32
#endif

typedef _dword_ _ptr_;

#pragma pack(push, 4)

class Variable
{
public:
	virtual _dword_ __stdcall GetValue() = 0;
	virtual void __stdcall SetValue(_dword_ value) = 0;
	virtual _dword_* __stdcall GetPValue() = 0;
};

struct FlagsRegister
{
	_dword_ CF          : 1; //0
	_dword_ reserved_1  : 1; //1
	_dword_ PF          : 1; //2
	_dword_ reserved_3  : 1; //3
	_dword_ AF          : 1; //4
	_dword_ reserved_5  : 1; //5
	_dword_ ZF          : 1; //6
	_dword_ SF          : 1; //7
	_dword_ TF          : 1; //8
	_dword_ IF          : 1; //9
	_dword_ DF          : 1; //10
	_dword_ OF          : 1; //11
	_dword_ IOPL        : 2; //12-13
	_dword_ NT          : 1; //14
	_dword_ reserved_15 : 1; //15
	_dword_ RF          : 1; //16
	_dword_ VM          : 1; //17
	_dword_ AC          : 1; //18
	_dword_ VIF         : 1; //19
	_dword_ VIP         : 1; //20
	_dword_ ID          : 1; //21
	_dword_ reserved_22 : 1; //22
	_dword_ reserved_23 : 1; //23
	_dword_ reserved_24 : 1; //24
	_dword_ reserved_25 : 1; //25
	_dword_ reserved_26 : 1; //26
	_dword_ reserved_27 : 1; //27
	_dword_ reserved_28 : 1; //28
	_dword_ reserved_29 : 1; //29
	_dword_ reserved_30 : 1; //30
	_dword_ reserved_31 : 1; //31
};

struct HookContext
{
	int eax; //register EAX, read / modify		// +0
	int ecx; //register ECX, read / modify		// +4
	int edx; //register EDX, read / modify		// +8
	int ebx; //register EBX, read / modify		// +C
	int esp; //register ESP, read / modify		// +10
	int ebp; //register EBP, read / modify		// +14
	int esi; //register ESI, read / modify		// +18
	int edi; //register EDI, read / modify		// +1C

	_ptr_ return_address; //return address, read / modify	// +20

	FlagsRegister flags;						// +24

	inline void Push(int v)
	{
		esp -= 4;
		*(int*)(esp) = v;
	}

	inline int Pop()
	{
		int r = *(int*)(esp);
		esp += 4;
		return r;
	}
	_dword_ Retn() { return *(_dword_*)(ebp + 4); }

	int& Arg(_dword_ n) { return *reinterpret_cast<int*>(ebp + 4 + 4 * n); }

	template<typename T>
	T& Arg(_dword_ n) { return *reinterpret_cast<T*>(ebp + 4 + 4 * n); }

	int& Local(_dword_ n) { return *reinterpret_cast<int*>(ebp - 4 * n); }

	template<typename T>
	T& Local(_dword_ n) { return *reinterpret_cast<T*>(ebp - 4 * n); }

	_ptr_ LocalStack(_dword_ n) { return (ebp - 4 * n); }

	template<typename T>
	T* LocalStack(_dword_ n) { return reinterpret_cast<T*>(ebp - 4 * n); }
	_byte_& AL() { return *reinterpret_cast<_byte_*>(&eax); }
	_byte_& AH() { return  reinterpret_cast<_byte_*>(&eax)[1]; }
	_word_& AX() { return *reinterpret_cast<_word_*>(&eax); }
	_byte_& CL() { return *reinterpret_cast<_byte_*>(&ecx); }
	_byte_& CH() { return  reinterpret_cast<_byte_*>(&ecx)[1]; }
	_word_& CX() { return *reinterpret_cast<_word_*>(&ecx); }
	_byte_& DL() { return *reinterpret_cast<_byte_*>(&edx); }
	_byte_& DH() { return  reinterpret_cast<_byte_*>(&edx)[1]; }
	_word_& DX() { return *reinterpret_cast<_word_*>(&edx); }
	_byte_& BL() { return *reinterpret_cast<_byte_*>(&ebx); }
	_byte_& BH() { return  reinterpret_cast<_byte_*>(&ebx)[1]; }
	_word_& BX() { return *reinterpret_cast<_word_*>(&ebx); }
	_word_& BP() { return *reinterpret_cast<_word_*>(&ebp); }
	_word_& SI() { return *reinterpret_cast<_word_*>(&esi); }
	_word_& DI() { return *reinterpret_cast<_word_*>(&edi); }
	template<typename T>
	T& Eax() { return *reinterpret_cast<T*>(&eax); }
	template<typename T>
	T& Ebx() { return *reinterpret_cast<T*>(&ebx); }
	template<typename T>
	T& Ecx() { return *reinterpret_cast<T*>(&ecx); }
	template<typename T>
	T& Edx() { return *reinterpret_cast<T*>(&edx); }
	template<typename T>
	T& Edi() { return *reinterpret_cast<T*>(&edi); }
	template<typename T>
	T& Esi() { return *reinterpret_cast<T*>(&esi); }
	template<typename T>
	T& Esp() { return *reinterpret_cast<T*>(&esp); }
	template<typename T>
	T& Ebp() { return *reinterpret_cast<T*>(&ebp); }
	template<typename T>
	void Eax(const T& data) { eax = int(data); }
	template<typename T>
	void Ebx(const T& data) { ebx = int(data); }
	template<typename T>
	void Ecx(const T& data) { ecx = int(data); }
	template<typename T>
	void Edx(const T& data) { edx = int(data); }
	template<typename T>
	void Esi(const T& data) { esi = int(data); }
	template<typename T>
	void Edi(const T& data) { edi = int(data); }
	template<typename T>
	void Esp(const T& data) { esp = int(data); }
	template<typename T>
	void Ebp(const T& data) { ebp = int(data); }
};

#define EXEC_DEFAULT    1 // execute normal code
#define NO_EXEC_DEFAULT 0 // skip normal code
#define SKIP_DEFAULT    0

#define PATCH_  0
#define LOHOOK_ 1
#define HIHOOK_ 2

#define DATA_ 0
#define CODE_ 1

class Patch
{
public:
	virtual _ptr_ __stdcall GetAddress() = 0;

	virtual _dword_ __stdcall GetSize() = 0;

	virtual char* __stdcall GetOwner() = 0;

	virtual int  __stdcall GetType() = 0;

	virtual _bool_ __stdcall IsApplied() = 0;

	virtual _bool_ __stdcall Apply() = 0;

	virtual _bool_ __stdcall ApplyInsert(int zorder) = 0;

	virtual _bool_ __stdcall Undo() = 0;

	virtual _bool_ __stdcall Destroy() = 0;

	virtual Patch* __stdcall GetAppliedBefore() = 0;

	virtual Patch* __stdcall GetAppliedAfter() = 0;

	_ptr_ operator&() { return GetAddress(); }
};

class LoHook : public Patch
{
};

typedef int(__stdcall *_LoHookFunc_)(LoHook*, HookContext*);
typedef int(__stdcall* _LoHookReferenceFunc_)(LoHook&, HookContext&);

#define CALL_ 0
#define SPLICE_ 1
#define FUNCPTR_ 2

#define DIRECT_  0
#define EXTENDED_ 1
#define SAFE_  2

#define ANY_  0
#define STDCALL_ 0
#define THISCALL_ 1
#define FASTCALL_ 2
#define CDECL_  3
#define FASTCALL1 1

class HiHook : public Patch
{
public:
	virtual _ptr_ __stdcall GetDefaultFunc() = 0;

	virtual _ptr_ __stdcall GetOriginalFunc() = 0;

	virtual _ptr_ __stdcall GetReturnAddress() = 0;

	virtual void __stdcall SetUserData(_dword_ data) = 0;
	virtual _dword_ __stdcall GetUserData() = 0;

	_ptr_ operator()() { return GetDefaultFunc(); }
};

class PatcherInstance
{
public:
	virtual Patch* __stdcall WriteByte(_ptr_ address, int value) = 0;

	virtual Patch* __stdcall WriteWord(_ptr_ address, int value) = 0;

	virtual Patch* __stdcall WriteDword(_ptr_ address, int value) = 0;

	template<typename T>
	Patch* __stdcall WriteAddressOf(_ptr_ address, const T& data)
	{
		return WriteDword(address, reinterpret_cast<int>(&data));
	}

	virtual Patch* __stdcall WriteJmp(_ptr_ address, _ptr_ to) = 0;

	virtual Patch* __stdcall WriteHexPatch(_ptr_ address, const char* hex_str) = 0;

	virtual Patch* __stdcall WriteCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;

	virtual LoHook* __stdcall WriteLoHook(_ptr_ address, _LoHookFunc_ func) = 0;

	LoHook* WriteLoHook(_ptr_ address, _LoHookReferenceFunc_ func)
	{
		return WriteLoHook(address, _LoHookFunc_(func));
	}

	virtual HiHook* __stdcall WriteHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;
	template<typename T>
	HiHook* WriteHiHook(_ptr_ address, int hooktype, int calltype, T new_func)
	{
		return WriteHiHook(address, hooktype, EXTENDED_, calltype, reinterpret_cast<void*>(new_func));
	}
	HiHook* WriteHiHook(_ptr_ address, int calltype, void* new_func)
	{
		if (*reinterpret_cast<_byte_*>(address) == 0xE8 || *reinterpret_cast<_word_*>(address) == 0x15FF)
			return WriteHiHook(address, CALL_, EXTENDED_, calltype, new_func);
		return WriteHiHook(address, SPLICE_, EXTENDED_, calltype, new_func);
	}

	virtual Patch* __stdcall CreateBytePatch(_ptr_ address, int value) = 0;
	virtual Patch* __stdcall CreateWordPatch(_ptr_ address, int value) = 0;
	virtual Patch* __stdcall CreateDwordPatch(_ptr_ address, int value) = 0;
	virtual Patch* __stdcall CreateJmpPatch(_ptr_ address, _ptr_ to) = 0;
	virtual Patch* __stdcall CreateHexPatch(_ptr_ address, char* hex_str) = 0;
	virtual Patch* __stdcall CreateCodePatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
	virtual LoHook* __stdcall CreateLoHook(_ptr_ address, _LoHookFunc_ func) = 0;
	virtual HiHook* __stdcall CreateHiHook(_ptr_ address, int hooktype, int subtype, int calltype, void* new_func) = 0;

	virtual _bool_ __stdcall ApplyAll() = 0;

	virtual _bool_ __stdcall UndoAll() = 0;

	virtual _bool_ __stdcall DestroyAll() = 0;

	virtual Patch* __stdcall WriteDataPatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;
	virtual Patch* __stdcall CreateDataPatchVA(_ptr_ address, char* format, _dword_* va_args) = 0;

	virtual Patch* __stdcall GetLastPatchAt(_ptr_ address) = 0;

	virtual _bool_ __stdcall UndoAllAt(_ptr_ address) = 0;

	virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address) = 0;

	virtual Patch* __stdcall Write(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;
	virtual Patch* __stdcall CreatePatch(_ptr_ address, _ptr_ data, _dword_ size, _bool_ is_code = 0) = 0;

	virtual LoHook* __stdcall WriteLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;
	virtual LoHook* __stdcall CreateLoHookEx(_ptr_ address, void* func, _dword_ stack_delta) = 0;

	virtual LoHook* __stdcall WriteHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;
	virtual LoHook* __stdcall CreateHexHookVA(_ptr_ address, _bool_ exec_default, char* hex_str, _dword_* va_args) = 0;

	virtual void __stdcall BlockAt(_ptr_ address) = 0;

	virtual void __stdcall BlockAllExceptVA(_dword_ *va_args) = 0;

	virtual Patch* __stdcall WriteAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

	virtual Patch* __stdcall CreateAsmPatchVA(_ptr_ address, _dword_* va_args) = 0;

	virtual LoHook* __stdcall WriteAsmHookVA(_ptr_ address, _dword_* va_args) = 0;

	virtual LoHook* __stdcall CreateAsmHookVA(_ptr_ address, _dword_* va_args) = 0;

	inline Patch* WriteAsmPatch(_ptr_ address, ...)
	{
		return WriteAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
	}
	inline Patch* CreateAsmPatch(_ptr_ address, ...)
	{
		return CreateAsmPatchVA(address, (_dword_*)((_ptr_)&address + 4));
	}

	inline LoHook* WriteAsmHook(_ptr_ address, ...)
	{
		return WriteAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
	}

	inline LoHook* CreateAsmHook(_ptr_ address, ...)
	{
		return CreateAsmHookVA(address, (_dword_*)((_ptr_)&address + 4));
	}

	inline LoHook* WriteHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
	{
		return WriteHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
	}
	inline LoHook* CreateHexHook(_ptr_ address, _bool_ exec_default, char* format, ...)
	{
		return CreateHexHookVA(address, exec_default, format, (_dword_*)((_ptr_)&format + 4));
	}

	inline Patch* WriteCodePatch(_ptr_ address, char* format, ...)
	{
		return WriteCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
	}

	inline Patch* CreateCodePatch(_ptr_ address, char* format, ...)
	{
		return CreateCodePatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
	}

	inline Patch* WriteDataPatch(_ptr_ address, char* format, ...)
	{
		return WriteDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
	}

	inline Patch* CreateDataPatch(_ptr_ address, char* format, ...)
	{
		return CreateDataPatchVA(address, format, (_dword_*)((_ptr_)&format + 4));
	}
	inline Patch* __stdcall WriteDword(_ptr_ address, const char* value)
	{
		return WriteDword(address, int(value));
	}
};

class Patcher
{
public:
	virtual PatcherInstance* __stdcall CreateInstance(const char* owner) = 0;

	virtual PatcherInstance*  __stdcall GetInstance(const char* owner) = 0;

	virtual Patch* __stdcall GetLastPatchAt(_ptr_ address) = 0;

	virtual Patch* __stdcall UndoAllAt(_ptr_ address) = 0;

	virtual void __stdcall SaveDump(const char* file_name) = 0;

	virtual void __stdcall SaveLog(const char* file_name) = 0;

	virtual int __stdcall GetMaxPatchSize() = 0;

	virtual int __stdcall WriteComplexDataVA(_ptr_ address, char* format, _dword_* args) = 0;

	virtual int __stdcall GetOpcodeLength(_ptr_ p_opcode) = 0;

	virtual int __stdcall MemCopyCode(_ptr_ dst, _ptr_ src, _dword_ size) = 0;

	virtual Patch* __stdcall GetFirstPatchAt(_ptr_ address) = 0;

	virtual int __stdcall MemCopyCodeEx(_ptr_ dst, _ptr_ src, _dword_ size) = 0;

	virtual Variable* __stdcall VarInit(const char* name, _dword_ value) = 0;
	virtual Variable* __stdcall VarFind(const char* name) = 0;

	virtual PatcherInstance* __stdcall PreCreateInstance(const char* name) = 0;

	virtual int __stdcall WriteAsmCodeVA(_ptr_ address, _dword_* args) = 0;
	virtual _ptr_ __stdcall CreateCodeBlockVA(_dword_* args) = 0;

	template<typename ValueType>
	inline ValueType VarGetValue(const char* name, ValueType default_value)
	{
		if (sizeof(ValueType) > 4) return default_value;
		Variable* v = VarFind(name);
		if (v == NULL) return default_value;
		return (ValueType)v->GetValue();
	}

	template<typename ValueType>
	inline ValueType& VarValue(const char* name)
	{
		if (sizeof(ValueType) > 4) __asm{__asm int 3};

		Variable* v = VarFind(name);
		if (v == NULL) v = VarInit(name, 0);

		if (v == NULL) __asm{__asm int 3};

		return (ValueType&)*v->GetPValue();
	}

	inline _ptr_ WriteComplexData(_ptr_ address, char* format, ...)
	{
		return WriteComplexDataVA(address, format, (_dword_*)((_ptr_)&format + 4));
	}

	inline HiHook* GetFirstHiHookAt(_ptr_ address)
	{
		Patch* p = GetFirstPatchAt(address);
		while (true)
		{
			if (p == 0) return 0;
			if (p->GetType() == HIHOOK_) return (HiHook*)p;
			p = p->GetAppliedAfter();
		}
	}

	inline HiHook* GetLastHiHookAt(_ptr_ address)
	{
		Patch* p = GetLastPatchAt(address);
		while (true)
		{
			if (p == 0) return 0;
			if (p->GetType() == HIHOOK_) return (HiHook*)p;
			p = p->GetAppliedBefore();
		}
	}
};

#pragma pack(pop)

#ifndef _WINDOWS_
	#define NOMINMAX
	#include <Windows.h>
	#undef NOMINMAX
	#ifdef VOID
		#undef VOID
	#endif
#endif

inline Patcher* GetPatcher()
{
	typedef Patcher*(__stdcall* GetPatcher_t)();
	HMODULE pl = LoadLibraryA("patcher_x86.dll");
	if (pl)
	{
		GetPatcher_t f = GetPatcher_t(GetProcAddress(pl, "_GetPatcherX86@0"));
		if (f)
			return f();
	}
	return NULL;
}

#ifndef _LHF_
#define _LHF_(func) int __stdcall func(LoHook *h, HookContext *c)
#endif

#ifndef _LHREF_
#define _LHREF_(func) int __stdcall func(LoHook& h, HookContext& c)
#endif

#endif /* _H3API_PATCHER_X86_ */
