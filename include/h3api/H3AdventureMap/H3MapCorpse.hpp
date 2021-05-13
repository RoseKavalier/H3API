//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstArtifact.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemCorpse);

#pragma pack(push, 4)

	/** @brief data for corpse on adventure map*/
	struct H3MapitemCorpse
	{
		/** @brief [00] 0..31 corpse index*/
		unsigned  id          : 5;
		/** @brief [05]*/
		unsigned _u1          : 1;
		/** @brief [06] 0..1023 artifact ID*/
		unsigned  artifactID  : 10;
		/** @brief [16] whether the Corpse contains an artifact*/
		unsigned  hasArtifact : 1;
		/** @brief [17]*/
		unsigned _u2          : 15;

		_H3API_ eArtifact GetArtifact();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
