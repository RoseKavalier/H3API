//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3CombatDlg.hpp"

namespace h3
{
	_H3API_ VOID H3CombatDlg::ShowHint(LPCSTR hint, BOOL8 add_to_log)
	{
		THISCALL_4(VOID, 0x4729D0, this, hint, add_to_log, 0);
	}
	_H3API_ H3Vector<H3String*>& H3CombatDlg::GetCombatText()
	{
		return combatText;
	}
} /* namespace h3 */
