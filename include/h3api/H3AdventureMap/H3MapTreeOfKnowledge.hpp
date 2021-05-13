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
	_H3API_DECLARE_(MapitemTreeOfKnowledge);

#pragma pack(push, 4)

	/** @brief data for tree of knowledge on adventure map*/
	struct H3MapitemTreeOfKnowledge
	{
		enum eType
		{
			FREE,
			GOLD2000,
			GEMS10,
		};

		/** @brief [00] 0..31 individual IDs*/
		unsigned  id      : 5;
		/** @brief [05] which players have come by*/
		unsigned  visited : 8;
		/** @brief [13] cost: 0 free, 1 2000 gold, 2 10 gems*/
		unsigned  type    : 2;
		/** @brief [15]*/
		unsigned _u1      : 17;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ eType GetType();
	};


#pragma pack(pop) /* align-4 */

} /* namespace h3 */
