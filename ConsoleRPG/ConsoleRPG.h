#pragma once

#define TEXT(X) make_shared<string>(X)

enum EEventType
{
	EET_CharacterTakeDamage,// 캐릭터가 데미지를 받을 때 호출(예시: 몬스터가 Attack()으로 Broadcast, 캐릭터가 TakeDamage()를 Subscribe)
	EET_MonsterTakeDamage,	// 몬스터가 데미지를 받을 때 호출
	EET_CombatApply,		// 전투가 수행될 때 호출
	EET_CombatWin,			// 전투에서 승리했을 때 호출
	EET_CombatLose,			// 전투에서 패배했을 때 호출
	EET_SetUserName,		// 닉네임 지정할 때 호출
	EET_CharacterAct,		// 캐릭터가 행동을 지정해야 할 때 호출
	EET_CharacterDead,		// 캐릭터가 사망했을 때 호출
	EET_CharacterAttack,	// 캐릭터가 공격할 때 호출
	EET_StoreOpen,			// 상점 열릴 때 호출
	EET_StoreItemSelect,	// 상점에 있는 아이템을 선택했을 때 호출
	EET_InventoryOpen,		// 인벤토리 목록을 불러올 때 호출
	EET_InventoryItemSelect,// 인벤토리에 있는 아이템을 선택했을 때 호출
	EET_ShowInventoryList,  // 인벤토리 목록을 UI로 보낼 때 호출
	EET_MonsterRandomDrop,	// 몬스터가 아이템을 드랍할 때 호출
	EET_MonsterDead,		// 몬스터가 죽었을 때 호출
	EET_MonsterAttack,		// 몬스터가 공격할 때 호출
	EET_CharacterStatInit,	// 캐릭터 정보를 불러올 때 호출
	EET_MonsterStatInit,	// 몬스터 정보를 불러올 때 호출
	EET_GameOver,			// 게임 종료
	EET_END = 99,
};

enum EUnitStatus
{
	EUS_Default,			// 유닛 디폴트
	EUS_Alive,				// 유닛이 살아 있음
	EUS_Dead,				// 유닛이 사망

	EUS_END = 99,
};