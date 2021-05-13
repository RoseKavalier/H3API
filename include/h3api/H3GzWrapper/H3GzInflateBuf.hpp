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
#include "h3api/H3GzWrapper/H3ZStream.hpp"

namespace h3
{
	_H3API_DECLARE_(GzInflateBuf);
	_H3API_DECLARE_(GzInflateBufFile);
	struct H3String;

#pragma pack(push, 4)
	/**
	 * @brief Wrapper around zlib inherited from basic_streambuf
	 * Original name TGzInflateBuf
	 */
	struct H3GzInflateBuf
	{
		_H3API_SIZE_(0x84);
		_H3API_VTABLE_(0x63E710);
		_H3API_CTOR_DTOR_(0x4D6260, 0x4D6A80);
	protected:
		struct
		{
			h3func dtor;
			h3func overflow;
			h3func pbackfail;
			h3func showmanyc;
			h3func underflow;
			h3func uflow;
			h3func xsgetn; /* v18 */
			h3func xsputn; /* v1C */
			h3func seekoff;
			h3func seekpos;
			h3func setbuf;
			h3func sync;
			h3func imbue;
		}*vtable;
		CHAR*     gbeg;
		CHAR*     pbeg;
		CHAR**    igbeg;
		CHAR**    ipbeg;
		CHAR*     gnext;
		CHAR*     pnext;
		CHAR**    ignext;
		CHAR**    ipnext;
		INT       gcnt;
		INT       pcnt;
		INT*      igcnt;
		INT*      ipcnt;
		PVOID     locale; // basic_streambuf end
		PVOID     strstreambuf; // vt 645680
		H3ZStream zstream;
		PVOID     buffer;
		PVOID     bufferEnd;
		h3unk32   _f_7C;
		h3unk8    _f_80; // related to zstrm
		h3unk8    _f_81; // related to strstreambuf
		h3unk8    _f_82; // related to zstrm

		_H3API_ UINT32 read(PVOID dst, UINT32 size);
		_H3API_ UINT32 write(PVOID src, UINT32 size);
	public:
	};
	_H3API_ASSERT_SIZE_(H3GzInflateBuf);

	/** @brief wrapper around H3GzInflateBuf*/
	struct H3GzInflateBufFile
	{
		_H3API_SIZE_(8);
		_H3API_VTABLE_(0x63DACC);
	protected:
		struct
		{
			h3func dtor;
			h3func read;
			h3func write;
		}*vtable;
		H3GzInflateBuf* inflatebuf;

		_H3API_ UINT32 read(PVOID dst, UINT32 size);
		_H3API_ UINT32 write(PVOID src, UINT32 size);
	public:
		_H3API_ H3String* Read(H3String& string);
	};
	_H3API_ASSERT_SIZE_(H3GzInflateBufFile);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
