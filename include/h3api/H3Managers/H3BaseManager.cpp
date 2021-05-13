//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3BaseManager.hpp"

namespace h3
{

	_H3API_ INT32 H3Manager::Start(INT32 z_order)
	{
		return THISCALL_2(INT32, vtable->start, this, z_order);
	}
	_H3API_ VOID H3Manager::Stop()
	{
		THISCALL_1(VOID, vtable->stop, this);
	}
	_H3API_ INT32 H3Manager::ProcessMessage(H3Msg& msg)
	{
		return THISCALL_2(INT32, vtable->processMessage, this, &msg);
	}
	_H3API_ VOID H3Manager::SetPreviousManager(H3Manager* prev)
	{
		parent = prev;
	}
	_H3API_ VOID H3Manager::SetNextManager(H3Manager* next)
	{
		child = next;
	}
} /* namespace h3 */
