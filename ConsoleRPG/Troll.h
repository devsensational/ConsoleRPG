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
	// ICRMonsterbase��(��) ���� ��ӵ�
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
		std::cout << "Troll�� ����\n" << "Troll�� ���ݷ� : " << attack << endl;
	}
	void TakeDamage(int damage) override
	{
		hp -= damage;
		std::cout << "Thump! Thump!\n" << "���� HP : " << hp;
	}

	
};