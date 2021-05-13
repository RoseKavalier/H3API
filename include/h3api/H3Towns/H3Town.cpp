//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Towns/H3Town.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3Towns/H3TownCreatureTypes.hpp"

namespace h3
{
	_H3API_ BOOL H3Town::IsBuildingBuilt(INT32 id) const
	{
		return THISCALL_3(BOOL, 0x4305A0, this, id, id >= 32 ? 1 : 0);
	}
	_H3API_ LPCSTR H3Town::GetTownTypeName() const
	{
		return THISCALL_1(LPCSTR, 0x5C1850, this);
	}
	_H3API_ H3Hero* H3Town::GetGarrisonHero() const
	{
		return H3Main::Get()->GetHero(garrisonHero);
	}
	_H3API_ H3Hero* H3Town::GetVisitingHero() const
	{
		return H3Main::Get()->GetHero(visitingHero);
	}
	_H3API_ BOOL8 H3Town::IsMageGuildBuilt(INT level) const
	{
		return magicGuild[level];
	}
	_H3API_ H3String H3Town::GetNameAndType() const
	{
		H3String str(this->name);
		str.Append(", ").Append(GetTownTypeName());
		return str;
	}
	_H3API_ INT32 H3Town::GoldIncome(BOOL count_silo) const
	{
		return THISCALL_2(INT32, 0x5BFA00, this, count_silo ? 1 : 0);
	}
	_H3API_ H3Resources& H3Town::GetResourceSiloIncome() const
	{
		return THISCALL_1(H3Resources&, 0x5C1680, this);
	}
	_H3API_ H3TownCreatureTypes& H3Town::GetCreatureTypes() const
	{
		return H3TownCreatureTypes::Get()[type];
	}
	_H3API_ BOOL H3Town::CanBeBuilt(eBuildings id) const
	{
		return buildableMask.bitfield->GetState(int(id));
	}
	_H3API_ H3Resources H3Town::TotalIncome() const
	{
		H3Resources total;
		total.gold = GoldIncome(TRUE);
		total += GetResourceSiloIncome();
		return total;
	}
} /* namespace h3 */
