#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "ICRMonsterbase.h"

class CRSlime : ICRMonsterbase
{
	CRSlime(int level)
	{
		name = "Slime";
		hp = monsterrandHP(level);
		attack = monsterrandAttack(level);
	}
	int monsterrandHP(int level) override
	{
		return level * (30 + randHp);
	}
	int monsterrandAttack(int level) override
	{
		return level * (3 + randAttack);
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
		std::cout << "Slime�� ����\n" << "Slime�� ���ݷ� : " << attack << endl;
	}
	void TakeDamage(int damage) override
	{
		hp -= damage;
		std::cout << "poing~ poing~~\n" << "���� HP : " << hp;
	}
	
};