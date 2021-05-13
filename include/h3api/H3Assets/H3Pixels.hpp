//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(ARGB888);
	_H3API_DECLARE_(RGB888);
	struct H3RGB555;
	struct H3RGB565;
	_H3API_DECLARE_(HSV);

	/** @brief Represents a 15bit r5g5b5 pixel*/
	typedef UINT16 RGB555;
	/** @brief Represents a 16bit r5g6b5 pixel*/
	typedef UINT16 RGB565;

#pragma pack(push, 1)
	/** @brief 24bit rgb pixel stored as 3 contiguous bytes. Now only exists in H3LoadedPcx24*/
	struct H3RGB888
	{
		_H3API_SIZE_(3);

		UINT8 r;
		UINT8 g;
		UINT8 b;

		/** @brief approximate darkening by 20%, but faster than hsv*/
		_H3API_ VOID Darken20();
		/** @brief approximate darkening by 50%, but faster than hsv*/
		_H3API_ VOID Darken50();
		/** @brief applies grayscale effect by narrowing the gap between the rgb components*/
		_H3API_ VOID GrayScale();
		/**
		 * @brief darkens pixel's color through HSV by specified amount*
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(const UINT8 amount);
		/**
		 * @brief lightens pixel's color through HSV by amount
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(const UINT8 amount);
		/**
		 * @brief applies rgb mask of specified weight, assuming source pixel has full alpha visibility
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @param alpha weight component  0..255
		 */
		_H3API_ VOID AlphaDraw(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha);
		/**
		 * @brief Get equivalent hue as normalized float
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @return FLOAT 0.0f..1.0f
		 */
		_H3API_ static FLOAT GetHueAsNormalizedFloat(UINT8 red, UINT8 green, UINT8 blue);
		/**
		 * @brief Pack rgb components into a single dword with full alpha visibility
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @return DWORD packed rgb
		 */
		_H3API_ static DWORD Pack(UINT8 red, UINT8 green, UINT8 blue);
		_H3API_ H3RGB888();
		_H3API_ H3RGB888(DWORD color);
		_H3API_ H3RGB888(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB888(const H3RGB565& rgb);
		_H3API_ H3RGB888(const H3ARGB888& rgb);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB888& col);
	#pragma region NamedColors
		_H3API_ static H3RGB888 Regular();
		_H3API_ static H3RGB888 Highlight();
		_H3API_ static H3RGB888 H3Red();
		_H3API_ static H3RGB888 H3Cyan();
		_H3API_ static H3RGB888 H3Green();
		_H3API_ static H3RGB888 H3Blue();
		_H3API_ static H3RGB888 H3Yellow();
		_H3API_ static H3RGB888 H3Orange();
		_H3API_ static H3RGB888 H3Purple();
		_H3API_ static H3RGB888 H3Pink();
		_H3API_ static H3RGB888 AliceBlue();
		_H3API_ static H3RGB888 AntiqueWhite();
		_H3API_ static H3RGB888 Aqua();
		_H3API_ static H3RGB888 Aquamarine();
		_H3API_ static H3RGB888 Azure();
		_H3API_ static H3RGB888 Beige();
		_H3API_ static H3RGB888 Bisque();
		_H3API_ static H3RGB888 Black();
		_H3API_ static H3RGB888 BlanchedAlmond();
		_H3API_ static H3RGB888 Blue();
		_H3API_ static H3RGB888 BlueViolet();
		_H3API_ static H3RGB888 Brown();
		_H3API_ static H3RGB888 BurlyWood();
		_H3API_ static H3RGB888 CadetBlue();
		_H3API_ static H3RGB888 Chartreuse();
		_H3API_ static H3RGB888 Chocolate();
		_H3API_ static H3RGB888 Coral();
		_H3API_ static H3RGB888 CornflowerBlue();
		_H3API_ static H3RGB888 Cornsilk();
		_H3API_ static H3RGB888 Crimson();
		_H3API_ static H3RGB888 Cyan();
		_H3API_ static H3RGB888 DarkBlue();
		_H3API_ static H3RGB888 DarkCyan();
		_H3API_ static H3RGB888 DarkGoldenRod();
		_H3API_ static H3RGB888 DarkGray();
		_H3API_ static H3RGB888 DarkGrey();
		_H3API_ static H3RGB888 DarkGreen();
		_H3API_ static H3RGB888 DarkKhaki();
		_H3API_ static H3RGB888 DarkMagenta();
		_H3API_ static H3RGB888 DarkOliveGreen();
		_H3API_ static H3RGB888 Darkorange();
		_H3API_ static H3RGB888 DarkOrchid();
		_H3API_ static H3RGB888 DarkRed();
		_H3API_ static H3RGB888 DarkSalmon();
		_H3API_ static H3RGB888 DarkSeaGreen();
		_H3API_ static H3RGB888 DarkSlateBlue();
		_H3API_ static H3RGB888 DarkSlateGray();
		_H3API_ static H3RGB888 DarkSlateGrey();
		_H3API_ static H3RGB888 DarkTurquoise();
		_H3API_ static H3RGB888 DarkViolet();
		_H3API_ static H3RGB888 DeepPink();
		_H3API_ static H3RGB888 DeepSkyBlue();
		_H3API_ static H3RGB888 DimGray();
		_H3API_ static H3RGB888 DimGrey();
		_H3API_ static H3RGB888 DodgerBlue();
		_H3API_ static H3RGB888 FireBrick();
		_H3API_ static H3RGB888 FloralWhite();
		_H3API_ static H3RGB888 ForestGreen();
		_H3API_ static H3RGB888 Fuchsia();
		_H3API_ static H3RGB888 Gainsboro();
		_H3API_ static H3RGB888 GhostWhite();
		_H3API_ static H3RGB888 Gold();
		_H3API_ static H3RGB888 GoldenRod();
		_H3API_ static H3RGB888 Gray();
		_H3API_ static H3RGB888 Grey();
		_H3API_ static H3RGB888 Green();
		_H3API_ static H3RGB888 GreenYellow();
		_H3API_ static H3RGB888 HoneyDew();
		_H3API_ static H3RGB888 HotPink();
		_H3API_ static H3RGB888 IndianRed();
		_H3API_ static H3RGB888 Indigo();
		_H3API_ static H3RGB888 Ivory();
		_H3API_ static H3RGB888 Khaki();
		_H3API_ static H3RGB888 Lavender();
		_H3API_ static H3RGB888 LavenderBlush();
		_H3API_ static H3RGB888 LawnGreen();
		_H3API_ static H3RGB888 LemonChiffon();
		_H3API_ static H3RGB888 LightBlue();
		_H3API_ static H3RGB888 LightCoral();
		_H3API_ static H3RGB888 LightCyan();
		_H3API_ static H3RGB888 LightGoldenRodYellow();
		_H3API_ static H3RGB888 LightGray();
		_H3API_ static H3RGB888 LightGrey();
		_H3API_ static H3RGB888 LightGreen();
		_H3API_ static H3RGB888 LightPink();
		_H3API_ static H3RGB888 LightSalmon();
		_H3API_ static H3RGB888 LightSeaGreen();
		_H3API_ static H3RGB888 LightSkyBlue();
		_H3API_ static H3RGB888 LightSlateGray();
		_H3API_ static H3RGB888 LightSlateGrey();
		_H3API_ static H3RGB888 LightSteelBlue();
		_H3API_ static H3RGB888 LightYellow();
		_H3API_ static H3RGB888 Lime();
		_H3API_ static H3RGB888 LimeGreen();
		_H3API_ static H3RGB888 Linen();
		_H3API_ static H3RGB888 Magenta();
		_H3API_ static H3RGB888 Maroon();
		_H3API_ static H3RGB888 MediumAquaMarine();
		_H3API_ static H3RGB888 MediumBlue();
		_H3API_ static H3RGB888 MediumOrchid();
		_H3API_ static H3RGB888 MediumPurple();
		_H3API_ static H3RGB888 MediumSeaGreen();
		_H3API_ static H3RGB888 MediumSlateBlue();
		_H3API_ static H3RGB888 MediumSpringGreen();
		_H3API_ static H3RGB888 MediumTurquoise();
		_H3API_ static H3RGB888 MediumVioletRed();
		_H3API_ static H3RGB888 MidnightBlue();
		_H3API_ static H3RGB888 MintCream();
		_H3API_ static H3RGB888 MistyRose();
		_H3API_ static H3RGB888 Moccasin();
		_H3API_ static H3RGB888 NavajoWhite();
		_H3API_ static H3RGB888 Navy();
		_H3API_ static H3RGB888 OldLace();
		_H3API_ static H3RGB888 Olive();
		_H3API_ static H3RGB888 OliveDrab();
		_H3API_ static H3RGB888 Orange();
		_H3API_ static H3RGB888 OrangeRed();
		_H3API_ static H3RGB888 Orchid();
		_H3API_ static H3RGB888 PaleGoldenRod();
		_H3API_ static H3RGB888 PaleGreen();
		_H3API_ static H3RGB888 PaleTurquoise();
		_H3API_ static H3RGB888 PaleVioletRed();
		_H3API_ static H3RGB888 PapayaWhip();
		_H3API_ static H3RGB888 PeachPuff();
		_H3API_ static H3RGB888 Peru();
		_H3API_ static H3RGB888 Pink();
		_H3API_ static H3RGB888 Plum();
		_H3API_ static H3RGB888 PowderBlue();
		_H3API_ static H3RGB888 Purple();
		_H3API_ static H3RGB888 Red();
		_H3API_ static H3RGB888 RosyBrown();
		_H3API_ static H3RGB888 RoyalBlue();
		_H3API_ static H3RGB888 SaddleBrown();
		_H3API_ static H3RGB888 Salmon();
		_H3API_ static H3RGB888 SandyBrown();
		_H3API_ static H3RGB888 SeaGreen();
		_H3API_ static H3RGB888 SeaShell();
		_H3API_ static H3RGB888 Sienna();
		_H3API_ static H3RGB888 Silver();
		_H3API_ static H3RGB888 SkyBlue();
		_H3API_ static H3RGB888 SlateBlue();
		_H3API_ static H3RGB888 SlateGray();
		_H3API_ static H3RGB888 SlateGrey();
		_H3API_ static H3RGB888 Snow();
		_H3API_ static H3RGB888 SpringGreen();
		_H3API_ static H3RGB888 SteelBlue();
		_H3API_ static H3RGB888 Tan();
		_H3API_ static H3RGB888 Teal();
		_H3API_ static H3RGB888 Thistle();
		_H3API_ static H3RGB888 Tomato();
		_H3API_ static H3RGB888 Turquoise();
		_H3API_ static H3RGB888 Violet();
		_H3API_ static H3RGB888 Wheat();
		_H3API_ static H3RGB888 White();
		_H3API_ static H3RGB888 WhiteSmoke();
		_H3API_ static H3RGB888 Yellow();
		_H3API_ static H3RGB888 YellowGreen();
	#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB888);
#pragma pack(pop) /* align-1 */

#pragma pack(push, 4)
	/** @brief 32bit argb pixel in HD mod*/
	struct H3ARGB888
	{
		_H3API_SIZE_(4);

		UINT8 b;
		UINT8 g;
		UINT8 r;
		UINT8 a;

		/**
		 * @brief pack the pixel components into a single dword
		 * @return UINT packed pixel value as dword
		 */
		_H3API_ UINT Value() const;
		/**
		 * @brief pack the pixel components into a single dword
		 * @return UINT packed pixel value as dword
		 */
		_H3API_ UINT operator*() const;
		/**
		 * @brief automatic cast as DWORD
		 * @return DWORD packed pixel value as dword
		 */
		_H3API_ operator DWORD () const;
		/**
		 * @brief darkens pixel's color through HSV by specified amount
		 * note full transparency is not supported, so this only affects rgb components
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(const UINT8 amount);
		/**
		 * @brief lightens pixel's color through HSV by specified amount
		 * note full transparency is not supported, so this only affects rgb components
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(const UINT8 amount);
		/** @brief applies grayscale effect by narrowing the gap between the rgb components*/
		_H3API_ VOID GrayScale();
		/** @brief reorders argb components based on legacy drawing, pre - HDmod 5.0RC63*/
		_H3API_ VOID Legacy();
		_H3API_ H3ARGB888();
		_H3API_ H3ARGB888(DWORD col);
		_H3API_ H3ARGB888(const H3RGB565& col);
		_H3API_ H3ARGB888(const H3RGB888& col);
		_H3API_ H3ARGB888(const H3ARGB888& col);
		_H3API_ H3ARGB888(UINT8 red, UINT8 blue, UINT8 green);
		/**
		 * @brief pack the pixel components into a single dword
		 * @return DWORD packed pixel value as dword
		 */
		_H3API_ DWORD GetColor() const;
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(UINT16 col);
		_H3API_ VOID operator=(UINT32 col);
		_H3API_ BOOL operator==(const H3ARGB888& col);
		/** @brief approximate lightening by 25% following game logic*/
		_H3API_ VOID LightShadow();
		/** @brief approximate darkening by 50% following game logic*/
		_H3API_ VOID DarkShadow();
		/**
		 * @brief blend or superpose a specific mask over the current pixel*
		 * @param col mask to apply
		 */
		_H3API_ VOID Blend(const H3ARGB888& col);
	#pragma region NamedColors
		_H3API_ static H3ARGB888 Regular();
		_H3API_ static H3ARGB888 Highlight();
		_H3API_ static H3ARGB888 H3Red();
		_H3API_ static H3ARGB888 H3Cyan();
		_H3API_ static H3ARGB888 H3Green();
		_H3API_ static H3ARGB888 H3Blue();
		_H3API_ static H3ARGB888 H3Yellow();
		_H3API_ static H3ARGB888 H3Orange();
		_H3API_ static H3ARGB888 H3Purple();
		_H3API_ static H3ARGB888 H3Pink();
		_H3API_ static H3ARGB888 AliceBlue();
		_H3API_ static H3ARGB888 AntiqueWhite();
		_H3API_ static H3ARGB888 Aqua();
		_H3API_ static H3ARGB888 Aquamarine();
		_H3API_ static H3ARGB888 Azure();
		_H3API_ static H3ARGB888 Beige();
		_H3API_ static H3ARGB888 Bisque();
		_H3API_ static H3ARGB888 Black();
		_H3API_ static H3ARGB888 BlanchedAlmond();
		_H3API_ static H3ARGB888 Blue();
		_H3API_ static H3ARGB888 BlueViolet();
		_H3API_ static H3ARGB888 Brown();
		_H3API_ static H3ARGB888 BurlyWood();
		_H3API_ static H3ARGB888 CadetBlue();
		_H3API_ static H3ARGB888 Chartreuse();
		_H3API_ static H3ARGB888 Chocolate();
		_H3API_ static H3ARGB888 Coral();
		_H3API_ static H3ARGB888 CornflowerBlue();
		_H3API_ static H3ARGB888 Cornsilk();
		_H3API_ static H3ARGB888 Crimson();
		_H3API_ static H3ARGB888 Cyan();
		_H3API_ static H3ARGB888 DarkBlue();
		_H3API_ static H3ARGB888 DarkCyan();
		_H3API_ static H3ARGB888 DarkGoldenRod();
		_H3API_ static H3ARGB888 DarkGray();
		_H3API_ static H3ARGB888 DarkGrey();
		_H3API_ static H3ARGB888 DarkGreen();
		_H3API_ static H3ARGB888 DarkKhaki();
		_H3API_ static H3ARGB888 DarkMagenta();
		_H3API_ static H3ARGB888 DarkOliveGreen();
		_H3API_ static H3ARGB888 Darkorange();
		_H3API_ static H3ARGB888 DarkOrchid();
		_H3API_ static H3ARGB888 DarkRed();
		_H3API_ static H3ARGB888 DarkSalmon();
		_H3API_ static H3ARGB888 DarkSeaGreen();
		_H3API_ static H3ARGB888 DarkSlateBlue();
		_H3API_ static H3ARGB888 DarkSlateGray();
		_H3API_ static H3ARGB888 DarkSlateGrey();
		_H3API_ static H3ARGB888 DarkTurquoise();
		_H3API_ static H3ARGB888 DarkViolet();
		_H3API_ static H3ARGB888 DeepPink();
		_H3API_ static H3ARGB888 DeepSkyBlue();
		_H3API_ static H3ARGB888 DimGray();
		_H3API_ static H3ARGB888 DimGrey();
		_H3API_ static H3ARGB888 DodgerBlue();
		_H3API_ static H3ARGB888 FireBrick();
		_H3API_ static H3ARGB888 FloralWhite();
		_H3API_ static H3ARGB888 ForestGreen();
		_H3API_ static H3ARGB888 Fuchsia();
		_H3API_ static H3ARGB888 Gainsboro();
		_H3API_ static H3ARGB888 GhostWhite();
		_H3API_ static H3ARGB888 Gold();
		_H3API_ static H3ARGB888 GoldenRod();
		_H3API_ static H3ARGB888 Gray();
		_H3API_ static H3ARGB888 Grey();
		_H3API_ static H3ARGB888 Green();
		_H3API_ static H3ARGB888 GreenYellow();
		_H3API_ static H3ARGB888 HoneyDew();
		_H3API_ static H3ARGB888 HotPink();
		_H3API_ static H3ARGB888 IndianRed();
		_H3API_ static H3ARGB888 Indigo();
		_H3API_ static H3ARGB888 Ivory();
		_H3API_ static H3ARGB888 Khaki();
		_H3API_ static H3ARGB888 Lavender();
		_H3API_ static H3ARGB888 LavenderBlush();
		_H3API_ static H3ARGB888 LawnGreen();
		_H3API_ static H3ARGB888 LemonChiffon();
		_H3API_ static H3ARGB888 LightBlue();
		_H3API_ static H3ARGB888 LightCoral();
		_H3API_ static H3ARGB888 LightCyan();
		_H3API_ static H3ARGB888 LightGoldenRodYellow();
		_H3API_ static H3ARGB888 LightGray();
		_H3API_ static H3ARGB888 LightGrey();
		_H3API_ static H3ARGB888 LightGreen();
		_H3API_ static H3ARGB888 LightPink();
		_H3API_ static H3ARGB888 LightSalmon();
		_H3API_ static H3ARGB888 LightSeaGreen();
		_H3API_ static H3ARGB888 LightSkyBlue();
		_H3API_ static H3ARGB888 LightSlateGray();
		_H3API_ static H3ARGB888 LightSlateGrey();
		_H3API_ static H3ARGB888 LightSteelBlue();
		_H3API_ static H3ARGB888 LightYellow();
		_H3API_ static H3ARGB888 Lime();
		_H3API_ static H3ARGB888 LimeGreen();
		_H3API_ static H3ARGB888 Linen();
		_H3API_ static H3ARGB888 Magenta();
		_H3API_ static H3ARGB888 Maroon();
		_H3API_ static H3ARGB888 MediumAquaMarine();
		_H3API_ static H3ARGB888 MediumBlue();
		_H3API_ static H3ARGB888 MediumOrchid();
		_H3API_ static H3ARGB888 MediumPurple();
		_H3API_ static H3ARGB888 MediumSeaGreen();
		_H3API_ static H3ARGB888 MediumSlateBlue();
		_H3API_ static H3ARGB888 MediumSpringGreen();
		_H3API_ static H3ARGB888 MediumTurquoise();
		_H3API_ static H3ARGB888 MediumVioletRed();
		_H3API_ static H3ARGB888 MidnightBlue();
		_H3API_ static H3ARGB888 MintCream();
		_H3API_ static H3ARGB888 MistyRose();
		_H3API_ static H3ARGB888 Moccasin();
		_H3API_ static H3ARGB888 NavajoWhite();
		_H3API_ static H3ARGB888 Navy();
		_H3API_ static H3ARGB888 OldLace();
		_H3API_ static H3ARGB888 Olive();
		_H3API_ static H3ARGB888 OliveDrab();
		_H3API_ static H3ARGB888 Orange();
		_H3API_ static H3ARGB888 OrangeRed();
		_H3API_ static H3ARGB888 Orchid();
		_H3API_ static H3ARGB888 PaleGoldenRod();
		_H3API_ static H3ARGB888 PaleGreen();
		_H3API_ static H3ARGB888 PaleTurquoise();
		_H3API_ static H3ARGB888 PaleVioletRed();
		_H3API_ static H3ARGB888 PapayaWhip();
		_H3API_ static H3ARGB888 PeachPuff();
		_H3API_ static H3ARGB888 Peru();
		_H3API_ static H3ARGB888 Pink();
		_H3API_ static H3ARGB888 Plum();
		_H3API_ static H3ARGB888 PowderBlue();
		_H3API_ static H3ARGB888 Purple();
		_H3API_ static H3ARGB888 Red();
		_H3API_ static H3ARGB888 RosyBrown();
		_H3API_ static H3ARGB888 RoyalBlue();
		_H3API_ static H3ARGB888 SaddleBrown();
		_H3API_ static H3ARGB888 Salmon();
		_H3API_ static H3ARGB888 SandyBrown();
		_H3API_ static H3ARGB888 SeaGreen();
		_H3API_ static H3ARGB888 SeaShell();
		_H3API_ static H3ARGB888 Sienna();
		_H3API_ static H3ARGB888 Silver();
		_H3API_ static H3ARGB888 SkyBlue();
		_H3API_ static H3ARGB888 SlateBlue();
		_H3API_ static H3ARGB888 SlateGray();
		_H3API_ static H3ARGB888 SlateGrey();
		_H3API_ static H3ARGB888 Snow();
		_H3API_ static H3ARGB888 SpringGreen();
		_H3API_ static H3ARGB888 SteelBlue();
		_H3API_ static H3ARGB888 Tan();
		_H3API_ static H3ARGB888 Teal();
		_H3API_ static H3ARGB888 Thistle();
		_H3API_ static H3ARGB888 Tomato();
		_H3API_ static H3ARGB888 Turquoise();
		_H3API_ static H3ARGB888 Violet();
		_H3API_ static H3ARGB888 Wheat();
		_H3API_ static H3ARGB888 White();
		_H3API_ static H3ARGB888 WhiteSmoke();
		_H3API_ static H3ARGB888 Yellow();
		_H3API_ static H3ARGB888 YellowGreen();
	#pragma endregion
	protected:
		_H3API_ PDWORD AsDword();
		_H3API_ PDWORD AsDword() const;
	};
	_H3API_ASSERT_SIZE_(H3ARGB888);

	/**
	 * @brief 15bits rgb packed in 2 bytes; apparently unused by h3 but the mechanics exist
	 * This is the predominant type used in the mapeditor.
	 * https://docs.microsoft.com/en-us/windows/desktop/DirectShow/working-with-16-bit-rgb
	 */
	struct H3RGB555
	{
		_H3API_SIZE_(2);
	protected:
		RGB555 bits;
	public:
		_H3API_ UINT8 GetRed();
		_H3API_ UINT8 GetGreen();
		_H3API_ UINT8 GetBlue();
		_H3API_ DWORD UnPack();
		_H3API_ VOID SetBits(WORD color);
		_H3API_ static WORD Pack(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ static DWORD Unpack(RGB555 rgb);
		_H3API_ VOID PackRGB(UINT8 r, UINT8 g, UINT8 b);
	};
	_H3API_ASSERT_SIZE_(H3RGB555);

	/**
	 * @brief 16bits rgb packed in 2 bytes; most common type used without 32bit mode
	 * https://docs.microsoft.com/en-us/windows/desktop/DirectShow/working-with-16-bit-rgb
	 */
	struct H3RGB565
	{
		_H3API_SIZE_(2);
		_H3API_ static H3RGB565 mask25();
		_H3API_ static H3RGB565 mask50();

protected:
		RGB565 bits;
public:
		/**
		 * @brief retrieve the packed red component
		 * @return UINT8 0..31
		 */
		_H3API_ UINT8 GetRed() const;
		/**
		 * @brief retrieve the red component in 8bit format
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetRed8() const;
		/**
		 * @brief retrieve the packed green component
		 * @return UINT8 0..63
		 */
		_H3API_ UINT8 GetGreen() const;
		/**
		 * @brief retrieve the green component in 8bit format
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetGreen8() const;
		/**
		 * @brief retrieve the packed blue component
		 * @return UINT8 0..31
		 */
		_H3API_ UINT8 GetBlue() const;
		/**
		 * @brief retrieve the blue component in 8bit format
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetBlue8() const;
		/**
		 * @brief retrieves the rgb components in 24bit format
		 * @return DWORD 0x000000..0xFFFFFF
		 */
		_H3API_ DWORD GetRGB888() const;
		/**
		 * @brief Get a copy of the packed rgb components
		 * @return RGB565 color packed in 2 bytes
		 */
		_H3API_ RGB565 GetBits() const;
		_H3API_ H3RGB565();
		_H3API_ H3RGB565(RGB565 rgb);
		_H3API_ H3RGB565(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB565(DWORD color);
		_H3API_ H3RGB565(const H3RGB888& color);
		_H3API_ H3RGB565(const H3ARGB888& color);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB565& col);
		/**
		 * @brief automatic cast as 2 bytes WORD
		 * @return WORD color packed in 2 bytes
		 */
		_H3API_ operator WORD () const;
		/**
		 * @brief Get a copy of the packed rgb components
		 * @return WORD color packed in 2 bytes
		 */
		_H3API_ WORD Value() const;
		/**
		 * @brief Set the packed color to the specified value
		 * @param color packed 16bit rgb
		 */
		_H3API_ VOID SetBits(WORD color);
		/**
		 * @brief Set the pixel's components
		 * @param r red component 0..255
		 * @param g green component 0..255
		 * @param b blue component 0..255
		 */
		_H3API_ VOID PackRGB565(UINT8 r, UINT8 g, UINT8 b);
		/**
		 * @brief Set the pixel's components
		 * @param rgb color to use
		 */
		_H3API_ VOID Pack(H3RGB888& rgb);
		/**
		 * @brief transform any rgb components into a packed 16bit pixel
		 * @param r red component 0..255
		 * @param g green component 0..255
		 * @param b blue component 0..255
		 * @return WORD packed 16bit color
		 */
		_H3API_ static WORD  Pack(UINT8 r, UINT8 g, UINT8 b);
		/**
		 * @brief transform a packed 16bit color into a 24bit pixel
		 * @param rgb 16bit color to unpack
		 * @return DWORD color without alpha component 0x000000..0xFFFFFF
		 */
		_H3API_ static DWORD Unpack(RGB565 rgb);
		/**
		 * @brief darkens pixel's color by specified amount
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(UINT8 amount);
		/**
		 * @brief lightens pixel's color by specified amount
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(UINT8 amount);
		/** @brief applies grayscale effect by narrowing the gap between the rgb components*/
		_H3API_ VOID GrayScale();
		/**
		 * @brief darkens by 25% as performed by h3, using default masks
		 * i.e. rgb components are reduced to 75% of their current value
		 */
		_H3API_ VOID LightShadow();
		/**
		 * @brief darkens by 25% as performed by h3, using specified masks
		 * i.e. rgb components are reduced to 75% of their current value
		 * @param mask50 a mask representing 50% rgb components
		 * @param mask25 a mask representing 25% rgb components
		 */
		_H3API_ VOID LightShadow(RGB565 mask50, RGB565 mask25);
		/**
		 * @brief darkens by 50% as performed by h3, using default mask
		 * i.e. rgb components are reduced to 50% of their current value
		 */
		_H3API_ VOID DarkShadow();
		/**
		 * @brief darkens by 50% as performed by h3, using specified mask
		 * i.e. rgb components are reduced to 50% of their current value
		 * @param mask a mask representing 50% rgb components
		 */
		_H3API_ VOID DarkShadow(RGB565 mask);
		/**
		 * @brief Blend 2 colors together to obtain a new one
		 * @param col the color to mix
		 */
		_H3API_ VOID Blend(const H3RGB565& col);
		/**
		 * @brief Blend 2 colors together to obtain a new one, with an upper cap specified by a mask
		 * @param col the color to mix
		 * @param mask upper limit for blending of source and \p col
		 */
		_H3API_ VOID Blend(const H3RGB565& col, RGB565 mask);
#pragma region NamedColors
		_H3API_ static RGB565 Regular();
		_H3API_ static RGB565 Highlight();
		_H3API_ static RGB565 H3Red();
		_H3API_ static RGB565 H3Cyan();
		_H3API_ static RGB565 H3Green();
		_H3API_ static RGB565 H3Blue();
		_H3API_ static RGB565 H3Yellow();
		_H3API_ static RGB565 H3Orange();
		_H3API_ static RGB565 H3Purple();
		_H3API_ static RGB565 H3Pink();
		_H3API_ static RGB565 AliceBlue();
		_H3API_ static RGB565 AntiqueWhite();
		_H3API_ static RGB565 Aqua();
		_H3API_ static RGB565 Aquamarine();
		_H3API_ static RGB565 Azure();
		_H3API_ static RGB565 Beige();
		_H3API_ static RGB565 Bisque();
		_H3API_ static RGB565 Black();
		_H3API_ static RGB565 BlanchedAlmond();
		_H3API_ static RGB565 Blue();
		_H3API_ static RGB565 BlueViolet();
		_H3API_ static RGB565 Brown();
		_H3API_ static RGB565 BurlyWood();
		_H3API_ static RGB565 CadetBlue();
		_H3API_ static RGB565 Chartreuse();
		_H3API_ static RGB565 Chocolate();
		_H3API_ static RGB565 Coral();
		_H3API_ static RGB565 CornflowerBlue();
		_H3API_ static RGB565 Cornsilk();
		_H3API_ static RGB565 Crimson();
		_H3API_ static RGB565 Cyan();
		_H3API_ static RGB565 DarkBlue();
		_H3API_ static RGB565 DarkCyan();
		_H3API_ static RGB565 DarkGoldenRod();
		_H3API_ static RGB565 DarkGray();
		_H3API_ static RGB565 DarkGrey();
		_H3API_ static RGB565 DarkGreen();
		_H3API_ static RGB565 DarkKhaki();
		_H3API_ static RGB565 DarkMagenta();
		_H3API_ static RGB565 DarkOliveGreen();
		_H3API_ static RGB565 Darkorange();
		_H3API_ static RGB565 DarkOrchid();
		_H3API_ static RGB565 DarkRed();
		_H3API_ static RGB565 DarkSalmon();
		_H3API_ static RGB565 DarkSeaGreen();
		_H3API_ static RGB565 DarkSlateBlue();
		_H3API_ static RGB565 DarkSlateGray();
		_H3API_ static RGB565 DarkSlateGrey();
		_H3API_ static RGB565 DarkTurquoise();
		_H3API_ static RGB565 DarkViolet();
		_H3API_ static RGB565 DeepPink();
		_H3API_ static RGB565 DeepSkyBlue();
		_H3API_ static RGB565 DimGray();
		_H3API_ static RGB565 DimGrey();
		_H3API_ static RGB565 DodgerBlue();
		_H3API_ static RGB565 FireBrick();
		_H3API_ static RGB565 FloralWhite();
		_H3API_ static RGB565 ForestGreen();
		_H3API_ static RGB565 Fuchsia();
		_H3API_ static RGB565 Gainsboro();
		_H3API_ static RGB565 GhostWhite();
		_H3API_ static RGB565 Gold();
		_H3API_ static RGB565 GoldenRod();
		_H3API_ static RGB565 Gray();
		_H3API_ static RGB565 Grey();
		_H3API_ static RGB565 Green();
		_H3API_ static RGB565 GreenYellow();
		_H3API_ static RGB565 HoneyDew();
		_H3API_ static RGB565 HotPink();
		_H3API_ static RGB565 IndianRed();
		_H3API_ static RGB565 Indigo();
		_H3API_ static RGB565 Ivory();
		_H3API_ static RGB565 Khaki();
		_H3API_ static RGB565 Lavender();
		_H3API_ static RGB565 LavenderBlush();
		_H3API_ static RGB565 LawnGreen();
		_H3API_ static RGB565 LemonChiffon();
		_H3API_ static RGB565 LightBlue();
		_H3API_ static RGB565 LightCoral();
		_H3API_ static RGB565 LightCyan();
		_H3API_ static RGB565 LightGoldenRodYellow();
		_H3API_ static RGB565 LightGray();
		_H3API_ static RGB565 LightGrey();
		_H3API_ static RGB565 LightGreen();
		_H3API_ static RGB565 LightPink();
		_H3API_ static RGB565 LightSalmon();
		_H3API_ static RGB565 LightSeaGreen();
		_H3API_ static RGB565 LightSkyBlue();
		_H3API_ static RGB565 LightSlateGray();
		_H3API_ static RGB565 LightSlateGrey();
		_H3API_ static RGB565 LightSteelBlue();
		_H3API_ static RGB565 LightYellow();
		_H3API_ static RGB565 Lime();
		_H3API_ static RGB565 LimeGreen();
		_H3API_ static RGB565 Linen();
		_H3API_ static RGB565 Magenta();
		_H3API_ static RGB565 Maroon();
		_H3API_ static RGB565 MediumAquaMarine();
		_H3API_ static RGB565 MediumBlue();
		_H3API_ static RGB565 MediumOrchid();
		_H3API_ static RGB565 MediumPurple();
		_H3API_ static RGB565 MediumSeaGreen();
		_H3API_ static RGB565 MediumSlateBlue();
		_H3API_ static RGB565 MediumSpringGreen();
		_H3API_ static RGB565 MediumTurquoise();
		_H3API_ static RGB565 MediumVioletRed();
		_H3API_ static RGB565 MidnightBlue();
		_H3API_ static RGB565 MintCream();
		_H3API_ static RGB565 MistyRose();
		_H3API_ static RGB565 Moccasin();
		_H3API_ static RGB565 NavajoWhite();
		_H3API_ static RGB565 Navy();
		_H3API_ static RGB565 OldLace();
		_H3API_ static RGB565 Olive();
		_H3API_ static RGB565 OliveDrab();
		_H3API_ static RGB565 Orange();
		_H3API_ static RGB565 OrangeRed();
		_H3API_ static RGB565 Orchid();
		_H3API_ static RGB565 PaleGoldenRod();
		_H3API_ static RGB565 PaleGreen();
		_H3API_ static RGB565 PaleTurquoise();
		_H3API_ static RGB565 PaleVioletRed();
		_H3API_ static RGB565 PapayaWhip();
		_H3API_ static RGB565 PeachPuff();
		_H3API_ static RGB565 Peru();
		_H3API_ static RGB565 Pink();
		_H3API_ static RGB565 Plum();
		_H3API_ static RGB565 PowderBlue();
		_H3API_ static RGB565 Purple();
		_H3API_ static RGB565 Red();
		_H3API_ static RGB565 RosyBrown();
		_H3API_ static RGB565 RoyalBlue();
		_H3API_ static RGB565 SaddleBrown();
		_H3API_ static RGB565 Salmon();
		_H3API_ static RGB565 SandyBrown();
		_H3API_ static RGB565 SeaGreen();
		_H3API_ static RGB565 SeaShell();
		_H3API_ static RGB565 Sienna();
		_H3API_ static RGB565 Silver();
		_H3API_ static RGB565 SkyBlue();
		_H3API_ static RGB565 SlateBlue();
		_H3API_ static RGB565 SlateGray();
		_H3API_ static RGB565 SlateGrey();
		_H3API_ static RGB565 Snow();
		_H3API_ static RGB565 SpringGreen();
		_H3API_ static RGB565 SteelBlue();
		_H3API_ static RGB565 Tan();
		_H3API_ static RGB565 Teal();
		_H3API_ static RGB565 Thistle();
		_H3API_ static RGB565 Tomato();
		_H3API_ static RGB565 Turquoise();
		_H3API_ static RGB565 Violet();
		_H3API_ static RGB565 Wheat();
		_H3API_ static RGB565 White();
		_H3API_ static RGB565 WhiteSmoke();
		_H3API_ static RGB565 Yellow();
		_H3API_ static RGB565 YellowGreen();
#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB565);

	/** @brief approximate HSV pixel without floats for smarter color manipulation*/
	struct H3HSV
	{
	protected:
		UINT8 h;
		UINT8 s;
		UINT8 v;
	public:
		_H3API_ H3HSV();
		_H3API_ H3HSV(H3HSV& other);
		_H3API_ H3HSV(const H3RGB888& rgb);
		// * based on https://stackoverflow.com/a/14733008
		_H3API_ H3HSV& ConvertFromRgb888(const H3RGB888& rgb);
		_H3API_ H3RGB888 ConvertToRgb888() const;
		_H3API_ VOID AddSaturation(UINT8 saturation);
		_H3API_ VOID RemoveSaturation(UINT8 saturation);
		_H3API_ VOID SetHue(UINT8 hue);
		_H3API_ VOID AddValue(UINT8 value);
		_H3API_ VOID RemoveValue(UINT8 value);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
