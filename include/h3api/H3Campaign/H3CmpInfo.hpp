//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(CampaignInfo);
	struct H3CmpScenarioInfo;
	struct H3Hero;

#pragma pack(push, 4)

	// from WoG sources
	struct H3CmpInfo
	{
		_H3API_SIZE_(0x7C);
		/** @brief [00]*/
		BOOL8 cheater;
		/** @brief [01]*/
		BOOL8 avgMapScoreAbove350;
		/** @brief [02]*/
		INT8  campaignMapIndex;
	protected:
		h3unk8 _f_3;
	public:
		/** @brief [04]*/
		INT32 bigCampaignIndex;
	protected:
		/** @brief [08]*/
		h3unk8 _f_8[4];
	public:
		/** @brief [0C]*/
		INT8 crossoverArrayIndex;
	protected:
		h3unk8 _f_D[3];
		/** @brief [10]*/
		h3unk8 _f_10[4];
		h3unk8 _f_14;
		h3unk8 _f_15[3];
		h3unk8 _f_18[4];
		h3unk8 _f_1C;
		h3unk8 _f_1D[3];
		h3unk8 _f_20[4];
	public:
		/** @brief [24]*/
		h3unk8 BigCampaignStarted[21];
	protected:
		h3unk8 _f_39[3];
		/** @brief [3C]*/
		H3Vector<H3Vector<H3Hero>> crossoverHeroes;
		/** @brief [4C]*/
		H3Vector<h3unk> someCrossoverArraysRef;
		/** @brief [5C]*/
		H3Vector<H3CmpScenarioInfo> campaignMapInfo;
		/** @brief [6C]*/
		H3Vector<h3unk> someCrossoverInfoStructs;
	};
	_H3API_ASSERT_SIZE_(H3CmpInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
