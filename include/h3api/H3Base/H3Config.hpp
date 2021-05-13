//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

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

#include "H3Types.hpp" // all H3API specific types
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
	/** @brief indicates your compiler is C++98 compatible*/
	#define _H3API_CPLUSPLUS98_
#endif

#if (__cplusplus >= 201103L || (_MSC_VER && _MSC_VER >= 1900))
	/**
	 * @brief indicates your compiler is C++11 compatible
	 * this checks for C++11 standard or Visual Studio 2015+ because VS2013 is not fully compliant
	 */
	#define _H3API_CPLUSPLUS11_
#endif

#if (__cplusplus >= 201402L || (_MSC_VER && _MSC_VER >= 1900))
	/** @brief indicates your compiler is C++14 compatible*/
	#define _H3API_CPLUSPLUS14_
#endif

#if (__cplusplus >= 201703L || (_MSC_VER && _MSC_VER >= 1910))
	/** @brief indicates your compiler is C++17 compatible*/
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
	/* defines bitwise operators for an enum */
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
		/*header-only doesn't get deprecation messages*/
		#define _H3API_DEPRECATED_(msg)
	#endif
#else
	#if _MSC_VER && _MSC_VER >= 1900
		#ifndef _H3API_DEPRECATED_
			/*indicates this content is deprecated and replaced by equivalent expressions*/
			#define _H3API_DEPRECATED_(msg) [[deprecated(msg)]]
		#endif
	#elif _MSC_VER
		#ifndef _H3API_DEPRECATED_
			/*indicates this content is deprecated and replaced by equivalent expressions*/
			#define _H3API_DEPRECATED_(msg) __declspec(deprecated(msg))
		#endif
	#elif defined(__GNUC__) || defined(__clang__)
		#ifndef _H3API_DEPRECATED_
			/*indicates this content is deprecated and replaced by equivalent expressions*/
			#define _H3API_DEPRECATED_(msg) __attribute__((deprecated(msg)))
		#endif
	#else
		#pragma message("WARNING: _H3API_DEPRECATED_ is not implemented for this compiler.")
		#ifndef _H3API_DEPRECATED_
			/*indicates this content is deprecated and replaced by equivalent expressions*/
			#define _H3API_DEPRECATED_(msg)
		#endif
	#endif
#endif /* _H3API_LIBRARY_ */

#ifndef _H3API_NOVTABLE_
	/*indicates that a virtual table for this class should not be created*/
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
		/*used to force function to be inline*/
		#define _H3API_FORCEINLINE_ __forceinline
	#endif
#elif defined(__GNUC__)
	#ifndef _H3API_FORCEINLINE_
		/*used to force function to be inline*/
		#define _H3API_FORCEINLINE_ inline __attribute__((__always_inline__))
	#endif
#elif defined(__CLANG__)
	#if __has_attribute(__always_inline__)
		#ifndef _H3API_FORCEINLINE_
		/*used to force function to be inline*/
		#define _H3API_FORCEINLINE_ inline __attribute__((__always_inline__))
		#endif
	#else
		#ifndef _H3API_FORCEINLINE_
			/*used to force function to be inline*/
			#define _H3API_FORCEINLINE_ inline
		#endif
	#endif
#else
	#ifndef _H3API_FORCEINLINE_
		/*used to force function to be inline*/
		#define _H3API_FORCEINLINE_ inline
	#endif
#endif

#ifndef _H3API_DECLARE_
	#ifndef _H3API_UNPREFIXED_NAMES_
		/** @brief forward-defines a struct, pointer to struct*/
		#define _H3API_DECLARE_(NAME) struct H3 ## NAME; typedef H3 ## NAME *PH3 ## NAME
	#else
		/** @brief forward-defines a struct, pointer to struct and unprefixed struct*/
		#define _H3API_DECLARE_(NAME) struct H3 ## NAME; typedef H3 ## NAME *PH3 ## NAME; typedef H3 ## NAME NAME
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif

