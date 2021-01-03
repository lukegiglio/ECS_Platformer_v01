//
//  WindowComponent.h
//  ECS_Test
//
//  Created by Lucas Giglio on 26.12.20.
//

#ifndef WindowComponent_h
#define WindowComponent_h
#include "Component.h"

struct WindowComponent : public Component {
    const char* title;
    int posX, posY;
    int width, height;
    SDL_Window* window;
    bool fullScreen;
};

#endif /* WindowComponent_h */
