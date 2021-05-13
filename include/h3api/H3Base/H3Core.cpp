//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-05                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base/H3Core.hpp"
#include "h3api/H3Base/H3Functions.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"

namespace h3
{
	_H3API_ H3Version::H3Version()
	{
		PIMAGE_DOS_HEADER pDOSHeader = PIMAGE_DOS_HEADER(0x400000);
		PIMAGE_NT_HEADERS pNTHeaders = PIMAGE_NT_HEADERS(PBYTE(pDOSHeader) + pDOSHeader->e_lfanew);
		DWORD entry                  = pNTHeaders->OptionalHeader.AddressOfEntryPoint;

		// * checks entry point of exe
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

		// * work with positives
		INT64 m;
		if (num != INT_MIN)
			m = Abs(num);
		else
			m = INT64(INT_MAX) + 1;

		// * if smaller than specified value, print regular number
		if (m < RN_MIN_VALUE)
		{
			const INT32 r = libc::sprintf(out, "%d", num);
			return r;
		}

		// * round the number to required precision
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
		// * rounding, same idea as f = round(f + 0.5)
		d = (d + plus) / div * div;

		// * print template
		INT32 len = libc::sprintf(buffer, "%d", d);
		INT32 c = 2 - len % 3;

		CHAR *dst = out;
		CHAR *src = buffer;

		// * leading negative
		if (num < 0)
			*dst++ = '-';

		// * copy source to destination
		while (*src)
		{
			*dst++ = *src++;
			if (c == 1)
			{
				// * if decimals are required
				if (dec)
				{
					*dst++ = '.';
					// * add required precision
					for (INT32 i = 0; i < dec; i++)
						*dst++ = *src++;
				}
				break;
			}
			c = (c + 1) % 3;
		}
		// * add proper ending
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
