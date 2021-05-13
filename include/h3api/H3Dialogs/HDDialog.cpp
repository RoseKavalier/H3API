//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/HDDialog.hpp"

namespace h3
{
	_H3API_ INT HDDlg::CallHDProc(const H3Msg& msg)
	{
		return hdProc(this, msg);
	}
} /* namespace h3 */
