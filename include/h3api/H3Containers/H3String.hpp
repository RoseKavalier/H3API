//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-05                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

#ifdef _H3API_STD_CONVERSIONS_
#include <string>
#endif

namespace h3
{
	_H3API_DECLARE_(String);
	_H3API_DECLARE_(WString);

#pragma pack(push, 4)
	/**
	 * @brief std::string in h3 format
	*/
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

		// * H3 constructor
		_H3API_ VOID Init();
		// * H3 destructor
		_H3API_ VOID Dereference();

		_H3API_ BOOL Empty() const;

		// * current length of string
		_H3API_ UINT Length() const;
		// * capacity of string
		_H3API_ UINT MaxLength() const;
		// * returns constant char* string
		_H3API_ LPCSTR String() const;

		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_H3API_ CHAR* begin();
		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_H3API_ CHAR* end();
		_H3API_ const CHAR* begin() const;
		_H3API_ const CHAR* end() const;

		_H3API_ VOID swap(H3String& other);

		// * returns beginning of string
		// * modifiable contrary to String()
		_H3API_ PCHAR Begin();
		// * returns end of string, on null char
		_H3API_ PCHAR End();

		// * returns the last char of string
		_H3API_ CHAR Last() const;

		// * sets string as mes

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

		// * sets new capacity, 0x1F is default
		_H3API_ BOOL Reserve(UINT new_size = 0x1E);
		// * Sets capacity if larger, otherwise shortens
		_H3API_ BOOL SetLength(UINT len);
		// * reduces buffer capacity to length + 1
		_H3API_ VOID ShrinkToFit();

		// * Adds mes to end of string

		_H3API_ H3String& Append(LPCSTR mes, UINT len);
		template<UINT Sz>
		inline H3String& AppendA(const CHAR (&buffer)[Sz]);
		_H3API_ H3String& Append(const H3String & other);
		_H3API_ H3String& Append(INT32 number);
		_H3API_ H3String& Append(UINT32 number);
		_H3API_ H3String& Append(LPCSTR mes);
		_H3API_ H3String& Append(CHAR ch);
		_H3API_ H3String& Append(int count, CHAR ch);

		// * Finds position of first ch
		_H3API_ LPCSTR FindFirst(CHAR ch);
		// * Finds position of first substring
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

		// * removes leading and trailing whitespace ' ' and '\t'
		_H3API_ H3String& Trim();

		// * returns string offset at pos
		_H3API_ PCHAR At(UINT pos);
		_H3API_ CHAR GetCharAt(UINT pos) const;

		// * Removes all instances of string

		_H3API_ H3String& Remove(CHAR ch);
		_H3API_ H3String& Remove(LPCSTR substr);
		_H3API_ H3String& Remove(LPCSTR substr, UINT sublen);
		// * Remove chars from start to end - inclusively!
		_H3API_ H3String& Remove(UINT start, UINT end);
		// * removes character at position
		_H3API_ H3String& Erase(UINT pos);
		// * removes characters from [first, last)
		_H3API_ H3String& Erase(UINT first, UINT last);
		// * removes characters from [first, last)
		_H3API_ H3String& Erase(PCHAR first, PCHAR last);

		// * Splits a string on a given char
		// * The character is removed
		// * the original string is truncated
		// * The outgoing string gets the remainder
		// * of the original string
		_H3API_ BOOL Split(CHAR ch, H3String& out);

		// * sets string to all 0s
		_H3API_ VOID Erase();

		// * memcmp ~ case sensitive
		_H3API_ BOOL Equals(LPCSTR msg, UINT len) const;
		_H3API_ BOOL Equals(LPCSTR msg) const;
		_H3API_ BOOL Equals(const H3String& other) const;

		// * strcmpi ~ not case-sensitive
		_H3API_ BOOL Equals_i(LPCSTR msg, UINT len) const;
		_H3API_ BOOL Equals_i(LPCSTR msg) const;
		_H3API_ BOOL Equals_i(const H3String& other) const;

		// * Inserts string within h3string at position
		_H3API_ H3String& Insert(UINT pos, LPCSTR msg, UINT len);
		_H3API_ H3String& Insert(UINT pos, LPCSTR msg);
		_H3API_ H3String& Insert(UINT pos, const H3String& to_insert);
		_H3API_ H3String& Insert(UINT pos, CHAR ch);

		_H3API_ INT Compare(LPCSTR other) const;
		_H3API_ INT Compare(const H3String& other) const;
		// * compare case insensitive
		_H3API_ INT Comparei(LPCSTR other) const;
		_H3API_ INT Comparei(const H3String& other) const;

		_H3API_ BOOL operator<(const H3String& other) const;

		// * Ends string at position
		_H3API_ BOOL Truncate(UINT position);

		// * counts number of times a character shows up
		_H3API_ UINT Occurrences(CHAR ch) const;

		// * Assigns string to current

		_H3API_ H3String& operator=(const H3String& other);
		_H3API_ H3String& operator=(LPCSTR msg);
		_H3API_ H3String& operator=(CHAR ch);

	#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3String& operator=(H3String&& other) noexcept;
	#endif

		// * Appends to string

