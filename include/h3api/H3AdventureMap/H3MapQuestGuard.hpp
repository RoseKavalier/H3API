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
#include "h3api/H3Constants/H3CstQuest.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Skills/H3PrimarySkills.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemQuestGuard);
	_H3API_DECLARE_(QuestGuard);
	template<typename _Elem> struct H3Vector;
	struct H3Main;
	struct H3Resources;

#pragma pack(push, 4)
	/** @brief quest in memory, used for seer's hut and quest guards*/
	struct H3Quest
	{
		_H3API_SIZE_(0x60);
		// * Unions don't like to have constructors
		// * so this structure is made only for quests
		// * based on H3Vector
		struct QuestVector
		{
		protected:
			h3unk8 _allocator;
			INT32* first;
			INT32* last;
			INT32* capacity;
		public:
			_H3API_ INT32  Count();
			_H3API_ INT32& operator[](INT32 index);
			_H3API_ INT32* begin();
			_H3API_ INT32* end();
		};

		struct QuestVTable
		{
			h3func dtor;
			h3func aiValue;
			h3func conditionMet;
			h3func removeFromHero;
			h3func showMessage1;
			h3func showMessage2;
			h3func objectiveText;
			h3func customText;
			h3func type;
			h3func vt09;
			h3func vt10;
			h3func vt11;
			h3func vt12;
			h3func vt13;
			h3func vt14;
		}*vTable;

		/** @brief [0] */
		// * 0x641798 + questType * 0x3C
		//
		// vt0	dtor
		// vt1	AI value
		// vt2	Condition is met
		// vt3	Remove from hero
		// vt4	Show Message1
		// vt5	Show Message2
		// vt6	Print objective number
		// vt7	Get custom text
		// vt8  GetType 1..9
		// vt9
		// vt10
		// vt11
		// vt12
		// vt13
		// vt14

		/** @brief [4] 0 = quest guard, 1 = seer hut*/
		BOOL hasReward;
		/** @brief [8] */
		H3String messageProposal;
		/** @brief [18] */
		H3String messageProgress;
		/** @brief [28] */
		H3String messageCompletion;
		/** @brief [38] */
		// * texts variant, of no apparent use
		INT32 stringId;
		/** @brief [3C] */
		INT32 lastDay;
		/** @brief [40] size 20h, varies depending on quest type*/
		union QuestData
		{
			INT32 achieveLevel;						// achieve level
			H3PrimarySkills achievePrimarySkill;	// have primary skills
			struct
			{
				INT32 _f_00;
				INT32 targetHero;
				INT32 successfulPlayers;
			} killHero;						// kill certain hero
			struct
			{
				INT32 _f_00;
				UINT32 packedCoords; // H3Position, error C2620 workaround use GetCoordinates()
				INT32 displayCreatureType;
				INT32 player;
			} killMonster;					// kill a monster in certain position on the map
			QuestVector getArtifacts;		// bring artifacts
			struct
			{
				QuestVector number;
				QuestVector type;
			} getCreatures;					// bring creatures
			INT getResources[7];			// bring resources
			INT32 beHero;					// visit as a certain hero
			INT32 bePlayer;					// visit as a certain player
		} data;

		_H3API_ H3Point          GetCoordinates() const;
		_H3API_ eQuest           GetQuestType() const;
		_H3API_ H3Resources&     GetResources();
		_H3API_ H3Vector<INT32>& GetArtifacts();
		_H3API_ H3Vector<INT32>& GetCreatureCounts();
		_H3API_ H3Vector<INT32>& GetCreatureTypes();
	};
	_H3API_ASSERT_SIZE_(H3Quest);

	/** @brief data for quest guards on adventure map*/
	struct H3MapitemQuestGuard
	{
		UINT id;

		_H3API_ H3QuestGuard* Get();
		_H3API_ H3QuestGuard* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)
	/** @brief quest guard is a quest plus a byte to show who visited*/
	struct H3QuestGuard
	{
		_H3API_SIZE_(0x5);
		H3Quest* quest;
		H3PlayersBitfield playersVisited;

		_H3API_ eQuest QuestType() const;
	};
	_H3API_ASSERT_SIZE_(H3QuestGuard);
#pragma pack(pop) /* align-1 */

} /* namespace h3 */
