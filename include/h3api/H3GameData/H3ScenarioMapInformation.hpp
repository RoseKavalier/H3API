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
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3GameData/H3MapInfo.hpp"
#include "h3api/H3Players/H3PlayersInfo.hpp"

namespace h3
{
	_H3API_DECLARE_(ScenarioMapInformation);
	struct H3Hero;

#pragma pack(push, 4)
	
	/** @brief Used when loading preliminary data from map files*/
	struct H3ScenarioMapInformation : H3MapInfo
	{
		_H3API_SIZE_(0xCA4);
		/** @brief [304]*/
		H3PlayersInfo              playersInfo;
		/** @brief [4D0]*/
		h3unk16                    _f_4D0;
		/** @brief [4D2]*/
		h3unk8                     _f_4D2[30];
		/** @brief [4F0]*/
		INT8                       heroOwner[156];
		/** @brief [58C]*/
		CHAR                       mapNameArray[61];
		/** @brief [5C9]*/
		CHAR                       mapDescriptionArray[300];
		/** @brief [6F8]*/
		FILETIME                   fileTime;
		/** @brief [700]*/
		h3unk8                     gap700[8];
		/** @brief [708]*/
		h3unk32                    _f_708;
		/** @brief [70C]*/
		h3unk8                     _f_70C[4];
		/** @brief [710]*/
		H3MapInfo                  mapinfo;
		/** @brief [A14]*/
		H3PlayersInfo              playersinfo;
		/** @brief [BE0]*/
		h3unk8                     _f_BE0[64];
		/** @brief [C20]*/
		H3Vector<H3Vector<H3Hero>> heroes;
		/** @brief [C30]*/
		h3unk8                     _f_C30[16];
		/** @brief [C40]*/
		H3Vector<h3unk8>            _f_C40;
		/** @brief [C50]*/
		H3Vector<h3unk8>            _f_C50;
		/** @brief [C60]*/
		H3String                   _f_C60;
		/** @brief [C70]*/
		h3unk8                     _f_C70[8];
		/** @brief [C78]*/
		BOOL8                      isPlayerAbsent[8];
		/** @brief [C80]*/
		h3unk32                    _f_C80[8];
		/** @brief [CA0]*/
		h3unk32                    _f_CA0;
	};
	_H3API_ASSERT_SIZE_(H3ScenarioMapInformation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
