//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(GzFile);
	struct H3GzStream;
	struct H3String;

#pragma pack(push, 4)

	/**
	 * @brief Wrapper around gz_stream used to read/write h3m and save files
	 * For reading map files from lod archives: TGzInflateBuf
	 * original name as glanced from exception 'TGzFile::TOpenFailure'
	 */
	struct H3GzFile : H3Allocator
	{
		_H3API_SIZE_(8);
	protected:
		struct
		{
			h3func dtor;
			h3func read;
			h3func write;
		}*vtable;
		H3GzStream* gzStream;
		/* returns written size */
		_H3API_ UINT32 write(VOID* src, UINT32 size);
		/* returns read size */
		_H3API_ UINT32 read(VOID* dst, UINT32 size);

	public:
		/**
		 * @brief Construct a TGzFile to read or write
		 * @param file_name file name you wish to open
		 * @param mode 'rb', 'wb' etc.
		 */
		_H3API_ H3GzFile(LPCSTR file_name, LPCSTR mode);
		/** @brief has a virtual destructor but we're not using it */
		_H3API_ ~H3GzFile();
		/**
		 * @brief Read a string with 16-bit length
		 * @param string Destination string
		 * @return Number of bytes read in string
		 */
		_H3API_ BOOL ReadString16(H3String& string);
		/**
		 * @brief Read a string with 32-bit length
		 * @param string Destination string
		 * @return Number of bytes read in string
		 */
		_H3API_ BOOL Read(H3String& string);
		/**
		 * @brief Writes a string with 32-bit length
		 * @param string Text to write
		 * @return Number of bytes written
		 */
		_H3API_ BOOL Write(const H3String& string);
		/**
		 * @brief Writes a string with 16-bit length
		 * @param string Text to write
		 * @return Number of bytes written
		 */
		_H3API_ BOOL WriteString16(const H3String& string);
		/**
		 * @brief Write primitive data array to file
		 * @tparam Type primitive data type (e.g. char, int, float)
		 * @param src data array to be written
		 * @return Number of bytes written
		 */
		template<typename Type, UINT32 Size>
		BOOL Write(const Type(&src)[Size]);
		/**
		 * @brief Read primitive data array from file
		 * @tparam Type primitive data type (e.g. char, int, float)
		 * @param dst data array to be read into
		 * @return Number of bytes read
		 */
		template<typename Type, UINT32 Size>
		BOOL Read(Type(&dst)[Size]);
		/**
		 * @brief Write primitive data to file
		 * @tparam Type primitive data type (e.g. char, int, float)
		 * @param src data to be written
		 * @return Number of bytes written
		 */
		template<typename Type>
		BOOL Write(const Type& src);
		/**
		 * @brief Read primitive data from file
		 * @tparam Type primitive data type (e.g. char, int, float)
		 * @param dst data to be read into
		 * @return Number of bytes read
		 */
		template<typename Type>
		BOOL Read(Type& dst);
	};
	_H3API_ASSERT_SIZE_(H3GzFile);

#pragma pack(pop) /* align-4 */

	template<typename Type, UINT32 Size>
	BOOL H3GzFile::Write(const Type(&src)[Size])
	{
		UINT32 total_size = sizeof(Type) * Size;
		return write(PVOID(src), total_size) == total_size;
	}
	template<typename Type>
	BOOL H3GzFile::Write(const Type& src)
	{
		return write(PVOID(&src), sizeof(Type)) == sizeof(Type);
	}
	template<typename Type, UINT32 Size>
	BOOL H3GzFile::Read(Type(&dst)[Size])
	{
		UINT32 total_size = sizeof(Type) * Size;
		return read(PVOID(dst), total_size) == total_size;
	}
	template<typename Type>
	BOOL H3GzFile::Read(Type& dst)
	{
		return read(PVOID(&dst), sizeof(Type)) == sizeof(Type);
	}

} /* namespace h3 */
