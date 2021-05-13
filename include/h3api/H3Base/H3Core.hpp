//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-05                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base/H3Config.hpp"

namespace h3
{
	/* POINT is a common Win type, don't play with fire! */
	struct H3POINT;
	_H3API_DECLARE_(Point);
	_H3API_DECLARE_(Position);
	template<typename T> class H3Map;
	template<typename T> class H3FastMap;

	typedef H3Map<UINT16>     H3Map_UINT16;
	typedef H3FastMap<UINT16> H3FastMap_UINT16;

	/** @brief Null string ""*/
	LPCSTR const h3_NullString = LPCSTR(0x63A608);
	/** @brief 512 bytes of char buffer to be used for printing text*/
	PCHAR  const h3_TextBuffer = PCHAR(0x697428);
	/** @brief path to the main directory of the game*/
	LPCSTR const h3_GamePath   = LPCSTR(0x698614);
	/** @brief a text buffer used to save the game*/
	PCHAR  const h3_SaveName   = PCHAR(0x69FC88);

	/** @brief detects H3 exe version at runtime*/
	class H3Version
	{
	public:
		_H3API_ENUM_ GameVersion : INT32
		{
			UNKNOWN         = -1,
			ROE             = 0,
			SOD             = 1,
			SOD_POLISH_GOLD = 2,
			HOTA            = 3,
			ERA             = 4,
			WOG             = 5,
		};
		/** @brief the constructor is required to detect the exe type*/
		_H3API_ H3Version();
		/**
		 * @brief returns the detected exe version
		 *
		 * @return GameVersion a value matching the current exe
		 */
		_H3API_ GameVersion version() const;
		/**
		 * @brief compares the exe version to Restoration of Erathia
		 * @return true if the current exe is RoE
		 */
		_H3API_ BOOL roe()  const;
		/**
		 * @brief compares the exe version to Shadow of Death 3.2
		 * @return true if the current exe is SoD 3.2
		 */
		_H3API_ BOOL sod()  const;
		/**
		 * @brief compares the exe version to Horn of the Abyss
		 * @return true if the current exe is HotA
		 */
		_H3API_ BOOL hota() const;
		/**
		 * @brief compares the exe version to ERA II
		 * @return true if the current exe is ERA
		 */
		_H3API_ BOOL era()  const;
		/**
		 * @brief compares the exe version to Wake of Gods
		 * @return true if the current exe is WOG
		 */
		_H3API_ BOOL wog()  const;
	private:
		GameVersion m_version;
	};

	// deprecate, use H3String:: variants
	namespace H3Numbers
	{
		/**
		 * @brief add thousands commas to numbers, e.g. 123,456 instead of 123456
		 * @param num the number to format
		 * @param out a char[] buffer to receive the formatted number
		 * @return number of bytes written
		 */
		_H3API_ INT32 AddCommas(INT32 num, CHAR* out);
		/**
		 * @brief show a number in short scale format with specified number of decimals
		 * e.g. 123,456,789 in short scale can be 123.5M for 1 decimal
		 * @param num the number to format
		 * @param out a char[] buffer to receive the formatted number
		 * @param decimals the number of decimals to use after the period
		 * @return number of bytes written
		 */
		_H3API_ INT32 MakeReadable(INT32 num, CHAR* out, INT32 decimals = 1);
	}

	namespace H3Error
	{
		/**
		 * @brief displays MessageBox with custom message and title
		 * @param message the message to be shown
		 * @param title title of the MessageBox
		 */
		_H3API_ VOID ShowError(LPCSTR message, LPCSTR title = "H3Error!");
		/**
		 * @brief displays MessageBox with custom message, title and OK / Cancel choice
		 * @param message the message to be shown
		 * @param title title of the MessageBox
		 * @return true if the user clicked OK
		 */
		_H3API_ BOOL ShowErrorChoice(LPCSTR message, LPCSTR title = "H3Error!");
		/**
		 * @brief displays MessageBox with custom UNICODE message and title
		 * @param message the message to be shown
		 * @param title title of the MessageBox
		 */
		_H3API_ VOID ShowErrorW(LPCWSTR message, LPCWSTR title = L"H3Error!");
		/**
		 * @brief displays MessageBox with custom UNICODE message, title and OK / Cancel choice
		 * @param message the message to be shown
		 * @param title title of the MessageBox
		 * @return true if the user clicked OK
		 */
		_H3API_ BOOL ShowErrorChoiceW(LPCWSTR message, LPCWSTR title = L"H3Error!");
	}

#pragma pack(push, 4)

