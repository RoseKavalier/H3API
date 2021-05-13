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

#pragma once

#include "h3api/H3Base.hpp"

#include <eh.h>
#include <exception>
#include <Psapi.h>

namespace h3
{
	struct H3String;
	class  H3Exception;
	class  H3SEHandler;

	/**
	* @brief Catches SEH exceptions when combined with H3SEHandler
	* Also adds some logging options for std::exception
	* See H3SEHandler below for more information
	*/
	class H3Exception : public std::exception
	{
	public:
		_H3API_ H3Exception(LPCSTR message);
		_H3API_ H3Exception(const H3String& message);
		// * creates an in-game dialog showing the error
		_H3API_ VOID ShowInGame(LPCSTR precursor_text = nullptr) const;
		// * creates an in-game dialog showing the error
		_H3API_ BOOL ShowInGameLog(LPCSTR precursor_text = nullptr) const;
		// * creates a out-of-game messagebox showing the error
		_H3API_ VOID ShowMessagebox(LPCSTR precursor_text = nullptr) const;
		// * creates a out-of-game messagebox showing the error
		_H3API_ BOOL ShowMessageboxLog(LPCSTR precursor_text = nullptr) const;
		// * logs error to specified path
		_H3API_ VOID LogError(LPCSTR path) const;
		_H3API_ VOID LogError(const H3String& path) const;

		_H3API_ static VOID ShowInGame(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static BOOL ShowInGameLog(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static VOID ShowMessagebox(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static BOOL ShowMessageboxLog(const std::exception& e, LPCSTR precursor_text = nullptr);
		_H3API_ static VOID LogError(const std::exception& e, LPCSTR path);
		_H3API_ static VOID LogError(const std::exception& e, const H3String& path);
	};

	/**
	 * @brief create a H3SEHandler object on the stack where you want to use try{} catch{}
	 * to receive the error code, use the what() exception member function
	 * e.g. this snippet would show an error in-game without crashing the game
	 * \code{.cpp}
	 * H3SEHandler seh;
	 * try
	 * {
	 *     some stuff that can create an error...
	 * }
	 * catch (const HException& e)
	 * {
	 * 	   e.ShowInGame();
	 * }
	 * catch (const std::exception& e)
	 * {
	 *		H3Exception::LogError(e, custom_file_name);
	 * }\endcode
	 */
	class H3SEHandler
	{
		const _se_translator_function m_oldTranslator;
	public:
		_H3API_ H3SEHandler();
		_H3API_ ~H3SEHandler();
	};

}

#endif /* if defined(_H3API_EXCEPTION_) && defined(_CPPUNWIND) */
