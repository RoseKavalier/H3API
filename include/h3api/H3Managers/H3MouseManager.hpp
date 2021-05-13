//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"
#include "h3api/H3Constants/H3CstMouseCursor.hpp"

namespace h3
{
	_H3API_DECLARE_(MouseManager);
	struct H3LoadedDef;

#pragma pack(push, 4)

	// * manager for mouse
	struct H3MouseManager : public H3Manager
	{
		struct Cursor
		{
			INT32 type;
			INT32 frame;
		};

		_H3API_SIZE_(0x90);
		_H3API_VTABLE_(0x640038);
		_H3API_GET_INFO_(0x6992B0, H3MouseManager);

	protected:
		h3unk8 _f_38[20];
	public:
		/* @brief [4C] H3MouseCursorType @ 0x67FF88*/
		INT32 cursorType;
		/* @brief [50]*/
		INT32 cursorFrame;
		/* @brief [54]*/
		H3LoadedDef* cursorDef;
	protected:
		h3unk32 _f_58;
		h3unk32 _f_5C;
		h3unk32 _f_60;
	public:
		/** @brief [64] The state of ::ShowCursor()*/
		BOOL8  showCursorState;
		/** @brief [68] whether game cursor is hidden*/
		BOOL   cursorHidden;
	protected:
		h3unk32 _f_6C;
		h3unk32 _f_70;
		h3unk32 _f_74;
		/* @brief [78]*/
		RTL_CRITICAL_SECTION criticalSection;
	public:
		_H3API_ VOID operator=(const Cursor& cursor);

		_H3API_ VOID   TurnOn();
		_H3API_ VOID   TurnOff();
		_H3API_ INT32  GetType() const;
		_H3API_ INT32  GetFrame() const;
		_H3API_ VOID   SetCursor(INT32 frame, INT32 type);
		_H3API_ VOID   SetCursor(INT32 frame, eCursor type);
		_H3API_ VOID   SetCursor(const Cursor& cursor);
		_H3API_ VOID   DefaultCursor();
		_H3API_ VOID   SetArtifactCursor(INT32 art_id);
		_H3API_ Cursor CurrentCursor() const;
	};
	_H3API_ASSERT_SIZE_(H3MouseManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
