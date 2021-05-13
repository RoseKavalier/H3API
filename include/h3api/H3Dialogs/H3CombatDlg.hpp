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
#include "h3api/H3Dialogs/H3BaseDialog.hpp"
#include "h3api/H3Dialogs/H3DialogPanel.hpp"

namespace h3
{
	struct H3CombatBottomPanel;
	struct H3CombatMonsterPanel;
	struct H3CombatHeroPanel;
	struct H3String;

#pragma pack(push, 4)

	struct H3CombatDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x8C);
	protected:
		h3unk32               _f_4C;
		/** @brief [50]*/
		H3DlgEdit*            editText;
		/** @brief [54]*/
		H3Vector<H3String*>   combatText;
		/** @brief [64]*/
		UINT                  lastTimeStamp;
		h3unk32               _f_68;
		/** @brief [6C]*/
		UINT                  timeHint;
	public:
		/** @brief [70]*/
		H3CombatBottomPanel*  bottomPanel;
		/** @brief [74]*/
		H3CombatHeroPanel*    leftHeroPopup;
		/** @brief [78]*/
		H3CombatHeroPanel*    rightHeroPopup;
		/** @brief [7C]*/
		H3CombatMonsterPanel* leftMonsterPopup;
		/** @brief [80]*/
		H3CombatMonsterPanel* rightMonsterPopup;
		/** @brief [84]*/
		H3CombatMonsterPanel* bottomleftMonsterPopup;
		/** @brief [88]*/
		H3CombatMonsterPanel* bottomRightMonsterPopup;

		_H3API_ VOID ShowHint(LPCSTR hint, BOOL8 add_to_log = FALSE);
		_H3API_ H3Vector<H3String*>& GetCombatText();
	};
	_H3API_ASSERT_SIZE_(H3CombatDlg);

	struct H3CombatBottomPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x40);
	protected:
		H3DlgTextPcx*      commentBar;  /**< @brief [34]*/
		H3DlgCustomButton* commentUp;   /**< @brief [38]*/
		H3DlgCustomButton* commentDown; /**< @brief [3C]*/
	public:
	};
	_H3API_ASSERT_SIZE_(H3CombatBottomPanel);

	struct H3CombatHeroPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x5C);
	protected:
		H3DlgPcx*  background;  /**< @brief [34]*/
		H3DlgPcx*  hero;        /**< @brief [38]*/
		H3DlgText* attack;      /**< @brief [3C]*/
		H3DlgText* defense;     /**< @brief [40]*/
		H3DlgText* power;       /**< @brief [44]*/
		H3DlgText* knowledge;   /**< @brief [48]*/
		H3DlgDef*  morale;      /**< @brief [4C]*/
		H3DlgDef*  luck;        /**< @brief [50]*/
		H3DlgText* spellPoints; /**< @brief [54]*/
		BOOL8      needsRedraw; /**< @brief [58]*/
	public:
	};
	_H3API_ASSERT_SIZE_(H3CombatHeroPanel);

	struct H3CombatMonsterPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x70);
	protected:
		H3DlgPcx*  background;    /**< @brief [34]*/
		H3DlgDef*  creature;      /**< @brief [38]*/
		H3DlgText* attack;        /**< @brief [3C]*/
		H3DlgText* defense;       /**< @brief [40]*/
		H3DlgText* damage;        /**< @brief [44]*/
		H3DlgText* health;        /**< @brief [48]*/
		H3DlgDef*  morale;        /**< @brief [4C]*/
		H3DlgDef*  luck;          /**< @brief [50]*/
		H3DlgText* numberAlive;   /**< @brief [54]*/
		H3DlgDef*  spells[3];     /**< @brief [58]*/
		H3DlgText* noActiveSpell; /**< @brief [64]*/
		BOOL8      needsRedraw;   /**< @brief [68]*/
		INT32      type;          /**< @brief [6C] 1 or 2 ?*/
	public:

	};
	_H3API_ASSERT_SIZE_(H3CombatMonsterPanel);

	struct H3BattleOptionsDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x50);
		_H3API_GET_INFO_(0x694FE0, H3BattleOptionsDlg);
		_H3API_CTOR_DTOR_(0x46DF00, 0x46F250);
		_H3API_VTABLE_(0x63D448);

		BOOL8 optionsModified;
	};
	_H3API_ASSERT_SIZE_(H3BattleOptionsDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