#ifndef _H3API_TYPE_DECLARE_
	#ifndef _H3API_UNPREFIXED_NAMES_
		/** @brief declares a typedef with H3 prefix*/
		#define _H3API_TYPE_DECLARE_(struct_type, NAME) typedef struct_type H3 ## NAME
	#else
		/** @brief declares a typedef with and without H3 prefix*/
		#define _H3API_TYPE_DECLARE_(struct_type, NAME) typedef struct_type H3 ## NAME; typedef struct_type NAME
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif

#ifndef _H3API_TEMPLATE_DECLARE_
	#if defined(_H3API_CPLUSPLUS11_) && defined(_H3API_UNPREFIXED_NAMES_)
		/** @brief Used internally to know that a templated struct can be abbreviated*/
		#define _H3API_TEMPLATE_DECLARE_
	#endif /* _H3API_CPLUSPLUS11_ && _H3API_UNPREFIXED_NAMES_ */
#endif /* _H3API_TEMPLATE_DECLARE_ */

#ifndef _H3API_EXPORT_
	/**
	 * @brief exports a function without name mangling
	 * to use, type the following within a function's definition:
	 * #pragma _H3API_EXPORT_
	 */
	#define _H3API_EXPORT_ comment(linker, "/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__)
#endif

#ifndef _H3API_STR_EXPAND_
	#define _H3API_STR_EXPAND_(x) #x // inserts text representation of macro
#endif
#ifndef _H3API_STR_
	#define _H3API_STR_(x) _H3API_STR_EXPAND_(x) // expands a macro into its actual text
#endif

#ifndef _H3API_SIZE_
	/** @brief Assigns a SIZE static value to a structure*/
	#define _H3API_SIZE_(struct_size) static constexpr UINT32 SIZE = struct_size
#endif

#ifndef _H3API_GET_INFO_
	/**
	 * @brief Assigns a static ADDRESS pointer to known address of a structure,
	 * TYPE typedef and defines a static Get() method to get a pointer to the structure.
	 */
	#define _H3API_GET_INFO_(address_pointer, struct_type) \
	static constexpr h3::ADDRESS ADDRESS = address_pointer;\
	static struct_type* Get() { return StructAt<struct_type>(ADDRESS); }\
	typedef struct_type TYPE
#endif

#ifndef _H3API_NAMED_STRUCT_
	#ifndef _H3API_UNPREFIXED_NAMES_
		/** @brief Declares a H3-named struct with a ::Get() method*/
		#define _H3API_NAMED_STRUCT_(struct_type, NAME, address_pointer)\
		struct H3 ## NAME : struct_type { _H3API_GET_INFO_(address_pointer, struct_type); }
	#else
		/** @brief Declares a H3-named struct with a ::Get() method and typedefs unprefixed name*/
		#define _H3API_NAMED_STRUCT_(struct_type, NAME, address_pointer)\
		struct H3 ## NAME : struct_type { _H3API_GET_INFO_(address_pointer, struct_type); };\
		typedef struct_type NAME;
	#endif /* _H3API_UNPREFIXED_NAMES_ */
#endif /* _H3API_NAMED_STRUCT_ */

#ifndef _H3API_CTOR_DTOR_
	/** @brief Assigns CONSTRUCTOR and DESTRUCTOR information to structure*/
	#define _H3API_CTOR_DTOR_(constructor_address, destructor_address) \
	static constexpr h3func CONSTRUCTOR = constructor_address;\
	static constexpr h3func DESTRUCTOR  = destructor_address
#endif

#ifndef _H3API_VTABLE_
	/** @brief Assigns VTABLE information to structure*/
	#define _H3API_VTABLE_(virtual_table_address) \
	static constexpr h3::ADDRESS VTABLE = virtual_table_address
#endif /* define _H3API_VTABLE_ */

