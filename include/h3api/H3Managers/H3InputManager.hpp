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
#include "h3api/H3Constants/H3CstVKey.hpp"

namespace h3
{
	_H3API_DECLARE_(InputManager);

#pragma pack(push, 4)

	// * keyboard and mouse input
	struct H3InputManager : public H3Manager
	{
		_H3API_SIZE_(0x960);
		_H3API_VTABLE_(0x63FE10);
		_H3API_GET_INFO_(0x6992D4, H3InputManager);

		struct InputMessages
		{
			UINT message;
			h3unk8 f_4[28]; // contents vary
		}
		/** @brief [38] see 0x4EC6B8 */
		messages[64];
		/** @brief [838] */
		INT32 currentMessage;
		/** @brief [83C] */
		INT32 nextMessage;
		BOOL32  addingMessage;

	protected:
		h3unk8  _f_844[260];
		h3unk32 _f_948;
		h3unk32 _f_94C;
		h3unk32 _f_950;
		h3unk32 _f_954;
		h3unk32 _f_958;
		h3unk32 _f_95C;
	public:
		_H3API_ InputMessages& GetCurrentMessage();
		/** @brief Adds a MC_MOUSE_OVER message to the message queue based on current position*/
		_H3API_ VOID AddMouseOverMessage();
	};
	_H3API_ASSERT_SIZE_(H3InputManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
