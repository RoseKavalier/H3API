//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ UINT32 H3Main::Date::CurrentDay() const
	{
		return 28 * (month - 1) + 7 * (week - 1) + day - 1;
	}

	_H3API_ BOOL H3Main::HasUnderground() const
	{
		return mainSetup.hasUnderground;
	}
	_H3API_	H3MapItem* H3Main::GetMapItem(UINT32 mixedPosition)
	{
		return THISCALL_2(H3MapItem*, 0x42ED80, this, mixedPosition);
	}
	_H3API_ H3Player* H3Main::GetPlayer()
	{
		return THISCALL_1(H3Player*, 0x4CE670, this);
	}
	_H3API_ INT32 H3Main::GetPlayerID()
	{
		return THISCALL_1(INT32, 0x4CE6E0, this);
	}
	_H3API_ H3Hero* H3Main::GetHero(INT32 id)
	{
		return THISCALL_2(H3Hero*, 0x4317D0, this, id);
	}
	_H3API_ VOID H3Main::ResetRandomArtifacts()
	{
		libc::memset(randomArtifacts, 0, sizeof(randomArtifacts));
	}
	_H3API_ INT32 H3Main::GetRandomArtifactOfLevel(INT32 level)
	{
		return THISCALL_2(INT32, 0x4C9190, this, level);
	}
	_H3API_ VOID H3Main::SaveGame(LPCSTR save_name)
	{
		THISCALL_6(VOID, 0x4BEB60, this, save_name, 1, 1, 1, 0);
	}
	_H3API_ VOID H3Main::PlaceObjectOnMap(INT32 x, INT32 y, INT32 z, INT32 type, INT32 subtype, INT32 setup)
	{
		{ THISCALL_7(VOID, 0x4C9550, this, x, y, z, type, subtype, setup); }
	}
	_H3API_ VOID H3Main::RefreshMapItemAppearrance(H3MapItem* mi)
	{
		{ THISCALL_2(VOID, 0x4C9650, this, mi); }
	}
	_H3API_ H3Point H3Main::GetCoordinates(H3MapItem* item)
	{
		return mainSetup.GetCoordinates(item);
	}
	_H3API_ BOOL8 H3Main::IsHuman(INT32 player_id)
	{
		return THISCALL_2(BOOL8, 0x4CE600, this, player_id);
	}
	_H3API_ VOID H3Main::UpdateMapItemAppearance(H3MapItem* item)
	{
		THISCALL_2(VOID, 0x4C9650, this, item);
	}
	_H3API_ H3Map<H3MapItem> H3Main::GetMap()
	{
		return mainSetup.GetMap();
	}
	_H3API_ H3FastMap<H3MapItem> H3Main::GetFastMap()
	{
		return mainSetup.GetFastMap();
	}
} /* namespace h3 */
