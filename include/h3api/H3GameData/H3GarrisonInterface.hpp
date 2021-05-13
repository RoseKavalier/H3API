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

namespace h3
{
	_H3API_DECLARE_(GarrisonInterface);
	// previously called CreatureExchange, garrison interface is more explicit
	typedef H3GarrisonInterface H3CreatureExchange;
	struct H3Army;
	struct H3Hero;
	struct H3BaseDlg;

#pragma pack(push, 4)

	/** @brief Used both in town and in adv map garrisons*/
	struct H3GarrisonInterface
	{
		_H3API_SIZE_(0x78);
		_H3API_CTOR_DTOR_(0x5AA030, -1);

	protected:
		h3unk8 _f_00[28]; // unused afaict
	public:
		/** @brief [1C]*/
		INT32 x;
		/** @brief [20]*/
		INT32 y;
		/** @brief [24]*/
		BOOL32 isBottom;
		/** @brief [28] player color*/
		INT32 ownerId;
		/** @brief [2C] 0..6, -2 if none*/
		INT32 selectedSlotIndex;
	protected:
		h3unk8 _f_30[52];
	public:
		/** @brief [64]*/
		INT32 id;
		/** @brief [68] parent dialog*/
		H3BaseDlg* dlg;
		/** @brief [6C]*/
		H3Army* army;
		/** @brief [70]*/
		INT32 heroPictureIndex;
		/** @brief [74]*/
		H3Hero* hero;

		_H3API_ VOID DrawHero(INT32 hero_picture);
		/**
		 * @brief Draw a creature portrait to the specified slot
		 * @param index 0..6 which creature slot to draw to
		 * @param creature_portrait_index The index of TwCrPort.def, which is creature id + 2
		 */
		_H3API_ VOID DrawCreature(INT32 index, INT32 creature_portrait_index);
		_H3API_ VOID Redraw(INT32 selected_slot = -1);
	};
	_H3API_ASSERT_SIZE_(H3GarrisonInterface);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
