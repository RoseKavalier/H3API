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
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_DECLARE_(QuestsText);

#pragma pack(push, 4)

	struct H3QuestsText
	{
		_H3API_GET_INFO_(0x56C72F + 2, H3QuestsText);

		struct
		{
		private:
			H3String m_unused[5];
		public:
			H3String text[44];
		private:
			H3String m_unused2;
		public:
			H3String deserted;
			H3String deadline;
		}variants[3];
	};

	_H3API_NAMED_STRUCT_(H3QuestsText, SeersText, 0x56C724 + 2);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
