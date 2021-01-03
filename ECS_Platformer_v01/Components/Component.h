//
//  Component.h
//  ECS_Test
//
//  Created by Lucas Giglio on 28.12.20.
//

#ifndef Component_h
#define Component_h
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Component {
public:
    bool operator==(Component const&) const = default; // custom == operator for component comparison
    bool nullComponent = false;
};
#endif /* Component_h */
