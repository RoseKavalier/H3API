//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3Resources.hpp"

namespace h3
{
	_H3API_ H3Resources::H3Resources() :
		wood(0),
		mercury(0),
		ore(0),
		sulfur(0),
		crystal(0),
		gems(0),
		gold(0)
	{
	}
	_H3API_ H3Resources::H3Resources(H3Resources const& other) :
		wood(other.wood),
		mercury(other.mercury),
		ore(other.ore),
		sulfur(other.sulfur),
		crystal(other.crystal),
		gems(other.gems),
		gold(other.gold)
	{
	}
	_H3API_ BOOL H3Resources::EnoughResources(const H3Resources& cost) const
	{
		return *this >= cost;
	}
	_H3API_ VOID H3Resources::RemoveResources(const H3Resources& cost)
	{
		operator-=(cost);
	}
	_H3API_ VOID H3Resources::GainResourcesOF(const H3Resources& gain)
	{
		operator+=(gain);
	}
	_H3API_ INT H3Resources::Count() const
	{
		INT r = 0;
		for (INT32 i = 0; i < 7; ++i)
			if (asArray[i] != 0)
				++r;
		return r;
	}
	_H3API_ PINT H3Resources::begin()
	{
		return asArray;
	}
	_H3API_ PINT H3Resources::end()
	{
		return &asArray[7];
	}
	_H3API_ PINT H3Resources::cbegin() const
	{
		return PINT(this);
	}
	_H3API_ PINT H3Resources::cend() const
	{
		return PINT(&asArray[7]);
	}
	_H3API_ H3Resources& H3Resources::operator+=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
			if (asArray[i] > 0) // positive
			{
				asArray[i] += other.asArray[i]; // add resources

				if (other.asArray[i] > 0) // check if there was overflow
				{
					if (asArray[i] <= 0)
						asArray[i] = INT_MAX;
				}
				else if (asArray[i] < 0) // no negative resources from subtraction
					asArray[i] = 0;
			}
			else // gain normally
				asArray[i] += other.asArray[i];
		return *this;
	}
	_H3API_ H3Resources& H3Resources::operator-=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
		{
			if (asArray[i] >= 0)
				asArray[i] = std::max(0, asArray[i] - other.asArray[i]);
			else
				asArray[i] -= other.asArray[i];
		}
		return *this;
	}
	_H3API_ H3Resources& H3Resources::operator=(const H3Resources& other)
	{
		for (INT32 i = 0; i < 7; ++i)
			asArray[i] = other.asArray[i];
		return *this;

	}
	_H3API_ BOOL H3Resources::operator>=(const H3Resources& other) const
	{
		return !(*this < other);
	}
	_H3API_ BOOL H3Resources::operator>(const H3Resources& other) const
	{
		return other < *this;
	}
	_H3API_ BOOL H3Resources::operator<(const H3Resources& other) const
	{
		for (INT32 i = 0; i < 7; ++i)
			if (other.asArray[i] > asArray[i])
				return TRUE;
		return FALSE;
	}
	_H3API_ BOOL H3Resources::operator<=(const H3Resources& other) const
	{
		return !(*this > other);
	}
	_H3API_ INT& H3Resources::operator[](INT32 index)
	{
		return asArray[index];
	}
} /* namespace h3 */
