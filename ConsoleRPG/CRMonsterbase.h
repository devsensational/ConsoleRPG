#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "IMonster.h"
#include "CREventManager.h"
#include <cstdlib>


class MonsterBase : public IMonster,ICRCombat
{
public:
	virtual ~MonsterBase() = default;
	
	std::string getname();
	int GetHealth() override;
	void Attack() override;
	void TakeDamage(int damage) override;

	//몬스터 체력 공격력 랜덤 함수
	virtual int MonsterRandHealth(int level);
	virtual int MonsterRandAttack(int level);

protected:
	MonsterBase();
	std::string name;
	int health = 0 ;
	int attack= 0 ;

	int baseHealth = 0;
	int baseAttack = 0;

	int randHealth = 0;
	int randAttack = 0;

};
