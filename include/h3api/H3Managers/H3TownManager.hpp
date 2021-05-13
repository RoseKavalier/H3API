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
	_H3API_DECLARE_(TownManager);
	struct H3Town;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3LoadedDef;
	struct H3DlgTransparentItem;
	struct H3TownDialog;
	struct H3GarrisonInterface;

#pragma pack(push, 4)

	// * in charge of towns
	struct H3TownManager : public H3Manager
	{
		_H3API_SIZE_(0x1D8);
		_H3API_VTABLE_(0x643730);
		_H3API_GET_INFO_(0x69954C, H3TownManager);

		/** @brief [38] */
		// * current town structure
		H3Town* town;
		/** @brief [3C] */
		H3LoadedPcx16* background;
		/** @brief [40] */
		H3LoadedDef* creatures[7];
		struct BuildingDrawInfo
		{
			UINT numberFrames; // +0
			UINT currentFrame; // +4
			UINT xPos; // +8
			UINT yPos; // +C
			UINT width; // +10
			UINT height; // +14
			BOOL isActive; // +18
			UINT id; // +1C
			H3LoadedDef* def; // +20
			H3LoadedPcx* outline; // + 24
			H3LoadedPcx* background; // +28
			H3DlgTransparentItem* transparentOverlay; // +2C
		}*buildingDrawing[44]; // +5C
		/** @brief [10C] */
		UINT numberBuildings;
		/** @brief [110] */
		INT townType;
	protected:
		h3unk8 _f_114[4];
	public:
		/** @brief [118] */
		H3TownDialog* dlg;
		/** @brief [11C] */
		H3GarrisonInterface* top;
		/** @brief [120] */
		H3GarrisonInterface* bottom;
	protected:
		h3unk8 _f_124[8];
	public:
		/** @brief [12C] source page*/
		H3GarrisonInterface* source;
		/** @brief [130] number of source stack*/
		INT32 sourcePageStack;
		/** @brief [134] recipient page */
		H3GarrisonInterface* recipientPage;
		/** @brief [138] number of recipient page*/
		INT32 recipientPageStack;
	protected:
		h3unk8 _f_13C[100];
	public:
		/** @brief [1A0] what can be built in the construction screen of the city*/
		H3BuildingsBitfield buildings;
	protected:
		h3unk32 _f_1A8[9];
	public:
		/** @brief [1CC] index of each of the dwellings, 0..6 unupgraded, 7..13 upgraded*/
		UINT8 dwellingIndexes[7];
	protected:
		h3unk32 _f_1D4;
	public:
		_H3API_ VOID Draw();
		_H3API_ VOID RefreshScreen();
		_H3API_ BOOL8 ViewTavern();
	};
	_H3API_ASSERT_SIZE_(H3TownManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
