//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"
#include "h3api/H3Assets/H3ResourceManager.hpp"
#include "h3api/H3Assets/H3Palette565.hpp"
#include "h3api/H3Assets/H3Palette888.hpp"

namespace h3
{
	_H3API_ H3ResourceItem* H3ResourceItem::InitiateResource(LPCSTR name, INT type)
	{
		return THISCALL_3(H3ResourceItem*, 0x558970, this, name, type);
	}
	_H3API_ VOID H3ResourceItem::Dereference()
	{
		vTable->vEraseFromResourceManager(this);
	}
	_H3API_ VOID H3ResourceItem::AddToResourceManager()
	{
		H3ResourceManager::Get()->AddItem(this);
	}
	_H3API_ VOID H3ResourceItem::IncreaseReferences()
	{
		++ref;
	}
	_H3API_ INT32 H3ResourceItem::References() const
	{
		return ref;
	}
	_H3API_ LPCSTR H3ResourceItem::GetName() const
	{
		return name;
	}
	_H3API_ H3ResourceItem::~H3ResourceItem()
	{
		Dereference();
	}
	_H3API_ H3Palette565* H3BasePalette565::cast()
	{
		return reinterpret_cast<H3Palette565*>(this);
	}
	_H3API_ VOID H3BasePalette565::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x6003E0, color, id);
	}
	_H3API_ VOID H3BasePalette565::RotateColors(INT min_index, INT max_index, INT count)
	{
		THISCALL_4(VOID, 0x522E40, this, min_index, max_index, count);
	}
	_H3API_ H3Palette32* H3BasePalette565::Get32bitColors()
	{
		return cast()->Get32bitColors();
	}
	_H3API_ VOID H3BasePalette565::CopyPalette(H3Palette565& source)
	{
		cast()->CopyPalette(source);
	}
	_H3API_ VOID H3BasePalette565::CopyPalette(H3BasePalette565& source)
	{
		cast()->CopyPalette(source);
	}
	_H3API_ VOID H3BasePalette565::InitiateFromPalette888(const H3BasePalette888& palette)
	{
		THISCALL_8(void, 0x522BC0, this, &palette, IntAt(0x69E5DC), IntAt(0x69E5E4), IntAt(0x69E5D0), IntAt(0x69E5E0), IntAt(0x69E5F0), IntAt(0x69E5D8));
	}
	_H3API_	H3RGB565& H3BasePalette565::operator[](UINT index)
	{
		return reinterpret_cast<H3RGB565*>(color)[index]; // required cast for VS2008
	}
	_H3API_ H3RGB565 H3BasePalette565::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3BasePalette565::H3BasePalette565()
	{
	}
	_H3API_ H3BasePalette565::H3BasePalette565(const H3Palette888& palette)
	{
		InitiateFromPalette888(*(H3BasePalette888*)&palette);
	}

	_H3API_ H3BasePalette565::H3BasePalette565(const H3BasePalette888& palette)
	{
		InitiateFromPalette888(palette);
	}

	_H3API_ H3BasePalette565::~H3BasePalette565()
	{
		THISCALL_1(void, 0x522E30, this);
	}
	_H3API_ H3Palette32 H3BasePalette565::Convert() const
	{
		return PH3Palette565(this)->Convert();
	}
#ifdef _H3API_CPLUSPLUS11_
	_H3API_ H3BasePalette565::H3BasePalette565(H3BasePalette565&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		other.palette32 = nullptr; // for safety
	}

	_H3API_ H3BasePalette565& H3BasePalette565::operator=(H3BasePalette565&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		other.palette32 = nullptr; // for safety
		return *this;
	}
	_H3API_ H3BasePalette888::H3BasePalette888(H3BasePalette888&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
	}

	_H3API_ H3BasePalette888& H3BasePalette888::operator=(H3BasePalette888&& other)
	{
		libc::memcpy(this, &other, sizeof(*this));
		return *this;
	}
#endif

	_H3API_ VOID H3BasePalette888::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x600400, this, id);
	}
	_H3API_ H3BasePalette888::~H3BasePalette888()
	{
		THISCALL_1(void, 0x523450, this);
	}
	_H3API_ H3BasePalette888::H3BasePalette888()
	{
	}
	_H3API_ H3RGB888& H3BasePalette888::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ const H3RGB888& H3BasePalette888::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3Palette32 H3BasePalette888::Convert() const
	{
		return PH3Palette888(this)->Convert();
	}
	_H3API_ H3ResourceItemData::H3ResourceItemData(LPCSTR name) :
		m_nameEnd(),
		m_item()
	{
		libc::strncpy(m_name, name, sizeof(m_name));
	}
	_H3API_ BOOL8 H3ResourceItemData::operator<(const H3ResourceItemData& other) const
	{
		return libc::strcmpi(m_name, other.m_name) < 0;
	}
}
