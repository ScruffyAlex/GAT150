#include "pch.h"
#include "PhysicsComponent.h"
#include "Objects/GameObject.h"

bool nc::PhysicsComponent::Create(void* data)
{
	return true;
}

void nc::PhysicsComponent::Destroy()
{
}

void nc::PhysicsComponent::Update()
{
	m_velocity = m_velocity + m_force * m_owner->m_engine->GetTimer().DeltaTime();// *timer.DeltaTime();
	m_velocity = m_velocity * m_drag;
	m_owner->m_transform.position = m_owner->m_transform.position + m_velocity * m_owner->m_engine->GetTimer().DeltaTime();// *timer.DeltaTime();
}