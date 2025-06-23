#pragma once

#include "CRCharacter.h"
#include "CRItem.h"

class CRGameManager {
public:
    static CRGameManager* getInstance();

    void startGame();
    void showCharacterStatus(CRCharacter* character);
    void startBattle(CRCharacter* character);
    void battleRound(CRCharacter* character, CRCharacter* monster);

private:
    CRGameManager() {}
    static CRGameManager* instance;
};
