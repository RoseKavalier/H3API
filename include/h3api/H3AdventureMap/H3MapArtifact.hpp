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
#include "h3api/H3Creatures/H3Army.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemArtifact);
	_H3API_DECLARE_(MapArtifact);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief if a mapartifact has a custom setup, this is the referenced data*/
	struct H3MapArtifact
	{
		_H3API_SIZE_(0x4C);
		/** @brief [0] */
		H3String message;
		/** @brief [10] */
		BOOL8 isGuarded;
		/** @brief [14] */
		H3Army guardians;
	};
	_H3API_ASSERT_SIZE_(H3MapArtifact);

	/** @brief data for artifact on the map*/
	struct H3MapitemArtifact
	{
		enum eType
		{
			/** @brief free selection*/
			FREE,
			/** @brief buy for 2000 gold*/
			GOLD2000,
			/** @brief wisdom sec skill is required*/
			WISDOM,
			/** @brief leadership sec skill is required*/
			LEADERSHIP,
			/** @brief buy for 2500 gold and 3 wood*/
			GOLD2500_WOOD3,
			/** @brief buy for 3000 gold and 5 wood*/
			GOLD3000_WOOD5,
			/** @brief fight is triggered*/
			FIGHT,
		};

		/** @brief [00] RoE-style artifact pickup requirements, see eType*/
		unsigned type     : 4;
		unsigned _u1      : 15;
		/** @brief [19] index of custom setup, up to 4096*/
		unsigned id       : 12;
		/** @brief [31] monster has a custom setup*/
		unsigned hasSetup : 1;

		_H3API_ H3MapArtifact* Get();
		_H3API_ H3MapArtifact* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
