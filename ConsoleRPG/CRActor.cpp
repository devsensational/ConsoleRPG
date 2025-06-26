#include "ConsoleRPG.h"
#include "CRActor.h"
#include "Singleton.h"
#include "CREventManager.h"

// 액터 예시
CRActor::CRActor()
{
	// 구독
	// -> 로 참조한거와 거의 비슷함
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_CharacterTakeDamage, 
		bind(&CRActor::TakeDamage /*함수*/, this /* 본인 인스턴스 */, placeholders::_1 /* 인자 수 마다 증가*/));
}


void CRActor::Act()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("Attack!!"));
}

void CRActor::TakeDamage(int value)
{
	//HP가 감소한다
	hp -= value;
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("아프다!"));
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT(to_string(hp)));
	//cout << hp << '\n';
}
