//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Assets/H3Pixels.hpp"

namespace h3
{
	_H3API_DECLARE_(Palette32);

#pragma pack(push, 4)

	/** @brief a 256 argb palette of colors for indexed images, introduced by HDmod*/
	struct H3Palette32
	{
		H3ARGB888 colors[256];

		_H3API_ H3ARGB888& operator[](UINT index);
		_H3API_ H3ARGB888  operator[](UINT index) const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
