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
#include "h3api/H3Creatures/H3Army.hpp"

namespace h3
{
	_H3API_DECLARE_(Generator);
	_H3API_DECLARE_(MapitemGenerator);
	_H3API_TYPE_DECLARE_(H3Generator, Dwelling);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief data of creature dwelling on adventure map*/
	struct H3Generator
	{
		_H3API_SIZE_(0x5C);
		/** @brief [0] */
		INT8 type;
		/** @brief [1] used to retrieve name*/
		INT8 subtype;
		/** @brief [4] */
		INT32 creatureTypes[4];
		/** @brief [14] */
		INT16 creatureCounts[4];
		/** @brief [1C] */
		H3Army defenders;
		/** @brief [54] */
		UINT8 x;
		/** @brief [55] */
		UINT8 y;
		/** @brief [56] */
		UINT8 z;
		/** @brief [57] */
		INT8 ownerID;
	protected:
		h3unk8 _f58;
	};
	_H3API_ASSERT_SIZE_(H3Generator);

	/** @brief creature generators type 1 and 4 (2&3 don't exist)*/
	struct H3MapitemGenerator
	{
		/** @brief [00] setup index*/
		INT32 id;

		_H3API_ H3Generator* Get();
		_H3API_ H3Generator* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
