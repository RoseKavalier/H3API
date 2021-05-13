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
	_H3API_DECLARE_(GzStream);

#pragma pack(push, 4)

	/* gz_stream https://github.com/madler/zlib/blob/14763ac7c6c03bca62c39e35c03cf5bfc7728802/gzio.c#L40 */
	/* Copyright (C) 1995-1998 Jean-loup Gailly. */
	/* Heroes3 version is 1.1.3 */
	struct H3GZStream : H3Allocator
	{
		_H3API_SIZE_(0x64);
		/* aka z_stream */
		H3ZStream zstrm;
		INT       zError;           /* error code for last stream operation */
		INT       zEof;             /* set if end of input file */
		FILE*     file;             /* .gz file */
		BYTE*     inbuf;            /* input buffer */
		BYTE*     outbuf;           /* output buffer */
		UINT32    crc;              /* crc32 of uncompressed data */
		PCHAR     msg;              /* error message */
		PCHAR     path;             /* path name for debugging only */
		INT       transparent;      /* 1 if input file is not a .gz file */
		CHAR      mode;             /* 'w' or 'r' */
		INT       startPos;         /* start of compressed data in file (header skipped) */
	};
	_H3API_ASSERT_SIZE_(H3GZStream);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
