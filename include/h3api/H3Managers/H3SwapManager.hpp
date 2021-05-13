//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"

namespace h3
{
	_H3API_DECLARE_(SwapManager);
	struct H3Hero;
	struct H3SwapManagerDlg;
	struct H3LoadedPcx;

#pragma pack(push, 4)
	/**
	 * @brief trading between two armies, similar to
	 * https://github.com/potmdehex/homm3tools/blob/master/hd_edition/hde_mod/hde/structures/swapmgr.h
	 */
	struct H3SwapManager : public H3Manager
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x64245C);
		_H3API_GET_INFO_(0x6A3D90, H3SwapManager);
		_H3API_CTOR_DTOR_(0x5AE850, -1);

		/** @brief [38] */
		H3SwapManagerDlg* dlg;
		/** @brief [3C] */
		H3LoadedPcx* aTradesel_pcx;
		/** @brief [40]*/
		H3Hero* hero[2];
		/** @brief [48] */
		INT32 heroSelected;
		/** @brief [4C] */
		INT32 heroClicked;
		/** @brief [50] */
		INT32 clickedCreatureSlot;
		/** @brief [54] -1 if none*/
		INT32 slotClicked;
	protected:
		h3unk32 _f_58;
	public:
		/** @brief [5C]*/
		BOOL8 twoHumansTrade;
		/** @brief [5D]*/
		BOOL8 samePlayer;
	protected:
		h3unk32 directPlayOffset_F0_60;
		h3unk32 object_10h_vt_642468_f_64;

	public:
		/**
		 * @brief Orders the manager to close
		 * @param msg The current thread message
		 * @return Value 2 to indicate end of loop
		 */
		_H3API_ INT32 Close(H3Msg& msg);
		_H3API_ VOID UpdateLuckMorale();
		_H3API_ VOID RefreshDialog();
	};
	_H3API_ASSERT_SIZE_(H3SwapManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
