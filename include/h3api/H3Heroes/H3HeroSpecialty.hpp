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
#include "h3api/H3Constants/H3CstHeroes.hpp"
#include "h3api/H3Constants/H3CstSpells.hpp"

namespace h3
{
	_H3API_DECLARE_(HeroSpecialty);

#pragma pack(push, 4)

	/** @brief specialty structure of heroes*/
	struct H3HeroSpecialty
	{
		_H3API_SIZE_(0x28);
		_H3API_GET_INFO_(0x679C80, H3HeroSpecialty);

		/** @brief [0]*/
		eHeroSpecialty type;
		/** @brief [4] the ID of skill, creature, resource, spell, creature to upgrade (Dracon/Gelu)*/
		UINT32 bonusId;
		/** @brief [8] to be used with creature bonus*/
		UINT32 attackBonus;
		/** @brief [C] to be used with creature bonus */
		UINT32 defenseBonus;
		/** @brief [10] to be used with creature bonus */
		UINT32 damageBonus;
		/** @brief [14] the ID of the second creature that can be upgraded */
		UINT32 upgrade2;
		/** @brief [18] the ID of the upgraded creature (Enchanters/Sharpshooters) */
		UINT32 upgradeTo;
		/** @brief [1C] short specialty name*/
		LPCSTR spShort;
		/** @brief [20] full specialty name*/
		LPCSTR spFull;
		/** @brief [24] specialty description*/
		LPCSTR spDescr;

		_H3API_ BOOL   HasSpellSpec() const;
		_H3API_ eSpell GetSpell() const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
