#include "ConsoleRPG.h"
#include "CREventManager.h"
#include "CRCharacterBase.h"
#include "Singleton.h"
using namespace std;

CRCharacterBase::CRCharacterBase(const string& name)
	: Name(name), Level(1), Health(200), MaxHealth(200), Damage(30), Experience(0), Gold(0)
	// 이름, 레벨, 체력, 최대체력, 공격력, 경험치, 골드 순
{
	
	// 구독
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EventType::CharacterTakeDamage,
		bind(&CRCharacterBase::TakeDamage, this, placeholders::_1 /* 인자 수 마다 증가*/));
}


void CRCharacterBase::Attack()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("Attack!!"));
}

void CRCharacterBase::TakeDamage(int value)
{
	//체력 감소
	Health -= value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("아프다!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(Health)));
	//cout << hp << '\n'; 와 같은 효과
}

// Name(name), Level(1), Health(200), MaxHealth(200), Damage(30), Experience(0), Gold(0)
void CRCharacterBase::DisplayStatus()
{
	cout << "이름: " << Name << endl;
	cout << "레벨: " << Level << endl;
	cout << "체력: " << Health << " / " << MaxHealth << endl;
	cout << "공격력: " << Damage << endl;
	cout << "경험치: " << Experience << " / 100" << endl;
	cout << "골드: " << Gold << endl;
}

void CRCharacterBase::LevelUp()
{
	Level += 1;
	Experience = 0;
}

void CRCharacterBase::UseItem(int index)
{
	Inventory[index]->Use(this);
}

void CRCharacterBase::Heal(int value)
{
	Health += value;
	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("체력이 회복되었습니다!"));
}

void CRCharacterBase::Boost(int value)
{
	Damage += value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("공격력이 " + to_string(value) + " 증가했습니다!"));
}

void CRCharacterBase::AddItem(unique_ptr<CRItemBase> item)
{
	Inventory.emplace_back(move(item));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(item->Name + "을(를) 획득!"));
}
