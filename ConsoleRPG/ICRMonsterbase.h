#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include <cstdlib>


class ICRMonsterbase : public ICRCombat
{
public:
	virtual void Attack() ;
	virtual void TakeDamage(int damage) override;
	virtual std::string getname() = 0;
	virtual int GetHP() = 0;
	virtual int monsterrandHP(int level) = 0;
	virtual int monsterrandAttack(int level) = 0;
protected:
	std::string name;
	int hp = 0 ;
	int attack= 0 ;
	int randHp=  0;
	int randAttack = 0  ;

	ICRMonsterbase()
	{
		randHp = rand() % 11;
		randAttack = rand() % 6;
	}
};
