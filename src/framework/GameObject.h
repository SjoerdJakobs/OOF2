#pragma once
#include <vector>
#include "Component.h"
#include <iostream>

class GameObject final
{
private:
    bool m_IsActive;
    bool m_IsPersistent;

    //Scene* m_CurrentScene;
    GameObject* m_Parent{ nullptr };
    GameObject* m_Child{ nullptr };
    std::vector<Component*> m_Components;
public:

    GameObject();
    ~GameObject();

    void Update(float deltatime);
    void FixedUpdate(float fixedDeltatime);
    void OnSleep();
    void OnAwake();
    void OnDestroy();

    template<typename T>
    T GetComponent()
    {
        for (auto c : m_Components)
        {
            if (dynamic_cast<T>(c) != nullptr)
            {
                return static_cast<T>(c);
            }
        }
        return nullptr;
    }

    template<typename T>
    T DemandComponent()
    {
        if (GetComponent<T>() == nullptr)
        {
            AddComponent<T>();
            return GetComponent<T>();
        }
        else
        {
            return GetComponent<T>();
        }
    }

    template<typename T>
    T AddComponent(T* newComponent)
    {
        m_Components.push_back(newComponent);
    }

    template<typename T>
    T RemoveComponent()
    {
        for (auto c : m_Components)
        {
            if (c != nullptr)
            {
                if (dynamic_cast<T>(c) != nullptr)
                {
                    delete c;
                    c = nullptr;
                }
            }
        }
    }
};