namespace h3
{
#ifdef _H3API_CPLUSPLUS11_
	/**
	 * @brief Literal operator to convert a value to 8 bits.
	 * e.g. 123_byte
	 * @param value Unsigned value to be converted.
	 * @return Unsigned 8-bits value.
	 */
	constexpr inline UINT8 operator""_byte(UINT64 value)
	{
		return static_cast<UINT8>(value);
	}
	/**
	 * @brief Literal operator to convert a value to 16 bites.
	 * e.g. 123456_word
	 * @param value Unsigned value to be converted.
	 * @return Unsigned 16-bits value.
	 */
	constexpr inline UINT16 operator""_word(UINT64 value)
	{
		return static_cast<UINT16>(value);
	}
	/**
	 * @brief Literal operator to convert a value to 32 bits.
	 * e.g. 123_dword
	 * @param value Unsigned value to be converted.
	 * @return Unsigned 32-bits value.
	 */
	constexpr inline UINT32 operator""_dword(UINT64 value)
	{
		return static_cast<UINT32>(value);
	}
	/**
	 * @brief Literal operator to convert a value to unsigned 8 bits.
	 * e.g. 123_u8
	 * @param value Value to be converted.
	 * @return Unsigned 8-bits value.
	 */
	constexpr inline UINT8 operator""_u8(UINT64 value)
	{
		return static_cast<UINT8>(value);
	}
	/**
	 * @brief Literal operator to convert a value to unsigned 16 bits.
	 * e.g. 123_u16
	 * @param value Value to be converted.
	 * @return Unsigned 16-bits value.
	 */
	constexpr inline UINT16 operator""_u16(UINT64 value)
	{
		return static_cast<UINT16>(value);
	}
	/**
	 * @brief Literal operator to convert a value to unsigned 32 bits.
	 * e.g. 123_u32
	 * @param value Value to be converted.
	 * @return Unsigned 32-bits value.
	 */
	constexpr inline UINT32 operator""_u32(UINT64 value)
	{
		return static_cast<UINT32>(value);
	}
	/**
	 * @brief Literal operator to convert a value to signed 8 bits.
	 * e.g. 123_i8
	 * @param value Value to be converted.
	 * @return Signed 8-bits value.
	 */
	constexpr inline INT8 operator""_i8(UINT64 value)
	{
		return static_cast<INT8>(value);
	}
	/**
	 * @brief Literal operator to convert a value to signed 16 bits.
	 * e.g. 123_i16
	 * @param value Value to be converted.
	 * @return Signed 16-bits value.
	 */
	constexpr inline INT16 operator""_i16(UINT64 value)
	{
		return static_cast<INT16>(value);
	}
	/**
	 * @brief Literal operator to convert a value to signed 32 bits.
	 * e.g. 123_i32
	 * @param value Value to be converted.
	 * @return Signed 32-bits value.
	 */
	constexpr inline INT32 operator""_i32(UINT64 value)
	{
		return static_cast<INT32>(value);
	}
	/**
	 * @brief Literal operator to convert a value to 32 bits.
	 * This should be used to indicate the the value in question
	 * belongs to the Heroes3 address space.
	 *
	 * @param value Unsigned value to be converted.
	 * @return Unsigned 32-bits value.
	*/
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

	/**
	 * @brief Get a reference of specific type at the specified address
	 * @tparam T Type of data to cast to.
	 * @param address The location of the sought data.
	 * @return A reference of the value at the specified location.
	 */
	template<typename T>
	_H3API_FORCEINLINE_ T& ValueAt(ADDRESS address) { return *reinterpret_cast<T*>(address); }

