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
#include "h3api/H3Creatures/H3Army.hpp"
#include "h3api/H3Artifacts/H3Artifact.hpp"
#include "h3api/H3Containers/H3Bitset.hpp"

namespace h3
{
	_H3API_DECLARE_(Hero);
	struct H3CombatCreature;

#pragma pack(push, 1)
	// * Hero structure on the adventure map
	struct H3Hero
	{
		_H3API_SIZE_(0x492);

		/** @brief [0] */
		INT16   x;
		/** @brief [2] */
		INT16   y;
		/** @brief [4] */
		INT16   z;
		/** @brief [6] used when the current hero is active and appears on H3MapItem*/
		BOOL8	isVisible;
		/** @brief [7] used to show / hide active hero*/
		H3Position  mixedPosition;
		/** @brief [B] true if there is an object below the hero*/
		BOOL8	objectBelow;
		/** @brief [C] type of H3MapItem under hero*/
		INT32   objectTypeUnder;
	protected:
		/** @brief [10] ??? related to H3MapItem under hero*/
		UINT32  _flag;
	public:
		/** @brief [14] setup of H3MapItem under the hero*/
		UINT32  objectBelowSetup;
		/** @brief [18] number of spell points*/
		INT16   spellPoints;
	public:
		/** @brief [1A] 0..156, has to match class, cannot be used to change specialty*/
		INT32	id;
	protected:
		/** @brief [1E] set at 4D8DB1, unknown*/
		UINT	number;
	public:
		/** @brief [22] 0..7 Red ~ Pink*/
		INT8	owner;
		/** @brief [23] hero's name, null-terminated*/
		CHAR	name[12+1];
		/**
		 * @brief [30] index of the hero sprite to use 0..17 Knight ~ Elementalist
		 * 0x12 boat sprite no class - can't navigate water (more sprites after but can crash)
		 */
		INT32   hero_class;
		/** @brief [34] id of the hero's portrait, 0 ~ 156*/
		UINT8   picture;
		/** @brief [35] planned x destination*/
		INT32	dest_x;
		/** @brief [39] planned y destination*/
		INT32	dest_y;
		/** @brief [3D] planned z destination*/
		INT32	dest_z;
	protected:
		h3unk8	_f_41[3];
	public:
		/** @brief [44] starting x position*/
		UINT8   patrol_x;
		/** @brief [45] starting y position*/
		UINT8   patrol_y;
		/** @brief [46] radius for patrolling, -1 means no range limit*/
		INT8   patrolRadius;
	protected:
		h3unk8	_f_47;
		h3unk8  _f_48;
	public:
		/** @brief [49] maximum movement points of the hero on a given turn*/
		INT32   maxMovement;
		/** @brief [4D] remaining movement points of the hero on a given turn*/
		INT32   movement;
		/** @brief [51] current experience of the hero*/
		INT32	experience;
		/** @brief [55] current level of the hero*/
		INT16   level;
	protected:
		/** @brief [57] 32 visited object types per hero*/
		H3Bitfield  learningStones;
		/** @brief [5B] 32 visited object types per hero*/
		H3Bitfield  marlettoTower;
		/** @brief [5F] 32 visited object types per hero*/
		H3Bitfield  gardenRevelation;
		/** @brief [63] 32 visited object types per hero*/
		H3Bitfield  mercenaryCamp;
		/** @brief [67] 32 visited object types per hero*/
		H3Bitfield  starAxis;
		/** @brief [6B] 32 visited object types per hero*/
		H3Bitfield  treeKnowldge;
		/** @brief [6F] 32 visited object types per hero*/
		H3Bitfield  libraryEnlightenment;
		/** @brief [73] 32 visited object types per hero*/
		H3Bitfield  arena;
		/** @brief [77] 32 visited object types per hero*/
		H3Bitfield  schoolMagic;
		/** @brief [7B] 32 visited object types per hero*/
		H3Bitfield  schoolWar;
		UINT8	_f_7F[16];
	public:
		/** @brief [8F] seed for skill tree, 1..255*/
		UINT8	levelSeed;
	protected:
		UINT8	_f_90;
	public:
		/** @brief [91] creatures of the hero*/
		H3Army army;
		/** @brief [C9] level of each secondary skill*/
		INT8   secSkill[28];
		/** @brief [E5] order in which to display SSkills (1,2,3,...)*/
		INT8   secSkillPosition[28];
		/** @brief [101] number of secondary skills the hero has*/
		INT32  secSkillCount;
		/** @brief [105] temporary hero flags*/
		union
		{
			struct
			{
				/** @brief [0x00000001] Visited Well*/
				unsigned well              : 1;
				/** @brief [0x00000002] Visited Stables*/
				unsigned stables           : 1;
				/** @brief [0x00000004] Visited Buoy*/
				unsigned buoy              : 1;
				/** @brief [0x00000008] Visited Swan Pond*/
				unsigned swanPond          : 1;
				/** @brief [0x00000010] Visited idol of fortune on days 1~6, morale bonys*/
				unsigned idolFortuneMorale : 1;
				/** @brief [0x00000020] -1 luck from fountain of fortune*/
				unsigned fountainFortune1  : 1;
				/** @brief [0x00000040] visited watering hole*/
				unsigned wateringHole      : 1;
				/** @brief [0x00000080] visited oasis*/
				unsigned oasis             : 1;
				/** @brief [0x00000100] visited temple on days 1~6*/
				unsigned temple            : 1;
				/** @brief [0x00000200] shipwreck morale penalty*/
				unsigned shipwreck         : 1;
				/** @brief [0x00000400] crypt morale penalty*/
				unsigned crypt             : 1;
				/** @brief [0x00000800] derelict ship morale penalty*/
				unsigned derelectShip      : 1;
				/** @brief [0x00001000] pyramid morale penalty*/
				unsigned pyramid           : 1;
				/** @brief [0x00002000] visited faerie ring*/
				unsigned faerieRing        : 1;
				/** @brief [0x00004000] visited fountain of youth*/
				unsigned fountainOfYouth   : 1;
				/** @brief [0x00008000] visited mermaids*/
				unsigned mermaids          : 1;
				/** @brief [0x00010000] visited rally flag*/
				unsigned rallyFlag         : 1;
				/** @brief [0x00020000] hero is in tavern, see 0x4DA4D1*/
				unsigned inTavern          : 1;
				/** @brief [0x00040000] hero is in a boat*/
				unsigned inBoat            : 1;
				/** @brief [0x00080000] */
				unsigned unk80000          : 1;
				/** @brief [0x00100000] visited sirens*/
				unsigned sirens            : 1;
				/** @brief [0x00200000] warrior's tomb morale penalty*/
				unsigned warriorTomb       : 1;
				/** @brief [0x00400000] typed luck cheat*/
				unsigned luckCheat         : 1;
				/** @brief [0x00800000] typed morale cheat*/
				unsigned moraleCheat       : 1;
				/** @brief [0x01000000] typed speed cheat*/
				unsigned speedCheat        : 1;
				/** @brief [0x02000000] luck bonus from idol of fortune*/
				unsigned idolFortuneLuck   : 1;
				/** @brief [0x04000000] visited temple on day 7, +2 morale*/
				unsigned temple2           : 1;
				/** @brief [0x08000000] +1 luck from fountain of fortune*/
				unsigned fountainFortune2  : 1;
				/** @brief [0x10000000] +2 luck from fountain of fortune*/
				unsigned fountainFortune3  : 1;
				/** @brief [0x20000000] +3 luck from fountain of fortune*/
				unsigned fountainFortune4  : 1;
				/** @brief [0x40000000-0x80000000] */
				unsigned unk40000000       : 2;
			};
			UINT32 flags;
		};
		/** @brief [109] */
		FLOAT  AI_experienceEffectiveness;
		/** @brief [10D] number of times dimension door was cast this day*/
		INT8	dimDoorCastCount; // +10D
		/** @brief [10E] spell expertise of disguise that was cast*/
		INT32   disguisePower;  // +10E
		/** @brief [112] spell expertise of fly that was cast*/
		INT32	flyPower;
		/** @brief [116] spell expertise of waterwalk that was cast*/
		INT32	waterwalkPower; // +116
		/** @brief [11A] */
		INT8	moraleBonus;
		/** @brief [11B] */
		INT8	luckBonus;
		/** @brief [11C] */
		BOOL8	isSleeping;
	protected:
		h3unk8  _f_11D[4];
	public:
		/** @brief [121] (48 towns, room for 64)*/
		H3VisitedTownsBitset visitedTowns;
		/** @brief [129] spell expertise of Visions spell*/
		INT32	visionPower; // +129
		/** @brief [12D] 19 artifacts on a hero*/
		H3Artifact bodyArtifacts[19];
	protected:
		/** @brief [1C5] ?*/
		UINT8	freeAddSlots;
	public:
		/** @brief [1C6] whether an artifact slot is blocked or not*/
		UINT8	blockedArtifacts[14];
		/** @brief [1D4] 64 artifacts in the backpack*/
		H3Artifact backpackArtifacts[64];
		/** @brief [3D1] number of artifacts in the backpack*/
		INT8	backpackCount;
		/** @brief [3D5] male or female*/
		BOOL    isFemale;
		/** @brief [3D9] has custom biography?*/
		BOOL8	customBio;
		/** @brief [3DA] custom biography*/
		H3String biography;
		/** @brief [3EA] Spells the hero has learned*/
		BOOL8   learnedSpells[70];
		/** @brief [430] Spells the hero has access to through artifacts*/
		BOOL8   availableSpell[70];
		/** @brief [476] four primary skills, attack, defense, spell power, knowledge*/
		INT8   primarySkill[4];
		/** @brief [47A] */
		UINT   aiAggressiveness;
		/** @brief [47E] */
		UINT   aiSpellPowerEffectiveness;
		/** @brief [482] */
		UINT   aiSpellLengthEffectiveness;
		/** @brief [486] */
		UINT   aiKnowledgeEffectiveness;
		/** @brief [48A] */
		UINT   aiDoubleSpellPointsEffectiveness;
		/** @brief [48E] */
		UINT   aiExtraSpellPointsEffectiveness;

