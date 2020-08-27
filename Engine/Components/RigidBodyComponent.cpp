#include "pch.h"
#include "RigidBodyComponent.h"

namespace nc {

	bool RigidBodyComponent::Create(void* data)
	{
		m_owner = static_cast<GameObject*>(data);
		return true;
	}

	void RigidBodyComponent::Destroy()
	{
	}

	void RigidBodyComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value,"isDynamic", m_data.isDynamic);
		json::Get(value,"lockAngle", m_data.lockAngle);
		json::Get(value,"size", m_data.size);
		json::Get(value,"density", m_data.density);
		json::Get(value,"friction", m_data.friction);
		json::Get(value, "restitution", m_data.restitution);
	}

	void RigidBodyComponent::Update()
	{
		if (m_body == nullptr)
		{
			m_body = m_owner->m_engine->GetSystem<PhysicsSystem>()->CreateBody(m_owner->m_transform.position,m_data,m_owner);
			m_body->SetTransform(m_owner->m_transform.position, nc::DegreesToRadians( m_owner->m_transform.angle));
		}

		m_owner->m_transform.position = m_body->GetPosition();
		m_owner->m_transform.angle = nc::RadiansToDegrees( m_body->GetAngle());
	}

	void RigidBodyComponent::SetForce(const Vector2& force)
	{
		m_body->ApplyLinearImpulseToCenter(force, true);
	}

}
