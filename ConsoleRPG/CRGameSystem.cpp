//�ۼ���: �輱ȣ

#include "CRGameSystem.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRConsoleRenderer.h"

/*	Ŭ���� ����:
*	������ �ʱ�ȭ�ϰ�, LIfecycle�� �����ϱ� ���� Ŭ�����Դϴ�.
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
