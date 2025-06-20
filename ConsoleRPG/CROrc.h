#pragma once
#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "ICRMonsterbase.h"



class CROrc : public ICRMonsterbase 
{
	CROrc(int level)
	{
		name = "Orc";
		hp = monsterrandHP(level);
		attack = monsterrandAttack(level);

	}
	int monsterrandHP(int level) override
	{
		return level * (40 + randHp);
	}
	int monsterrandAttack(int level) override
	{
		return level * (10 + randAttack);
	}
	// ICRMonsterbase을(를) 통해 상속됨
	std::string getname() override
	{
		return name;
	}
	int GetHP() override
	{
		return hp;
	}

	void Attack() override
	{
		std::cout << "Orc의 공격\n" << "Orc의 공격력 : " << attack << endl;
	}
	void TakeDamage(int damage) override
	{
		hp -= damage;
		std::cout << "Orc!! Orc!!\n" << "남은 HP : " << hp;
	}
};