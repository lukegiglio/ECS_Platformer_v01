//
//  Types.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 24.12.20.
//
//  This header provides all basic types for ECS
//
//

#ifndef Types_hpp
#define Types_hpp

#include <stdio.h>
#include <bitset>
#include <map>

using Entity = std::size_t;
const Entity MAX_ENTITIES = 50;
using ComponentType = u_int8_t;
const ComponentType MAX_COMPONENTS = 30;

#endif /* Types_hpp */
