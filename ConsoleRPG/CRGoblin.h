#pragma once
#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "ICRMonsterbase.h"
#include <iostream>


class CRGoblin : public ICRMonsterbase
{
public:
	CRGoblin(int level)
	{
		name = "Goblin";
		hp = monsterrandHP(level);
		attack = monsterrandAttack(level);
	}
	int monsterrandHP(int level)
	{
		return level * (20 + randHp);
	}
	int monsterrandAttack(int level)
	{		
		return level * (5 + randAttack);
	}
	
	std::string getname() 
	{
		return name;
	}
	
	int getHP() 
	{
		return hp;
	}
	
	void Attack() 
	{
		std::cout << "Goblin의 공격\n" << "Goblin의 공격력 : " << attack << endl;
	}
	
	void TakeDamage(int damage) 
	{
		hp -= damage;
		std::cout << "Ugh~~\n" << "남은 HP : " << hp;
	}
};