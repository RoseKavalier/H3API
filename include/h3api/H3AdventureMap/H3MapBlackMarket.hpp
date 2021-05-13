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
#include "h3api/H3Constants/H3CstArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemBlackMarket);
	_H3API_DECLARE_(BlackMarket);
	_H3API_DECLARE_(ArtifactMerchant);
	struct H3Main;

#pragma pack(push, 4)
	/** @brief black market is an array of 7 artifacts*/
	struct H3BlackMarket
	{
		INT32 artifacts[7];
	};

	struct H3ArtifactMerchant : H3BlackMarket
	{
	};

	/** @brief data for Black Markets on adventure map*/
	struct H3MapitemBlackMarket
	{
		UINT id;

		_H3API_ H3BlackMarket* Get();
		_H3API_ H3BlackMarket* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
