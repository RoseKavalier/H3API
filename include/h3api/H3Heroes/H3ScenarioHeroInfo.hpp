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
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_DECLARE_(ScenarioHeroInfo);

#pragma pack(push, 4)

	struct H3ScenarioHeroInfo
	{
		_H3API_SIZE_(0x1C);
		/** @brief [00]*/
		INT32    heroId;
		/** @brief [04]*/
		INT32    portraitId;
		/** @brief [08]*/
		H3String name;
		/** @brief [18]*/
		H3PlayersBitfield32 availableToPlayers;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioHeroInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
