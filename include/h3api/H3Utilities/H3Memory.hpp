//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-06                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	class  H3Protect;
	struct H3DLL;

	/** @brief raii virtual protection to enable writing*/
	class H3Protect
	{
		UINT32 m_address;
		UINT32 m_size;
		DWORD  m_oldProtect;
		BOOL   m_protectEdited;
	public:
		/**
		 * @brief enables writing at memory location
		 *
		 * @param address where you wish to write
		 * @param size how many bytes should be unprotected
		 */
		_H3API_ H3Protect(UINT32 address, UINT32 size);
		_H3API_ ~H3Protect();
		/**
		 * @brief checks if virtual protect was successful
		 *
		 * @return BOOL whether virtual protect operation enabled writing
		 */
		_H3API_ BOOL CanWrite();
	};

	/** @brief perform operations on loaded memory*/
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

		/**
		 * @brief finds the first byte sequence in a specified region
		 *
		 * @param haystack region in which to look for
		 * @param hlen the length of the memory region to search
		 * @param needle byte sequence to search for
		 * @param nlen how many bytes are in the needle
		 * @return PUCHAR address that matches needle, as a pointer. nullptr if not found
		 */
		_H3API_ PUCHAR Memmem(PUCHAR haystack, size_t hlen, PUCHAR needle, size_t nlen);
		/**
		 * @brief performs Memmem operation to find first byte sequence in a specified region
		 *
		 * @param address starting search point
		 * @param max_search_length maximum bytes to search through
		 * @param needle byte sequence to search for
		 * @param needle_length how many bytes are in the needle
		 * @param offset how many bytes to shift the found needle location by
		 * @return UINT32 location in the region, matching the needle and shifted by \p offset. nullptr if not found
		 */
		_H3API_ UINT32 FindByNeedle(PUINT8 address, UINT32 max_search_length, PUINT8 needle, INT32 needle_length, INT32 offset);

