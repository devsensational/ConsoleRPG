#pragma once

#include "../../../ICRCombat.h"
#include "../../../Singleton.h"
#include "../../../CREventManager.h"
#include "../Struct/CRMonsterHealthInfo.h"
#include "IMonster.h"
#include <string>
#include <algorithm>

/**
 * noexcept 사용시 함수가 예외를 던지지 않음을 명시적으로 선언하는 키워드
 * 
 * constexpr는 C++에서 **"컴파일 타임에 값을 계산할 수 있다"**는 걸 컴파일러에게 알려주는 키워드입니다.
 * 즉, 상수인데, 빠르고 똑똑한 상수
 * 주의사항: constexpr는 무조건 쓰는 게 아니라, 딱 "컴파일 타임에 계산되면 이득인 상황"에서만 쓰는 게 효과적.
 **/

/**
 * @brief 기본 몬스터 클래스
 * 
 * 게임 내 모든 몬스터의 기본이 되는 클래스입니다.
 * 기본적인 몬스터의 상태와 행동을 정의합니다.
 * 
 * @note 이 클래스는 IMonster와 ICRCombat 인터페이스를 구현합니다
 * @see IMonster
 * @see ICRCombat
 */
class MonsterBase : public IMonster, public ICRCombat
{
private:
    // @brief 기본 체력값 상수
    static constexpr int DEFAULT_HEALTH = 100;
    // @brief 기본 공격력 상수
    static constexpr int DEFAULT_DAMAGE = 10;

protected:
    std::string Name;   //< 몬스터의 이름
    int UniqueId;       // 식별용 ID
    int CurrentHealth;  //< 현재 체력
    int MaxHealth;      //< 최대 체력
    int MonsterDamage;  //< 공격력

    EUnitStatus Status = EUnitStatus::EUS_Alive;
    vector<int> EventIds; // Event Id 저장용

public:
    /**
     * @brief 몬스터 생성자
     * 
     * @param monsterName 몬스터의 이름 (기본값: 빈 문자열)
     * @note 모든 기본 스탯은 상수값으로 초기화됩니다
     */
    explicit MonsterBase(const std::string& monsterName = "", const int& uniqueId = 0)
        : Name(monsterName)
        , UniqueId(uniqueId)
        , CurrentHealth(DEFAULT_HEALTH)
        , MaxHealth(DEFAULT_HEALTH)
        , MonsterDamage(DEFAULT_DAMAGE)
    {
        //EventIds.push_back(Singleton<CREventManager<int>>::GetInstance()
        //    .Subscribe(EEventType::EET_MonsterTakeDamage, bind(&MonsterBase::TakeDamage, this, placeholders::_1)));
        Status = EUnitStatus::EUS_Alive;
    }

    // @brief 가상 소멸자
    virtual ~MonsterBase() = default;

    /**
     * 
     * @brief 이동 생성자
     * @note noexcept 보장으로 예외 안전성 제공
     */
    MonsterBase(MonsterBase&&) noexcept = default;

    /**
     * @brief 이동 대입 연산자
     * @return MonsterBase& 이동된 객체에 대한 참조
     * @note noexcept 보장으로 예외 안전성 제공
     */
    MonsterBase& operator=(MonsterBase&&) noexcept = default;

    /**
     * @brief 몬스터의 이름을 반환
     * 
     * @return std::string 몬스터의 이름
     * @note 이 메서드는 예외를 발생시키지 않습니다
     */
    std::string GetName() const noexcept override
    {
        return Name;
    }

    /**
     * @brief 몬스터의 현재 체력을 반환
     * 
     * @return int 현재 체력값
     * @note 이 메서드는 예외를 발생시키지 않습니다
     */
    int GetCurrentMonsterHealth() const noexcept override
    {
        return CurrentHealth;
    }

    /**
     * @brief 몬스터의 최대 체력을 반환
     * 
     * @return int 최대 체력값
     * @note 이 메서드는 예외를 발생시키지 않습니다
     */
    int GetMaxMonsterHealth() const noexcept override
    {
        return MaxHealth;
    }

    /**
     * @brief 몬스터가 데미지를 받는 함수
     * 
     * @param value 받을 데미지 양
     * @note 음수 데미지는 무시됩니다
     * @note 체력은 0과 최대체력 사이로 제한됩니다
     */
    void TakeDamage(int value) override {
        CurrentHealth = std::clamp(CurrentHealth - value, 0, MaxHealth);

        Singleton<CREventManager<string, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_MonsterStatInit, Name, CurrentHealth, MaxHealth);

        if (CurrentHealth <= 0) Dead();

        //cout << "TakeDamage: " << value << endl;
        //cout << "CurrentHP: " << CurrentHealth << endl;
    }

    void Act() override {
        Attack();
    }

    /**
     * @brief 몬스터의 공격 함수
     *
     * 이벤트 시스템을 통해 캐릭터에게 데미지를 전달합니다.
     * @note EET_CharacterTakeDamage 이벤트를 발생시킵니다
     * @see CREventManager
     */
    void Attack() override
    {
        Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_MonsterAttack, MonsterDamage);
    }
    

    /**
     * @brief 몬스터의 현재 체력 정보를 반환
     * 
     * @return HealthInfo + CurrentHealth, MaxHealth (현재 체력과 최대 체력을 포함한 구조체)
     * @note 이 메서드는 예외를 발생시키지 않습니다
     */
    MonsterHealthInfo GetHealthInfo() const noexcept
    {
        return { CurrentHealth, MaxHealth };
    }

    void Dead() override
    {
        if (Status == EUnitStatus::EUS_Dead) return; // 이미 죽었으면 아무것도 하지 않음

        cout << Name << "이(가) 죽었다!" << '\n';
        Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_MonsterDead, UniqueId);
        //Singleton<CREventManager<int>>::GetInstance().Unsubscribe(EEventType::EET_MonsterTakeDamage, EventIds[0]);
        Status = EUnitStatus::EUS_Dead;
    }

    inline int GetUniqueId() override { return UniqueId; }
    inline EUnitStatus GetUnitStatus() override { return Status; }
};