	/**
	 * @brief Get a reference of const char* at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the string at the specified location.
	 */
	_H3API_FORCEINLINE_ LPCSTR& StrAt(ADDRESS address) { return ValueAt<LPCSTR>(address); }
	/**
	 * @brief Get a reference of pointer for any data.
	 * @tparam T Type of data of the data.
	 * @param address The location of the sought data.
	 * @return A reference of the pointer at the specified location.
	 */
	template<typename T>
	_H3API_FORCEINLINE_ UINT32& PtrAt(T data) { return ValueAt<UINT32>(ADDRESS(data)); }
	/**
	 * @brief Get a reference of unsigned integer at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the unsigned integer at the specified location.
	 */
	_H3API_FORCEINLINE_ UINT32& DwordAt(ADDRESS address) { return ValueAt<UINT32>(address); }
	/**
	 * @brief Get a reference of signed integer at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the signed integer at the specified location.
	 */
	_H3API_FORCEINLINE_ INT32&  IntAt(ADDRESS address) { return ValueAt<INT32>(address); }
	/**
	 * @brief Get a reference of unsigned short at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the unsigned short at the specified location.
	 */
	_H3API_FORCEINLINE_ UINT16& WordAt(ADDRESS address) { return ValueAt<UINT16>(address); }
	/**
	 * @brief Get a reference of signed short at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the signed short at the specified location.
	 */
	_H3API_FORCEINLINE_ INT16&  ShortAt(ADDRESS address) { return ValueAt<INT16>(address); }
	/**
	 * @brief Get a reference of unsigned char at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the unsigned char at the specified location.
	 */
	_H3API_FORCEINLINE_ UINT8&  ByteAt(ADDRESS address) { return ValueAt<UINT8>(address); }
	/**
	 * @brief Get a reference of signed char at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the signed char at the specified location.
	 */
	_H3API_FORCEINLINE_ INT8&   CharAt(ADDRESS address) { return ValueAt<INT8>(address); }
	/**
	 * @brief Get a reference of float at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the float at the specified location.
	 */
	_H3API_FORCEINLINE_ FLOAT&  FloatAt(ADDRESS address) { return ValueAt<FLOAT>(address); }
	/**
	 * @brief Get a reference of double at the specified address.
	 * @param address The location of the sought data.
	 * @return A reference of the double at the specified location.
	 */
	_H3API_FORCEINLINE_ DOUBLE& DoubleAt(ADDRESS address) { return ValueAt<DOUBLE>(address); }
	/**
	 * @brief Get the value of the function called (or jump destination) at the specified address.
	 * @param address The location of the call/JMP instruction.
	 * @return The address of the destination.
	 */
	_H3API_FORCEINLINE_ h3func  FuncAt(ADDRESS address) { return ValueAt<h3func>(address + 1) + address + 5; }
	/**
	 * @brief Returns a struct pointer located at an address
	 * @tparam T Type of the struct
	 * @param address_pointer The location of the struct pointer
	 * @return Casted structure pointer
	*/
	template<typename T>
	_H3API_FORCEINLINE_ T* StructAt(ADDRESS address_pointer) { return *reinterpret_cast<T**>(address_pointer); }
	/**
	 * @brief Get the address of a specific object.
	 * @tparam T Type of the current object.
	 * @param value The object itself.
	 * @return The address of the provided object.
	 */
	template<typename T>
	_H3API_FORCEINLINE_ ADDRESS AddressOf(const T& value) { return reinterpret_cast<ADDRESS>(&value); }
	/**
	 * @brief Used to get the hexadecimal value of a type T instead of getting a casted value.
	 * Useful to convert a FLOAT to DWORD, e.g. 0.25f is returned as 0x3E800000h instead of 0h.
	 * @tparam T Type of data to convert
	 * @param value Value of the data to convert.
	 * @return Converted data as unsigned integer.
	 */
	template<typename T>
	_H3API_FORCEINLINE_ UINT32 ValueAsDword(T value) { return DwordAt(AddressOf(value)); }
	/**
	 * @brief Get current FPU's value as float
	 * @return The state of the FPU
	 */
	_H3API_FORCEINLINE_ FLOAT LoadFloatFromFPU()
	{
		FLOAT value = 0;
		__asm FSTP DWORD PTR SS : [value]
		return value;
	}
	/**
	 * @brief Store a float to FPU
	 * @param value Float to store
	 */
	_H3API_FORCEINLINE_ VOID StoreToFPU(FLOAT value)
	{
		__asm FLD DWORD PTR SS : [value]
	}
	/**
	 * @brief Get current FPU's value as double
	 * @return The state of the FPU
	 */
	_H3API_FORCEINLINE_ DOUBLE LoadDoubleFromFPU()
	{
		DOUBLE value = 0;
		__asm FSTP QWORD PTR SS : [value]
		return value;
	}
	/**
	 * @brief Store a double to FPU
	 * @param value Double to store
	 */
	_H3API_FORCEINLINE_ VOID StoreToFPU(DOUBLE value)
	{
		__asm FLD QWORD PTR SS : [value]
	}

