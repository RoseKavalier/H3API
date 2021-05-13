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
#include "h3api/H3Constants/H3CstSpells.hpp"

namespace h3
{
	_H3API_DECLARE_(Spell);

#pragma pack(push, 4)

	/** @brief information about all spells (including creature spell-abilities)*/
	struct H3Spell
	{
		_H3API_SIZE_(0x88);
		_H3API_GET_INFO_(0x687FA8, H3Spell);

		/** @brief [0]*/
		eSpellTarget type;
		/** @brief [4] name of the sound to use*/
		LPCSTR soundName;
		/** @brief [8]*/
		UINT32 animationIndex;
	public:
		/** @brief [C] bitfield of spell data*/
		union
		{
			struct
			{
				BOOL8 battlefieldSpell    : 1; // [1]
				BOOL8 mapSpell            : 1; // [2]
				BOOL8 timeScale           : 1; // [4]
				BOOL8 creatureSpell       : 1; // [8]
				BOOL8 singleTarget        : 1; // [10]
				BOOL8 singleShootingStack : 1; // [20]
				BOOL8 expertMassVersion   : 1; // [40]
				BOOL8 targetAnywhere      : 1; // [80]
				BOOL8 removeObstacle      : 1; // [100]
				/** @brief All damage spells*/
				BOOL8 damageSpell         : 1; // [200]
				BOOL8 mindSpell           : 1; // [400]
				BOOL8 friendlyMass        : 1; // [800]
				BOOL8 cannotTargetSiege   : 1; // [1000]
				BOOL8 spellFromArtifact   : 1; // [2000]
				/** @brief Air/Fire Shield, Protections From, Anti-Magic, Magic Mirror, Stone Skin, Counterstrike*/
				BOOL8 defensive           : 1; // [4000]
				/** @brief All damage spells except INFERNO and CHAING LIGHTNING*/
				BOOL8 aiDamageSpell      : 1; // [8000]
				/** @brief Inferno and Chaing Lightning*/
				BOOL8 aiAreaEffect        : 1; // [10000]
				/** @brief Death Ripple, Destroy Undead and Armageddon*/
				BOOL8 aiMassDamageSpell  : 1; // [20000]
				/** @brief Shield, Air Shield, ... Berserk, Teleport, Clone, NO SUMMON SPELLS*/
				BOOL8 aiNonDamageSpell   : 1; // [40000]
				/** @brief Resurrection, Animate Dead, Hypnotize, all summon spells*/
				BOOL8 aiCreatures         : 1; // [80000]
				/**
				 * @brief Summon Boat, Fly, WW, DD, TP
				 * Earthquake, Titan's Lightning Bolt (not sure why these are here???)
				 */
				BOOL8 aiAdventureMap      : 1; // [100000]
				// * there are no spells with further bits set
			};
			UINT32 flags;
		};

		/** @brief [10] full name*/
		LPCSTR name;
		/** @brief [14] abbreviated name*/
		LPCSTR shortName;
		/** @brief [18] 0..5*/
		INT32 level;
		/** @brief [1C] */
		eSpellchool school;
		/** @brief [20] mana cost at each spell expertise*/
		INT32 manaCost[4];
		/** @brief [30] value multiplied by spell power*/
		INT32 spEffect;
		/** @brief [34] base value of spell for calculations*/
		INT32 baseValue[4];
		/** @brief [44] change for each class?*/
		INT32 chanceToGet[9];
		/** @brief [68] */
		UINT32 aiValue[4];
		/** @brief [78] description of spell based on secondary skill level*/
		LPCSTR description[4];

		_H3API_ INT32 GetBaseEffect(INT32 level, INT32 spellPower);
		_H3API_ static BOOL8 SingleTarget(INT32 id, INT32 expertise);
	};
	_H3API_ASSERT_SIZE_(H3Spell);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
