#pragma once

// nodiscard = 함수의 반환값이 무시되면 안 된다는 것을 명시적으로 나타냅니다.

/**
 * @brief 게임 내 캐릭터들의 체력 정보를 관리하는 구조체
 */
struct MonsterHealthInfo {
    int current;    //< 현재 체력
    int max;        //< 최대 체력

    /**
     * @brief 체력이 0인지 확인
     * @return 체력이 0이면 true, 아니면 false
     */
    bool IsDead() const noexcept {
        return current <= 0;
    }

    /**
     * @brief 현재 체력 비율을 반환
     * @return 현재 체력 / 최대 체력 (0.0 ~ 1.0)
     */
    float GetHealthRatio() const noexcept {
        return max > 0 ? static_cast<float>(current) / max : 0.0f;
    }

    /**
     * @brief 체력이 최대치인지 확인
     * @return 현재 체력이 최대 체력과 같으면 true
     */
    bool IsFullHealth() const noexcept {
        return current >= max;
    }
};
