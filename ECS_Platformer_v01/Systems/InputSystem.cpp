//
//  InputSystem.cpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#include "InputSystem.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"

extern std::unique_ptr<EntityManager> entityManager;
extern std::unique_ptr<SystemManager> systemManager;
extern std::unique_ptr<ComponentManager> componentManager;

void InputSystem::Init() {}

void InputSystem::Update() {
    
    SDL_PollEvent(&event);
    
    // Continous-response keys
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    if (keyState[SDL_SCANCODE_RIGHT] ||
        keyState[SDL_SCANCODE_LEFT]) {
        keyPressed = keyState;
    }
}
