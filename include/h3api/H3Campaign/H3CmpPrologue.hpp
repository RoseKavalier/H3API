//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-11              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Constants/H3CstCampaigns.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpPrologue);

#pragma pack(push, 4)

	struct H3CmpPrologue
	{
		_H3API_SIZE_(0x18);

		/** @brief [00]*/
		eCampaignMovie movie;
		/** @brief [04]*/
		eCampaignMusic music;
		/** @brief [08]*/
		H3String       text;
	};
	_H3API_ASSERT_SIZE_(H3CmpPrologue);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
