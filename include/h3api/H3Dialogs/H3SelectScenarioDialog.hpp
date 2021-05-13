//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Dialogs/H3NetworkDialog.hpp"
#include "h3api/H3GameData/H3ScenarioMapInformation.hpp"
#include "h3api/H3Players/H3ScenarioPlayer.hpp"
#include "h3api/H3Constants/H3Limits.hpp"

namespace h3
{
	_H3API_DECLARE_(SelectScenarioDialog);
	struct H3LoadedDef;
	struct H3LoadedPcx;

#pragma pack(push, 4)
	/* original name : TSingleSelectionWindow, see 0x57A04A */
	struct H3SelectScenarioDialog : H3NetworkDlg
	{
		_H3API_SIZE_(0x1970);
		_H3API_VTABLE_(0x641CBC);
		_H3API_GET_INFO_(0x69FC44, H3SelectScenarioDialog);
		/** @brief [0060]*/
		UINT32                     lastLeftClickTime;
		/** @brief [0064]*/
		h3unk8                     isCampaignMaybe;
		/** @brief [0065]*/
		h3unk8                     isLoadingMaybe;
		/** @brief [0066]*/
		h3unk8                     _f_66;
		/** @brief [0068]*/
		h3unk32                    _f_68;
		/** @brief [006C]*/
		H3LoadedDef*               scselcDef;
		/** @brief [0070]*/
		H3LoadedDef*               scnrvictDef;
		/** @brief [0074]*/
		H3LoadedDef*               scnrlossDef;
		/** @brief [0078]*/
		H3LoadedDef*               itpaDef;
		/** @brief [007C]*/
		H3LoadedDef*               scnrstarDef;
		/** @brief [0080]*/
		H3LoadedDef*               un44Def;
		/** @brief [0084]*/
		h3unk32                    _f_84;
		/** @brief [0088]*/
		H3LoadedPcx*               playerFlagsPcx[8];
		/** @brief [00A8]*/
		H3LoadedPcx*               playerInfoBarPcx[8];
		/** @brief [00C8]*/
		H3LoadedPcx*               heroSmallPortraitsPcx[limits::TOTAL_HEROES];
		/** @brief [0354]*/
		H3LoadedPcx*               hpsrandPcx;
		/** @brief [0358]*/
		h3unk8                     _f_358[4];
		/** @brief [035C]*/
		H3LoadedPcx*               hpsrand0Pcx;
		/** @brief [0360]*/
		H3LoadedPcx*               hpsrand1Pcx;
		/** @brief [0364]*/
		h3unk32                    _f_364;
		/** @brief [0368]*/
		H3LoadedPcx*               hpsrand6Pcx;
		/** @brief [036C]*/
		h3unk8                     _f_36C;
		/** @brief [0370]*/
		UINT32                     mapListNumberTop;
		/** @brief [0374]*/
		UINT32                     selectedMapIndex;
		/** @brief [0378]*/
		UINT32                     turnDuration;
		/** @brief [037C]*/
		BOOL8                      mapSelectShown;
		/** @brief [037D]*/
		BOOL8                      mapListShown;
		/** @brief [037E]*/
		BOOL8                      rmgSettingsShown;
		/** @brief [037F]*/
		h3unk8                     _f_37F;
		/** @brief [0380]*/
		H3DlgEdit*                 edit380;
		/** @brief [0384]*/
		h3unk32                    _f_384;
		/** @brief [0388]*/
		h3unk32                    _f_388;
		/** @brief [038C]*/
		H3ScenarioMapInformation   mapInfo;
		/** @brief [1030]*/
		H3Vector<H3ScenarioMapInformation> vector1030;
		/** @brief [1040]*/
		H3Vector<H3ScenarioMapInformation> vector1040;
		/** @brief [1050]*/
		H3Vector<H3ScenarioMapInformation> mapsInformation;
		/** @brief [1060]*/
		H3ScenarioMapInformation*  mapsInfoPtr;
		/** @brief [1064]*/
		H3ScenarioPlayer           mapPlayersHuman[8];
		/** @brief [1444]*/
		H3ScenarioPlayer           mapPlayersComputer[8];
		/** @brief [1824]*/
		h3unk32                    _f_1824;
		/** @brief [1828]*/
		h3unk32                    _f_1828;
		/** @brief [182C]*/
		h3unk32                    _f_182C;
		/** @brief [1830]*/
		h3unk32                    _f_1830;
		/** @brief [1834]*/
		h3unk8                     _f_1834;
		/** @brief [1838]*/
		H3DlgScrollbar*            scrollBar1838;
		/** @brief [183C]*/
		H3DlgScrollbar*            scrollBar183C;
		/** @brief [1840]*/
		H3DlgScrollbar*            turnDurationScroll;
		/** @brief [1844]*/
		h3unk32                    _f_1844;
		/** @brief [1848]*/
		H3DlgText*                 text1848;
		/** @brief [184C]*/
		H3DlgText*                 text184C;
		/** @brief [1850]*/
		H3DlgText*                 text1850;
		/** @brief [1854]*/
		BOOL8                      newMapSelected;
		/** @brief [1858]*/
		H3DlgEdit*                 edit1858;
		/** @brief [185C]*/
		h3unk32                    _f_185C;
		/** @brief [1860]*/
		h3unk32                    _f_1860;
		/** @brief [1864]*/
		h3unk8                     _f_1864;
		/** @brief [1865]*/
		h3unk8                     _f_1865;
		/** @brief [1868]*/
		H3DlgDefButton*            button1868;
		/** @brief [186C]*/
		h3unk8                     _f_186C;
		/** @brief [1870] derived with an extra byte + 2 ints*/
		H3LoadedPcx16*             extendedPcx;
		/** @brief [1874] read from VersionInfo*/
		CHAR                       gameVersionName[20];
		/** @brief [1888] start or another class*/
		h3func*                    newGameCampaignVtable;
		/** @brief [188C]*/
		h3unk8                     _f_188C[8];
		/** @brief [1894]*/
		h3unk8                     _f_1894;
		/** @brief [1898]*/
		INT32                      gameVersion;
		/** @brief [189C]*/
		h3unk32                    _f_189C;
		/** @brief [18A0]*/
		UINT32                     mapDimension;
		/** @brief [18A4]*/
		INT32                      numberLevels;
		/** @brief [18A8]*/
		INT32                      numberPlayersSelected;
		/** @brief [18AC]*/
		h3unk32                    _f_18AC;
		/** @brief [18B0]*/
		INT32                      computerPlayersOnlySelected;
		/** @brief [18B4]*/
		h3unk32                    _f_18B4;
		/** @brief [18B8]*/
		INT32                      waterContentSelected;
		/** @brief [18BC]*/
		INT32                      monsterStrengthSelected;
		/** @brief [18C0]*/
		H3DlgDefButton*            humanComputerButtons[9];
		/** @brief [18E4]*/
		H3DlgDefButton*            humanComputerTeamsButtons[9];
		/** @brief [1908]*/
		H3DlgDefButton*            computerOnlyButtons[9];
		/** @brief [192C]*/
		H3DlgDefButton*            computerOnlyTeams[8];
		/** @brief [194C]*/
		H3DlgDefButton*            waterContentButtons[4];
		/** @brief [195C]*/
		H3DlgDefButton*            monsterStrengthButtons[4];
		/** @brief [196C]*/
		H3DlgScrollableText*       textScroll;

		_H3API_ H3ScenarioMapInformation& CurrentMap();
		_H3API_ VOID UpdateForSelectedScenario(INT32 index, BOOL8 redraw);
		_H3API_ VOID Redraw();
	};
	_H3API_ASSERT_SIZE_(H3SelectScenarioDialog);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
