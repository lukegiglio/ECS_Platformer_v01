//
//  EntityToComponent.h
//  ECS_Test
//
//  Created by Lucas Giglio on 27.12.20.
//

#ifndef EntityToComponent_h
#define EntityToComponent_h

#include "Types.hpp"

template <typename T>
struct EntityToComponent {
    Entity entity;
    T component;
};

#endif /* EntityToComponent_h */
