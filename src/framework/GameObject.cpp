#include "GameObject.h"

GameObject::GameObject():m_IsActive(true),m_IsPersistent(false)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update(float deltatime)
{
	for (auto c : m_Components)
	{
		c->Update(deltatime);
	}
}

void GameObject::FixedUpdate(float fixedDeltatime)
{
	for (auto c : m_Components)
	{
		c->FixedUpdate(fixedDeltatime);
	}
}

void GameObject::OnSleep()
{
	for (auto c : m_Components)
	{
		c->OnSleep();
	}
}

void GameObject::OnAwake()
{
	for (auto c : m_Components)
	{
		c->OnAwake();
	}
}

void GameObject::OnDestroy()
{
	for (auto c : m_Components)
	{
		c->OnDestroy();
	}
}
