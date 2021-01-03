//
//  RenderComponent.h
//  ECS_Test
//
//  Created by Lucas Giglio on 25.12.20.
//

#ifndef RenderComponent_h
#define RenderComponent_h
#include "Component.h"

struct RenderComponent : public Component {
    SDL_Renderer* renderer;
};
#endif /* RenderComponent_h */
