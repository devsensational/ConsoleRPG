### :흰색_확인_표시: **프로젝트 기반 테스트 케이스 점검표**
| **테스트 제목**       | **테스트 절차 (프로젝트 흐름 기준)**                                                                                         | **케이스 분류** | 필수/도전 | 구현 상태        |
| ---------------- | --------------------------------------------------------------------------------------------------------------- | ---------- | ----- | ------------ |
| 캐릭터 생성 테스트       | `CRGameMode::SetUserName()`에서 이름 입력 → `CRCharacter` 객체 생성 → `GameMode`에 등록                                      | Normal     | 필수    | :white_check_mark: 정상 구현됨     |
| 캐릭터 이름 공백 입력     | 공백/빈 문자열 입력 시 재입력 요구 없음                                                | Abnormal   | 필수    |  :white_check_mark: 정상 구현됨     |
| 초기 상태 확인 테스트     | `CRCharacter` 초기 상태는 생성자에서 지정.                     | Normal     | 필수    |  :white_check_mark: 정상 구현됨   |
| 전투 시스템 테스트       | `CRCombatManager::CombatInit()` → 유닛 등록 → `Act() → Attack() → TakeDamage()` 순서로 전투 흐름 진행. 이벤트 시스템 기반으로 UI/HP 반영 | Normal     | 필수    |  :white_check_mark: 정상 구현됨      |
| 전투 승리 보상 테스트     | `CombatWin()` 호출 → 보상 로직 (`GetExp()`, `GetGold()`)                                           | Normal     | 필수    | :white_check_mark: 정상 구현됨    |
| 전투 패배 종료 테스트     | `PlayerCharacterDead()` → `PlayerCount==0` 확인 → `CombatLose()` → `GameOver()` 이벤트 브로드캐스트                        | Normal     | 필수    |  :white_check_mark: 정상 구현됨      |
| 레벨업 테스트          | `GetExp()` 누적 → 100 도달 시 `LevelUp()` 호출 → `HP`, `Damage` 증가.                        | Normal     | 필수    |  :white_check_mark: 정상 구현됨 |
| 최대 레벨 보스전 테스트    | `GameLevel >= 10`일 경우 `CRDragon` 생성됨 (`CRMonsterFactory::CreateMonsterByLevel`) → `CombatWin()` 시 클리어           | Normal     | 도전    |  :white_check_mark: 정상 구현됨        |
| 상점 이용 테스트        | `EET_StoreOpen` → `PrintStoreMenu()` → 입력값으로 `CreateItem()` 실행 → 아이템 인벤토리에 정상 추가됨                               | Normal     | 도전    |  :white_check_mark: 정상 구현됨        |
| 골드 소비 테스트        | 상점 구매 시 골드 차감                                          | Abnormal   | 도전    |  :white_check_mark: 정상 구현됨        |
| 몬스터 처치 후 아이템 드랍  | `Dead()` 호출 시 `EET_MonsterDead` 발생. 드랍 이벤트 호출                                    | Normal     | 도전    |  :white_check_mark: 정상 구현됨        |
| 전투 중 인벤토리 사용 테스트 | 전투 중 `"2. 인벤토리"` 선택 → `PrintInventory()` → 선택 시 `useItem()` 호출 → 힐 or 공격력 상승 기능 동작                              | Normal     | 도전    |  :white_check_mark: 정상 구현됨        |
