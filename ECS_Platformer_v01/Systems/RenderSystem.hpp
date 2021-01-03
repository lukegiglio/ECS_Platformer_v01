//
//  RenderSystem.hpp
//  ECS_Test
//
//  Created by Lucas Giglio on 26.12.20.
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp
#include "System.h"
#include <SDL2_image/SDL_image.h>
#include "WindowComponent.h"
#include "RenderComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"


class RenderSystem : public System {
public:
    void Init();    
    void Update();
    void Clean();
    void ClearRenderer();
    bool IsRenderDestroyed() {return renderDestroyed;}
private:
    WindowComponent windowComponent;
    bool renderDestroyed;
};

#endif /* RenderSystem_hpp */
