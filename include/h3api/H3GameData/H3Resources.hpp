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
#include "h3api/H3Constants/H3CstResources.hpp"

namespace h3
{
	_H3API_DECLARE_(Resources);

#pragma pack(push, 4)

	// * An "array" representing the 7 resources
	struct H3Resources
	{
		_H3API_SIZE_(0x1C);

		union
		{
			struct
			{
				INT32 wood;
				INT32 mercury;
				INT32 ore;
				INT32 sulfur;
				INT32 crystal;
				INT32 gems;
				INT32 gold;
			};
			INT32 asArray[7];
		};

		_H3API_ H3Resources();
		_H3API_ H3Resources(H3Resources const& other);
		// * compares current values against cost
		// * returns true if every current value is greater or equal
		_H3API_ BOOL EnoughResources(const H3Resources& cost) const;
		// * removes cost resources from current
		// * checks for negative overflow!
		_H3API_ VOID RemoveResources(const H3Resources& cost);
		// * adds resources to current
		// * checks for overflow!
		_H3API_ VOID GainResourcesOF(const H3Resources& gain);
		// * Number of non-zero resources
		_H3API_ INT Count() const;
		_H3API_ PINT begin();
		_H3API_ PINT end();
		_H3API_ PINT cbegin() const;
		_H3API_ PINT cend() const;
		// * checks for overflow
		_H3API_ H3Resources& operator+=(const H3Resources& other);
		// * checks for overflow
		_H3API_ H3Resources& operator-=(const H3Resources& other);
		// * does not check for overflow
		_H3API_ H3Resources& operator=(const H3Resources& other);
		_H3API_ BOOL operator>=(const H3Resources& other) const;
		_H3API_ BOOL operator>(const H3Resources& other) const;
		_H3API_ BOOL operator<(const H3Resources& other) const;
		_H3API_ BOOL operator<=(const H3Resources& other) const;
		_H3API_ INT& operator[](INT32 index);
	};
	_H3API_ASSERT_SIZE_(H3Resources);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
