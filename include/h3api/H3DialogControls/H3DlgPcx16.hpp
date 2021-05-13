//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3DialogControls/H3DlgItem.hpp"

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
		/** @brief [v34]*/
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;
	protected:
		/** @brief [30]*/
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
