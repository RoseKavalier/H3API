//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3MouseManager.hpp"

namespace h3
{
	_H3API_ VOID H3MouseManager::operator=(const Cursor& cursor)
	{
		SetCursor(cursor);
	}
	_H3API_ VOID H3MouseManager::TurnOn()
	{
		THISCALL_2(VOID, 0x50D7B0, this, 1);
	}
	_H3API_ VOID H3MouseManager::TurnOff()
	{
		THISCALL_2(VOID, 0x50D7B0, this, 0);
	}
	_H3API_ INT32 H3MouseManager::GetType() const
	{
		return cursorType;
	}
	_H3API_ INT32 H3MouseManager::GetFrame() const
	{
		return cursorFrame;
	}
	_H3API_ VOID H3MouseManager::SetCursor(INT32 frame, INT32 type)
	{
		THISCALL_3(VOID, 0x50CEA0, this, frame, type);
	}
	_H3API_ VOID H3MouseManager::SetCursor(const Cursor& cursor)
	{
		SetCursor(cursor.frame, cursor.type);
	}
	_H3API_ VOID H3MouseManager::SetCursor(INT32 frame, eCursor type)
	{
		THISCALL_3(VOID, 0x50CEA0, this, frame, type);
	}
	_H3API_ VOID H3MouseManager::DefaultCursor()
	{
		SetCursor(0, 0);
	}
	_H3API_ VOID H3MouseManager::SetArtifactCursor(INT32 art_id)
	{
		SetCursor(art_id, eCursor::ARTIFACT);
	}
	_H3API_ H3MouseManager::Cursor H3MouseManager::CurrentCursor() const
	{
		Cursor cursor;
		cursor.type = cursorType;
		cursor.frame = cursorFrame;
		return cursor;
	}

} /* namespace h3 */
