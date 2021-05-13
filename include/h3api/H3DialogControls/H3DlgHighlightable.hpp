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
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Assets/H3Pixels.hpp"

namespace h3
{
	class H3DlgHighlightable;

	struct H3DlgItem;
	struct H3Msg;

#pragma pack(push, 4)

	/** @brief custom class that manages a list of items and draws a contour around them*/
	class H3DlgHighlightable
	{
	protected:
		struct Highlighter
		{
			H3DlgItem* m_item;
			H3ARGB888  m_highlight;
			UINT       m_thickness;
			_H3API_ Highlighter();
			_H3API_ Highlighter(H3DlgItem* item, const H3ARGB888& color, UINT thickness);
			_H3API_ Highlighter(H3DlgItem* item, BYTE r, BYTE g, BYTE b, UINT thickness);
		};

		H3Vector<Highlighter> m_highlightableItems;
		mutable H3DlgItem* m_currentHighlight;
		_H3API_ BOOL unhighlightSelection() const;
	public:
		_H3API_ H3DlgHighlightable();
		_H3API_ VOID AddItem(H3DlgItem* dlgItem, BYTE red, BYTE green, BYTE blue, UINT frame_thickness);
		_H3API_ VOID AddItem(H3DlgItem* dlgItem, const H3ARGB888& color, UINT frame_thickness);
		_H3API_ BOOL HighlightItem(H3DlgItem* dlgItem) const;
		_H3API_ BOOL HighlightItem(const H3Msg& msg) const;
		_H3API_ VOID Clear();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
