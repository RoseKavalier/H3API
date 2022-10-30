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
#include "h3api/H3Containers/H3Set.hpp"

namespace h3
{
	_H3API_DECLARE_(ResourceManager);
	struct H3ResourceItem;

#pragma pack(push, 4)

	struct H3ResourceItemData
	{
		_H3API_SIZE_(0x14);
		CHAR            m_name[12];
		UINT            m_nameEnd;
		H3ResourceItem* m_item;

		_H3API_ H3ResourceItemData(LPCSTR name);
		_H3API_ BOOL8 operator<(const H3ResourceItemData& other) const;
	};
	_H3API_ASSERT_SIZE_(H3ResourceItemData);

	// * a binary tree to hold game assets
	struct H3ResourceManager : H3Set<H3ResourceItemData, 0x69E604>
	{
		_H3API_GET_INFO_(0x69E560, H3ResourceManager);

		_H3API_ Node* FindItem(LPCSTR name);
		_H3API_ VOID  AddItem(H3ResourceItem* item);
		_H3API_ VOID  RemoveItem(Node* node);
		_H3API_ VOID  RemoveItem(const iterator& iter);
		_H3API_ VOID  RemoveItem(LPCSTR name);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
