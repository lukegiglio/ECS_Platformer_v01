//
//  RigidBody.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef RigidBody_h
#define RigidBody_h
#include "Component.h"
#include "Vector2D.h"

struct RigidBodyComponent : public Component {
    Vector2D velocity {10, 10};
    Vector2D acceleration;
};
#endif /* RigidBody_h */