	/** @brief represents a x-y point on the map, improves POINT*/
	struct H3POINT
	{
		INT32 x, y;

		_H3API_ H3POINT();
		_H3API_ H3POINT(INT32 x, INT32 y);
		_H3API_ H3POINT(const H3POINT& other);
		_H3API_ H3POINT(const ::POINT& point);
		_H3API_ BOOL     operator==(const H3POINT& other) const;
		_H3API_ BOOL     operator!=(const H3POINT& other) const;
		_H3API_ H3POINT& operator=(const  H3POINT& other);
		_H3API_ H3POINT& operator=(const  ::POINT& point);
		_H3API_ H3POINT& IncX(INT32 dx = 1);
		_H3API_ H3POINT& IncY(INT32 dy = 1);
		_H3API_ H3POINT& DecX(INT32 dx = 1);
		_H3API_ H3POINT& DecY(INT32 dy = 1);
		_H3API_ H3POINT& operator+(const H3POINT& other);
		_H3API_ H3POINT& operator-(const H3POINT& other);
		_H3API_ VOID     Clamp(INT32 map_size);
		_H3API_ VOID     Clamp();
		_H3API_ H3POINT& GetCurrentCursorPosition();

		_H3API_ static H3POINT GetCursorPosition();
		_H3API_ static VOID    GetCursorPosition(INT32& x, INT32& y);
		_H3API_ static VOID    GetCursorPosition(H3POINT& p);
	};

	/** @brief represents a x-y-z point on the map*/
	struct H3Point
	{
		INT32 x;
		INT32 y;
		INT32 z;

		_H3API_ H3Point();
		_H3API_ H3Point(INT32 x, INT32 y, INT32 z);
		_H3API_ H3Point(const H3Point& pt);
		_H3API_ H3Point(const H3Position& pos);
		_H3API_ H3Point& operator=(const H3Point& pt);
		_H3API_ H3Point& operator=(const H3Position& pos);
		_H3API_ BOOL     operator==(const H3Point& pt) const;
		_H3API_ BOOL     operator==(const H3Position& pos) const;
		_H3API_ BOOL     operator!=(const H3Point& pt) const;
		_H3API_ BOOL     operator!=(const H3Position& pos) const;
		_H3API_ UINT32   Pack() const;
		_H3API_ VOID     Clamp(INT32 map_size);
		_H3API_ VOID     Clamp();
		_H3API_ H3Point& IncX(INT32 dx = 1);
		_H3API_ H3Point& IncY(INT32 dy = 1);
		_H3API_ H3Point& DecX(INT32 dx = 1);
		_H3API_ H3Point& DecY(INT32 dy = 1);
	}; /* H3Point */

