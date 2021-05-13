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
	_H3API_DECLARE_(DlgDef);

#pragma pack(push, 4)

	struct H3DlgDef : public H3DlgItem
	{
		_H3API_SIZE_(0x48);
		_H3API_VTABLE_(0x63EC48);
	protected:
		/** @ brief [v34]*/
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;

	protected:
		/** @ brief [30]*/
		H3LoadedDef* loadedDef;
		/** @ brief [34]*/
		INT32        defFrame;
		/** @ brief [38] */
		INT32        defGroup;
		/** @ brief [3C]*/
		INT32        mirror;
		/** @ brief [40]*/
		INT32        _f_40;
		/** @ brief [44]*/
		BOOL8        closeDialog;
	public:

		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, INT32 width,
			INT32 height, INT32 id, LPCSTR defName, INT32 frame = 0,
			INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame = 0, INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ static H3DlgDef* Create(INT32 x, INT32 y, LPCSTR defName,
			INT32 frame = 0, INT32 group = 0);
		_H3API_ VOID         SetFrame(INT32 frame);
		_H3API_ INT32        GetFrame() const;
		_H3API_ INT32        GetGroup() const;
		_H3API_ VOID         SetGroup(INT32 group);
		_H3API_ VOID         ColorDefToPlayer(INT32 id);
		_H3API_ H3LoadedDef* GetDef();
	};
	_H3API_ASSERT_SIZE_(H3DlgDef);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
