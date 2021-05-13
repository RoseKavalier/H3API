//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3TownAlignmentDlg.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"

namespace h3
{
	_H3API_ H3TownAlignmentDlg::H3TownAlignmentDlg(INT32 town)
	{
		//TODO check the exact meaning of the 0/1 flag
		THISCALL_2(H3TownAlignmentDlg&, CONSTRUCTOR, this, 1);
		INT32 frame = 2 * town + 2;
		H3DefLoader def(NH3Dlg::Assets::TOWN_SMALL);
		THISCALL_4(BOOL8, 0x5761C0, this, *def, frame, town);
		THISCALL_2(VOID, vtable->runDlg, this, 0); // no fade-in
	}
	_H3API_ H3TownAlignmentDlg::~H3TownAlignmentDlg()
	{
		THISCALL_1(VOID, DESTRUCTOR, this);
	}
} /* namespace h3 */
