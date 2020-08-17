#pragma once
#include "RenderComponent.h"

namespace nc
{
	class SpriteComponent : public RenderComponent
	{
	public:
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void Read(const rapidjson::Value& value);

		virtual void Update() override;
		virtual void Draw() override;

	protected:
		class Texture* m_texture;
		std::string m_textureName;
		SDL_Rect m_rect;
	};
}