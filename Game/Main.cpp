#include "pch.h"
#include "Graphics/Texture.h"
#include "Engine.h"
#include "Components/PlayerComponent.h"
#include "EnemyComponent.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include "Objects/ObjectFactory.h"
#include "Objects/Scene.h"
#include "TileMap.h"

//#include <SDL_image.h>

nc::Engine engine;
nc::Scene scene;

int main(int, char**)
{
	engine.Startup();

	nc::ObjectFactory::Instance().Initialize();
	nc::ObjectFactory::Instance().Register("PlayerComponent", new nc::Creator<nc::PlayerComponent, nc::Object>);
	nc::ObjectFactory::Instance().Register("EnemyComponent", new nc::Creator<nc::EnemyComponent, nc::Object>);

	
	rapidjson::Document document;
	nc::json::Load("scene.txt", document);
	scene.Create(&engine);
	scene.Read(document);

	nc::TileMap tileMap;
	nc::json::Load("tileMap.txt", document);
	tileMap.Read(document);
	tileMap.Create(&scene);

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

		//update
		engine.Update();
		scene.Update();

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == nc::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		//draw
		engine.GetSystem<nc::Renderer>()->BeginFrame();
		scene.Draw();
		
		
		engine.GetSystem<nc::Renderer>()->EndFrame();
		
	}

	scene.Destroy();
	engine.Shutdown();
	//IMG_Quit();

	return 0;
}


