//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	struct H3RmgZoneGenerator
	{
		_H3API_SIZE_(0x414);
		H3RmgZone*        zoneInfo;         /**< @brief [00]*/
		INT32            townType;         /**< @brief [04]*/
		INT32            townType2;        /**< @brief [08]*/
		INT32            ground;           /**< @brief [0C]*/
		INT32            x;                /**< @brief [10]*/
		INT32            y;                /**< @brief [14]*/
		INT32            z;                /**< @brief [18]*/
		INT32            size;             /**< @brief [1C]*/
		h3unk8           _f_20[4];         /**< @brief [20]*/
		h3unk8           _f_24[4];         /**< @brief [24]*/
		INT32            width;            /**< @brief [28]*/
		INT32            height;           /**< @brief [2C]*/
		h3unk8           _f_30[12];        /**< @brief [30]*/
		h3unk8           _f_3C[8];         /**< @brief [3C]*/
		INT32            objectCount[232]; /**< @brief [44]*/
		H3Vector<h3unk*> _f_3E4;           /**< @brief [3E4]*/
		H3Vector<h3unk*> _f_3F4;           /**< @brief [3F4]*/
		H3Vector<h3unk*> _f_404;           /**< @brief [404]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneGenerator);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
