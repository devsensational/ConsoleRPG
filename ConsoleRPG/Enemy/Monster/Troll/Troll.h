#pragma once

#include "../Interface/MonsterInterface.h"
#include <string>

class Troll : public IMonster
{
public:
  Troll(int level);

  std::string GetName() const override;
  int GetHealth() const override;
  int GetAttack() const override;
  void TakeDamage(int damage) override;

private:
  std::string name;
  int health;
  int attack;
};
