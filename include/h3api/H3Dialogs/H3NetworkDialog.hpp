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

#pragma pack(push, 4)
	/** @brief cannot be used except as a pointer or reference*/
	struct _H3API_NOVTABLE_ H3NetworkDlg : H3ExtendedDlg
	{
		_H3API_SIZE_(0x60); // was 0x68 with 8 unknown bytes, seem only relevant to specialized dialogs
		_H3API_VTABLE_(0x63A6A8);
		_H3API_CTOR_DTOR_(0x41AFA0, 0x41B080);
	protected:
		/** @ brief [v38]*/
		_H3API_ virtual INT vEndDialogOnTimeExpired(H3Msg& msg) = 0;

		/** @ brief [4C]*/
		INT32 lastHintShowed;
		/** @ brief [50]*/
		INT32 exitCommand;
		/** @ brief [54]*/
		INT32 exitSubtype;
		/** @ brief [58]*/
		INT32 resultItemId;
		/** @ brief [5C]*/
		BOOL8 networkGame;
	public:
		_H3API_ H3NetworkDlg(INT x, INT y, INT w, INT h);
	};
	_H3API_ASSERT_SIZE_(H3NetworkDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
