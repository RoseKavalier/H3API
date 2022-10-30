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
	_H3API_DECLARE_(ScreenChat);
	struct H3ScreenchatEdit;
	struct H3WavFile;
	struct H3String;

#pragma pack(push, 4)

	/**
	 * @brief Handles printing of player text on the screen.
	 * Not a dialog per se but has similar behaviour.
	 */
	struct H3ScreenChat
	{
		_H3API_SIZE_(0x44);
		_H3API_GET_INFO_(0x69D800, H3ScreenChat);
		_H3API_CTOR_DTOR_(0x5525C4, 0x552640);

		struct ChatEntry
		{
			_H3API_SIZE_(0x88);
			CHAR   text[128];
			UINT32 showTime;
			BOOL8  flag;
		};
		struct UnkEntry
		{
			_H3API_SIZE_(0x7F);
			h3unk8 unk[0x7F];
		};

		/** @brief [00]*/
		ChatEntry* entries;
		/** @brief [04]*/
		INT32      firstItemShift;
		/** @brief [08]*/
		INT32      currentlyShown;
		/** @brief [0C]*/
		UnkEntry*  items;
		/** @brief [10]*/
		UINT32     time;
		/** @brief [14]*/
		BOOL8      redraw;
		/** @brief [18]*/
		H3ScreenchatEdit* dlgEdit;
		/** @brief [1C]*/
		INT32      maxItemNum;
		/** @brief [20]*/
		INT32      lastDrawn;
		/** @brief [24]*/
		h3unk8     field_24;
		/** @brief [28]*/
		h3unk32    sound_f_28;
		/** @brief [2C]*/
		BOOL8      flag;
		/** @brief [30]*/
		H3WavFile* chatWav;
		/** @brief [34]*/
		H3WavFile* playexitWav;
		/** @brief [38]*/
		H3WavFile* sysmsgWav;
		/** @brief [3C]*/
		H3WavFile* timeoverWav;
		/** @brief [40]*/
		H3WavFile* playcomeWav;

		/**
		 * @brief Checks the oldest message for removal
		 * @return Whether 20,000ms have elapsed
		 */
		_H3API_ BOOL8 CheckExpiry();
		_H3API_ VOID  Clear();
		_H3API_ VOID  ShowVA(LPCSTR format, ...);
		_H3API_ VOID  Show(LPCSTR text);
		_H3API_ VOID  Show(const H3String& text);
		_H3API_ VOID  CheckTimeUpdate();
		_H3API_ VOID  SetCurrentTime();
	};
	_H3API_ASSERT_SIZE_(H3ScreenChat);
	_H3API_ASSERT_SIZE_(H3ScreenChat::ChatEntry);
	_H3API_ASSERT_SIZE_(H3ScreenChat::UnkEntry);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
