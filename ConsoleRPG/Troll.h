#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "ICRMonsterbase.h"

class CRTroll : ICRMonsterbase
{
	CRTroll(int level)
	{
		name = "Troll";
		hp = monsterrandHP(level);
		attack = monsterrandAttack(level);
	}
	int monsterrandHP(int level) override
	{
		return level * (60 + randHp);
	}
	int monsterrandAttack(int level) override
	{
		return level * (20 + randAttack);
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
		std::cout << "Troll의 공격\n" << "Troll의 공격력 : " << attack << endl;
	}
	void TakeDamage(int damage) override
	{
		hp -= damage;
		std::cout << "Thump! Thump!\n" << "남은 HP : " << hp;
	}

	
};