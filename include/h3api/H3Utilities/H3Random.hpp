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
#include "h3api/H3Utilities/H3Memory.hpp" /* value backup */

namespace h3
{
	_H3API_DECLARE_(Random);

#pragma pack(push, 4)

	struct H3Random
	{
	public:
		/**
		 * @brief Set the Random Seed object. This is your own seed, not h3's. Uses timeGetTime() as seed
		 */
		_H3API_ static VOID SetRandomSeed();
		/**
		 * @brief Set the Random Seed object. This is your own seed, not h3's
		 * @param seed value to set the random generator position
		 */
		_H3API_ static VOID SetRandomSeed(UINT seed);
		/**
		 * @brief generates a random number. This is your own random value, not h3's
		 * @param high the upper margin of the number to be generated
		 * @return a random number between 0 and \p high
		 */
		_H3API_ static INT32 Random(INT32 high);
		/**
		 * @brief generates a random number in the specified interval. This is your own random value, not h3's
		 * @param low the lower boundary
		 * @param high the upper boundary
		 * @return a random number between \p low and \p high
		 */
		_H3API_ static INT32 RandBetween(INT32 low, INT32 high);
		/**
		 * @brief Uses h3's random number generator (will advance seed!)
		 * If in multiplayer mode, uses TimeGetTime() instead of Random()
		 * @param min_value lower bound
		 * @param max_value upper bound
		 * @return Value clamped in between bounds
		 */
		_H3API_ static INT32 MultiplayerRandom(INT32 min_value, INT32 max_value);
		/**
		 * @brief Peeks at h3's current random value without advancing seed
		 * @return random value 0..0x7FFF
		 */
		_H3API_ static INT32 PeekRand();
		/**
		 * @brief Peeks at h3's current random value without advancing seed
		 * @param low Minimum value sought, inclusive
		 * @param high Highest value sought, exclusive
		 * @return random value low..high-1
		 */
		_H3API_ static INT32 PeekRand(INT32 low, INT32 high);
		/**
		 * @brief Gets the random value offered by h3, (will advance seed!)
		 * @return random value 0..0x7FFF
		 */
		_H3API_ static INT32 Rand();
		/**
		 * @brief Gets the random value offered by h3, (will advance seed!)
		 * @param low Minimum value sought, inclusive
		 * @param high Highest value sought, exclusive
		 * @return random value low..high-1
		 */
		_H3API_ static INT32 Rand(INT32 low, INT32 high);
		/**
		 * @brief Sets h3's seed value
		 * @param seed New value to use
		 */
		_H3API_ static VOID Srand(UINT32 seed);
	public:
		/** @brief Probably best not to touch this*/
		struct ThreadLocalSingleton
		{
		public:
			_H3API_SIZE_(0x74);
		private:

			/** @brief [00]*/
			UINT32 currentThreadId;
			h3unk32 _f_04[2];
			/** @brief [0C]*/
			DWORD   lastError;
			h3unk32 _f_10;
			/** @brief [14]*/
			UINT32 currentSeedValue;
			h3unk8 _f_18[56];
			/** @brief [50] 0x690420 nice*/
			h3unk8* _f_50;
			h3unk8 _f_54[32];
		public:
			_H3API_ UINT32  CurrentSeed() const;
			_H3API_ VOID    SetSeed(UINT32 value);
			_H3API_ DWORD   GetLastError() const;
			_H3API_ VOID    SetLastError(DWORD error);
			_H3API_ static  ThreadLocalSingleton& Get();
		};

		/** @brief Used to restore h3's seed to its original value*/
		class SeedRestore
		{
		public:
			_H3API_ SeedRestore();
			_H3API_ ~SeedRestore();
		private:
			ThreadLocalSingleton& m_tls;
			UINT32 m_oldSeed;
		};
	};
	_H3API_ASSERT_SIZE_(H3Random::ThreadLocalSingleton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
