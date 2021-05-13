//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Players/H3Player.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3Hero* H3Player::GetActiveHero()
	{
		return H3Main::Get()->GetHero(currentHero);
	}
} /* namespace h3 */
