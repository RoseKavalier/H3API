//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3LoadedPcx.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"
#include "h3api/H3Assets/H3Palette32.hpp"
#include "h3api/H3Assets/H3Palette565.hpp"
#include "h3api/H3Assets/H3Palette888.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"

namespace h3
{
    _H3API_ VOID H3LoadedPcx::DrawToPcx16(int srcX, int srcY, int dx, int dy, H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors)
    {
        THISCALL_9(VOID, 0x44FA80, this, srcX, srcY, dx, dy, dest, destX, destY, skip_transparent_colors);
    }
    _H3API_ VOID H3LoadedPcx::DrawToPcx16(H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors)
    {
        THISCALL_9(VOID, 0x44FA80, this, 0, 0, width, height, dest, destX, destY, skip_transparent_colors);
    }
    _H3API_ VOID H3LoadedPcx::DrawToPcx(int src_x, int src_y, int dx, int dy, H3LoadedPcx* pcx_dest, int dest_x, int dest_y, BOOL copy_palette)
    {
        if (pcx_dest == nullptr || dx <= 0 || dy <= 0)
            return;

        if (src_x < 0)
            src_x = 0;
        if (src_y < 0)
            src_y = 0;
        if (dest_x < 0)
            dest_x = 0;
        if (dest_y < 0)
            dest_y = 0;

        const int w = std::min(dx, std::min(width - src_x, pcx_dest->width - dest_x));
        const int h = std::min(dy, std::min(height - src_y, pcx_dest->height - dest_y));

        if (w <= 0 || h <= 0)
            return;

        PUINT8 p_src = GetPixelIndex(src_x, src_y);
        PUINT8 p_dest = pcx_dest->GetPixelIndex(dest_x, dest_y);

        for (int j = 0; j < h; ++j)
        {
            PUINT8 dst = p_dest;
            PUINT8 src = p_src;
            for (int i = 0; i < w; ++i, ++dst, ++src)
                *dst = *src;
            p_dest += pcx_dest->scanlineSize;
            p_src  += scanlineSize;
        }

        if (copy_palette)
        {
            pcx_dest->palette565.CopyPalette(palette565);
            libc::memcpy(pcx_dest->palette888.color, palette888.color, sizeof(palette888.color));
        }
    }
    _H3API_ H3LoadedPcx* H3LoadedPcx::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedPcx*, 0x55AA10, name);
    }
    _H3API_ H3LoadedPcx* H3LoadedPcx::Create(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx* pcx = H3ObjectAllocator<H3LoadedPcx>().allocate(1);
        if (!pcx)
            return nullptr;

        pcx->InitiateResource(name, 16); // see 0x44F5CC
        pcx->vTable = reinterpret_cast<ResourceItemVTable*>(0x63BA14);
        pcx->width = width;
        pcx->height = height;
        // round up to nearest 4
        pcx->scanlineSize = ((width + 3) >> 2) << 2;
        pcx->bufSize = height * pcx->scanlineSize;
        pcx->bufSizeUnk = pcx->bufSize;
        pcx->buffer = ByteAllocator().allocate(pcx->bufSize);
        if (!pcx->buffer)
        {
            H3ObjectAllocator<H3LoadedPcx>().deallocate(pcx);
            return nullptr;
        }
        PH3Palette565(&pcx->palette565)->Initiate();
        PH3Palette888(&pcx->palette888)->Initiate();

        return pcx;
    }
    _H3API_ VOID H3LoadedPcx::DrawAlpha(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        pcx16->Clamp(x, y, w, h, dst_x, dst_y);
        if (H3BitMode::Get() == 2)
            drawAlpha2(x, y, w, h, pcx16, dst_x, dst_y, skip_transparent);
        else
            drawAlpha4(x, y, w, h, pcx16, dst_x, dst_y, skip_transparent);
    }

    _H3API_ VOID H3LoadedPcx::drawAlpha2(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        PUINT8    row_src = GetPixelIndex(x, y);
        H3RGB565* row_dst = pcx16->GetPixel565(dst_x, dst_y);
        PUINT8 src = row_src;

        for (INT j = 0; j < h; ++j)
        {
            for (INT i = 0; i < w; ++i)
            {
                UINT8 pixel = src[i];
                if (pixel == 0 && skip_transparent)
                    continue;
                row_dst[i].Blend(palette565[pixel]);
            }
            src += scanlineSize;
            row_dst += (pcx16->scanlineSize >> 1);
        }
    }
    _H3API_ VOID H3LoadedPcx::drawAlpha4(INT x, INT y, INT w, INT h, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL skip_transparent) const
    {
        H3Palette32& pal32 = *palette565.palette32;
        PUINT8     row_src = GetPixelIndex(x, y);
        H3ARGB888* row_dst = pcx16->GetPixel888(dst_x, dst_y);
        PUINT8 src = row_src;

        for (INT j = 0; j < h; ++j)
        {
            for (INT i = 0; i < w; ++i)
            {
                UINT8 pixel = src[i];
                if (pixel == 0 && skip_transparent)
                    continue;
                row_dst[i].Blend(pal32[pixel]);
            }
            src += scanlineSize;
            row_dst += (pcx16->scanlineSize >> 2);
        }
    }
    _H3API_ PUINT8 H3LoadedPcx::GetRow(int row) const
    {
        return buffer + row * scanlineSize;
    }
    _H3API_ PUINT8 H3LoadedPcx::GetPixelIndex(int x, int y) const
    {
        return GetRow(y) + x;
    }
    _H3API_ VOID H3LoadedPcx::FillRectangle(INT x, INT y, INT dx, INT dy, BYTE color_index)
    {
        const INT l_x = std::max(x, 0);
        const INT l_y = std::max(y, 0);
        if (dx < 0)
            dx = 0;
        if (dy < 0)
            dy = 0;
        dx = std::min(width - l_x, dx);
        dy = std::min(width - l_y, dy);

        PUINT8 start = GetPixelIndex(l_x, l_y);

        for (int j = 0; j < dy; ++j)
        {
            PUINT8 pixel = start;
            for (int i = 0; i < dx; ++i, ++pixel)
                *pixel = color_index;
            start += scanlineSize;
        }
    }
    _H3API_ H3LoadedPcx::H3LoadedPcx(LPCSTR name) :
        bufSize(),
        bufSizeUnk(),
        width(),
        height(),
        scanlineSize(),
        buffer()
    {
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
    }
    _H3API_ VOID H3LoadedPcx::Init(LPCSTR name)
    {
        bufSize = 0;
        bufSizeUnk = 0;
        width = 0;
        height = 0;
        scanlineSize = 0;
        buffer = nullptr;
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
    }
    _H3API_ VOID H3LoadedPcx::Init(LPCSTR name, INT w, INT h)
    {
        InitiateResource(name, 16);
        PH3Palette565(&palette565)->Initiate();
        PH3Palette888(&palette888)->Initiate();
        PtrAt(this) = 0x63BA14;
        scanlineSize = ((w + 3) >> 2) << 2;
        bufSize = scanlineSize * h;
        bufSizeUnk = bufSize;
        width  = w;
        height = h;
        buffer = nullptr;
    }
} /* namespace h3 */
