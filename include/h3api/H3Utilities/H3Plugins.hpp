//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-07              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

/* only available if you define this macro */
#ifdef _H3API_PLUGINS_

#include "h3api/H3Base.hpp"

namespace h3
{
	struct H3LoadedPcx;
	struct H3WavFile;
	struct H3LoadedDef;
	struct H3LoadedPcx16;
	struct H3String;
	template<typename _Elem> struct H3Vector;

namespace H3Plugin
{
	namespace AssetLoader
	{
		class H3AssetLoader
		{
		public:
			/* the number of assets added by the plugin so far */
			virtual INT NumberAdded() = 0;
			/* returns the last error */
			virtual LPCSTR GetLastError() = 0;
			/**
			 * @brief Loads a pcx from anywhere to the game space
			 * @param filePath the complete path to the pcx you are looking to load
			 * @param h3name name of the pcx to use (12-chars)
			 * @return The loaded pcx or nullptr on failure
			 */
			virtual H3LoadedPcx* LoadPcxFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;
			/**
			 * @brief Loads a wav from anywhere to the game space
			 * @param filePath the complete path to the wav you are looking to load
			 * @param h3name name of the wav to use (12-chars)
			 * @return The loaded wav or nullptr on failure
			 */
			virtual H3WavFile* LoadWavFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;

			/**
			 * @brief Loads a def from anywhere to the game space
			 * @param filePath the complete path to the def you are looking to load
			 * @param h3name name of the def to use (12-chars)
			 * @return The loaded def or nullptr on failure
			 */
			virtual H3LoadedDef* LoadDefFromFile(LPCSTR const filePath, LPCSTR const h3name) = 0;
		};

		inline H3AssetLoader* GetAssetLoader()
		{
			if (HMODULE h = LoadLibraryA("H3.AssetLoader.dll"))
				if (FARPROC f = GetProcAddress(h, "GetAssetLoader_"))
					return STDCALL_0(H3AssetLoader*, f);
			return nullptr;
		}
	} /* namespace AssetLoader */

	namespace ImageLoader
	{
		class H3ImageLoader
		{
		public:
			/* the number of images added by the plugin so far */
			virtual INT NumberAdded() = 0;
			/* returns the last error */
			virtual LPCSTR GetLastError() = 0;
			/**
			 * @brief Loads many types of image from specified fiel to h3 space. DOES NOT SUPPORT TRANSPARENCY
			 * @param filepath complete path to the image you are looking to load
			 * @param h3name name of the pcx16 to use (12-chars)
			 * @param width optional, used to resize image
			 * @param height optional, used to resize image
			 * @return Loaded pcx16 or nullptr on failure
			*/
			virtual H3LoadedPcx16* LoadImageToPcx16(LPCSTR filepath, LPCSTR h3name, INT width = -1, INT height = -1) = 0;
		};

		inline H3ImageLoader* GetImageLoader()
		{
			if (HMODULE h = LoadLibraryA("H3.ImageLoader.dll"))
				if (FARPROC f = GetProcAddress(h, "GetImageLoader_"))
					return STDCALL_0(H3ImageLoader*, f);
			return NULL;
		}
	} /* namespace ImageLoader */

	namespace TextColor
	{
		class H3TextColorInformation
		{
		public:
			/* number of colors currently available */
			virtual UINT GetNumberColors() = 0;
			/* returns a vector of H3Strings with names of colors */
			virtual const H3Vector<H3String>* GetColorNames() = 0;
			/* empties the vector of H3Strings with color names */
			virtual VOID DeleteColorNames() = 0;
			/**
			 * @brief Adds a color dynamically, duplicate names are not allowed but colors are.
			 * @param name Up to 31 characters long
			 * @param red Index of RRGGBB
			 * @param green Index of RRGGBB
			 * @param blue Index of RRGGBB
			 */
			virtual VOID AddColor(LPCSTR name, UINT8 red, UINT8 green, UINT8 blue) = 0;
			/* Adds a color dynamically from a RRGGBB value */
			VOID AddColor(LPCSTR name, DWORD rgb_color)
			{
				AddColor(name, (rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
			}
		};

		inline H3TextColorInformation* GetTextColor()
		{
			if (HMODULE h = LoadLibraryA("H3.TextColor.dll"))
				if (FARPROC f = GetProcAddress(h, "GetTextColor_"))
					return STDCALL_0(H3TextColorInformation*, f);
			return nullptr;
		}
	} /* namespace TextColor */

} /* namespace H3Plugin */
} /* namespace h3 */

#endif /* _H3API_PLUGINS_ */