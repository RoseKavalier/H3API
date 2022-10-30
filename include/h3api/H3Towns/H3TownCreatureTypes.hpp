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
	_H3API_DECLARE_(TownCreatureTypes);

#pragma pack(push, 4)

	struct H3TownCreatureTypes
	{
		_H3API_SIZE_(0x38);
		_H3API_GET_INFO_(0x6747B4, H3TownCreatureTypes);
		struct iterator
		{
		protected:
			INT32* m_base;
		public:
			_H3API_ iterator(INT32* base);

			_H3API_ iterator& operator*();
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ BOOL operator==(const iterator& other) const;
			_H3API_ BOOL operator!=(const iterator& other) const;

			_H3API_ INT32& Base();
			_H3API_ INT32& Upgraded();
		};

		INT32 base[7];
		INT32 upgrade[7];

		_H3API_ iterator begin();
		_H3API_ iterator end();
	};
	_H3API_ASSERT_SIZE_(H3TownCreatureTypes);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
