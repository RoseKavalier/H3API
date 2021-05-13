//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Skills/H3PrimarySkills.hpp"

namespace h3
{
	_H3API_ INT8& H3PrimarySkills::Get(ePrimary skill)
	{
		return priSkills[static_cast<INT>(skill)];
	}
	_H3API_ PINT8 H3PrimarySkills::begin()
	{
		return &priSkills[0];
	}
	_H3API_ PINT8 H3PrimarySkills::end()
	{
		return &priSkills[4];
	}
} /* namespace h3 */
