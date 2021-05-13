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

namespace h3
{
	_H3API_DECLARE_(MapitemBoat);
	_H3API_DECLARE_(Boat);
	struct H3MapItem;
	struct H3Main;

#pragma pack(push, 1)
	// * boat data on adventure map
	// from WoG source
	struct H3Boat // size 0x28 from 0x4CE5C0
	{
		_H3API_SIZE_(0x28);
		/** @brief [00]*/
		INT16 x;
		/** @brief [02]*/
		INT16 y;
		/** @brief [04]*/
		INT16 z;
		/** @brief [06]*/
		INT8 visible;
		/** @brief [07] no clue how to get this offset without align-1, may be substructure*/
		H3MapItem* item;
	protected:
		h3unk8 _f_0B;
	public:
		/** @brief [0C]*/
		INT32 objectType;
		/** @brief [10]*/
		INT8 objectFlag;
	protected:
		h3unk8 _f_11[3];
	public:
		/** @brief [14]*/
		INT32 objectSetup;
		/** @brief [18]*/
		INT8 exists;
		/** @brief [19]*/
		INT8 index;
		/** @brief [1A]*/
		INT8 par1;
		/** @brief [1B]*/
		INT8 par2;
		/** @brief [1C]*/
		INT8 owner;
	protected:
		h3unk8 _f_1D[3];
	public:
		/** @brief [20]*/
		INT32 heroId;
		/** @brief [24]*/
		BOOL8 hasHero;
	protected:
		h3unk8 _f_25[3];
	};
	_H3API_ASSERT_SIZE_(H3Boat);
#pragma pack(pop)

#pragma pack(push, 4)

	struct H3MapitemBoat
	{
		UINT32 index;

		_H3API_ H3Boat* Get();
		_H3API_ H3Boat* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
