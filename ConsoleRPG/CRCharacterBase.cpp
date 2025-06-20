#include "ConsoleRPG.h"
#include "CREventManager.h"
#include "CRCharacterBase.h"
#include "Singleton.h"
using namespace std;

CRCharacterBase::CRCharacterBase(const string& name)
	: Name(name), Level(1), Health(200), MaxHealth(200), Damage(30), Experience(0), Gold(0)
	// �̸�, ����, ü��, �ִ�ü��, ���ݷ�, ����ġ, ��� ��
{
	
	// ����
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EventType::CharacterTakeDamage,
		bind(&CRCharacterBase::TakeDamage, this, placeholders::_1 /* ���� �� ���� ����*/));
}


void CRCharacterBase::Attack()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("Attack!!"));
}

void CRCharacterBase::TakeDamage(int value)
{
	//ü�� ����
	Health -= value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("������!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(Health)));
	//cout << hp << '\n'; �� ���� ȿ��
}

// Name(name), Level(1), Health(200), MaxHealth(200), Damage(30), Experience(0), Gold(0)
void CRCharacterBase::DisplayStatus()
{
	cout << "�̸�: " << Name << endl;
	cout << "����: " << Level << endl;
	cout << "ü��: " << Health << " / " << MaxHealth << endl;
	cout << "���ݷ�: " << Damage << endl;
	cout << "����ġ: " << Experience << " / 100" << endl;
	cout << "���: " << Gold << endl;
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
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("ü���� ȸ���Ǿ����ϴ�!"));
}

void CRCharacterBase::Boost(int value)
{
	Damage += value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("���ݷ��� " + to_string(value) + " �����߽��ϴ�!"));
}

void CRCharacterBase::AddItem(unique_ptr<CRItemBase> item)
{
	Inventory.emplace_back(move(item));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(item->Name + "��(��) ȹ��!"));
}
