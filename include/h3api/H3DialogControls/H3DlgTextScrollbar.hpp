//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3DialogControls/H3DlgScrollbar.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgTextScrollbar);
	struct H3DlgScrollableText;

#pragma pack(push, 4)
	/** @brief automatically created for scrollable text*/
	struct H3DlgTextScrollbar : public H3DlgScrollbar
	{
		_H3API_SIZE_(0x6C);
		_H3API_VTABLE_(0x642CD8);
	protected:
		/** @brief [68]*/
		H3DlgScrollableText* owner;
	public:

	};
	_H3API_ASSERT_SIZE_(H3DlgTextScrollbar);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
