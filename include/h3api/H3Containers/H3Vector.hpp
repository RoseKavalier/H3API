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

#include "h3api/H3Base.hpp"

#if defined(_H3API_STD_CONVERSIONS_) || defined(_H3API_STD_VECTOR_)
#include <vector>
#endif

namespace h3
{
	template<typename _Elem> struct H3Vector;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<typename _Elem>
	using Vector = H3Vector<_Elem>;
#endif /*_H3API_TEMPLATE_DECLARE_*/
	_H3API_DECLARE_(IndexVector);

#pragma pack(push, 4)
	/**
	 * @brief a vector following the H3 format
	 * @tparam _Elem type of element to store
	*/
	template<typename _Elem>
	struct H3Vector : H3Allocator
	{
		_H3API_SIZE_(0x10);
	protected:
		h3unk _allocator; // useless
		// * the first item, also start of list
		_Elem* m_first;
		// * the end of last item
		_Elem* m_end;
		// * end of allocated memory
		_Elem* m_capacity;

		_Elem* Allocate(UINT number);
		VOID Construct(_Elem* start, _Elem* finish);
		VOID Destruct(_Elem* start, _Elem* finish);
		VOID Deallocate();
		BOOL reserveExtra(INT32 number);

		UINT EXPAND_NUMBER(UINT minimumNeeded);
		static constexpr UINT MIN_ELEMENTS = 10;
		static constexpr UINT GROWTH_MULTIPLIER = 2 ;
	public:
		H3Vector();
		H3Vector(UINT number_elements);
		~H3Vector();

		H3Vector(const H3Vector<_Elem>& other);
		H3Vector<_Elem>& operator=(const H3Vector<_Elem>& other);

#ifdef _H3API_CPLUSPLUS11_
		H3Vector(H3Vector<_Elem>&& other);
		H3Vector<_Elem>& operator=(H3Vector<_Elem>&& other);
#endif

		void swap(H3Vector<_Elem>& other);

		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_Elem* begin();
		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_Elem* end();
		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_Elem* begin() const;
		// * this is used in combination of C++11 'for :' range-based for loop iterator operations
		_Elem* end() const;

		// * ~constructor
		VOID Init();
		// * ~destructor.
		VOID Deref();
		// * If list is empty
		BOOL IsEmpty() const;
		// * If vector is full
		BOOL IsFull() const;
		// * the number of items
		UINT32 Size() const;
		// * the number of items
		UINT32 Count() const;
		// * the maximum number of items
		UINT32 CountMax() const;
		// * calculates size
		UINT32 RawSize() const;
		// * calculates allocated size
		UINT32 RawSizeAllocated() const;
		// * removes the last item
		VOID RemoveLast();
		// * empties list
		VOID RemoveAll();
		// * Adds item
		_Elem* Add(const _Elem & item);
		// * Adds only 1 item, expands by only 1
		_Elem* AddOne(const _Elem & item);
		// * only for size 4 or references, H3 code
		VOID AddSize4(_Elem item);
		// * increases capacity
		BOOL Expand();
		// * returns First item
		_Elem *First();
		const _Elem *CFirst() const;
		_Elem& RFirst();
		const _Elem& CRFirst() const;
		// * returns Last item
		_Elem *Last();
		const _Elem *CLast() const;
		_Elem& RLast();
		const _Elem& CRLast() const;
		// * Add one item to end
		_Elem* Append(const _Elem& item);
		// * Add a single item, expanding by 1
		_Elem* Push(const _Elem& item);
		// * Removes last item and returns reference to it
		_Elem* Pop();
		// * Returns item at position, can be negative to get from end
		_Elem* At(UINT32 pos);
		const _Elem* At(UINT32 pos) const;
		// * returns reference to item at position
		_Elem& RAt(UINT32 pos);
		const _Elem& RAt(UINT32 pos) const;
		// * remove one item, elements shift left
		BOOL Remove(UINT32 pos);
		// * remove range, elements shift left
		BOOL Remove(UINT32 fromPos, UINT32 toPos);
		// * removes elements [first, last) (that is, last is excluded)
		BOOL Remove(_Elem* first, _Elem* last);
		// * removes element and shifts remaining left
		BOOL Remove(_Elem* elem);
		// * reserves a number of elements, always greater than current
		BOOL Reserve(UINT number);
		// * Sets the current size to the specified number, smaller or greater
		BOOL Resize(UINT number);

