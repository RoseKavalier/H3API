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

#include "h3api/H3Base/H3Config.hpp" /* _H3API_STR_ */

#define _H3API_VERSION_MAJOR_ 1
#define _H3API_VERSION_MINOR_ 6
#define _H3API_VERSION_BUILD_ 1

#define _H3API_VERSION_ (_H3API_VERSION_MAJOR_ * 10000 | _H3API_VERSION_MINOR_ * 100 | _H3API_VERSION_BUILD_)
#define _H3API_VERSION_TEXT_ "H3API version " _H3API_STR_(_H3API_VERSION_MAJOR_) "." _H3API_STR_(_H3API_VERSION_MINOR_) "." _H3API_STR_(_H3API_VERSION_BUILD_)
