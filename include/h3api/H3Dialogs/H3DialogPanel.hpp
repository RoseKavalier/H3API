//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgBasePanel);

	struct H3BaseDlg;
	struct H3DlgItem;
	struct H3LoadedPcx16;

#pragma pack(push, 4)

	struct H3DlgBasePanel : H3Allocator
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x64235C);
	protected:
		/** @brief [v00]*/
		_H3API_ virtual H3DlgBasePanel* vDestroy(BOOL8 deallocate) = 0;
		/** @brief [v04]*/
		_H3API_ virtual VOID            vFunc04(INT unknown) = 0;
		/** @brief [v08]*/
		_H3API_ virtual VOID            vFunc08(INT unknown1, INT unknown2) = 0;
		/** @brief [v0C]*/
		_H3API_ virtual VOID            vDrawToWindow() = 0;

		/** @brief [04]*/
		INT32                x;
		/** @brief [08]*/
		INT32                y;
		/** @brief [0C]*/
		INT32                width;
		/** @brief [10]*/
		INT32                height;
		/** @brief [14]*/
		H3Vector<H3DlgItem*> items;
		/** @brief [24]*/
		H3BaseDlg*           parent;
		/** @brief [28]*/
		INT32                largestId;
		/** @brief [2C]*/
		INT32                smallestId;
		/** @brief [30]*/
		H3LoadedPcx16*       backupPcx;

		_H3API_ VOID backupScreen();
		_H3API_ VOID restoreBackupScreen();
	public:
		_H3API_ H3Vector<H3DlgItem*>& GetItems();

		_H3API_ H3DlgItem* AddItem(H3DlgItem* item);
		_H3API_ VOID Redraw();
		_H3API_ VOID Hide();
		_H3API_ VOID Show();
		_H3API_ VOID Move(INT xDest, INT yDest);
		_H3API_ VOID MoveRelative(INT xDelta, INT yDelta);

		_H3API_ INT32 GetWidth() const;
		_H3API_ INT32 GetHeight() const;
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
	};
	_H3API_ASSERT_SIZE_(H3DlgBasePanel);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
