#include "ConsoleRPG.h"
#include "CRActor.h"
#include "Singleton.h"
#include "CREventManager.h"

// ���� ����
CRActor::CRActor()
{
	// ����
	// -> �� �����Ѱſ� ���� �����
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_CharacterTakeDamage, 
		bind(&CRActor::TakeDamage /*�Լ�*/, this /* ���� �ν��Ͻ� */, placeholders::_1 /* ���� �� ���� ����*/));
}


void CRActor::Act()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("Attack!!"));
}

void CRActor::TakeDamage(int value)
{
	//HP�� �����Ѵ�
	hp -= value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("������!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(hp)));
	//cout << hp << '\n';
}
