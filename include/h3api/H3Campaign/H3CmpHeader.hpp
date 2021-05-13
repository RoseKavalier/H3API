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
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Constants/H3CstCampaigns.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpHeader);
	struct H3GzInflateBuf;
	struct H3CmpScenarioHeader;

#pragma pack(push, 4)

	struct H3CmpHeader
	{
		h3unk32                        _f_0; // set as 2 for old campaign versions
		/** @brief [04] .h3c campaign name*/
		H3String                       filename;
		/** @brief [14] */
		eCampaignType                  type;
		/** @brief [18] */
		INT32                          mapCount;
		/** @brief [1C] */
		H3String                       name;
		/** @brief [2C] */
		H3String                       description;
		/** @brief [3C] */
		H3Vector<H3CmpScenarioHeader*> scenarios;
		/** @brief [4C] raw deflated h3c buffer*/
		PBYTE                          rawBuffer;
		/** @brief [50] used to parse rawBuffer */
		H3GzInflateBuf*                gzBuf;
		/** @brief [54] */
		BOOL8                          canChooseDifficulty;
		/** @brief [58] */
		eCampaignMusic                 music;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
