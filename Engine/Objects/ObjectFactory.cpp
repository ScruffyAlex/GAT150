#include "pch.h"
#include "ObjectFactory.h"
#include "Components/PhysicsComponent.h"
#include "Components/RenderComponent.h"
#include "Components/SpriteComponent.h"
#include "../Game/Components/PlayerComponent.h"
#include "Components/SpriteAnimationComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/AudioComponent.h"

void nc::ObjectFactoryImpl::Initialize()
{
	nc::ObjectFactory::Instance().Register("GameObject", new Creator<GameObject, Object>);
	nc::ObjectFactory::Instance().Register("PhysicsComponent", new Creator<PhysicsComponent, Object>);
	nc::ObjectFactory::Instance().Register("SpriteComponent", new Creator<SpriteComponent, Object>);
	nc::ObjectFactory::Instance().Register("SpriteAnimationComponent", new Creator<SpriteAnimationComponent, Object>);
	nc::ObjectFactory::Instance().Register("RigidBodyComponent", new Creator<RigidBodyComponent, Object>);
	nc::ObjectFactory::Instance().Register("AudioComponent", new Creator<AudioComponent, Object>);
	
}
