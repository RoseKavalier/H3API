//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgHighlightable.hpp"
#include "h3api/H3DialogControls/H3DlgItem.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"

namespace h3
{
    _H3API_ BOOL H3DlgHighlightable::unhighlightSelection() const
	{
		if (m_currentHighlight)
		{
			m_currentHighlight->Draw();
			m_currentHighlight->Refresh();
			m_currentHighlight = nullptr;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ H3DlgHighlightable::H3DlgHighlightable() :
		m_currentHighlight()
	{
	}
	_H3API_ VOID H3DlgHighlightable::AddItem(H3DlgItem* dlgItem, BYTE red,
        BYTE green, BYTE blue, UINT frame_thickness)
	{
		AddItem(dlgItem, H3ARGB888(red, green, blue), frame_thickness);
	}
	_H3API_ VOID H3DlgHighlightable::AddItem(H3DlgItem* dlgItem, const H3ARGB888& color, UINT frame_thickness)
	{
		Highlighter highlight(dlgItem, color, frame_thickness);
		m_highlightableItems += highlight;
	}
	_H3API_ BOOL H3DlgHighlightable::HighlightItem(H3DlgItem* dlgItem) const
	{
		if (!dlgItem)
			return unhighlightSelection();

        if (dlgItem == m_currentHighlight)
            return FALSE;
        unhighlightSelection();
        for (Highlighter* it = m_highlightableItems.begin(); it != m_highlightableItems.end(); ++it)
        {
            if (it->m_item == dlgItem)
            {
                it->m_item->DrawTempFrame(it->m_thickness, it->m_highlight);
                it->m_item->Refresh();
                m_currentHighlight = it->m_item;
                return TRUE;
            }
        }

		return FALSE;
	}
	_H3API_ BOOL H3DlgHighlightable::HighlightItem(const H3Msg& msg) const
	{
		if (m_highlightableItems.IsEmpty())
			return FALSE;
		if (!msg.IsMouseOver())
			return FALSE;
		return HighlightItem(msg.ItemAtPosition(m_highlightableItems[0].m_item->GetParent()));
	}
	_H3API_ VOID H3DlgHighlightable::Clear()
	{
		m_currentHighlight = nullptr;
		m_highlightableItems.RemoveAll();
	}
	H3DlgHighlightable::Highlighter::Highlighter() :
		m_item(), m_highlight(), m_thickness()
	{
	}
	_H3API_ H3DlgHighlightable::Highlighter::Highlighter(H3DlgItem* item, const H3ARGB888& color, UINT thickness) :
		m_item(item), m_highlight(color), m_thickness(thickness)
	{
	}
	_H3API_ H3DlgHighlightable::Highlighter::Highlighter(H3DlgItem* item, BYTE r, BYTE g, BYTE b, UINT thickness) :
		m_item(item), m_highlight(r, g, b), m_thickness(thickness)
	{
	}
} /* namespace h3 */
