//
//  GravityComponent.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef GravityComponent_h
#define GravityComponent_h

#include "Component.h"
#include "Vector2D.h"

struct GravityComponent : public Component {
    Vector2D force {0, -1};
};
#endif /* GravityComponent_h */
