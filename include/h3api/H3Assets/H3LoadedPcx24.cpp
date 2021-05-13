//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3LoadedPcx24.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"

namespace h3
{
    _H3API_ H3LoadedPcx24* H3LoadedPcx24::Construct(LPCSTR name, INT width, INT height, PUINT8 data, UINT32 dataSize)
    {
        return THISCALL_6(H3LoadedPcx24*, 0x44EA20, this, name, width, height, data, dataSize);
    }
    _H3API_ VOID H3LoadedPcx24::DrawToPcx16(INT dst_x, INT dst_y, H3LoadedPcx16* dest, INT srcX, INT srcY)
    {
        return THISCALL_11(VOID, 0x44ECE0, this, srcX, srcY, width, height, dest->buffer, dst_x, dst_y, dest->width, dest->height, dest->scanlineSize);
    }
    _H3API_ H3LoadedPcx24* H3LoadedPcx24::Load(LPCSTR name, INT width, INT height)
    {
        H3LoadedPcx24* pcx = H3ObjectAllocator<H3LoadedPcx24>().allocate(1);
        UINT32 data_size = width * height * sizeof(H3RGB888);
        PBYTE buffer = ByteAllocator().allocate(data_size);
        pcx->Construct(name, width, height, buffer, data_size);
        return pcx;
    }
    _H3API_ PUINT8 H3LoadedPcx24::GetRow(int row)
    {
        return buffer + row * sizeof(H3RGB888) * width;
    }
    _H3API_ H3RGB888* H3LoadedPcx24::GetPixel(int x, int y)
    {
        return (H3RGB888*)GetRow(y) + x;
    }
} /* namespace h3 */
