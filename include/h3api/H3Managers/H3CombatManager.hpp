//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-01              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstCombat.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Combat/H3CombatCreature.hpp"
#include "h3api/H3Combat/H3CombatSquare.hpp"
#include "h3api/H3Combat/H3AdjacentSquares.hpp"

namespace h3
{
	_H3API_DECLARE_(CombatManager);
	struct H3LoadedPcx16;
	struct H3MapItem;
	struct H3Msg;
	struct H3Town;
	struct H3Hero;
	struct H3LoadedDef;
	struct H3DefFrame;
	struct H3Army;
	struct H3Obstacle;
	struct H3Spell;
	struct H3LoadedPcx;
	struct H3CombatCreature;

#pragma pack(push, 4)

	// * the manager of the battlefield
	struct H3CombatManager : public H3Manager
	{
		_H3API_SIZE_(0x140EC);
		_H3API_VTABLE_(0x63D3E8);
		_H3API_GET_INFO_(0x699420, H3CombatManager);

	protected:
		h3unk8 _f_0038[4];
	public:
		/** @brief [3C] */
		eCombatAction action;
		/** @brief [40] */
		INT32 actionParameter;
		/** @brief [44] */
		INT32 actionTarget;
		/** @brief [48] */
		INT32 actionParameter2;
		/** @brief [4C] */
		INT8 accessibleSquares[187];
		/** @brief [107] */
		eCombatSquareAccess accessibleSquares2[187];
		/** @brief [1C4] */
		H3CombatSquare squares[187];
		/** @brief [5394] */
		INT32 landType;
	protected:
		h3unk8 _f_5398[8];
	public:
		/** @brief [53A0] */
		INT32 absoluteObstacleId;
		/** @brief [53A4] */
		INT32 siegeKind;
		/** @brief [53A8] */
		INT32 hasMoat;
	protected:
		h3unk8 _f_53AC[4];
	public:
		/** @brief [53B0] */
		H3LoadedPcx16* drawBuffer;
	protected:
		h3unk8 _f_53B4[4];
	public:
		/** @brief [53B8] */
		BOOL doNotDrawShade;
		/** @brief [53BC] H3MapItem where combat is taking place*/
		H3MapItem* mapitem;
		/** @brief [53C0] special terrain type used*/
		INT32 specialTerrain;
		/** @brief [53C4] */
		BOOL8 antiMagicGarrison;
		/** @brief [53C5] */
		BOOL8 creatureBank;
		/** @brief [53C6] */
		BOOL8 boatCombat;
		/** @brief [53C8] town structure where combat is taking place*/
		H3Town* town;
		/** @brief [53CC] hero structures from each side*/
		H3Hero* hero[2];
		/** @brief [53D4] spell power from each side*/
		INT32 heroSpellPower[2];
	protected:
		h3unk8 _f_53DC[8];
		/** @brief [53E4] */
		// * current group
		UINT32 HeroAnimation[2];
		/** @brief [53EC] */
		UINT32 HeroAnimationFrame[2];
		h3unk8 _f_53F4[16];
		/** @brief [5404] */
		H3LoadedDef* heroDefLoaded[2];
		/** @brief [540C] */
		H3LoadedDef* heroFlagLoaded[2];
		/** @brief [5414] */
		INT32 heroFlagFrame[2];
		/** @brief [541C] */
		RECT heroUpdateRect[2];
		/** @brief [543C] */
		RECT heroFlagUpdateRect[2];
		/** @brief [545C] eagle eye 2x vector*/
		H3Vector<INT32> eagleEyeSpell[2];
	public:
		/** @brief [547C] which stacks are to be affected by a mass spell animation*/
		BOOL8 massSpellTarget[2][20];
		/** @brief [54A4] */
		UINT8 isNotAI[2];
		/** @brief [54A6] */
		BOOL8 isHuman[2];
		/** @brief [54A8] */
		INT32 heroOwner[2];
		/** @brief [54B0] */
		BOOL8 artifactAutoCast[2];
		/** @brief [54B4] */
		BOOL heroCasted[2];
		/** @brief [54BC] */
		INT32 heroMonCount[2];
		/** @brief [54C4] */
		H3Army* army[2];
		/**
		 * @brief [54CC] called "Troop stack" in manual.
		 * a two-sided array of 21 stacks for each side of combat
		 * Note only 20 creatures are typically used, the 21st slot
		 * seems reserved for the presence of the arrow tower when needed
		 */
		H3CombatCreature stacks[2][21];
	protected:
		h3unk8 _f_1329C[4];
	public:
		/** @brief [132A0] */
		INT32 turnsSinceLastEnchanterCast[2];
		/** @brief [132A8] unique monster type to summon with magic for current combat */
		eCreature summonedMonster[2];
	protected:
		h3unk8 _f_132A8[8];
	public:
		/** @brief [132B8] */
		INT32 currentMonSide;
		/** @brief [132BC] */
		INT32 currentMonIndex;
		/** @brief [132C0] */
		INT32 currentActiveSide;
		/** @brief [132C4] */
		INT32 autoCombat;
		/** @brief [132C8] */
		H3CombatCreature* activeStack;
		/** @brief [132CC] */
		INT8 blueHighlight;
		/** @brief [132D0] */
		INT32 creatureAtMousePos;
		/** @brief [132D4] */
		INT32 mouseCoord;
		/** @brief [132D8] */
		INT32 attackerCoord;
		/** @brief [132DC] icons of CRCOMBAT.def, see H3MouseManager::eBattleFieldCursorType*/
		INT32 moveType;
	protected:
		h3unk8 _f_132E0[8];
	public:
		/** @brief [132E8] */
		H3LoadedDef* currentMagicAnim;
		/** @brief [132EC] */
		INT32 currentMagicAnimId;
	protected:
		h3unk8 _f_132F0[4];
	public:
		/** @brief [132F4] */
		INT32 siegeKind2;
		/** @brief [132F8] */
		BOOL finished;
		/** @brief [132FC] */
		struct H3CombatDlg* dlg;
	protected:
		h3unk8 _f_13300[352];
		/** @brief [13460] */
		BOOL8 removeDeadCreatures;
		/** @brief [13464] */
		LPCSTR backgroundPcxName;
	public:
		/** @brief [13468] */
		H3AdjacentSquares adjacentSquares[187];
	protected:
		h3unk8 _f_13D2C[12];
		/** @brief [132E8] */
		RECT updateRect;
		h3unk8 _f_13D48[4];
	public:
		/** @brief [13D4C] */
		INT32 necromancyRaisedAmount;
		/** @brief [13D50] eCreatures */
		eCreature necromancyRaisedMonsters;
	protected:
		/** @brief [13D54] */
		INT cmNumWinPcxLoaded;
	public:
		/** @brief [13D58] information about obstacles on battlefield*/
		H3Vector<H3Obstacle> obstacleInfo;
		/** @brief [13D68] */
		BOOL8 tacticsPhase;
		/** @brief [13D6C] the current turn 0+ */
		INT32 turn;
		/** @brief [13D70] */
		INT32 tacticsDifference;
	protected:
		h3unk8 _f_13D74[4]; // spell related?
	public:
		/** @brief [13D78] */
		struct TownTowerLoaded
		{
			_H3API_SIZE_(0x24);
			INT32        crType2Shot;
			H3LoadedDef* monDefLoaded;
			H3LoadedDef* shotDefLoaded;
			INT32        creatureX;
			INT32        creatureY;
			INT32        orientation;
			INT32        defGroup;
			H3DefFrame*  frame;
			INT32        stackNumber;
		}towers[3];
		/** @brief [13DE4] */
		BOOL32 waitPhase;
	protected:
		/** @brief [13DE8] */
		INT32 heroDAttack;
		/** @brief [13DEC] */
		INT32 heroDDefence;
		/** @brief [13DF0] */
		INT32 heroDSpellPower2;
		/** @brief [13DF4] */
		INT32 heroDSpellPoints;
	public:
		/** @brief [13DF8] 18 pieces each with 5 stages */
		H3LoadedPcx* townSiegePcx[18][5];
		/** @brief [13F60] hit points of town walls*/
		INT32 fortWallsHp[18];
		/** @brief [13FA8] */
		INT32 fortWallsAlive[18];
	protected:
		h3unk8 _f_13FF0[4];
	public:
		/** @brief [13FF4] pcx of grids, name of the resource in the lod*/
		H3LoadedPcx* CCellGrdPcx;
		/** @brief [13FF8] pcx to shade in blue using cheat menu, name in lod*/
		H3LoadedPcx* CCellShdPcx;
	protected:
		/** @brief [13FFC] wog name */
		INT32 globalCardeIndex;
	public:
		/** @brief [14000] only 20 unlike stacks*/
		BOOL8 redrawCreatureFrame[2][20];
		/** @brief [14028] */
		BOOL8 heroAnimation[2];
		/** @brief [1402A] */
		BOOL8 heroFlagAnimation[2];
		/** @brief [1402C] */
		BOOL8 turretAnimation[3];
		/** @brief [14030] marked as true when a combat action is just starting*/
		BOOL8 actionUndergoing;
		/** @brief [14031] marked as true when a creature is moving*/
		BOOL8 travelingSquares[187];
	public:
		// functions
		_H3API_ VOID  SimulateMouseAtHex(INT32 hex_id);
		_H3API_ BOOL8 CanCastSpellAtCoord(INT32 spell_id, INT32 spell_expertise, INT32 coordinates);
		_H3API_ VOID  WinBattle();
		_H3API_ VOID  LoadSpell(INT32 spell_id);
		_H3API_ VOID  CastSpell(INT32 spell_id, INT32 hex_ix, INT32 cast_type_012, INT32 hex2_ix, INT32 skill_level, INT32 spell_power);
		_H3API_ INT32 SquareAtCoordinates(const H3POINT& p) const;
		_H3API_ INT32 SquareAtCoordinates(INT32 x, INT32 y) const;
		/**
		 * @brief Checks specified combat square for resurrectable unit
		 * @param coordinate Valid combat hex 0..187
		 * @param caster_kind H3Hero: 0, Creature: 1, Artifact: 2
		 * @return A pointer to a dead stack at the specified hex, nullptr if no valid target
		 */
		_H3API_ H3CombatCreature* GetResurrectionTarget(INT32 coordinate, INT32 caster_kind = 0);
		_H3API_ H3CombatCreature* GetAnimateDeadTarget(INT32 coordinate);
		_H3API_ INT32 NextCreatureToMove();
		_H3API_ BOOL8 IsHiddenBattle();
		_H3API_ BOOL8 IsBattleOver();
		/**
         * @brief Make army perform an animation.
		 * 
         * @param animationIndex which animation
         * @param resetAnimationWhenDone reset animation idx to 0 or not.
        */
        _H3API_ VOID  ApplyAnimationToLastHitArmy(INT32 animationIndex, BOOL resetAnimationWhenDone);
		_H3API_ VOID  AddNecromancyRaisedCreature(INT32 side);
		_H3API_ VOID  Refresh();
		_H3API_ VOID  Refresh(BOOL redrawScreen, INT timeDelay, BOOL redrawBackground);
		_H3API_ VOID  RefreshCreatures();
		_H3API_ VOID  ShadeSquare(INT32 index);
		_H3API_ BOOL8 IsHumanTurn();
		_H3API_ VOID  AddStatusMessage(LPCSTR message, BOOL permanent = TRUE);
		_H3API_ VOID  PlayMagicAnimation(INT32 id, H3CombatCreature* target, INT32 timeStep, BOOL8 showTargetBeingHit);
		/**
		 * @brief Make a combat log template by gentext=378 or 379 for damage, 380 or 381 for killed,
				  and some creature ability damage also use this function to generate combat log.

		 * @param attackerName just name
		 * @param numAttackers num of creature in attacker stack
		 * @param damageDone damage done
		 * @param target target army
		 * @param killedCount how many creature be killed
		*/
		_H3API_ VOID  ReportDamageDone(LPCSTR attackerName, INT32 numAttackers, INT32 damageDone, H3CombatCreature* target, INT32 killedCount);
		_H3API_ BOOL8 ShouldCastSpellAfterHit(INT32 spellId, INT32 side, H3CombatCreature* target);
		_H3API_ VOID ResurrectTarget(H3CombatCreature* target, INT32 hitPoints, INT32 isTemporary);
        /**
         * @brief Caculate the spell's damage on target
         * @param damage Basic damage
         * @param spellId Which spell
         * @param atkHero Attacker hero
         * @param defHero Defender hero
         * @param target Target creature
         * @param showLog generate combat log.
         * @return Damage has been modified
        */
        _H3API_ INT32 CalculateSpellDamageOnTarget(INT32 damage, INT32 spellId, H3Hero* atkHero, H3Hero* defHero, H3CombatCreature* target, BOOL showLog);
		_H3API_ H3CombatCreature* SummonCreature(INT32 side, INT32 creatureId, INT32 amount, INT32 position, INT32 redrawAnimation, BOOL redraw);
		_H3API_ H3CombatCreature* GetSummonDemonTarget(INT32 side, INT32 coordinate);
		_H3API_ VOID RaiseDemon(H3CombatCreature* caster, H3CombatCreature* target);
		/**
		 * @brief Checks whether after-hit creature spells can be applied to the target stack using rand(1, 100).
		 *
		 * @param spell_id id of the spell being considered
		 * @param creature_side controlling side of the creature performing the attack [hypnotized ? 1 - side : side]
		 * @param target creature that will receive the spell
		 * @return BOOL8 whether the spell can be applied to the target
		 */
		_H3API_ BOOL8 CanApplyCreatureSpell(INT32 spell_id, INT32 creature_side, H3CombatCreature* target);
		_H3API_ VOID DrawRay(BOOL redraw, INT startX, INT startY, INT dstX, INT dstY, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay);
		_H3API_ VOID DrawRay(BOOL redraw, H3CombatCreature* start, H3CombatCreature* end, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay);
		/**
		 * @brief Animates a mass spell cast on the battlefield
		 *
		 * @param animation_id the animation id of the spell (H3Spell::animationIndex)
		 * @param affects_both_sides Whether both sides are affected (Destroy Undead and Death Ripple)
		 */
		_H3API_ VOID AnimateMassSpell(INT32 animation_id, BOOL8 affects_both_sides);
		/**
		 * @brief Orders the manager to close
		 * @param msg The current thread message
		 * @return Value 2 to indicate end of loop
		 */
		_H3API_ INT32 Close(H3Msg& msg);
		/**
		 * @brief follows the logic from 0x479A5B that prevents summoning a clone
		 * if too many creatures are present
		 */
		_H3API_ BOOL CanSummonOrClone() const;
	};
	_H3API_ASSERT_SIZE_(H3CombatManager);
	_H3API_ASSERT_SIZE_(H3CombatManager::TownTowerLoaded);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
