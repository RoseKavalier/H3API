//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgObject.hpp"

namespace h3
{
    _H3API_ h3func H3RmgObject::GetVTable() const
	{
		return h3func(vTable);
	}
} /* namespace h3 */
