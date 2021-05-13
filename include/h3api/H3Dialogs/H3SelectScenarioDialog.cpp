//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3SelectScenarioDialog.hpp"

namespace h3
{
	_H3API_ H3ScenarioMapInformation& H3SelectScenarioDialog::CurrentMap()
	{
		return mapsInformation[selectedMapIndex];
	}
	_H3API_ VOID H3SelectScenarioDialog::UpdateForSelectedScenario(INT32 index, BOOL8 redraw)
	{
		THISCALL_3(VOID, 0x5857D0, this, index, redraw);
	}
	_H3API_ VOID H3SelectScenarioDialog::Redraw()
	{
		THISCALL_1(VOID, 0x584820, this);
	}
} /* namespace h3 */