	/** @brief stored (x,y,z) coordinates in a bitfield following h3 format*/
	struct H3Position
	{
	protected:
		UINT pos;
	public:
		_H3API_ H3Position();
		_H3API_ H3Position(UINT32 mixed_position);
		_H3API_ H3Position(const H3Position& other);
		_H3API_ H3Position(INT16 x, INT16 y, INT8 z);
		_H3API_ H3Position(const H3Point& pt);
		_H3API_ VOID operator=(const H3Position& other);
		_H3API_ VOID operator=(const H3Point& pt);
		_H3API_ VOID operator=(UINT32 mixed_position);
		_H3API_ BOOL operator==(const H3Position& other) const;
		_H3API_ BOOL operator==(const H3Point& other) const;
		_H3API_ BOOL operator!=(const H3Position& other) const;
		_H3API_ BOOL operator!=(const H3Point& other) const;
		_H3API_ UINT32 operator*() const;
		// * Cast operator
		_H3API_ operator UINT () const;
		// * returns the packed coordinates
		_H3API_ UINT Mixed() const;
		// * returns x from coordinates
		_H3API_ UINT GetX() const;
		// * returns y from coordinates
		_H3API_ UINT GetY() const;
		// * returns z from coordinates
		_H3API_ UINT8 GetZ() const;
		// * provided variables x, y, z, unpacks the coordinates to those variables
		_H3API_ VOID GetXYZ(INT& x, INT& y, INT& z) const;
		// * modifies x
		_H3API_ VOID SetX(INT16 x);
		// * modifies y
		_H3API_ VOID SetY(INT16 y);
		// * modifies z
		_H3API_ VOID SetZ(INT16 z);
		// * modifies x, y and z
		_H3API_ VOID SetXYZ(INT x, INT y, INT z);
		_H3API_ H3Point Unpack() const;
		// * Can be used on the stack safely to pack coordinates
		_H3API_ static UINT Pack(INT x, INT y, INT z);
		_H3API_ static UINT Pack(const H3Point& pt);
		// * Can be used on the stack safely to unpack coordinates
		_H3API_ static VOID UnpackXYZ(UINT coord, INT& x, INT& y, INT& z);
		// * Can be used on the stack safely to unpack X
		_H3API_ static UINT UnpackX(UINT coord);
		// * Can be used on the stack safely to unpack Y
		_H3API_ static UINT UnpackY(UINT coord);
		// * Can be used on the stack safely to unpack Z
		_H3API_ static UINT8 UnpackZ(UINT coord);
	}; /* H3Position */

	/**
	 * @brief represents T* array as [x][y][z] map since they are created as T* map = new T[number_cells];
	 * maps are always square in h3 so only 1 dimension is used for x & y
	 * @tparam T type of the map object
	 */
	template<typename T>
	class H3Map
	{
	public:
		typedef T* pointer;
		typedef T& reference;

		/** @brief incrementable iterator to to go over the map's span*/
		class iterator
		{
		public:
			/**
			 * @brief Construct a new iterator object
			 * @param it an existing iterator
			 */
			iterator(const iterator& it);
			/**
			 * @brief Construct a new iterator object
			 * @param map base array of the map
			 * @param x 0..mapsize-1
			 * @param y 0..mapsize-1
			 * @param z 0..1
			 */
			iterator(H3Map* map, UINT x, UINT y, UINT z);
			/**
			 * @brief Construct a new iterator object without known coordinates
			 * @param map base array of the map
			 * @param item an object from the current map
			 */
			iterator(H3Map* map, pointer item);
			/**
			 * @brief equality comparison
			 * @param it another iterator
			 * @return BOOL whether both iterators are equal
			 */
			BOOL      operator==(const iterator& it) const;
			/**
			 * @brief inequality comparison
			 * @param it another iterator
			 * @return BOOL whether both iterators are different
			 */
			BOOL      operator!=(const iterator& it) const;
			/**
			 * @brief pre-increment
			 * @return itself
			 */
			iterator& operator++();
			/**
			 * @brief post-increment
			 * @return copy of itself before increment
			 */
			iterator  operator++(int);
			/** @brief direct access to T contents and methods*/
			pointer   operator->() const;
			/**
			 * @brief get address of iterator state
			 * @return pointer address of current map cell
			 */
			pointer   operator&() const;
			/**
			 * @brief dereference iterator state
			 * @return reference to current map cell
			 */
			reference operator*() const;
			/**
			 * @brief allows inspection of map cells at an offset from the current one
			 * @param dx horizontal difference
			 * @param dy vertical difference
			 * @return reference to the map cell at specified offset
			 */
			reference operator()(INT32 dx, INT32 dy) const;
			/**
			 * @brief computes the current map cell's horizontal position
			 * @return UINT 0..mapsize-1
			 */
			UINT      GetX() const;
			/**
			 * @brief computes the current map cell's vertical position
			 * @return UINT 0..mapsize-1
			 */
			UINT      GetY() const;
			/**
			 * @brief computes the current map cell's level
			 * @return UINT 0..1
			 */
			UINT      GetZ() const;
			/**
			 * @brief computes the current map cell's position
			 * @return H3Point (x,y,z)
			 */
			H3Point   Get() const;
		private:
			pointer m_current;
			UINT    m_x;
			UINT    m_y;
			UINT    m_z;
			H3Map* m_map;
		};
		/**
		 * @brief Construct a new H3Map object
		 * @param base the start of the map array
		 * @param map_size the unique dimension size since maps are square
		 * @param has_underground whether an underground level is present
		 */
		H3Map(pointer base, UINT map_size, BOOL has_underground);
		/**
		 * @brief the first map cell of the array
		 * @return iterator (0, 0, 0)
		 */
		iterator begin();
		/**
		 * @brief 1 beyond the last cell of the array
		 * @return iterator (0, 0, 1 or 2) depending on underground
		 */
		iterator end();
		/**
		 * @brief obtain an iterator for the specified position
		 * @param x 0..mapsize-1
		 * @param y 0..mapsize-1
		 * @param z 0..1
		 * @return iterator the specified position
		 */
		iterator operator()(UINT x, UINT y, UINT z);
		/**
		 * @brief get a reference to the map cell at specified position
		 * @param x 0..mapsize-1
		 * @param y 0..mapsize-1
		 * @param z 0..1
		 * @return reference the specified position
		 */
		reference At(UINT x, UINT y, UINT z);

