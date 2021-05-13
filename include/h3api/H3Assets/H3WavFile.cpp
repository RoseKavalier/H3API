//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3WavFile.hpp"

namespace h3
{
    _H3API_ H3WavFile* H3WavFile::Load(LPCSTR name)
    {
        return THISCALL_1(H3WavFile*, 0x55C930, name);
    }
    _H3API_ H3WavFile::H3WavFile(LPCSTR name) :
        hSample(0),
        buffer(),
        bufferSize(),
        lockSemaphore(HANDLE(0)),
        spinCount(127),
        debugInfo(PRTL_CRITICAL_SECTION_DEBUG(1)) // RTL_RESOURCE_TYPE
    {
        InitiateResource(name, 32);
        PtrAt(this) = VTABLE;
    }
    _H3API_ H3WavFile::H3WavFile(LPCSTR name, PUINT8 buffer, DWORD bufferSize) :
        hSample(0),
        buffer(buffer),
        bufferSize(bufferSize),
        lockSemaphore(HANDLE(0)),
        spinCount(127),
        debugInfo(PRTL_CRITICAL_SECTION_DEBUG(1)) // RTL_RESOURCE_TYPE
    {
        InitiateResource(name, 32);
        PtrAt(this) = VTABLE;
    }
} /* namespace h3 */
