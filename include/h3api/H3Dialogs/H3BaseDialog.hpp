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
#include "h3api/H3Constants.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(BaseDlg);
	_H3API_DECLARE_(ExtendedDlg);

	struct H3DlgItem;
	struct H3LoadedPcx16;
	struct H3Msg;
	struct H3DlgDef;
	struct H3DlgPcx;
	struct H3DlgEdit;
	struct H3DlgText;
	struct H3DlgFrame;
	struct H3DlgPcx16;
	struct H3DlgTextPcx;
	struct H3DlgDefButton;
	struct H3DlgScrollbar;
	struct H3DlgTransparentItem;
	struct H3DlgCustomButton;
	struct H3DlgCaptionButton;
	struct H3DlgScrollableText;
	struct H3ScreenlogEdit;

	typedef UINT16 RGB565;
	typedef INT32(__fastcall* H3DlgButton_proc)(H3Msg*);
	typedef INT32(__fastcall* H3DlgButtonProc)(H3Msg&);
	typedef VOID(__fastcall* H3DlgScrollbar_proc)(INT32, H3BaseDlg*);
	typedef VOID(__fastcall* H3DlgScrollbarProc)(INT32,  H3BaseDlg&);

#pragma pack(push, 4)

	struct H3DlgVTable
	{
	public:
		h3func destroyDlg;
		h3func showDlg;
		h3func hideDlg;
		h3func callProcessAction;
		h3func _nullsub;
		h3func redrawDlg;
		h3func runDlg;
		h3func initDlgItems;
		h3func activateDlg;
		h3func dlgProc;
		h3func mouseMove;
		h3func rightClick;
		h3func clickRet;
		h3func _nullsub3;
		h3func closeDlg;
	};

	/** @brief A minimal dialog class without proc. Likely originally named TWindow or a variant */
	struct _H3API_NOVTABLE_ H3BaseDlg : H3Allocator
	{
		_H3API_SIZE_(0x4C);
		_H3API_VTABLE_(0x643CD4);
		_H3API_CTOR_DTOR_(0x5FEFB0, 0x5FF040);

	protected:
		/** @ brief [v00]*/
		_H3API_ virtual H3BaseDlg* vDestroy() = 0;
		/** @ brief [v04]*/
		_H3API_ virtual INT        vShow(INT zorder, BOOL8 draw) = 0;
		/** @ brief [v08]*/
		_H3API_ virtual INT        vHide(BOOL8 redrawScreen) = 0;
		/** @ brief [v0C]*/
		_H3API_ virtual INT        vPreProcess(H3Msg& msg) = 0;
		/** @ brief [v10] always seems to be nullsub*/
		_H3API_ virtual VOID       vParentActivate_10(H3DlgItem* unknown) = 0;
		/** @ brief [v14]*/
		_H3API_ virtual BOOL8      vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId) = 0;
		/** @ brief [v18]*/
		_H3API_ virtual INT        vShowAndRun(BOOL8 fadeIn) = 0;
		/** @ brief [v1C]*/
		_H3API_ virtual INT        vInitiateItems() = 0;
		/** @ brief [v20]*/
		_H3API_ virtual INT        vActivateItems(BOOL8 increase) = 0;

		/** @ brief [04]*/
		INT32                zOrder;
		/** @ brief [08]*/
		H3BaseDlg*           nextDialog;
		/** @ brief [0C]*/
		H3BaseDlg*           lastDialog;
		/** @ brief [10]*/
		INT32                flags;
		/** @ brief [14]*/
		INT32                state;
		/** @ brief [18]*/
		INT32                xDlg;
		/** @ brief [1C]*/
		INT32                yDlg;
		/** @ brief [20]*/
		INT32                widthDlg;
		/** @ brief [24]*/
		INT32                heightDlg;
		/** @ brief [28]*/
		H3DlgItem*           lastItem;
		/** @ brief [2C]*/
		H3DlgItem*           firstItem;
		/** @ brief [30]*/
		H3Vector<H3DlgItem*> dlgItems;
		/** @ brief [40]*/
		INT32                focusedItemId;
		/** @ brief [44]*/
		H3LoadedPcx16*       pcx16;
		/** @ brief [48]*/
		INT32                deactivatesCount;

		_H3API_ H3DlgItem* getDlgItem(UINT16 id, h3func vtable) const;
		template<typename ItemType>
		ItemType* get(UINT16 id) const;

	public:
		_H3API_ H3BaseDlg(INT x, INT y, INT w, INT h);
		_H3API_ INT32 GetWidth() const;
		_H3API_ INT32 GetHeight() const;
		_H3API_ INT32 GetX() const;
		_H3API_ INT32 GetY() const;
		_H3API_ BOOL  IsTopDialog() const;
		/**
		 * @brief Adds the specified state to control id
		 * @param id Control identifier
		 * @param state Value to be added
		 */
		_H3API_ VOID AddControlState(INT32 id, eControlState state);
		/**
		 * @brief Removes the specified state to control id
		 * @param id Control identifier
		 * @param state Value to be removed
		 */
		_H3API_ VOID RemoveControlState(INT32 id, eControlState state);

		/**
		 * @brief Adds an item to the dialog
		 * @param item Any of H3DlgItem children
		 * @param initiate Whether to pre-initiate the item. Set to false if the dialog handles that itself.
		 * @return The added item
		*/
		_H3API_ H3DlgItem* AddItem(H3DlgItem* item, BOOL initiate = TRUE);
		_H3API_ VOID       Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy); // redraw part of dialog
		_H3API_ VOID       Redraw(); // redraw whole dialog
		_H3API_ INT32      DefaultProc(H3Msg* msg);
		_H3API_ INT32      DefaultProc(H3Msg& msg);

		// * this is what gets shown on the screen
		// * it gets drawn over every time you refresh an item
		// * or draw a new item... good for temporary things
		_H3API_ H3LoadedPcx16*        GetCurrentPcx();
		_H3API_ H3Vector<H3DlgItem*>& GetList();

		_H3API_ H3DlgItem* ItemAtPosition(H3Msg* msg);
		_H3API_ H3DlgItem* ItemAtPosition(H3Msg& msg);
		_H3API_ H3DlgItem* GetH3DlgItem(UINT16 id);

		_H3API_ VOID RedrawItem(UINT16 itemID);
		_H3API_ VOID EnableItem(UINT16 id, BOOL enable);
		_H3API_ VOID SendCommandToItem(INT32 command, UINT16 itemID, UINT32 parameter);
		_H3API_ VOID SendCommandToAllItems(INT32 command, INT32 itemID, INT32 parameter);
		_H3API_ VOID AdjustToPlayerColor(INT8 player, UINT16 itemId);

		// * search and cast to ItemType
		// * e.g. Get<H3DlgDef>(1234)
		template<typename ItemType>
		ItemType* Get(UINT16 id);

		// * these DlgItem Get functions will confirm not only the id
		// * but also the type of the item through its virtual table
		// * because of this latter confirmation, it is possible that
		// * the result is nullptr, so you should always check the return
		_H3API_ H3DlgDef*             GetDef(UINT16 id) const;
		_H3API_ H3DlgPcx*             GetPcx(UINT16 id) const;
		_H3API_ H3DlgEdit*            GetEdit(UINT16 id) const;
		_H3API_ H3DlgText*            GetText(UINT16 id) const;
		_H3API_ H3DlgFrame*           GetFrame(UINT16 id) const;
		_H3API_ H3DlgPcx16*           GetPcx16(UINT16 id) const;
		_H3API_ H3DlgTextPcx*         GetTextPcx(UINT16 id) const;
		_H3API_ H3DlgDefButton*       GetDefButton(UINT16 id) const;
		_H3API_ H3DlgScrollbar*       GetScrollbar(UINT16 id) const;
		_H3API_ H3DlgTransparentItem* GetTransparent(UINT16 id) const;
		_H3API_ H3DlgCustomButton*    GetCustomButton(UINT16 id) const;
		_H3API_ H3DlgCaptionButton*   GetCaptionButton(UINT16 id) const;
		_H3API_ H3DlgScrollableText*  GetScrollableText(UINT16 id) const;

		// * dlgitem that is not visible but responds to commands
		_H3API_ H3DlgTransparentItem* CreateHidden(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id);

		_H3API_ H3DlgFrame* CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color);
		_H3API_ H3DlgFrame* CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color);
		_H3API_ H3DlgFrame* CreateFrame(H3DlgItem* target, RGB565 color, INT id = 0, BOOL around_edge = false);

		_H3API_ H3DlgDef* CreateDef(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame,
			INT32 group = 0, INT32 mirror = FALSE, BOOL closeDialog = FALSE);
		_H3API_ H3DlgDef* CreateDef(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 group = 0,
			INT32 mirror = FALSE, BOOL closeDialog = FALSE);

		_H3API_ H3DlgDefButton* CreateButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName,
			INT32 frame, INT32 clickFrame, BOOL closeDialog = FALSE, INT32 hotkey = NULL);
		_H3API_ H3DlgDefButton* CreateButton(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame = 0, INT32 clickFrame = 1, BOOL closeDialog = FALSE, INT32 hotkey = NULL);

		_H3API_ H3DlgDefButton* CreateOKButton(INT32 x, INT32 y);
		_H3API_ H3DlgDefButton* CreateSaveButton(INT32 x, INT32 y, LPCSTR button_name = NH3Dlg::Assets::iSAVE_DEF);
		_H3API_ H3DlgDefButton* CreateOnOffCheckbox(INT32 x, INT32 y, INT32 id, INT32 frame, INT32 clickFrame = -1);
		_H3API_ H3DlgDefButton* CreateOKButton(); // adjust for hintBar
		_H3API_ H3DlgDefButton* CreateOK32Button(INT32 x, INT32 y); // height is 32
		_H3API_ H3DlgDefButton* CreateCancelButton(); // adjust for hintBar
		_H3API_ H3DlgDefButton* CreateCancelButton(INT32 x, INT32 y);

		_H3API_ H3DlgCaptionButton* CreateCaptionButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id,
			LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame,
			INT32 group = 0, BOOL closeDialog = FALSE, INT32 hotkey = NULL, INT32 color = 0);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id,
			LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ H3DlgCustomButton* CreateCustomButton(INT32 x, INT32 y, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);

		_H3API_ H3DlgPcx* CreatePcx(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);
		_H3API_ H3DlgPcx* CreatePcx(INT32 x, INT32 y, INT32 id, LPCSTR pcxName);

		_H3API_ H3DlgPcx* CreateLineSeparator(INT32 x, INT32 y, INT32 width);

		_H3API_ H3DlgPcx16* CreatePcx16(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName);

		_H3API_ H3DlgEdit* CreateEdit(INT32 x, INT32 y, INT32 width, INT32 height, INT32 maxLength, LPCSTR text,
			LPCSTR fontName = NH3Dlg::Text::MEDIUM, INT32 color = eTextColor::REGULAR,
			INT32 align = eTextAlignment::MIDDLE_CENTER, LPCSTR pcxName = nullptr,
			INT32 id = 0, INT32 hasBorder = FALSE, INT32 borderX = 0, INT32 borderY = 0);

		_H3API_ H3DlgText* CreateText(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName,
			INT32 color, INT32 id, eTextAlignment align = eTextAlignment::MIDDLE_CENTER, INT32 bkColor = 0);

		_H3API_ H3DlgTextPcx* CreateTextPcx(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName,
			LPCSTR pcxName, INT32 color, INT32 id, INT32 align = eTextAlignment::MIDDLE_CENTER);

		_H3API_ H3DlgScrollableText* CreateScrollableText(LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR font, INT32 color, INT32 isBlue = FALSE);

		_H3API_ H3DlgScrollbar* CreateScrollbar(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc = nullptr,
			BOOL isBlue = FALSE, INT32 stepSize = 0, BOOL arrowsEnabled = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3BaseDlg);

	/**
	 * @brief ExtendedDlg doesn't properly inherit from H3BasicDlg per se (constructor-wise)
	 * but they have the exact same base and virtual methods. For simplicity they are set as related.
	 */
	struct _H3API_NOVTABLE_ H3ExtendedDlg : H3BaseDlg
	{
		_H3API_SIZE_(0x4C); // same as H3BasicDlg
		_H3API_VTABLE_(0x643CF8);
		_H3API_CTOR_DTOR_(0x5FFC00, 0x5FF040); // dtor jump from virtual table, shared with H3BasicDlg
	protected:
		/** @ brief [v24]*/
		_H3API_ virtual INT   vDialogProc(H3Msg& msg) = 0;
		/** @ brief [v28]*/
		_H3API_ virtual BOOL8 vOnMouseMove(INT32 x, INT32 y) = 0;
		/** @ brief [v2C]*/
		_H3API_ virtual BOOL8 vOnRightClick(INT32 id) = 0;
		/** @brief [v30] if a status bar is provided, short tip text for H3DlgItem under cursor will be shown*/
		_H3API_ virtual BOOL8 vOnLeftClick(INT32 id, BOOL8& closeDialog) = 0;
		/** @ brief [v34]*/
		_H3API_ virtual H3DlgTextPcx* vGetStatusBar() = 0;
	public:
		_H3API_ H3ExtendedDlg(INT x, INT y, INT w, INT h);
	};
	_H3API_ASSERT_SIZE_(H3ExtendedDlg);

#pragma pack(pop) /* align-4 */

	template<typename ItemType>
	inline typename ItemType* H3BaseDlg::Get(UINT16 id)
	{
		return reinterpret_cast<ItemType*>(GetH3DlgItem(id));
	}
	template<typename ItemType>
	inline typename ItemType* H3BaseDlg::get(UINT16 id) const
	{
		return reinterpret_cast<ItemType*>(getDlgItem(id, ItemType::VTABLE));
	}

} /* namespace h3 */
