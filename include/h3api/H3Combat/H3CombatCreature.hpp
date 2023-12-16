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
#include "h3api/H3Constants/H3CstCreatures.hpp"
#include "h3api/H3Constants/H3CstSpells.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Creatures/H3CreatureAnimation.hpp"
#include "h3api/H3Creatures/H3CreatureInformation.hpp"

namespace h3
{
	_H3API_DECLARE_(CombatCreature);
	typedef H3CombatCreature H3CombatMonster;
	struct H3LoadedDef;
	struct H3Hero;
	struct H3WavFile;

#pragma pack(push, 4)

	// * monster information on battlefield
	struct H3CombatCreature
	{
		_H3API_SIZE_(0x548);

	//protected: // these need confirmations
		/** @brief [00]*/
		BOOL8   attackedAlready;
		/** @brief [04] ??*/
		INT32   totalPlayerStacks;
		/** @brief [08] 4-visible, 8-not visible*/
		UINT32  visibility;
		h3unk32 _f_0C;
		h3unk32 _f_10;
		h3unk32 _f_14;
		h3unk32 _f_18;
		/** @brief [1C] where to shoot/move to*/
		INT32   battlefieldDestination;
		/** @brief [20] fire shield animation is being shown*/
		BOOL8   fireShieldAnimation;
		/** @brief [21] fire shield animation is being shown*/
		BOOL8   movementRelated;
		h3unk32 _f_24;
		/** @brief [28] the index of the cloned creature*/
		INT32   cloneId;
		/** @brief [2C] number of turns left for cloned creature*/
		INT32   cloneDuration;
		/** @brief [30] when true, the rectangular pcx with stack count is not drawn*/
		BOOL8   skipCountDraw;
	public:
		/** @brief [34] eCreatureType */
		INT32 type;
		/** @brief [38] position on battlefield 0..186 */
		INT32 position;
		/** @brief [3C]*/
		INT32 animation;
		/** @brief [40]*/
		INT32 animationFrame;
		/** @brief [44] 0 left, 1 right, -1 not applicable*/
		INT32 secondHexOrientation;
	protected:
		h3unk32 _f_048;
	public:
		/** @brief [4C] number of creatures that are currently alive*/
		INT32 numberAlive;
		/** @brief [50]*/
		INT32 previousNumber;
		/** @brief [54] number of creatures that can never be recovered (e.g. basic Resurrection) */
		INT32 numberForeverDead;
		/** @brief [50] number of lost hit points of top creature in stack*/
		INT32 healthLost;
		/** @brief [5C] 0..6, -1 is removed after battle */
		INT32 slotIndex;
		/** @brief [60] number of creatures in this stack to compare against resurrection*/
		INT32 numberAtStart;
	protected:
		h3unk32 _f_064[2]; // maybe align?
	public:
		/** @brief [6C] maximum hit points*/
		INT32 baseHP;
		/** @brief [70]*/
		INT32 isLucky;
		/** @brief [74] copy of H3CreatureInformation using combat values in some places*/
		H3CreatureInformation info;
	protected: // these need confirmations
		/** @brief [E8] stack needs to be hit by fire shield*/
		BOOL8 applyFireShield;
		/** @brief [E9] ?at least one creature has died?*/
		BOOL8 hasLosses;
		/** @brief [EA] ?at least one creature has died?*/
		BOOL8 hasLosses2;
		/** @brief [EB] all creatures have died*/
		BOOL8 isDead;
	public:
		/** @brief [EC] set in After-Hit spell subroutine 0x440220*/
		INT32 spellToApply;
	protected:
	/** @brief [F0] ?before getting attacked? */
		h3unk8 _f_0F0[4];
	public:
		/** @brief [F4] the real owner of the creature, 0.attacker 1.defender */
		INT32 side;
		/** @brief [F8] reference to position on side*/
		INT32 sideIndex;
	protected:
	/** @brief [FC]*/
		UINT32 lastAnimationTime;
		/** @brief [100]*/
		INT32 yOffset;
		/** @brief [104]*/
		INT32 xOffset;
		/** @brief [108]*/
		h3unk8 _f_108[8];
		/** @brief [110]*/
		H3MonsterAnimation cranim;
	public:
		/** @brief [164]*/
		H3LoadedDef* def;
	protected:
		/** @brief [168]*/
		H3LoadedDef* shootingDef;
		h3unk8 _f_16C[4];
		/** @brief [170]*/
		H3WavFile* moveSound;
		/** @brief [174]*/
		H3WavFile* attackSound;
		/** @brief [178]*/
		H3WavFile* getHitSound;
		/** @brief [17C]*/
		H3WavFile* shotSound;
		/** @brief [180]*/
		H3WavFile* deathSound;
		/** @brief [184]*/
		H3WavFile* defendSound;
		/** @brief [188]*/
		H3WavFile* extraSound1;
		/** @brief [18C]*/
		H3WavFile* extraSound2;
		h3unk8 _f_190[4];
	public:
		/** @brief [194] number of spells currently active*/
		INT32 activeSpellNumber;
		/** @brief [198] remaining number of turns of any spells*/
		INT32 activeSpellDuration[81];
		/** @brief [2DC] secondary skill level of applied spells*/
		INT32 activeSpellLevel[81];
	protected:
		H3Vector<h3unk> _f_420; // size 0x400, spell related... may not be vector
		h3unk8 _f_430[36];
	public:
		/** @brief [454] number of retaliations left*/
		INT32 retaliations;
		/** @brief [458]*/
		INT32 blessDamage;
		/** @brief [0x45C]*/
		INT32 curseDamage;
		/** @brief [0x460]*/
		INT32 antiMagic;
		/** @brief [0x464]*/
		INT32 bloodlustEffect;
		/** @brief [0x468]*/
		INT32 precisionEffect;
		/** @brief [0x46C]*/
		INT32 weaknessEffect;
		/** @brief [0x470]*/
		INT32 stoneSkinEffect;
	protected:
		INT32 _f_474;
	public:
		/** @brief [0x478]*/
		INT32 prayerEffect;
		/** @brief [0x47C]*/
		INT32 mirthEffect;
		/** @brief [0x480]*/
		INT32 sorrowEffect;
		/** @brief [0x484]*/
		INT32 fortuneEffect;
		/** @brief [0x488]*/
		INT32 misfortuneEffect;
		/** @brief [0x48C] called KING_1/2/3*/
		INT32 slayerType;
		/** @brief [490] for jousting bonus*/
		INT32 hexesTraveled;
		/** @brief [0x494] number of strikes added through spell*/
		INT32 counterstrikeEffect;
		/** @brief [0x498]*/
		FLOAT frenzyMultiplier;
		/** @brief [0x49C] for calculating damage retaliation damage*/
		FLOAT blindEffect;
		/** @brief [0x4A0]*/
		FLOAT fireShieldEffect;
	protected:
		h3unk32 _f_4A4;
	public:
		/** @brief [0x4A8] in %*/
		FLOAT protectionAirEffect;
		/** @brief [0x4AC] in %*/
		FLOAT protectionFireEffect;
		/** @brief [0x4B0] in %*/
		FLOAT protectionWaterEffect;
		/** @brief [0x4B4] in %*/
		FLOAT protectionEarthEffect;
		/** @brief [0x4B8] in %*/
		FLOAT shieldEffect;
		/** @brief [0x4BC] in %*/
		FLOAT airShieldEffect;
		/** @brief [0x4C0]*/
		BOOL8 blinded;
		/** @brief [0x4C1]*/
		BOOL8 paralyzed;
		/** @brief [0x4C4]*/
		INT32 forgetfulnessLevel;
		/** @brief [0x4C8]*/
		FLOAT slowEffect;
		/** @brief [0x4C4] value added/removed*/
		INT32 hasteEffect;
		/** @brief [0x4D0]*/
		INT32 diseaseAttackEffect;
		/** @brief [0x4D4]*/
		INT32 diseaseDefenseEffect;
	protected:
		h3unk32 _f_4D8[2];
	public:
		/** @brief [0x4E0]*/
		INT32 faerieDragonSpell;
		/** @brief [0x4E4] not a float!*/
		INT32 magicMirrorEffect;
		/** @brief [0x4E8]*/
		INT32 morale;
		/** @brief [0x4EC]*/
		INT32 luck;
		/** @brief [0x4F0]*/
		BOOL8 isDone;
		/** @brief [0x4F1]*/
		BOOL8 highlightContour;
		/** @brief [0x4F4] which dendroids have binded the current target (used for animation requirement)*/
		H3Vector<H3CombatCreature*> dendroidBinder;
		/** @brief [0x504] list of H3CombatCreature binded by this dendroid*/
		H3Vector<H3CombatCreature*> dendroidBinds;
	protected:
		/** @brief [0x514] possibly tied to hypnotize as well?*/
		H3Vector<H3CombatCreature*> _f_514;
		/** @brief [0x524]*/
		H3Vector<H3CombatCreature*> hypnotized;
		h3unk8 _f_534[20];
	public:
		// * returns appropriate name of stack
		_H3API_ LPCSTR GetCreatureName() const;
		// * returns second square if creature occupies 2 squares
		_H3API_ INT32 GetSecondSquare() const;
		// * returns actual speed of creature
		_H3API_ INT32 GetStackSpeed() const;
		/**
		 * @brief Seeks hex id location considering relative orientation for a given position. Battle side is taken into consideration.
		 * @param considered_hex hex location to inspect
		 * @param relative_orientation The neighbor hex orientation, 0~7 see H3AdjacentSquares::eRelativeOrientation
		 * @return hex at relative position, -1 if invalid
		 */
		_H3API_ INT32 HexRelativePosition(INT32 considered_hex, INT32 relative_orientation) const;
		/** @brief Checks if any of the non-fatal conditions disabling a creature's turn are active*/
		_H3API_ BOOL IsIncapacitated() const;
		_H3API_ BOOL IsDefending() const;
		_H3API_ BOOL IsDone() const;
		_H3API_ BOOL IsClone() const;
		_H3API_ BOOL IsSiege() const;
		_H3API_ BOOL IsSummon() const;
		_H3API_ BOOL HadMorale() const;
		_H3API_ BOOL IsWaiting() const;
		_H3API_ BOOL HasMoved() const;
		// * index 0 ~ 41
		_H3API_ INT32 Index() const;
		// * show creature information dialog
		_H3API_ VOID ShowStatsDialog(BOOL RightClick) const;
		// * Checks if hypnotized
		_H3API_ INT32 GetSide() const;
		// * Checks if hypnotized
		_H3API_ H3Hero* GetOwner() const;
		// * the bonus/decreased effect on a spell from targeting a creature
		_H3API_ INT32 GetProtectiveSpellEffect(INT32 damage, INT32 spellID) const;
		// * odds of magic resisting
		_H3API_ INT32 MagicMirrorEffect() const;
        /**
         * @brief Apply physical damage to target, this damage would not be reduce by creature basic stats.
		 * 
         * @param amount of damage
         * @return how many creatures killed by this damage.
         */
		_H3API_ INT32 ApplyPhysicalDamage(INT32 amount);
		_H3API_ VOID  ApplySpell(INT32 spellId, INT32 spellPower, INT32 schoolLevel, H3Hero* hero);
        /**
         * @brief For those creature who cast spell after hit, this function only set h3::H3CombatCreature->spellToApply
		          so spell will be executed later not right now
		 * 
         * @param defender target army
         * @return if true, it will suspend target army action after success cast.
        */
        _H3API_ BOOL8 ApplyAfterHitSpell(H3CombatCreature* defender);
        /**
         * @brief For those creature: VAMPIRE_LORD, THUNDERBIRD, MIGHTY_GORGON, SERPENT_FLY, DRAGON_FLY and RUST_DRAGON, after hit target
		 *        effect will be executed right now.
		 * 
         * @param defender target army
         * @param damage physical damage done
         * @param killed how many creature killed by physical damage
         * @param totalDefenderLifeRemain defender army total hp
         * @return 
        */
        _H3API_ VOID  ApplyAfterHitAbility(H3CombatCreature* defender, INT32 damage, INT32 killed, INT32 totalDefenderHp);
		_H3API_ BOOL8 CanReceiveSpell(INT32 spellId) const;
		_H3API_ BOOL  CanCastSpellAtEmptyHex(INT32 hexId) const;
		_H3API_ BOOL8 MoveToHex(INT32 hexId);
		_H3API_ BOOL8 UseEnchanters();
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
		_H3API_ INT32 CurrentHitPoints() const;
		_H3API_ INT32 MaxHitPoints() const;
	};
	_H3API_ASSERT_SIZE_(H3CombatCreature);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
