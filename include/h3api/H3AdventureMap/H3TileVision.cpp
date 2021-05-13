//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3TileVision.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"

namespace h3
{
    _H3API_ H3TileVision& H3TileVision::GetTile(INT32 x, INT32 y, INT32 z)
    {
        return FASTCALL_3(H3TileVision&, 0x4F8070, x, y, z);
    }

    _H3API_ H3TileVision& H3TileVision::GetTile(const H3Point& p)
    {
        return GetTile(p.x, p.y, p.z);
    }

    _H3API_ H3TileVision& H3TileVision::GetTile(const H3Position& p)
    {
        return GetTile(p.Unpack());
    }

    _H3API_ BOOL H3TileVision::CanViewTile(INT32 x, INT32 y, INT32 z, INT32 player /*= -1*/)
    {
        if (player < 0)
            player = H3CurrentPlayerID::Get();
        return GetTile(x, y, z).vision.bits & (1 << player);
    }

    _H3API_ BOOL H3TileVision::CanViewTile(const H3Point& p, INT32 player /*= -1*/)
    {
        return CanViewTile(p.x, p.y, p.z, player);
    }

    _H3API_ BOOL H3TileVision::CanViewTile(const H3Position& p, INT32 player /*= -1*/)
    {
        return CanViewTile(p.Unpack(), player);
    }

    _H3API_ VOID H3TileVision::RevealTile(INT32 x, INT32 y, INT32 z, INT32 player /*= -1*/)
    {
        if (player < 0)
            player = H3CurrentPlayerID::Get();
        GetTile(x, y, z).vision.bits |= (1 << player);
    }

    _H3API_ VOID H3TileVision::RevealTile(const H3Point& p, INT32 player /*= -1*/)
    {
        RevealTile(p.x, p.y, p.z, player);
    }

    _H3API_ VOID H3TileVision::RevealTile(const H3Position& p, INT32 player /*= -1*/)
    {
        RevealTile(p.Unpack(), player);
    }

    _H3API_ H3Map<H3TileVision> H3TileVision::GetMap()
    {
        return H3Map<H3TileVision>(Get(), H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
    }

    _H3API_ H3FastMap<H3TileVision> H3TileVision::GetFastMap()
    {
        return H3FastMap<H3TileVision>(Get(), H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
    }
} /* namespace h3 */
