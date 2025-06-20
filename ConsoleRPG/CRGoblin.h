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
		std::cout << "Goblin�� ����\n" << "Goblin�� ���ݷ� : " << attack << endl;
	}
	
	void TakeDamage(int damage) 
	{
		hp -= damage;
		std::cout << "Ugh~~\n" << "���� HP : " << hp;
	}
};