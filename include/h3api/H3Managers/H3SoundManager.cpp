//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3SoundManager.hpp"
#include "h3api/H3Assets/H3WavFile.hpp"

namespace h3
{
	_H3API_ VOID H3SoundManager::ClickSound()
	{
		INT32 backup = clickSoundVar;
		H3WavFile* button_wav = H3ButtonWav::Get();
		button_wav->spinCount = 64;
		button_wav->debugInfo = PRTL_CRITICAL_SECTION_DEBUG(1);
		button_wav->lockSemaphore = HANDLE(HANDLE_FLAG_PROTECT_FROM_CLOSE | HANDLE_FLAG_INHERIT);
		THISCALL_2(VOID, 0x59A510, this, button_wav);
		clickSoundVar = backup;
	}
#pragma push_macro("PlaySound")
#ifdef PlaySound
#undef PlaySound
#endif

	_H3API_ VOID H3SoundManager::Play(H3WavFile* wav)
	{
		THISCALL_2(VOID, 0x59A510, this, wav);
	}
	_H3API_ VOID H3SoundManager::Play(LPCSTR wav_name)
	{
		H3WavLoader wav(wav_name);
		if (wav)
			Play(*wav);
	}
	_H3API_ VOID H3SoundManager::PlaySoundAndWait(LPCSTR wav_name, INT milliseconds)
	{
		H3WavLoader wav(wav_name);
		if (!wav)
			return;
		Play(*wav);
		THISCALL_3(VOID, 0x59A7C0, milliseconds, *wav, wav->hSample);
	}

	_H3API_ VOID H3SoundManager::PlaySoundAsync(LPCSTR wav_name, INT32 duration /*= -1*/)
	{
		FASTCALL_3(VOID, 0x59A890, wav_name, duration, 3);
    }

    _H3API_ INT64 H3SoundManager::PlaySoundByFileAsync(LPCSTR wav_name)
    {
        return FASTCALL_1(INT64, 0x59A770, wav_name);
    }

#pragma pop_macro("PlaySound")
} /* namespace h3 */
