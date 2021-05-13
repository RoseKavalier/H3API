//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-15                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base/H3Core.hpp"

namespace h3
{
	template <typename T> struct H3ObjectAllocator;
	template <typename T> struct H3ArrayAllocator;
	template <typename T> struct H3AutoPtr;
	template <typename T, typename Allocator> struct H3UniquePtr;
#ifdef _H3API_TEMPLATE_DECLARE_
	template <typename T>
	using ObjectAllocator = H3ObjectAllocator<T>;
	template <typename T>
	using ArrayAllocator  = H3ArrayAllocator<T>;
	template <typename T>
	using AutoPtr         = H3AutoPtr<T>;
	template <typename T, typename Allocator>
	using UniquePtr       = H3UniquePtr<T, Allocator>;
#endif /* _H3API_TEMPLATE_DECLARE_ */

	/** @brief Common allocator type for Byte objects */
	typedef H3ObjectAllocator<BYTE> ByteAllocator;
	/** @brief Common allocator type for char objects */
	typedef H3ObjectAllocator<CHAR> CharAllocator;

#pragma pack(push, 4)

	/**
	 * @brief heap realloc using H3 assets
	 * @param obj memory block previously allocated by H3
	 * @param new_size the sought size of the new memory block
	 * @return reallocated memory block
	 */
	_H3API_ PVOID H3Realloc(PVOID obj, UINT new_size);
	/**
	 * @brief calloc using H3 assets
	 * @param count the number of objects to allocate and null
	 * @param size sizeof() these objects
	 * @return allocated memory block initiated to 0s
	 */
	_H3API_ PVOID H3Calloc(UINT count, UINT size = 1);
	/**
	 * @brief heapalloc using H3 assets
	 * @param size the sought size of the memory block
	 * @return VOID* allocated memory nlock
	 */
	_H3API_ PVOID H3Malloc(UINT size);
	/**
	 * @brief heapfree using H3 assets
	 * @param obj a memory block previously allocated by H3
	 */
	_H3API_ VOID H3Free(PVOID obj);
	/**
	 * @brief Allocates an object using h3's malloc
	 * @tparam Type Object to be allocated
	 * @param count Number of objects to allocate
	 * @return Number of objects requested
	 */
	template<typename Type>
	inline Type* H3Alloc(UINT count = 1);

	/** @brief base structure to let structures use H3 operators new, delete, new[] and delete[] */
	struct H3Allocator
	{
		_H3API_ static PVOID operator new(const size_t sz);
		_H3API_ static VOID  operator delete(PVOID block);
		_H3API_ static PVOID operator new[](const size_t sz);
		_H3API_ static VOID  operator delete[](PVOID block);
	};

	/**
	 * @brief An allocator to simulate H3's new & delete on objects
	 * @tparam T any type of data that will interact with H3 code
	 */
	template <typename T>
	struct H3ObjectAllocator
	{
		typedef T        value_type;
		typedef T*       pointer;
		typedef const T* const_pointer;
		typedef T&       reference;
		typedef const T& const_reference;
		typedef size_t   size_type;

