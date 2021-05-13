//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(TextFile);
	_H3API_TYPE_DECLARE_(H3TextFile, TextResource);

#pragma pack(push, 4)
	/** @brief text file with a single column of text. Original name TTextResource*/
	struct H3TextFile : public H3ResourceItem
	{
		_H3API_SIZE_(0x30);
	protected:
		/** @brief [1C] list of rows holding text, single column*/
		H3Vector<LPCSTR> text;
		/** @brief [2C] text read from file*/
		LPCSTR buffer;
	public:
		/**
		 * @brief Get the text from specified row
		 * @param row Using the index from TxtEdit
		 * @return text at specified row
		 */
		_H3API_ LPCSTR  GetText(UINT32 row) const;
		_H3API_ LPCSTR  GetText(UINT32 row);
		_H3API_ VOID    UnLoad();
		_H3API_ LPCSTR& operator[](UINT row);
		_H3API_ LPCSTR* begin();
		_H3API_ LPCSTR* end();

		_H3API_ static H3TextFile* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextFile);

	_H3API_NAMED_STRUCT_(H3TextFile, GeneralText,  0x6A5DC4);
	_H3API_NAMED_STRUCT_(H3TextFile, AdveventText, 0x696A68);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
