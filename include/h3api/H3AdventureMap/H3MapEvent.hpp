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
#include "h3api/H3AdventureMap/H3MapPandorasBox.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemEvent);
	_H3API_DECLARE_(Event);
	struct H3Main;

#pragma pack(push, 4)

	struct H3Event : H3PandorasBox
	{
	};

	/** @brief data for event and Pandora's Box on adventure map*/
	struct H3MapitemEvent
	{
		/** @brief [00] 0..1023 custom setups*/
		unsigned  id        : 10;
		/** @brief [10] which players can activate it?*/
		unsigned  enabled   : 8;
		/** @brief [18] can AI activate it?*/
		unsigned  aiEnabled : 1;
		/** @brief [19] cancel after 1 visit*/
		unsigned  oneVisit  : 1;
		/** @brief [20] ?unused? ==> could be used to expand number of uniques*/
		unsigned _u1        : 12;

		_H3API_ H3Event*          Get();
		_H3API_ H3Event*          Get(H3Main* main);
		_H3API_ H3PlayersBitfield EnabledPlayers();
		_H3API_ VOID              SetEnabled(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
