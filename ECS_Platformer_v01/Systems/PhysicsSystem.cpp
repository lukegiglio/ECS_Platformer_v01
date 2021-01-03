//
//  PhysicsSystem.cpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#include "PhysicsSystem.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"

extern std::unique_ptr<EntityManager> entityManager;
extern std::unique_ptr<SystemManager> systemManager;
extern std::unique_ptr<ComponentManager> componentManager;
auto entities = entityManager->GetEntities();

void PhysicsSystem::Init() {}

void PhysicsSystem::Update(const Uint8* keyPressed, SDL_Event* event, float deltaTime) {
    entities = entityManager->GetEntities();
    auto system = systemManager->GetSystem<PhysicsSystem>();
    for (auto entity : entities) {
        auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(entity);
        auto& rigidBodyComponent = componentManager->GetComponentFromEntity<RigidBodyComponent>(entity);
        auto& gravityComponent = componentManager->GetComponentFromEntity<GravityComponent>(entity);
        // Check if entity has the necessary physics components
        if (&transformComponent == &componentManager->GetComponentFromSystem<TransformComponent>(system) &&
            &rigidBodyComponent == &componentManager->GetComponentFromSystem<RigidBodyComponent>(system) &&
            &gravityComponent == &componentManager->GetComponentFromSystem<GravityComponent>(system)   ) {
            
            
            
            
            
            
            auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(entity); // Get texture
            // Check if player needs to be transformed and animate
            if (&componentManager->GetComponentFromEntity<PlayerComponent>(entity) == &componentManager->GetComponentFromSystem<PlayerComponent>(system) &&
                keyPressed != NULL) {
                PlayerPhysics(keyPressed, deltaTime, textureComponent, transformComponent, rigidBodyComponent, gravityComponent, event);
            }
            
            // Handle intersection between entities
            
            if (!HandleIntersection(deltaTime, textureComponent, transformComponent, rigidBodyComponent, gravityComponent, entity)
                && jumpActive != true) {
                transformComponent.positionRect.y -= rigidBodyComponent.velocity.y * deltaTime;
                rigidBodyComponent.velocity += gravityComponent.force * deltaTime;
            } else if (jumpActive) {

                jumpRefresh++;
                //rigidBodyComponent.velocity -= gravityComponent.force * deltaTime;
                transformComponent.positionRect.y -= rigidBodyComponent.velocity.y * deltaTime;
                if (60 / jumpRefresh == 10) {
                    jumpRefresh  = 0;
                    jumpActive = false;
                }
                

            }
            
        }
    }
}


void PhysicsSystem::PlayerPhysics(const Uint8* keyPressed, float deltaTime, TextureComponent &textureComponent, TransformComponent &transformComponent,
                                  RigidBodyComponent &rigidBodyComponent, GravityComponent &gravityComponent, SDL_Event* event) {
    if (keyPressed[SDL_SCANCODE_RIGHT]) { // Move to the right
        spriteRefresh++;
        if (60 / spriteRefresh == 6) {
            spriteRefresh = 0;
            transformComponent.rect.y = 0; // Reset to the walking right sprite
            transformComponent.rect.x += textureComponent.frameWidth; // move to next sprite
            
            if (transformComponent.rect.x >= textureComponent.textureWidth) { // Reset sprite
                transformComponent.rect.x = 0;
            }
            
        }
        
        jumpActive = false;
        transformComponent.positionRect.x += rigidBodyComponent.velocity.x * deltaTime; // move character
        
        
    } else if (keyPressed[SDL_SCANCODE_LEFT]) { // Move to the left
        spriteRefresh++;
        if (60 / spriteRefresh == 6) {
            spriteRefresh = 0;
            transformComponent.rect.y = textureComponent.textureHeight / 2; // move down to the walking left sprite
            transformComponent.rect.x += textureComponent.frameWidth; // move to next sprite
            
            if (transformComponent.rect.x >= textureComponent.textureWidth) { // Reset sprite
                transformComponent.rect.x = 0;
            }
            
        }
        
        jumpActive = false;
        transformComponent.positionRect.x -= rigidBodyComponent.velocity.x * deltaTime; // move character
        
        
        
    } else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE &&
               !jumpActive) { // Jump
            rigidBodyComponent.velocity = { 10, 10 };
            jumpActive = true;
        } else { // If any of the keys above is pressed, reset initial sprite
        transformComponent.rect.x = 0;
    }
    
}







bool PhysicsSystem::HandleIntersection(float deltaTime, TextureComponent &textureComponent, TransformComponent &transformComponent,
                                    RigidBodyComponent &rigidBodyComponent, GravityComponent &gravityComponent, Entity &entity) {
    for (auto otherEntity : entities) {
        if (entity != otherEntity) { // check if entities are identical
            auto& otherTransformComponent = componentManager->GetComponentFromEntity<TransformComponent>(otherEntity); // get transform component from other entity
            if (SDL_HasIntersection(&transformComponent.positionRect, &otherTransformComponent.positionRect)) { // check for intersection between the two entities
                
                
                // Check against which entity an intersection occurs
                // if it's a platform, stay on top of it
                if (componentManager->GetComponentFromEntity<PlatformComponent>(otherEntity).nullComponent != true) {
                    transformComponent.positionRect.y = otherTransformComponent.positionRect.y - transformComponent.positionRect.h + 1;
                }
                
                
                return true;
            }
        } else {
            continue;
        }
    }
    return false;
}


void PhysicsSystem::ApplyGravity(TransformComponent* transformComponent, RigidBodyComponent* rigidBodyComponent, Entity* entity, GravityComponent* gravityComponent, float deltaTime) {
    if (componentManager->GetComponentFromEntity<GravityComponent>(*entity).nullComponent != true) {
        rigidBodyComponent->velocity.y += gravityComponent->force.y * deltaTime;
        rigidBodyComponent->velocity.x += gravityComponent->force.x * deltaTime;
        //transformComponent->positionRect.x += rigidBodyComponent->velocity.x * deltaTime;
        //transformComponent->positionRect.y += rigidBodyComponent->velocity.y * deltaTime;
    }
}
