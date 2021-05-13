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

namespace h3
{
	_H3API_DECLARE_(Creature);

#pragma pack(push, 4)

	struct H3Creature
	{
		/**
		 * @brief returns a creature's upgraded version
		 * @param id Index of the creature
		 * @return -1 if no upgrade exist
		 */
		_H3API_ static INT32 GetUpgrade(INT32 id);
		/**
		 * @brief Checks if a creature has an upgraded version
		 * @param id Index of the creature
		 * @return Whether an upgrade exists
		 */
		_H3API_ static BOOL8 HasUpgrade(INT32 id);
		/**
		 * @brief Get a description of a creature group's size based on how many there are
		 * @param amount How many creatures are present
		 * @param text_variant 0..2 | 0=> X-Y | 1=> A XYZ of | 2=> a XYZ of (same as 1 but lower-case)
		 * @return Description of group's size based on text files
		*/
		_H3API_ static LPCSTR GroupName(INT32 amount, INT32 text_variant);
	};

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)

	/** @brief Creature slots are sometimes represented with only a 16bit signed amount*/
	struct H3CreatureSlot16
	{
		_H3API_SIZE_(0x6);
		INT32 type;
		INT16 amount;
	};
	_H3API_ASSERT_SIZE_(H3CreatureSlot16);
#pragma pack(pop) /* align-1 */

} /* namespace h3 */
