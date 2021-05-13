//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"

namespace h3
{
	_H3API_DECLARE_(RecruitMgr);
	struct H3Army;
	struct H3Hero;
	struct H3CreatureSlot16;
	struct H3Generator;

#pragma pack(push, 4)

	struct H3RecruitMgr : H3Manager
	{
		_H3API_SIZE_(0xBC);
		_H3API_VTABLE_(0x640C80);
		/* only used when in town */
		_H3API_GET_INFO_(0x6AAABC, H3RecruitMgr);

		h3unk8 _f_38[16];
		/** @brief [48] dwelling, town... */
		INT32 objectType;
		/** @brief [4C]*/
		BOOL8 teamDwelling;
		/** @brief [50]*/
		INT32 selectedType;
		/** @brief [54] amount currently set for selected type*/
		INT32 selectedAmount;
		h3unk32 selectedCreatureIndex;
		/** @brief [5C]*/
		INT32  types[4];
		/** @brief [6C]*/
		INT16* amounts[4];
		/** @brief [7C]*/
		H3Hero* hero;
		h3unk8 _f_80[4];
		/** @brief [84]*/
		INT32 goldCost;
		/** @brief [88]*/
		INT32 specialResourceIndex;
		/** @brief [8C]*/
		INT32 specialResourceCost;
		/** @brief [90]*/
		h3unk32 dword90;
		h3unk8 _f_94[4];
		/** @brief [98]*/
		H3Army* army;
		/** @brief [9C]*/
		BOOL8 summoningPortal;
		h3unk32 _f_A0;
		h3unk32 _f_A4;
		h3unk32 _f_A8;
		/** @brief [AC] for the selected type*/
		h3unk32 amountAvailable;
		/** @brief [B0]*/
		h3unk32 totalGoldCost;
		/** @brief [B4]*/
		h3unk32 totalResourceCost;
		/** @brief [B8]*/
		h3unk32 amountToBuy;

		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1, INT32 type2, INT16& amount2);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2, INT32 type3, INT16& amount3);
		_H3API_ H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, H3CreatureSlot16& slot0,
			H3CreatureSlot16& slot1, H3CreatureSlot16& slot2, H3CreatureSlot16& slot3);
		_H3API_ H3RecruitMgr(H3Army& army, H3Generator& generator);
		/* Used for war machines */
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type, INT16& amount);
		/* Used for war machines */
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1);
		/* Used for war machines */
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2);
		/* Used for war machines */
		_H3API_ H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
			INT32 type2, INT16& amount2, INT32 type3, INT16& amount3);
		_H3API_ VOID Run();
	protected:
		_H3API_ H3RecruitMgr& initialize(H3Army& army, BOOL8 is_summoning_portal,
			INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
			INT32 type2, INT16* amount2, INT32 type3, INT16* amount3);
		_H3API_ H3RecruitMgr& initialize(H3Hero* hero, INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
			INT32 type2, INT16* amount2, INT32 type3, INT16* amount3);
	};
	_H3API_ASSERT_SIZE_(H3RecruitMgr);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
