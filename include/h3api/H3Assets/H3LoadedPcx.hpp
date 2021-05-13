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
	_H3API_DECLARE_(LoadedPcx);
	_H3API_TYPE_DECLARE_(H3LoadedPcx, Bitmap8);

#pragma pack(push, 4)

	/** @brief original name Bitmap8*/
	struct H3LoadedPcx : public H3ResourceItem
	{
		_H3API_SIZE_(0x56C);
		_H3API_VTABLE_(0x63BA14);

		/** @brief [1C]*/
		INT32 bufSize;
		/** @brief [20]*/
		INT32 bufSizeUnk;
		/** @brief [24]*/
		INT32 width;
		/** @brief [28]*/
		INT32 height;
		/** @brief [2C]*/
		INT32 scanlineSize;
		/** @brief [30] 256-color indexed buffer*/
		PUINT8 buffer;
		/** @brief [34]*/
		H3BasePalette565 palette565;
		/** @brief [250]*/
		H3BasePalette888 palette888;

		_H3API_ VOID DrawToPcx16(int srcX, int srcY, int dx, int dy, H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx16(H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx(int src_x, int src_y, int dx, int dy, H3LoadedPcx* pcx_dest, int dest_x = 0, int dest_y = 0, BOOL copy_palette = TRUE);
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row) const;
		// * returns the color index of pixel (x, y) starting from top left
		_H3API_ PUINT8 GetPixelIndex(int x, int y) const;
		// * fills rectangle with color index from palette565
		_H3API_ VOID FillRectangle(INT x, INT y, INT dx, INT dy, BYTE color_index);

		_H3API_ H3LoadedPcx(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name, INT w, INT h);

		_H3API_ static H3LoadedPcx* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx* Create(LPCSTR name, INT width, INT height);
		_H3API_ VOID DrawAlpha(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
	protected:
		_H3API_ VOID drawAlpha2(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
		_H3API_ VOID drawAlpha4(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const;
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