	private:
		pointer at(UINT x, UINT y, UINT z);

		pointer m_base;
		UINT    m_dimensions;
		UINT    m_levels;
	};

	/**
	 * @brief same as H3Map except it doesn't keep track of coordinates
	 * you can recover MapIterator's coordinates through H3FastMap::GetCoordinates(FastMapIterator)
	 * @tparam T type of the map object
	 */
	template<typename T>
	class H3FastMap
	{
	public:
		typedef T* pointer;
		typedef T& reference;

		/** @brief incrementable iterator to to go over the map's span*/
		class iterator
		{
		public:
			/**
			 * @brief Construct a new iterator object
			 * @param it an existing iterator
			 */
			iterator(const iterator& it);
			/**
			 * @brief Construct a new iterator object
			 * @param map base array of the map
			 * @param x 0..mapsize-1
			 * @param y 0..mapsize-1
			 * @param z 0..1
			 */
			iterator(H3FastMap* map, UINT x, UINT y, UINT z);
			/**
			 * @brief Construct a new iterator object without known coordinates
			 * @param map base array of the map
			 * @param item an object from the current map
			 */
			iterator(pointer item, UINT map_size);
			/**
			 * @brief equality comparison
			 * @param it another iterator
			 * @return BOOL whether both iterators are equal
			 */
			BOOL      operator==(const iterator& it) const;
			/**
			 * @brief inequality comparison
			 * @param it another iterator
			 * @return BOOL whether both iterators are different
			 */
			BOOL      operator!=(const iterator& it) const;
			/**
			 * @brief pre-increment
			 * @return itself
			 */
			iterator& operator++();
			/**
			 * @brief post-increment
			 * @return copy of itself before increment
			 */
			iterator  operator++(int);
			/**
			 * @brief allows inspection of map cells at an offset from the current one
			 * @param dx horizontal difference
			 * @param dy vertical difference
			 * @return reference to the map cell at specified offset
			 */
			reference operator()(INT32 dx, INT32 dy) const;
			/**
			 * @brief dereference iterator state
			 * @return reference to current map cell
			 */
			reference operator*() const;
			/**
			 * @brief get address of iterator state
			 * @return pointer address of current map cell
			 */
			pointer   operator&() const;
			/** @brief direct access to T contents and methods*/
			pointer   operator->() const;
		private:
			pointer m_current;
			UINT    m_dimensions;
		};

