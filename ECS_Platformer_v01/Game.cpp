//
//  Game.cpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#include "Game.hpp"

std::unique_ptr<EntityManager> entityManager = std::make_unique<EntityManager>();
std::unique_ptr<ComponentManager> componentManager = std::make_unique<ComponentManager>();
std::unique_ptr<SystemManager> systemManager = std::make_unique<SystemManager>();

// Create render system
const auto& renderSystem = systemManager->CreateSystem<RenderSystem>();
const auto& physicsSystem = systemManager->CreateSystem<PhysicsSystem>();
const auto& inputSystem = systemManager->CreateSystem<InputSystem>();
const auto& animationSystem = systemManager->CreateSystem<AnimationSystem>();

void Game::Init() {
    CreateComponents();

    // Create render entity 0
    Entity renderEntity = entityManager->CreateEntity();
    // Add components to render entity
    componentManager->AddComponentToEntity(renderEntity, WindowComponent{});
    componentManager->AddComponentToEntity(renderEntity, RenderComponent{});
    
    // Create player entity 1
    CreatePlayerEntity();
    
    // Create platform entity 2
    CreatePlatformEntity();
    
    // Create platform entity 3
    CreatePlatformEntity2();
    
    // Create platform entity 4
    CreatePlatformEntity3();

    
    // Add components to render system
    componentManager->AddComponentToSystem(renderSystem, RenderComponent{});
    componentManager->AddComponentToSystem(renderSystem, WindowComponent{});
    componentManager->AddComponentToSystem(renderSystem, TextureComponent{});

    // Add components to physics system
    componentManager->AddComponentToSystem(physicsSystem, TransformComponent{});
    componentManager->AddComponentToSystem(physicsSystem, RigidBodyComponent{});
    componentManager->AddComponentToSystem(physicsSystem, GravityComponent{});
    componentManager->AddComponentToSystem(physicsSystem, PlayerComponent{});
    
    // Add components to input system
    componentManager->AddComponentToSystem(inputSystem, TransformComponent{});
    
    // Add components to animation system
    componentManager->AddComponentToSystem(animationSystem, AnimationComponent{});
    
    // Initialize systems
    renderSystem->Init();
    physicsSystem->Init();
    inputSystem->Init();
}

bool Game::Run() {
    unsigned int frameStart = SDL_GetTicks(); // get start frame time
    // Game loop
    renderSystem->ClearRenderer();
    inputSystem->Update();
    animationSystem->Update();
    physicsSystem->Update(inputSystem->GetKeyPressed(), inputSystem->GetEvent(), deltaTime);
    
    renderSystem->Update();
    if (renderSystem->IsRenderDestroyed()) {
        return false;
    }
    
    // Handle FPS
    if (frameDelay > deltaTime) {
        SDL_Delay(frameDelay - deltaTime);
    }
    deltaTime = SDL_GetTicks() - frameStart;
    if (deltaTime > 1.0f) {
        deltaTime = 1.0f;
    }
    return true;
}

void Game::CreateComponents() {
    // Create components
    componentManager->CreateComponentType<WindowComponent>();
    componentManager->CreateComponentType<RenderComponent>();
    componentManager->CreateComponentType<InputComponent>();
    componentManager->CreateComponentType<TextureComponent>();
    componentManager->CreateComponentType<PlayerComponent>();
    componentManager->CreateComponentType<TransformComponent>();
    componentManager->CreateComponentType<RigidBodyComponent>();
    componentManager->CreateComponentType<GravityComponent>();
    componentManager->CreateComponentType<AnimationComponent>();
    componentManager->CreateComponentType<PlatformComponent>();
    componentManager->CreateComponentType<CollisionComponent>();
}


void Game::CreatePlayerEntity() {
    // Create player entity 1
    Entity playerEntity = entityManager->CreateEntity();
    // Add components to player entity
    componentManager->AddComponentToEntity(playerEntity, PlayerComponent{});
    componentManager->AddComponentToEntity(playerEntity, RenderComponent{});
    componentManager->AddComponentToEntity(playerEntity, TextureComponent{});
    componentManager->AddComponentToEntity(playerEntity, TransformComponent{});
    componentManager->AddComponentToEntity(playerEntity, GravityComponent{});
    componentManager->AddComponentToEntity(playerEntity, RigidBodyComponent{});
    componentManager->AddComponentToEntity(playerEntity, AnimationComponent{});
    componentManager->AddComponentToEntity(playerEntity, CollisionComponent{});
    
    auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(playerEntity);
    auto& playerComponent = componentManager->GetComponentFromEntity<PlayerComponent>(playerEntity);
    textureComponent.surface = IMG_Load(playerComponent.playerSprite);
    
    auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(playerEntity);
    transformComponent.rect = {0, 0, 0, 0};
    transformComponent.positionRect = {0, 0, 0, 0};
}

void Game::CreatePlatformEntity() {
    // Create platform entity 2
    Entity lowestPlatformEntity = entityManager->CreateEntity();
    // Add components to this platform
    componentManager->AddComponentToEntity(lowestPlatformEntity, PlatformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TransformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TextureComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, RigidBodyComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, CollisionComponent{});
    
    auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(lowestPlatformEntity);
    auto& platformComponent = componentManager->GetComponentFromEntity<PlatformComponent>(lowestPlatformEntity);
    textureComponent.surface = IMG_Load(platformComponent.platformSprite);
    
    auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(lowestPlatformEntity);
    transformComponent.rect = {0, 0, 800, 40};
    transformComponent.positionRect = {0, 591, 800, 40};
}

void Game::CreatePlatformEntity2() {
    // Create platform entity 4
    Entity lowestPlatformEntity = entityManager->CreateEntity();
    // Add components to this platform
    componentManager->AddComponentToEntity(lowestPlatformEntity, PlatformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TransformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TextureComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, RigidBodyComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, CollisionComponent{});
    
    auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(lowestPlatformEntity);
    auto& platformComponent = componentManager->GetComponentFromEntity<PlatformComponent>(lowestPlatformEntity);
    textureComponent.surface = IMG_Load(platformComponent.platformSprite);
    
    auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(lowestPlatformEntity);
    transformComponent.rect = {0, 0, 500, 40};
    transformComponent.positionRect = {0, 400, 500, 40};
}

void Game::CreatePlatformEntity3() {
    // Create platform entity 4
    Entity lowestPlatformEntity = entityManager->CreateEntity();
    // Add components to this platform
    componentManager->AddComponentToEntity(lowestPlatformEntity, PlatformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TransformComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, TextureComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, RigidBodyComponent{});
    componentManager->AddComponentToEntity(lowestPlatformEntity, CollisionComponent{});
    
    auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(lowestPlatformEntity);
    auto& platformComponent = componentManager->GetComponentFromEntity<PlatformComponent>(lowestPlatformEntity);
    textureComponent.surface = IMG_Load(platformComponent.platformSprite);
    
    auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(lowestPlatformEntity);
    transformComponent.rect = {0, 0, 500, 40};
    transformComponent.positionRect = {400, 200, 500, 40};
}
