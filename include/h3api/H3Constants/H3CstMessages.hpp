//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
	namespace NH3Messages
	{
		namespace NItemIDs
		{
			enum eItemIDs
			{
				SAVE         = 30000, /* custom value */
				OK           = 30725,
				CANCEL       = 30726,
                SELECT_RIGHT = 30729,
                SELECT_LEFT  = 30730,
			};
		}
		typedef NItemIDs::eItemIDs eItemIDs;

		namespace NMessageCommand
		{
			enum eMessageCommand
			{
				NONE           = 0,
				KEY_DOWN       = 0x0001,
				KEY_UP         = 0x0002,
				MOUSE_OVER     = 0x0004,
				LCLICK_OUTSIDE = 0x0008,
				LBUTTON_UP     = 0x0010,
				ITEM_REDRAW    = 0x0010,
				RCLICK_OUTSIDE = 0x0020,
				RBUTTON_UP     = 0x0040,
				KEY_HELD       = 0x0100,
				MOUSE_BUTTON   = 0x0200,
				ITEM_COMMAND   = 0x0200,
				WHEEL_BUTTON   = 0x0309,
				MOUSE_WHEEL    = 0x020A,

				/* modified WM_ style messages to h3
					WM_KEY_DOWN       = 1,  // 0x100
					WM_KEY_UP         = 2,  // 0x101
					WM_MOUSE_MOVE     = 4,  // 0x200
					WM_LBUTTON_DOWN   = 8,  // 0x201
					WM_LBUTTON_UP     = 16, // 0x202
					WM_LBUTTON_DBLCLK = 8,  // 0x203
					WM_RBUTTON_DOWN   = 32, // 0x204
					WM_RBUTTON_UP     = 64, // 0x205
					WM_RBUTTON_DBLCLK = 32, // 0x206
				*/
			};
		}
		typedef NMessageCommand::eMessageCommand eMessageCommand;

		namespace NMessageMsgSubtype
		{
			enum eMessageMsgSubtype
			{
				NONE                    = 0,
				END_DIALOG              = 0xA,
				LBUTTON_DOWN            = 0xC,
				LBUTTON_CLICK           = 0xD,
				RBUTTON_DOWN            = 0xE,
				MOUSE_WHEEL_BUTTON_DOWN = 0x207,
				MOUSE_WHEEL_BUTTON_UP   = 0x208,

				/* message commands sent to window controls using MessageMsgCommand::MC_ITEM_COMMAND */
				/* payload is set in H3Msg::parameter */

				REPAINT           = 0x02, /* no payload */
				SET_TEXT          = 0x03, /* LPCSTR text */
				SET_FRAME         = 0x04, /* INT def frame */
				ADD_FLAGS         = 0x05, /* INT alters control state TODO */
				REMOVE_FLAGS      = 0x06, /* INT alters control state TODO */
				SET_COLOR         = 0x08, /* INT for DlgFrame */
				CLOSE_ON_CLICK    = 0x08, /* INT for DlgDef */
				SET_IMAGE         = 0x09, /* LPCSTR name, replaces existing sprite */
				SET_PALETTE       = 0x0A, /* LPCSTR name */
				SET_FRAME_GROUP   = 0x0C, /* sets def frame to 0 and group to specified type*/
				USE_PLAYER_COLOR  = 0x0D, /* INT player index */
				SET_TICK_COUNT    = 0x31, /* INT for scrollbar */
				SET_TICK_POSITION = 0x32, /* INT for scrollbar */
				SET_LENGTH        = 0x33, /* max length: Edit Control */
				SET_X             = 0x34, /* INT new x position */
				SET_Y             = 0x35, /* INT new y position */
				SET_WIDTH         = 0x3D, /* INT new width */
				CHANGE_HUE        = 0x3F, /* BOOL for DlgFrame */
			};
		}
		typedef NMessageMsgSubtype::eMessageMsgSubtype eMessageMsgSubtype;

		namespace NMessageMsgFlag
		{
			enum eMessageMsgFlag
			{
				NONE  = 0,
				SHIFT = 1,
				CTRL  = 4,
				ALT   = 32,

				CTRL_SHIFT = CTRL | SHIFT,
				SHIFT_CTRL = CTRL_SHIFT,

				CTRL_ALT   = CTRL | ALT,
				ALT_CTRL   = CTRL_ALT,

				SHIFT_ALT  = SHIFT | ALT,
				ALT_SHIFT  = SHIFT_ALT,
			};
			_H3API_ENUM_OPERATORS_(eMessageMsgFlag, INT16);
		}
		typedef NMessageMsgFlag::eMessageMsgFlag eMessageMsgFlag;

	} /* namespace NH3Messages */
	typedef NH3Messages::eItemIDs        eControlId;
	typedef NH3Messages::eMessageCommand eMsgCommand;
	typedef NH3Messages::eMessageMsgSubtype eMsgSubtype;
	typedef NH3Messages::eMessageMsgFlag    eMsgFlag;
} /* namespace h3 */
