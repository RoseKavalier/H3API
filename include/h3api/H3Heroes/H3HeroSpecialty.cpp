//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Heroes/H3HeroSpecialty.hpp"

namespace h3
{
	_H3API_ BOOL H3HeroSpecialty::HasSpellSpec() const
	{
		return type == eHeroSpecialty::SPEED;
	}
	_H3API_ eSpell H3HeroSpecialty::GetSpell() const
	{
		return eSpell(bonusId);
	}

} /* namespace h3 */
