//////////////////////////////////////////////////////////////////////
//                                                                  //
//                  Created by RoseKavalier:                        //
//                  rosekavalierhc@gmail.com                        //
//                                                                  //
//          ***You may use or distribute these files freely         //
//             so long as this notice remains present.***           //
//                                                                  //
//          In preparing these files, several sources were          //
//            consulted, they are listed in no particular           //
//                          order below.                            //
//                                                                  //
//  Source: https://github.com/potmdehex/homm3tools                 //
//  Author: potmdehex and contributors                              //
//                                                                  //
//  Source: https://github.com/redxu/HoMM3_FA                       //
//  Author: redxu                                                   //
//                                                                  //
//  Source: https://github.com/openhomm/openhomm                    //
//  Author: Ershov Stanislav, Fomin Roman, Akulich Alexander        //
//                                                                  //
//  Source: https://github.com/GrayFace/wog                         //
//  Author: GrayFace and WoG team                                   //
//                                                                  //
//  Source: https://github.com/ethernidee/era                       //
//  Author: Berserker                                               //
//                                                                  //
//  Source: https://github.com/ethernidee/era-editor                //
//  Author: Grayface and Berserker                                  //
//                                                                  //
//  Source: http://wforum.heroes35.net/showthread.php?tid=3900      //
//  Author: Slava and GrayFace                                      //
//                                                                  //
//  Source: http://wforum.heroes35.net/showthread.php?tid=4583      //
//  Author: gamecreator                                             //
//                                                                  //
//  Thanks: patcher_x86 by baratorch and code therein               //
//                                                                  //
//////////////////////////////////////////////////////////////////////

//
//  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄
// ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
// ▐░▌       ▐░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀
// ▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌
// ▐░█▄▄▄▄▄▄▄█░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌
// ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌
// ▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀      ▐░▌
// ▐░▌       ▐░▌          ▐░▌▐░▌       ▐░▌▐░▌               ▐░▌
// ▐░▌       ▐░▌ ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌           ▄▄▄▄█░█▄▄▄▄
// ▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░░░░░░░░░░░▌
//  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀            ▀▀▀▀▀▀▀▀▀▀▀
//

// * Note to USERS
// *
// * If you are using MSVC 2017+ and are getting errors
// * with the H3API headers, go to your project's
// * Property Pages. Under the C/C++ options, look
// * for "Conformance mode" and set it as "No".
// * It's a bug that is still not resolved in VS.
// *
// * https://developercommunity.visualstudio.com/content/problem/174539/objbaseh-error-when-compiling-with-permissive-and.html

// *
// * H3API Preprocessor Definitions Overview
// *

#ifndef _H3API_LIBRARY_
// * tells the library that it should only include header files within your project
// * and that you will rely on the static library to access the library's implementation
// * in this header, library is enforced. Use <.>/single_header/H3API.hpp for include-only
#define _H3API_LIBRARY_
#endif

// * _H3API_STD_CONVERSIONS_
// * allows conversion between the following formats
// * std::string <<==>> h3::H3String
// * std::vector <<==>> h3::H3Vector

// * _H3API_STD_VECTOR_
// * If you are using Visual Studio 2013 or more recent you can
// * define this preprocessor to use H3StdVector<> which acts as std::vector<>
// * with correct padding and uses H3ObjectAllocator<>

// * _H3API_EXCEPTION_
// * tells the library to include the H3Exception exception handler within your project
// * which is derived from std::exception and may catch SEH errors.
// * your project needs to use /EHa compiler flag to use it.

// * _H3API_DONT_USE_MACROS_
// * tells the library to exclude macros that can pollute the global namespace when defined.
// * these macros are then replaced by typedefs so extra parentheses may be required.
// * if you would like the convenience of switching between both modes, always add parentheses at the end.

// * _H3API_UNPREFIXED_NAMES_
// * H3API structures are always prefixed with H3#### and used so internally.
// * By defining this preprocessor option, declarations will also
// * add an unprefixed typedef so that code may appear less redundant when
// * accessing them from outside the h3 namespace, e.g. h3::Vector vs h3::H3Vector
// * If you prefer 'using namespace h3;' then it may be better to use the prefixed versions
// * to avoid potential conflicts.

// * _H3API_NO_VALIDATION_
// * there are compile-time asserts in H3API to verify
// * structures' sizes and validate some template parameters.
// * define this macro if you do not wish to perform these validations.

// * _H3API_PATCHER_X86_
// * tells the library to include its own "patcher_x86.hpp" header within your project
// * don't use this if you prefer having your own patcher_x86 header.

// * _H3API_PLUGINS_
// * tells the library to include the necessary headers to interact with H3Plugins projects
// * in most cases you won't need this.

#ifndef _H3API_HPP_
#define _H3API_HPP_

#include "h3api/H3AdventureMap.hpp"
#include "h3api/H3AI.hpp"
#include "h3api/H3Artifacts.hpp"
#include "h3api/H3Assets.hpp"
#include "h3api/H3Base.hpp"
#include "h3api/H3Campaign.hpp"
#include "h3api/H3Combat.hpp"
#include "h3api/H3Constants.hpp"
#include "h3api/H3Containers.hpp"
#include "h3api/H3Creatures.hpp"
#include "h3api/H3Defines.hpp"
#include "h3api/H3DialogControls.hpp"
#include "h3api/H3Dialogs.hpp"
#include "h3api/H3GameData.hpp"
#include "h3api/H3GzWrapper.hpp"
#include "h3api/H3Heroes.hpp"
#include "h3api/H3Managers.hpp"
#include "h3api/H3Players.hpp"
#include "h3api/H3RMG.hpp"
#include "h3api/H3Skills.hpp"
#include "h3api/H3Towns.hpp"
#include "h3api/H3Utilities.hpp"
#include "h3api/H3Version.hpp"
#include "h3api/PreprocessorCleanup.hpp"

#ifdef _H3API_PATCHER_X86_
#include <patcher_x86.hpp>
#endif

#endif /* #define _H3API_HPP_ */
