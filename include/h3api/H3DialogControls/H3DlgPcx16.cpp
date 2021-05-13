//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgPcx16.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"

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
