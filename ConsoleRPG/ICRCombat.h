#pragma once

//Interface
class ICRCombat
{
protected:
	ICRCombat() = default;

public:
	virtual void Attack() = 0;
	virtual void TakeDamage() = 0;

	virtual ~ICRCombat() = default;
};

