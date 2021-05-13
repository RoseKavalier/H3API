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

namespace h3
{
	_H3API_DECLARE_(MapitemFountainFortune);

#pragma pack(push, 4)

	/** @brief data for Fountain of Fortune on adventure map*/
	struct H3MapitemFountainFortune
	{
		/** @brief [00]*/
		unsigned _u1       : 5;
		/** @brief [05] which players have come by*/
		unsigned visited   : 8;
		/** @brief [13] -1..3 luck bonus */
		  signed bonusLuck : 4;
		  /** @brief [17]*/
		unsigned _u2       : 15;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
