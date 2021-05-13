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
	_H3API_DECLARE_(MapitemWarriorsTomb);

#pragma pack(push, 4)

	/** @brief data for warrior's tomb on adventure map*/
	struct H3MapitemWarriorsTomb
	{
		/** @brief [00] does the tomb contains an artifact*/
		unsigned  hasArt : 1;
		/** @brief [01] */
		unsigned _u1 : 4;
		/** @brief [05] which players have come by*/
		unsigned  visited : 8;
		/** @brief [13] 0..1023 artifact IDs */
		unsigned  artifactID : 10;
		/** @brief [23] */
		unsigned _u2 : 9;

		_H3API_ eArtifact         GetArtifact();
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
