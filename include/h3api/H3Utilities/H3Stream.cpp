//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-06                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Utilities/H3Stream.hpp"

namespace h3
{
	_H3API_ H3Stream::H3Stream(LPCSTR filename, StreamMode read_write_mode, BOOL read_to_buffer) :
		m_file(nullptr),
		m_size(0),
		m_mode(read_write_mode),
		m_writeHex(FALSE),
		m_writeNewLines(FALSE),
		m_status(StreamStatus::SS_NOT_LOADED),
		m_buffer(nullptr),
		m_bufferSize(0),
		m_bufferPosition(0)
	{
		LPCSTR mode = getModeFormat();
		if (mode)
		{
			if ((m_file = fopen(filename, mode)))
			{
				m_status = StreamStatus::SS_OK;
				m_size = GetFileSize(m_file);
			}
			if (read_to_buffer && m_size && canRead())
				ReadFile(m_size);
		}
	}
	_H3API_ H3Stream::H3Stream(LPCSTR filename, LPCSTR read_write_mode, BOOL read_to_buffer) :
		m_file(nullptr),
		m_size(0),
		m_mode(StreamMode::SM_INVALID),
		m_writeHex(FALSE),
		m_writeNewLines(FALSE),
		m_status(StreamStatus::SS_NOT_LOADED),
		m_buffer(nullptr),
		m_bufferSize(0),
		m_bufferPosition(0)
	{
		m_mode = getMode(read_write_mode);

		if (m_mode != StreamMode::SM_INVALID)
		{
			if ((m_file = fopen(filename, read_write_mode)))
			{
				m_status = StreamStatus::SS_OK;
				m_size = GetFileSize(m_file);
			}
			if (read_to_buffer && m_size && canRead())
				ReadFile(m_size);
		}
	}
	_H3API_ H3Stream::~H3Stream()
	{
		if (m_file)
		{
			fclose(m_file);
			m_file = nullptr;
		}
		if (m_buffer)
		{
			ByteAllocator().deallocate(m_buffer);
			m_buffer = nullptr;
		}
	}
	_H3API_ H3Stream& H3Stream::hex()
	{
		m_writeHex = TRUE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::decimal()
	{
		m_writeHex = FALSE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::new_lines()
	{
		m_writeNewLines = TRUE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::no_new_lines()
	{
		m_writeNewLines = FALSE;
		return *this;
	}
	_H3API_ H3Stream& H3Stream::endl()
	{
		if (IsReady() && canWrite())
			CDECL_3(int, 0x61A031, m_file, "%s", "\r\n");
		return *this;
	}
	_H3API_ BOOL H3Stream::IsReady() const
	{
		return m_status == StreamStatus::SS_OK;
	}
	_H3API_ H3Stream::StreamStatus H3Stream::GetStatus() const
	{
		return m_status;
	}
	_H3API_ H3Stream::StreamMode H3Stream::GetMode() const
	{
		return m_mode;
	}
	_H3API_ BOOL H3Stream::Copy(LPCSTR destination)
	{
		if (!(int(m_mode) & (MV_READ | MV_UPDATE)))
			return FALSE;

		if ((!m_bufferSize || !m_buffer) && !ReadFile(m_size))
			return FALSE;

		fread(m_buffer, 1, m_size, m_file);

		H3Stream dest(destination, StreamMode::SM_WRITE_BINARY);
		if (dest.GetStatus() == StreamStatus::SS_OK)
			fwrite(m_buffer, 1, m_size, dest.m_file);

		return TRUE;
	}
	_H3API_ BOOL H3Stream::Copy(const H3String& destination)
	{
		if (destination.String() && destination.Length())
			return Copy(destination.String());
		return FALSE;
	}
#ifndef _H3API_CPLUSPLUS11_
	_H3API_	H3Stream& H3Stream::Write(LPCSTR format, ...)
	{
		if (IsReady() && canWrite())
		{
			va_list args;
			va_start(args, format);
#pragma warning(push)
#pragma warning(disable : 4996)
			//int len = _snprintf(nullptr, 0, format, args);
			INT32 len = _vsnprintf(nullptr, 0, format, args);
#pragma warning(pop)
			H3String buffer;
			if (len > 0 && buffer.Reserve(len + 1))
			{
				len = libc::vsprintf(buffer.Begin(), format, args);
				buffer.Truncate(len);
				operator<<(buffer);
			}
			va_end(args);
			writeNewLine();
	}
		return *this;
	}
#endif

	_H3API_	H3Stream& H3Stream::operator<<(const int number)
	{
		if (IsReady() && canWrite())
		{
			if (m_writeHex)
				CDECL_3(int, 0x61A031, m_file, "0x%X", number);
			else
				CDECL_3(int, 0x61A031, m_file, "%d", number);
			writeNewLine();
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const unsigned int number)
	{
		if (IsReady())
		{
			if (m_writeHex)
				CDECL_3(int, 0x61A031, m_file, "0x%X", number);
			else
				CDECL_3(int, 0x61A031, m_file, "%u", number);
			writeNewLine();
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const FLOAT number)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%f", number);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const DOUBLE number)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%f", number);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const CHAR character)
	{
		if (IsReady() && canWrite())
		{
			fputc(character, m_file);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(LPCSTR text)
	{
		if (IsReady())
		{
			CDECL_3(int, 0x61A031, m_file, "%s", text);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator<<(const H3String& str)
	{
		if (IsReady() && str.String() && str.Length())
		{
			fwrite(str.String(), 1, str.Length(), m_file);
			writeNewLine();
		}

		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator>>(H3String& line)
	{
		line.Truncate(0);

		if (IsReady() && m_buffer && m_bufferPosition < m_bufferSize)
		{
			if (m_bufferPosition == 0 && m_bufferSize >= 3)
			{
				if (m_buffer[0] == 0xEF && m_buffer[1] == 0xBB && m_buffer[2] == 0xBF)
				{
					m_bufferPosition += 3;
				}
			}

			int len = 0;
			BYTE* start = m_buffer + m_bufferPosition;
			BYTE* current = start;
			while (m_bufferPosition < m_bufferSize && *current)
			{
				if (*current == '\n')
				{
					// * if at least 1 character was parsed, check if previous is carriage return
					if (len && *(current - 1) == '\r')
						len--;
					// * skip this character for next time
					++m_bufferPosition;
					break;
				}
				++len;
				++current;
				++m_bufferPosition;
			}
			// * blank lines ("\n" or "\r\n") are not assigned
			if (len)
				line.Assign(LPCSTR(start), len);
		}
		return *this;
	}
	_H3API_	H3Stream& H3Stream::operator>>(H3Vector<H3String>& lines)
	{
		if (!IsReady() || !m_buffer || m_bufferPosition >= m_bufferSize)
			return *this;
		lines.Deref();

		while (m_bufferPosition < m_bufferSize)
		{
			H3String line;
			operator>>(line);
			lines += line;
		}

		return *this;
	}
	_H3API_	BOOL H3Stream::ReadFile(DWORD size_to_read)
	{
		if (!IsReady() || !canRead())
			return FALSE;

		const DWORD sz = std::min(m_size, size_to_read);

		if (m_bufferSize < sz)
		{
			ByteAllocator().deallocate(m_buffer);
			m_bufferSize = sz;
			m_buffer = static_cast<PBYTE>(H3Calloc(m_bufferSize));
		}

		m_bufferPosition = 0;

		return fread(m_buffer, 1, m_bufferSize, m_file) == m_bufferSize;
	}
	_H3API_	LPCSTR H3Stream::getModeFormat()
	{
		switch (m_mode)
		{
		case StreamMode::SM_READ:
			return "r";
		case StreamMode::SM_READ_BINARY:
			return "rb";
		case StreamMode::SM_WRITE:
			return "w";
		case StreamMode::SM_WRITE_BINARY:
			return "wb";
		case StreamMode::SM_APPEND:
			return "a";
		case StreamMode::SM_APPEND_BINARY:
			return "ab";
		case StreamMode::SM_READ_UPDATE:
			return "r+";
		case StreamMode::SM_READ_UPDATE_BINARY:
			return "r+b";
		case StreamMode::SM_WRITE_UPDATE:
			return "w+";
		case StreamMode::SM_WRITE_UPDATE_BINARY:
			return "w+b";
		case StreamMode::SM_APPEND_UPDATE:
			return "a+";
		case StreamMode::SM_APPEND_UPDATE_BINARY:
			return "a+b";
		default:
			return nullptr;
		}
	}
	_H3API_	VOID H3Stream::writeNewLine()
	{
		if (m_writeNewLines)
			endl();
	}
	_H3API_	BOOL H3Stream::canWrite()
	{
		return int(m_mode) & (MV_WRITE | MV_APPEND | MV_UPDATE);
	}
	_H3API_	BOOL H3Stream::canRead()
	{
		return int(m_mode) & (MV_READ | MV_UPDATE);
	}

	_H3API_ H3Stream::StreamMode H3Stream::getMode(LPCSTR read_write_mode)
	{
		StreamMode mode = StreamMode::SM_INVALID;

		if (!read_write_mode)
			return mode;

		switch (read_write_mode[0])
		{
		case 'r':
			mode = StreamMode(MV_READ);
			break;
		case 'w':
			mode = StreamMode(MV_WRITE);
			break;
		case 'a':
			mode = StreamMode(MV_APPEND);
			break;
		default:
			break;
		}

		if (!read_write_mode[1])
			return mode;

		switch (read_write_mode[1])
		{
		case 'r':
			mode = StreamMode(int(mode) | int(StreamMode(MV_READ)));
			break;
		case 'w':
			mode = StreamMode(int(mode) | int(StreamMode(MV_WRITE)));
			break;
		case 'a':
			mode = StreamMode(int(mode) | int(StreamMode(MV_APPEND)));
			break;
		case '+':
			mode = StreamMode(int(mode) | int(StreamMode(MV_UPDATE)));
			break;
		case 'b':
			mode = StreamMode(int(mode) | int(StreamMode(MV_BINARY)));
			break;
		default:
			break;
		}

		if (!read_write_mode[2])
			return mode;

		switch (read_write_mode[2])
		{
		case 'r':
			mode = StreamMode(int(mode) | int(StreamMode(MV_READ)));
			break;
		case 'w':
			mode = StreamMode(int(mode) | int(StreamMode(MV_WRITE)));
			break;
		case 'a':
			mode = StreamMode(int(mode) | int(StreamMode(MV_APPEND)));
			break;
		case '+':
			mode = StreamMode(int(mode) | int(StreamMode(MV_UPDATE)));
			break;
		case 'b':
			mode = StreamMode(int(mode) | int(StreamMode(MV_BINARY)));
			break;
		default:
			break;
		}
		return mode;
	}


	_H3API_ INT32 H3Stream::fclose(FILE* f)
	{
		return CDECL_1(int, 0x618F5E, f);
	}
	_H3API_ INT32 H3Stream::fgetpos(FILE* f, fpos_t& pos)
	{
		return CDECL_2(INT, 0x618C56, f, &pos);
	}
	_H3API_ FILE* H3Stream::fopen(LPCSTR filename, LPCSTR mode)
	{
		return CDECL_2(FILE*, 0x619691, filename, mode);
	}
	_H3API_ INT32 H3Stream::fputc(CHAR c, FILE* f)
	{
		return CDECL_2(INT, 0x618B53, c, f);
	}
	_H3API_ BOOL H3Stream::fread(PVOID buffer, size_t size, size_t count, FILE* f)
	{
		return CDECL_4(BOOL, 0x6196A4, buffer, size, count, f);
	}
	_H3API_ INT32 H3Stream::fseek(FILE* f, INT32 offset, INT32 origin)
	{
		return CDECL_3(INT, 0x618C78, f, offset, origin);
	}
	_H3API_ INT32 H3Stream::fsetpos(FILE* f, const fpos_t& pos)
	{
		return CDECL_2(INT, 0x618D31, f, &pos);
	}
	_H3API_ DWORD H3Stream::ftell(FILE* f)
	{
		return CDECL_1(DWORD, 0x6194DD, f);
	}
	_H3API_ UINT32 H3Stream::fwrite(const VOID* buffer, UINT32 size, UINT32 count, FILE* f)
	{
		return CDECL_4(size_t, 0x618A1A, buffer, size, count, f);
	}
	_H3API_ DWORD H3Stream::GetFileSize(FILE* f)
	{
		fseek(f, 0, SEEK_END);
		DWORD size = ftell(f);
		fseek(f, 0, SEEK_SET);
		return size;
	}
	_H3API_ void H3File::getSize()
	{
		m_fileSize = GetFileSize(m_handle);
	}
	_H3API_ void H3File::clear()
	{
		if (m_buffer)
		{
			ByteAllocator().deallocate(m_buffer);
			m_buffer = nullptr;
		}
	}
	_H3API_ void H3File::close()
	{
		if (m_handle)
		{
			CloseHandle(m_handle);
			m_handle = NULL;
		}
		if (m_save)
		{
			CloseHandle(m_save);
			m_save = NULL;
		}
	}
	_H3API_ BOOL H3File::read(PVOID buffer, DWORD sizeToRead)
	{
		if (m_pointer + sizeToRead > m_fileSize)
			return FALSE;

		if (!ReadFile(m_handle, buffer, sizeToRead))
			return FALSE;
		m_pointer += sizeToRead;
		return TRUE;
	}
	_H3API_ BOOL H3File::write(const PVOID buffer, DWORD sizeToWrite)
	{
		return WriteFile(m_save, buffer, sizeToWrite);
	}
	_H3API_ H3File::H3File() :
		m_handle(),
		m_fileSize(),
		m_buffer(),
		m_pointer(),
		m_save()
	{
	}
	_H3API_ H3File::~H3File()
	{
		close();
		clear();
	}
	_H3API_ BOOL H3File::Open(LPCSTR const file)
	{
		if (!exists(file))
			return FALSE;
		getSize();
		return TRUE;
	}

	_H3API_ BOOL H3File::Open(const H3String& file)
	{
		return Open(file.String());
	}

	_H3API_ BOOL H3File::Read(const PVOID buffer, DWORD sizeToRead)
	{
		return read(buffer, sizeToRead);
	}
	_H3API_ BOOL H3File::ReadToBuffer()
	{
		if (m_buffer)
			return TRUE;

		m_buffer = ByteAllocator().allocate(m_fileSize);
		return read(m_buffer, m_fileSize);
	}
	_H3API_ BOOL H3File::Save(LPCSTR const file)
	{
		m_save = CreateFileA(file, FALSE);
		return m_save != INVALID_HANDLE_VALUE;
	}
	_H3API_ UINT H3File::Size() const
	{
		return m_fileSize;
	}
	_H3API_ const PBYTE H3File::Buffer() const
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::ReleaseBuffer()
	{
		PBYTE buffer = m_buffer;
		m_buffer = nullptr;
		return buffer;
	}
	_H3API_ BOOL H3File::SetPointer(UINT pos)
	{
		if (pos >= m_fileSize)
			return FALSE;
		m_pointer = pos;
		SetFilePointer(m_handle, m_pointer, FILE_BEGIN);
		return TRUE;
	}
	_H3API_ UINT H3File::Pointer() const
	{
		return m_pointer;
	}
	_H3API_ BOOL H3File::Skip(UINT numBytes)
	{
		if (m_pointer + numBytes >= m_fileSize)
			return FALSE;
		m_pointer += numBytes;
		SetFilePointer(m_handle, m_pointer, FILE_CURRENT);
		return TRUE;
	}
	_H3API_ PBYTE H3File::begin()
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::begin() const
	{
		return m_buffer;
	}
	_H3API_ PBYTE H3File::end()
	{
		return m_buffer + m_fileSize;
	}
	_H3API_ PBYTE H3File::end() const
	{
		return m_buffer + m_fileSize;
	}
	_H3API_ VOID H3File::Close()
	{
		close();
	}
	_H3API_ BOOL H3File::Read(PVOID data, size_t data_len)
	{
		return read(data, data_len);
	}
	_H3API_ BOOL H3File::Write(PVOID data, size_t data_len)
	{
		return write(data, data_len);
	}
	_H3API_ BOOL H3File::Write(const H3String & string)
	{
		return write(PVOID(string.String()), string.Length());
	}
	_H3API_ BOOL H3File::Write(LPCSTR string)
	{
		return write(PVOID(string), libc::strlen(string));
	}

	_H3API_ H3String H3File::GetLine()
	{
		H3String line;
		if (m_pointer < m_fileSize)
		{
			if (m_pointer == 0 && m_fileSize >= 3)
			{
				if (m_buffer[0] == 0xEF && m_buffer[1] == 0xBB && m_buffer[2] == 0xBF)
				{
					m_pointer += 3;
				}
			}

			UINT len = 0;
			PCHAR start = reinterpret_cast<PCHAR>(m_buffer + m_pointer);
			PCHAR current = start;
			while (m_pointer < m_fileSize && *current)
			{
				if (*current == '\n')
				{
					// * if at least 1 character was parsed, check if previous is carriage return
					if (len && *(current - 1) == '\r')
						len--;
					// * skip this character for next time
					++m_pointer;
					break;
				}
				++len;
				++current;
				++m_pointer;
			}
			// * blank lines ("\n" or "\r\n") are not assigned
			if (len)
				line.Assign(start, len);
		}
		return line;
	}
	_H3API_ H3Vector<H3String> H3File::GetLines(BOOL includeEmptyLines)
	{
		H3Vector<H3String> result;

		m_pointer = 0;
		while (m_pointer < m_fileSize)
		{
			H3String line = GetLine();
			if (includeEmptyLines || !line.Empty())
				result += line;
		}

		return result;
	}
	_H3API_ BOOL H3File::exists(LPCSTR filepath)
	{
		m_handle = CreateFileA(filepath, TRUE);
		if (m_handle == INVALID_HANDLE_VALUE)
			return FALSE;
		return TRUE;
	}
	_H3API_ VOID H3SpreadSheet::Clear()
	{
		m_lines.RemoveAll();
	}
	_H3API_ VOID H3SpreadSheet::NewLine()
	{
		m_currentLine.AppendA("\r\n");
		m_lines += m_currentLine;
		m_currentLine.Erase();
	}
	_H3API_ VOID H3SpreadSheet::NewColumn()
	{
		m_currentLine.Append('\t');
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::Hex()
	{
		m_hexMode = TRUE;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::Dec()
	{
		m_hexMode = FALSE;
		return *this;
	}
	_H3API_ BOOL H3SpreadSheet::Save(LPCSTR const file)
	{
		H3File f;
		if (!f.Save(file))
			return FALSE;
		for (UINT i = 0; i < m_lines.Size(); ++i)
		{
			if (!f.Write(m_lines[i]))
				return FALSE;
		}
		return TRUE;
	}
	_H3API_ BOOL H3SpreadSheet::Save(const H3String& file)
	{
		return Save(file.String());
	}

	_H3API_ BOOL H3SpreadSheet::InsertLine(const H3String& line, UINT row)
	{
		if (row == static_cast<UINT>(-1))
		{
			H3String* l = m_lines.Append(line);
			if (!l)
				return FALSE;
			l->AppendA("\r\n");
			return TRUE;
		}
		else
		{
			H3String l = line;
			l.AppendA("\r\n");
			return m_lines.Insert(m_lines.begin() + row, l);
		}
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(const H3SpreadSheet&)
	{
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(LPCSTR text)
	{
		addTab();
		m_currentLine += text;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(INT32 value)
	{
		addTab();
		m_currentLine.Append(value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(UINT32 value)
	{
		addTab();
		if (!m_hexMode)
		{
			m_currentLine.PrintfAppend("%u", value);
		}
		else
		{
			m_currentLine.PrintfAppend("%X", value);
		}
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(FLOAT value)
	{
		addTab();
		m_currentLine.PrintfAppend("%f", value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(DOUBLE value)
	{
		addTab();
		m_currentLine.PrintfAppend("%f", value);
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(CHAR ch)
	{
		addTab();
		m_currentLine += ch;
		return *this;
	}
	_H3API_ H3SpreadSheet& H3SpreadSheet::operator<<(const H3String& line)
	{
		addTab();
		m_currentLine += line;
		return *this;
	}
	_H3API_ BOOL H3File::CloseHandle(HANDLE handle)
	{
		return STDCALL_1(BOOL, PtrAt(0x63A0C8), handle);
	}
	_H3API_ HANDLE H3File::CreateFileA(LPCSTR file, BOOL open_existing)
	{
		// * HDmod hijacks H3's CreateFile at import table and other similar functions
		// * this function serves as a pleasant shortcut
		return ::CreateFileA(file, open_existing ? GENERIC_READ : GENERIC_WRITE, 0, LPSECURITY_ATTRIBUTES(NULL),
			open_existing ? OPEN_EXISTING : CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, HANDLE(NULL));
	}
	_H3API_ DWORD H3File::GetFileSize(HANDLE handle)
	{
		// ::GetFileSize() isn't used in h3, might change to use it
		DWORD file_size = 0;
		if (handle)
		{
			DWORD pos = ::SetFilePointer(handle, 0, NULL, FILE_CURRENT);
			file_size = ::SetFilePointer(handle, 0, NULL, FILE_END);
			::SetFilePointer(handle, pos, NULL, FILE_BEGIN);
		}
		return file_size;
	}
	_H3API_ BOOL H3File::ReadFile(HANDLE handle, PVOID data, DWORD bytes_to_read)
	{
		DWORD szRead;

		if (!::ReadFile(handle, data, bytes_to_read, &szRead, NULL))
			return FALSE;
		return szRead == bytes_to_read;
	}
	_H3API_ DWORD H3File::SetFilePointer(HANDLE handle, LONG position, DWORD source)
	{
		return ::SetFilePointer(handle, position, NULL, source);
	}
	_H3API_ BOOL H3File::WriteFile(HANDLE handle, PVOID buffer, DWORD bytes_to_write)
	{
		DWORD szWritten;
		if (!::WriteFile(handle, buffer, bytes_to_write, &szWritten, NULL))
			return FALSE;
		return szWritten == bytes_to_write;
	}
	_H3API_ VOID H3SpreadSheet::addTab()
	{
		if (!m_currentLine.Empty())
			m_currentLine += '\t';
	}
}
