//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-06                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND)

#include "h3api/H3Utilities/H3Exception.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Dialogs/H3Messagebox.hpp"
#include "h3api/H3Utilities/H3Path.hpp"
#include "h3api/H3Utilities/H3Stream.hpp"

namespace h3
{
	namespace H3Internal
	{
		CHAR const CONTEXT_FORMAT[] = "\n\
Context:\n\
EAX   = 0x%08X\n\
ECX   = 0x%08X\n\
EDX   = 0x%08X\n\
EBX   = 0x%08X\n\
ESP   = 0x%08X\n\
EBP   = 0x%08X\n\
ESI   = 0x%08X\n\
EDI   = 0x%08X\n\
Flags = 0x%08X";

		_H3API_ VOID     _h3TransFunction(UINT code, EXCEPTION_POINTERS* ep);
		_H3API_ LPCSTR   _opDescription(const ULONG opcode);
		_H3API_ LPCSTR   _seDescription(const UINT& code);
		_H3API_ H3String _exInformation(_EXCEPTION_POINTERS* ep, UINT code = 0);

		_H3API_ VOID _h3TransFunction(UINT code, EXCEPTION_POINTERS* ep)
		{
			throw H3Exception(_exInformation(ep, code));
		}
		_H3API_ LPCSTR _opDescription(const ULONG opcode)
		{
			switch (opcode)
			{
			case 0:
				return "read";
			case 1:
				return "write";
			case 8:
				return "user-mode data execution prevention (DEP) violation";
			default:
				return "unknown";
			}
		}
		_H3API_ LPCSTR _seDescription(const UINT& code)
		{
			switch (code)
			{
			case EXCEPTION_ACCESS_VIOLATION:
				return "EXCEPTION_ACCESS_VIOLATION [0xC0000005]";
			case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
				return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED [0xC000008C]";
			case EXCEPTION_BREAKPOINT:
				return "EXCEPTION_BREAKPOINT [0x80000003]";
			case EXCEPTION_DATATYPE_MISALIGNMENT:
				return "EXCEPTION_DATATYPE_MISALIGNMENT [0x80000002]";
			case EXCEPTION_FLT_DENORMAL_OPERAND:
				return "EXCEPTION_FLT_DENORMAL_OPERAND [0xC000008D]";
			case EXCEPTION_FLT_DIVIDE_BY_ZERO:
				return "EXCEPTION_FLT_DIVIDE_BY_ZERO [0xC000008E]";
			case EXCEPTION_FLT_INEXACT_RESULT:
				return "EXCEPTION_FLT_INEXACT_RESULT [0xC000008F]";
			case EXCEPTION_FLT_INVALID_OPERATION:
				return "EXCEPTION_FLT_INVALID_OPERATION [0xC0000090]";
			case EXCEPTION_FLT_OVERFLOW:
				return "EXCEPTION_FLT_OVERFLOW [0xC0000091]";
			case EXCEPTION_FLT_STACK_CHECK:
				return "EXCEPTION_FLT_STACK_CHECK [0xC0000092]";
			case EXCEPTION_FLT_UNDERFLOW:
				return "EXCEPTION_FLT_UNDERFLOW [0xC0000093]";
			case EXCEPTION_ILLEGAL_INSTRUCTION:
				return "EXCEPTION_ILLEGAL_INSTRUCTION [0xC000001D]";
			case EXCEPTION_IN_PAGE_ERROR:
				return "EXCEPTION_IN_PAGE_ERROR [0xC0000006]";
			case EXCEPTION_INT_DIVIDE_BY_ZERO:
				return "EXCEPTION_FLT_DIVIDE_BY_ZERO [0xC000008E]";
			case EXCEPTION_INT_OVERFLOW:
				return "EXCEPTION_INT_OVERFLOW [0xC0000095]";
			case EXCEPTION_INVALID_DISPOSITION:
				return "EXCEPTION_INVALID_DISPOSITION [0xC0000026]";
			case EXCEPTION_NONCONTINUABLE_EXCEPTION:
				return "EXCEPTION_NONCONTINUABLE_EXCEPTION [0xC0000025]";
			case EXCEPTION_PRIV_INSTRUCTION:
				return "EXCEPTION_PRIV_INSTRUCTION [0xC0000096]";
			case EXCEPTION_SINGLE_STEP:
				return "EXCEPTION_SINGLE_STEP [0x80000004]";
			case EXCEPTION_STACK_OVERFLOW:
				return "EXCEPTION_STACK_OVERFLOW [0xC00000FD]";
			case EXCEPTION_INVALID_HANDLE:
				return "EXCEPTION_INVALID_HANDLE [0xC0000008]";
			case EXCEPTION_GUARD_PAGE:
				return "EXCEPTION_GUARD_PAGE [0x80000001]";
			default:
				return "UNKNOWN EXCEPTION";
			}
		}
		_H3API_ H3String _exInformation(_EXCEPTION_POINTERS* ep, UINT code)
		{
			H3String error;
			HMODULE hm;
			GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, LPCSTR(ep->ExceptionRecord->ExceptionAddress), &hm);

