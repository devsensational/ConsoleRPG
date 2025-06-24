#pragma once

class ICRGameMode
{
protected:
	ICRGameMode() = default;

public:
	virtual void GameStart() = 0;

	virtual ~ICRGameMode() = default;
};