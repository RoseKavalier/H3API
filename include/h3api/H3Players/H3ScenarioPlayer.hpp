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
	_H3API_DECLARE_(ScenarioPlayer);

#pragma pack(push, 4)
	/** @brief player information in the select scenario dialog*/
	struct H3ScenarioPlayer
	{
		_H3API_SIZE_(0x7C);
		_H3API_CTOR_DTOR_(0x57CB10, -1);
		/** @brief [00]*/
		INT32   player;
		/** @brief [04]*/
		CHAR    name[24];
		/** @brief [1C]*/
		INT32*  gameVersionPtr;
		/** @brief [20]*/
		INT32   gameVersion;
		/** @brief [24]*/
		INT32   town;
		/** @brief [28]*/
		INT32   heroesCount;
		/** @brief [2C]*/
		INT32   heroes[16];
		/** @brief [6C] 0..3 art, gold, resource, random*/
		INT32   bonusType;
		/** @brief [70] {-1}*/
		h3unk32 player2;
		/** @brief [74] {-1}*/
		h3unk32 _f_74;
		/** @brief [78] {0}*/
		h3unk8  _f_78;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioPlayer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
