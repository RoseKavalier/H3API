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
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemSign);
	_H3API_DECLARE_(SignPost);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief custom text for signpost*/
	struct H3Signpost
	{
		_H3API_SIZE_(0x14);
		BOOL8    hasMessage;
		H3String message;
	};
	_H3API_ASSERT_SIZE_(H3Signpost);

	/** @brief data for sign posts and ocean bottles on adventure map*/
	struct H3MapitemSign
	{
		INT32 id;

		_H3API_ H3Signpost* Get();
		_H3API_ H3Signpost* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
