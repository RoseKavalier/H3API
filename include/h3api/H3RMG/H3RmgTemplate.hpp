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
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	struct H3RmgTemplate
	{
		_H3API_SIZE_(0x38);
		H3String            name;      /**< @brief [00]*/
		H3Vector<H3RmgZone*> zones;     /**< @brief [10]*/
		h3unk8              _f_20[16]; /**< @brief [20]*/
		INT32               minSize;   /**< @brief [30]*/
		INT32               maxSize;   /**< @brief [34]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgTemplate);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
