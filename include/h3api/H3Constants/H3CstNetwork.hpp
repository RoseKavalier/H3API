//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-09              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
	namespace NH3Network
    {
        namespace NNetwork
        {
            enum eNetworkId // from 0x405DC0
            {
                LOAD_GAME        = 1000,
                TEXT_MSG         = 1004,
                BATTLE_INFO      = 1005,
                PLAYER_E4        = 1009,
                DROP_GAME        = 1014,
                UNK1015          = 1015,
                END_TURN         = 1016,
                DROP_MSG         = 1017,
                ADD_PLAYER       = 1018,
                END_GAME         = 1019,
                LOSE_GAME        = 1020,
                REVEAL_AREA      = 1021,
                REVEAL_AREA2     = 1022, // identical except map draw parameters
                MOVE_HERO        = 1050,
                TELEPORT_HERO    = 1051,
                CAPTURE_MINE     = 1052,
                CAPTURE_TOWN     = 1053,
                CAPTURE_DWELLING = 1054,
                CAPTURE_GARRISON = 1055,
                CAPTURE_SHIPYARD = 1056,
                ADD_BOAT         = 1057,
                DELETE_OBJECT    = 1058,
                DELETE_HERO      = 1059,
                SHOW_HERO        = 1060,
                VANQUISHED_MBOX  = 1061,
                HIDE_HERO        = 1062,
                HEROES_MEET      = 1064,
                START_TURN       = 1071,
                UNK1074          = 1074,
                ASK_GIFT         = 1075,
                CONNECTION_LOST  = 1076,
                UNK1078          = 1078,
            };
        }
        typedef NNetwork::eNetworkId eNetworkId;
    } /* namespace NH3Network */
    typedef NH3Network::eNetworkId eNetwork;
} /* namespace h3 */
