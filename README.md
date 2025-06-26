# ConsoleRPG 프로젝트 분석

> 객체지향 설계 원칙과 디자인 패턴을 활용한 콘솔 기반 턴제 RPG 게임

## 📋 프로젝트 개요

**ConsoleRPG**는 C++로 개발된 콘솔 기반 턴제 RPG 게임으로, 다양한 디자인 패턴과 현대적 C++ 기법을 실제 프로젝트에 적용한 교육적 가치가 높은 프로젝트입니다.

### 🎯 주요 특징
- **객체지향 설계 원칙** 적용 (SOLID)
- **다양한 디자인 패턴** 활용
- **이벤트 기반 아키텍처**
- **모듈화된 시스템 구조**
- **현대적 C++ 기법** 활용

## 🏗️ 아키텍처 구조

### 시스템 계층 구조
```
CRGameSystem (최상위 관리자)
    ├── CRGameMode (게임 로직 관리)
    ├── CRConsoleUI (사용자 인터페이스)
    └── CRCombatManager (전투 시스템)
```

### 의존성 역전 원칙 (DIP) 적용

**상위 → 하위**: 직접 참조, **하위 → 상위**: 인터페이스 참조

```cpp
// 상위 레벨에서 하위 레벨로 직접 참조
class CRGameSystem {
    unique_ptr<ICRGameMode> GameMode;        // 인터페이스 참조
    unique_ptr<CRConsoleUI> GameConsoleUI;   // 구체 클래스 직접 참조
};

class CRGameMode : public ICRGameMode {      // 인터페이스 구현
    shared_ptr<CRCombatManager> CombatManager;  // 구체 클래스 직접 참조
    shared_ptr<CRCharacter> PlayerCharacter;    // 구체 클래스 직접 참조
};
```

## 🎨 적용된 디자인 패턴

### 1. Singleton 패턴 - Thread-Safe 구현
```cpp
template <typename T>
class Singleton {
private:
    inline static std::unique_ptr<T> instance = nullptr;
    inline static std::once_flag initFlag;
public:
    static T& GetInstance() {
        call_once(initFlag, []() { 
            instance = std::make_unique<T>();
        });
        return *instance;
    }
};
```

**특징**:
- `std::call_once` 사용으로 멀티스레드 환경에서 안전
- `unique_ptr`로 자동 메모리 관리
- EventManager, ConsoleRenderer 등에 활용

### 2. Observer 패턴 - 이벤트 시스템
```cpp
template<typename... Args>
class CREventManager {
    using Callback = function<void(Args...)>;
    unordered_map<EEventType, vector<Listener>> listeners;
    
    ListenerID Subscribe(const EEventType& eventName, Callback callback);
    void Broadcast(const EEventType& eventName, Args... args);
};
```

**특징**:
- 템플릿으로 컴파일 타임 타입 체크
- 가변 템플릿으로 다양한 이벤트 타입 지원
- 모듈 간 독립성 확보

### 3. Factory 패턴 - 몬스터 생성
```cpp
class CRMonsterFactory {
public:
    static std::shared_ptr<MonsterBase> CreateMonsterByLevel(int level, int uniqueId);
private:
    static const std::vector<LevelRange> LevelMappings;
};
```

**특징**:
- 레벨 기반 동적 몬스터 생성
- 람다 함수를 활용한 유연한 생성 로직
- 예외 처리 및 메모리 안전성

### 4. Strategy 패턴 - 아이템 시스템
```cpp
class CRItem {
public:
    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};

// 구체적인 전략들
class CRHealthPotion : public CRItem { /* 체력 회복 전략 */ };
class CRAttackBoost : public CRItem { /* 공격력 증가 전략 */ };
```

**특징**:
- 런타임 동작 변경
- 새로운 아이템 효과 쉽게 추가
- 각 아이템의 고유 로직 독립적 관리

## 🔧 현대적 C++ 기법 활용

### 스마트 포인터
```cpp
// shared_ptr 활용
shared_ptr<CRCombatManager> CombatManager;
shared_ptr<CRCharacter> PlayerCharacter;

// unique_ptr 활용
unique_ptr<ICRGameMode> GameMode;
unique_ptr<CRConsoleUI> GameConsoleUI;
```

### 람다 함수와 함수형 프로그래밍
```cpp
// 팩토리에서 람다 함수 활용
const std::vector<LevelRange> CRMonsterFactory::LevelMappings = {
    {1, 2, [](int level, int uniqueId) { return std::make_shared<Slime>(level, uniqueId); }},
    {3, 5, [](int level, int uniqueId) { return std::make_shared<Goblin>(level, uniqueId); }},
};

// 이벤트 구독에서 std::bind 사용
bind(&CRCharacter::Attack, this)
bind(&CRInventory::CreateItem, this, placeholders::_1)
```

