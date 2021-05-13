//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapScholar.hpp"

namespace h3
{
	_H3API_ H3MapitemScholar::eType H3MapitemScholar::GetType()
	{
		return eType(type);
	}
	_H3API_ ePrimary H3MapitemScholar::GetPrimary()
	{
		return ePrimary(pSkill);
	}
	_H3API_ eSecondary H3MapitemScholar::GetSecondary()
	{
		return eSecondary(sSkill);
	}
	_H3API_ eSpell H3MapitemScholar::GetSpell()
	{
		return eSpell(spell);
	}
} /* namespace h3 */
