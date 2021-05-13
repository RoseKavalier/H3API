//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3ScreenChat.hpp"
#include "h3api/H3Containers/H3String.hpp"

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
