//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants.hpp"
#include "h3api/H3Containers/H3Set.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Assets/H3Pixels.hpp"

namespace h3
{
	_H3API_DECLARE_(ResourceItem);
	_H3API_DECLARE_(BasePalette565);
	_H3API_DECLARE_(BasePalette888);
	struct H3ResourceManager;
	struct H3ResourceManagerNode;
	struct H3WavFile;
	struct H3TextFile;
	struct H3TextTable;
	struct H3Palette565;
	struct H3Palette888;
	struct H3Palette32;
	struct H3Font;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3LoadedPcx24;
	struct H3DefFrame;
	struct H3LoadedDef;

	template <typename T> class H3BinaryLoader;

	struct _H3API_DEPRECATED_("Use H3LoadedDef::DefGroup") H3DefGroup;

	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3Font>,        FontLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedDef>,   DefLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3Palette565>,  PaletteLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedPcx>,   PcxLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3LoadedPcx16>, Pcx16Loader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3TextFile>,    TextFileLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3TextTable>,   TextTableLoader);
	_H3API_TYPE_DECLARE_(H3BinaryLoader<H3WavFile>,     WavLoader);

#pragma pack(push, 4)
	/** @brief Base class for inheritance of assets. original name: 'type_resource'*/
	struct H3ResourceItem : H3Allocator
	{
		_H3API_SIZE_(0x1C);
		_H3API_CTOR_DTOR_(0x558970, -1);

		friend H3ResourceManager;
	protected:
		struct ResourceItemVTable
		{
			typedef H3ResourceItem* (__thiscall* VDestroy)(H3ResourceItem*, BOOL8);
			typedef VOID(__thiscall* VDeref)(H3ResourceItem*);
			typedef UINT(__thiscall* VGetSize)(H3ResourceItem*);

			VDestroy vdestroy; // 0x5589C0, called by dereference
			VDeref   vEraseFromResourceManager; // 0x55D300
			VGetSize vGetSize;
		}*vTable;
		// * +4
		CHAR name[12];
		// * +10
		UINT nameEnd; // always 0
		// * +14
		INT32 type; // arg3 from constructor
		// * +18
		INT32 ref; // the number of times it is being used
	public:
		_H3API_ H3ResourceItem* InitiateResource(LPCSTR name, INT type);
		_H3API_ VOID Dereference();
		_H3API_ VOID AddToResourceManager();
		_H3API_ VOID IncreaseReferences();
		_H3API_ INT32 References() const;
		_H3API_ LPCSTR GetName() const;
		_H3API_ ~H3ResourceItem();
	};
	_H3API_ASSERT_SIZE_(H3ResourceItem);

	/**
	 * @brief same functionality as H3Palette565 except it does not derive from H3ResourceItem
	 * Hence it skips constructor/destructor. Used by H3LoadedPcx.
	 */
	struct H3BasePalette565
	{
		_H3API_SIZE_(0x21C);
	protected:
		h3align _f_00[28];

		_H3API_ H3Palette565* cast();
	public:
		// * +1C
		union
		{
#ifdef _H3API_CPLUSPLUS11_
			H3RGB565 color[256];
#else // older VS have issues with unions and non-default constructors
			RGB565 color[256];
#endif
			struct
			{
				H3RGB565 unusedColors[254];
				H3Palette32* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		// * as of HDmod 5.0 RC 63, Palette565 now contains a buffer of ARGB888 colors[256] located at &color[254]
		// * http://heroescommunity.com/viewthread.php3?TID=44581&PID=1503736#focus
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(H3Palette565& source);
		_H3API_ VOID CopyPalette(H3BasePalette565& source);

		_H3API_ VOID InitiateFromPalette888(const H3BasePalette888& palette);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;
		_H3API_ H3BasePalette565();
		_H3API_ H3BasePalette565(const H3Palette888& palette);
		_H3API_ H3BasePalette565(const H3BasePalette888& palette);
		_H3API_ ~H3BasePalette565();

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette565(H3BasePalette565&& other);
		_H3API_ H3BasePalette565& operator=(H3BasePalette565&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette565);
	/**
	 * @brief same functionality as H3Palette888 except it does not derive from H3ResourceItem
	 * Hence it skips constructor/destructor. Used by H3LoadedPcx and H3Font.
	 */
	struct H3BasePalette888
	{
		_H3API_SIZE_(0x31C);
	protected:
		h3align _f_00[28];
	public:
		// * +1C
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ ~H3BasePalette888();
		_H3API_ H3BasePalette888();
		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette888(H3BasePalette888&& other);
		_H3API_ H3BasePalette888& operator=(H3BasePalette888&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette888);

	/**
	 * @brief raii loader for h3 assets
	 * It is suggested to use the common type definitions
	 * @tparam T One of the data types that exist in ResourceManager
	 */
	template <typename T>
	class H3BinaryLoader
	{
	protected:
		T* m_binary;
	public:
		H3BinaryLoader();
		H3BinaryLoader(LPCSTR file_name);
		H3BinaryLoader(const H3String& file_name);
		H3BinaryLoader(T* binary_item);
		~H3BinaryLoader();
		void Set(T* binary);
		T* Get();
		T* Release();
		T* operator->();
		T* operator*();
		BOOL operator!();
		operator BOOL();
	};

#pragma pack(pop) /* align-4 */

	template<typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader() :
		m_binary()
	{
	}
	template <typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(LPCSTR file_name) :
		m_binary(T::Load(file_name))
	{
	}
	template <typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(const H3String& file_name) :
		m_binary(T::Load(file_name))
	{
	}
	template<typename T>
	inline H3BinaryLoader<T>::H3BinaryLoader(T* binary_item) :
		m_binary(binary_item)
	{
	}
	template<typename T>
	inline H3BinaryLoader<T>::~H3BinaryLoader()
	{
		if (m_binary)
			m_binary->Dereference();
	}
	template<typename T>
	inline void H3BinaryLoader<T>::Set(T* binary)
	{
		m_binary = binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::Get()
	{
		return m_binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::Release()
	{
		T* b = m_binary;
		m_binary = nullptr;
		return b;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::operator->()
	{
		return m_binary;
	}
	template<typename T>
	inline T* H3BinaryLoader<T>::operator*()
	{
		return m_binary;
	}
	template<typename T>
	inline BOOL H3BinaryLoader<T>::operator!()
	{
		return m_binary == nullptr;
	}
	template<typename T>
	inline H3BinaryLoader<T>::operator BOOL()
	{
		return m_binary != nullptr;
	}

} /* namespace h3 */
