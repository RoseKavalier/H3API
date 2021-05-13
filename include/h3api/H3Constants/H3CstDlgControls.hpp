//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-07              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
	namespace NH3DlgControls
	{
		namespace NType
		{
			enum eType : UINT16
			{
				TRANSPARENT_CTRL = 0x0001,
				SCROLL_CTRL      = 0x0001,
				BUTTON_CTRL      = 0x0002,
				TEXT_CTRL        = 0x0008,
				EDIT_CTRL        = 0x0008,
				DEF_CTRL         = 0x0010,
				FRAME_CTRL       = 0x0400,
				PCX_CTRL         = 0x0800,
			};
		}
		typedef NType::eType eType;

		namespace NState
		{
			enum eState : UINT16
			{
				PRESSED  = 0x0001, /* button is pressed */
				ACTIVE   = 0x0002, /* captures messages */
				VISIBLE  = 0x0004, /* is drawn */
				SHADED   = 0x0008, /* for pcx */
				SELECTED = 0x0010, /* for buttons */
				ENABLED  = 0x0020, /* item accepts user input */
				FOCUSED  = 0x0040,
			};
			_H3API_ENUM_OPERATORS_(eState, INT16);
		}
		typedef NState::eState eState;
	} /* namespace NH3DlgControls */
	typedef NH3DlgControls::eType  eControl;
	typedef NH3DlgControls::eState eControlState;
} /* namespace h3 */
