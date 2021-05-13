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
	_H3API_DECLARE_(TileVision);

#pragma pack(push, 4)

	/** @brief information about visibility and wandering monster zone control of map tiles*/
	struct H3TileVision
	{
		_H3API_SIZE_(0x2);
		_H3API_GET_INFO_(0x698A48, H3TileVision);

		H3PlayersBitfield vision; // bitfield of players
		BOOL8 zoneControl; // does not exist in Demo

		_H3API_ static H3TileVision& GetTile(INT32 x, INT32 y, INT32 z);
		_H3API_ static H3TileVision& GetTile(const H3Point& p);
		_H3API_ static H3TileVision& GetTile(const H3Position& p);
		_H3API_ static BOOL CanViewTile(INT32 x, INT32 y, INT32 z, INT32 player = -1);
		_H3API_ static BOOL CanViewTile(const H3Point& p, INT32 player = -1);
		_H3API_ static BOOL CanViewTile(const H3Position& p, INT32 player = -1);
		_H3API_ static VOID RevealTile(INT32 x, INT32 y, INT32 z, INT32 player = -1);
		_H3API_ static VOID RevealTile(const H3Point& p, INT32 player = -1);
		_H3API_ static VOID RevealTile(const H3Position& p, INT32 player = -1);
		_H3API_ static H3Map<H3TileVision>     GetMap();
		_H3API_ static H3FastMap<H3TileVision> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3TileVision);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
