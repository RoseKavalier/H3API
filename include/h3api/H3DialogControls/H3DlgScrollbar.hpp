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
	_H3API_DECLARE_(DlgScrollbar);
	struct H3LoadedPcx;
	struct H3LoadedDef;
	typedef VOID(__fastcall* H3DlgScrollbar_proc)(INT32, H3BaseDlg*);
	typedef VOID(__fastcall* H3DlgScrollbarProc)(INT32, H3BaseDlg&);

#pragma pack(push, 4)

	struct H3DlgScrollbar : public H3DlgItem
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x641D60);
		_H3API_CTOR_DTOR_(0x5963C0, -1);
	protected:
		/** @brief [v34]*/
		_H3API_ virtual VOID vSetTickCount(INT tick) const = 0;
		/** @brief [v38]*/
		_H3API_ virtual VOID vChangeTickPosition(INT change) = 0;
		/** @brief [v3C]*/
		_H3API_ virtual VOID vDecreaseTickPosition(INT change) = 0;
		/** @brief [v40]*/
		_H3API_ virtual VOID vScrollCallOwner() const = 0;

	protected:
		/** @brief [30]*/
		H3LoadedDef*        loadedBtnDef;
		/** @brief [34]*/
		H3LoadedPcx*        loadedPcx;
		/** @brief [38]*/
		INT32               previousTick;
		/** @brief [3C]*/
		INT32               tick;
		/** @brief [40]*/
		INT32               btnPosition;
		/** @brief [44]*/
		INT32               sizeFree;
		/** @brief [48]*/
		INT32               ticksCount;
		/** @brief [4C]*/
		INT32               sizeMax;
		/** @brief [50]*/
		INT32               bigStepSize;
		/** @brief [54]*/
		INT32               btnSize2;
		/** @brief [58]*/
		h3unk32             _f_58;
		/** @brief [5C]*/
		BOOL8               catchKeys;
		/** @brief [5D]*/
		BOOL8               focused;
		/** @brief [60]*/
		h3unk32             _f_60;
		/** @brief [64]*/
		H3DlgScrollbar_proc callBack;

		VOID loadButton(LPCSTR buttonName);

	public:
		_H3API_ static H3DlgScrollbar* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc, BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled);
		_H3API_ INT32 GetTick() const;
		_H3API_ VOID  SetTick(INT32 index);
		_H3API_ VOID  SetBigStep(INT32 step);
		_H3API_ VOID  SetButtonPosition();
		_H3API_ BOOL  IsHorizontal() const;
		_H3API_ INT32 GetRightButtonX() const; // for horizontal scrollbar only!
		_H3API_ INT32 GetHorizontalY() const;
		_H3API_ INT32 GetBackgroundWidth() const;
		_H3API_ INT32 GetBackgroundX() const;
		_H3API_ INT32 GetSliderX() const;
		_H3API_ H3LoadedPcx* GetPcx();
	};
	_H3API_ASSERT_SIZE_(H3DlgScrollbar);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
