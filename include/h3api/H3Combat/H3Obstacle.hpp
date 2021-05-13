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

namespace h3
{
	_H3API_DECLARE_(Obstacle);
	struct H3LoadedDef;
	struct H3ObstacleInfo;

#pragma pack(push, 4)

	// * information about obstacle in combat manager
	struct H3Obstacle
	{
		_H3API_SIZE_(0x18);

		/** @brief [00] */
		H3LoadedDef* def;
		/** @brief [04] */
		H3ObstacleInfo* info;
		/** @brief [08] */
		UINT8 anchorHex;
		/** @brief [09] if anyone owns this, otherwise -1 */
		INT8 ownerSide;
		/** @brief [0A] uncertain but set when features are triggered , default 1*/
		h3unk8 featureTriggered;
		/** @brief [0C] damage of existing feature (e.g. firewall), -1 if not set */
		UINT32 featureDamage;
		/** @brief [10] defaults to 0 */
		UINT32 featureDuration;
		/** @brief [14] combat animation index, if not set -1 */
		UINT32 animationIndex;
	};
	_H3API_ASSERT_SIZE_(H3Obstacle);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
