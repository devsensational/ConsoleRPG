#include "CRCombatManager.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRGameMode.h"
#include "Enemy/Monster/Slime/CRSlime.h"
#include "Enemy/Monster/Goblin/CRGoblin.h"

CRCombatManager::CRCombatManager()
{
	CombatSequence = make_unique<vector<shared_ptr<ICRCombat>>>();

	// 플레이어 캐릭터 중 하나가 죽었을 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterDead, bind(&CRCombatManager::PlayerCharacterDead, this, placeholders::_1));
	// 몬스터 중 하나가 죽었을 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterDead, bind(&CRCombatManager::MonsterDead, this, placeholders::_1));
	// 플레이어가 공격을 시도할 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterAttack, bind(&CRCombatManager::PlayerCharacterAttack, this, placeholders::_1));
	// 몬스터가 공격을 시도할 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterAttack, bind(&CRCombatManager::MonsterAttack, this, placeholders::_1));
	
}

/*
* 전투(Combat)을 초기화합니다.
* CombatSequence에 유닛들을 추가합니다.
*/
void CRCombatManager::CombatInit(const shared_ptr<ICRCombat> Unit, const int InLevel)
{
	PlayerCharacterMap[Unit->GetUniqueId()] = Unit;
	PlayerCount = PlayerCharacterMap.size();
	PlayerCharacterList.push_back(Unit);
	CombatSequence->push_back(Unit);

	shared_ptr<ICRCombat> MonsterTemp = make_shared<Slime>(InLevel, 1);
	MonsterMap[MonsterTemp->GetUniqueId()] = MonsterTemp;
	MonsterList.push_back(MonsterTemp);
	MonsterCount = MonsterMap.size();
	CombatSequence->push_back(MonsterTemp);
	
	MonsterTemp = make_shared<Slime>(InLevel, 2);
	MonsterMap[MonsterTemp->GetUniqueId()] = MonsterTemp;
	MonsterList.push_back(MonsterTemp);
	MonsterCount = MonsterMap.size();
	//Todo: 내 캐릭터와 적이 될 유닛들을 생성 후 CombatSequence에 추가해야 함, 또한 행동력 수치가 있다면 행동력 수치를 기준으로 정렬
}

/*
* CombatSequence의 순서에 따라 모든 유닛이 공격을 수행합니다.
* ICRCombat을 통해 Attack()을 호출합니다.
*
*/
void CRCombatManager::CombatStart()
{
	if (CombatSequence->empty()) return;

	for (int i = 0; i < CombatSequence->size(); i++)
	{
		//cout << i << "번째 행동대기" << '\n';
		if ((*CombatSequence)[i]->GetUnitStatus() == EUnitStatus::EUS_Alive)
		{
			//cout << i << "번째 공격시도!" << '\n';
			(*CombatSequence)[i]->Attack();
		}

	}
}

/*
* Combat의 주기가 모두 종료됐을 때 호출됩니다.
* CombatSquence를 초기화합니다.
*/
void CRCombatManager::CombatEnd()
{
	//Singleton<CREventManager<>>::GetInstance().Broadcast("CombatEnd");
	CombatSequence->clear();
	PlayerCharacterMap.clear();
	PlayerCharacterList.clear();
	MonsterMap.clear();
	MonsterList.clear();

}

void CRCombatManager::CombatWin()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatWin);
	CombatEnd();
}

void CRCombatManager::CombatLose()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatLose);
	CombatEnd();
}

void CRCombatManager::PlayerCharacterAttack(int InDamage)
{
	int idx = RandomIndexSelector(MonsterList.size() - 1);

	if (MonsterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	cout << "몬스터를 공격!" << '\n';
	MonsterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::MonsterAttack(int InDamage)
{
	int idx = RandomIndexSelector(PlayerCharacterList.size() - 1);
	if (PlayerCharacterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	cout << "플레이어를 공격!2" << '\n';
	PlayerCharacterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::PlayerCharacterDead(int UniqueId)
{
	PlayerCount--;
	if (PlayerCount <= 0) CombatLose();
}

void CRCombatManager::MonsterDead(int UniqueId)
{
	MonsterCount--;
	if (MonsterCount <= 0) CombatWin();
}

int CRCombatManager::RandomIndexSelector(int InMaxValue)
{
	random_device rd;                     // 하드웨어 시드 기반 난수 생성기
	mt19937 gen(rd());                    
	uniform_int_distribution<> dist(0, InMaxValue); // [0, InMaxValue] 범위 정수 랜덤

	return dist(gen);
}
