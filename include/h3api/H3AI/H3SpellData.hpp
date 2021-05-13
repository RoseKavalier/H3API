//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(SpellData);
	typedef H3SpellData H3AiSpellData;

#pragma pack(push, 4)

	struct H3SpellData
	{
		_H3API_SIZE_(0x24);

		INT32 spellId;
		INT32 expertise;
		INT32 _f_08;
		INT32 _f_0C;
		INT32 _f_10;
		INT32 actionParameter;
		INT32 _f_18;
		INT32 spellValue;
		INT32 _f_20;
	};
	_H3API_ASSERT_SIZE_(H3SpellData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
