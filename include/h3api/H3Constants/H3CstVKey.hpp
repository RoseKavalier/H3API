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

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
    namespace NH3VKey
    {
        enum eVirtualKeys : INT32
        {
            H3VK_ESCAPE        = 1,
            H3VK_1             = 2,
            H3VK_2             = 3,
            H3VK_3             = 4,
            H3VK_4             = 5,
            H3VK_5             = 6,
            H3VK_6             = 7,
            H3VK_7             = 8,
            H3VK_8             = 9,
            H3VK_9             = 10,
            H3VK_0             = 11,
            H3VK_MINUS         = 12,
            H3VK_PLUS          = 13,
            H3VK_BACKSPACE     = 14,
            H3VK_TAB           = 15,
            H3VK_Q             = 16,
            H3VK_W             = 17,
            H3VK_E             = 18,
            H3VK_R             = 19,
            H3VK_T             = 20,
            H3VK_Y             = 21,
            H3VK_U             = 22,
            H3VK_I             = 23,
            H3VK_O             = 24,
            H3VK_P             = 25,
            H3VK_LEFT_BRACKET  = 26,
            H3VK_RIGHT_BRACKET = 27,
            H3VK_ENTER         = 28,
            H3VK_CTRL          = 29,
            H3VK_A             = 30,
            H3VK_S             = 31,
            H3VK_D             = 32,
            H3VK_F             = 33,
            H3VK_G             = 34,
            H3VK_H             = 35,
            H3VK_J             = 36,
            H3VK_K             = 37,
            H3VK_L             = 38,
            H3VK_SEMICOLON     = 39,
            H3VK_APOSTROPHE    = 40,
            H3VK_TILDE         = 41,
            H3VK_SHIFT         = 42,
            H3VK_BACKSLASH     = 43,
            H3VK_Z             = 44,
            H3VK_X             = 45,
            H3VK_C             = 46,
            H3VK_V             = 47,
            H3VK_B             = 48,
            H3VK_N             = 49,
            H3VK_M             = 50,
            H3VK_COMMA         = 51,
            H3VK_PERIOD        = 52,
            H3VK_SLASH         = 53,
            H3VK_RIGHT_SHIFT   = 54,
            H3VK_PRINTSCREEN   = 55, // or * on numpad?
            H3VK_ALT           = 56,
            H3VK_SPACEBAR      = 57,

            H3VK_F2            = 60,
            H3VK_F3            = 61,
            H3VK_F4            = 62,
            H3VK_F5            = 63,
            H3VK_F6            = 64,
            H3VK_F7            = 65,
            H3VK_F8            = 66,
            H3VK_F9            = 67,
            H3VK_F10           = 68,
            H3VK_PAUSE         = 69,
            H3VK_SCROLL_LOCK   = 70,
            H3VK_HOME          = 71, // numpad7
            H3VK_UP            = 72, // numpad8
            H3VK_PAGE_UP       = 73, // numpad9
            H3VK_NUMPAD_MINUS  = 74,
            H3VK_LEFT          = 75, // numpad4
            H3VK_NUMPAD5       = 76,
            H3VK_RIGHT         = 77, // numpad6
            H3VK_NUMPAD_PLUS   = 78,
            H3VK_END           = 79, // numpad1
            H3VK_DOWN          = 80, // numpad2
            H3VK_PAGE_DOWN     = 81, // numpad3
            H3VK_INSERT        = 82,
            H3VK_DELETE        = 83,

            H3VK_F11           = 87,
            H3VK_F12           = 88,

            H3VK_LEFT_WIN      = 91,
            H3VK_RIGHT_WIN     = 92,
            H3VK_RIGHT_CLICK   = 93,
        };
    } /* namespace NH3VKey */
    typedef NH3VKey::eVirtualKeys eVKey;
} /* namespace h3 */
