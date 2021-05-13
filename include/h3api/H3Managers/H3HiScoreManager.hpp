//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"

namespace h3
{
	_H3API_DECLARE_(HiScoreManager);

#pragma pack(push, 4)

	struct H3HiScoreManager : H3Manager
	{
		_H3API_SIZE_(0x8D4);
		_H3API_VTABLE_(0x63EB8C);
		_H3API_GET_INFO_(0x69941C, H3HiScoreManager);
		struct Entry
		{
			_H3API_SIZE_(0x64);

			CHAR username[40];
			CHAR mapname[40];
			h3unk32 _f_50;
			INT32 score;
			INT32 days;
			h3unk8 _f_5C[8];
		};
		/** @brief [38] a buffer to read from <Heroes3>/data/HiScore.dat*/
		Entry scenarios[11];
		/** @brief [484] a buffer to read from <Heroes3>/data/HiScore.dat*/
		Entry campaigns[11];
		/** @brief [8D0]*/
		BOOL showingSingleScenarios;

		_H3API_ VOID ResetScores();
	};
	_H3API_ASSERT_SIZE_(H3HiScoreManager);
	_H3API_ASSERT_SIZE_(H3HiScoreManager::Entry);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
