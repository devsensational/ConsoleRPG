#include "CRMonsterBase.h"
#include "CREventManager.h"
#include "Singleton.h"
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

MonsterBase :: MonsterBase()
{
	
	randHealth = rand() % 11;
	randAttack = rand() % 6;
	
	Singleton<CREventManager<int>>::GetInstance().Subscribe(
		EEventType::EET_MonsterTakeDamage,
		bind(&MonsterBase::TakeDamage, this, placeholders::_1));
}

string MonsterBase::getname() {
	return name;
}

int MonsterBase::GetHealth()
{
	return health;
}
void MonsterBase::Attack() {
	
	Singleton<CREventManager<int>>::GetInstance().Broadcast(
		EEventType::EET_CharacterTakeDamage,
		attack);
}
void MonsterBase::TakeDamage(int damage) {
	health = std::max(0, health - damage);
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("�ƾ�!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(health)));
}

int MonsterBase::MonsterRandHealth(int level) {
	return level * (baseHealth + randHealth);
}

int MonsterBase::MonsterRandAttack(int level) {
	return level * (baseAttack + randAttack);
}