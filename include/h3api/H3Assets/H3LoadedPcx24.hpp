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
#include "h3api/H3Assets/H3Resource.hpp"

namespace h3
{
	_H3API_DECLARE_(LoadedPcx24);

#pragma pack(push, 4)

	struct H3LoadedPcx24 : public H3ResourceItem
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x63B9F4);

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
		/** @brief [2C] RGB888 buffer*/
		PUINT8 buffer;

		// * data argument can be NULL if needed, in this case no pixels will be copied
		// * you should still set dataSize as that is sent to buffSize
		// * dataSize = width * height * 3
		_H3API_ H3LoadedPcx24* Construct(LPCSTR name, INT width, INT height, PUINT8 data, UINT32 dataSize);
		// * converts RGB888 to RGB565
		// * if True mode, copies to ARGB888
		_H3API_ VOID DrawToPcx16(INT dst_x, INT dst_y, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row);
		// * returns rgb888 pixel at coordinates (x, y) in buffer
		_H3API_ H3RGB888* GetPixel(int x, int y);

		_H3API_ static H3LoadedPcx24* Load(LPCSTR name, INT width, INT height);
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx24);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
