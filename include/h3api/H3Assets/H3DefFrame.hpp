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

namespace h3
{
	_H3API_DECLARE_(DefFrame);
	_H3API_TYPE_DECLARE_(H3DefFrame, SpriteFrame);

#pragma pack(push, 4)

	/** @brief original name: CSpriteFrame*/
	struct H3DefFrame : public H3ResourceItem
	{
		_H3API_SIZE_(0x48);

		/** @brief [1C] all row offsets and actual pixel data*/
		INT32 rawDataSize;
		/** @brief [20] frame width * frame height*/
		INT32 dataSize;
		/** @brief [24] 0..3*/
		INT32 compressionType;
		/** @brief [28]*/
		INT32 width;
		/** @brief [2C]*/
		INT32 height;
		/** @brief [30]*/
		INT32 frameWidth;
		/** @brief [34]*/
		INT32 frameHeight;
		/** @brief [38] marginLeft + frameWidth = width*/
		INT32 marginLeft;
		/** @brief [3C]*/
		INT32 marginTop;
		/** @brief [40]*/
		INT32 width2;
		/** @brief [44] rle pixels or index*/
		PUINT8 rawData;

		_H3API_ VOID DrawToPcx16(INT src_x, INT src_y, INT src_width, INT src_height,
			H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, H3Palette565* palette565,
			BOOL mirror = FALSE, BOOL no_special_colors = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3DefFrame);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
