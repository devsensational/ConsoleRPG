#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include <random>

#include "Enemy/Monster/Factory/CRMonsterFactory.h"

class ICRCombat;

using namespace std;

class CRCombatManager
{
public:
	CRCombatManager();


	/* 전투 관련 섹션 */
protected:
	CRMonsterFactory MonsterFactory;
	unique_ptr<vector<shared_ptr<ICRCombat>>> CombatSequence;
	unordered_map<int, shared_ptr<ICRCombat>> PlayerCharacterMap;
	unordered_map<int, shared_ptr<ICRCombat>> MonsterMap;
	vector<shared_ptr<ICRCombat>> PlayerCharacterList;
	vector<shared_ptr<ICRCombat>> MonsterList;


	int PlayerCount = 0;
	int MonsterCount = 0;

public:
	void CombatInit(shared_ptr<ICRCombat> Unit, const int InLevel);
	void CombatStart();
	void CombatEnd();

	void CombatWin();
	void CombatLose();

	void PlayerCharacterAttack(int InDamage);
	void MonsterAttack(int InDamage);
	void PlayerCharacterDead(int InUniqueId);
	void MonsterDead(int InUniqueId);

	int RandomIndexSelector(int InMaxValue);
};

