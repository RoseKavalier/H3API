//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(PathNode);
	struct H3MapItem;
	typedef H3PathNode H3TileMovement;

#pragma pack(push, 1)

	struct H3PathNode
	{
		_H3API_SIZE_(0x1E);
	protected:
		/** @brief [00]*/
		H3Position mixedPosition;
	public:
		/** @brief [04]*/
		union
		{
			struct
			{
				unsigned accessible      : 1;   // 1
				unsigned teleporter      : 1;   // 2 (monolith or Subterannean gate), see 56BC7A
				unsigned isWater         : 1;   // 4 see 56BE81
				unsigned magicRestricted : 1;   // 8 ~ cursed ground or antimagic garrison
				unsigned flyableWater    : 1;	// 0x10 entrance? 56BAEF shows water+fly access
				unsigned walkableWater   : 1;	// 0x20 56BAEF shows water+waterwalk access
				unsigned unk2            : 26; 	// 0x40, 0x80, ...
			};
			UINT32 access;
		};
	protected:
		h3unk8 _f_08[16];
	public:
		/** @brief [18]*/
		UINT16 movementCost;
	protected:
		/** @brief [1A]*/
		UINT16 movementCost2;
		h3unk8 _f_1C[2];
	public:
		_H3API_ UINT8 GetX() const;
		_H3API_ UINT8 GetY() const;
		_H3API_ UINT8 GetZ() const;
		_H3API_ H3Point GetCoordinates() const;
		_H3API_ BOOL ZoneControlled() const;
		_H3API_ H3MapItem* GetMapItem() const;
	};
	_H3API_ASSERT_SIZE_(H3PathNode);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */
