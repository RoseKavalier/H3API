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

namespace h3
{
	_H3API_DECLARE_(Manager);
	struct H3Msg;

#pragma pack(push, 4)

	/* likely known as BASEMANAGER in source */
	struct H3Manager : public H3Uncopyable
	{
		_H3API_SIZE_(0x38);
		_H3API_CTOR_DTOR_(0x44D200, -1);

		enum eType : INT32
		{
			BASE_MANAGER      = -1,
			INPUT_MANAGER     = 0x4,
			SOUND_MANAGER     = 0x10,
			WINDOW_MANAGER    = 0x20,
			MOUSE_MANAGER     = 0x40,
			SWAP_MANAGER      = 0x100,
			COMBAT_MANAGER    = 0x200,
			ADVENTURE_MANAGER = 0x400,
			TOWN_MANAGER      = 0x800,
			RECRUIT_MANAGER   = 0x4000,
		};

		enum eStatus : INT32
		{
			DESTROYED = 0,
			ACTIVE    = 1,
			DISABLED  = 2,
		};

		struct ManagerVTable
		{
			h3func start;
			h3func stop;
			h3func processMessage;
			/* extra method for MouseMgr (virtual dtor) */
		};
	protected:
		/** @brief [00] virtual table. Use Start(), Stop() or ProcessMessage() to access it*/
		ManagerVTable *vtable;
	public:
		/**
		 * @brief [v00] constructs associated dialog and loads manager-specifics
		 * @param z_order where to insert dialog
		 * @return status? SwapMgr -> 0
		*/
		_H3API_ INT32 Start(INT32 z_order);
		/** @brief [v04] Destructor for associated dialog and unloads manager-specifics*/
		_H3API_ VOID  Stop();
		/**
		 * @brief [v08] Process the current message and pass it along to other managers as required
		 * @param msg Current thread message
		 * @return 0..2 => 0 (continue?) 1 (done?) 2 (close, with mgr-specific messages)
		*/
		_H3API_ INT32 ProcessMessage(H3Msg& msg);

		/** @brief [04] previous manager*/
		H3Manager* parent;
		/** @brief [08] next manager*/
		H3Manager* child;
		/** @brief [0C]*/
		eType      type;
		/** @brief [10]*/
		INT32      zOrder;
		/** @brief [14]*/
		CHAR       name[28];
		/** @brief [30]*/
		INT32      nameEnd;
		/** @brief [34]*/
		eStatus    status;

		_H3API_ VOID SetPreviousManager(H3Manager* prev);
		_H3API_ VOID SetNextManager(H3Manager* next);
	};
	_H3API_ASSERT_SIZE_(H3Manager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