		_H3API_ H3String& operator+=(const H3String& other);
		_H3API_ H3String& operator+=(LPCSTR msg);
		_H3API_ H3String& operator+=(CHAR ch);
		_H3API_ H3String& operator+=(INT32 number);
		// * Adds hex number to string
		_H3API_ H3String& operator+=(UINT32 number);

		// * Compare using strcmp

		_H3API_ BOOL operator==(const H3String& h3str) const;
		_H3API_ BOOL operator==(LPCSTR str) const;
		_H3API_ BOOL operator!=(const H3String& h3str) const;
		_H3API_ BOOL operator!=(LPCSTR str) const;

		// * Returns char at offset
		_H3API_ CHAR  operator[](UINT32 pos) const;
		_H3API_ CHAR& operator[](UINT32 pos);

		// * The number of times this string is referenced - avoids deletion from destructor in references
		_H3API_ INT8 References() const;

		// * Increase the number of references to this string
		_H3API_ VOID IncreaseReferences();

		// * assigns a number with commas to a string
		_H3API_ BOOL FormattedNumber(INT32 number);

		// * assigns a scaled number with k, M or B index and number of decimals
		_H3API_ BOOL ScaledNumber(INT32 number, INT32 decimals = 1);

		// * use sprintf on a H3String, appending the result to the end
		// * uses H3 assets, buffer limit 512 chars
		_H3API_ H3String& PrintfAppendH3(LPCSTR format, ...);

		_H3API_ INT32  ToSigned() const;
		_H3API_ UINT32 ToUnsigned() const;
		_H3API_ DOUBLE ToDouble() const;
		_H3API_ INT32  HexToSigned() const;
		_H3API_ UINT32 HexToUnsigned() const;

		// * use sprintf on a H3String directly
		_H3API_ H3String& Printf(LPCSTR format, ...);
		// * use sprintf on a H3String, appending the result to the end
		_H3API_ H3String& PrintfAppend(LPCSTR format, ...);

		/**
		 * @brief Get Local Time as a string
		 * @return H3String formatted time
		 */
		_H3API_ static H3String GetLocalTime();
		/**
		 * @brief Adds commas after every 3 digits of a number
		 * @param number any integer
		 * @return formatted number
		 */
		_H3API_ static H3String FormatNumber(INT32 number);
		/**
		 * @brief Changes a number to use short scale format, e.g. 123k, 123.4k
		 * @param number any integer
		 * @param decimals How many decimals to show
		 * @return formatted short scale number
		 */
		_H3API_ static H3String ShortScale(INT32 number, INT32 decimals);
		/**
		 * @brief sprintf for any buffer size, uses _snprintf to determine length
		 * @param format String format
		 * @param ... arguments
		 * @return formatted text
		 */
		_H3API_ static H3String Format(LPCSTR format, ...);
		_H3API_ static H3String Format(LPCSTR format, va_list args);
		/**
		 * @brief sprintf using H3 assets and a buffer of size 512
		 * Faster than ::Format but riskier
		 * @param format String format
		 * @param ... arguments
		 * @return formatted text
		 */
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

		/*
		*
		* Non-member functions
		*
		*/

		// * H3Strings

		friend inline H3String operator+(const H3String& lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(const H3String& lhs, H3String&& rhs);
		friend inline H3String operator+(H3String&& lhs, const H3String& rhs);
		friend inline H3String operator+(H3String&& lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		// * const char*

		friend inline H3String operator+(const H3String& lhs, LPCSTR rhs);
		friend inline H3String operator+(LPCSTR lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(H3String&& lhs, LPCSTR rhs);
		friend inline H3String operator+(LPCSTR lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		// * char

		friend inline H3String operator+(const H3String& lhs, CHAR rhs);
		friend inline H3String operator+(CHAR lhs, const H3String& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3String operator+(H3String&& lhs, CHAR rhs);
		friend inline H3String operator+(CHAR lhs, H3String&& rhs);
#endif /* _H3API_CPLUSPLUS11_ */

		// * these enum values follow std::string naming convention
		enum eH3String : UINT
		{
			max_len     = static_cast<UINT>(-3),
			npos        = static_cast<UINT>(-1),
		};

		_H3API_ H3WString ToH3WString(UINT code_page = CP_ACP) const;
	};
	_H3API_ASSERT_SIZE_(H3String);

	/**
	 * @brief std::wstring in h3 format
	*/
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

		/*
		*
		* Non-member functions
		*
		*/

		// * H3WString

		friend inline H3WString operator+(const H3WString& lhs, const H3WString& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3WString operator+(H3WString&& lhs, const H3WString& rhs);
		friend inline H3WString operator+(const H3WString& lhs, H3WString&& rhs);
		friend inline H3WString operator+(H3WString&& lhs, H3WString&& rhs);
#endif
		// * LPCWSTR

		friend inline H3WString operator+(const H3WString& lhs, LPCWSTR rhs);
		friend inline H3WString operator+(LPCWSTR lhs, const H3WString& rhs);
#ifdef _H3API_CPLUSPLUS11_
		friend inline H3WString operator+(H3WString&& lhs, LPCWSTR rhs);
		friend inline H3WString operator+(LPCWSTR lhs, H3WString&& rhs);
#endif
		// * WCHAR

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
