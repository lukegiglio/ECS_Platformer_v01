//
//  PhysicsSystem.hpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef PhysicsSystem_hpp
#define PhysicsSystem_hpp
#include "System.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"
#include "GravityComponent.h"
#include "PlayerComponent.h"
#include "TextureComponent.h"
#include "CollisionComponent.h"
#include "PlatformComponent.h"
#include "Types.hpp"

class PhysicsSystem : public System {
public:
    void Init();
    void Update(const Uint8* keyPressed, SDL_Event* event, float deltaTime);
    void PlayerPhysics(const Uint8* keyPressed, float deltaTime,TextureComponent &textureComponent, TransformComponent &transformComponent,
                       RigidBodyComponent &rigidBodyComponent, GravityComponent &gravityComponent, SDL_Event* event);
    
    bool HandleIntersection(float deltaTime, TextureComponent &textureComponent, TransformComponent &transformComponent,
                         RigidBodyComponent &rigidBodyComponent, GravityComponent &gravityComponent, Entity &entity);
    
    void ApplyGravity(TransformComponent* transformComponent, RigidBodyComponent* rigidBodyComponent, Entity* entity, GravityComponent* gravityComponent, float deltaTime);
private:
    int spriteRefresh = 0;
    int jumpRefresh = 0;
    bool jumpActive = false;
};

#endif /* PhysicsSystem_hpp */
