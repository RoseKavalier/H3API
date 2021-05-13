//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Palette32.hpp"

namespace h3
{
	_H3API_ H3ARGB888& H3Palette32::operator[](UINT index)
	{
		return colors[index];
	}
	_H3API_ H3ARGB888 H3Palette32::operator[](UINT index) const
	{
		return colors[index];
	}
} /* namespace h3 */
