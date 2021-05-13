//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Pixels.hpp"

namespace h3
{
	_H3API_ VOID H3RGB888::Darken20()
	{
		r = ((r & 0xFE) >> 1) | (r & 0x80);
		g = ((g & 0xFE) >> 1) | (g & 0x80);
		b = ((b & 0xFE) >> 1) | (b & 0x80);
	}
	_H3API_ VOID H3RGB888::Darken50()
	{
		r = ((r & 0xFE) >> 1);
		g = ((g & 0xFE) >> 1);
		b = ((b & 0xFE) >> 1);
	}
	_H3API_ VOID H3RGB888::GrayScale()
	{
		const int c = std::max(r, std::max(g, b));
		int dr = c - r;
		int dg = c - g;
		int db = c - b;

		dr = (dr << 2) / 5;
		dg = (dg << 2) / 5;
		db = (db << 2) / 5;

		r += dr;
		g += dg;
		b += db;
	}
	_H3API_ VOID H3RGB888::Darken(const UINT8 amount)
	{
		H3HSV hsv(*this);
		hsv.RemoveValue(amount);
		*this = hsv.ConvertToRgb888();
	}
	_H3API_ VOID H3RGB888::Lighten(const UINT8 amount)
	{
		H3HSV hsv(*this);
		hsv.AddValue(amount);
		*this = hsv.ConvertToRgb888();
	}
	_H3API_ VOID H3RGB888::AlphaDraw(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha)
	{
		// no weight
		if (alpha == 0)
			return;
		// full weight
		if (alpha == 255)
		{
			r = red;
			g = green;
			b = blue;
			return;
		}
		// how much weight does the existing color has
		const int dest_weight = 255 - alpha;

		const int weighted_r = alpha * red + dest_weight * r;
		r = weighted_r / 255;

		const int weighted_g = alpha * green + dest_weight * g;
		g = weighted_g / 255;

		const int weighted_b = alpha * blue + dest_weight * b;
		b = weighted_b / 255;
	}
	_H3API_ FLOAT H3RGB888::GetHueAsNormalizedFloat(UINT8 red, UINT8 green, UINT8 blue)
	{
		int c_min = std::min(std::min(red, green), blue);
		int c_max = std::max(std::max(red, green), blue);
		if (c_min == c_max)
			return 0.0f;
		FLOAT hue;
		if (c_max == red)
			hue = FLOAT(green - blue) / FLOAT(c_max - c_min);
		else if (c_max == green)
			hue = 2.0f + FLOAT(blue - red) / FLOAT(c_max - c_min);
		else
			hue = 4.0f + FLOAT(red - green) / FLOAT(c_max - c_min);

		hue /= 6.0f;

		if (hue < 0.0f)
			hue += 1.0f;

		return hue;
	}
	_H3API_ DWORD H3RGB888::Pack(UINT8 red, UINT8 green, UINT8 blue)
	{
		return 0xFF000000 + blue + (green << 8) + (red << 16);
	}
	_H3API_ H3RGB888::H3RGB888()
	{
	}
	_H3API_ H3RGB888::H3RGB888(DWORD color) :
		r((color >> 16) & 0xFF),
		g((color >> 8) & 0xFF),
		b(color & 0xFF)
	{
	}
	_H3API_ H3RGB888::H3RGB888(UINT8 r, UINT8 g, UINT8 b) :
		r(r),
		g(g),
		b(b)
	{
	}
	_H3API_ H3RGB888::H3RGB888(const H3RGB565& rgb) :
		r(rgb.GetRed8()),
		g(rgb.GetGreen8()),
		b(rgb.GetBlue8())
	{
	}
	_H3API_ H3RGB888::H3RGB888(const H3ARGB888& rgb) :
		r(rgb.r),
		g(rgb.g),
		b(rgb.b)
	{
	}
	_H3API_ VOID H3RGB888::operator=(const H3RGB565& col)
	{
		r = col.GetRed8();
		g = col.GetGreen8();
		b = col.GetBlue8();
	}
	_H3API_ VOID H3RGB888::operator=(const H3RGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
	}
	_H3API_ VOID H3RGB888::operator=(const H3ARGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
	}
	_H3API_ VOID H3RGB888::operator=(const UINT16 col)
	{
		operator=(H3RGB565(col));
	}
	_H3API_ VOID H3RGB888::operator=(const UINT32 col)
	{
		operator=(H3ARGB888(col));
	}
	_H3API_ BOOL H3RGB888::operator==(const H3RGB888& col)
	{
		return b == col.b && g == col.b && r == col.r;
	}
	_H3API_ UINT H3ARGB888::Value() const
	{
		return PtrAt(this);
	}
	_H3API_ H3RGB888 H3RGB888::Regular()
	{
		return H3RGB888(248, 240, 216);
	}
	_H3API_ H3RGB888 H3RGB888::Highlight()
	{
		return H3RGB888(232, 212, 120);
	}
	_H3API_ H3RGB888 H3RGB888::H3Red()
	{
		return H3RGB888(248, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Cyan()
	{
		return H3RGB888(0, 252, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Green()
	{
		return H3RGB888(0, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Blue()
	{
		return H3RGB888(0, 0, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Yellow()
	{
		return H3RGB888(248, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Orange()
	{
		return H3RGB888(248, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::H3Purple()
	{
		return H3RGB888(248, 0, 248);
	}
	_H3API_ H3RGB888 H3RGB888::H3Pink()
	{
		return H3RGB888(192, 120, 136);
	}
	_H3API_ H3RGB888 H3RGB888::AliceBlue()
	{
		return H3RGB888(240, 248, 255);
	}
	_H3API_ H3RGB888 H3RGB888::AntiqueWhite()
	{
		return H3RGB888(250, 235, 215);
	}
	_H3API_ H3RGB888 H3RGB888::Aqua()
	{
		return H3RGB888(0, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Aquamarine()
	{
		return H3RGB888(127, 255, 212);
	}
	_H3API_ H3RGB888 H3RGB888::Azure()
	{
		return H3RGB888(240, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Beige()
	{
		return H3RGB888(245, 245, 220);
	}
	_H3API_ H3RGB888 H3RGB888::Bisque()
	{
		return H3RGB888(255, 228, 196);
	}
	_H3API_ H3RGB888 H3RGB888::Black()
	{
		return H3RGB888(0, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::BlanchedAlmond()
	{
		return H3RGB888(255, 235, 205);
	}
	_H3API_ H3RGB888 H3RGB888::Blue()
	{
		return H3RGB888(0, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::BlueViolet()
	{
		return H3RGB888(138, 43, 226);
	}
	_H3API_ H3RGB888 H3RGB888::Brown()
	{
		return H3RGB888(165, 42, 42);
	}
	_H3API_ H3RGB888 H3RGB888::BurlyWood()
	{
		return H3RGB888(222, 184, 135);
	}
	_H3API_ H3RGB888 H3RGB888::CadetBlue()
	{
		return H3RGB888(95, 158, 160);
	}
	_H3API_ H3RGB888 H3RGB888::Chartreuse()
	{
		return H3RGB888(127, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::Chocolate()
	{
		return H3RGB888(210, 105, 30);
	}
	_H3API_ H3RGB888 H3RGB888::Coral()
	{
		return H3RGB888(255, 127, 80);
	}
	_H3API_ H3RGB888 H3RGB888::CornflowerBlue()
	{
		return H3RGB888(100, 149, 237);
	}
	_H3API_ H3RGB888 H3RGB888::Cornsilk()
	{
		return H3RGB888(255, 248, 220);
	}
	_H3API_ H3RGB888 H3RGB888::Crimson()
	{
		return H3RGB888(220, 20, 60);
	}
	_H3API_ H3RGB888 H3RGB888::Cyan()
	{
		return H3RGB888(0, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::DarkBlue()
	{
		return H3RGB888(0, 0, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkCyan()
	{
		return H3RGB888(0, 139, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGoldenRod()
	{
		return H3RGB888(184, 134, 11);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGray()
	{
		return H3RGB888(169, 169, 169);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGrey()
	{
		return H3RGB888(169, 169, 169);
	}
	_H3API_ H3RGB888 H3RGB888::DarkGreen()
	{
		return H3RGB888(0, 100, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkKhaki()
	{
		return H3RGB888(189, 183, 107);
	}
	_H3API_ H3RGB888 H3RGB888::DarkMagenta()
	{
		return H3RGB888(139, 0, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkOliveGreen()
	{
		return H3RGB888(85, 107, 47);
	}
	_H3API_ H3RGB888 H3RGB888::Darkorange()
	{
		return H3RGB888(255, 140, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkOrchid()
	{
		return H3RGB888(153, 50, 204);
	}
	_H3API_ H3RGB888 H3RGB888::DarkRed()
	{
		return H3RGB888(139, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSalmon()
	{
		return H3RGB888(233, 150, 122);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSeaGreen()
	{
		return H3RGB888(143, 188, 143);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateBlue()
	{
		return H3RGB888(72, 61, 139);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateGray()
	{
		return H3RGB888(47, 79, 79);
	}
	_H3API_ H3RGB888 H3RGB888::DarkSlateGrey()
	{
		return H3RGB888(47, 79, 79);
	}
	_H3API_ H3RGB888 H3RGB888::DarkTurquoise()
	{
		return H3RGB888(0, 206, 209);
	}
	_H3API_ H3RGB888 H3RGB888::DarkViolet()
	{
		return H3RGB888(148, 0, 211);
	}
	_H3API_ H3RGB888 H3RGB888::DeepPink()
	{
		return H3RGB888(255, 20, 147);
	}
	_H3API_ H3RGB888 H3RGB888::DeepSkyBlue()
	{
		return H3RGB888(0, 191, 255);
	}
	_H3API_ H3RGB888 H3RGB888::DimGray()
	{
		return H3RGB888(105, 105, 105);
	}
	_H3API_ H3RGB888 H3RGB888::DimGrey()
	{
		return H3RGB888(105, 105, 105);
	}
	_H3API_ H3RGB888 H3RGB888::DodgerBlue()
	{
		return H3RGB888(30, 144, 255);
	}
	_H3API_ H3RGB888 H3RGB888::FireBrick()
	{
		return H3RGB888(178, 34, 34);
	}
	_H3API_ H3RGB888 H3RGB888::FloralWhite()
	{
		return H3RGB888(255, 250, 240);
	}
	_H3API_ H3RGB888 H3RGB888::ForestGreen()
	{
		return H3RGB888(34, 139, 34);
	}
	_H3API_ H3RGB888 H3RGB888::Fuchsia()
	{
		return H3RGB888(255, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Gainsboro()
	{
		return H3RGB888(220, 220, 220);
	}
	_H3API_ H3RGB888 H3RGB888::GhostWhite()
	{
		return H3RGB888(248, 248, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Gold()
	{
		return H3RGB888(255, 215, 0);
	}
	_H3API_ H3RGB888 H3RGB888::GoldenRod()
	{
		return H3RGB888(218, 165, 32);
	}
	_H3API_ H3RGB888 H3RGB888::Gray()
	{
		return H3RGB888(128, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Grey()
	{
		return H3RGB888(128, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Green()
	{
		return H3RGB888(0, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::GreenYellow()
	{
		return H3RGB888(173, 255, 47);
	}
	_H3API_ H3RGB888 H3RGB888::HoneyDew()
	{
		return H3RGB888(240, 255, 240);
	}
	_H3API_ H3RGB888 H3RGB888::HotPink()
	{
		return H3RGB888(255, 105, 180);
	}
	_H3API_ H3RGB888 H3RGB888::IndianRed()
	{
		return H3RGB888(205, 92, 92);
	}
	_H3API_ H3RGB888 H3RGB888::Indigo()
	{
		return H3RGB888(75, 0, 130);
	}
	_H3API_ H3RGB888 H3RGB888::Ivory()
	{
		return H3RGB888(255, 255, 240);
	}
	_H3API_ H3RGB888 H3RGB888::Khaki()
	{
		return H3RGB888(240, 230, 140);
	}
	_H3API_ H3RGB888 H3RGB888::Lavender()
	{
		return H3RGB888(230, 230, 250);
	}
	_H3API_ H3RGB888 H3RGB888::LavenderBlush()
	{
		return H3RGB888(255, 240, 245);
	}
	_H3API_ H3RGB888 H3RGB888::LawnGreen()
	{
		return H3RGB888(124, 252, 0);
	}
	_H3API_ H3RGB888 H3RGB888::LemonChiffon()
	{
		return H3RGB888(255, 250, 205);
	}
	_H3API_ H3RGB888 H3RGB888::LightBlue()
	{
		return H3RGB888(173, 216, 230);
	}
	_H3API_ H3RGB888 H3RGB888::LightCoral()
	{
		return H3RGB888(240, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::LightCyan()
	{
		return H3RGB888(224, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::LightGoldenRodYellow()
	{
		return H3RGB888(250, 250, 210);
	}
	_H3API_ H3RGB888 H3RGB888::LightGray()
	{
		return H3RGB888(211, 211, 211);
	}
	_H3API_ H3RGB888 H3RGB888::LightGrey()
	{
		return H3RGB888(211, 211, 211);
	}
	_H3API_ H3RGB888 H3RGB888::LightGreen()
	{
		return H3RGB888(144, 238, 144);
	}
	_H3API_ H3RGB888 H3RGB888::LightPink()
	{
		return H3RGB888(255, 182, 193);
	}
	_H3API_ H3RGB888 H3RGB888::LightSalmon()
	{
		return H3RGB888(255, 160, 122);
	}
	_H3API_ H3RGB888 H3RGB888::LightSeaGreen()
	{
		return H3RGB888(32, 178, 170);
	}
	_H3API_ H3RGB888 H3RGB888::LightSkyBlue()
	{
		return H3RGB888(135, 206, 250);
	}
	_H3API_ H3RGB888 H3RGB888::LightSlateGray()
	{
		return H3RGB888(119, 136, 153);
	}
	_H3API_ H3RGB888 H3RGB888::LightSlateGrey()
	{
		return H3RGB888(119, 136, 153);
	}
	_H3API_ H3RGB888 H3RGB888::LightSteelBlue()
	{
		return H3RGB888(176, 196, 222);
	}
	_H3API_ H3RGB888 H3RGB888::LightYellow()
	{
		return H3RGB888(255, 255, 224);
	}
	_H3API_ H3RGB888 H3RGB888::Lime()
	{
		return H3RGB888(0, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::LimeGreen()
	{
		return H3RGB888(50, 205, 50);
	}
	_H3API_ H3RGB888 H3RGB888::Linen()
	{
		return H3RGB888(250, 240, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Magenta()
	{
		return H3RGB888(255, 0, 255);
	}
	_H3API_ H3RGB888 H3RGB888::Maroon()
	{
		return H3RGB888(128, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::MediumAquaMarine()
	{
		return H3RGB888(102, 205, 170);
	}
	_H3API_ H3RGB888 H3RGB888::MediumBlue()
	{
		return H3RGB888(0, 0, 205);
	}
	_H3API_ H3RGB888 H3RGB888::MediumOrchid()
	{
		return H3RGB888(186, 85, 211);
	}
	_H3API_ H3RGB888 H3RGB888::MediumPurple()
	{
		return H3RGB888(147, 112, 216);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSeaGreen()
	{
		return H3RGB888(60, 179, 113);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSlateBlue()
	{
		return H3RGB888(123, 104, 238);
	}
	_H3API_ H3RGB888 H3RGB888::MediumSpringGreen()
	{
		return H3RGB888(0, 250, 154);
	}
	_H3API_ H3RGB888 H3RGB888::MediumTurquoise()
	{
		return H3RGB888(72, 209, 204);
	}
	_H3API_ H3RGB888 H3RGB888::MediumVioletRed()
	{
		return H3RGB888(199, 21, 133);
	}
	_H3API_ H3RGB888 H3RGB888::MidnightBlue()
	{
		return H3RGB888(25, 25, 112);
	}
	_H3API_ H3RGB888 H3RGB888::MintCream()
	{
		return H3RGB888(245, 255, 250);
	}
	_H3API_ H3RGB888 H3RGB888::MistyRose()
	{
		return H3RGB888(255, 228, 225);
	}
	_H3API_ H3RGB888 H3RGB888::Moccasin()
	{
		return H3RGB888(255, 228, 181);
	}
	_H3API_ H3RGB888 H3RGB888::NavajoWhite()
	{
		return H3RGB888(255, 222, 173);
	}
	_H3API_ H3RGB888 H3RGB888::Navy()
	{
		return H3RGB888(0, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::OldLace()
	{
		return H3RGB888(253, 245, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Olive()
	{
		return H3RGB888(128, 128, 0);
	}
	_H3API_ H3RGB888 H3RGB888::OliveDrab()
	{
		return H3RGB888(107, 142, 35);
	}
	_H3API_ H3RGB888 H3RGB888::Orange()
	{
		return H3RGB888(255, 165, 0);
	}
	_H3API_ H3RGB888 H3RGB888::OrangeRed()
	{
		return H3RGB888(255, 69, 0);
	}
	_H3API_ H3RGB888 H3RGB888::Orchid()
	{
		return H3RGB888(218, 112, 214);
	}
	_H3API_ H3RGB888 H3RGB888::PaleGoldenRod()
	{
		return H3RGB888(238, 232, 170);
	}
	_H3API_ H3RGB888 H3RGB888::PaleGreen()
	{
		return H3RGB888(152, 251, 152);
	}
	_H3API_ H3RGB888 H3RGB888::PaleTurquoise()
	{
		return H3RGB888(175, 238, 238);
	}
	_H3API_ H3RGB888 H3RGB888::PaleVioletRed()
	{
		return H3RGB888(216, 112, 147);
	}
	_H3API_ H3RGB888 H3RGB888::PapayaWhip()
	{
		return H3RGB888(255, 239, 213);
	}
	_H3API_ H3RGB888 H3RGB888::PeachPuff()
	{
		return H3RGB888(255, 218, 185);
	}
	_H3API_ H3RGB888 H3RGB888::Peru()
	{
		return H3RGB888(205, 133, 63);
	}
	_H3API_ H3RGB888 H3RGB888::Pink()
	{
		return H3RGB888(255, 192, 203);
	}
	_H3API_ H3RGB888 H3RGB888::Plum()
	{
		return H3RGB888(221, 160, 221);
	}
	_H3API_ H3RGB888 H3RGB888::PowderBlue()
	{
		return H3RGB888(176, 224, 230);
	}
	_H3API_ H3RGB888 H3RGB888::Purple()
	{
		return H3RGB888(128, 0, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Red()
	{
		return H3RGB888(255, 0, 0);
	}
	_H3API_ H3RGB888 H3RGB888::RosyBrown()
	{
		return H3RGB888(188, 143, 143);
	}
	_H3API_ H3RGB888 H3RGB888::RoyalBlue()
	{
		return H3RGB888(65, 105, 225);
	}
	_H3API_ H3RGB888 H3RGB888::SaddleBrown()
	{
		return H3RGB888(139, 69, 19);
	}
	_H3API_ H3RGB888 H3RGB888::Salmon()
	{
		return H3RGB888(250, 128, 114);
	}
	_H3API_ H3RGB888 H3RGB888::SandyBrown()
	{
		return H3RGB888(244, 164, 96);
	}
	_H3API_ H3RGB888 H3RGB888::SeaGreen()
	{
		return H3RGB888(46, 139, 87);
	}
	_H3API_ H3RGB888 H3RGB888::SeaShell()
	{
		return H3RGB888(255, 245, 238);
	}
	_H3API_ H3RGB888 H3RGB888::Sienna()
	{
		return H3RGB888(160, 82, 45);
	}
	_H3API_ H3RGB888 H3RGB888::Silver()
	{
		return H3RGB888(192, 192, 192);
	}
	_H3API_ H3RGB888 H3RGB888::SkyBlue()
	{
		return H3RGB888(135, 206, 235);
	}
	_H3API_ H3RGB888 H3RGB888::SlateBlue()
	{
		return H3RGB888(106, 90, 205);
	}
	_H3API_ H3RGB888 H3RGB888::SlateGray()
	{
		return H3RGB888(112, 128, 144);
	}
	_H3API_ H3RGB888 H3RGB888::SlateGrey()
	{
		return H3RGB888(112, 128, 144);
	}
	_H3API_ H3RGB888 H3RGB888::Snow()
	{
		return H3RGB888(255, 250, 250);
	}
	_H3API_ H3RGB888 H3RGB888::SpringGreen()
	{
		return H3RGB888(0, 255, 127);
	}
	_H3API_ H3RGB888 H3RGB888::SteelBlue()
	{
		return H3RGB888(70, 130, 180);
	}
	_H3API_ H3RGB888 H3RGB888::Tan()
	{
		return H3RGB888(210, 180, 140);
	}
	_H3API_ H3RGB888 H3RGB888::Teal()
	{
		return H3RGB888(0, 128, 128);
	}
	_H3API_ H3RGB888 H3RGB888::Thistle()
	{
		return H3RGB888(216, 191, 216);
	}
	_H3API_ H3RGB888 H3RGB888::Tomato()
	{
		return H3RGB888(255, 99, 71);
	}
	_H3API_ H3RGB888 H3RGB888::Turquoise()
	{
		return H3RGB888(64, 224, 208);
	}
	_H3API_ H3RGB888 H3RGB888::Violet()
	{
		return H3RGB888(238, 130, 238);
	}
	_H3API_ H3RGB888 H3RGB888::Wheat()
	{
		return H3RGB888(245, 222, 179);
	}
	_H3API_ H3RGB888 H3RGB888::White()
	{
		return H3RGB888(255, 255, 255);
	}
	_H3API_ H3RGB888 H3RGB888::WhiteSmoke()
	{
		return H3RGB888(245, 245, 245);
	}
	_H3API_ H3RGB888 H3RGB888::Yellow()
	{
		return H3RGB888(255, 255, 0);
	}
	_H3API_ H3RGB888 H3RGB888::YellowGreen()
	{
		return H3RGB888(154, 205, 50);
	}

	_H3API_ H3ARGB888 H3ARGB888::Regular()
	{
		return H3ARGB888(248, 240, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::Highlight()
	{
		return H3ARGB888(232, 212, 120);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Red()
	{
		return H3ARGB888(248, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Cyan()
	{
		return H3ARGB888(0, 252, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Green()
	{
		return H3ARGB888(0, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Blue()
	{
		return H3ARGB888(0, 0, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Yellow()
	{
		return H3ARGB888(248, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Orange()
	{
		return H3ARGB888(248, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Purple()
	{
		return H3ARGB888(248, 0, 248);
	}
	_H3API_ H3ARGB888 H3ARGB888::H3Pink()
	{
		return H3ARGB888(192, 120, 136);
	}
	_H3API_ H3ARGB888 H3ARGB888::AliceBlue()
	{
		return H3ARGB888(240, 248, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::AntiqueWhite()
	{
		return H3ARGB888(250, 235, 215);
	}
	_H3API_ H3ARGB888 H3ARGB888::Aqua()
	{
		return H3ARGB888(0, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Aquamarine()
	{
		return H3ARGB888(127, 255, 212);
	}
	_H3API_ H3ARGB888 H3ARGB888::Azure()
	{
		return H3ARGB888(240, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Beige()
	{
		return H3ARGB888(245, 245, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::Bisque()
	{
		return H3ARGB888(255, 228, 196);
	}
	_H3API_ H3ARGB888 H3ARGB888::Black()
	{
		return H3ARGB888(0, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::BlanchedAlmond()
	{
		return H3ARGB888(255, 235, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::Blue()
	{
		return H3ARGB888(0, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::BlueViolet()
	{
		return H3ARGB888(138, 43, 226);
	}
	_H3API_ H3ARGB888 H3ARGB888::Brown()
	{
		return H3ARGB888(165, 42, 42);
	}
	_H3API_ H3ARGB888 H3ARGB888::BurlyWood()
	{
		return H3ARGB888(222, 184, 135);
	}
	_H3API_ H3ARGB888 H3ARGB888::CadetBlue()
	{
		return H3ARGB888(95, 158, 160);
	}
	_H3API_ H3ARGB888 H3ARGB888::Chartreuse()
	{
		return H3ARGB888(127, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::Chocolate()
	{
		return H3ARGB888(210, 105, 30);
	}
	_H3API_ H3ARGB888 H3ARGB888::Coral()
	{
		return H3ARGB888(255, 127, 80);
	}
	_H3API_ H3ARGB888 H3ARGB888::CornflowerBlue()
	{
		return H3ARGB888(100, 149, 237);
	}
	_H3API_ H3ARGB888 H3ARGB888::Cornsilk()
	{
		return H3ARGB888(255, 248, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::Crimson()
	{
		return H3ARGB888(220, 20, 60);
	}
	_H3API_ H3ARGB888 H3ARGB888::Cyan()
	{
		return H3ARGB888(0, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkBlue()
	{
		return H3ARGB888(0, 0, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkCyan()
	{
		return H3ARGB888(0, 139, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGoldenRod()
	{
		return H3ARGB888(184, 134, 11);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGray()
	{
		return H3ARGB888(169, 169, 169);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGrey()
	{
		return H3ARGB888(169, 169, 169);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkGreen()
	{
		return H3ARGB888(0, 100, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkKhaki()
	{
		return H3ARGB888(189, 183, 107);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkMagenta()
	{
		return H3ARGB888(139, 0, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkOliveGreen()
	{
		return H3ARGB888(85, 107, 47);
	}
	_H3API_ H3ARGB888 H3ARGB888::Darkorange()
	{
		return H3ARGB888(255, 140, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkOrchid()
	{
		return H3ARGB888(153, 50, 204);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkRed()
	{
		return H3ARGB888(139, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSalmon()
	{
		return H3ARGB888(233, 150, 122);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSeaGreen()
	{
		return H3ARGB888(143, 188, 143);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateBlue()
	{
		return H3ARGB888(72, 61, 139);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateGray()
	{
		return H3ARGB888(47, 79, 79);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkSlateGrey()
	{
		return H3ARGB888(47, 79, 79);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkTurquoise()
	{
		return H3ARGB888(0, 206, 209);
	}
	_H3API_ H3ARGB888 H3ARGB888::DarkViolet()
	{
		return H3ARGB888(148, 0, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::DeepPink()
	{
		return H3ARGB888(255, 20, 147);
	}
	_H3API_ H3ARGB888 H3ARGB888::DeepSkyBlue()
	{
		return H3ARGB888(0, 191, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::DimGray()
	{
		return H3ARGB888(105, 105, 105);
	}
	_H3API_ H3ARGB888 H3ARGB888::DimGrey()
	{
		return H3ARGB888(105, 105, 105);
	}
	_H3API_ H3ARGB888 H3ARGB888::DodgerBlue()
	{
		return H3ARGB888(30, 144, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::FireBrick()
	{
		return H3ARGB888(178, 34, 34);
	}
	_H3API_ H3ARGB888 H3ARGB888::FloralWhite()
	{
		return H3ARGB888(255, 250, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::ForestGreen()
	{
		return H3ARGB888(34, 139, 34);
	}
	_H3API_ H3ARGB888 H3ARGB888::Fuchsia()
	{
		return H3ARGB888(255, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gainsboro()
	{
		return H3ARGB888(220, 220, 220);
	}
	_H3API_ H3ARGB888 H3ARGB888::GhostWhite()
	{
		return H3ARGB888(248, 248, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gold()
	{
		return H3ARGB888(255, 215, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::GoldenRod()
	{
		return H3ARGB888(218, 165, 32);
	}
	_H3API_ H3ARGB888 H3ARGB888::Gray()
	{
		return H3ARGB888(128, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Grey()
	{
		return H3ARGB888(128, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Green()
	{
		return H3ARGB888(0, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::GreenYellow()
	{
		return H3ARGB888(173, 255, 47);
	}
	_H3API_ H3ARGB888 H3ARGB888::HoneyDew()
	{
		return H3ARGB888(240, 255, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::HotPink()
	{
		return H3ARGB888(255, 105, 180);
	}
	_H3API_ H3ARGB888 H3ARGB888::IndianRed()
	{
		return H3ARGB888(205, 92, 92);
	}
	_H3API_ H3ARGB888 H3ARGB888::Indigo()
	{
		return H3ARGB888(75, 0, 130);
	}
	_H3API_ H3ARGB888 H3ARGB888::Ivory()
	{
		return H3ARGB888(255, 255, 240);
	}
	_H3API_ H3ARGB888 H3ARGB888::Khaki()
	{
		return H3ARGB888(240, 230, 140);
	}
	_H3API_ H3ARGB888 H3ARGB888::Lavender()
	{
		return H3ARGB888(230, 230, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::LavenderBlush()
	{
		return H3ARGB888(255, 240, 245);
	}
	_H3API_ H3ARGB888 H3ARGB888::LawnGreen()
	{
		return H3ARGB888(124, 252, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::LemonChiffon()
	{
		return H3ARGB888(255, 250, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightBlue()
	{
		return H3ARGB888(173, 216, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightCoral()
	{
		return H3ARGB888(240, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightCyan()
	{
		return H3ARGB888(224, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGoldenRodYellow()
	{
		return H3ARGB888(250, 250, 210);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGray()
	{
		return H3ARGB888(211, 211, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGrey()
	{
		return H3ARGB888(211, 211, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightGreen()
	{
		return H3ARGB888(144, 238, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightPink()
	{
		return H3ARGB888(255, 182, 193);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSalmon()
	{
		return H3ARGB888(255, 160, 122);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSeaGreen()
	{
		return H3ARGB888(32, 178, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSkyBlue()
	{
		return H3ARGB888(135, 206, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSlateGray()
	{
		return H3ARGB888(119, 136, 153);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSlateGrey()
	{
		return H3ARGB888(119, 136, 153);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightSteelBlue()
	{
		return H3ARGB888(176, 196, 222);
	}
	_H3API_ H3ARGB888 H3ARGB888::LightYellow()
	{
		return H3ARGB888(255, 255, 224);
	}
	_H3API_ H3ARGB888 H3ARGB888::Lime()
	{
		return H3ARGB888(0, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::LimeGreen()
	{
		return H3ARGB888(50, 205, 50);
	}
	_H3API_ H3ARGB888 H3ARGB888::Linen()
	{
		return H3ARGB888(250, 240, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Magenta()
	{
		return H3ARGB888(255, 0, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::Maroon()
	{
		return H3ARGB888(128, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumAquaMarine()
	{
		return H3ARGB888(102, 205, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumBlue()
	{
		return H3ARGB888(0, 0, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumOrchid()
	{
		return H3ARGB888(186, 85, 211);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumPurple()
	{
		return H3ARGB888(147, 112, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSeaGreen()
	{
		return H3ARGB888(60, 179, 113);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSlateBlue()
	{
		return H3ARGB888(123, 104, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumSpringGreen()
	{
		return H3ARGB888(0, 250, 154);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumTurquoise()
	{
		return H3ARGB888(72, 209, 204);
	}
	_H3API_ H3ARGB888 H3ARGB888::MediumVioletRed()
	{
		return H3ARGB888(199, 21, 133);
	}
	_H3API_ H3ARGB888 H3ARGB888::MidnightBlue()
	{
		return H3ARGB888(25, 25, 112);
	}
	_H3API_ H3ARGB888 H3ARGB888::MintCream()
	{
		return H3ARGB888(245, 255, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::MistyRose()
	{
		return H3ARGB888(255, 228, 225);
	}
	_H3API_ H3ARGB888 H3ARGB888::Moccasin()
	{
		return H3ARGB888(255, 228, 181);
	}
	_H3API_ H3ARGB888 H3ARGB888::NavajoWhite()
	{
		return H3ARGB888(255, 222, 173);
	}
	_H3API_ H3ARGB888 H3ARGB888::Navy()
	{
		return H3ARGB888(0, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::OldLace()
	{
		return H3ARGB888(253, 245, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Olive()
	{
		return H3ARGB888(128, 128, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::OliveDrab()
	{
		return H3ARGB888(107, 142, 35);
	}
	_H3API_ H3ARGB888 H3ARGB888::Orange()
	{
		return H3ARGB888(255, 165, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::OrangeRed()
	{
		return H3ARGB888(255, 69, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::Orchid()
	{
		return H3ARGB888(218, 112, 214);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleGoldenRod()
	{
		return H3ARGB888(238, 232, 170);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleGreen()
	{
		return H3ARGB888(152, 251, 152);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleTurquoise()
	{
		return H3ARGB888(175, 238, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::PaleVioletRed()
	{
		return H3ARGB888(216, 112, 147);
	}
	_H3API_ H3ARGB888 H3ARGB888::PapayaWhip()
	{
		return H3ARGB888(255, 239, 213);
	}
	_H3API_ H3ARGB888 H3ARGB888::PeachPuff()
	{
		return H3ARGB888(255, 218, 185);
	}
	_H3API_ H3ARGB888 H3ARGB888::Peru()
	{
		return H3ARGB888(205, 133, 63);
	}
	_H3API_ H3ARGB888 H3ARGB888::Pink()
	{
		return H3ARGB888(255, 192, 203);
	}
	_H3API_ H3ARGB888 H3ARGB888::Plum()
	{
		return H3ARGB888(221, 160, 221);
	}
	_H3API_ H3ARGB888 H3ARGB888::PowderBlue()
	{
		return H3ARGB888(176, 224, 230);
	}
	_H3API_ H3ARGB888 H3ARGB888::Purple()
	{
		return H3ARGB888(128, 0, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Red()
	{
		return H3ARGB888(255, 0, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::RosyBrown()
	{
		return H3ARGB888(188, 143, 143);
	}
	_H3API_ H3ARGB888 H3ARGB888::RoyalBlue()
	{
		return H3ARGB888(65, 105, 225);
	}
	_H3API_ H3ARGB888 H3ARGB888::SaddleBrown()
	{
		return H3ARGB888(139, 69, 19);
	}
	_H3API_ H3ARGB888 H3ARGB888::Salmon()
	{
		return H3ARGB888(250, 128, 114);
	}
	_H3API_ H3ARGB888 H3ARGB888::SandyBrown()
	{
		return H3ARGB888(244, 164, 96);
	}
	_H3API_ H3ARGB888 H3ARGB888::SeaGreen()
	{
		return H3ARGB888(46, 139, 87);
	}
	_H3API_ H3ARGB888 H3ARGB888::SeaShell()
	{
		return H3ARGB888(255, 245, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::Sienna()
	{
		return H3ARGB888(160, 82, 45);
	}
	_H3API_ H3ARGB888 H3ARGB888::Silver()
	{
		return H3ARGB888(192, 192, 192);
	}
	_H3API_ H3ARGB888 H3ARGB888::SkyBlue()
	{
		return H3ARGB888(135, 206, 235);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateBlue()
	{
		return H3ARGB888(106, 90, 205);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateGray()
	{
		return H3ARGB888(112, 128, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::SlateGrey()
	{
		return H3ARGB888(112, 128, 144);
	}
	_H3API_ H3ARGB888 H3ARGB888::Snow()
	{
		return H3ARGB888(255, 250, 250);
	}
	_H3API_ H3ARGB888 H3ARGB888::SpringGreen()
	{
		return H3ARGB888(0, 255, 127);
	}
	_H3API_ H3ARGB888 H3ARGB888::SteelBlue()
	{
		return H3ARGB888(70, 130, 180);
	}
	_H3API_ H3ARGB888 H3ARGB888::Tan()
	{
		return H3ARGB888(210, 180, 140);
	}
	_H3API_ H3ARGB888 H3ARGB888::Teal()
	{
		return H3ARGB888(0, 128, 128);
	}
	_H3API_ H3ARGB888 H3ARGB888::Thistle()
	{
		return H3ARGB888(216, 191, 216);
	}
	_H3API_ H3ARGB888 H3ARGB888::Tomato()
	{
		return H3ARGB888(255, 99, 71);
	}
	_H3API_ H3ARGB888 H3ARGB888::Turquoise()
	{
		return H3ARGB888(64, 224, 208);
	}
	_H3API_ H3ARGB888 H3ARGB888::Violet()
	{
		return H3ARGB888(238, 130, 238);
	}
	_H3API_ H3ARGB888 H3ARGB888::Wheat()
	{
		return H3ARGB888(245, 222, 179);
	}
	_H3API_ H3ARGB888 H3ARGB888::White()
	{
		return H3ARGB888(255, 255, 255);
	}
	_H3API_ H3ARGB888 H3ARGB888::WhiteSmoke()
	{
		return H3ARGB888(245, 245, 245);
	}
	_H3API_ H3ARGB888 H3ARGB888::Yellow()
	{
		return H3ARGB888(255, 255, 0);
	}
	_H3API_ H3ARGB888 H3ARGB888::YellowGreen()
	{
		return H3ARGB888(154, 205, 50);
	}

	_H3API_ RGB565 H3RGB565::Regular()
	{
		return 0xFF9B;
	}
	_H3API_ RGB565 H3RGB565::Highlight()
	{
		return 0xEEAF;
	}
	_H3API_ RGB565 H3RGB565::H3Red()
	{
		return 0xF800;
	}
	_H3API_ RGB565 H3RGB565::H3Cyan()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::H3Green()
	{
		return 0x7E0;
	}
	_H3API_ RGB565 H3RGB565::H3Blue()
	{
		return 0x1F;
	}
	_H3API_ RGB565 H3RGB565::H3Yellow()
	{
		return 0xFFE0;
	}
	_H3API_ RGB565 H3RGB565::H3Orange()
	{
		return 0xFC00;
	}
	_H3API_ RGB565 H3RGB565::H3Purple()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::H3Pink()
	{
		return 0xC3D1;
	}
	_H3API_ RGB565 H3RGB565::AliceBlue()
	{
		return 0xF7DF;
	}
	_H3API_ RGB565 H3RGB565::AntiqueWhite()
	{
		return 0xFF5A;
	}
	_H3API_ RGB565 H3RGB565::Aqua()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::Aquamarine()
	{
		return 0x7FFA;
	}
	_H3API_ RGB565 H3RGB565::Azure()
	{
		return 0xF7FF;
	}
	_H3API_ RGB565 H3RGB565::Beige()
	{
		return 0xF7BB;
	}
	_H3API_ RGB565 H3RGB565::Bisque()
	{
		return 0xFF38;
	}
	_H3API_ RGB565 H3RGB565::Black()
	{
		return 0x0;
	}
	_H3API_ RGB565 H3RGB565::BlanchedAlmond()
	{
		return 0xFF59;
	}
	_H3API_ RGB565 H3RGB565::Blue()
	{
		return 0x1F;
	}
	_H3API_ RGB565 H3RGB565::BlueViolet()
	{
		return 0x895C;
	}
	_H3API_ RGB565 H3RGB565::Brown()
	{
		return 0xA145;
	}
	_H3API_ RGB565 H3RGB565::BurlyWood()
	{
		return 0xDDD0;
	}
	_H3API_ RGB565 H3RGB565::CadetBlue()
	{
		return 0x5CF4;
	}
	_H3API_ RGB565 H3RGB565::Chartreuse()
	{
		return 0x7FE0;
	}
	_H3API_ RGB565 H3RGB565::Chocolate()
	{
		return 0xD343;
	}
	_H3API_ RGB565 H3RGB565::Coral()
	{
		return 0xFBEA;
	}
	_H3API_ RGB565 H3RGB565::CornflowerBlue()
	{
		return 0x64BD;
	}
	_H3API_ RGB565 H3RGB565::Cornsilk()
	{
		return 0xFFDB;
	}
	_H3API_ RGB565 H3RGB565::Crimson()
	{
		return 0xD8A7;
	}
	_H3API_ RGB565 H3RGB565::Cyan()
	{
		return 0x7FF;
	}
	_H3API_ RGB565 H3RGB565::DarkBlue()
	{
		return 0x11;
	}
	_H3API_ RGB565 H3RGB565::DarkCyan()
	{
		return 0x451;
	}
	_H3API_ RGB565 H3RGB565::DarkGoldenRod()
	{
		return 0xBC21;
	}
	_H3API_ RGB565 H3RGB565::DarkGray()
	{
		return 0xAD55;
	}
	_H3API_ RGB565 H3RGB565::DarkGrey()
	{
		return 0xAD55;
	}
	_H3API_ RGB565 H3RGB565::DarkGreen()
	{
		return 0x320;
	}
	_H3API_ RGB565 H3RGB565::DarkKhaki()
	{
		return 0xBDAD;
	}
	_H3API_ RGB565 H3RGB565::DarkMagenta()
	{
		return 0x8811;
	}
	_H3API_ RGB565 H3RGB565::DarkOliveGreen()
	{
		return 0x5345;
	}
	_H3API_ RGB565 H3RGB565::Darkorange()
	{
		return 0xFC60;
	}
	_H3API_ RGB565 H3RGB565::DarkOrchid()
	{
		return 0x9999;
	}
	_H3API_ RGB565 H3RGB565::DarkRed()
	{
		return 0x8800;
	}
	_H3API_ RGB565 H3RGB565::DarkSalmon()
	{
		return 0xECAF;
	}
	_H3API_ RGB565 H3RGB565::DarkSeaGreen()
	{
		return 0x8DF1;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateBlue()
	{
		return 0x49F1;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateGray()
	{
		return 0x2A69;
	}
	_H3API_ RGB565 H3RGB565::DarkSlateGrey()
	{
		return 0x2A69;
	}
	_H3API_ RGB565 H3RGB565::DarkTurquoise()
	{
		return 0x67A;
	}
	_H3API_ RGB565 H3RGB565::DarkViolet()
	{
		return 0x901A;
	}
	_H3API_ RGB565 H3RGB565::DeepPink()
	{
		return 0xF8B2;
	}
	_H3API_ RGB565 H3RGB565::DeepSkyBlue()
	{
		return 0x5FF;
	}
	_H3API_ RGB565 H3RGB565::DimGray()
	{
		return 0x6B4D;
	}
	_H3API_ RGB565 H3RGB565::DimGrey()
	{
		return 0x6B4D;
	}
	_H3API_ RGB565 H3RGB565::DodgerBlue()
	{
		return 0x1C9F;
	}
	_H3API_ RGB565 H3RGB565::FireBrick()
	{
		return 0xB104;
	}
	_H3API_ RGB565 H3RGB565::FloralWhite()
	{
		return 0xFFDE;
	}
	_H3API_ RGB565 H3RGB565::ForestGreen()
	{
		return 0x2444;
	}
	_H3API_ RGB565 H3RGB565::Fuchsia()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::Gainsboro()
	{
		return 0xDEFB;
	}
	_H3API_ RGB565 H3RGB565::GhostWhite()
	{
		return 0xFFDF;
	}
	_H3API_ RGB565 H3RGB565::Gold()
	{
		return 0xFEA0;
	}
	_H3API_ RGB565 H3RGB565::GoldenRod()
	{
		return 0xDD24;
	}
	_H3API_ RGB565 H3RGB565::Gray()
	{
		return 0x8410;
	}
	_H3API_ RGB565 H3RGB565::Grey()
	{
		return 0x8410;
	}
	_H3API_ RGB565 H3RGB565::Green()
	{
		return 0x400;
	}
	_H3API_ RGB565 H3RGB565::GreenYellow()
	{
		return 0xAFE5;
	}
	_H3API_ RGB565 H3RGB565::HoneyDew()
	{
		return 0xF7FE;
	}
	_H3API_ RGB565 H3RGB565::HotPink()
	{
		return 0xFB56;
	}
	_H3API_ RGB565 H3RGB565::IndianRed()
	{
		return 0xCAEB;
	}
	_H3API_ RGB565 H3RGB565::Indigo()
	{
		return 0x4810;
	}
	_H3API_ RGB565 H3RGB565::Ivory()
	{
		return 0xFFFE;
	}
	_H3API_ RGB565 H3RGB565::Khaki()
	{
		return 0xF731;
	}
	_H3API_ RGB565 H3RGB565::Lavender()
	{
		return 0xE73F;
	}
	_H3API_ RGB565 H3RGB565::LavenderBlush()
	{
		return 0xFF9E;
	}
	_H3API_ RGB565 H3RGB565::LawnGreen()
	{
		return 0x7FE0;
	}
	_H3API_ RGB565 H3RGB565::LemonChiffon()
	{
		return 0xFFD9;
	}
	_H3API_ RGB565 H3RGB565::LightBlue()
	{
		return 0xAEDC;
	}
	_H3API_ RGB565 H3RGB565::LightCoral()
	{
		return 0xF410;
	}
	_H3API_ RGB565 H3RGB565::LightCyan()
	{
		return 0xE7FF;
	}
	_H3API_ RGB565 H3RGB565::LightGoldenRodYellow()
	{
		return 0xFFDA;
	}
	_H3API_ RGB565 H3RGB565::LightGray()
	{
		return 0xD69A;
	}
	_H3API_ RGB565 H3RGB565::LightGrey()
	{
		return 0xD69A;
	}
	_H3API_ RGB565 H3RGB565::LightGreen()
	{
		return 0x9772;
	}
	_H3API_ RGB565 H3RGB565::LightPink()
	{
		return 0xFDB8;
	}
	_H3API_ RGB565 H3RGB565::LightSalmon()
	{
		return 0xFD0F;
	}
	_H3API_ RGB565 H3RGB565::LightSeaGreen()
	{
		return 0x2595;
	}
	_H3API_ RGB565 H3RGB565::LightSkyBlue()
	{
		return 0x867F;
	}
	_H3API_ RGB565 H3RGB565::LightSlateGray()
	{
		return 0x7453;
	}
	_H3API_ RGB565 H3RGB565::LightSlateGrey()
	{
		return 0x7453;
	}
	_H3API_ RGB565 H3RGB565::LightSteelBlue()
	{
		return 0xB63B;
	}
	_H3API_ RGB565 H3RGB565::LightYellow()
	{
		return 0xFFFC;
	}
	_H3API_ RGB565 H3RGB565::Lime()
	{
		return 0x7E0;
	}
	_H3API_ RGB565 H3RGB565::LimeGreen()
	{
		return 0x3666;
	}
	_H3API_ RGB565 H3RGB565::Linen()
	{
		return 0xFF9C;
	}
	_H3API_ RGB565 H3RGB565::Magenta()
	{
		return 0xF81F;
	}
	_H3API_ RGB565 H3RGB565::Maroon()
	{
		return 0x8000;
	}
	_H3API_ RGB565 H3RGB565::MediumAquaMarine()
	{
		return 0x6675;
	}
	_H3API_ RGB565 H3RGB565::MediumBlue()
	{
		return 0x19;
	}
	_H3API_ RGB565 H3RGB565::MediumOrchid()
	{
		return 0xBABA;
	}
	_H3API_ RGB565 H3RGB565::MediumPurple()
	{
		return 0x939B;
	}
	_H3API_ RGB565 H3RGB565::MediumSeaGreen()
	{
		return 0x3D8E;
	}
	_H3API_ RGB565 H3RGB565::MediumSlateBlue()
	{
		return 0x7B5D;
	}
	_H3API_ RGB565 H3RGB565::MediumSpringGreen()
	{
		return 0x7D3;
	}
	_H3API_ RGB565 H3RGB565::MediumTurquoise()
	{
		return 0x4E99;
	}
	_H3API_ RGB565 H3RGB565::MediumVioletRed()
	{
		return 0xC0B0;
	}
	_H3API_ RGB565 H3RGB565::MidnightBlue()
	{
		return 0x18CE;
	}
	_H3API_ RGB565 H3RGB565::MintCream()
	{
		return 0xF7FF;
	}
	_H3API_ RGB565 H3RGB565::MistyRose()
	{
		return 0xFF3C;
	}
	_H3API_ RGB565 H3RGB565::Moccasin()
	{
		return 0xFF36;
	}
	_H3API_ RGB565 H3RGB565::NavajoWhite()
	{
		return 0xFEF5;
	}
	_H3API_ RGB565 H3RGB565::Navy()
	{
		return 0x410;
	}
	_H3API_ RGB565 H3RGB565::OldLace()
	{
		return 0xFFBC;
	}
	_H3API_ RGB565 H3RGB565::Olive()
	{
		return 0x8400;
	}
	_H3API_ RGB565 H3RGB565::OliveDrab()
	{
		return 0x6C64;
	}
	_H3API_ RGB565 H3RGB565::Orange()
	{
		return 0xFD20;
	}
	_H3API_ RGB565 H3RGB565::OrangeRed()
	{
		return 0xFA20;
	}
	_H3API_ RGB565 H3RGB565::Orchid()
	{
		return 0xDB9A;
	}
	_H3API_ RGB565 H3RGB565::PaleGoldenRod()
	{
		return 0xEF55;
	}
	_H3API_ RGB565 H3RGB565::PaleGreen()
	{
		return 0x9FD3;
	}
	_H3API_ RGB565 H3RGB565::PaleTurquoise()
	{
		return 0xAF7D;
	}
	_H3API_ RGB565 H3RGB565::PaleVioletRed()
	{
		return 0xDB92;
	}
	_H3API_ RGB565 H3RGB565::PapayaWhip()
	{
		return 0xFF7A;
	}
	_H3API_ RGB565 H3RGB565::PeachPuff()
	{
		return 0xFED7;
	}
	_H3API_ RGB565 H3RGB565::Peru()
	{
		return 0xCC27;
	}
	_H3API_ RGB565 H3RGB565::Pink()
	{
		return 0xFE19;
	}
	_H3API_ RGB565 H3RGB565::Plum()
	{
		return 0xDD1B;
	}
	_H3API_ RGB565 H3RGB565::PowderBlue()
	{
		return 0xB71C;
	}
	_H3API_ RGB565 H3RGB565::Purple()
	{
		return 0x8010;
	}
	_H3API_ RGB565 H3RGB565::Red()
	{
		return 0xF800;
	}
	_H3API_ RGB565 H3RGB565::RosyBrown()
	{
		return 0xBC71;
	}
	_H3API_ RGB565 H3RGB565::RoyalBlue()
	{
		return 0x435C;
	}
	_H3API_ RGB565 H3RGB565::SaddleBrown()
	{
		return 0x8A22;
	}
	_H3API_ RGB565 H3RGB565::Salmon()
	{
		return 0xFC0E;
	}
	_H3API_ RGB565 H3RGB565::SandyBrown()
	{
		return 0xF52C;
	}
	_H3API_ RGB565 H3RGB565::SeaGreen()
	{
		return 0x2C4A;
	}
	_H3API_ RGB565 H3RGB565::SeaShell()
	{
		return 0xFFBD;
	}
	_H3API_ RGB565 H3RGB565::Sienna()
	{
		return 0xA285;
	}
	_H3API_ RGB565 H3RGB565::Silver()
	{
		return 0xC618;
	}
	_H3API_ RGB565 H3RGB565::SkyBlue()
	{
		return 0x867D;
	}
	_H3API_ RGB565 H3RGB565::SlateBlue()
	{
		return 0x6AD9;
	}
	_H3API_ RGB565 H3RGB565::SlateGray()
	{
		return 0x7412;
	}
	_H3API_ RGB565 H3RGB565::SlateGrey()
	{
		return 0x7412;
	}
	_H3API_ RGB565 H3RGB565::Snow()
	{
		return 0xFFDF;
	}
	_H3API_ RGB565 H3RGB565::SpringGreen()
	{
		return 0x7EF;
	}
	_H3API_ RGB565 H3RGB565::SteelBlue()
	{
		return 0x4416;
	}
	_H3API_ RGB565 H3RGB565::Tan()
	{
		return 0xD5B1;
	}
	_H3API_ RGB565 H3RGB565::Teal()
	{
		return 0x410;
	}
	_H3API_ RGB565 H3RGB565::Thistle()
	{
		return 0xDDFB;
	}
	_H3API_ RGB565 H3RGB565::Tomato()
	{
		return 0xFB08;
	}
	_H3API_ RGB565 H3RGB565::Turquoise()
	{
		return 0x471A;
	}
	_H3API_ RGB565 H3RGB565::Violet()
	{
		return 0xEC1D;
	}
	_H3API_ RGB565 H3RGB565::Wheat()
	{
		return 0xF6F6;
	}
	_H3API_ RGB565 H3RGB565::White()
	{
		return 0xFFFF;
	}
	_H3API_ RGB565 H3RGB565::WhiteSmoke()
	{
		return 0xF7BE;
	}
	_H3API_ RGB565 H3RGB565::Yellow()
	{
		return 0xFFE0;
	}
	_H3API_ RGB565 H3RGB565::YellowGreen()
	{
		return 0x9E66;
	}

	_H3API_ UINT H3ARGB888::operator*() const
	{
		return Value();
	}

	_H3API_ H3ARGB888::operator DWORD() const
	{
		return Value();
	}
	_H3API_ VOID H3ARGB888::Darken(const UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Darken(amount);
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::Lighten(const UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Lighten(amount);
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::GrayScale()
	{
		H3RGB888 rgb(*this);
		rgb.GrayScale();
		r = rgb.r;
		g = rgb.g;
		b = rgb.b;
	}
	_H3API_ VOID H3ARGB888::Legacy()
	{
		const UINT8 tmp = a;
		a = b;
		b = g;
		g = tmp;
	}
	_H3API_ H3ARGB888::H3ARGB888()
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(DWORD col)
	{
		*AsDword() = col;
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3RGB565& col) :
		b(col.GetBlue8()),
		g(col.GetGreen8()),
		r(col.GetRed8()),
		a(0xFF)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3RGB888& col) :
		b(col.b),
		g(col.g),
		r(col.r),
		a(0xFF)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(const H3ARGB888& col) :
		b(col.b),
		g(col.g),
		r(col.r),
		a(col.a)
	{
	}
	_H3API_ H3ARGB888::H3ARGB888(UINT8 red, UINT8 green, UINT8 blue) :
		b(blue),
		g(green),
		r(red),
		a(0xFF)
	{
	}
	_H3API_ DWORD H3ARGB888::GetColor() const
	{
		return *AsDword();
	}
	_H3API_ VOID H3ARGB888::operator=(const H3RGB565& col)
	{
		r = col.GetRed8();
		g = col.GetGreen8();
		b = col.GetBlue8();
		a = 0xFF;
	}
	_H3API_ VOID H3ARGB888::operator=(const H3RGB888& col)
	{
		r = col.r;
		g = col.g;
		b = col.b;
		a = 0xFF;
	}
	_H3API_ VOID H3ARGB888::operator=(const H3ARGB888& col)
	{
		*AsDword() = col.Value();
	}
	_H3API_ VOID H3ARGB888::operator=(UINT16 col)
	{
		*this = H3RGB565(col);
	}
	_H3API_ VOID H3ARGB888::operator=(UINT32 col)
	{
		*AsDword() = col;
	}
	_H3API_ BOOL H3ARGB888::operator==(const H3ARGB888& col)
	{
		return r == col.r && g == col.g && b == col.b && a == col.a;
	}
	_H3API_ VOID H3ARGB888::LightShadow()
	{
		*AsDword() = ((*AsDword() >> 1) & 0x7F7F7F) | ((*AsDword() >> 2) & 0x3F3F3F);
	}
	_H3API_ VOID H3ARGB888::DarkShadow()
	{
		*AsDword() = (*AsDword() >> 1) & 0x7F7F7F;
	}
	_H3API_ VOID H3ARGB888::Blend(const H3ARGB888& col)
	{
		*AsDword() = ((*AsDword() >> 1) & 0x7F7F7F) | ((*col.AsDword() >> 1) & 0x7F7F7F);
	}
	_H3API_ PDWORD H3ARGB888::AsDword()
	{
		return PDWORD(this);
	}
	_H3API_ PDWORD H3ARGB888::AsDword() const
	{
		return PDWORD(this);
	}
	_H3API_ UINT8 H3RGB555::GetRed()
	{
		return (bits & 0x7C00) >> 10;
	}
	_H3API_ UINT8 H3RGB555::GetGreen()
	{
		return (bits & 0x3E0) >> 5;
	}
	_H3API_ UINT8 H3RGB555::GetBlue()
	{
		return bits & 0x1F;
	}
	_H3API_ DWORD H3RGB555::UnPack()
	{
		return GetRed() << 16 | GetGreen() << 8 | GetBlue();
	}
	_H3API_ VOID H3RGB555::SetBits(WORD color)
	{
		bits = color;
	}
	_H3API_ WORD H3RGB555::Pack(UINT8 r, UINT8 g, UINT8 b)
	{
		return ((r / 8) & 0x1F) << 10 | ((g / 8) & 0x1F) << 5 | ((b / 8) & 0x1F);
	}
	_H3API_ DWORD H3RGB555::Unpack(RGB555 rgb)
	{
		return (((((rgb & 0x7C00) >> 10) * 255 + 15) / 31) << 16) + (((((rgb & 0x3E0) >> 5) * 255 + 31) / 63) << 8) + (((rgb & 0x1F) * 255 + 15) / 31);
	}
	_H3API_ VOID H3RGB555::PackRGB(UINT8 r, UINT8 g, UINT8 b)
	{
		bits = Pack(r, g, b);
	}
	_H3API_ UINT8 H3RGB565::GetRed() const
	{
		return (bits & 0xF800) >> 11;
	}
	_H3API_ UINT8 H3RGB565::GetRed8() const
	{
		return (GetRed() * 255 + 15) / 31;
	}
	_H3API_ UINT8 H3RGB565::GetGreen() const
	{
		return (bits & 0x7E0) >> 5;
	}
	_H3API_ UINT8 H3RGB565::GetGreen8() const
	{
		return (GetGreen() * 255 + 31) / 63;
	}
	_H3API_ UINT8 H3RGB565::GetBlue() const
	{
		return bits & 0x1F;
	}
	_H3API_ UINT8 H3RGB565::GetBlue8() const
	{
		return (GetBlue() * 255 + 15) / 31;
	}
	_H3API_ DWORD H3RGB565::GetRGB888() const
	{
		return (GetRed8() << 16 | GetGreen8() << 8 | GetBlue8());
	}
	_H3API_ RGB565 H3RGB565::GetBits() const
	{
		return bits;
	}
	_H3API_ H3RGB565::H3RGB565() :
		bits()
	{
	}
	_H3API_ H3RGB565::H3RGB565(RGB565 rgb) :
		bits(rgb)
	{
	}
	_H3API_ H3RGB565::H3RGB565(UINT8 r, UINT8 g, UINT8 b) :
		bits(Pack(r, g, b))
	{
	}
	_H3API_ H3RGB565::H3RGB565(DWORD color)
	{
		PackRGB565((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
	}
	_H3API_ H3RGB565::H3RGB565(const H3RGB888& color)
	{
		PackRGB565(color.r, color.g, color.b);
	}
	_H3API_ H3RGB565::H3RGB565(const H3ARGB888& color)
	{
		PackRGB565(color.r, color.g, color.b);
	}
	_H3API_ VOID H3RGB565::operator=(const H3RGB565& col)
	{
		bits = col.bits;
	}
	_H3API_ VOID H3RGB565::operator=(const H3RGB888& col)
	{
		bits = Pack(col.r, col.g, col.b);
	}
	_H3API_ VOID H3RGB565::operator=(const H3ARGB888& col)
	{
		bits = Pack(col.r, col.g, col.b);
	}
	_H3API_ VOID H3RGB565::operator=(const UINT16 col)
	{
		bits = col;
	}
	_H3API_ VOID H3RGB565::operator=(const UINT32 col)
	{
		operator=(H3ARGB888(col));
	}
	_H3API_ BOOL H3RGB565::operator==(const H3RGB565& col)
	{
		return bits == col.bits;
	}
	_H3API_ H3RGB565::operator WORD() const
	{
		return Value();
	}
	_H3API_ WORD H3RGB565::Value() const
	{
		return bits;
	}
	_H3API_ VOID H3RGB565::SetBits(WORD color)
	{
		bits = color;
	}
	_H3API_ VOID H3RGB565::PackRGB565(UINT8 r, UINT8 g, UINT8 b)
	{
		bits = Pack(r, g, b);
	}
	_H3API_ VOID H3RGB565::Pack(H3RGB888& rgb)
	{
		bits = Pack(rgb.r, rgb.g, rgb.b);
	}
	_H3API_ WORD H3RGB565::Pack(UINT8 r, UINT8 g, UINT8 b)
	{
		return ((r / 8) & 0x1F) << 11 | ((g / 4) & 0x3F) << 5 | ((b / 8) & 0x1F);
	}
	_H3API_ DWORD H3RGB565::Unpack(RGB565 rgb)
	{
		return (((((rgb & 0xF800) >> 11) * 255 + 15) / 31) << 16) + (((((rgb & 0x7E0) >> 5) * 255 + 31) / 63) << 8) + (((rgb & 0x1F) * 255 + 15) / 31);
	}
	_H3API_ VOID H3RGB565::Darken(UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Darken(amount);
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::Lighten(UINT8 amount)
	{
		H3RGB888 rgb(*this);
		rgb.Lighten(amount);
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::GrayScale()
	{
		H3RGB888 rgb(*this);
		rgb.GrayScale();
		Pack(rgb);
	}
	_H3API_ VOID H3RGB565::LightShadow()
	{
		LightShadow(H3RGB565::mask50(), H3RGB565::mask25());
	}
	_H3API_ VOID H3RGB565::LightShadow(RGB565 mask50, RGB565 mask25)
	{
		bits = ((bits >> 1) & mask50) | ((bits >> 2) & mask25);
	}
	_H3API_ VOID H3RGB565::DarkShadow()
	{
		DarkShadow(H3RGB565::mask50());
	}
	_H3API_ VOID H3RGB565::DarkShadow(RGB565 mask50)
	{
		bits = (bits >> 1) & mask50;
	}
	_H3API_ VOID H3RGB565::Blend(const H3RGB565& col)
	{
		Blend(col, H3RGB565::mask50());
	}
	_H3API_ VOID H3RGB565::Blend(const H3RGB565& col, RGB565 mask)
	{
		bits = ((bits >> 1) & mask) | ((col.bits >> 1) & mask);
	}
	_H3API_ H3HSV::H3HSV() :
		h(),
		s(),
		v()
	{
	}
	_H3API_ H3HSV::H3HSV(H3HSV& other) :
		h(other.h),
		s(other.s),
		v(other.v)
	{
	}
	_H3API_ H3HSV::H3HSV(const H3RGB888& rgb)
	{
		ConvertFromRgb888(rgb);
	}
	_H3API_ H3HSV& H3HSV::ConvertFromRgb888(const H3RGB888& rgb)
	{
		const UINT8 rgb_min = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
		const UINT8 rgb_max = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

		v = rgb_max;
		if (v == 0)
		{
			h = 0;
			s = 0;
			return *this;
		}

		s = 255 * long(rgb_max - rgb_min) / v;
		if (s == 0)
		{
			h = 0;
			return *this;
		}

		if (rgb_max == rgb.r)
			h = 0 + 43 * (rgb.g - rgb.b) / (rgb_max - rgb_min);
		else if (rgb_max == rgb.g)
			h = 85 + 43 * (rgb.b - rgb.r) / (rgb_max - rgb_min);
		else
			h = 171 + 43 * (rgb.r - rgb.g) / (rgb_max - rgb_min);

		return *this;
	}
	_H3API_ H3RGB888 H3HSV::ConvertToRgb888() const
	{
		H3RGB888 rgb;

		if (s == 0)
		{
			rgb.r = v;
			rgb.g = v;
			rgb.b = v;
			return rgb;
		}

		const UINT8 region = h / 43;
		const UINT8 remainder = (h - (region * 43)) * 6;

		const UINT8 p = (v * (255 - s)) >> 8;
		const UINT8 q = (v * (255 - ((s * remainder) >> 8))) >> 8;
		const UINT8 t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

		switch (region)
		{
		case 0:
			rgb.r = v; rgb.g = t; rgb.b = p;
			break;
		case 1:
			rgb.r = q; rgb.g = v; rgb.b = p;
			break;
		case 2:
			rgb.r = p; rgb.g = v; rgb.b = t;
			break;
		case 3:
			rgb.r = p; rgb.g = q; rgb.b = v;
			break;
		case 4:
			rgb.r = t; rgb.g = p; rgb.b = v;
			break;
		default:
			rgb.r = v; rgb.g = p; rgb.b = q;
			break;
		}
		return rgb;
	}
	_H3API_ VOID H3HSV::AddSaturation(UINT8 saturation)
	{
		s = std::min(255, s + saturation);
	}
	_H3API_ VOID H3HSV::RemoveSaturation(UINT8 saturation)
	{
		s = std::max(0, s - saturation);
	}
	_H3API_ VOID H3HSV::SetHue(UINT8 hue)
	{
		h = hue;
	}
	_H3API_ VOID H3HSV::AddValue(UINT8 value)
	{
		v = std::min(255, v + value);
	}
	_H3API_ VOID H3HSV::RemoveValue(UINT8 value)
	{
		v = std::max(0, v - value);
	}
	_H3API_ H3RGB565 H3RGB565::mask25()
	{
		return WordAt(0x6968FA);
	}
	_H3API_ H3RGB565 H3RGB565::mask50()
	{
		return WordAt(0x6968F4);
	}
}
