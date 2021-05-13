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
#include "h3api/H3Constants/H3CstSkills.hpp"

namespace h3
{
	_H3API_DECLARE_(PrimarySkills);

#pragma pack(push, 4)

	struct H3PrimarySkills
	{
		union
		{
			struct
			{
				INT8 attack;
				INT8 defense;
				INT8 spellPower;
				INT8 knowledge;
			};
			INT8 priSkills[4];
		};

		_H3API_ PINT8 begin();
		_H3API_ PINT8 end();
		_H3API_ INT8& Get(ePrimary skill);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
