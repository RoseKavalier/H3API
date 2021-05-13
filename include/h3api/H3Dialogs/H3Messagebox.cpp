//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3Messagebox.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Managers/H3WindowManager.hpp"

namespace h3
{
	_H3API_ VOID H3Messagebox::Show(const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::Show(LPCSTR text, const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::OK, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::Show(const H3String& text, const H3PictureCategories& pic1, const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(text.String(), pic1, pic2, pic3);
	}
	_H3API_ H3Messagebox::H3Messagebox(LPCSTR message)
	{
		Show(message);
	}
	_H3API_ H3Messagebox::H3Messagebox(const H3String& message)
	{
		Show(message.String());
	}
	_H3API_ H3Messagebox::H3Messagebox()
	{
		Show();
	}
	_H3API_ VOID H3Messagebox::Display(const H3PictureVector& images, INT32 timeout /*= 0*/)
	{
		display(h3_TextBuffer, images, timeout);
	}
	_H3API_ VOID H3Messagebox::Display(LPCSTR text, const H3PictureVector& images, INT32 timeout)
	{
		display(text, images, timeout);
	}
	_H3API_ VOID H3Messagebox::Display(const H3String& text, const H3PictureVector& images, INT32 timeout)
	{
		display(text.String(), images, timeout);
	}
	_H3API_ BOOL H3Messagebox::Choice(const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return Choice(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ BOOL H3Messagebox::Choice(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return choice(text, pic1, pic2, pic3);
	}
	_H3API_ BOOL H3Messagebox::Choice(const H3String& text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		return Choice(text.String(), pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(h3_TextBuffer, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::RIGHT_CLICK, pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::RMB(const H3String& text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		Show(text.String(), pic1, pic2, pic3);
	}
	_H3API_ VOID H3Messagebox::show(LPCSTR text, eButtonType type, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		FASTCALL_12(VOID, 0x4F6C00, text,
			static_cast<INT32>(type), -1, -1,
			static_cast<INT32>(pic1.type), pic1.subtype,
			static_cast<INT32>(pic2.type), pic2.subtype,
			static_cast<INT32>(pic3.type), pic3.subtype,
			-1, 0);
	}
	_H3API_ VOID H3Messagebox::display(LPCSTR text, const H3PictureVector& images, INT32 timeout)
	{
		FASTCALL_5(VOID, 0x4F7D20, text, &images, -1, -1, timeout);
	}
	_H3API_ BOOL H3Messagebox::choice(LPCSTR text, const H3PictureCategories& pic1,
		const H3PictureCategories& pic2, const H3PictureCategories& pic3)
	{
		show(text, eButtonType::OK_CANCEL, pic1, pic2, pic3);
		return H3WindowManager::Get()->ClickedOK();
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(LPCSTR text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		show(text, eButtonType::TAKE, pic1, pic2);
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_LEFT)
			return ePick::LEFT;
		return ePick::RIGHT; // no option for NONE in this mode
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(const H3String& text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Take(text.String(), pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Take(const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Take(h3_TextBuffer, pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(LPCSTR text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		show(text, eButtonType::OPTION, pic1, pic2);
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_LEFT)
			return ePick::LEFT;
		if (H3WindowManager::Get()->ClickedItemID() == eControlId::SELECT_RIGHT)
			return ePick::RIGHT;
		return ePick::NONE; // clicked cancel
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(const H3String& text,
		const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Choose(text.String(), pic1, pic2);
	}
	_H3API_ H3Messagebox::ePick H3Messagebox::Choose(const H3PictureCategories& pic1, const H3PictureCategories& pic2)
	{
		return Choose(h3_TextBuffer, pic1, pic2);
	}
	_H3API_ H3PictureCategories::H3PictureCategories() :
		type(ePictureCategories::NONE), subtype(0)
	{
	}
	_H3API_ H3PictureCategories::H3PictureCategories(const H3PictureCategories& other) :
		type(other.type), subtype(other.subtype)
	{
	}
	_H3API_ H3PictureCategories::H3PictureCategories(ePictureCategories type, INT32 subtype) :
		type(type), subtype(subtype)
	{
	}
	_H3API_ H3PictureCategories H3PictureCategories::Resource(eResource type, INT32 amount)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(type), amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Artifact(eArtifact id)
	{
		return H3PictureCategories(ePictureCategories::ARTIFACT, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Spell(eSpell id)
	{
		return H3PictureCategories(ePictureCategories::SPELL, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Player(ePlayer id)
	{
		return H3PictureCategories(ePictureCategories::CREST, static_cast<INT32>(id));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Luck(INT32 amount)
	{
		if (amount < 0)
			return H3PictureCategories(ePictureCategories::NEUTRAL_LUCK, -amount);
		if (amount > 0)
			return H3PictureCategories(ePictureCategories::POSITIVE_LUCK, amount);
		return H3PictureCategories(ePictureCategories::NEUTRAL_LUCK, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Morale(INT32 amount)
	{
		if (amount < 0)
			return H3PictureCategories(ePictureCategories::NEUTRAL_MORALE, -amount);
		if (amount > 0)
			return H3PictureCategories(ePictureCategories::POSITIVE_MORALE, amount);
		return H3PictureCategories(ePictureCategories::NEUTRAL_MORALE, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Experience(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::EXPERIENCE, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::SecSkill(eSecondary skill, eSecSkillLevel level)
	{
		return H3PictureCategories(ePictureCategories::SECONDARY_SKILL,
			static_cast<INT32>(skill) * 3 + static_cast<INT32>(level) + 2);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Creature(eCreature id, UINT16 amount)
	{
		return H3PictureCategories(ePictureCategories::CREATURE, static_cast<UINT16>(id) | (amount << 16));
	}
	_H3API_ H3PictureCategories H3PictureCategories::Building(eTown town_type, eBuildings building_id)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(static_cast<INT32>(town_type) +
			static_cast<INT32>(ePictureCategories::CASTLE_BUILDINGS)), building_id);
	}
	_H3API_ H3PictureCategories H3PictureCategories::PrimarySkill(ePrimary skill_type, INT8 amount)
	{
		return H3PictureCategories(static_cast<ePictureCategories>(static_cast<INT32>(skill_type) +
			static_cast<INT32>(ePictureCategories::ATTACK)), amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::SpellPoints(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::SPELL_POINTS, amount);
	}
	_H3API_ H3PictureCategories H3PictureCategories::Money(INT32 amount)
	{
		return H3PictureCategories(ePictureCategories::MONEY, amount);
	}
	_H3API_ H3PictureCategories& H3PictureCategories::operator=(const H3PictureCategories& other)
	{
		type = other.type;
		subtype = other.subtype;
		return *this;
	}
}
