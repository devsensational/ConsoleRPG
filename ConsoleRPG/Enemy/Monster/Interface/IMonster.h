#pragma once
#include <string>

class IMonster {
public:
  virtual ~IMonster() = default;

  virtual std::string GetName() const = 0;
  virtual int GetCurrentMonsterHealth() const = 0;
  virtual int GetMaxMonsterHealth() const = 0;
  virtual int GetAttack() const = 0;
};