#ifndef _H3API_NAKED_FUNCTION_
#define _H3API_NAKED_FUNCTION_ VOID __declspec(naked)
#endif

		/**
		 * @brief only works for opcode length 5, most basic hook there is.
		 * you are also in charge of overwritten assembly
		 * @param address where to place hook
		 * @param function _H3API_NAKED_FUNCTION_ hook
		 */
		_H3API_ BOOL NakedHook5(UINT32 address, H3NakedFunction function);
		/**
		 * @brief same as NakedHook5, but replaces bytes after the first 5 by NOP instructions
		 *
		 * @param address where to place hook
		 * @param function _H3API_NAKED_FUNCTION_ hook
		 * @param total_bytes how many bytes should be overwritten, minimum 5
		 */
		_H3API_ BOOL NakedHook(UINT32 address, H3NakedFunction function, UINT32 total_bytes);
		/**
		 * @brief write data at specific location
		 *
		 * @tparam T byte, word or dword, float, double...
		 * @param address where to write data
		 * @param value data to write
		 * @return Whether the data was successfully written
		 */
		template<typename T>
		BOOL WriteValue(ADDRESS address, const T value);

		/**
		 * @brief write data at specific locations
		 *
		 * @tparam T byte, word or dword, float, double...
		 * @tparam size how many locations will be written to
		 * @param address where to write data
		 * @param value data to write
		 * @return Whether the data was successfully written
		 */
		template<typename T, size_t size>
		BOOL WriteValues(const UINT address, const T(&value)[size]);

		/**
		 * @brief writes pointer of data type (its address)
		 *
		 * @tparam T any data type
		 * @param address address to write to
		 * @param data a global or constexpr array, double or other value to be written as a pointer
		 * @return Whether the data was successfully written
		 */
		template<typename T>
		BOOL AddressOfPatch(const UINT address, const T& data);
		/**
		 * @brief writes pointer of data type (its address) to multiple locations
		 *
		 * @tparam Type any data type
		 * @tparam size number of items in \p address array
		 * @param address Locations to write to
		 * @param data a global or constexpr array, double or other value to be written as a pointer
		 * @return Whether all patches were successfully done
		 */
		template<typename Type, size_t size>
		inline BOOL AddressOfPatch(const ADDRESS(&address)[size], const Type& data);
		/**
		 * @brief writes data type to an object reference without having to dereference to obtain their address
		 *
		 * @tparam T type of the object
		 * @param reference data member of the object
		 * @param data replacement value
		 */
		template<typename T>
		BOOL ObjectPatch(T& reference, T data);
		/**
		 * @brief writes an array of bytes to the specified location
		 *
		 * @tparam size how many bytes are to be written
		 * @param address starting location to write patch
		 * @param value an array of bytes representing a patch
		 */
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

		/**
		 * @brief A scoped patch will modify the value at the specified address
		 * for the duration of the declared class's scope and restore the original
		 * value once that scope is ended. Useful for modifying something temporarily (raii).
		 * @tparam Type Any type of value (char, int, double,...)
		 */
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
	/**
	 * @brief Similar to H3Patcher::ScopedPatch, however the value should be writable (no memory access modifications)
	 * @tparam _Address The value to be backed up
	 * @tparam Type any type of value (char, int, double ...)
	 */
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

	/** @brief get information about loaded dll or process through its name*/
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
		/**
		 * @brief constructs the object and performs GetDllInfo()
		 *
		 * @param dll_name name of the process to inspect
		 */
		_H3API_ H3DLL(LPCSTR dll_name);

	protected:
		_H3API_ VOID needleNotFound(PUINT8 needle, INT32 needle_size, BOOL in_code = TRUE) const;
		_H3API_ VOID needleUnexpectedCode(UINT32 address, PUINT8 needle, INT32 needle_size, PUINT8 expected_code, INT32 expected_size) const;
		_H3API_ VOID processNotFound() const;
	public:
		/**
		 * @brief get process memory layout and size
		 *
		 * @param name name of the process
		 * @return Whether the DLL was found and data analyzed.
		 */
		_H3API_ BOOL GetDLLInfo(LPCSTR name);
		/**
		 * @brief find the first instance of needle
		 *
		 * @param needle byte sequence to look for
		 * @param needle_size number of bytes in needle
		 * @param offset number of bytes by which to shift the result
		 * @return UINT32 address of the needle modified by \p offset, 0 if needle was not found
		 */
		_H3API_ UINT32 NeedleSearch(PUINT8 needle, INT32 needle_size, INT32 offset);
		/**
		 * @brief find the location of a secondary needle in the vicinity of primary needle
		 *
		 * @param needle primary byte sequence to look for
		 * @param needle_size size of primary needle
		 * @param radius search length around primary needle
		 * @param needle2 secondary byte sequence to look for
		 * @param needle_size2 size of secondary needle
		 * @return UINT32 address of the secondary needle, 0 if not found
		 */
		_H3API_ UINT32 NeedleSearchAround(PUINT8 needle, INT32 needle_size, INT32 radius, PUINT8 needle2, INT32 needle_size2);
		/**
		 * @brief used to perform subsequent searches of a needle based on previous results
		 *
		 * @param after starting search location
		 * @param needle byte sequence to look for
		 * @param needle_size number of bytes in needle
		 * @param offset number of bytes by which to shift the result
		 * @return UINT32 address of the needle modified by \p offset, 0 if needle was not found
		 */
		_H3API_ UINT32 NeedleSearchAfter(UINT32 after, const PUINT8 needle, INT32 needle_size, INT32 offset) const;
		/**
		 * @brief performs NeedleSearch and checks checks location for expectedCode
		 *
		 * @param needle byte sequence to look for
		 * @param needle_size number of bytes in needle
		 * @param offset number of bytes by which to shift the result
		 * @param expected_code byte sequence expected to be found at destination
		 * @param expected_size size of expected byte sequence
		 * @return UINT32 address of the needle modified by \p offset, 0 if needle was not found or expected sequence is not confirmed
		 */
		_H3API_ UINT32 NeedleSearchConfirm(PUINT8 needle, INT32 needle_size, INT32 offset, PUINT8 expected_code, INT32 expected_size);
		/**
		 * @brief performs NeedleSearch in RDATA section
		 *
		 * @param needle byte sequence to look for
		 * @param needle_size number of bytes in needle
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		_H3API_ UINT32 NeedleSearchRData(PUINT8 needle, INT32 needle_size) const;
		/**
		 * @brief performs NeedleSearch in DATA section
		 *
		 * @param needle byte sequence to look for
		 * @param needle_size number of bytes in needle
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		_H3API_ UINT32 NeedleSearchData(PUINT8 needle, INT32 needle_size) const;
		/**
		 * @brief find the first instance of needle
		 *
		 * @tparam sz number of bytes in needle
		 * @param needle byte sequence to look for
		 * @param offset number of bytes by which to shift the result
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		template <INT32 sz>
		UINT32 NeedleSearch(const UINT8(&needle)[sz], INT32 offset);
		/**
		 * @brief find the location of a secondary needle in the vicinity of primary needle
		 *
		 * @tparam sz number of bytes in primary needle
		 * @tparam sz2 number of bytes in secondary needle
		 * @param needle primary byte sequence to look for
		 * @param radius search length around primary needle
		 * @param needle2 secondary byte sequence to look for
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		template <INT32 sz, INT32 sz2>
		UINT32 NeedleSearchAround(const UINT8(&needle)[sz], INT32 radius, const UINT8(&needle2)[sz2]);
		/**
		 * @brief used to perform subsequent searches of a needle based on previous results
		 *
		 * @tparam sz number of bytes in needle
		 * @param after starting search location
		 * @param needle byte sequence to look for
		 * @param offset number of bytes by which to shift the result
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		template <INT32 sz>
		UINT32 NeedleSearchAfter(UINT32 after, const UINT8(&needle)[sz], INT32 offset);
		/**
		 * @brief performs NeedleSearch and checks checks location for expectedCode
		 *
		 * @tparam sz number of bytes in primary needle
		 * @tparam sz2 number of bytes in confirmation needle
		 * @param needle byte sequence to look for
		 * @param offset number of bytes by which to shift the result
		 * @param expected_code byte sequence expected to be found at destination
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		template <INT32 sz, INT32 sz2>
		UINT32 NeedleSearchConfirm(const UINT8(&needle)[sz], INT32 offset, const UINT8(&expected_code)[sz2]);
		/**
		 * @brief performs NeedleSearch in RDATA section
		 *
		 * @tparam sz number of bytes in needle
		 * @param needle byte sequence to look for
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
		template <INT32 sz>
		UINT32 NeedleSearchRData(const UINT8(&needle)[sz]);
		/**
		 * @brief performs NeedleSearch in DATA section
		 *
		 * @tparam sz number of bytes in needle
		 * @param needle byte sequence to look for
		 * @return UINT32 address of the needle, 0 if needle was not found
		 */
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