			//PIMAGE_DOS_HEADER pDOSHeader = PIMAGE_DOS_HEADER(hm);
			//PIMAGE_NT_HEADERS pNTHeaders = PIMAGE_NT_HEADERS(PBYTE(pDOSHeader) + pDOSHeader->e_lfanew);
			//DWORD base_of_code = ((DWORD)hm + pNTHeaders->OptionalHeader.BaseOfCode);
			DWORD base_of_code = DWORD(hm); // gives address relative to base instead of code start

			H3String module_name = H3Path::GetModuleFileNameA(hm);
			UINT pos = module_name.FindLastOf("/\\");
			LPCSTR short_name = pos == H3String::npos ? module_name.String() : module_name.At(pos + 1);

			error.Printf("SE %s at address offset 0x%08X inside %s.\n",
				_seDescription(code),
				(DWORD)ep->ExceptionRecord->ExceptionAddress - base_of_code,
				short_name);

			if (code == EXCEPTION_ACCESS_VIOLATION || code == EXCEPTION_IN_PAGE_ERROR)
			{
				error.PrintfAppend("Invalid operation: %s at address 0x%08X.\n",
					_opDescription(ep->ExceptionRecord->ExceptionInformation[0]),
					ep->ExceptionRecord->ExceptionInformation[1]);
			}

			if (code == EXCEPTION_IN_PAGE_ERROR)
			{
				error.PrintfAppend("Underlying NTSTATUS code that resulted in the exception %08X.\n",
					ep->ExceptionRecord->ExceptionInformation[2]);
			}

			PCONTEXT ctx = ep->ContextRecord;
			error.PrintfAppend(H3Internal::CONTEXT_FORMAT,
				ctx->Eax, ctx->Ecx, ctx->Edx, ctx->Ebx, ctx->Esp, ctx->Ebp, ctx->Esi, ctx->Edi, ctx->ContextFlags);

			return error;
		}
	}
	_H3API_ H3Exception::H3Exception(LPCSTR message) :
		std::exception(message)
	{
	}
	_H3API_ H3Exception::H3Exception(const H3String& message) :
		std::exception(message.String())
	{
	}
	_H3API_ VOID H3Exception::ShowInGame(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			H3Messagebox::Show(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		H3Messagebox::Show(msg);
	}
	_H3API_ VOID H3Exception::ShowInGame(LPCSTR precursor_text) const
	{
		ShowInGame(*this, precursor_text);
	}
	_H3API_ BOOL H3Exception::ShowInGameLog(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			return H3Messagebox::Choice(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		return H3Messagebox::Choice(msg);
	}
	_H3API_ BOOL H3Exception::ShowInGameLog(LPCSTR precursor_text) const
	{
		return ShowInGameLog(*this, precursor_text);
	}
	_H3API_ VOID H3Exception::ShowMessagebox(const std::exception& e, LPCSTR precursor_text)
	{
		if (!precursor_text)
			H3Error::ShowError(e.what());
		H3String msg(precursor_text);
		msg.AppendA("\n\n").Append(e.what());
		H3Error::ShowError(msg.String());
	}
	_H3API_ VOID H3Exception::ShowMessagebox(LPCSTR precursor_text) const
	{
		ShowMessagebox(*this, precursor_text);
	}
	_H3API_ BOOL H3Exception::ShowMessageboxLog(const std::exception& e, LPCSTR precursor_text)
	{
		return H3Error::ShowErrorChoice(e.what());
	}
	_H3API_ BOOL H3Exception::ShowMessageboxLog(LPCSTR precursor_text) const
	{
		return ShowMessageboxLog(*this, precursor_text);
	}
	_H3API_ VOID H3Exception::LogError(const std::exception& e, LPCSTR path)
	{
		H3File f;
		if (!f.Save(path))
			return;
		f.Write(PVOID(e.what()), libc::strlen(e.what()));
	}
	_H3API_ VOID H3Exception::LogError(const std::exception& e, const H3String & path)
	{
		LogError(e, path.String());
	}
	_H3API_ VOID H3Exception::LogError(LPCSTR path) const
	{
		LogError(*this, path);
	}
	_H3API_ VOID H3Exception::LogError(const H3String& path) const
	{
		LogError(*this, path);
	}
	_H3API_ H3SEHandler::H3SEHandler() :
		m_oldTranslator(_set_se_translator(H3Internal::_h3TransFunction))
	{
	}
	_H3API_ H3SEHandler::~H3SEHandler()
	{
		_set_se_translator(m_oldTranslator);
	}
}

#endif /* #if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND) */
