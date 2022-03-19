#pragma once

class Component
{
public:
    virtual ~Component() = default;
    virtual void Update(float deltaTime) = 0;
    virtual void FixedUpdate(float){};
    virtual void OnSleep(){};
    virtual void OnAwake(){};
    virtual void OnDestroy(){};
};