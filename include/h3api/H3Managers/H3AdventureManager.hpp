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
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	struct H3MapItem;
	struct H3MainSetup;
	struct H3Msg;
	struct H3LoadedDef;
	struct H3WavFile;
	_H3API_DECLARE_(AdventureManager);

#pragma pack(push, 4)

	// * in charge of the adventure map
	struct H3AdventureManager : public H3Manager
	{
		_H3API_SIZE_(0x3B8);
		_H3API_VTABLE_(0x63A678);
		_H3API_GET_INFO_(0x6992B8, H3AdventureManager);
		enum ePanel
		{
			// from 0 through 7
			PHERO = 3,
			PTOWN = 4,
		};

	protected:
		h3unk32 _f_038; // mplay object
	public:
		/** @brief [3C] */
		BOOL8 showFPS;
	protected:
		h3unk32 _f_040;
	public:
		/** @brief [44] */
		struct H3Dlg* dlg;
		/** @brief [48] [x][y][z] array storing id of frame to be drawn*/
		UINT16* arrowPathFrames;
	protected:
		h3unk8 _f_04C[4];
	public:
		/** @brief [50] for complete calculation of tile movements*/
		BOOL movementCalculated;
		/** @brief [54] for partial calculation of tile movements*/
		BOOL movementCalculated1;
	protected:
		h3unk8 _f_058[4];
	public:
		/** @brief [5C] pointer to H3Main's mainSetup*/
		H3MainSetup* map;
		/** @brief [60] */
		H3LoadedDef* terrainDef[10];
	protected:
		h3unk8 _f_088[4];
	public:
		/** @brief [8C] */
		H3LoadedDef* riverDef[4];
	protected:
		h3unk8 _f_09C[4];
	public:
		/** @brief [A0] */
		H3LoadedDef* roadDef[3];
		/** @brief [AC] */
		H3LoadedDef* edgDef;
		/** @brief [B0] */
		H3LoadedDef* adagDef;
		/** @brief [B4] */
		H3LoadedDef* agemulDef;
		/** @brief [B8] */
		H3LoadedDef* agemurDef;
		/** @brief [BC] */
		H3LoadedDef* agemllDef;
		/** @brief [C0] */
		H3LoadedDef* agemlrDef;
		/** @brief [C4] */
		H3LoadedDef* tshrcDef;
		/** @brief [C8] */
		H3LoadedDef* radarDef;
		/** @brief [CC] */
		H3LoadedDef* tshreDef;
		/** @brief [D0] */
		H3Vector<H3LoadedDef*> defs;
		/** @brief [E0] */
		H3LoadedDef* attackDEF;
		/** @brief [E4] the position of top left of the screen*/
		H3Position screenPosition;
		/** @brief [E8] the position of the mouse cursor in (x,y,z)*/
		H3Position mousePosition;
		/** @brief [EC] the previous map adventure coordinates of the mouse*/
		POINT previousMousePosition;
	protected:
		h3unk8 _f_0F4[24];
	public:
		/** @brief [10C] */
		H3LoadedDef* heroDef[18];
		/** @brief [154] */
		H3LoadedDef* boatDef[3];
		/** @brief [160] */
		H3LoadedDef* boatMovementDef[3];
		/** @brief [16C] */
		H3LoadedDef* heroFlags00[8];
		/** @brief [18C] */
		H3LoadedDef* heroFlags01[8];
		/** @brief [1AC] */
		H3LoadedDef* heroFlags02[8];
		/** @brief [1CC] */
		H3LoadedDef* heroFlags03[8];
		/** @brief [1EC] see 40F65F*/
		BOOL8 drawTransparentHero;
		/** @brief [1F0] */
		INT32 terrain;
		/** @brief [1F4] direction the hero is facing*/
		INT32 heroDirection;
	protected:
		h3unk8 _f_1F8[4];
	public:
		/** @brief [1FC] which group from AHXX.def to draw from*/
		INT32 heroDefGroup;
	protected:
		h3unk8 _f_200[12];
	public:
		/** @brief [20C] */
		BOOL8 centeredHero;
	protected:
		h3unk8 _f_20D[11];
	public:
		/** @brief [218] */
		INT32 monsterTypeBattle;
		/** @brief [21C] */
		INT32 monsterCountBattle;
		/** @brief [220] */
		INT32 monsterSideBattle;
	protected:
		h3unk8 _f_224[4];
	public:
		struct {
			INT32 loopSound; // index of looped sound
			INT32 volume;
		} currentSounds[4];
		/** @brief [248] */
		H3WavFile* loopSounds[70];
		/** @brief [360] */
		H3WavFile* horseXYSounds[11];
	protected:
		h3unk8 _f_38C[8];
	public:
		/** @brief [394] see ePanel*/
		INT32 currentInfoPanel;
	protected:
		h3unk8 _f_398[32];
	public:

		_H3API_ H3MapItem* GetMapItem();
		_H3API_ H3MapItem* GetMapItem(UINT32 mixedPos);
		_H3API_ H3MapItem* GetMapItem(const H3Position& p);
		_H3API_ H3MapItem* GetMapItem(const H3Point& p);
		_H3API_ H3MapItem* GetMapItem(INT32 x, INT32 y, INT32 z);
		_H3API_ UINT8      GetX();
		_H3API_ UINT8      GetY();
		_H3API_ UINT8      GetZ();
		_H3API_ VOID       FullUpdate();
		_H3API_ VOID       MobilizeHero();
		_H3API_ VOID       DemobilizeHero();
		_H3API_ VOID       MovementCalculationsMouse();
		_H3API_ VOID       MovementCalculations(UINT32 mixedPosition);
		_H3API_ VOID       MakeHeroPath();
		_H3API_ VOID       ShowCoordinates(UINT32 x, UINT32 y, UINT8 z);
		_H3API_ INT        SimulateMouseOver(INT x, INT y);
		_H3API_ INT        SimulateMouseOver(POINT& p);
		_H3API_ CHAR       UpdateHintMessage();
		_H3API_ H3Point    GetCoordinates(H3MapItem* item);
		_H3API_ VOID       StopSound(H3WavFile* wav);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
		_H3API_ H3Map<UINT16>        GetPathMap();
		_H3API_ H3FastMap<UINT16>    GetPathFastMap();
		/**
		 * @brief Orders the manager to close
		 * @param msg The current thread message
		 * @return Value 2 to indicate end of loop
		 */
		_H3API_ INT32 Close(H3Msg& msg);
	};
	_H3API_ASSERT_SIZE_(H3AdventureManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
