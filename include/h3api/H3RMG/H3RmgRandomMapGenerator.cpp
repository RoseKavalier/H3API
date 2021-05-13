//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgRandomMapGenerator.hpp"
#include "h3api/H3RMG/H3RmgParameters.hpp"
#include "h3api/H3RMG/H3RmgObjectProperties.hpp" /* for H3Vector in ctor/dtor */

namespace h3
{
    _H3API_ H3RmgRandomMapGenerator::H3RmgRandomMapGenerator(H3RmgParameters& p, PVOID progress)
    {
        p.Validate();
        THISCALL_12(H3RmgRandomMapGenerator*, 0x538000, this, p.width, p.height, p.hasUnderground, p.humanCount, p.humanTeams,
            p.computerCount, p.computerTeams, p.waterAmount, p.monsterStrength, progress, p.gameVersion);
        for (INT i = 0; i < 8; ++i)
        {
            if (p.isHuman[i])
                isHuman[i] = TRUE;
            playerTown[i] = p.townId[i];
        }
    }
    _H3API_ H3RmgRandomMapGenerator::~H3RmgRandomMapGenerator()
    {
        THISCALL_1(VOID, 0x5382E0, this);
    }
    _H3API_ BOOL8 H3RmgRandomMapGenerator::GenerateMap()
    {
        return THISCALL_1(BOOL8, 0x549E20, this);
    }
    _H3API_ BOOL8 H3RmgRandomMapGenerator::WriteMap(H3GzFile& stream)
    {
        return THISCALL_2(BOOL8, 0x54B0E0, this, &stream);
    }
} /* namespace h3 */
