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
    namespace NH3Skills
    {
        namespace NPrimarySkills
        {
            enum ePrimarySkills : INT32
            {
                ATTACK       = 0,
                DEFENSE      = 1,
                SPELL_POWER  = 2,
                KNOWLEDGE    = 3,
            };
        }
        typedef NPrimarySkills::ePrimarySkills ePrimarySkills;

        namespace NSecondarySkills
        {
            enum eSecondary : INT32
            {
                NONE         = -1,
                PATHFINDING  = 0,
                ARCHERY      = 1,
                LOGISTICS    = 2,
                SCOUTING     = 3,
                DIPLOMACY    = 4,
                NAVIGATION   = 5,
                LEADERSHIP   = 6,
                WISDOM       = 7,
                MYSTICISM    = 8,
                LUCK         = 9,
                BALLISTICS   = 10,
                EAGLE_EYE    = 11,
                NECROMANCY   = 12,
                ESTATES      = 13,
                FIRE_MAGIC   = 14,
                AIR_MAGIC    = 15,
                WATER_MAGIC  = 16,
                EARTH_MAGIC  = 17,
                SCHOLAR      = 18,
                TACTICS      = 19,
                ARTILLERY    = 20,
                LEARNING     = 21,
                OFFENSE      = 22,
                ARMORER      = 23,
                INTELLIGENCE = 24,
                SORCERY      = 25,
                RESISTANCE   = 26,
                FIRST_AID    = 27,
            };
        }
        typedef NSecondarySkills::eSecondary eSecondary;

        namespace NSecSkillLevel
        {
            enum eSecSkillLevel : INT32
            {
                NONE     = 0,
                BASIC    = 1,
                ADVANCED = 2,
                EXPERT   = 3,
            };
        }
        typedef NSecSkillLevel::eSecSkillLevel eSecSkillLevel;
    } /* namespace NH3Skills */
    typedef NH3Skills::ePrimarySkills   ePrimary;
    typedef NH3Skills::eSecondary eSecondary;
    typedef NH3Skills::eSecSkillLevel   eSecSkillLevel;
} /* namespace h3 */
