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
    namespace NH3Quest
    {
        namespace NQuestType
        {
            enum eQuestType
            {
                NONE             = 0,
                EXPERIENCE_LEVEL = 1,
                PRIMARY_SKILL    = 2,
                DEFEAT_HERO      = 3,
                DEFEAT_MONSTER   = 4,
                BRING_ARTIFACTS  = 5,
                BRING_CREATURES  = 6,
                BRING_RESOURCES  = 7,
                BE_HERO          = 8,
                BE_PLAYER        = 9,
            };
        }
        typedef NQuestType::eQuestType eQuestType;

        namespace NSeerReward
        {
            enum eSeerReward
            {
                NONE            = 0,
                EXPERIENCE      = 1,
                SPELL_POINTS    = 2,
                MORALE          = 3,
                LUCK            = 4,
                RESOURCE        = 5,
                PRIMARY_SKILL   = 6,
                SECONDARY_SKILL = 7,
                ARTIFACT        = 8,
                SPELL           = 9,
                CREATURE        = 10,
            };
        }
        typedef NSeerReward::eSeerReward eSeerReward;
    }
    typedef NH3Quest::eQuestType  eQuest;
    typedef NH3Quest::eSeerReward eSeer;
} /* namespace h3 */
