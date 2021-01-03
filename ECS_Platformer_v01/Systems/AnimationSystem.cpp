//
//  AnimationSystem.cpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 30.12.20.
//

#include "AnimationSystem.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"

extern std::unique_ptr<EntityManager> entityManager;
extern std::unique_ptr<SystemManager> systemManager;
extern std::unique_ptr<ComponentManager> componentManager;

void AnimationSystem::Init() {}

void AnimationSystem::Update() {
    auto entities = entityManager->GetEntities();
    auto& renderComponent = componentManager->GetComponentFromEntity<RenderComponent>(0);
    
    for (auto entity : entities) {
        auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(entity); // update texture component with reference
        auto& transformComponent = componentManager->GetComponentFromEntity<TransformComponent>(entity); // Get transform component to manipulate sprite position
        
        if (textureComponent.nullComponent != true &&
            componentManager->GetComponentFromEntity<AnimationComponent>(entity).nullComponent != true) {
            // Get texture component to set sprite size
            auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(entity);
            SDL_QueryTexture(textureComponent.texture, NULL, NULL, &textureComponent.textureWidth, &textureComponent.textureHeight);
            
            textureComponent.frameWidth = textureComponent.textureWidth / 3;
            textureComponent.frameHeight = textureComponent.textureHeight / 2;
            
            
            transformComponent.rect.w = textureComponent.frameWidth;
            transformComponent.rect.h = textureComponent.frameHeight;
            
            transformComponent.positionRect.w = transformComponent.positionRect.h = textureComponent.frameWidth;
            
            // Get renderer
            
            SDL_RenderCopy(renderComponent.renderer, textureComponent.texture, &transformComponent.rect, &transformComponent.positionRect);
        } else {
            SDL_RenderCopy(renderComponent.renderer, textureComponent.texture, &transformComponent.rect, &transformComponent.positionRect);
        }
    }
}
