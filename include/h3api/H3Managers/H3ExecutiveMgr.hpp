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
	struct H3Manager;
	_H3API_DECLARE_(ExecutiveMgr);

#pragma pack(push, 4)
	/** @brief Chief Executive Officer of Managers*/
	struct H3ExecutiveMgr
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x699550, H3ExecutiveMgr);

		H3Manager* first_mgr;
		H3Manager* last_mgr;
		H3Manager* active_mgr;
	protected:
		h3unk32    _f_0C; // status?
	public:
		_H3API_ VOID RemoveManager(H3Manager* mgr);
		_H3API_ INT  AddManager(H3Manager* mgr, INT32 order);
		/**
		 * @brief Starts the specified manager, and removes it once it has run its course
		 * @param mgr Manager to be started
		 */
		_H3API_ VOID StartManager(H3Manager* mgr);
	};
	_H3API_ASSERT_SIZE_(H3ExecutiveMgr);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
