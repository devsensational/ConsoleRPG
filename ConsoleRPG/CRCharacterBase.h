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
	// 인터페이스
	void Attack() override;
	void TakeDamage(int value) override;

	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);

	// 캐릭터 상태 변경
	void Heal(int value);
	void Boost(int value);

	void AddItem(unique_ptr<CRItemBase> item);

	/* getter 함수
	int GetHealth() const;
	int GetDamage() const;
	int GetExperience() const;
	int GetGold() const;
	*/
};

