#pragma once

#define TEXT(X) make_shared<string>(X)

enum EventType
{
	CharacterTakeDamage = 0,

	end = 99,
};