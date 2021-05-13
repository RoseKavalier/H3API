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
#include "h3api/H3Dialogs/H3BaseDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(TownDlg);

#pragma pack(push, 4)

	struct H3TownDialog : H3BaseDlg
	{
		_H3API_SIZE_(0xB4);
		/** @brief [4C]*/
		INT32      townIndex;
		/** @brief [50]*/
		RGB565*    drawBuffer;
		/** @brief [54] 8th slot for summoning portal creatures*/
		H3DlgDef*  creaturePortraits[8];
		/** @brief [74] 8th slot for summoning portal creatures*/
		H3DlgText* creaturesText[8];
		/** @brief [94] 8th slot for summoning portal creatures*/
		INT32      creatureTypes[8];
	};
	_H3API_ASSERT_SIZE_(H3TownDialog);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
