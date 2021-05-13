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
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(PlayerAttributes);
	struct H3CustomHeroData;

#pragma pack(push, 4)

	struct H3PlayerAttributes
	{
		_H3API_SIZE_(0x44);
		/** @brief [00]*/
		BOOL8 humanPlayable;
		/** @brief [01]*/
		BOOL8 computerPlayable;
		/** @brief [04]*/
		INT32 aiBehaviour;
		/** @brief [08]*/
		UINT16 availableFactionsBitset;
		/** @brief [0A]*/
		BOOL8 ownsRandomTown;
		/** @brief [0B]*/
		BOOL8 generateHeroAtMainTown;
		/** @brief [0C]*/
		BOOL8 hasMainTown;
		/** @brief [10]*/
		BOOL32 generateHero;
		/** @brief [14]*/
		H3Position mainTownPosition;
		/** @brief [18]*/
		BOOL8 hasRandomHero;
		/** @brief [1C]*/
		INT32 mainHeroId;
		/** @brief [20]*/
		INT32 mainHeroCustomPicture;
		/** @brief [24]*/
		CHAR customName[12];
		/** @brief [30]*/
		h3unk32 powerPlaceholder;
		/** @brief [34]*/
		H3Vector<H3CustomHeroData> heroesData;
	};
	_H3API_ASSERT_SIZE_(H3PlayerAttributes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