		H3ObjectAllocator() noexcept;
		/**
		 * @brief allocates an object
		 * @param number how many objects you wish to allocate, by default 1
		 * @return T* a memory block of \p number objects
		 */
		T* allocate(size_t number = 1) const noexcept;
		/**
		 * @brief deallocates a memory block previously allocated using H3 allocator
		 * @param block the object to deallocate
		 */
		VOID deallocate(T* block) const noexcept;
		/**
		 * @brief same as deallocate(T*), is a requirement for named allocators
		 * https://en.cppreference.com/w/cpp/named_req/Allocator
		 */
		VOID deallocate(T* block, size_t number) const noexcept;
		/**
		 * @brief calls default constructor on an allocated object
		 * @param block the object to construct
		 */
		VOID construct(T* block) const noexcept;
		/**
		 * @brief calls constructor with argument of matching type
		 * @param block the object to construct
		 * @param value the base argument to pass to the constructor
		 */
		VOID construct(T* block, const T& value) const noexcept;
		/**
		 * @brief calls constructor with argument of a different type
		 * @tparam U a type different than T
		 * @param block the object to construct
		 * @param arg an argument to pass to the constructor
		 */
		template<typename U>
		VOID construct(T* block, const U& arg) const noexcept;
		/**
		 * @brief calls default destructor
		 * @param block the object to destruct
		 */
		VOID destroy(T* block) const noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		H3ObjectAllocator(const H3ObjectAllocator<U>&) noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		bool operator==(const H3ObjectAllocator<U>&) const noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		bool operator!=(const H3ObjectAllocator<U>&) const noexcept;

#ifdef _H3API_CPLUSPLUS11_
		/**
		 * @brief calls constructor with arbitrary number of arguments
		 * @tparam Args any arguments list necessary
		 * @param block the object to construct
		 * @param args the arguments to pass to the constructor
		 */
		template<typename... Args>
		VOID construct(T* block, Args&&... args);
#endif
	};

	/**
	 * @brief An allocator to simulate H3's new[] & delete[] on object arrays
	 * The amount of objects is stored at array[-1]
	 * @tparam T any type of data that will interact with H3 code
	 */
	template <typename T>
	struct H3ArrayAllocator
	{
		typedef T        value_type;
		typedef T*       pointer;
		typedef const T* const_pointer;
		typedef T&       reference;
		typedef const T& const_reference;
		typedef size_t   size_type;
	private:
		size_t* getArrayBase(T* block) const noexcept;
		size_t getArraySize(T* block) const noexcept;
	public:
		H3ArrayAllocator() noexcept;
		/**
		 * @brief allocates an object
		 * @param number how many objects you wish to allocate, by default 1
		 * @return T* a memory block of \p number objects
		 */
		T* allocate(size_t number = 1) const noexcept;
		/**
		 * @brief deallocates a memory block previously allocated using H3 allocator
		 * @param block the object to deallocate
		 */
		VOID deallocate(T* block) const noexcept;
		/**
		 * @brief calls default constructor on an allocated object
		 * @param block the object to construct
		 */
		VOID construct(T* block) const noexcept;
		/**
		 * @brief calls constructor with argument of matching type
		 * @param block the object to construct
		 * @param value the base argument to pass to the constructor
		 */
		VOID construct(T* block, const T& value) const noexcept;
		/**
		 * @brief calls constructor with argument of a different type
		 * @tparam U a type different than T
		 * @param block the object to construct
		 * @param arg an argument to pass to the constructor
		 */
		template<typename U>
		VOID construct(T* block, const U& arg) const noexcept;
		/**
		 * @brief calls default destructor on all objects
		 * @param block the object array to destruct
		 */
		VOID destroy(T* block) const noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		H3ArrayAllocator(const H3ArrayAllocator<U>&) noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		bool operator==(const H3ArrayAllocator<U>&) const noexcept;
		/** @brief Requirement for named constructors */
		template <typename U>
		bool operator!=(const H3ArrayAllocator<U>&) const noexcept;

#ifdef _H3API_CPLUSPLUS11_
		/** @brief calls constructor with arbitrary number of arguments */
		template<typename... Args>
		VOID construct(T* block, Args&&... args);
#endif
	};
#pragma pack(push, 4)
	/**
	 * @brief Stand-in for std::auto_ptr, mainly used for objects with virtual destructors
	 * @tparam T type for which a pointer is held
	 */
	template<typename T>
	struct H3AutoPtr
	{
		_H3API_SIZE_(0x8);
	protected:
		BOOL8 m_used;
		T*    m_data;
	public:
		H3AutoPtr(T* _Ptr = 0);
		~H3AutoPtr();
		/**
		 * @brief get a pointer to managed object
		 * @return T* current pointer, may be NULL
		 */
		T* Get();
		/** @brief access the managed object and its methods directly */
		T* operator->();
		/**
		 * @brief releases the managed object, replacing it with nullptr
		 * you become responsible of destroying and deallocating the returned object
		 * @return T* the managed object
		 */
		T* Release();
		/**
		 * @brief check the existence of an managed object
		 * @return BOOL8 whether there is a managed object
		 */
		BOOL8 Exists() const;
		/**
		 * @brief allows use of if (pointer)
		 * @return BOOL whether there is a managed object
		 */
		operator BOOL() const;
		/**
		 * @brief allows the use of if (!pointer)
		 * @return BOOL8 whether there is no managed object
		 */
		BOOL operator!() const;
		/**
		 * @brief dereference the managed object
		 * @return T& reference to managed object
		 */
		T& operator*() const;
	}; /* H3AutoPtr<> */
	_H3API_ASSERT_SIZE_(H3AutoPtr<h3unk>);
#pragma pack(pop)

