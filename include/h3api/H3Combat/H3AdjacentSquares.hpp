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
#include "h3api/H3Constants/H3CstCombat.hpp"

namespace h3
{
	_H3API_DECLARE_(AdjacentSquares);

#pragma pack(push, 4)

	/** @brief index of adjacent squares, -1 if outside battlefield boundaries*/
	struct H3AdjacentSquares
	{
		_H3API_SIZE_(0xC);

		INT16 topRight;
		INT16 right;
		INT16 bottomRight;
		INT16 bottomLeft;
		INT16 left;
		INT16 topLeft;
	};
	_H3API_ASSERT_SIZE_(H3AdjacentSquares);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
