//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Skills/H3Diplomacy.hpp"
#include "h3api/H3AdventureMap/H3MapMonster.hpp"
#include "h3api/H3Constants/H3CstSkills.hpp"
#include "h3api/H3Creatures/H3CreatureInformation.hpp"
#include "h3api/H3Heroes/H3Hero.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
    _H3API_ INT32 H3Diplomacy::GetPowerFactor(FLOAT k)
    {
        return STDCALL_1(INT32, 0x4A7330, k);
    }
    _H3API_ INT32 H3Diplomacy::DiplomacyJoinCost(H3Hero* hero, const H3MapitemMonster& creature)
    {
        if (!hero)
            return eDiploType::NO_HERO;

        INT32 type = creature.CreatureType();
        H3CreatureInformation& info = H3CreatureInformation::Get()[type];
        INT32 sympathy = hero->HasSimilarCreature(type);
        FLOAT hero_power = FLOAT(hero->GetPower());
        FLOAT creature_power = FLOAT(info.aiValue * creature.count);
        FLOAT ratio = hero_power / creature_power;
        INT32 power_factor = GetPowerFactor(ratio);
        INT32 difficulty_bonus = H3Main::Get()->playersInfo.difficulty == 0;
        INT32 diplo_lvl = hero->secSkill[eSecondary::DIPLOMACY] + difficulty_bonus;
        diplo_lvl = std::min(3, diplo_lvl);
        INT32 charisma = power_factor + diplo_lvl + sympathy;
        INT32 aggression = creature.aggression;

        if (aggression > charisma)
            return eDiploType::FIGHT;
        if (aggression <= sympathy + diplo_lvl + 1)
            return eDiploType::JOIN_FREE;
        if (aggression <= sympathy + 2 * diplo_lvl + 1)
            return info.cost.gold * creature.count;
        if (creature.noRun || aggression == charisma)
            return eDiploType::FIGHT;
        return eDiploType::FLEE;
    }
} /* namespace h3 */
