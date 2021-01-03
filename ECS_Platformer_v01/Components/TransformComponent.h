//
//  TransformComponent.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef TransformComponent_h
#define TransformComponent_h
#include "Component.h"

struct TransformComponent : public Component {
    SDL_Rect rect;
    SDL_Rect positionRect;
};
#endif /* TransformComponent_h */
