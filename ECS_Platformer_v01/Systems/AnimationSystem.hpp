//
//  AnimationSystem.hpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 30.12.20.
//

#ifndef AnimationSystem_hpp
#define AnimationSystem_hpp
#include "System.h"
#include "AnimationComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

class AnimationSystem : public System {
public:
    void Init();
    void Update();
private:

};

#endif /* AnimationSystem_hpp */
