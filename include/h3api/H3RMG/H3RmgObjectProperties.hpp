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

#pragma pack(push, 4)

	/** @brief similar to H3ObjectAttributes but not same order*/
	struct H3RmgObjectProperties
	{
		_H3API_SIZE_(0x4C);
		INT32        defNumber;   /**< @brief [00]*/
		H3ObjectMask passable;    /**< @brief [04]*/
		H3ObjectMask enterable;   /**< @brief [0C]*/
		H3Bitfield   land;        /**< @brief [14]*/
		H3Bitfield   landpage;    /**< @brief [18]*/
		INT32        type;        /**< @brief [1C]*/
		INT32        subtype;     /**< @brief [20]*/
		INT32        page;        /**< @brief [24]*/
		BOOL8        flat;        /**< @brief [28]*/
		BOOL8        hasEntrance; /**< @brief [29]*/
		INT32        enterX;      /**< @brief [2C]*/
		INT32        enterY;      /**< @brief [30]*/
		INT32        width;       /**< @brief [34]*/
		INT32        height;      /**< @brief [38]*/
		H3ObjectMask colors;      /**< @brief [3C]*/
		H3ObjectMask shadows;     /**< @brief [44]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectProperties);

	struct H3RmgObjectPropsRef // size E8
	{
		_H3API_SIZE_(0xE8);
		H3RmgObjectProperties* prototype;		 /**< @brief [00]*/
		h3unk32          _f_4;			 /**< @brief [04]*/
		UINT32           refCount;		 /**< @brief [08]*/
		INT32            prototypeIndex; /**< @brief [0C]*/
		// ...
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
