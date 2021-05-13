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

namespace h3
{
	_H3API_DECLARE_(MainSetup);
	struct H3ObjectAttributes;
	struct H3ObjectDetails;
	struct H3LoadedDef;
	struct H3MapArtifact;
	struct H3Monster;
	struct H3PandorasBox;
	struct H3SeerHut;
	struct H3QuestGuard;
	struct H3GlobalEvent;
	struct H3CastleEvent;
	struct H3HeroPlaceholder;
	struct H3Quest;
	struct H3RandomDwelling;
	struct H3MapItem;
	struct H3ObjectDraw;

#pragma pack(push, 4)

	// * mostly vectors of information used on adventure map
	struct H3MainSetup
	{
		_H3API_SIZE_(0xF5C);
		H3Vector<H3ObjectAttributes> objectAttributes; // +00 // +01FB70
		H3Vector<H3ObjectDetails>    objectDetails;	   // +10
		H3Vector<H3LoadedDef*>       defs;			   // +20
		H3Vector<H3MapArtifact>      artifactResource; // +30
		H3Vector<H3Monster>          monsters;	       // +40
		H3Vector<H3PandorasBox>      pandoraEvents;    // +50 // +01FBC0
		H3Vector<H3SeerHut>          seerHuts;	       // +60 // +01FBD0
		H3Vector<H3QuestGuard>       questGuards;	   // +70 // +01FBE0
		H3Vector<H3GlobalEvent>      globalEvents;	   // +80
		H3Vector<H3CastleEvent>      castleEvents;	   // +90
		H3Vector<H3HeroPlaceholder*> heroPlaceholders; // +A0
		H3Vector<H3Quest*>           quests;           // +B0
		H3Vector<H3RandomDwelling>   randomDwellings;  // +C0
		H3MapItem*                   mapitems;         // +D0 // +1FC40
		INT32                        mapSize;          // +D4 // +1FC44
		BOOL8                        hasUnderground;   // +D8 // +1FC48
		H3Vector<H3ObjectAttributes> objectLists[232];

		_H3API_ H3MapItem* GetMapItem(INT32 x, INT32 y, INT32 z);
		_H3API_ VOID DrawItem(H3MapItem* mitem, H3ObjectDraw* draw);
		_H3API_ VOID AddObjectAttribute(H3ObjectAttributes* oa);
		_H3API_ H3Point GetCoordinates(H3MapItem* item);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3MainSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
