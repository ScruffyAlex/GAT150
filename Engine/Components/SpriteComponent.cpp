#include "pch.h"
#include "SpriteComponent.h"
#include "Graphics/Texture.h"

bool nc::SpriteComponent::Create(void* data)
{
	m_texture = m_owner->m_engine->GetSystem<nc::ResourceManager>()->Get<nc::Texture>(m_textureName, m_owner->m_engine->GetSystem<nc::Renderer>());
	return true;
}

void nc::SpriteComponent::Destroy()
{
	
}

void nc::SpriteComponent::Read(const rapidjson::Value& value)
{
	nc::json::Get(value, "texture", m_textureName);
	nc::json::Get(value, "rect", m_rect);
}

void nc::SpriteComponent::Update()
{

}

void nc::SpriteComponent::Draw()
{
	m_texture->Draw(m_rect, m_owner->m_transform.position, {m_owner->m_transform.scale, m_owner->m_transform.scale }, m_owner->m_transform.angle);
}
