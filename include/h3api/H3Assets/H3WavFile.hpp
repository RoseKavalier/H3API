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
#include "h3api/H3Assets/H3Resource.hpp"

namespace h3
{
	_H3API_DECLARE_(WavFile);

#pragma pack(push, 4)
	/** @brief original name unknown, only references are 'midi' and 'sfx'*/
	struct H3WavFile : public H3ResourceItem
	{
		_H3API_SIZE_(0x34);
		_H3API_VTABLE_(0x6416E0);

		/** @brief [1C]*/
		HANDLE hSample;
		/** @brief [20] from SoundMgr*/
		PUINT8 buffer;
		/** @brief [24]*/
		DWORD bufferSize;
		/** @brief [28] fields of _RTL_CRITICAL_SECTION*/
		HANDLE lockSemaphore;
		/** @brief [2C]*/
		ULONG_PTR spinCount;
		/** @brief [30]*/
		PRTL_CRITICAL_SECTION_DEBUG debugInfo;

		_H3API_ static H3WavFile* Load(LPCSTR name);

		_H3API_ H3WavFile(LPCSTR name);
		_H3API_ H3WavFile(LPCSTR name, PUINT8 buffer, DWORD bufferSize);
	};
	_H3API_ASSERT_SIZE_(H3WavFile);

	_H3API_NAMED_STRUCT_(H3WavFile, ButtonWav, 0x694DF4);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
