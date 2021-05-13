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
#include "h3api/H3Constants/H3CstSkills.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemUniversity);
	_H3API_DECLARE_(University);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief university is an array of 4 sskills*/
	struct H3University
	{
		_H3API_SIZE_(0x10);

		INT32 sSkill[4];

		_H3API_ PINT begin();
		_H3API_ PINT end();
	};
	_H3API_ASSERT_SIZE_(H3University);

	/** @brief data for university on adventure map*/
	struct H3MapitemUniversity
	{
		/** @brief [00]*/
		unsigned _u1      : 5;
		/** @brief [05] which players have come by*/
		unsigned  visited : 8;
		/** @brief [13] 0..4095*/
		unsigned  id      : 12;
		/** @brief [25]*/
		unsigned _u2      : 7;

		_H3API_ H3University*     Get();
		_H3API_ H3University*     Get(H3Main* main);
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
