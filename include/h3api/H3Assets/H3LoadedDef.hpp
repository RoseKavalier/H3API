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
	_H3API_DECLARE_(LoadedDef);
	_H3API_TYPE_DECLARE_(H3LoadedDef, Sprite);

#pragma pack(push, 4)
	/** @brief original name: CSprite*/
	struct H3LoadedDef : public H3ResourceItem
	{
		_H3API_SIZE_(0x38);

		struct DefGroup
		{
			_H3API_SIZE_(0x0C);
			/** @brief [00]*/
			INT32 count;
			/** @brief [04]*/
			UINT32 spritesSize;
			/** @brief [08]*/
			H3DefFrame** frames;

			_H3API_ H3DefFrame& operator[](UINT index);
		};

		/** @brief [1C]*/
		DefGroup**    groups;
		/** @brief [20]*/
		H3Palette565* palette565;
		/** @brief [24]*/
		H3Palette888* palette888;
		/** @brief [28]*/
		INT32 groupsCount;
		/** @brief [2C]*/
		INT32* activeGroups;
		/** @brief [30]*/
		INT32 widthDEF;
		/** @brief [34]*/
		INT32 heightDEF;

		_H3API_ VOID AddFrameFromDef(LPCSTR source, INT32 index);
		_H3API_ VOID ColorToPlayer(INT32 id);
		_H3API_ H3DefFrame* GetGroupFrame(INT group, INT frame);
		_H3API_ VOID DrawTransparent(INT32 frame, H3LoadedPcx16* pcx, INT32 x, INT32 y, BOOL transparent = TRUE,
			BOOL mirror = FALSE, INT32 group = 0, INT32 xFromRight = 0, INT32 yFromBottom = 0);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, INT src_x, INT src_y, INT src_width, INT src_height,
			H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL mirror = FALSE, BOOL do_not_use_special_colors = TRUE);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y);

		_H3API_ VOID AddDefGroup(UINT group_id, UINT frames_in_group);
		_H3API_ VOID AddFrameToGroup(UINT group_id, H3DefFrame* frame);
		_H3API_ VOID Init(LPCSTR name, UINT type, UINT width, UINT height);

		_H3API_ DefGroup& operator[](UINT index);

		_H3API_ static H3LoadedDef* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3LoadedDef);
	_H3API_ASSERT_SIZE_(H3LoadedDef::DefGroup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
