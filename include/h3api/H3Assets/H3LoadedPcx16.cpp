//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3LoadedPcx16.hpp"
#include "h3api/H3Assets/H3LoadedPcx.hpp"
#include "h3api/H3Assets/H3Palette565.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"
#include "h3api/H3Assets/H3DefFrame.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"

namespace h3
{
    _H3API_ VOID H3LoadedPcx16::CopyRegion(H3LoadedPcx16* source, INT x, INT y)
    {
        THISCALL_7(VOID, 0x44E0C0, this, source->buffer, x, y, source->width, source->height, source->scanlineSize);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Construct(LPCSTR name, INT width, INT height)
    {
        return THISCALL_4(H3LoadedPcx16*, 0x44DD20, this, name, width, height);
    }
    _H3API_ VOID H3LoadedPcx16::DrawToPcx16(INT x, INT y, BOOL transparent, H3LoadedPcx16* dest, INT srcX, INT srcY)
    {
        return THISCALL_12(VOID, 0x44DF80, this, srcX, srcY, width, height, dest->buffer, x, y, dest->width, dest->height, dest->scanlineSize, transparent);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedPcx16*, 0x55B1E0, name);
    }
    _H3API_ H3LoadedPcx16* H3LoadedPcx16::Create(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx16* pcx16 = H3ObjectAllocator<H3LoadedPcx16>().allocate(1);
        if (!pcx16)
            return nullptr;
        return pcx16->Construct(name, width, height);
    }
	_H3API_ H3LoadedPcx16* H3LoadedPcx16::Create(INT width, INT height)
	{
        return Create(h3_NullString, width, height);
	}
	_H3API_ VOID H3LoadedPcx16::Destroy(BOOL destroy_buffer)
    {
        THISCALL_2(VOID, 0x44DCF0, this, destroy_buffer);
    }
    _H3API_ VOID H3LoadedPcx16::DrawShadow(INT x, INT y, INT dw, INT dh)
    {
        THISCALL_5(VOID, 0x44E2C0, this, x, y, dw, dh);
    }
    _H3API_ VOID H3LoadedPcx16::FillRectangle(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT _w = std::min(w, width - x);
        INT _h = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888 color(r, g, b);
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < _h; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    *rgb = color;

                rgb_row = reinterpret_cast<H3ARGB888*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;
            H3RGB565 color(r, g, b);
            for (int j = 0; j < _h; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->SetBits(color.GetBits());

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::FillRectangle(INT x, INT y, INT w, INT h, DWORD color)
    {
        FillRectangle(x, y, w, h, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    }
    _H3API_ VOID H3LoadedPcx16::DrawFrame(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b)
    {
        DrawThickFrame(x, y, w, h, 1, r, g, b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawFrame(INT x, INT y, INT w, INT h, const H3RGB888& color)
    {
        DrawFrame(x, y, w, h, color.r, color.g, color.b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, BYTE r, BYTE g, BYTE b)
    {
        FillRectangle(x, y, w, thickness, r, g, b);
        FillRectangle(x, y + thickness, thickness, h - thickness - thickness, r, g, b);
        FillRectangle(x + w - thickness, y + thickness, thickness, h - thickness - thickness, r, g, b);
        FillRectangle(x, y + h - thickness, w, thickness, r, g, b);
    }
    _H3API_ VOID H3LoadedPcx16::DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, const H3RGB888& color)
    {
        DrawThickFrame(x, y, w, h, thickness, color.r, color.g, color.b);
    }
    _H3API_ VOID H3LoadedPcx16::DarkenArea(INT x, INT y, INT w, INT h, UINT8 amount)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT w_ = std::min(w, width - x);
        INT h_ = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < h_; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Darken(amount);

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < h_; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Darken(amount);

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::LightenArea(INT x, INT y, INT w, INT h, UINT8 amount)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT w_ = std::min(w, width - x);
        INT h_ = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < h_; ++j)
            {
                H3ARGB888* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Lighten(amount);

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < h_; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < w_; ++i, ++rgb)
                    rgb->Lighten(amount);

                rgb_row = reinterpret_cast<H3RGB565*>(PUINT8(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::GrayScaleArea(INT x, INT y, INT w, INT h)
    {
        if (x >= width || x < 0 || y >= height || y < 0 || !buffer)
            return;
        INT _w = std::min(w, width - x);
        INT _h = std::min(h, height - y);

        if (H3BitMode::Get() == 4) // RGB888 mode
        {
            H3ARGB888* rgb_row = reinterpret_cast<H3ARGB888*>(GetRow(y));
            rgb_row += x;
            for (int j = 0; j < _h; ++j)
            {
                H3ARGB888* rgb = rgb_row;
                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->GrayScale();

                rgb_row += width;
            }
        }
        else // RGB565 mode
        {
            H3RGB565* rgb_row = reinterpret_cast<H3RGB565*>(GetRow(y));
            rgb_row += x;

            for (int j = 0; j < _h; ++j)
            {
                H3RGB565* rgb = rgb_row;

                for (int i = 0; i < _w; ++i, ++rgb)
                    rgb->GrayScale();

                rgb_row = reinterpret_cast<H3RGB565*>(reinterpret_cast<PUINT8>(rgb_row) + scanlineSize);
            }
        }
    }
    _H3API_ VOID H3LoadedPcx16::AdjustHueSaturation(INT x, INT y, INT w, INT h, FLOAT hue, FLOAT saturation)
    {
        THISCALL_7(VOID, 0x44E610, this, x, y, w, h, hue, saturation);
    }
    _H3API_ BOOL H3LoadedPcx16::BackgroundRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL is_blue)
    {
        H3PcxLoader back(is_blue ? NH3Dlg::HDassets::DLGBLUEBACK : NH3Dlg::Assets::DIBOXBACK);

        if (back.Get() == nullptr)
            return FALSE;

        int _y = y;
        int _h = h;

        // * add background region
        while (_h > 0)
        {
            int _x = x;
            int dh = std::min(256, _h);
            int _w = w;
            while (_w > 0)
            {
                back.Get()->DrawToPcx16(0, 0, _w, dh, this, _x, _y, FALSE);
                _x += 256;
                _w -= 256;
            }
            _y += 256;
            _h -= 256;
        }

        return TRUE;
    }
    _H3API_ BOOL H3LoadedPcx16::SimpleFrameRegion(INT32 x, INT32 y, INT32 _width, INT32 _height)
    {
        INT32 dX = _width;
        INT32 dY = _height;
        INT32 xEnd = x + _width;
        INT32 yEnd = y + _height;
        if (dX < 4 || dY < 4)
            return FALSE;

        // * helper struct
        struct Frames
        {
            enum
            {
                up,
                down,
                left,
                right,
                tl,
                tr,
                bl,
                br
            };

            H3PcxLoader m_up;
            H3PcxLoader m_down;
            H3PcxLoader m_left;
            H3PcxLoader m_right;
            H3PcxLoader m_tl;
            H3PcxLoader m_tr;
            H3PcxLoader m_bl;
            H3PcxLoader m_br;
            H3LoadedPcx16* m_tgt;

            Frames(H3LoadedPcx16* bg) :
                m_tgt(bg),
                m_up(NH3Dlg::HDassets::FRAME_U),
                m_down(NH3Dlg::HDassets::FRAME_D),
                m_left(NH3Dlg::HDassets::FRAME_L),
                m_right(NH3Dlg::HDassets::FRAME_R),
                m_tl(NH3Dlg::HDassets::FRAME_LU),
                m_tr(NH3Dlg::HDassets::FRAME_RU),
                m_bl(NH3Dlg::HDassets::FRAME_LD),
                m_br(NH3Dlg::HDassets::FRAME_RD)
            {
            }

            H3PcxLoader* begin() { return &m_up; }
            H3PcxLoader* end() { return &begin()[8]; }

            BOOL AllLoaded()
            {
                for (int i = 0; i < 8; ++i)
                    if (begin()[i].Get() == nullptr)
                        return FALSE;
                return TRUE;
            }

            VOID Draw(const INT x, const INT y, const INT frame)
            {
                begin()[frame].Get()->DrawToPcx16(0, 0, 4, 4, m_tgt, x, y, FALSE);
            }
        };

        Frames frames(this);
        if (!frames.AllLoaded())
            return FALSE;

        ////////////////////////////////////////
        // do horizontal sides - bottom to top
        ////////////////////////////////////////
        while (dX >= 4)
        {
            dX -= 4;
            frames.Draw(x + dX, y, frames.up);
            frames.Draw(x + dX, yEnd - 4, frames.down);
        }

        ////////////////////////////////////////
        // do vertical sides - right to left
        ////////////////////////////////////////
        while (dY >= 4)
        {
            dY -= 4;
            frames.Draw(x, y + dY, frames.left);
            frames.Draw(xEnd - 4, y + dY, frames.right);
        }

        ////////////////////
        // Add corners
        ////////////////////
        frames.Draw(x, y, frames.tl);
        frames.Draw(x, yEnd - 4, frames.bl);
        frames.Draw(xEnd - 4, y, frames.tr);
        frames.Draw(xEnd - 4, yEnd - 4, frames.br);

        return TRUE;
    }
    _H3API_ BOOL H3LoadedPcx16::FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
    {
        enum BoxFrames
        {
            BF_tl,
            BF_tr,
            BF_bl,
            BF_br,
            BF_ml,
            BF_mr,
            BF_tm,
            BF_bm,
            BF_blstat,
            BF_brstat,
            BF_bmstat
        };

        H3DefLoader box(is_blue ? NH3Dlg::HDassets::DLGBLUEBOX : NH3Dlg::Assets::DLGBOX);

        if (box.Get() == nullptr)
            return FALSE;

        // * copying to this local palette prevents recoloration of def for others
        H3BasePalette565 pal565;
        H3Palette565* pal;
        if (!is_blue)
        {
            pal565.CopyPalette(*box->palette565);
            pal565.ColorToPlayer(colorIndex);
            pal = PH3Palette565(&pal565);
        }
        else
            pal = box->palette565;

        INT f_bl, f_br, f_bm;
        if (statusBar)
        {
            f_bl = BoxFrames::BF_blstat;
            f_br = BoxFrames::BF_brstat;
            f_bm = BoxFrames::BF_bmstat;
        }
        else
        {
            f_bl = BoxFrames::BF_bl;
            f_br = BoxFrames::BF_br;
            f_bm = BoxFrames::BF_bm;
        }

        // * add horizontal bars
        int _w = w - 64 - 64;
        H3DefFrame* tm = box->GetGroupFrame(0, BoxFrames::BF_tm);
        H3DefFrame* bm = box->GetGroupFrame(0, f_bm);
        while (_w > 0)
        {
            tm->DrawToPcx16(0, 0, 64, 64, this, x + _w, y, pal);
            bm->DrawToPcx16(0, 0, 64, 64, this, x + _w, y + h - 64, pal);
            _w -= 64;
        }

        // * add vertical bars
        int _h = h - 64 - 64;
        H3DefFrame* ml = box->GetGroupFrame(0, BoxFrames::BF_ml);
        H3DefFrame* mr = box->GetGroupFrame(0, BoxFrames::BF_mr);
        while (_h > 0)
        {
            ml->DrawToPcx16(0, 0, 64, 64, this, x, y + _h, pal);
            mr->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y + _h, pal);
            _h -= 64;
        }

        // * add four corners
        box->GetGroupFrame(0, BoxFrames::BF_tl)->DrawToPcx16(0, 0, 64, 64, this, x, y, pal);
        box->GetGroupFrame(0, BoxFrames::BF_tr)->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y, pal);
        box->GetGroupFrame(0, f_bl)->DrawToPcx16(0, 0, 64, 64, this, x, y + h - 64, pal);
        box->GetGroupFrame(0, f_br)->DrawToPcx16(0, 0, 64, 64, this, x + w - 64, y + h - 64, pal);

        return TRUE;
    }
    _H3API_ VOID H3LoadedPcx16::SinkArea(INT32 x, INT32 y, INT32 w, INT32 h)
    {
        // * at the very minimum, we're gonna want to shade a 3x3 rectangle
        // * border to have 1 pixel within
        if (x >= width - 2 || y >= height - 2 || w <= 2 || h <= 2)
            return;
        int _x = std::max(x, 0);
        int _y = std::max(y, 0);
        int _w = std::min(w, width - _x);
        int _h = std::min(h, height - _y);

        DarkenArea(_x, _y, _w - 1, 1, 50);
        DarkenArea(_x, _y + 1, 1, _h - 2, 50);
        LightenArea(_x + 1, _y + _h - 1, _w - 1, 1, 50);
        LightenArea(_x + _w - 1, _y + 1, 1, _h - 2, 50);
    }
    _H3API_ VOID H3LoadedPcx16::BevelArea(INT32 x, INT32 y, INT32 w, INT32 h)
    {
        // * at the very minimum, we're gonna want to shade a 3x3 rectangle
        // * border to have 1 pixel within
        if (x >= width - 2 || y >= height - 2 || w <= 2 || h <= 2)
            return;
        int _x = std::max(x, 0);
        int _y = std::max(y, 0);
        int _w = std::min(w, width - _x);
        int _h = std::min(h, height - _y);

        LightenArea(_x, _y, _w, 1, 50);
        LightenArea(_x, _y + 1, 1, _y + _h - 2, 50);
        DarkenArea(_x + 1, _y + _h - 1, _w - 1, 1, 50);
        DarkenArea(_x + _w, _y + 1, 1, _h - 2, 50);
    }
    _H3API_ VOID H3LoadedPcx16::TextDraw(H3Font* font, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, eTextColor colorIndex, eTextAlignment alignment)
    {
        THISCALL_10(VOID, 0x4B51F0, font, text, this, x, y, width, height, colorIndex, alignment, -1);
    }
    _H3API_ PUINT8 H3LoadedPcx16::GetRow(int row)
    {
        return buffer + row * scanlineSize;
    }
    _H3API_ H3RGB565* H3LoadedPcx16::GetPixel565(int x, int y)
    {
        return (H3RGB565*)GetRow(y) + x;
    }
    _H3API_ H3ARGB888* H3LoadedPcx16::GetPixel888(int x, int y)
    {
        return (H3ARGB888*)GetRow(y) + x;
    }
    _H3API_ H3ARGB888 H3LoadedPcx16::GetPixel(int x, int y)
    {
        if (H3BitMode::Get() == 4)
            return *GetPixel888(x, y);
        else
            return H3ARGB888(*GetPixel565(x, y));
    }
    _H3API_ VOID H3LoadedPcx16::Clamp(INT& src_x, INT& src_y, INT& src_w, INT& src_h, INT& dst_x, INT& dst_y) const
    {
        if (src_x < 0)
            src_x = 0;
        if (src_x >= width)
            src_x = width - 1;
        if (src_y < 0)
            src_y = 0;
        if (src_y >= height)
            src_y = height - 1;
        if (src_w < 0)
            src_w = 0;
        if (src_w > width - src_x)
            src_w = width - src_x;
        if (src_h < 0)
            src_h = 0;
        if (src_h > height - src_y)
            src_h = height - src_y;
        if (dst_x < 0)
            dst_x = 0;
        if (dst_x > width)
            dst_x = width - 1;
        if (dst_y < 0)
            dst_y = 0;
        if (dst_y > height)
            dst_y = height - 1;
        if (src_x + src_w > width - dst_x)
            src_w = width - dst_x - src_x;
        if (src_y + src_h > height - dst_y)
            src_h = height - dst_y - src_y;
    }

} /* namespace h3 */
