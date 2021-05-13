//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapResource.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3AdventureMap/H3MapItems.hpp"

namespace h3
{
	_H3API_ H3MapResource* H3MapitemResource::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3MapResource* H3MapitemResource::Get(H3Main* main)
	{
		return hasSetup ? reinterpret_cast<H3MapResource*>(&main->mainSetup.artifactResource[setupIndex]) : nullptr;
	}
	_H3API_ eResource H3MapitemResource::GetType()
	{
		return eResource(reinterpret_cast<H3MapItem*>(this)->objectSubtype);
	}
} /* namespace h3 */