		/**
		 * @brief Construct a new H3FastMap object
		 * @param base the start of the map array
		 * @param map_size the unique dimension size since maps are square
		 * @param has_underground whether an underground level is present
		 */
		H3FastMap(pointer base, UINT map_size, BOOL has_underground);
		/**
		 * @brief the first map cell of the array
		 * @return iterator (0, 0, 0)
		 */
		iterator  begin();
		/**
		 * @brief 1 beyond the last cell of the array
		 * @return iterator (0, 0, 1 or 2) depending on underground
		 */
		iterator  end();
		/**
		 * @brief obtain an iterator for the specified position
		 * @param x 0..mapsize-1
		 * @param y 0..mapsize-1
		 * @param z 0..1
		 * @return iterator the specified position
		 */
		iterator  operator()(UINT x, UINT y, UINT z);
		/**
		 * @brief get a reference to the map cell at specified position
		 * @param x 0..mapsize-1
		 * @param y 0..mapsize-1
		 * @param z 0..1
		 * @return reference the specified position
		 */
		reference At(UINT x, UINT y, UINT z);
		/**
		 * @brief Calculate coordinates from an iterator
		 * @param it an iterator of the current map
		 * @return H3Point (x, y, z) position of the iterator
		 */
		H3Point   GetCoordinates(const iterator& it) const;
		/**
		 * @brief Get coordinates from a map cell
		 * @param item a cell from the current map
		 * @return H3Point (x, y, z) position of the iterator
		 */
		H3Point   GetCoordinates(const pointer item) const;
	private:
		pointer at(UINT x, UINT y, UINT z);

		pointer m_base;
		UINT    m_dimensions;
		UINT    m_levels;
	};
#pragma pack(pop) /* align-4 */