	/*based on https://stackoverflow.com/a/1980156 by Gregory Pakosz*/
#ifndef _H3API_STATIC_ASSERT_
	#ifdef _H3API_NO_VALIDATION_
			/**
			 * @brief disabled compilation-time assertion
			 * undefine _H3API_NO_VALIDATION_ to enable these checks
			 */
		#define _H3API_STATIC_ASSERT_(condition, message)
	#else
		#ifdef _H3API_CPLUSPLUS11_
			/**
			 * @brief compile-time assertion to ensure integrity of structure size and use of some templates
			 * define _H3API_NO_VALIDATION_ to remove these checks
			 */
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
			// ugly but it should get the job done...
			/**
			 * @brief compile-time assertion to ensure integrity of structure size and use of some templates
			 * $message is not used and is simply a placeholder for static_assert
			 * define _H3API_NO_VALIDATION_ to remove these checks
			 */
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
	/** @brief Performs sizeof() static_assert on the named structure to guarantee library integrity*/
	#define _H3API_ASSERT_SIZE_(name) _H3API_STATIC_ASSERT_(sizeof(name) == name::SIZE, #name " size is incorrect")
#endif /* _H3API_ASSERT_SIZE_ */

#ifndef _H3API_ASSERT_OFFSET_
	#define _H3API_ASSERT_OFFSET_(name, member, offset) _H3API_STATIC_ASSERT_(offsetof(name, member) == offset, #name "::" #member " offset invalid")
#endif

	namespace H3Internal
	{
		/*std::enable_if is only available as of C++11*/
		template<bool condition, class T = VOID>
		struct enable_if {};
		template<class T>
		struct enable_if<true, T> { typedef T type; };
		/*std::remove_pointer is only available as of C++11*/
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

// * this region declares a number of template functions to be used to call H3 functions;
// * template functions are superior to the old macro-style as there is no forced conversion
// * of arguments to a specific type; there is no longer complicated logic required to
// * pass a float or double to a function, it is done implicitly;
// * for ease of use, the old macros still exist and refer to these new templates;
// * these are generated via script, if you need more arguments for some reason request them;
// * in a perfect world without pre C++11, these would not be required...
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

// * you absolutely need c++11 to use STDCALL_VA, THISCALL_VA and FASTCALL_VA
// * in prior versions, variadic templates don't exist
// * va_list arguments would absolutely require __cdecl to clean the stack
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

	/** @brief objects marked with this should not be directly transferable*/
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
	/**
	 * @brief template model to access data structures within h3 memory
	 * DataPointer is not copyable and cannot be assigned to other variables.
	 * There is an operator cast to data type as well as operator& and operator*
	 * to achieve this task, so that your intentions may be clear.
	 * @tparam type indicates which type of data is pointed to
	 */
	template<class type>
	class H3DataPointer : public H3Uncopyable
	{
	public:
		typedef type* pointer;
		typedef type& reference;
		/** @brief constructor is forced inline to avoid unnecessary slowdown*/
		_H3API_FORCEINLINE_ H3DataPointer() :
			m_address(getAddress())
		{
		}
		/**
		 * @brief dereferences pointer
		 * @return reference to data
		 */
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		/** @brief access data methods and contents directly*/
		pointer operator->() { return reinterpret_cast<pointer>(m_address); }
		/**
		 * @brief grants a pointer to data which may be needed for some methods
		 * @return pointer to data
		 */
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		/**
		 * @brief returns itself as a way to switch between macro and typedef mode
		 * DataPointer-> as a macro is valid but not as typedef.
		 * DataPointer()-> is always valid
		 * @return itself without any modification
		 */
		H3DataPointer<type>& operator()() { return *this; }
#endif
		/**
		 * @brief automatic cast to data type
		 * @return pointer
		 */
		operator pointer() { return reinterpret_cast<pointer>(m_address); }
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

