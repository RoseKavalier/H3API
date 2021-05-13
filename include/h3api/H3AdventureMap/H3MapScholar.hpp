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
#include "h3api/H3Constants/H3CstSpells.hpp"
#include "h3api/H3Constants/H3CstSkills.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemScholar);

#pragma pack(push, 4)

	/** @brief data for scholar on adventure map*/
	struct H3MapitemScholar
	{
		enum eType
		{
			PRIMARY_SKILL,
			SECONDARY_SKILL,
			SPELL,
		};

		/** @brief [00] 0 Primary, 1 Secondary, 2 Spell*/
		unsigned  type   : 3;
		/** @brief [03] 0..3 primary skill id*/
		unsigned  pSkill : 3;
		/** @brief [06] 0..27 secondary skill id*/
		unsigned  sSkill : 7;
		/** @brief [13] 0..69 spell id*/
		unsigned  spell  : 10;
		unsigned _u1     : 9;

		_H3API_ eType      GetType();
		_H3API_ ePrimary   GetPrimary();
		_H3API_ eSecondary GetSecondary();
		_H3API_ eSpell     GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
