#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SpriteComponent.h"
#include "Core/EventManager.h"

namespace nc {

	bool nc::PlayerComponent::Create(void* data)
	{
		m_owner = static_cast<GameObject*>(data);

		EventManager::Instance().Subscribe("CollisionEnter",std::bind(&PlayerComponent::OnCollisionEnter,this,std::placeholders::_1), m_owner);
		EventManager::Instance().Subscribe("CollisionExit",std::bind(&PlayerComponent::OnCollisionExit,this,std::placeholders::_1), m_owner);

		return true;

		
	}

	void nc::PlayerComponent::Destroy()
	{
	}

	void nc::PlayerComponent::Update()
	{
		auto contacts = m_owner->GetContactswithTag("Floor");
		bool onGround = !contacts.empty();

		nc::Vector2 force{ 0,0 };
		//player controller
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD)
		{
			force.x = -100;
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD)
		{
			force.x = 100;
		}	 
		if (onGround && m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_SPACE) == nc::InputSystem::eButtonState::PRESSED)
		{
			force.y = -1500;
			AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
			if (audioComponent)
			{
				audioComponent->SetSoundName("audio/screm.wav");
				audioComponent->Play();
			}
		}



		RigidBodyComponent* component = m_owner->GetComponent<RigidBodyComponent>();
		if (component)
		{
			component->ApplyForce(force);
			Vector2 velocity = component->GetVelocity();
			
			SpriteComponent* spriteComponent = m_owner->GetComponent<SpriteComponent>();
			if (velocity.x <= -0.15f) spriteComponent->Flip(false);
			if (velocity.x >= 0.15f) spriteComponent->Flip();
		}

	}
	void PlayerComponent::OnCollisionEnter(const Event& event)
	{
		AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
		GameObject* gameObject = dynamic_cast<GameObject*>(event.sender);

		if (gameObject->m_tag == "Enemy")
		{
			gameObject->m_flags[GameObject::eFlags::DESTROY] = true;
			audioComponent->SetSoundName("audio/screm.wav");
			audioComponent->Play();
		}

		if (gameObject->m_tag == "Coin")
		{
			gameObject->m_flags[GameObject::eFlags::DESTROY] = true;
			audioComponent->SetSoundName("audio/coin.wav");
			audioComponent->Play();
		}
	}
	void PlayerComponent::OnCollisionExit(const Event& event)
	{
		GameObject* gameObject = dynamic_cast<GameObject*>(event.sender);
	}
}