### constexpr와 컴파일 타임 최적화
```cpp
class MonsterBase {
private:
    static constexpr int DEFAULT_HEALTH = 100;
    static constexpr int DEFAULT_DAMAGE = 10;
    static constexpr EMonsterAttribute DEFAULT_ATTRIBUTE = EMonsterAttribute::EMA_None;
};
```

## 🎮 다형성을 통한 통합 전투 시스템

### ICRCombat 인터페이스 기반 설계
```cpp
// 공통 전투 인터페이스
class ICRCombat {
    virtual void Act() = 0;
    virtual void TakeDamage(int value) = 0;
    virtual void Attack() = 0;
    virtual int GetUniqueId() = 0;
    virtual EUnitStatus GetUnitStatus() = 0;
};

// Character와 Monster 모두 동일한 인터페이스 구현
class CRCharacter : public ICRCombat { /* 플레이어 구현 */ };
class MonsterBase : public IMonster, public ICRCombat { /* 몬스터 구현 */ };
```

### CombatManager에서의 통합 처리
```cpp
class CRCombatManager {
    unique_ptr<vector<shared_ptr<ICRCombat>>> CombatSequence;
    
    void CombatStart() {
        for (auto& unit : *CombatSequence) {
            if (unit->GetUnitStatus() == EUnitStatus::EUS_Alive) {
                unit->Act();  // 다형성으로 각자의 행동 실행
            }
        }
    }
};
```

## ✨ 설계 특징

### 1. 모듈화된 시스템 구조
- **관심사 분리**: 각 클래스가 명확한 단일 책임
- **느슨한 결합**: 이벤트 시스템으로 모듈 간 독립성 확보
- **높은 응집도**: 관련 기능들이 적절히 그룹화

### 2. 확장성 고려
- **팩토리 패턴**: 새로운 몬스터/아이템 타입 쉽게 추가
- **템플릿 활용**: 타입 안전성과 재사용성 동시 확보
- **인터페이스 기반**: 새로운 구현체 추가 용이

### 3. 안전성 중시
- **예외 처리**: 메모리 할당 실패, 잘못된 입력 등 처리
- **타입 안전성**: 템플릿과 강타입 시스템 활용
- **메모리 안전성**: 스마트 포인터로 자동 메모리 관리

## 🚀 개선 제안사항

### 현재 구조의 장점 유지하면서 개선 가능한 부분
1. **Command 패턴 도입**: 사용자 입력 처리를 더 체계적으로 관리
2. **State 패턴 활용**: 게임 상태(메뉴, 전투, 상점 등) 관리 개선
3. **Template Method 패턴**: 캐릭터 클래스(Warrior, Mage, Rogue)의 공통 행동 패턴화
4. **Configuration 시스템**: 하드코딩된 값들을 설정 파일로 분리

### 캐릭터 상속 구조 활용 개선
```cpp
// 현재: 단순 상속
class CRWarrior : public CRCharacter { void specialMove(); };
class CRMage : public CRCharacter { void castSpell(); };
class CRRogue : public CRCharacter { void stealthAttack(); };

// 개선 제안: Template Method 패턴
class CRCharacter {
    void performSpecialAbility() { // Template Method
        prepareAbility();
        executeAbility(); // 하위 클래스에서 구현
        finishAbility();
    }
    virtual void executeAbility() = 0;
};
```

## 📚 교육적 가치

### 프로젝트의 학습 효과
- **디자인 패턴 실습**: 이론을 실제 코드로 구현
- **객체지향 설계**: SOLID 원칙의 실제 적용 사례
- **현대적 C++**: 스마트 포인터, 템플릿 등 활용법 학습
- **시스템 아키텍처**: 모듈화된 게임 시스템 설계 경험

### 실무 연결성
- **게임 개발**: 실제 게임 엔진에서 사용되는 패턴들
- **소프트웨어 아키텍처**: 확장 가능한 시스템 설계 원칙
- **팀 개발**: 모듈 간 독립성으로 협업 효율성 향상

## 🛠️ 기술 스택

- **언어**: C++17
- **패턴**: Singleton, Observer, Factory, Strategy
- **메모리 관리**: Smart Pointers (unique_ptr, shared_ptr)
- **함수형 프로그래밍**: Lambda, std::bind
- **컴파일 타임 최적화**: constexpr, Templates
