//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3LoadedDef.hpp"
#include "h3api/H3Assets/H3Palette565.hpp"
#include "h3api/H3Assets/H3Palette888.hpp"
#include "h3api/H3Assets/H3DefFrame.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"

namespace h3
{
    _H3API_ H3LoadedDef* H3LoadedDef::Load(LPCSTR name)
    {
        return THISCALL_1(H3LoadedDef*, 0x55C9C0, name);
    }
    _H3API_ VOID H3LoadedDef::AddFrameFromDef(LPCSTR source, INT32 index)
    {
        H3DefLoader src(source);
        if (!src.Get())
            return;
        H3DefFrame* frm = src->groups[0]->frames[0];
        DefGroup*   grp = groups[0];

        H3DefFrame* frame = H3ObjectAllocator<H3DefFrame>().allocate(1);
        if (frame)
        {
            libc::memcpy(frame, frm, sizeof(H3DefFrame)); // copy frame data
            frame->rawData = ByteAllocator().allocate(frame->rawDataSize);
            libc::memcpy(frame->rawData, frm->rawData, frame->rawDataSize); // copy data buffer

            const int n_frames = grp->count;

            if (n_frames < index + 1) // add room for frame
            {
                H3DefFrame** new_list = reinterpret_cast<H3DefFrame**>(H3Realloc(grp->frames, (index + 1) * 4));
                if (new_list)
                {
                    new_list[index] = frame;
                    grp->count = index + 1;
                    grp->spritesSize = index + 1;
                    grp->frames = new_list;
                }
            }
            else
                grp->frames[index] = frame;
        }
    }
    _H3API_ VOID H3LoadedDef::ColorToPlayer(INT32 id)
    {
        if (palette565)
            palette565->ColorToPlayer(id);
        palette888->ColorToPlayer(id);
    }
    _H3API_ H3DefFrame* H3LoadedDef::GetGroupFrame(INT group, INT frame)
    {
        return groups[group]->frames[frame];
    }
    _H3API_ VOID H3LoadedDef::DrawTransparent(INT32 frame, H3LoadedPcx16* pcx, INT32 x, INT32 y,
        BOOL transparent, BOOL mirror, INT32 group, INT32 xFromRight, INT32 yFromBottom)
    {
        THISCALL_15(VOID, 0x47BA90, this, group, frame, xFromRight, yFromBottom, widthDEF, heightDEF,
            pcx->buffer, x, y, pcx->width, pcx->height, pcx->scanlineSize, mirror, transparent);
    }
    _H3API_ VOID H3LoadedDef::DrawToPcx16(INT group, INT frame, INT src_x, INT src_y, INT src_width,
        INT src_height, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL mirror, BOOL do_not_use_special_colors)
    {
        GetGroupFrame(group, frame)->DrawToPcx16(src_x, src_y, src_width, src_height,
            pcx16, dst_x, dst_y, palette565, mirror, do_not_use_special_colors);
    }
    _H3API_ VOID H3LoadedDef::DrawToPcx16(INT group, INT frame, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y)
    {
        DrawToPcx16(group, frame, 0, 0, widthDEF, heightDEF, pcx16, dst_x, dst_y);
    }
    _H3API_ VOID H3LoadedDef::AddDefGroup(UINT group_id, UINT frames_in_group)
    {
        THISCALL_3(VOID, 0x47B410, this, group_id, frames_in_group);
    }
    _H3API_ VOID H3LoadedDef::AddFrameToGroup(UINT group_id, H3DefFrame* frame)
    {
        THISCALL_3(VOID, 0x47B480, this, group_id, frame);
    }
    _H3API_ VOID H3LoadedDef::Init(LPCSTR name, UINT type, UINT width, UINT height)
    {
        THISCALL_5(void, 0x47B240, this, name, type, width, height);
    }
    _H3API_ H3LoadedDef::DefGroup& H3LoadedDef::operator[](UINT index)
    {
        return *groups[index];
    }
    _H3API_ H3DefFrame& H3LoadedDef::DefGroup::operator[](UINT index)
    {
        return *frames[index];
    }
} /* namespace h3 */
