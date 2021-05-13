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
#include "h3api/H3Constants/H3CstResources.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemWagon);

#pragma pack(push, 4)

	/** @brief data for wagon on adventure map*/
	struct H3MapitemWagon
	{
		/** @brief [00] 2..5 amount of resources*/
		unsigned  resValue    : 5;
		/** @brief [05] which players have come by*/
		unsigned  visited     : 8;
		/** @brief [13] whether the wagon contains anything at all*/
		unsigned  hasBonus    : 1;
		/** @brief [14] does wagon contain an artifact*/
		unsigned  hasArtifact : 1;
		/** @brief [15] 0..1023 artifact ID*/
		unsigned  artifactID  : 10;
		/** @brief [25] 0..6 resource type, never gold*/
		unsigned  resType     : 4;
		/** @brief [29]*/
		unsigned _u3          : 3;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
		_H3API_ eArtifact         GetArtifact();
		_H3API_ eResource         GetResourceType();
		_H3API_ INT32             GetResourceAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
