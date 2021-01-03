//
//  InputSystem.hpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef InputSystem_h
#define InputSystem_h
#include "System.h"
#include "TransformComponent.h"

class InputSystem : public System {
public:
    void Init();
    void Update();
    const Uint8* GetKeyPressed() { return keyPressed; }
    SDL_Event* GetEvent() { return &event; }
private:
    const Uint8* keyPressed;
    SDL_Event event;
};

#endif /* InputSystem_h */