	/**
	 * @brief simili std::unique_ptr without C++11 requirements
	 * @tparam T type of object to manage
	 * @tparam H3ObjectAllocator<T> the allocator type to use, defaulted to H3ObjectAllocator
	 */
	template<typename T, typename Allocator = H3ObjectAllocator<T>>
	struct H3UniquePtr
	{
	protected:
		T* data;
		void destroy(T* block = nullptr);

	public:
		/**
		 * @brief Construct a new H3UniquePtr object
		 * data is initialized as nullptr
		 */
		H3UniquePtr();
		/**
		 * @brief Construct a new H3UniquePtr object
		 * @param source the data with which to initiate the data pointer
		 */
		H3UniquePtr(T* source);
		/** @brief Destruct and deallocates any managed object */
		~H3UniquePtr();
		/**
		 * @brief sets a new managed object
		 * if an object is already managed, it is destructed and deallocated
		 * @param source new object to manage
		 */
		void Set(T* source);
		/**
		 * @brief get access to the managed object, if it exists
		 * @return T* the managed object
		 */
		T* Get();
		/** @brief access the managed object and its methods directly */
		T* operator->();
		/**
		 * @brief releases the managed object, replacing it with nullptr
		 * you become responsible of destroying and deallocating the returned object
		 * @return T* the managed object
		 */
		T* Release();
		/**
		 * @brief Swaps the pointer's managed object with another pointer
		 * @param other the other pointer with which to swap contents
		 */
		void Swap(H3UniquePtr<T>& other);
		/**
		 * @brief allows the use of if (!pointer)
		 * @return BOOL whether there is no managed object
		 */
		BOOL operator!() const;
		/**
		 * @brief allows use of if (pointer)
		 * @return BOOL whether there is a managed object
		 */
		operator BOOL() const;

#ifdef _H3API_CPLUSPLUS11_
		/**
		 * @brief Construct a new H3UniquePtr object, taking ownership over its managed object
		 * @param other the pointer from which ownership should be taken
		 */
		H3UniquePtr(H3UniquePtr<T, Allocator>&& other);
		/**
		 * @brief Take control of another pointer's managed object
		 * @param other the pointer from which ownership should be taken
		 * @return H3UniquePtr<T, Allocator>& itself
		 */
		H3UniquePtr<T, Allocator>& operator=(H3UniquePtr<T, Allocator>&& other);
		H3UniquePtr<T, Allocator>& operator=(const H3UniquePtr<T, Allocator>& other) = delete;
#else
	private:
		H3UniquePtr<T, Allocator>& operator=(H3UniquePtr<T, Allocator>& other);
#endif
	}; /* H3UniquePtr<> */

#pragma pack(pop) /* align-4 */

#ifdef _H3API_CPLUSPLUS11_

	namespace H3Internal
	{
		/* Based on https://isocpp.org/files/papers/N3656.txt */
		/* Author: Stephan T. Lavavej (aka STL)*/

		template<typename T, typename Allocator>
		struct H3UniqueIf
		{
			typedef H3UniquePtr<T, Allocator> SingleObject;
		};

		template<typename T, typename Allocator>
		struct H3UniqueIf<T[], Allocator>
		{
			typedef H3UniquePtr<T[], Allocator> UnknownBound;
		};

