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
#include "h3api/H3AdventureMap/H3MapArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemScroll);
	struct H3Main;

#pragma pack(push, 4)
	/** @brief custom setup if any for map artifact*/
	struct H3MapScroll : H3MapArtifact
	{
	};

	/** @brief data for spell scroll on the map*/
	struct H3MapitemScroll
	{
		/** @brief [00] spell id*/
		unsigned  type     : 8;
		unsigned _u1       : 11;
		/** @brief [19] index of custom setup, up to 4096*/
		unsigned  id       : 12;
		/** @brief [31] scroll has a custom setup*/
		unsigned  hasSetup : 1;

		_H3API_ H3MapArtifact* Get();
		_H3API_ H3MapArtifact* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
