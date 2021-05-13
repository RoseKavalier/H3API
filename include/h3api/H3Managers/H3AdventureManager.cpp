//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3AdventureManager.hpp"
#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3Assets/H3WavFile.hpp"

namespace h3
{
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem()
	{
		return THISCALL_2(H3MapItem*, 0x412B30, this, mousePosition.Mixed());
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(UINT32 mixedPos)
	{
		return THISCALL_2(H3MapItem*, 0x412B30, this, mixedPos);
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(INT32 x, INT32 y, INT32 z)
	{
		return THISCALL_4(H3MapItem*, 0x4086D0, map, x, y, z);
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(const H3Position& p)
	{
		return GetMapItem(p.Mixed());
	}
	_H3API_ H3MapItem* H3AdventureManager::GetMapItem(const H3Point& p)
	{
		return GetMapItem(p.Pack());
	}
	_H3API_ UINT8 H3AdventureManager::GetX()
	{
		return mousePosition.GetX();
	}
	_H3API_ UINT8 H3AdventureManager::GetY()
	{
		return mousePosition.GetY();
	}
	_H3API_ UINT8 H3AdventureManager::GetZ()
	{
		return mousePosition.GetZ();
	}
	_H3API_ VOID H3AdventureManager::FullUpdate()
	{
		THISCALL_3(VOID, 0x417380, this, 1, 0);
	}
	_H3API_ VOID H3AdventureManager::MobilizeHero()
	{
		THISCALL_4(VOID, 0x417540, this, 0, 0, 0);
	}
	_H3API_ VOID H3AdventureManager::DemobilizeHero()
	{
		THISCALL_3(VOID, 0x4175E0, this, 0, 0);
	}
	_H3API_ VOID H3AdventureManager::MovementCalculationsMouse()
	{
		THISCALL_2(VOID, 0x419400, this, mousePosition.Mixed());
	}
	_H3API_ VOID H3AdventureManager::MovementCalculations(UINT32 mixedPosition)
	{
		THISCALL_2(VOID, 0x419400, this, mixedPosition);
	}
	_H3API_ VOID H3AdventureManager::MakeHeroPath()
	{
		THISCALL_4(VOID, 0x418D30, this, 1, 1, 1);
	}
	_H3API_ VOID H3AdventureManager::ShowCoordinates(UINT32 x, UINT32 y, UINT8 z)
	{
		if (x < H3MapSize::Get() && y < H3MapSize::Get())
		{
			UINT edge_x = H3GameEdgeHorizontal::Get();
			UINT edge_y = H3GameEdgeVertical::Get();
			UINT dx = x - (screenPosition.GetX() - edge_x);
			UINT dy = y - (screenPosition.GetY() - edge_y);
			DemobilizeHero();
			screenPosition.SetXYZ(edge_x + x, edge_y + y, z);
			FullUpdate(); // force immediate redraw
			mousePosition.SetXYZ(mousePosition.GetX() + dx, mousePosition.GetY() + dy, z); // update cursor position
		}
	}
	_H3API_ INT H3AdventureManager::SimulateMouseOver(INT x, INT y)
	{
		return THISCALL_3(int, 0x40E2C0, this, x, y);
	}
	_H3API_ INT H3AdventureManager::SimulateMouseOver(POINT& p)
	{
		return SimulateMouseOver(p.x, p.y);
	}
	_H3API_ CHAR H3AdventureManager::UpdateHintMessage()
	{
		return THISCALL_5(CHAR, 0x40B0B0, this, GetMapItem(), GetX(), GetY(), GetZ());
	}
	_H3API_ H3Point H3AdventureManager::GetCoordinates(H3MapItem* item)
	{
		return map->GetCoordinates(item);
	}
	_H3API_ VOID H3AdventureManager::StopSound(H3WavFile* wav)
	{
		THISCALL_2(VOID, 0x59A180, this, wav->hSample);
	}
	_H3API_ H3Map<H3MapItem> H3AdventureManager::GetMap()
	{
		return map->GetMap();
	}
	_H3API_ H3FastMap<H3MapItem> H3AdventureManager::GetFastMap()
	{
		return map->GetFastMap();
	}
	_H3API_ H3Map<UINT16> H3AdventureManager::GetPathMap()
	{
		return H3Map<UINT16>(arrowPathFrames, H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
	}
	_H3API_ H3FastMap<UINT16> H3AdventureManager::GetPathFastMap()
	{
		return H3FastMap<UINT16>(arrowPathFrames, H3MapSize::Get(), H3Main::Get()->mainSetup.hasUnderground);
	}

	_H3API_ INT32 H3AdventureManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(1);
		return 2;
	}

} /* namespace h3 */