		// * returns reference to element at pos, positive only
		_Elem& operator[](UINT32 pos);
		_Elem& operator[](UINT32 pos) const;
		// * Adds item to end of list
		_Elem* operator+=(const _Elem& item);

		BOOL Insert(_Elem* position, _Elem* first, _Elem* last);
		BOOL Insert(_Elem* position, const _Elem& elem);

#ifdef _H3API_CPLUSPLUS11_
		_Elem* Add(_Elem&& item);
		_Elem* Push(_Elem&& item);
		_Elem* AddOne(_Elem&& item);
		_Elem* Append(_Elem&& item);
		_Elem* operator+=(_Elem&& item);
#endif

#ifdef _H3API_STD_CONVERSIONS_
		BOOL Insert(_Elem* position, typename std::vector<_Elem>::iterator first, typename std::vector<_Elem>::iterator last);
		H3Vector(const std::vector<_Elem>& vec);
		std::vector<_Elem> to_std_vector() const;
		H3Vector<_Elem>& operator=(const std::vector<_Elem>& vec);
#endif /* _H3API_STD_CONVERSIONS_ */
	};
	_H3API_ASSERT_SIZE_(H3Vector<h3unk>);

	/** @brief to choose a random index within a range, without repeating results*/
	struct H3IndexVector
	{
		_H3API_SIZE_(0x18);
	protected:
		INT    m_minimum;
		INT    m_availableCount;
		BOOL8  m_init; // essentially H3Vector<BOOL8>
		BOOL8* m_begin;
		BOOL8* m_end;
		BOOL8* m_capacity;
	public:
		_H3API_ H3IndexVector(INT min_num, INT max_num);
		_H3API_ ~H3IndexVector();
		// * never returns the same value
		// * returns InvalidIndex() if there are no non-selected indexes
		_H3API_ INT ChooseRandom();
		// * returns m_minimum - 1
		_H3API_ INT InvalidIndex();
	};
	_H3API_ASSERT_SIZE_(H3IndexVector);

#pragma pack(pop) /* align-4 */

/******************************************************************************************
*
*						Using std::vector in place of H3Vector
*
******************************************************************************************/

#ifdef _H3API_STD_VECTOR_
#if defined(_MSC_VER) && (_MSC_VER >= 1800) // in VS2008, std::vector has size 20~24 which is not compatible.

#ifndef _DEBUG
#pragma pack(push, 4)
	/**
	 * @brief Required padding for H3StdVector<> to match H3Vector<> format
	*/
	class H3AllocatorReference
	{
		h3unk m_allocatorReference;
	};
#pragma pack(pop)
#endif

#ifdef _DEBUG // debug std::vector can be used directly as H3Vector
	/**
	 * @brief std::vector that is valid to be used as a H3Vector in debug format
	 *
	 * @tparam T type of element to store
	*/
	template<typename T>
	struct H3StdVector : public std::vector<T, H3ObjectAllocator<T>>
#else // non-debug std::vector requires padding to use as H3Vector
	/**
	 * @brief std::vector that is valid to be used as a H3Vector in non-debug format
	 *
	 * @tparam T type of element to store
	*/
	template<typename T>
	struct H3StdVector : H3AllocatorReference, public std::vector<T, H3ObjectAllocator<T>>

#endif /* _DEBUG */
		// implementation
	{
		_H3API_SIZE_(0x10);
	public:
		using std::vector<T, H3ObjectAllocator<T>>::vector; // inherit constructors
	};
	_H3API_ASSERT_SIZE_(H3StdVector<h3unk>);
#endif /* defined(_MSC_VER) && (_MSC_VER >= 1800) */
#endif /* _H3API_STD_VECTOR_ */