	/**
	 * @brief template model to access data structures that are arrays within h3 memory
	 * DataArrayPointer is not copyable and cannot be assigned to other variables.
	 * There is an operator cast to data type as well as operator& and operator*
	 * to achieve this task, so that your intentions may be clear.
	 * @tparam type indicates which type of data is pointed to
	 */
	template<class type>
	class H3DataArrayPointer : public H3Uncopyable
	{
	public:
		typedef type* pointer;
		typedef type& reference;
		/** @brief constructor is forced inline to avoid unnecessary slowdown*/
		_H3API_FORCEINLINE_ H3DataArrayPointer() :
			m_address(getAddress())
		{
		}
		/**
		 * @brief dereferences pointer
		 * @return reference to data
		 */
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		/** @brief access data methods and contents directly*/
		pointer operator->() { return reinterpret_cast<pointer>(m_address); }
		/**
		 * @brief grants a pointer to data which may be needed for some methods
		 * @return pointer to data
		 */
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		/**
		 * @brief returns itself as a way to switch between macro and typedef mode
		 * DataPointer-> as a macro is valid but not as typedef.
		 * DataPointer()-> is always valid
		 * @return itself without any modification
		 */
		H3DataArrayPointer<type>& operator()() { return *this; }
#endif
		/**
		 * @brief automatic cast to start of data array
		 * @return pointer*
		 */
		operator pointer*() { return reinterpret_cast<pointer*>(m_address); }
		/**
		 * @brief access to array items as reference
		 * beware that there is no boundary check performed on the data
		 * @param index unsigned position of the data to access
		 * @return reference to data at the given index
		 */
		reference operator[](UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
		/**
		 * @brief access to array items as reference
		 * beware that there is no boundary check performed on the data
		 * @param index signed position of the data to access, is converted to unsigned value
		 * @return reference to data at the given index
		 */
		reference operator[](INT index) { return reinterpret_cast<pointer>(m_address)[static_cast<UINT>(index)]; }
		/**
		 * @brief access to array items as pointer
		 * beware that there is no boundary check performed on the data
		 * @param index unsigned position of the data to access
		 * @return pointer to data at the given index
		 */
		pointer operator()(UINT index) { return &reinterpret_cast<pointer>(m_address)[index]; }

#ifdef _H3API_CPLUSPLUS11_
		/**
		 * @brief automatic-cast to pointer type is possible with c++11
		 * used through static_cast<type*>(DataPointer)
		 * @return pointer type matching start of array
		 */
		explicit operator pointer() { return *reinterpret_cast<pointer>(m_address); }
#endif

	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

	/**
	 * @brief template model to access data values within h3 memory
	 * PrimitivePointer is not copyable and cannot be assigned to other variables.
	 * There is an operator cast to data type as well as operator& and operator*
	 * to achieve this task, so that your intentions may be clear.
	 * Contrary to other Pointer types, this type does not have a pointer** format
	 * @tparam type indicates which type of data is pointed to
	 * @tparam address indicates the physical address to access the data from
	 */
	template<class type>
	class H3PrimitivePointer : public H3Uncopyable
	{
	public:
		typedef typename type::VALUE_TYPE* pointer;
		typedef typename type::VALUE_TYPE& reference;
		typedef typename type::VALUE_TYPE  value_type;
		/** @brief constructor is forced inline to avoid unnecessary slowdown*/
		_H3API_FORCEINLINE_ H3PrimitivePointer() :
			m_address(getAddress())
		{
		}
		/**
		 * @brief dereferences pointer
		 * @return reference to data
		 */
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		/**
		 * @brief grants a pointer to data which may be needed for some methods
		 * @return pointer to data
		 */
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }
#ifndef _H3API_DONT_USE_MACROS_
		/**
		 * @brief returns itself as a way to switch between macro and typedef mode
		 * DataPointer-> as a macro is valid but not as typedef.
		 * DataPointer()-> is always valid
		 * @return itself without any modification
		 */
		H3PrimitivePointer<type/*, value_type*/>& operator()() { return *this; }
#endif
		/**
		 * @brief automatic cast to data
		 * @return a copy of the primitive data
		 */
		operator value_type() { return *reinterpret_cast<pointer>(m_address); }
		/**
		 * @brief allows assignment of values to data
		 * beware that you may need to allow write with VirtualProtect first
		 * @param new_data new content to be inserted
		 */
		void operator=(value_type new_data) { *reinterpret_cast<pointer>(m_address) = new_data; }
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return type::ADDRESS; }
	};

