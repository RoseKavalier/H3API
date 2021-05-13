//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgMap.hpp"
#include "h3api/H3RMG/H3RmgMapItem.hpp"

namespace h3
{
    _H3API_ H3RmgMapItem* H3RmgMap::GetMapItem(INT x, INT y, INT z)
    {
        return THISCALL_4(H3RmgMapItem*, 0x537DD0, this, x, y, z);
    }
    _H3API_ H3RmgMapItem* H3RmgMap::begin()
    {
        return mapItems;
    }
    _H3API_ H3RmgMapItem* H3RmgMap::end()
    {
        return &mapItems[mapHeight * mapWidth * numberLevels];
    }
    _H3API_ H3Point H3RmgMap::GetCoordinates(H3RmgMapItem* item)
    {
        return ReverseCoordinates<H3RmgMapItem>(item, mapItems, mapWidth);
    }
    _H3API_ H3Map<H3RmgMapItem> H3RmgMap::GetMap()
    {
        return H3Map<H3RmgMapItem>(mapItems, static_cast<UINT>(mapWidth), numberLevels - 1);
    }
    _H3API_ H3FastMap<H3RmgMapItem> H3RmgMap::GetFastMap()
    {
        return H3FastMap<H3RmgMapItem>(mapItems, static_cast<UINT>(mapWidth), numberLevels - 1);
    }
} /* namespace h3 */
