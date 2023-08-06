//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"

namespace h3
{
	_H3API_DECLARE_(SoundManager);
	struct H3WavFile;

#pragma pack(push, 4)

	// * in charge of playing sounds
	struct H3SoundManager : public H3Manager
	{
		_H3API_SIZE_(0xD4);
		_H3API_VTABLE_(0x63FE68);
		_H3API_GET_INFO_(0x699414, H3SoundManager);

	protected:
		/** @brief [38]*/
		UINT32 mssHandle;
		/** @brief [3C]*/
		HANDLE hSamples[16];
		h3unk8 _f_80;
		/** @brief [84]*/
		INT32 clickSoundVar;
		h3unk32 _f_88;
		h3unk8 _f_8C;
		/** @brief [A0]*/
		_RTL_CRITICAL_SECTION rtlSection[3];
	public:
		_H3API_ VOID ClickSound(); // modeled after sub_00456540
		_H3API_ VOID Play(H3WavFile* wav);
		_H3API_ VOID Play(LPCSTR wav_name);
		/**
		 * @brief Plays a sound file and then waits the specified amount of milliseconds before resuming. Has no effect with HDmod
		 *
		 * @param wav_name name of the wav file to play
		 * @param milliseconds time delay. If negative, 4000 milliseconds are used.
		 */
		_H3API_ VOID PlaySoundAndWait(LPCSTR wav_name, INT milliseconds);
		/**
		 * @brief Plays a wav asynchronously
		 *
		 * @param wav_name The name of the file to play
		 * @param milliseconds The maximum duration in milliseconds, -1 defaults to 10,000ms
		*/
		_H3API_ static VOID PlaySoundAsync(LPCSTR wav_name, INT32 duration = -1);
        /**
         * @brief play a sound directly.
         * 
         * @param wav_name The name of the file to play
         * @return Played Wav file, WARNNING Homm3HD MOD will modify this return pointer to INT32 value as waiting timesteps
         */
        _H3API_ static INT64 PlaySoundByFileAsync(LPCSTR wav_name);
	};
	_H3API_ASSERT_SIZE_(H3SoundManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
