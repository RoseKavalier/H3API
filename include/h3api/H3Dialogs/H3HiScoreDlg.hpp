//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-06              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Dialogs/H3BaseDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(HiScoreDlg);
	struct H3LoadedPcx;

#pragma pack(push, 4)

	/* Dialog used to show high scores. Callback 0x4EA2B0 */
	struct H3HiScoreDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x110);
		_H3API_GET_INFO_(0x699210, H3HiScoreDlg);
		_H3API_VTABLE_(0x63EB98);
		_H3API_CTOR_DTOR_(0x4E9960, -1);

		/** @brief [4C]*/
		H3DlgDef* campaignCreatureDefs[11];
		/** @brief [78]*/
		H3DlgDef* scenarioCreatureDefs[11];
		/** @brief [A4]*/
		h3unk8 _f_A4[88];
		/** @brief [FC]*/
		BOOL8 showingSingleScenarios;
		/** @brief [100]*/
		h3unk32 f100;
		/** @brief [104]*/
		UINT32 time;
		/** @brief [108] */
		H3LoadedPcx* campaignPcx;
		/** @brief [10C]*/
		H3LoadedPcx* scenarioPcx;

		_H3API_ static VOID Show();
	};
	_H3API_ASSERT_SIZE_(H3HiScoreDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
