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

#pragma pack(push, 4)

	struct H3PuzzleCoordinates
	{
		_H3API_GET_INFO_(0x52CC09 + 3, H3PuzzleCoordinates);
		INT16 x[48];
		INT16 y[48];
	};

	struct H3PuzzlePiecesOrder
	{
		_H3API_GET_INFO_(0x52CBF2 + 4, H3PuzzlePiecesOrder);
		INT16 order[48];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
