//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgEdit.hpp"

namespace h3
{
    _H3API_ H3DlgEdit* H3DlgEdit::Create(INT32 x, INT32 y, INT32 width, INT32 height,
                INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align,
                LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY)
    {
        H3DlgEdit* e = H3ObjectAllocator<H3DlgEdit>().allocate(1);
        if (e)
            THISCALL_17(H3DlgEdit*, 0x5BACD0, e, x, y, width, height, maxLength, text,
                fontName, color, align, pcxName, 0, id, 0, hasBorder, borderX, borderY);
        return e;
    }
    _H3API_ LPCSTR H3DlgEdit::GetText() const
    {
        return text.String();
    }
    _H3API_ H3String* H3DlgEdit::GetString()
    {
        return &text;
    }
    _H3API_ VOID H3DlgEdit::SetText(LPCSTR text)
    {
        vSetText(text);
    }
    _H3API_ VOID H3DlgEdit::DecreaseCaret()
    {
        if (caretPos > 0)
            --caretPos;
    }
    _H3API_ VOID H3DlgEdit::IncreaseCaret()
    {
        if (caretPos < text.Length())
            ++caretPos;
    }
    _H3API_ UINT H3DlgEdit::GetCaret() const
    {
        return caretPos;
    }
    _H3API_ BOOL H3DlgEdit::SetCaret(UINT pos)
    {
        if (pos == caretPos || pos > text.Length())
            return FALSE;
        caretPos = pos;
        return TRUE;
    }
    _H3API_ VOID H3DlgEdit::SetAutoredraw(BOOL on)
    {
        autoRedraw = on;
    }
    _H3API_ VOID H3DlgEdit::SetFocus(BOOL on)
    {
        vSetFocus(on);
    }
} /* namespace h3 */
