//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(MagicAnimation);

#pragma pack(push, 4)

	struct H3MagicAnimation
	{
		_H3API_SIZE_(0x0C);
		_H3API_GET_INFO_(0x43F77B + 3, H3MagicAnimation);

		LPCSTR defName;
		LPCSTR name;
		INT32 type;

		/**
		 * @brief Get spell effect animation info by spell id.
		 * @param spellId which spell
		 * @return if anim does not exist return nullptr
		 */
		_H3API_ static H3MagicAnimation* GetAnim(INT32 spellId);
	};
	_H3API_ASSERT_SIZE_(H3MagicAnimation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
