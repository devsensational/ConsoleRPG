//작성자: 김선호

#include "CRGameSystem.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRConsoleRenderer.h"

/*	클래스 설명:
*	게임을 초기화하고, LIfecycle을 관리하기 위한 클래스입니다.
*/

CRGameSystem::CRGameSystem()
{
	mapCreator = make_unique<CRMapCreator>();
	grid = mapCreator->CreateNewMap(5, 5);
}

void CRGameSystem::GameStart()
{
	LIfecycle();
}

void CRGameSystem::LIfecycle()
{
	while (!bEndSignal)
	{
		Singleton<CRConsoleRenderer>::GetInstance().RenderMap(grid);

		int n;
		cin >> n;
	}
}

void CRGameSystem::GameEnd()
{
	bEndSignal = true;
}
