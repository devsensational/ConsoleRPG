#pragma once

// Interface
// 
// MonsterBase�� CharacterBase�� �ش� �������̽��� �����ؼ� ����ø� �˴ϴ�.
class ICRCombat
{
protected:
	ICRCombat() = default;

public:
	virtual void Attack() = 0;
	virtual void TakeDamage(int value) = 0;

	virtual ~ICRCombat() = default;
};
