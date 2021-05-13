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
	_H3API_DECLARE_(LoadedPcx16);
	_H3API_TYPE_DECLARE_(H3LoadedPcx16, Bitmap16);

#pragma pack(push, 4)
	/** @brief original name Bitmap16*/
	struct H3LoadedPcx16 : public H3ResourceItem
	{
		_H3API_SIZE_(0x38);
		_H3API_VTABLE_(0x63B9C8);

		/** @brief [1C]*/
		INT32 buffSize;
	protected:
		/** @brief [20]*/
		INT32 buffSizeUnk;
	public:
		/** @brief [24]*/
		INT32 width;
		/** @brief [28]*/
		INT32 height;
		/** @brief [2C]*/
		INT32 scanlineSize;
		/** @brief [30] H3RGB565 buffer unless bitmode == 4 in which case this is a H3ARGB888 buffer*/
		PUINT8 buffer;
		/** @brief [34]*/
		BOOL8 keepBuffer; // see 0x44DDE0

		_H3API_ VOID CopyRegion(H3LoadedPcx16* source, INT x, INT y);
		_H3API_ H3LoadedPcx16* Construct(LPCSTR name, INT width, INT height);
		_H3API_ VOID DrawToPcx16(INT x, INT y, BOOL transparent, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		_H3API_ VOID Destroy(BOOL destroy_buffer = TRUE);
		// * darkens RGB by about 50%
		_H3API_ VOID DrawShadow(INT x, INT y, INT dw, INT dh);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, DWORD color);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, BYTE r = 232, BYTE g = 212, BYTE b = 120);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, const H3RGB888& color);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, const H3RGB888& color);
		_H3API_ VOID DarkenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID LightenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID GrayScaleArea(INT x, INT y, INT w, INT h);
		// * modifies hue and saturation of region to match the specified values (HSV model)
		// * <hue> is on the scale 0~1 and represents the color scheme
		// * <saturation> is also scaled between 0 ~ 1 and represents how colorful (0 being grayscale) the image appears
		// * value is fixed
		_H3API_ VOID AdjustHueSaturation(INT x, INT y, INT w, INT h, FLOAT hue, FLOAT saturation);
		_H3API_ BOOL BackgroundRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL is_blue);
		_H3API_ BOOL SimpleFrameRegion(INT32 x, INT32 y, INT32 _width, INT32 _height);
		_H3API_ BOOL FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue);
		// * adds a 1 pixel border around the designated area to make it look
		// * as if the contents were lowered
		_H3API_ VOID SinkArea(INT32 x, INT32 y, INT32 w, INT32 h);
		// * adds a 1 pixel border around the designated area to make it look
		// * as if the contents were elevated
		_H3API_ VOID BevelArea(INT32 x, INT32 y, INT32 w, INT32 h);
		// * Draws text on the pcx
		_H3API_ VOID TextDraw(H3Font* font, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			eTextColor colorIndex = eTextColor::REGULAR,
			eTextAlignment alignment = eTextAlignment::MIDDLE_CENTER);

		_H3API_ static H3LoadedPcx16* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx16* Create(LPCSTR name, INT width, INT height);
		/** @brief creates an unnamed pcx16 drawing canvas*/
		_H3API_ static H3LoadedPcx16* Create(INT width, INT height);
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row);
		// * returns rgb565 pixel at coordinates (x,y) in buffer
		// * !WARNING! This is only valid when h3_BitMode == 2 aka default
		_H3API_ H3RGB565* GetPixel565(int x, int y);
		// * returns argb8888 pixel at coordinates (x,y) in buffer
		// * !WARNING! This is only valid when h3_BitMode == 4 aka TRUE mode with HDmod
		_H3API_ H3ARGB888* GetPixel888(int x, int y);
		_H3API_ H3ARGB888 GetPixel(int x, int y);
		// * clamp drawing coordinates and dimensions
		_H3API_ VOID Clamp(INT& src_x, INT& src_y, INT& src_w, INT& src_h, INT& dst_x, INT& dst_y) const;
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx16);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
