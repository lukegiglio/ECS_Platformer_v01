//
//  PlatformComponent.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 30.12.20.
//

#ifndef PlatformComponent_h
#define PlatformComponent_h
#include "Component.h"

struct PlatformComponent : public Component {
    const char* platformSprite = "Assets/platform.png";
};

#endif /* PlatformComponent_h */
