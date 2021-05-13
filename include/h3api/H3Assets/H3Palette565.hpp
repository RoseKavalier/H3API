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
#include "h3api/H3Assets/H3Pixels.hpp"
#include "h3api/H3Assets/H3Palette32.hpp"

namespace h3
{
	_H3API_DECLARE_(Palette565);
	_H3API_TYPE_DECLARE_(H3Palette565, Palette16);

#pragma pack(push, 4)
	/** @brief 16-bits palette. Original name TPalette16*/
	struct H3Palette565 : public H3ResourceItem
	{
		_H3API_SIZE_(0x21C);
		/** @brief [1C]*/
		union {
			struct {
				H3RGB565 color[256];
			};
			struct {
				H3RGB565   unusedColors[254];
				H3Palette32* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		_H3API_ H3Palette565* Initiate();
		// * as of HDmod 5.0 RC 63, Palette565 now contains a buffer o ARGB888 colors[256] located at &color[254]
		// * http://heroescommunity.com/viewthread.php3?TID=44581&PID=1503736#focus
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(const H3Palette565& source);
		_H3API_ VOID CopyPalette(const H3BasePalette565& source);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

		_H3API_ VOID Init(const H3BasePalette565& palette);

		_H3API_ static H3Palette565* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3Palette565);

	_H3API_NAMED_STRUCT_(H3Palette565, PlayersPalette, 0x6AAD10);
	_H3API_NAMED_STRUCT_(H3Palette565, GamePalette, 0x6AAD18);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