	template<typename T>
	inline H3Map<T>::iterator::iterator(const iterator& it) :
		m_current(it.m_current),
		m_x(it.m_x),
		m_y(it.m_y),
		m_z(it.m_z),
		m_map(it.m_map)
	{
	}
	template<typename T>
	inline H3Map<T>::iterator::iterator(H3Map* map, UINT x, UINT y, UINT z) :
		m_current(map->at(x, y, z)),
		m_x(x),
		m_y(y),
		m_z(z),
		m_map(map)
	{
	}
	template<typename T>
	inline H3Map<T>::iterator::iterator(H3Map* map, pointer item) :
		m_current(item),
		m_map(map)
	{
		UINT delta = item - map->m_base;
		m_x = delta % map->m_dimensions;
		delta /= map->m_dimensions;
		m_y = delta % map->m_dimensions;
		m_z = delta / map->m_dimensions;
	}
	template<typename T>
	inline BOOL H3Map<T>::iterator::operator==(const iterator& it) const
	{
		return m_current == it.m_current;
	}
	template<typename T>
	inline BOOL H3Map<T>::iterator::operator!=(const iterator& it) const
	{
		return m_current != it.m_current;
	}
	template<typename T>
	inline typename H3Map<T>::iterator& H3Map<T>::iterator::operator++()
	{
		++m_current;
		if (++m_x < m_map->m_dimensions)
			return *this;
		m_x = 0;
		if (++m_y < m_map->m_dimensions)
			return *this;
		m_y = 0;
		++m_z;
		return *this;
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::iterator::operator++(int)
	{
		iterator it(*this);
		++(*this);
		return it;
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::iterator::operator->() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::iterator::operator&() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::iterator::operator*() const
	{
		return *m_current;
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::iterator::operator()(INT32 dx, INT32 dy) const
	{
		return m_current[dx + m_map->m_dimensions * dy];
	}

	template<typename T>
	inline UINT H3Map<T>::iterator::GetX() const
	{
		return m_x;
	}
	template<typename T>
	inline UINT H3Map<T>::iterator::GetY() const
	{
		return m_y;
	}
	template<typename T>
	inline UINT H3Map<T>::iterator::GetZ() const
	{
		return m_z;
	}
	template<typename T>
	inline H3Point H3Map<T>::iterator::Get() const
	{
		return H3Point(m_x, m_y, m_z);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::begin()
	{
		return iterator(this, 0, 0, 0);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::end()
	{
		return iterator(this, 0, 0, m_levels);
	}
	template<typename T>
	inline typename H3Map<T>::iterator H3Map<T>::operator()(UINT x, UINT y, UINT z)
	{
		return iterator(this, x, y, z);
	}
	template<typename T>
	inline H3Map<T>::H3Map(pointer base, UINT map_size, BOOL has_underground) :
		m_base(base),
		m_dimensions(map_size),
		m_levels(has_underground ? 2 : 1)
	{
	}
	template<typename T>
	inline typename H3Map<T>::reference H3Map<T>::At(UINT x, UINT y, UINT z)
	{
		return *at(x, y, z);
	}
	template<typename T>
	inline typename H3Map<T>::pointer H3Map<T>::at(UINT x, UINT y, UINT z)
	{
		return &m_base[x + m_dimensions * (y + z * m_dimensions)];
	}

	template<typename T>
	inline BOOL H3FastMap<T>::iterator::operator==(const iterator& it) const
	{
		return m_current == it.m_current;
	}

	template<typename T>
	inline BOOL H3FastMap<T>::iterator::operator!=(const iterator& it) const
	{
		return m_current != it.m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::iterator& H3FastMap<T>::iterator::operator++()
	{
		++m_current;
		return *this;
	}

	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::iterator::operator++(int)
	{
		iterator it(*this);
		++m_current;
		return it;
	}

	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::iterator::operator()(INT32 dx, INT32 dy) const
	{
		return m_current[dx + m_dimensions * dy];
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(const iterator& it) :
		m_current(it.m_current),
		m_dimensions(it.m_dimensions)
	{
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(H3FastMap* map, UINT x, UINT y, UINT z) :
		m_current(map->at(x, y, z)),
		m_dimensions(map->m_dimensions)
	{
	}

	template<typename T>
	inline H3FastMap<T>::iterator::iterator(pointer item, UINT map_size) :
		m_current(item),
		m_dimensions(map_size)
	{
	}

	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::iterator::operator*() const
	{
		return *m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::iterator::operator&() const
	{
		return m_current;
	}

	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::iterator::operator->() const
	{
		return m_current;
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::begin()
	{
		return iterator(this, 0, 0, 0);
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::end()
	{
		return iterator(this, 0, 0, m_levels);
	}
	template<typename T>
	inline typename H3FastMap<T>::iterator H3FastMap<T>::operator()(UINT x, UINT y, UINT z)
	{
		return iterator(this, x, y, z);
	}
	template<typename T>
	inline H3FastMap<T>::H3FastMap(pointer base, UINT map_size, BOOL has_underground) :
		m_base(base),
		m_dimensions(map_size),
		m_levels(has_underground ? 2 : 1)
	{
	}
	template<typename T>
	inline typename H3FastMap<T>::reference H3FastMap<T>::At(UINT x, UINT y, UINT z)
	{
		return *at(x, y, z);
	}
	template<typename T>
	inline H3Point H3FastMap<T>::GetCoordinates(const iterator& it) const
	{
		return GetCoordinates(&it);
	}
	template<typename T>
	inline H3Point H3FastMap<T>::GetCoordinates(const pointer item) const
	{
		H3Point p;
		UINT delta = item - m_base;
		p.x        = delta % m_dimensions;
		delta     /= m_dimensions;
		p.y        = delta % m_dimensions;
		p.z        = delta / m_dimensions;
		return p;
	}
	template<typename T>
	inline typename H3FastMap<T>::pointer H3FastMap<T>::at(UINT x, UINT y, UINT z)
	{
		return &m_base[x + m_dimensions * (y + z * m_dimensions)];
	}

} /* namespace h3 */
