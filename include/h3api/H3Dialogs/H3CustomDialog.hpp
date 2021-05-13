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
#include "h3api/H3Constants/H3CstVKey.hpp"
#include "h3api/H3Dialogs/H3NetworkDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(Dlg);
	class  H3DlgHintBar;
	struct H3LoadedDef;
	struct H3LoadedPcx;
	struct H3LoadedPcx24;
	struct H3Msg;

#pragma pack(push, 4)

	// * This removes the following warning when using enum
	// * warning C4482: nonstandard extension used: enum '...' used in qualified name
#pragma warning(push)
#pragma warning(disable : 4482)
	struct H3Dlg : H3NetworkDlg
	{
		/** @brief Amount of time allowed between two consecutive clicks to determine whether it's double-click*/
		static constexpr DWORD DOUBLE_CLICK_SPEED = 400;

	protected:
		//======================================
		// original virtual functions
		// DO NOT OVERLOAD THESE!
		//======================================

		/** @ brief [v00]*/
		_H3API_ virtual H3Dlg* vDestroy() override;
		/** @ brief [v04]*/
		_H3API_ virtual INT vShow(INT zorder, BOOL8 draw) override;
		/** @ brief [v08]*/
		_H3API_ virtual INT vHide(BOOL8 redrawScreen) override;
		/** @ brief [v0C]*/
		_H3API_ virtual INT vPreProcess(H3Msg& msg) override;
		/** @ brief [v10] always seems to be nullsub*/
		_H3API_ virtual VOID vParentActivate_10(H3DlgItem* unknown) override;
		/** @ brief [v14]*/
		_H3API_ virtual BOOL8 vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId) override;
		/** @ brief [v18]*/
		_H3API_ virtual INT vShowAndRun(BOOL8 fadeIn) override;
		/** @ brief [v1C]*/
		_H3API_ virtual INT vInitiateItems() override;
		/** @ brief [v20]*/
		_H3API_ virtual INT vActivateItems(BOOL8 increase) override;
		//======================================
		// custom overload of original virtual function
		// OVERRIDE NOT RECOMMENDED!!
		//======================================
		/** @ brief [v24]*/
		_H3API_ virtual INT vDialogProc(H3Msg& msg) override;
		//======================================
		// original virtual functions
		// DO NOT OVERLOAD THESE!
		//======================================
		/** @ brief [v28]*/
		_H3API_ virtual BOOL8 vOnMouseMove(INT32 x, INT32 y) override;
		/** @ brief [v2C]*/
		_H3API_ virtual BOOL8 vOnRightClick(INT32 id) override;
		/** @ brief [v30]*/
		_H3API_ virtual BOOL8 vOnLeftClick(INT32 id, BOOL8& closeDialog) override;
		/** @ brief [v34]*/
		_H3API_ virtual H3DlgTextPcx* vGetStatusBar() override;
		/** @ brief [v38]*/
		_H3API_ virtual INT vEndDialogOnTimeExpired(H3Msg& msg) override;

	public:
		//======================================
		// custom virtual functions
		// FEEL FREE TO OVERLOAD THESE!
		//======================================

		// these remove the need to look at WindowManager to get clicked id
		// and occur within the message loop
		virtual _H3API_ VOID OnOK();
		virtual _H3API_ VOID OnCancel();
		virtual _H3API_ VOID OnClose(INT itemId);

		// * you can use this to add H3DlgItems to your dialog before running it
		// * return TRUE if you wish to run the dialog
		// * return FALSE if you wish to abort
		virtual _H3API_ BOOL OnCreate();

		// * BOOL override functions:
		// *	on TRUE will continue handling current message
		// *	on FALSE will not process current message further

		virtual _H3API_ BOOL DialogProc(H3Msg& msg);
		virtual _H3API_ BOOL OnLeftClick(INT itemId, H3Msg& msg);
		virtual _H3API_ BOOL OnLeftClickOutside();
		virtual _H3API_ BOOL OnRightClick(H3DlgItem* it);
		virtual _H3API_ BOOL OnRightClickOutside();
		// scroll down: -1, scroll up +1
		virtual _H3API_ BOOL OnMouseWheel(INT direction);
		virtual _H3API_ BOOL OnWheelButton(H3DlgItem* it);
		virtual _H3API_ BOOL OnMouseHover(INT32 x, INT32 y);
		virtual _H3API_ BOOL OnMouseHover(H3DlgItem* it);
		virtual _H3API_ BOOL OnKeyPress(eVKey key, eMsgFlag flag);
		virtual _H3API_ BOOL OnKeyHeld(eVKey key, eMsgFlag flag);
		virtual _H3API_ BOOL OnDoubleClick(INT itemId, H3Msg& msg);

		// * this message gets sent from individual H3DlgItems
		// * that use customized virtual tables instead of default ones
		// * this hook occurs before the H3Msg is sent to vDialogProc()
		virtual _H3API_ BOOL OnNotify(H3DlgItem* it, H3Msg& msg);
	protected:
		////////////////////////////////////////////////////////////////////////
		// Custom Fields - not part of regular dialogs!
		////////////////////////////////////////////////////////////////////////
		BOOL           enableDoubleClick; // disabled by default, you have to enable it to use
		DWORD          lastClickTime;     // used to detect double-click
		H3DlgItem*     lastClickedItem;   // used to detect double-click
		BOOL           endDialog;
		H3LoadedPcx16* background;
		H3DlgHintBar*  hintBar;

		////////////////////////////////////////////////////////////////////////
		// Protected functions not meant to be used outside implementation
		////////////////////////////////////////////////////////////////////////
		_H3API_ INT CheckEnd(H3Msg& msg);

	public:
		////////////////////////////////////////////////////////////////////////
		// Constructor and destructor
		////////////////////////////////////////////////////////////////////////
		// * default constructor
		_H3API_ H3Dlg(int width, int height, int x = -1, int y = -1, BOOL statusBar = FALSE,
			BOOL makeBackground = TRUE, INT32 colorIndex = IntAt(0x69CCF4));
		// * default destructor
		// * if you prefer to allocate your own dialogs, use this style:
		// * H3Dlg* MyDlg = new H3Dlg(.......);
		// * ...
		// * delete MyDlg;
		// * this will automatically call the destructor before deallocating memory
		_H3API_ ~H3Dlg();
		////////////////////////////////////////////////////////////////////////
		// Functions
		////////////////////////////////////////////////////////////////////////
		_H3API_ VOID  PlaceAtMouse();
		_H3API_ VOID  Start();
		_H3API_ VOID  Stop();
		_H3API_ VOID  RMB_Show();
		_H3API_ BOOL  AddBackground(INT32 x, INT32 y, INT32 w, INT32 h, BOOL frame,
			BOOL statusBar, INT32 colorIndex, BOOL is_blue = FALSE);
		_H3API_ BOOL  AddBackground(BOOL frame, BOOL statusBar, INT32 colorIndex);
		_H3API_ BOOL  AddBackground(H3LoadedPcx* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedPcx16* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedPcx24* pcx);
		_H3API_ BOOL  AddBackground(H3LoadedDef* def, INT group = 0, INT frame = 0);

		_H3API_ BOOL Notify(H3DlgItem* it, H3Msg& msg);
		_H3API_ VOID EnableDoubleClick(BOOL state);
		_H3API_ H3LoadedPcx16* GetBackgroundPcx() const;
		// * draws the background pcx only
		_H3API_ BOOL BackgroundRegion(INT32 xStart, INT32 yStart, INT32 w, INT32 h, BOOL is_blue = FALSE);
		// * draws the HDmod simple frames only
		_H3API_ BOOL SimpleFrameRegion(INT32 xStart, INT32 yStart,
			INT32 width, INT32 height, H3LoadedPcx16* destination = nullptr);
		// * draws the outside frames only
		_H3API_ BOOL FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar,
			INT32 colorIndex, BOOL is_blue = FALSE);

		// Item functions
		_H3API_ H3DlgHintBar* GetHintBar();
		_H3API_ BOOL CreateBlackBox(INT32 x, INT32 y, INT32 width, INT32 height);
		_H3API_ H3DlgHintBar* CreateHint();
		_H3API_ H3DlgHintBar* CreateHint(INT32 x, INT32 y, INT32 width, INT32 height);
	};
#pragma warning(pop)

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
