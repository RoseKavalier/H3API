//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	struct H3Msk;
	struct H3Fnt;
	struct H3LodItem;
	struct H3LoadedMsk;
	struct H3Lod;

#pragma pack(push, 1)

	/** @brief Adventure map masks information in lod archives*/
	struct H3Msk
	{
		_H3API_SIZE_(0x0E);
		struct Msk
		{
			/** @brief [00]*/
			DWORD dbits;
			/** @brief [04]*/
			WORD  wbits;

			_H3API_ void operator>>(H3ObjectMask& mask) const;
		};
		/** @brief [00] number or cells occupied horizontally*/
		UINT8 width;
		/** @brief [01] number or cells occupied vertically*/
		UINT8 height;
		/** @brief [02] which cells have a display colour*/
		Msk   colorMask;
		/** @brief [08] which cells have a shadow colour*/
		Msk   shadowMask;
	};
	_H3API_ASSERT_SIZE_(H3Msk);

	/** @brief Font information in lod archives*/
	struct H3Fnt
	{
		/** @brief [00]*/
		UINT8  magic[5];
		/** @brief [05]*/
		UINT8  height;
		/** @brief [06]*/
		h3unk8 header[26];
		/** @brief [20]*/
		struct FntCharacter
		{
			INT32 leftMargin;
			INT32 width;
			INT32 rightMargin;
		}characters[256];
		/** @brief [C20]*/
		UINT32 bufferOffsets[256];
		/**
		 * @brief [1020] total size is sum of all character widths * height
		 * 00 - nothing
		 * 01 - shadow
		 * FF - color
		 */
		UINT8 buffer[4]; // size unset
	};
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)

	/** @brief header for assets that exist within lod archive*/
	struct H3LodItem
	{
		_H3API_SIZE_(0x20);
		/** @brief [00]*/
		CHAR    name[12];
		/** @brief [0C] always 0, indicates end of name*/
		h3unk32 nameEnd;
		/** @brief [10]*/
		PUINT8  buffer;
		/** @brief [14]*/
		UINT32  size;
		/** @brief [18]*/
		INT32   type;
		/** @brief [1C]*/
		UINT32  sizeCompressed;
	};
	_H3API_ASSERT_SIZE_(H3LodItem);

	struct H3LoadedMsk
	{
		_H3API_SIZE_(0x18);

		/** @brief [00]*/
		UINT width;
		/** @brief [04]*/
		UINT height;
		/** @brief [08]*/
		H3ObjectMask colors;
		/** @brief [10]*/
		H3ObjectMask shadow;

		_H3API_ VOID operator=(const H3Msk& msk);
	};
	_H3API_ASSERT_SIZE_(H3LoadedMsk);

	struct H3Lod
	{
		_H3API_SIZE_(0x190);

		/** @brief [00] lod's name*/
		LPCSTR name;
		/** @brief [04]*/
		FILE* filePosition;
		/** @brief [08] possibly fewer chars, not important*/
		CHAR   path[256];
		/** @brief [108]*/
		h3unk  _f_108[112];
		/** @brief [178]*/
		INT32  filesCount;
		/** @brief [17C]*/
		h3unk  _f_17C[4];
		/** @brief [180] buffer to lod item headers*/
		PUINT8 fileHeaders;
		/** @brief [184]*/
		h3unk  _f_184[12];

		_H3API_ H3Lod*     Create(LPCSTR fileName);
		_H3API_ VOID       Destroy();
		_H3API_ BOOL       Load(LPCSTR fileName);
		_H3API_ BOOL8      FindFileInLod(LPCSTR file);
		_H3API_ H3LodItem* LoadFileFromLod(LPCSTR file);
	};
	_H3API_ASSERT_SIZE_(H3Lod);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
