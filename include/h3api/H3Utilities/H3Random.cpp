//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Utilities/H3Random.hpp"

namespace h3
{
	_H3API_ VOID H3Random::SetRandomSeed(UINT seed)
	{
		srand(seed);
	}
	_H3API_ VOID H3Random::SetRandomSeed()
	{
		SetRandomSeed(GetTime());
	}
	// https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range?answertab=active#tab-top
	_H3API_ INT32 H3Random::Random(INT32 high)
	{
		const INT32 num_bins = high + 1;
		const INT32 num_rand = RAND_MAX + 1;
		const INT32 bin_size = num_rand / num_bins;
		const INT32 defect   = num_rand % num_bins;

		INT32 x;
		do { x = rand(); } while (num_rand - defect <= x);

		return x / bin_size;
	}
	_H3API_ INT32 H3Random::RandBetween(INT32 low, INT32 high)
	{
		return H3Random::Random(high - low) + low;
	}
	_H3API_ INT32 H3Random::MultiplayerRandom(INT32 min_value, INT32 max_value)
	{
		return FASTCALL_2(INT, 0x50B3C0, min_value, max_value);
	}

	_H3API_ INT32 H3Random::PeekRand()
	{
		SeedRestore restore;
		return Rand();
	}
	_H3API_ INT32 H3Random::PeekRand(INT32 low, INT32 high)
	{
		SeedRestore restore;
		return Rand(low, high);
	}
	_H3API_ INT32 H3Random::Rand()
	{
		return STDCALL_0(INT32, 0x61842C);
	}
	_H3API_ INT32 H3Random::Rand(INT32 low, INT32 high)
	{
		return FASTCALL_2(INT32, 0x50C7C0, low, high);
	}
	_H3API_ VOID H3Random::Srand(UINT32 seed)
	{
		CDECL_1(VOID, 0x61841F, seed);
	}
	_H3API_ UINT32 H3Random::ThreadLocalSingleton::CurrentSeed() const
	{
		return currentSeedValue;
	}
	_H3API_ VOID H3Random::ThreadLocalSingleton::SetSeed(UINT32 value)
	{
		currentSeedValue = value;
	}
	_H3API_ DWORD H3Random::ThreadLocalSingleton::GetLastError() const
	{
		return lastError;
	}
	_H3API_ VOID H3Random::ThreadLocalSingleton::SetLastError(DWORD error)
	{
		THISCALL_2(VOID, 0x619E2B, this, error);
	}
	_H3API_ H3Random::ThreadLocalSingleton& H3Random::ThreadLocalSingleton::Get()
	{
		return STDCALL_0(H3Random::ThreadLocalSingleton&, 0x61D8C3);
	}
	_H3API_ H3Random::SeedRestore::SeedRestore() :
		m_tls(H3Random::ThreadLocalSingleton::Get()),
		m_oldSeed(m_tls.CurrentSeed())
	{
	}
	_H3API_ H3Random::SeedRestore::~SeedRestore()
	{
		m_tls.SetSeed(m_oldSeed);
	}

} /* namespace h3 */
