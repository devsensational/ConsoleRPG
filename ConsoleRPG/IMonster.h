#pragma once
#include <string>

class IMonster {
public:
	virtual ~IMonster() = default;

	virtual std::string GetName() const = 0;
	virtual int GetHealth()  = 0;
	virtual int GetAttack()  = 0;
};