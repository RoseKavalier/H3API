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
#include "h3api/H3GameData/H3Resources.hpp"
#include "h3api/H3Constants/H3CstCreatures.hpp"

namespace h3
{
	_H3API_DECLARE_(CreatureInformation);

#pragma pack(push, 4)

	// * hardcoded creature information in heroes3.exe
	struct H3CreatureInformation
	{
		_H3API_SIZE_(0x74);
		_H3API_GET_INFO_(0x6747B0, H3CreatureInformation);

		/** @brief [0] */
		// -1 means neutral
		INT32 town;
		/** @brief [4] */
		// 0 ~ 6
		INT32 level;
		/** @brief [8] */
		LPCSTR soundName;
		/** @brief [C] */
		LPCSTR defName;
		/** @brief [10] */
		union
		{
			struct
			{
				unsigned doubleWide        : 1; // 1
				unsigned flyer             : 1; // 2
				unsigned shooter           : 1; // 4
				unsigned extendedAttack    : 1; // 8 ~ aka dragon breath
				unsigned alive             : 1; // 10
				unsigned destroyWalls      : 1; // 20
				unsigned siegeWeapon       : 1; // 40
				unsigned king1             : 1; // 80 ~ all creatures of 7th level and neutral dragons that do not belong to the KING2 or KING3
				unsigned king2             : 1; // 100
				unsigned king3             : 1; // 200
				unsigned mindImmunity      : 1; // 400
				unsigned shootsRay         : 1; // 800 WoG incorrectly refers to this as 'no obstacle penalty' instead it's a flag used to draw a straight line when shooting - see 0x43F23D
				unsigned noMeleePenalty    : 1; // 1000
				unsigned unk2000           : 1; // 2000
				unsigned fireImmunity      : 1; // 4000
				unsigned doubleAttack      : 1; // 8000
				unsigned noRetaliation     : 1; // 10000
				unsigned noMorale          : 1; // 20000
				unsigned undead            : 1; // 40000
				unsigned attackAllAround   : 1; // 80000
				unsigned fireballAttack    : 1; // 100000
				unsigned cannotMove        : 1; // 200000 ~21
				unsigned summon            : 1; // 400000
				unsigned clone             : 1; // 800000
				unsigned morale            : 1; // 1000000
				unsigned waiting           : 1; // 2000000 ~25
				unsigned done              : 1; // 4000000
				unsigned defending         : 1; // 8000000
				unsigned sacrificed        : 1; // 10000000
				unsigned noColoring        : 1; // 20000000
				unsigned gray              : 1; // 40000000
				unsigned dragon            : 1; // 80000000
			};
			UINT32 flags;
		};
		/** @brief [14] */
		LPCSTR nameSingular;
		/** @brief [18] */
		LPCSTR namePlural;
		/** @brief [1C] */
		LPCSTR description;
		/** @brief [20] */
		H3Resources cost;
		/** @brief [3C] */
		INT32  fightValue;
		/** @brief [40] */
		INT32  aiValue;
		/** @brief [44] */
		INT32  grow;
		/** @brief [48] */
		INT32  hGrow;
		/** @brief [4C] */
		INT32  hitPoints;
		/** @brief [50] */
		INT32  speed;
		/** @brief [54] */
		INT32  attack;
		/** @brief [58] */
		INT32  defence;
		/** @brief [5C] */
		INT32  damageLow;
		/** @brief [60] */
		INT32  damageHigh;
		/** @brief [64] */
		INT32  numberShots;
		/** @brief [68] */
		INT32  spellCharges;
		/** @brief [6C] */
		INT32  advMapLow;
		/** @brief [70] */
		INT32  advMapHigh;

		_H3API_ LPCSTR      GetCreatureName(INT32 count) const;
		_H3API_ H3Resources UpgradeCost(H3CreatureInformation* upg, INT32 count) const;
	};
	_H3API_ASSERT_SIZE_(H3CreatureInformation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
