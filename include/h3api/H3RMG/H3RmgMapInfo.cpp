//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgMapInfo.hpp"
#include "h3api/H3RMG/H3RmgMapItem.hpp"
#include "h3api/H3RMG/H3RmgRandomMapGenerator.hpp"

namespace h3
{
    _H3API_ H3RmgMapInfo::H3RmgMapInfo(H3RmgRandomMapGenerator* main, BOOL underground) :
		vTable((h3func*)0x6409DC),
		hasMap(0),
		undergroundMap(nullptr),
		width(main->map.mapWidth),
		height(main->map.mapHeight),
		underground(underground)
	{
		undergroundMap = &main->map.mapItems[width * height];
	}
	_H3API_ H3RmgMapInfo::~H3RmgMapInfo()
	{
	}
} /* namespace h3 */
