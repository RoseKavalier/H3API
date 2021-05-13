//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base/H3Functions.hpp"

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
