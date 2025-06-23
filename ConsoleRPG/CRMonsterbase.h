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
	std::string getname() 
	{
		return name;
	}
	int GetHealth() override 
	{
		return health;
	}
	void Attack() override 
	{
		Singleton<CREventManager<int>>::GetInstance().Subscribe(EventType::CharacterTakeDamage,
			bind(&MonsterBase::TakeDamage, this, placeholders::_1));
	}
	
	void TakeDamage(int damage) override
	{
		health = std::max(0, health - damage);
	}

	//몬스터 체력 공격력 랜덤 함수
	virtual int MonsterRandHealth(int level) = 0;
	virtual int MonsterRandAttack(int level) = 0;
protected:
	std::string name;
	int health = 0 ;
	int attack= 0 ;
	int randHealth = 0;
	int randAttack = 0;

	MonsterBase()
	{
		randHealth = rand() % 11;
		randAttack = rand() % 6;
	}
};
