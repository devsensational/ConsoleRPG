#pragma once

/**
 * @brief 게임에 존재하는 몬스터 타입을 정의하는 열거형
 * 
 * 게임 내의 모든 생성 가능한 몬스터 타입을 정의합니다.
 * 새로운 몬스터를 추가할 때는 이 열거형에 해당 타입을 추가해야 합니다.
 * 
 * @note 각 몬스터 타입은 고유한 특성과 능력을 가지고 있습니다 (추가 개발 예정)
 */
enum class EMonsterType
{
  /* 트롤 */
  EMT_Troll,

  /* 오크 */
  EMT_Orc,

  /* 고블린 */
  EMT_Goblin,

  /* 슬라임 */
  EMT_Slime
};