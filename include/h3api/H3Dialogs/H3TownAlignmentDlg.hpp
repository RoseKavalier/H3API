//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Dialogs/H3BaseDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(TownAlignmentDlg);

#pragma pack(push, 4)

	/**
	 * @brief Shows creatures associated to current town
	 *
	 */
	struct H3TownAlignmentDlg : H3Allocator
	{
		_H3API_SIZE_(0x58);
		_H3API_VTABLE_(0x641AA0);
		_H3API_CTOR_DTOR_(0x5761A0, 0x48FA10);
	private:
		/**
		 * @brief same as H3BaseDlg but functionality not needed,
		 * just makes the dialog allowed to be built on stack without custom vtable
		*/
		H3DlgVTable* vtable;
		h3align      data[H3BaseDlg::SIZE - 4]; // -4 for vtable
		h3unk32      _f_4C;
		h3unk32      _f_50;
		BOOL8        isCampaign; // random guess
	public:
		_H3API_ H3TownAlignmentDlg(INT32 town);
		_H3API_ ~H3TownAlignmentDlg();
	};
	_H3API_ASSERT_SIZE_(H3TownAlignmentDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
