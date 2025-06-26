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
  EMT_Slime,

  EMT_Dragon
};

/**
 * @brief 몬스터 속성을 정의하는 열거형
 *
 * 게임 내의 몬스터들이 가질 수 있는 다양한 속성을 정의합니다.
 * 각 속성은 특정 특성과 상호작용을 나타내며, 전투 및 게임 메커니즘에 영향을 미칠 수 있습니다.
 *
 * @note 속성은 몬스터의 공격이나 방어, 특정 조건에서의 성능에 영향을 줄 수 있습니다.
 */
enum class EMonsterAttribute
{
  /* 속성없음 */
  EMA_None,

  /* 불속성 */
  EMA_Fire,

  /* 물속성 */
  EMA_Water,

  /* 땅속성 */
  EMA_Earth,

  /* 바람속성 */
  EMA_Wind,

  /* 독속성 */
  EMA_Poison
};