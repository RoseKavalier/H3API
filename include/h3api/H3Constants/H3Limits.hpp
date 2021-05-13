//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
	namespace limits
	{
		constexpr INT32 ARTIFACTS              = 141;
		constexpr INT32 ARTIFACT_SLOTS         = 19;
		constexpr INT32 BUILDINGS              = 44;
		constexpr INT32 COMBAT_CREATURES       = 20;  // 21st is usually excluded
		constexpr INT32 CREATURES              = 145; // up to troll
		constexpr INT32 CREATURE_BANKS         = 11;
		constexpr INT32 FORT_ELEMENTS          = 18;
		constexpr INT32 HEROES                 = 156;
		constexpr INT32 HERO_CLASSES           = 18;
		constexpr INT32 OBJECTS                = 232;
		constexpr INT32 PLAYERS                = 8;
		constexpr INT32 RESOURCES              = 7;
		constexpr INT32 SECONDARY_SKILLS       = 28;
		constexpr INT32 SPELLS                 = 70;
		constexpr INT32 TERRAIN                = 10;
		constexpr INT32 TOTAL_CREATURES        = 150;     // catapult..arrow tower
		constexpr INT32 TOTAL_COMBAT_CREATURES = 20  + 1; // 21st is usually excluded
		constexpr INT32 TOTAL_HEROES           = 156 + 7; // hidden campaign heroes
		constexpr INT32 TOTAL_HERO_CLASSES     = 18  + 2; // random hero and placeholder hero
		constexpr INT32 TOTAL_SPELLS           = 81;      // including creature spells
		constexpr INT32 TOWNS                  = 9;
		constexpr INT32 TOWNS_ON_MAP           = 48;
	}
}
