//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	struct H3RmgZoneConnection;

#pragma pack(push, 4)

	struct H3RmgZone
	{
		_H3API_SIZE_(0xD4);
		struct Treasure
		{
			INT32 lowValue;
			INT32 highValue;
			INT32 density;
		};
		typedef H3Vector<H3RmgZoneConnection> ZoneConnectionVec;

		INT32             id;                      /**< @brief [00]*/
		INT32             type;                    /**< @brief [04] 0..3 human-computer-treasure-junction*/
		INT32             baseSize;                /**< @brief [08]*/
		INT32             minHumanPositions;       /**< @brief [0C]*/
		INT32             maxHumanPositions;       /**< @brief [10]*/
		INT32             minTotalPositions;       /**< @brief [14]*/
		INT32             maxTotalPositions;       /**< @brief [18]*/
		INT32             townsOwner;              /**< @brief [1C]*/
		INT32             minPlayerTowns;          /**< @brief [20]*/
		INT32             minPlayerCastles;        /**< @brief [24]*/
		INT32             playerTownDensity;       /**< @brief [28]*/
		INT32             playerCastleDensity;     /**< @brief [2C]*/
		INT32             minNeutralTowns;         /**< @brief [30]*/
		INT32             minNeutralCastles;       /**< @brief [34]*/
		INT32             neutralTownsDensity;     /**< @brief [38]*/
		INT32             neutralCastlesDensity;   /**< @brief [3C]*/
		BOOL8             townsAreSameType;        /**< @brief [40]*/
		BOOL8             townTypes[9];            /**< @brief [41]*/
		INT32             minMines[7];             /**< @brief [4C]*/
		INT32             minesDensity[7];         /**< @brief [68]*/
		BOOL8             terrainMatchesTown;      /**< @brief [84]*/
		BOOL8             allowedTerrains[8];      /**< @brief [85]*/
		INT32             monsterStrength;         /**< @brief [90] 0/2/3/4 non/weak/average/strong*/
		BOOL8             monstersMatchTown;       /**< @brief [94]*/
		BOOL8             monstersAllowNeutrals;   /**< @brief [95]*/
		INT8              monstersAllowedTowns[9]; /**< @brief [96]*/
		Treasure      treasures[3];            /**< @brief [A0]*/
		ZoneConnectionVec connections;             /**< @brief [C4]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZone);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
