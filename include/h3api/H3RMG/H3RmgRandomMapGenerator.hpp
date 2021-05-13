//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3RMG/H3RmgMap.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
    struct H3RmgObjectProperties;
    struct H3RmgObject;
    struct H3RmgTemplate;
    struct H3RmgZoneGenerator;
    struct H3RmgObjectGenerator;
    struct H3GzFile;
    struct H3RmgParameters;

#pragma pack(push, 4)

    /** @brief original name: type_random_map_generator*/
    struct H3RmgRandomMapGenerator
    {
        _H3API_SIZE_(0x14E0);
        h3func*                        vTable;                 /**< @brief [00]*/
        UINT32                         randomSeed;             /**< @brief [04]*/
        INT32                          gameVersion;            /**< @brief [08]*/
        H3RmgMap                        map;                    /**< @brief [0C]*/
        H3Vector<H3RmgObjectProperties>      objectsTxt;             /**< @brief [24] all of the the object properties*/
        H3Vector<H3RmgObjectProperties**>    objectPrototypes[232];  /**< @brief [34] object properties classified by type*/
        H3Vector<h3unk*>               _f_0EB4;                /**< @brief [EB4]*/
        H3Vector<H3RmgObject*>          positions;              /**< @brief [EC4]*/
        h3unk32                        progress;               /**< @brief [ED4]*/
        BOOL8                          isHuman[8];             /**< @brief [ED8]*/
        INT32                          playerOwner[8];         /**< @brief [EE0]*/
        h3unk                          _f_f00[36];             /**< @brief [F00]*/
        INT32                          playerTown[8];          /**< @brief [F24]*/
        INT32                          monsterOrObjectCount;   /**< @brief [F44]*/
        INT32                          humanCount;             /**< @brief [F48]*/
        INT32                          humanTeams;             /**< @brief [F4C]*/
        INT32                          computerCount;          /**< @brief [F50]*/
        INT32                          computerTeams;          /**< @brief [F54]*/
        h3unk                          _f_f58[8];              /**< @brief [F58]*/
        INT32                          townsCount;             /**< @brief [F60]*/
        h3unk                          _f_f64[4];              /**< @brief [F64]*/
        h3unk                          _f_f68[32];             /**< @brief [F68]*/
        BOOL8                          bannedHeroes[156];      /**< @brief [F88]*/
        BOOL8                          bannedArtifacts[144];   /**< @brief [1024]*/
        h3unk                          _f_10B4[4];             /**< @brief [10B4]*/
        INT32                          waterAmount;            /**< @brief [10B8]*/
        INT32                          monsterStrength;        /**< @brief [10BC]*/
        H3String                       templateName;           /**< @brief [10C0]*/
        H3Vector<H3RmgTemplate*>        randomTemplates;        /**< @brief [10D0]*/
        H3Vector<H3RmgZoneGenerator*>   zoneGenerators;         /**< @brief [10E0]*/
        H3Vector<H3RmgObjectGenerator*> objectGenerators;       /**< @brief [10F0]*/
        H3Vector<h3unk*>               _f_1100;                /**< @brief [1100]*/
        INT32                          objectCountByType[232]; /**< @brief [1110]*/
        H3Vector<H3Point>              roadTargets;            /**< @brief [14B0]*/
        H3Vector<H3RmgObject*>          monolithsOneWay;        /**< @brief [14C0]*/
        H3Vector<H3RmgObject*>          monolithsTwoWay;        /**< @brief [14D0]*/

        _H3API_ H3RmgRandomMapGenerator(/* not const*/ H3RmgParameters& p, PVOID progress);
        _H3API_ ~H3RmgRandomMapGenerator();
        _H3API_ BOOL8 GenerateMap();
        _H3API_ BOOL8 WriteMap(H3GzFile& stream);
    };
    _H3API_ASSERT_SIZE_(H3RmgRandomMapGenerator);

    // old name
    typedef H3RmgRandomMapGenerator RMG_Main;

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
