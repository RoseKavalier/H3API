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
#include "h3api/H3Constants/H3CstPlayers.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemShipyard);

#pragma pack(push, 4)

	/** @brief data for shipyard on adventure map*/
	struct H3MapitemShipyard
	{
		/** @brief [00] current owner 0..8 */
		unsigned  owner : 8;
		/** @brief [08]*/
		unsigned  x : 8;
		/** @brief [16]*/
		unsigned  y : 8;
		/** @brief [24]*/
		unsigned _u3 : 8;

		_H3API_ ePlayer GetOwner();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
