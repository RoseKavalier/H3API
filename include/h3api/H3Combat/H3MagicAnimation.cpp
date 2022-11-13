//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Combat/H3MagicAnimation.hpp"
#include "h3api/H3GameData/H3Spell.hpp"

namespace h3
{
	_H3API_ H3MagicAnimation* H3MagicAnimation::GetAnim(INT32 spellId)
	{
		H3Spell* spellInfo = &H3Spell::Get()[spellId];
		if (spellInfo->animationIndex < 0)
		{
			return nullptr;
		}
		H3MagicAnimation* animTable = H3MagicAnimation::Get();
		return &animTable[spellInfo->animationIndex];
	}
} /* namespace h3 */
