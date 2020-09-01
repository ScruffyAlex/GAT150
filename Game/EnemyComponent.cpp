#include "pch.h"
#include "EnemyComponent.h"
#include "Components/PhysicsComponent.h"
#include "Objects/GameObject.h"
#include "Objects/Scene.h"

bool nc::EnemyComponent::Create(void* data)
{
	m_owner = static_cast<GameObject*>(data);
	return true;
}

void nc::EnemyComponent::Destroy()
{

}

void nc::EnemyComponent::Update()
{
	GameObject* player = m_owner->m_scene->Find("Player");
	if (player)
	{
		Vector2 direction = player->m_transform.position - m_owner->m_transform.position;
		Vector2 force = direction.Normalized() * 10.0f;

		PhysicsComponent* physicsComponent = m_owner->GetComponent<PhysicsComponent>();
		physicsComponent->ApplyForce(force);
	}
}