	public:
		// * calculates maximum daily movement on land
		_H3API_ INT32 MaxLandMovement();
		// * calculates maximum daily movement on water
		_H3API_ INT32 MaxWaterMovement();
		// * calculates maximum daily movement automatically
		_H3API_ INT32 CalcMaxMovement();
		// * give an artifact by reference
		_H3API_ VOID GiveArtifact(const H3Artifact& art, INT32 slot);
		// * give an artifact to hero
		_H3API_ VOID GiveArtifact(const H3Artifact& art);
		// * give an artifact to hero's backpack
		// * index = -1 means first free slot
		_H3API_ VOID GiveBackpackArtifact(const H3Artifact& art, INT32 index = -1);
		// * learn secondary skill by given increase
		_H3API_ VOID LearnSecondarySkill(INT32 id, INT32 increase);
		// * returns effect (none, basic, ... expert) of a spell on a given terrain
		_H3API_ INT32 GetSpellExpertise(INT32 spell_id, INT32 special_terrain);
		// * does this hero own creature of type...?
		_H3API_ BOOL8 HasCreatureType(INT32 type);
		// * the bonus effect on a spell from specialty
		_H3API_ INT32 GetSpellSpecialtyEffect(INT32 spellID, INT32 creatureLevel, INT32 baseDamage);
		// * the bonus effect on a spell from sorcery
		_H3API_ INT32 GetSorceryEffect(INT32 spell_id, INT32 base_damage, H3CombatCreature* mon);
		// * combined effects of a spell on a creature
		_H3API_ INT32 GetRealSpellDamage(INT32 baseDamage, H3CombatCreature* mon, INT32 spellID, H3Hero* enemy);
		// * checks under the hero for special terrain
		_H3API_ INT32 GetSpecialTerrain();
		// * checks under the hero for terrain modifying spells
		_H3API_ INT32 GetSpecialSpellTerrain();
		// * checks if hero has access to a spell
		_H3API_ BOOL HasSpell(INT32 spell);
		// * attempts to combine body artifacts into combo
		_H3API_ VOID BuildCombinationArtifact(INT32 combo_id);
		// * hero loses skill of id
		_H3API_ BOOL UnlearnSkill(INT32 id);
		// * forces recalculation of movement costs on the adventure map
		_H3API_ VOID RecalculateMovement();
		// * is it possible to move to where hero is standing?
		_H3API_ BOOL8 CanFlyOnTile();
		// * how much movement points it costs to move to given mixedPos
		_H3API_ INT32 GetMovementCost(INT32 orientation, UINT32 mixedPos);
		// * the maximum number of level ups required to master remaining secondary skills
		_H3API_ INT32 SSkillsLeftToLearn();
		// * is the hero currently wearing artifact id ?
		_H3API_ BOOL WearsArtifact(INT id);
		// * get the value of primary 0 ~ 3 between 0/1 ~ 99 even if negative
		_H3API_ INT32 GetHeroPrimary(INT primary);
		// * used for diplomacy
		_H3API_ INT32 HasSimilarCreature(INT id);
		// * the class name of the current hero
		_H3API_ LPCSTR GetHeroClassName();
		// * shows hero dialog in right-click mode
		_H3API_ VOID ShowDialog() const;
		/**
		 * @brief Shows the hero information dialog
		 * @param dismissable Whether to enable to Dismiss button
		 * @param not_in_town Whether the dialog is called from town; used to refresh adventure map when dismissing hero
		 * @param right_click Show with right-click or keep open
		 */
		_H3API_ VOID ShowDialog(BOOL32 dismissable, BOOL32 not_in_town, BOOL8 right_click);
		// * army value * (attack & defense power coefficient)
		_H3API_ INT GetPower() const;
		// * whether a specified artifact can replace or be placed in specified slot
		_H3API_ BOOL8 CanReplaceArtifact(INT32 id, INT32 slot) const;
		// * whether a specified artifact can be placed in specified slot
		_H3API_ BOOL8 CanPlaceArtifact(INT32 id, INT32 slot) const;
		// * removes an artifact from player
		_H3API_ VOID RemoveArtifact(INT32 slot);
		// * removes an artifact from player's backpack
		_H3API_ VOID RemoveBackpackArtifact(INT32 slot);
		// * shows animated creature dialog
		_H3API_ VOID ShowCreatureDialog(INT32 slot, BOOL rightClick);
		// * Show info about hero's proficiency at spell
		_H3API_ VOID ShowSpellInfo(INT32 spell, BOOL RMB);
		// * Show info about hero's seconday skill
		_H3API_ VOID ShowSSkillInfo(INT32 skill, BOOL RMB);
		// * Show info about hero's primary skill
		_H3API_ VOID ShowPSkillInfo(INT32 skill, BOOL RMB);
		// * Checks if the hero is wearing all pieces of a combination artifact
		_H3API_ BOOL HasAllCombinationParts(INT slot);
		// * disassembles a combination artifact and
		// * gives a hero all pieces of a combination artifact
		_H3API_ VOID DisassembleCombinationArtifact(INT slot);
		// * opponentArmy may be nullptr to calculate the cost on adventure map
		_H3API_ INT32 CalculateSpellCost(INT spell, H3Army* opponentArmy, INT specialTerrain);
		// * opponentArmy may be nullptr to calculate the cost on adventure map
		_H3API_ INT32 CalculateAdventureMapSpellCost(INT spell);
		// * remove spell points and redraw hero preview on adventure map
		_H3API_ VOID RemoveSpellPointsAndRefresh(UINT16 spellPoints);
		/**
		 * @brief Updates all temporary spells granted by artifacts or learned
		 */
		_H3API_ VOID UpdateAvailableSpell();
		_H3API_ VOID Hide();
		_H3API_ VOID Show();

