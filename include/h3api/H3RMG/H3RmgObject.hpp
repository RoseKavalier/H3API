//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	struct H3RmgObjectPropsRef;

#pragma pack(push, 4)

	/**
	 * @brief A created object using RMG_ObjectGenerator
	 * original name: type_object
	 */
	struct H3RmgObject
	{
		_H3API_SIZE_(0x1C);

		/** @brief [00]*/
		struct VTable
		{
			h3func dtor;     // virtual dtor
			h3func unk;      // usually nullsub
			h3func someBool; // returns bool 1 most of the time
			h3func write;    // write to stream
		}*vTable;
		/** @brief [04]*/
		H3RmgObjectPropsRef* properties;
		/** @brief [08]*/
		H3Point             coordinates;
		/** @brief [14]*/
		h3unk32             _f_14;
		h3unk8              _f_18;

		_H3API_ h3func GetVTable() const;
	};
	_H3API_ASSERT_SIZE_(H3RmgObject);

	/**
	 * @brief Abstract class to generate objects, all other types inherit this
	 * original name: none, but most generators have type_object_def format
	 */
	struct H3RmgObjectGenerator
	{
		_H3API_SIZE_(0x14);
		struct VTable
		{
			h3func createObject;
			h3func getValue;
			h3func someBool;
		}*vTable;
		INT32   type;
		INT32   subtype;
		INT32   value;
		INT32   density;
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectGenerator);



#pragma pack(pop) /* align-4 */

} /* namespace h3 */