		template<typename T, typename Allocator, size_t N>
		struct H3UniqueIf<T[N], Allocator>
		{
			typedef void KnownBound;
		};
	} /* H3Internal */

	template<typename T, typename Allocator = H3ObjectAllocator<T>, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::SingleObject
		MakeUnique(Args&&... args)
	{
		H3UniquePtr<T, Allocator> ptr(Allocator().allocate());
		Allocator().construct(ptr.Get(), std::forward<Args>(args)...);
		return ptr;
	}

	template<typename T, typename Allocator = H3ArrayAllocator<T>, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::UnknownBound
		MakeUnique(size_t n)
	{
		H3UniquePtr<T> ptr(Allocator().allocate(n));
		Allocator().construct(ptr.Get());
		return ptr;
	}

	template<typename T, typename Allocator, class... Args>
	typename H3Internal::H3UniqueIf<T, Allocator>::KnownBound
		MakeUnique(Args&&...) = delete;

#endif /* _H3API_CPLUSPLUS11_ */

	template<typename T>
	inline H3ObjectAllocator<T>::H3ObjectAllocator() noexcept
	{
	}
	template<typename T>
	inline T* H3ObjectAllocator<T>::allocate(size_t number) const noexcept
	{
		return reinterpret_cast<T*>(H3Malloc(number * sizeof(T)));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::deallocate(T* block) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(block));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::deallocate(T* block, size_t number) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(block));
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::construct(T* block) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T();
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::construct(T* block, const T& value) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T(value);
	}
	template<typename T>
	template<typename U>
	inline VOID H3ObjectAllocator<T>::construct(T* block, const U& arg) const noexcept
	{
		::new(reinterpret_cast<PVOID>(block)) T(arg);
	}
	template<typename T>
	inline VOID H3ObjectAllocator<T>::destroy(T* block) const noexcept
	{
		block->~T();
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T>
	template<typename ...Args>
	inline VOID H3ObjectAllocator<T>::construct(T* block, Args && ...args)
	{
		::new(reinterpret_cast<PVOID>(block)) T(std::forward<Args>(args)...);
	}
#endif

	template<typename T>
	inline size_t* H3ArrayAllocator<T>::getArrayBase(T* block) const noexcept
	{
		return reinterpret_cast<size_t*>(block) - 1;
	}
	template<typename T>
	inline size_t H3ArrayAllocator<T>::getArraySize(T* block) const noexcept
	{
		return *getArrayBase(block);
	}
	template<typename T>
	inline H3ArrayAllocator<T>::H3ArrayAllocator() noexcept
	{
	}
	template<typename T>
	inline T* H3ArrayAllocator<T>::allocate(size_t number) const noexcept
	{
		size_t* block = reinterpret_cast<size_t*>(H3Malloc(number * sizeof(T) + sizeof(size_t)));
		*block = number;
		return reinterpret_cast<T*>(block + 1);
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::deallocate(T* block) const noexcept
	{
		H3Free(reinterpret_cast<PVOID>(getArrayBase(block)));
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::construct(T* block) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			new(reinterpret_cast<PVOID>(block)) T();
			++block;
		}
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::construct(T* block, const T& value) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(value);
			++block;
		}
	}
	template<typename T>
	template<typename U>
	inline VOID H3ArrayAllocator<T>::construct(T* block, const U& arg) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(arg);
			++block;
		}
	}
	template<typename T>
	inline VOID H3ArrayAllocator<T>::destroy(T* block) const noexcept
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			block->~T();
			++block;
		}
	}
	template<typename T>
	template<typename U>
	inline H3ObjectAllocator<T>::H3ObjectAllocator(const H3ObjectAllocator<U>&) noexcept
	{
	}
	template<typename T>
	template<typename U>
	inline bool H3ObjectAllocator<T>::operator==(const H3ObjectAllocator<U>&) const noexcept
	{
		return TRUE;
	}
	template<typename T>
	template<typename U>
	inline bool H3ObjectAllocator<T>::operator!=(const H3ObjectAllocator<U>&) const noexcept
	{
		return FALSE;
	}
	template<typename T>
	template<typename U>
	inline H3ArrayAllocator<T>::H3ArrayAllocator(const H3ArrayAllocator<U>&) noexcept
	{
	}

	template<typename T>
	template<typename U>
	inline bool H3ArrayAllocator<T>::operator==(const H3ArrayAllocator<U>&) const noexcept
	{
		return true;
	}

	template<typename T>
	template<typename U>
	inline bool H3ArrayAllocator<T>::operator!=(const H3ArrayAllocator<U>&) const noexcept
	{
		return false;
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T>
	template<typename ...Args>
	inline VOID H3ArrayAllocator<T>::construct(T* block, Args && ...args)
	{
		size_t number = getArraySize(block);
		for (size_t i = 0; i < number; ++i)
		{
			::new(reinterpret_cast<PVOID>(block)) T(std::forward<Args>(args)...);
			++block;
		}
	}
#endif
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::destroy(T* replacement)
	{
		if (replacement && replacement == data)
			return;
		if (data)
		{
			Allocator().destroy(data);
			Allocator().deallocate(data);
			data = nullptr;
		}
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr() :
		data()
	{
	}

	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr(T* source) :
		data(source)
	{
		source = nullptr;
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::~H3UniquePtr()
	{
		destroy();
	}
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::Set(T* source)
	{
		destroy(source); // check we aren't releasing ourselves
		data = source;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::Get()
	{
		return data;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::operator->()
	{
		return data;
	}
	template<typename T, typename Allocator>
	inline T* H3UniquePtr<T, Allocator>::Release()
	{
		T* r = data;
		data = nullptr;
		return r;
	}
	template<typename T, typename Allocator>
	inline void H3UniquePtr<T, Allocator>::Swap(H3UniquePtr<T>& other)
	{
		T* tmp = data;
		data = other.data;
		other.data = tmp;
	}
	template<typename T, typename Allocator>
	inline BOOL H3UniquePtr<T, Allocator>::operator!() const
	{
		return data == nullptr;
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::operator BOOL() const
	{
		return data != nullptr;
	}
#ifdef _H3API_CPLUSPLUS11_
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>::H3UniquePtr(H3UniquePtr<T, Allocator>&& other) :
		data(other.Release())
	{
	}
	template<typename T, typename Allocator>
	inline H3UniquePtr<T, Allocator>& H3UniquePtr<T, Allocator>::operator=(H3UniquePtr<T, Allocator>&& other)
	{
		if (&other == this)
			return *this;

		destroy();
		data = other.Release();

		return *this;
	}
#endif

	template<typename T>
	inline H3AutoPtr<T>::H3AutoPtr(T* _Ptr) :
		m_used(_Ptr != 0),
		m_data(_Ptr)
	{
	}

	template<typename T>
	inline H3AutoPtr<T>::~H3AutoPtr()
	{
		if (m_used)
		{
			delete m_data;
			m_used = FALSE;
		}
	}

	template<typename T>
	inline T* H3AutoPtr<T>::Get()
	{
		return m_data;
	}

	template<typename T>
	inline T* H3AutoPtr<T>::operator->()
	{
		return m_data;
	}

	template<typename T>
	inline T* H3AutoPtr<T>::Release()
	{
		T* ptr = m_data;
		m_used = FALSE;
		m_data = nullptr;
		return ptr;
	}
	template<typename T>
	inline BOOL8 H3AutoPtr<T>::Exists() const
	{
		return m_used;
	}
	template<typename T>
	inline H3AutoPtr<T>::operator BOOL() const
	{
		return m_used != FALSE;
	}
	template<typename T>
	inline BOOL H3AutoPtr<T>::operator!() const
	{
		return m_used == FALSE;
	}
	template<typename T>
	inline T& H3AutoPtr<T>::operator*() const
	{
		return *m_data;
	}
	template<typename Type>
	inline Type* H3Alloc(UINT count)
	{
		return reinterpret_cast<Type*>(H3Malloc(sizeof(Type) * count));
	}
}