		/**
		 * @brief Get what creature type would be raised after combat
		 *
		 * @return eCretures to raise
		 */
		_H3API_ eCreature GetNecromancyCreatureId() const;
		/**
		 * @brief Calculates the hero's necromancy power
		 *
		 * @param clamp_value Whether to cap the value at 1.0f
		 * @return Percentage of creatures to raise
		 */
		_H3API_ FLOAT GetNecromancyPower(BOOL8 clamp_value) const;
		/**
		 * @brief Calculates how many mana points to restore daily
		 * Considers mysticism and artifacts worn
		 *
		 * @return The amount of spell points that will be restored
		 */
		_H3API_ INT32 GetSpellPointsRestored() const;
		/**
		 * @brief Calculate the hero's total luck
		 *
		 * @param enemy_hero Can be nullptr if no enemy
		 * @param is_cursed_ground Whether the hero is on cursed ground
		 * @param clamp_value Whether to clamp the value between -3..+3
		 * @return Total luck under specified conditions
		 */
		_H3API_ INT32 GetLuckBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const;
		/**
		 * @brief Calculate the hero's total morale
		 *
		 * @param enemy_hero *UNUSED* Can be nullptr if no enemy
		 * @param is_cursed_ground Whether the hero is on cursed ground
		 * @param clamp_value Whether to clamp the value between -3..+3
		 * @return Total morale under specified conditions
		 */
		_H3API_ INT32 GetMoraleBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const;
		/**
		 * @brief Calculates how many cells should be revealed
		 * Considers Scouting and artifacts
		 *
		 * @return Radius of cells to reveal
		 */
		_H3API_ INT32 GetScoutingRadius() const;
		/**
		 * @brief Get Archery power %
		 * Considers artifacts
		 *
		 * @return 0.0 if no skill
		*/
		_H3API_ FLOAT GetArcheryPower() const;
		/**
		 * @brief Get Offense power %
		 *
		 * @return 0.0 if no skill
		 */
		_H3API_ FLOAT GetOffensePower() const;
		/**
		 * @brief Get percentage of physical damage after Armorer reduction
		 *
		 * @return 1.0 if no skill, 0.0 at minimum
		 */
		_H3API_ FLOAT GetArmorerPower() const;
		/**
		 * @brief How many gold is generated by hero
		 * Considers both estates and gold specialty
		 *
		 * @return The amount of gold to generate
		 */
		_H3API_ INT32 GetGeneratedGold() const;
		/**
		 * @brief The effect of the hero's Eagle Eye Skill
		 * Takes into consideration artifacts
		 *
		 * @return 0.0 if no skill .. 1.0
		 */
		_H3API_ FLOAT GetEagleEyePower() const;
		/**
		 * @brief The fraction of gold you need to pay
		 * Takes into consideration artifacts
		 *
		 * @return 1.0 if no skill .. 0.1
		 */
		_H3API_ FLOAT GetDiplomacyPower() const;
		/**
		 * @brief The chance of a spell to NOT be resisted
		 * Takes into consideration artifacts even without having the skill.
		 *
		 * @return 1.0 if no skill .. 0.0
		 */
		_H3API_ FLOAT GetResistancePower() const;
		/**
		 * @brief The effect of the hero's Learning Skill
		 *
		 * @return 1.0 if no skill, plus whatever bonuses
		 */
		_H3API_ FLOAT GetLearningPower() const;
		/**
		 * @brief The effect of the hero's Intelligence Skill
		 *
		 * @return 1.0 if no skill, plus whatever bonuses
		 */
		_H3API_ FLOAT GetIntelligencePower() const;
		/**
		 * @brief The effect of the hero's First Aid Skill
		 *
		 * @return 1.0 if no skill, plus whatever bonuses
		 */
		_H3API_ FLOAT GetFirstAidPower() const;

	};
	_H3API_ASSERT_SIZE_(H3Hero);

	struct H3DialogHero : H3Hero
	{
		_H3API_GET_INFO_(0x698B70, H3Hero);
	};

#pragma pack(pop) /* align-1 */

} /* namespace h3 */
