//
//  Game.hpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef Game_hpp
#define Game_hpp
// Include managers
#include "ECS/EntityManager.hpp"
#include "ECS/ComponentManager.hpp"
#include "ECS/SystemManager.hpp"

// Include components
#include "Components/PlayerComponent.h"
#include "Components/RenderComponent.h"
#include "Components/InputComponent.h"
#include "Components/PlayableComponent.h"
#include "Components/WindowComponent.h"
#include "Components/TextureComponent.h"
#include "Components/TransformComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/GravityComponent.h"
#include "Components/AnimationComponent.h"
#include "Components/PlatformComponent.h"
#include "Components/CollisionComponent.h"

// Include systems
#include "Systems/InputSystem.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/AnimationSystem.hpp"

#include <SDL2_image/SDL_image.h>

class Game {
public:
    void Init();
    void Clean();
    bool Run();
    void CreateComponents();
    void CreatePlayerEntity();
    void CreatePlatformEntity();
    void CreatePlatformEntity2();
    void CreatePlatformEntity3();
private:
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    float deltaTime;
};

#endif /* Game_hpp */

