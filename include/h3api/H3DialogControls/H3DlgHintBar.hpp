//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3DialogControls/H3DlgTextPcx.hpp"

namespace h3
{
	class  H3DlgHintBar;
	struct H3BaseDlg;
	struct H3Msg;

#pragma pack(push, 4)
	/** @brief Custom dialog item that shows items's hints in a managed textpcx*/
	class H3DlgHintBar : public H3DlgTextPcx
	{
		H3DlgItem* lastHint;
		public:
		_H3API_ VOID   ShowHint(H3Msg* msg);
		_H3API_ VOID   ShowMessage(LPCSTR msg);
		_H3API_ static H3DlgHintBar* Create(H3BaseDlg* dlg);
		_H3API_ static H3DlgHintBar* Create(H3BaseDlg* dlg, INT32 x, INT32 y, INT32 w, INT32 h);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
