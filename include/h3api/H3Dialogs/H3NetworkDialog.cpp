//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3NetworkDialog.hpp"

namespace h3
{
	_H3API_ H3NetworkDlg::H3NetworkDlg(INT x, INT y, INT w, INT h) :
		H3ExtendedDlg(x, y, w, h), lastHintShowed(-1),
		exitCommand(512), exitSubtype(10), resultItemId(30721), networkGame(FALSE)
	{
		struct unkNetwork
		{
			h3unk _f_00[0xF0];
			BYTE* data;
		};
		if (IntAt(0x69959C))
		{
			unkNetwork* net = *(unkNetwork**)0x69D858;
			if (net->data)
			{
				if (net->data[4])
					networkGame = TRUE;
				net->data[4] = 1;
			}
		}
	}
} /* namespace h3 */
