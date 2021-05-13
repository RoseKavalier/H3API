//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Assets/H3Palette32.hpp"

namespace h3
{
	_H3API_DECLARE_(Palette888);
	_H3API_TYPE_DECLARE_(H3Palette888, Palette24);

#pragma pack(push, 4)
	/** @brief original name: TPalette24*/
	struct H3Palette888 : public H3ResourceItem
	{
		_H3API_SIZE_(0x31C);
		/** @brief [1C] */
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ H3Palette888* Initiate();

		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;
		_H3API_ VOID Init(const H3BasePalette888& palette);

		_H3API_ H3Palette32 Convert() const;
	};
	_H3API_ASSERT_SIZE_(H3Palette888);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
