#pragma once

#include "ICRCombat.h"
#include "CRConsoleRenderer.h"
#include "CRItemBase.h"
#include <vector>

class CRCharacterBase : public ICRCombat
{
private:
	CRCharacterBase(const string& name);

	string Name;
	int Level;
	int Health;
	int MaxHealth;
	int Damage;
	int Experience;
	int Gold;

	vector<unique_ptr<CRItemBase>> Inventory;

public:
	// �������̽�
	void Attack() override;
	void TakeDamage(int value) override;

	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);

	// ĳ���� ���� ����
	void Heal(int value);
	void Boost(int value);

	void AddItem(unique_ptr<CRItemBase> item);

	/* getter �Լ�
	int GetHealth() const;
	int GetDamage() const;
	int GetExperience() const;
	int GetGold() const;
	*/
};

