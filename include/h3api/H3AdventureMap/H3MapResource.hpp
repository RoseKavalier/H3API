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
#include "h3api/H3Constants/H3CstResources.hpp"
#include "h3api/H3AdventureMap/H3MapArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapResource);
	_H3API_DECLARE_(MapitemResource);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief if a mapresource has a custom setup, this is the referenced data*/
	struct H3MapResource : H3MapArtifact
	{
	};

	/** @brief data for resource on adventure map*/
	struct H3MapitemResource
	{
		/** @brief [00] up to 524,287*/
		unsigned value      : 19;
		/** @brief [19] index of custom setup for guardians and message*/
		unsigned setupIndex : 12;
		/** @brief [31] resource has a custom setup*/
		unsigned hasSetup   : 1;

		_H3API_ H3MapResource* Get();
		_H3API_ H3MapResource* Get(H3Main* main);
		_H3API_ eResource      GetType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
