#pragma once

#define TEXT(X) make_shared<string>(X)

enum EEventType
{
	/*
	*	캐릭터가 데미지를 받을 때 호출(예시: 몬스터가 Attack()으로 Broadcast, 캐릭터가 TakeDamage()를 Subscribe)
	*/
	EET_CharacterTakeDamage = 0, 
	/*
	*	몬스터가 데미지를 받을 때 호출
	*/
	EET_MonsterTakeDamage,
	

	EET_END = 99,
};