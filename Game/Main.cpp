#include "pch.h"
#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"

//#include <SDL_image.h>

nc::ResourceManager resourceManager;
nc::Renderer renderer;
nc::InputSystem inputSystem;
nc::Vector2 position = { 400,300 };

int main(int, char**)
{
	
	renderer.Startup();
	inputSystem.Startup();
	renderer.Create("Gat150", 800, 600);

	//texture
	nc::Texture* texture1 = resourceManager.Get<nc::Texture>("sf2.bmp",&renderer);
	nc::Texture* texture2 = resourceManager.Get<nc::Texture>("sf2.bmp",&renderer);
	//texture.Create("sf2.png",renderer);
	float angle{ 0 };

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		inputSystem.Update();

		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == nc::InputSystem::eButtonState::HELD)
		{
			position.x = position.x - 5.0f;
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == nc::InputSystem::eButtonState::HELD)
		{
			position.x = position.x + 5.0f;
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_DOWN) == nc::InputSystem::eButtonState::HELD)
		{
			position.y = position.y + 5.0f;
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_UP) == nc::InputSystem::eButtonState::HELD)
		{
			position.y = position.y - 5.0f;
		}
		
		angle = angle + 0.3f;
		renderer.BeginFrame();

		texture1->Draw(position, { 3.0f, 3.0f }, angle+90);
		//texture2->Draw({ 200,100 }, { 3.0f, 3.0f }, angle);

		renderer.EndFrame();
		
	}

	renderer.Shutdown();
	inputSystem.Shutdown();

	IMG_Quit();
	SDL_Quit();

	return 0;
}


