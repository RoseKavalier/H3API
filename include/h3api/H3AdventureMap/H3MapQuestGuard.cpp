//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapQuestGuard.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3QuestGuard* H3MapitemQuestGuard::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3QuestGuard* H3MapitemQuestGuard::Get(H3Main* main)
	{
		return &main->mainSetup.questGuards[id];
	}
	_H3API_ INT32 H3Quest::QuestVector::Count()
	{
		return last - first;
	}
	_H3API_ INT32& H3Quest::QuestVector::operator[](INT32 index)
	{
		return first[index];
	}
	_H3API_ INT32* H3Quest::QuestVector::begin()
	{
		return first;
	}
	_H3API_ INT32* H3Quest::QuestVector::end()
	{
		return last;
	}
	_H3API_ H3Point H3Quest::GetCoordinates() const
	{
		H3Position pos(data.killMonster.packedCoords);
		return pos.Unpack();
	}
	_H3API_ eQuest H3Quest::GetQuestType() const
	{
		return THISCALL_1(eQuest, vTable->type, this);
	}
	_H3API_ H3Resources& H3Quest::GetResources()
	{
		return *reinterpret_cast<H3Resources*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetArtifacts()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetCreatureCounts()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data);
	}
	_H3API_ H3Vector<INT32>& H3Quest::GetCreatureTypes()
	{
		return *reinterpret_cast<H3Vector<INT32>*>(&data.getCreatures.type);
	}
	_H3API_ eQuest H3QuestGuard::QuestType() const
	{
		return quest ? quest->GetQuestType() : eQuest::NONE;
	}

} /* namespace h3 */
