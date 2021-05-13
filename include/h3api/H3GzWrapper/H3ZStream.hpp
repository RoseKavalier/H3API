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
	_H3API_DECLARE_(ZStream);

#pragma pack(push, 4)

	/* z_stream https://github.com/madler/zlib/blob/14763ac7c6c03bca62c39e35c03cf5bfc7728802/zlib.h#L68 */
	/* Copyright (C) 1995-1998 Jean-loup Gailly and Mark Adler */
	/* Heroes3 version is 1.1.3 */
	struct H3ZStream
	{
		_H3API_SIZE_(0x38);
		BYTE* nextIn;        /* next input byte */
		UINT  availIn;       /* number of bytes available at next_in */
		UINT  totalIn;       /* total nb of input bytes read so far */
		BYTE* nextOut;       /* next output byte should be put there */
		UINT  availOut;      /* remaining free space at next_out */
		UINT  totalOut;      /* total nb of bytes output so far */
		PCHAR msg;           /* last error message, NULL if no error */
		INT*  internalState; /* not visible by applications */
		VOID* zalloc;        /* used to allocate the internal state */
		VOID* zfree;         /* used to free the internal state */
		VOID* opaque;        /* private data object passed to zalloc and zfree */
		INT   dataType;      /* best guess about the data type: ascii or binary */
		UINT  adler;         /* adler32 value of the uncompressed data */
		UINT  reserved;      /* reserved for future use */
	};
	_H3API_ASSERT_SIZE_(H3ZStream);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
