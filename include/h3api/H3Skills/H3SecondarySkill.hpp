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
	_H3API_DECLARE_(SecondarySkill);

#pragma pack(push, 4)

		// * secondary skills of a hero
	struct H3SecondarySkill
	{

		/** @brief [00] 0..27 eSecSkills*/
		eSecondary     type;
		/** @brief [04] 0..3 eSecSkillLevel*/
		eSecSkillLevel level;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
