//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgHintBar.hpp"
#include "h3api/H3Dialogs/H3BaseDialog.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"

namespace h3
{
    _H3API_ VOID H3DlgHintBar::ShowHint(H3Msg* msg)
    {
        if (msg->command == eMsgCommand::MOUSE_OVER)
        {
            H3DlgItem* di = msg->ItemAtPosition(parent);
            if (di && di != lastHint)
            {
                lastHint = di;
                if (di->GetHint())
                    SetText(di->GetHint());
                else
                    SetText(h3_NullString);
                Draw();
                Refresh();
            }
        }
    }
    _H3API_ VOID H3DlgHintBar::ShowMessage(LPCSTR msg)
    {
        SetText(msg);
        Draw();
        Refresh();
    }
    _H3API_ H3DlgHintBar* H3DlgHintBar::Create(H3BaseDlg* dlg)
    {
        return H3DlgHintBar::Create(dlg, 8, dlg->GetHeight() - 26, dlg->GetWidth() - 16, 19);
    }
    _H3API_ H3DlgHintBar* H3DlgHintBar::Create(H3BaseDlg* dlg, INT32 x, INT32 y, INT32 w, INT32 h)
    {
        H3DlgHintBar* hint = H3ObjectAllocator<H3DlgHintBar>().allocate(1);
        if (hint == nullptr)
            return nullptr;
        THISCALL_12(H3DlgHintBar*, 0x5BCB70, hint, x, y, w, h, h3_NullString, NH3Dlg::Text::SMALL,
                    NH3Dlg::HDassets::HD_STATUSBAR_PCX, eTextColor::REGULAR, 0, eTextAlignment::MIDDLE_CENTER, 8);        
        hint->lastHint = nullptr;
        return hint;
    }
} /* namespace h3 */
