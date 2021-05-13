//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgPcx.hpp"
#include "h3api/H3Assets/H3LoadedPcx.hpp"

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
