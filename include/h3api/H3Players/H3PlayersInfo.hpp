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
	_H3API_DECLARE_(PlayersInfo);

#pragma pack(push, 4)

	struct H3PlayersInfo
	{
		_H3API_SIZE_(0x1CC);
	protected:
		h3unk8 _f_000[8];
	public:
		/** @brief [008]*/
		INT8  handicap[8];
		/** @brief [010]*/
		INT32 townType[8];
		/** @brief [030] 0 human, 10 computer, -1 not set*/
		INT8  playerType[8];
		/** @brief [038]*/
		INT8  difficulty;
		/** @brief [039]*/
		CHAR  filename[251];
		/** @brief [134]*/
		CHAR  saveDirectory[100];
		/** @brief [198]*/
		BOOL8 isPlayable[8];
	protected:
		h3unk8 _f_1A0[3];
	public:
		/** @brief [1A3]*/
		INT8 turnDuration;
		/** @brief [1A4]*/
		INT32 heroMaybe[8];
	protected:
		h3unk8 _f_1C4[8];
	};
	_H3API_ASSERT_SIZE_(H3PlayersInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
