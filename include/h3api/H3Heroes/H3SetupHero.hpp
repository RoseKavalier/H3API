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
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Bitset.hpp"
#include "h3api/H3Artifacts/H3Artifact.hpp"

namespace h3
{
	_H3API_DECLARE_(SetupHero);

#pragma pack(push, 1)
	/** @brief Intermediary between h3m/save format and H3Hero*/
	struct H3SetupHero
	{
		_H3API_SIZE_(0x334);
		INT8	   owner;                    // +0
	protected:
		h3align    _f_01[3];
	public:
		UINT32     number;                   // +4
		UINT32     id;                       // +8
		BOOL8      hasCustomName;            // +C
		CHAR       name[13];                 // +D
		BOOL8      hasCustomExperience;      // +1A
	protected:
		h3align    _f_1B;
	public:
		INT32      experience;               // +1C
		UINT8      hasCustomPicture;         // +20
		UINT8      pictureId;                // +21
		BOOL8      hasCustomSecondarySkills; // +22
	protected:
		h3align    _f_23;
	public:
		UINT32     numberSecondarySkills;    // +24
		UINT8      secondarySkills[8];       // +28
		UINT8      secondarySkillsLevels[8]; // +30
		BOOL8      hasCustomCreatures;       // +38
	protected:
		h3align    _f_39[3];
	public:
		INT32      creatureType[7];          // +3C
		INT16      creatureNumber[7];        // +58
		BOOL8      groupedFormation;         // +66 spread/grouped
		BOOL8      hasCustomArtifacts;       // +67
		H3Artifact bodyArt[19];              // +68
		H3Artifact backpackArt[64];          // +100
		UINT8      backpackCount;            // +300
		UINT16     x;                        // +301
		UINT16     y;                        // +303
		UINT8      radius;                   // +305
		BOOL8      hasCustomBiography;       // +306
	protected:
		UINT8      _f_307;
	public:
		H3String   biography;
		BOOL8      isFemale;                 // +318
	protected:
		h3align    _f_319[3];
	public:
		BOOL8      hasCustomSpells;          // +31C
	protected:
		h3align    _f_31D[3];
	public:
		H3SpellsBitset spells;               // +320
		BOOL8      hasCustomPrimarySkills;   // +32C
		INT8       pSkill[4];                // +32D
	protected:
		h3unk8     _f_331[3];
	public:
	};
	_H3API_ASSERT_SIZE_(H3SetupHero);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */
