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

#include "h3api/H3Base/H3Core.hpp"
#include "h3api/H3Base/H3Allocator.hpp"

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

	/**
	 * @brief Waits for the specified time in async-like fashion, having app messages still be parsed
	 * @param milliseconds Duration of wait time
	 */
	_H3API_ VOID WaitFor(DWORD milliseconds);

	/** @brief TimeGetTime()*/
	_H3API_ DWORD GetTime();
	/**
	 * @brief Clamps a value in between two bounds
	 * @param min_value Lower bound
	 * @param value Value to clamp
	 * @param max_value Upper bound
	 * @return Clamped value [min_value, max_value]
	*/
	_H3API_ INT32 Clamp(INT32 min_value, INT32 value, INT32 max_value);
	/**
	 * @brief used to get coordinates of map data that is stored as an array
	 * @tparam T H3MapItems, RMG_MapItems, H3TileVision, etc.
	 * @param current_point The point from which to determine the coordinates
	 * @param base_point The first item in the array (&array[0][0][0])
	 * @param map_size The map size for the map related to the current format
	 * @return H3Point x-y-z coordinates
	*/
	template<typename T>
	H3Point ReverseCoordinates(const T* current_point, const T* base_point, UINT map_size);

	/** @brief Houses utf8, ansi and unicode conversions*/
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
