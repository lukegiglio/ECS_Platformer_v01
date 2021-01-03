//
//  TextureComponent.h
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#ifndef TextureComponent_h
#define TextureComponent_h
#include "Component.h"

struct TextureComponent : public Component {
    SDL_Surface* surface;
    SDL_Texture* texture;
    int textureWidth, textureHeight;
    int frameWidth, frameHeight;
};
#endif /* TextureComponent_h */
