#pragma once

#define TEXT(X) make_shared<string>(X)

enum EEventType
{
	EET_CharacterTakeDamage = 0, // 캐릭터가 공격 받았을 때 호출되는 이벤트
	

	end = 99,
};