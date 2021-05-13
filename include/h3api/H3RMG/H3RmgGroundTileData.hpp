//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgGroundTileData
	{
		_H3API_SIZE_(4);
		unsigned  roadSprite    : 7;
		unsigned _b8            : 5;	//
		unsigned  orientation   : 3;	// bit 13 [0x0000 1000] ~ monster position 0~7, see 0x5437E2 & 0x54E117
		unsigned  mirrorLandV   : 1;	// bit 16 [0x0000 8000]
		unsigned  mirrorLandH   : 1;	// bit 17 [0x0001 0000]
		unsigned  mirrorRiverV  : 1;	// bit 18 [0x0002 0000]
		unsigned  mirrorRiverH  : 1;	// bit 19 [0x0004 0000]
		unsigned  mirrorRoadV   : 1;	// bit 20 [0x0008 0000]
		unsigned  mirrorRoadH   : 1;	// bit 21 [0x0010 0000]
		unsigned  shore         : 1;	// bit 22 [0x0020 0000]~ unsure, written to h3m at 0x532E42
		unsigned  hasObject     : 1;	// bit 23 [0x0040 0000] ~ see 0x547EB8
		unsigned _b24           : 1;	// bit 24 [0x0080 0000]
		unsigned _b25           : 1;	// bit 25 [0x0100 0000]
		unsigned  mustBeBlocked : 1;	// bit 26 [0x0200 0000] checks if not rock after 0x537F10
		unsigned  isEntrance    : 1;	// bit 27 [0x0400 0000] set when yellow entrance tile
		unsigned  isBlocked     : 1;    // bit 28 [0x0800 0000] ~ if this is not set, roads are allowed to go everywhere!
		unsigned _b29           : 1;	// bit 29 [0x1000 0000] ~ water related ?
		unsigned _b30           : 1;	// bit 30 [0x2000 0000]
		unsigned _b31           : 1;	// bit 31 [0x4000 0000]
		unsigned _b32           : 1;	// bit 32 [0x8000 0000]
	};
	_H3API_ASSERT_SIZE_(H3RmgGroundTileData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
