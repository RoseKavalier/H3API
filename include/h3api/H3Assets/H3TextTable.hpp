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
	_H3API_DECLARE_(TextTable);
	_H3API_TYPE_DECLARE_(H3TextTable, SpreadSheetResource);

#pragma pack(push, 4)

	/** @brief text file with several columns of text. Original name TSpreadSheetResource*/
	struct H3TextTable : public H3ResourceItem
	{
		_H3API_SIZE_(0x34);
		struct iterator
		{
		protected:
			H3Vector<LPCSTR>** data;
		public:
			_H3API_ iterator(H3Vector<LPCSTR>** vec);
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ H3Vector<LPCSTR>& operator*();
			_H3API_ H3Vector<LPCSTR>* operator->();
			_H3API_ LPCSTR operator[](UINT column);
			_H3API_ BOOL   operator==(const iterator& other);
			_H3API_ BOOL   operator!=(const iterator& other);
		};

	protected:
		/** @brief [1C] list of rows holding lists of column text*/
		H3Vector<H3Vector<LPCSTR>*> text;
		/** @brief [2C] read from lod*/
		LPCSTR buffer;
		/** @brief [30]*/
		UINT bufferSize;
	public:
		_H3API_ H3Vector<H3Vector<LPCSTR>*>& GetText();
		_H3API_ H3Vector<LPCSTR>& operator[](UINT row);
		_H3API_ UINT32   CountRows() const;
		_H3API_ VOID     UnLoad();
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ static H3TextTable* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextTable);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
