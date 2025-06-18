#include "ConsoleRPG.h"
#include "CRActor.h"
#include "Singleton.h"
#include "CREventManager.h"

CRActor::CRActor()
{
	Singleton<CREventManager<>>::GetInstance().Subscribe("TakeDamage", bind(&CRActor::TakeDamage, this));
}

void CRActor::Attack()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("Attack!!"));
}

void CRActor::TakeDamage()
{
	Singleton<CRConsoleRenderer>::GetInstance().AddBuffer(TEXT("¾ÆÇÁ´Ù!"));
}
