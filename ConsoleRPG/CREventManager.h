// 작성자: 김선호

#pragma once

#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

template<typename... Args>
class CREventManager
{
public:
    using Callback = std::function<void(Args...)>;
    using ListenerID = int;

    struct Listener
    {
        ListenerID id;
        Callback callback;
    };

    // 콜백 등록, 고유 ID 반환
    ListenerID Subscribe(const std::string& eventName, Callback callback)
    {
        ListenerID id = nextId++;
        listeners[eventName].push_back({ id, callback });
        return id;
    }

    // 콜백 제거
    void Unsubscribe(const std::string& eventName, ListenerID id)
    {
        auto& vec = listeners[eventName];
        vec.erase(std::remove_if(vec.begin(), vec.end(),
            [id](const Listener& l) { return l.id == id; }),
            vec.end());
    }

    // 이벤트 발생
    void Broadcast(const std::string& eventName, Args... args)
    {
        auto it = listeners.find(eventName);
        if (it != listeners.end())
        {
            for (const auto& listener : it->second)
            {
                listener.callback(args...);
            }
        }
    }

private:
    std::unordered_map<std::string, std::vector<Listener>> listeners;
    ListenerID nextId = 0;
};

