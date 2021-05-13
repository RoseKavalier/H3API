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
#include "h3api/H3Constants/H3CstArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemSeaChest);

#pragma pack(push, 4)

	/** @brief data for sea chest on adventure map*/
	struct H3MapitemSeaChest
	{
		enum eType
		{
			EMPTY,
			GOLD1500,
			GOLD1000_ARTIFACT,
		};

		/** @brief [00] 0 empty, 1 1500 gold, 2 1000 gold & artifact*/
		unsigned level      : 2;
		/** @brief [02]*/
		unsigned _u1        : 1;
		/** @brief [03] 0..1023 artifact IDs*/
		unsigned artifactID : 10;
		/** @brief [13]*/
		unsigned _u2        : 19;

		_H3API_ eType     GetType();
		_H3API_ eArtifact GetArtifact();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
