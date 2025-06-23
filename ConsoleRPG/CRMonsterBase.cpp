#include "CRMonsterBase.h"
#include "CREventManager.h"
#include "Singleton.h"
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

MonsterBase :: MonsterBase()
{
	//랜덤 수치 생성
	randHealth = rand() % 11;
	randAttack = rand() % 6;
	//구독 : 몬스터가 데미지 받을 때 호출되는 이벤트에 등록
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
	// 브로드캐스트: 캐릭터가 데미지를 받도록 알림
	Singleton<CREventManager<int>>::GetInstance().Broadcast(
		EEventType::EET_CharacterTakeDamage,
		attack);
}
void MonsterBase::TakeDamage(int damage) {
	health = std::max(0, health - damage);
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("아야!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(health)));
}

int MonsterBase::MonsterRandHealth(int level) {
	return level * (baseHealth + randHealth);
}

int MonsterBase::MonsterRandAttack(int level) {
	return level * (baseAttack + randAttack);
}