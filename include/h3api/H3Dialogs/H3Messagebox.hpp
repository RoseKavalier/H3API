//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants.hpp"

namespace h3
{
	_H3API_DECLARE_(PictureCategories);
	/* MessageBox is a common define, not going to fight it */
	_H3API_DECLARE_(Messagebox);
	struct H3String;
	template<typename _Elem> struct H3Vector;

	/** @brief Vector to show multiple images in a dialog message*/
	typedef H3Vector<H3PictureCategories> H3PictureVector;

#pragma pack(push, 4)

	/** @brief Information about pre-built image types*/
	struct H3PictureCategories
	{
		_H3API_SIZE_(8);

		_H3API_ H3PictureCategories();
		_H3API_ H3PictureCategories(ePictureCategories type, INT32 subtype);
		_H3API_ H3PictureCategories(const H3PictureCategories& other);
		_H3API_ H3PictureCategories& operator=(const H3PictureCategories& other);

		_H3API_ static H3PictureCategories Artifact(eArtifact id);
		_H3API_ static H3PictureCategories Building(eTown town_type, eBuildings building_id);
		_H3API_ static H3PictureCategories Creature(eCreature id, UINT16 amount);
		_H3API_ static H3PictureCategories Experience(INT32 amount);
		_H3API_ static H3PictureCategories Luck(INT32 amount);
		_H3API_ static H3PictureCategories Money(INT32 amount);
		_H3API_ static H3PictureCategories Morale(INT32 amount);
		_H3API_ static H3PictureCategories Player(ePlayer id);
		_H3API_ static H3PictureCategories PrimarySkill(ePrimary skill_type, INT8 amount);
		_H3API_ static H3PictureCategories Resource(eResource type, INT32 amount);
		_H3API_ static H3PictureCategories SecSkill(eSecondary skill, eSecSkillLevel level);
		_H3API_ static H3PictureCategories Spell(eSpell id);
		_H3API_ static H3PictureCategories SpellPoints(INT32 amount);

		ePictureCategories type;
		INT32              subtype;
	};
	_H3API_ASSERT_SIZE_(H3PictureCategories);

	/** @brief All pre-built in-game messages are controlled by this static struct*/
	struct H3Messagebox
	{
		/** @brief Show a messagebox using h3_Textbuffer as message*/
		_H3API_ H3Messagebox();
		/**
		 * @brief Show a messagebox with text
		 * @param message Text to be displayed
		 */
		_H3API_ H3Messagebox(LPCSTR message);
		/**
		 * @brief Show a messagebox with text
		 * @param message Text to be displayed
		 */
		_H3API_ H3Messagebox(const H3String& message);

		/** @brief Which image the user selected*/
		enum ePick
		{
			LEFT  = -1,
			NONE  = 0,
			RIGHT = 1,
		};
		/**
		 * @brief Creates dialog to display variable images;
		 * h3_TextBuffer is used as the message to be shown
		 * @param images Vector of images to show
		 * @param timeout milliseconds before closing the dialog, 0 for no timeout
		 */
		_H3API_ static VOID  Display(const H3PictureVector& images, INT32 timeout = 0);
		/**
		 * @brief Creates dialog to display variable images
		 * @param text Message to be shown
		 * @param images Vector of images to show
		 * @param timeout milliseconds before closing the dialog, 0 for no timeout
		 */
		_H3API_ static VOID  Display(LPCSTR text, const H3PictureVector& images, INT32 timeout = 0);
		/**
		 * @brief Creates dialog to display variable images
		 * @param text Message to be shown
		 * @param images Vector of images to show
		 * @param timeout milliseconds before closing the dialog, 0 for no timeout
		 */
		_H3API_ static VOID  Display(const H3String& text, const H3PictureVector& images, INT32 timeout = 0);
		/**
		 * @brief Display a simple dialog box with up to 3 images and "OK" button;
		 * h3_TextBuffer is used as the message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  Show(  const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images and "OK" button
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  Show(  LPCSTR text,
								    const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images and "OK" button
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  Show(  const H3String& text,
								    const H3PictureCategories& pic1 = H3PictureCategories(),
								    const H3PictureCategories& pic2 = H3PictureCategories(),
								    const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, "OK" and "Cancel" buttons;
		 * h3_TextBuffer is used as the message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 * @return BOOL Whether user clicked on "OK"
		 */
		_H3API_ static BOOL  Choice(const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, "OK" and "Cancel" buttons
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 * @return BOOL Whether user clicked on "OK"
		 */
		_H3API_ static BOOL  Choice(LPCSTR text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, "OK" and "Cancel" buttons
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 * @return BOOL Whether user clicked on "OK"
		 */
		_H3API_ static BOOL  Choice(const H3String& text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, shown on Right-Mouse Button click;
		 * h3_TextBuffer is used as the message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  RMB(	const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, shown on Right-Mouse Button click
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  RMB(	LPCSTR text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Display a simple dialog box with up to 3 images, shown on Right-Mouse Button click
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @param pic3 Third image data
		 */
		_H3API_ static VOID  RMB(	const H3String& text,
									const H3PictureCategories& pic1 = H3PictureCategories(),
									const H3PictureCategories& pic2 = H3PictureCategories(),
									const H3PictureCategories& pic3 = H3PictureCategories());
		/**
		 * @brief Forces user to select between two images using "OK" button;
		 * h3_TextBuffer is used as the message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right)
		 */
		_H3API_ static ePick Take(  const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		/**
		 * @brief Forces user to select between two images using "OK" button
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right)
		 */
		_H3API_ static ePick Take(  LPCSTR text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		/**
		 * @brief Forces user to select between two images using "OK" button
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right)
		 */
		_H3API_ static ePick Take(  const H3String& text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		/**
		 * @brief Offers the choice between two images but also lets user refuse with "Cancel";
		 * h3_TextBuffer is used as the message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right or none)
		 */
		_H3API_ static ePick Choose(const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		/**
		 * @brief Offers the choice between two images but also lets user refuse with "Cancel"
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right or none)
		 */
		_H3API_ static ePick Choose(LPCSTR text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);
		/**
		 * @brief Offers the choice between two images but also lets user refuse with "Cancel"
		 * @param text Message to be shown
		 * @param pic1 First image data
		 * @param pic2 Second image data
		 * @return ePick Which item the user selected (left vs right or none)
		 */
		_H3API_ static ePick Choose(const H3String& text,
									const H3PictureCategories& pic1, const H3PictureCategories& pic2);

	protected:

		enum eButtonType
		{
			OK          = 1,
			OK_CANCEL   = 2,
			RIGHT_CLICK = 4,
			TAKE        = 7,
			OPTION      = 10,
		};

		_H3API_ static VOID show(LPCSTR text, eButtonType type,
			const H3PictureCategories& pic1 = H3PictureCategories(),
			const H3PictureCategories& pic2 = H3PictureCategories(),
			const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static BOOL choice(LPCSTR text,
			const H3PictureCategories& pic1 = H3PictureCategories(),
			const H3PictureCategories& pic2 = H3PictureCategories(),
			const H3PictureCategories& pic3 = H3PictureCategories());
		_H3API_ static VOID display(LPCSTR text, const H3PictureVector& images, INT32 timeout);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
