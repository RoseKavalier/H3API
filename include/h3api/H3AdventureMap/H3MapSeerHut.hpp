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
#include "h3api/H3AdventureMap/H3MapQuestGuard.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemSeerHut);

#pragma pack(push, 1)
	/** @brief seer hut is a quest guard plus some information about reward*/
	struct H3SeerHut : H3QuestGuard
	{
		_H3API_SIZE_(0x13);

		/** @brief [5] */
		INT32 rewardType;
		/** @brief [9] */
		INT32 rewardValue;
		/** @brief [D] */
		INT32 rewardValue2;
		/** @brief [11] */
		BYTE seerNameId;
		/** @brief [12] */
		h3unk8 _f_12;

		_H3API_ WORD  CreatureCount() const;
		_H3API_ INT8  Luck() const;
		_H3API_ INT8  Morale() const;
		_H3API_ INT32 Primary() const;
		_H3API_ INT8  PrimaryCount() const;
	};
	_H3API_ASSERT_SIZE_(H3SeerHut);
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)

	/** @brief data for seer huts on adventure map*/
	struct H3MapitemSeerHut
	{
		UINT id;

		_H3API_ H3SeerHut* Get();
		_H3API_ H3SeerHut* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
