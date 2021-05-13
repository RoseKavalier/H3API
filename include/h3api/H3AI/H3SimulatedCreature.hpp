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

namespace h3
{
	_H3API_DECLARE_(SimulatedCreature);
	typedef H3SimulatedCreature H3FastBattleCreature;

#pragma pack(push, 4)

	/** @brief A single creature stack in fast ai-ai battles*/
	struct H3SimulatedCreature
	{
		_H3API_SIZE_(0x48);
		INT32 count;
		INT32 type;
		INT32 num1;
		INT32 num2;
		INT32 speed;
	protected:
		DOUBLE f_14;
		DOUBLE f_1C;
		DOUBLE f_24;
		h3unk8 f_2C[4];
		h3unk8 f_30[4];
		h3unk8 f_34[4];
	public:
		INT32 turretPriority;
		INT32 unitPower;
		INT32 stackPower;
	protected:
		h3unk8 f_44[4];
	};
	_H3API_ASSERT_SIZE_(H3SimulatedCreature);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