	_H3API_NAMED_STRUCT_(H3Vector<INT32>, BattleShadowHexes, 0x493EA1 + 1);

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Allocate(UINT number)
	{
		return H3ObjectAllocator< _Elem>().allocate(number);
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Construct(_Elem* start, _Elem* finish)
	{
		while (start < finish)
		{
			H3ObjectAllocator< _Elem>().construct(start);
			++start;
		}
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Destruct(_Elem* start, _Elem* finish)
	{
		while (start < finish)
		{
			H3ObjectAllocator< _Elem>().destroy(start);
			++start;
		}
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Deallocate()
	{
		H3ObjectAllocator<_Elem>().deallocate(m_first);
	}

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::reserveExtra(INT32 number)
	{
		const INT32 count = Count();
		const INT32 capacity = CountMax();
		const INT32 avail = capacity - count;
		if (avail >= number)
			return TRUE;

		return Reserve(EXPAND_NUMBER(number));
	}
	template<typename _Elem>
	inline UINT H3Vector<_Elem>::EXPAND_NUMBER(UINT minimumNeeded)
	{
		UINT cap = CountMax();
		UINT num = std::max(cap * GROWTH_MULTIPLIER, MIN_ELEMENTS);
		return std::max(num, minimumNeeded);
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(UINT number_elements) :
		m_first(nullptr),
		m_end(nullptr),
		m_capacity(nullptr)
	{
		Reserve(number_elements);
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector() :
		m_first(nullptr),
		m_end(nullptr),
		m_capacity(nullptr)
	{
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(H3Vector<_Elem>&& other) :
		m_first(other.m_first), m_end(other.m_end), m_capacity(other.m_capacity)
	{
		other.m_first    = nullptr;
		other.m_end      = nullptr;
		other.m_capacity = nullptr;
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(H3Vector<_Elem>&& other)
	{
		if (&other == this)
			return *this;
		RemoveAll();
		m_first = other.m_first;
		m_end = other.m_end;
		m_capacity = other.m_capacity;
		other.m_first = nullptr;
		other.m_end = nullptr;
		other.m_capacity = nullptr;
		return *this;
	}
	template<typename _Elem>
	inline void H3Vector<_Elem>::swap(H3Vector<_Elem>& other)
	{
		if (&other == this)
			return;

		_Elem* first = m_first;
		_Elem* last = m_end;
		_Elem* cap = m_capacity;
		m_first = other.m_first;
		m_end = other.m_end;
		m_capacity = other.m_capacity;
		other.m_first = first;
		other.m_end = last;
		other.m_capacity = cap;
	}
#endif

	template<typename _Elem>
	inline H3Vector<_Elem>::~H3Vector()
	{
		Deref();
	}
	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(const H3Vector<_Elem>& other)
	{
		UINT num = other.Size();
		Resize(num);
		for (UINT i = 0; i < num; ++i)
			(*this)[i] = other[i];
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(const H3Vector<_Elem>& other)
	{
		if (&other == this)
			return *this;
		RemoveAll();
		UINT num = other.Size();
		Resize(num);
		for (UINT i = 0; i < num; ++i)
			(*this)[i] = other[i];
		return *this;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::begin()
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::end()
	{
		return m_end;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::begin() const
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::end() const
	{
		return m_end;
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Init()
	{
		m_first = nullptr;
		m_end = nullptr;
		m_capacity = nullptr;
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::Deref()
	{
		if (m_first)
		{
			Destruct(begin(), end());
			Deallocate();
		}
		m_first = nullptr;
		m_end = nullptr;
		m_capacity = nullptr;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::IsEmpty() const
	{
		if (!m_first || m_first == m_end)
			return TRUE;
		return FALSE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::IsFull() const
	{
		if (m_end == m_capacity)
			return TRUE;
		return FALSE;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::Size() const
	{
		return m_end - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::Count() const
	{
		return m_end - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::CountMax() const
	{
		return m_capacity - m_first;
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::RawSize() const
	{
		return UINT32(m_end) - UINT32(m_first);
	}
	template<typename _Elem>
	inline UINT32 H3Vector<_Elem>::RawSizeAllocated() const
	{
		return UINT32(m_capacity) - UINT32(m_first);
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::RemoveLast()
	{
		Pop();
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::RemoveAll()
	{
		for (_Elem* i = begin(); i < end(); ++i)
			i->~_Elem();

		m_end = m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Add(const _Elem& item)
	{
		if (!m_first || IsFull())
		{
			if (!Expand())
				return nullptr; // failed
		}
		*m_end = item;
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::AddOne(const _Elem& item)
	{
		if (!m_first)
		{
			if (!Reserve(1))
				return nullptr;
		}
		else if (IsFull())
		{
			if (!Reserve(CountMax() + 1))
				return nullptr;
		}
		*m_end = item;
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline VOID H3Vector<_Elem>::AddSize4(_Elem item)
	{
		THISCALL_4(VOID, 0x5FE2D0, this, m_end, 1, &item);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Expand()
	{
		if (!m_first)
			return Reserve(MIN_ELEMENTS);
		return Reserve(CountMax() * GROWTH_MULTIPLIER);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::First()
	{
		return m_first;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::CFirst() const
	{
		return m_first;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RFirst()
	{
		return *m_first;
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::CRFirst() const
	{
		return *m_first;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Last()
	{
		return m_end - 1;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::CLast() const
	{
		return m_end - 1;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RLast()
	{
		return *Last();
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::CRLast() const
	{
		return *CLast();
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Append(const _Elem& item)
	{
		return Add(item);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Push(const _Elem& item)
	{
		return Add(item);
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Pop()
	{
		if (m_end > m_first)
		{
			--m_end;
			m_end->~_Elem();
		}
		return m_end;
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::At(UINT32 pos)
	{
		return m_first + pos;
	}
	template<typename _Elem>
	inline const _Elem* H3Vector<_Elem>::At(UINT32 pos) const
	{
		return m_first + pos;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::RAt(UINT32 pos)
	{
		return *At(pos);
	}
	template<typename _Elem>
	inline const _Elem& H3Vector<_Elem>::RAt(UINT32 pos) const
	{
		return *At(pos);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(UINT32 pos)
	{
		return Remove(begin() + pos, begin() + pos + 1);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(UINT32 fromPos, UINT32 toPos)
	{
		return Remove(begin() + fromPos, begin() + toPos);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(_Elem* first, _Elem* last)
	{
		if (first >= last || IsEmpty())
			return FALSE;
		if (first < m_first)
			first = m_first;
		if (last > m_end)
			last = m_end;

		Destruct(first, last);
#ifdef _H3API_CPLUSPLUS11_
		_Elem* itFirst = first;
		_Elem* itLast = last;
		while (itLast < m_end)
		{
			*itFirst = std::move(*itLast);
			++itFirst;
			++itLast;
		}
#else
		memmove(PVOID(first), PVOID(last), UINT(m_end) - UINT(last));
#endif
		m_end -= last - first;

		return TRUE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Remove(_Elem* elem)
	{
		return Remove(elem, elem + 1);
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Reserve(UINT number)
	{
		UINT num = Count();
		if (number <= num)
			return TRUE;

		_Elem* t = Allocate(number);
		if (!t)
			return FALSE;

		Construct(&t[0], &t[number]);

#ifdef _H3API_CPLUSPLUS11_
		for (UINT i = 0; i < num; ++i)
			t[i] = std::move(m_first[i]);
#else
		for (UINT i = 0; i < num; ++i)
			t[i] = m_first[i];
#endif
		Destruct(begin(), end());
		Deallocate();

		m_first = t;
		m_end = m_first + num;
		m_capacity = m_first + number;

		return TRUE;
	}
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Resize(UINT number)
	{
		const UINT count = Count();

		if (number == count)
		{
			m_end = m_capacity;
			return TRUE;
		}
		if (number > count)
		{
			if (!Reserve(number))
				return FALSE;
			m_end = m_capacity;
			return TRUE;
		}

		// number < count

		Destruct(begin() + number, end());
		m_end = m_first + number;
		_Elem* t = Allocate(number);
		if (!t)
			return FALSE;

		Construct(t, t + number);

#ifdef _H3API_CPLUSPLUS11_
		for (UINT i = 0; i < number; ++i)
			t[i] = std::move(m_first[i]);
#else
		for (UINT i = 0; i < number; ++i)
			t[i] = m_first[i];
#endif
		Destruct(begin(), end());
		Deallocate();

		m_first = t;
		m_end = m_first + number;
		m_capacity = m_end;

		return TRUE;
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::operator[](UINT32 pos)
	{
		return m_first[pos];
	}
	template<typename _Elem>
	inline _Elem& H3Vector<_Elem>::operator[](UINT32 pos) const
	{
		return m_first[pos];
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::operator+=(const _Elem& item)
	{
		return Add(item);
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Add(_Elem&& item)
	{
		if (!m_first || IsFull())
		{
			if (!Expand())
				return nullptr; // failed
		}
		*m_end = std::move(item);
		++m_end;
		return m_end - 1;  // returns position where it was added
	}
	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Push(_Elem&& item)
	{
		return Add(std::move(item));
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::AddOne(_Elem&& item)
	{
		if (!m_first)
		{
			if (!Reserve(1))
				return nullptr;
		}
		else if (IsFull())
		{
			if (!Reserve(CountMax() + 1))
				return nullptr;
		}
		*m_end = std::move(item);
		++m_end;
		return m_end - 1;  // returns position where it was added
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::Append(_Elem&& item)
	{
		return Add(std::move(item));
	}

	template<typename _Elem>
	inline _Elem* H3Vector<_Elem>::operator+=(_Elem&& item)
	{
		return Add(std::move(item));
	}
#endif /* _H3API_CPLUSPLUS11_ */

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, _Elem* first, _Elem* last)
	{
		if (UINT(first) >= UINT(last))
			return FALSE;

		const UINT32 num = last - first;
		const UINT32 currNum = Count();
		UINT32 pos = 0;
		if (!IsEmpty())
		{
			if (UINT(position) > UINT(begin()))
			{
				if (UINT(position) > UINT(end()))
					pos = currNum;
				else
					pos = position - begin();
			}
		}

		if (!reserveExtra(num))
			return FALSE;

		// move elements to end
		_Elem* origStart = begin() + pos;
		_Elem* newEnd = end() + num - 1;
		_Elem* oldEnd = end() - 1;
		if (pos < currNum)
		{
			while (oldEnd >= origStart)
			{
#ifdef _H3API_CPLUSPLUS11_
				* newEnd-- = std::move(*oldEnd--);
#else
				* newEnd-- = *oldEnd--;
#endif
			}
		}

		// Insert new elements
		_Elem* it = first;
		while (it < last)
		{
			*origStart++ = *it++;
		}

		m_end += num;

		return TRUE;
	}

	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, const _Elem& elem)
	{
		_Elem* first = const_cast<_Elem*>(&elem);
		_Elem* last = first + 1;
		return Insert(position, first, last);
	}

#ifdef _H3API_STD_CONVERSIONS_
	template<typename _Elem>
	inline BOOL H3Vector<_Elem>::Insert(_Elem* position, typename std::vector<_Elem>::iterator first, typename std::vector<_Elem>::iterator last)
	{
		if (first >= last)
			return FALSE;

		const INT32 num = std::distance(first, last);
		const INT32 currNum = Count();
		INT32 pos = 0;
		if (!IsEmpty())
		{
			if (UINT(position) > UINT(begin()))
			{
				if (UINT(position) > UINT(end()))
					pos = currNum;
				else
					pos = position - begin();
			}
		}

		if (!reserveExtra(num))
			return FALSE;

		// move elements to end
		_Elem* origStart = begin() + pos;
		_Elem* newEnd = end() + num - 1;
		_Elem* oldEnd = end() - 1;
		if (pos < currNum)
		{
			while (oldEnd >= origStart)
			{
#ifdef _H3API_CPLUSPLUS11_
				* newEnd-- = std::move(*oldEnd--);
#else
				* newEnd-- = *oldEnd--;
#endif /* _H3API_CPLUSPLUS11_ */
			}
		}

		// Insert new elements
		while (first < last)
		{
			*origStart++ = *first++;
		}
		m_end += num;

		return TRUE;
	}

	template<typename _Elem>
	inline H3Vector<_Elem>::H3Vector(const std::vector<_Elem>& vec)
	{
		Init();
		const INT n = vec.size();
		Reserve(n);
		for (int i = 0; i < n; ++i)
			Add(const_cast<_Elem&>(vec[i]));
		return *this;
	}
	template<typename _Elem>
	inline std::vector<_Elem> H3Vector<_Elem>::to_std_vector() const
	{
		std::vector<_Elem> vec;
		for (_Elem* i = begin(); i < end(); ++i)
			vec.push_back(*i);

		return vec;
	}
	template<typename _Elem>
	inline H3Vector<_Elem>& H3Vector<_Elem>::operator=(const std::vector<_Elem>& vec)
	{
		RemoveAll();
		const INT n = vec.size();
		Reserve(n);
		for (int i = 0; i < n; ++i)
			Add(const_cast<_Elem&>(vec[i]));
		return *this;
	}
#endif /* _H3API_STD_CONVERSIONS_ */
}
