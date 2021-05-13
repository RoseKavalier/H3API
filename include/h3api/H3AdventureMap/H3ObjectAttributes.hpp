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
#include "h3api/H3Constants/H3CstObjects.hpp"

namespace h3
{
	_H3API_DECLARE_(ObjectAttributes);

#pragma pack(push, 4)

	/*
	 * Modeled after H3M_OA_ENTRY in h3m format
	 * https://github.com/potmdehex/homm3tools/blob/master/h3m/h3mlib/h3m_structures/object_attributes/h3m_oa.h#L20
	 * https://github.com/potmdehex/homm3tools/blob/master/h3m/h3mlib/h3m_structures/object_attributes/h3m_oa_body.h#L13
	 * https://github.com/ethernidee/era-editor/blob/master/Patch/Common.pas#L39 from mapeditor format
	 */
	struct H3ObjectAttributes
	{
		_H3API_SIZE_(0x44);

		/** @brief [0] name of the DEF*/
		H3String defName;
		/** @brief [10] width of object, read from LoD @ 0x503ED5*/
		UINT8 width;
		/** @brief [11] height of object, read from LoD @ 0x503EE2*/
		UINT8 height;
		/** @brief [14] object's presence, color-wise*/
		H3ObjectMask colors;
		/** @brief [1C] object's passability*/
		H3ObjectMask passability;
		/** @brief [24] object's shadow*/
		H3ObjectMask shadows;
		/** @brief [2C] object's yellow entrance tiles*/
		H3ObjectMask entrances;
		/** @brief [34] valid terrains for this object*/
		H3TerrainBitfield maskTerrain;
		/** @brief [38] type of object, 0..232*/
		INT32 type;
		/** @brief [3C] subtype of object, depends on type*/
		INT32 subtype;
		/** @brief [40] is the object flat on the adventure map? e.g. cursed ground*/
		BOOL8 flat;
		/** @brief [42] referenced a few places, e.g. 0x50663A*/
		UINT16 defIndex;
	};
	_H3API_ASSERT_SIZE_(H3ObjectAttributes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
