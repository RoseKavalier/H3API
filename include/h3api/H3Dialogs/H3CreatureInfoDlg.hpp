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
#include "h3api/H3Dialogs/H3NetworkDialog.hpp"
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{

#pragma pack(push, 4)

	struct H3CreatureInfoDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0xB8);

		/** @brief [60]*/
		INT32         creatureId;
		/** @brief [64]*/
		INT32         numberCreatures;
		/** @brief [68]*/
		INT32         morale;
		/** @brief [6C]*/
		H3String      moraleModifiers;
		/** @brief [7C]*/
		INT32         luck;
		/** @brief [80]*/
		H3String      luckModifiers;
		/** @brief [90]*/
		h3unk8        _f_90[32];
		/** @brief [B0]*/
		H3DlgTextPcx* varBackPcx;
		/** @brief [B4]*/
		H3DlgDef*     animation;
	};
	_H3API_ASSERT_SIZE_(H3CreatureInfoDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
