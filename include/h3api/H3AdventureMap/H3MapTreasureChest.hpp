//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemTreasureChest);

#pragma pack(push, 4)

	/** @brief data for treasure chest on adventure map*/
	struct H3MapitemTreasureChest
	{
		/** @brief [00] 0..1023 artifact IDs*/
		unsigned artifactID : 10;
		/** @brief [10] whether this chest contains an artifact*/
		unsigned hasArtifact : 1;
		/** @brief [11] 2..4 multiply by 500 to get gold amount, -500 to get experience*/
		unsigned bonus : 4;
		/** @brief [15]*/
		unsigned _u1 : 17;

		eArtifact GetArtifact();
		INT32     GetGold();
		INT32     GetExperience();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
