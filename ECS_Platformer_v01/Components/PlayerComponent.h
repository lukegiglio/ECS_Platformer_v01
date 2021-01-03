//
//  PlayerComponent.h
//  ECS_Test
//
//  Created by Lucas Giglio on 25.12.20.
//

#ifndef PlayerComponent_h
#define PlayerComponent_h
#include "Component.h"

struct PlayerComponent : public Component {
    const char* playerSprite = "Assets/mario_movement.png";
};

#endif /* PlayerComponent_h */
