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
	_H3API_DECLARE_(SpellbookText);

#pragma pack(push, 4)

	struct H3SpellbookText
	{
		_H3API_GET_INFO_(0x59DBB0 + 3, H3SpellbookText);
		struct TextPair
		{
			LPCSTR text;
			LPCSTR description;
		};

		TextPair previousPage;
		TextPair nextPage;
		TextPair adventureMapSpells;
		TextPair combatSpells;
		TextPair schoolSpells[5]; // air, fire, water, earth, all
		TextPair spellPoints;
		TextPair closeSpellbook;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
