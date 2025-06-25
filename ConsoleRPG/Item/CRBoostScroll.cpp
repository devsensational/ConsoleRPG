#include "CRBoostScroll.h"
#include "../Character/CRCharacter.h"
#include <iostream>
#include <random>
using namespace std;

/*
 *다른 곳에서도 쓸거라면
 *유틸리티 클래스나 네임스페이스화 필요
 */
int getRandom(int min, int max) // 랜덤 숫자
{
    static random_device rd; // static 으로 랜덤생성기 1번만 초기화
    static mt19937 gen(rd()); // 높은 품질의 난수
    uniform_int_distribution<> dis(min, max); // 균일한 확률 분포 보장
    return dis(gen);
}

void CRBoostScroll::use(CRCharacter* character)
{
    cout << "강화를 시도합니다.. " << endl;
    /*
     *boostChance = 강화확률이고
     *getRandom(1,100) 이 1부터 100 중에 숫자를 균일한 확률로 반환(1%)
     *ex) boostChance=30 이면 getRandom이 <= 30 일 확률은 균일하게 30%
     */
    if (getRandom(1, 100) <= boostChance)
    {
        cout << "강화 성공!" << endl;
        character->takeAttackBoost(defaultAmount);
    }
    else
    {
        cout << "강화 실패.." << endl;
    }
}