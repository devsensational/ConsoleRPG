#pragma once

//Interface
// 
// MonsterBase랑 CharacterBase에 해당 인터페이스를 적용해서 만드시면 됩니다.
class ICRCombat
{
protected:
	ICRCombat() = default;
public:
	virtual void Attack() = 0;
	virtual void TakeDamage(int value) = 0;
	virtual ~ICRCombat() = default;
};