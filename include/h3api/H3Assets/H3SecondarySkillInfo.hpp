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
	_H3API_DECLARE_(SecondarySkillText);
	_H3API_TYPE_DECLARE_(H3SecondarySkillText, SecondarySkillInfo);

#pragma pack(push, 4)

	struct H3SecondarySkillText
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x67DCF0, H3SecondarySkillText);

		LPCSTR name;
		LPCSTR description[3];
	};
	_H3API_ASSERT_SIZE_(H3SecondarySkillText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