	/**
	 * @brief template model to access primitive data as arrays within h3 memory
	 * PrimitivePointers is not copyable and cannot be assigned to other variables.
	 * There is an operator cast to data type as well as operator& and operator*
	 * to achieve this task, so that your intentions may be clear.
	 * @tparam type indicates which type of data is pointed to
	 * @tparam address indicates the physical address to access the data from
	 * @tparam is_pointer indicates that data has **pointer format
	 */
	template<typename type>
	class H3PrimitiveArrayPointer : public H3Uncopyable
	{
	public:
		typedef typename H3Internal::remove_pointer<typename type::VALUE_TYPE>::type value_type;
		typedef value_type* pointer;
		typedef value_type& reference;

		/** @brief constructor is forced inline to avoid unnecessary slowdown*/
		_H3API_FORCEINLINE_ H3PrimitiveArrayPointer() :
			m_address(getAddress())
		{
		}
		/**
		 * @brief dereferences pointer
		 * @return reference to data
		 */
		reference operator*() { return *reinterpret_cast<pointer>(m_address); }
		/**
		 * @brief grants a pointer to data which may be needed for some methods
		 * @return pointer to data
		 */
		pointer operator&() { return reinterpret_cast<pointer>(m_address); }

#ifndef _H3API_DONT_USE_MACROS_
		/**
		 * @brief returns itself as a way to switch between macro and typedef mode
		 * DataPointer-> as a macro is valid but not as typedef.
		 * DataPointer()-> is always valid
		 * @return itself without any modification
		 */
		H3PrimitiveArrayPointer<type>& operator()() { return *this; }
#endif
		/**
		 * @brief automatic cast to start of data array
		 * @return pointer* to array start
		 */
		operator pointer*() { return reinterpret_cast<pointer*>(m_address); }
		/**
		 * @brief access to array items as reference
		 * beware that there is no boundary check performed on the data
		 * @param index unsigned position of the data to access
		 * @return reference to data at the given index
		 */
		reference operator[](UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
		/**
		 * @brief access to array items as reference
		 * beware that there is no boundary check performed on the data
		 * @param index signed position of the data to access, is converted to unsigned value
		 * @return reference to data at the given index
		 */
		reference operator[](INT index) { return reinterpret_cast<pointer>(m_address)[static_cast<UINT>(index)]; }
		/**
		 * @brief access to array items as pointer
		 * beware that there is no boundary check performed on the data
		 * @param index unsigned position of the data to access
		 * @return pointer to data at the given index
		 */
		value_type operator()(UINT index) { return reinterpret_cast<pointer>(m_address)[index]; }
#ifdef _H3API_CPLUSPLUS11_
		/**
		 * @brief automatic-cast to pointer type is possible with c++11
		 * used through static_cast<type*>(DataPointer)
		 * @return pointer type matching start of array
		 */
		explicit operator pointer() { return *reinterpret_cast<pointer>(m_address); }
#endif
	private:
		UINT m_address;
		_H3API_FORCEINLINE_ UINT getAddress() { return *PUINT(type::ADDRESS); }
	};

} /* namespace h3 */
