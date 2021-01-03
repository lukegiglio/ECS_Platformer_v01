//
//  RenderSystem.cpp
//  ECS_Test
//
//  Created by Lucas Giglio on 26.12.20.

//

#include "RenderSystem.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"

extern std::unique_ptr<EntityManager> entityManager;
extern std::unique_ptr<SystemManager> systemManager;
extern std::unique_ptr<ComponentManager> componentManager;

void RenderSystem::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { // Initialize SDL
        
        // Init window parameters
        windowComponent.title = "ECS Platformer";
        windowComponent.posX = SDL_WINDOWPOS_CENTERED;
        windowComponent.posY = SDL_WINDOWPOS_CENTERED;
        windowComponent.width = 800;
        windowComponent.height = 640;
        windowComponent.fullScreen = false;
        
        // Get render component
        const auto system = systemManager->GetSystem<RenderSystem>(); // Get system
        auto& renderComponent = componentManager->GetComponentFromSystem<RenderComponent>(system);
        
        auto entities = entityManager->GetEntities();
        for (auto entity : entities) {
            
            
            // Initialize entities with WindowComponent
            if (&componentManager->GetComponentFromEntity<WindowComponent>(entity) == &componentManager->GetComponentFromSystem<WindowComponent>(system)) {
            windowComponent.window = SDL_CreateWindow(windowComponent.title, windowComponent.posX, windowComponent.posY, windowComponent.width, windowComponent.height, windowComponent.fullScreen); // Create window
                
                if (!windowComponent.window) {
                    cout << "Error creating window: " << SDL_GetError() << endl;
                }

                renderComponent.renderer = SDL_CreateRenderer(windowComponent.window, -1, SDL_RENDERER_ACCELERATED); // Create renderer
                assert (renderComponent.renderer != 0 && "Error initializing renderer " && SDL_GetError());
            }
            
            // Initialize entities with TextureComponent
            auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(entity); // update texture component with reference
            if (textureComponent.nullComponent != true) {
                textureComponent.texture = SDL_CreateTextureFromSurface(renderComponent.renderer, textureComponent.surface);
                SDL_FreeSurface(textureComponent.surface);
                SDL_RenderCopy(renderComponent.renderer, textureComponent.texture, 0, &componentManager->GetComponentFromEntity<TransformComponent>(entity).positionRect);
            }
        }        
    } else {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
    }
}


void RenderSystem::ClearRenderer() {
    const auto system = systemManager->GetSystem<RenderSystem>(); // Get system
    auto& renderComponent = componentManager->GetComponentFromSystem<RenderComponent>(system); // Get render component
    SDL_RenderClear(renderComponent.renderer);
}


void RenderSystem::Update() {
    const auto system = systemManager->GetSystem<RenderSystem>(); // Get system
    auto& renderComponent = componentManager->GetComponentFromSystem<RenderComponent>(system); // Get render component
    
    //SDL_RenderClear(renderComponent.renderer);
    
    // Check which entities have RenderComponent
//    auto entities = entityManager->GetEntities();
//    for (auto entity : entities) {
//
//        // Display textures
//        if (&componentManager->GetComponentFromEntity<TextureComponent>(entity) == &componentManager->GetComponentFromSystem<TextureComponent>(system)) {
//            auto& textureComponent = componentManager->GetComponentFromEntity<TextureComponent>(entity); // update texture component with reference
//            SDL_RenderCopy(renderComponent.renderer, textureComponent.texture, 0, &componentManager->GetComponentFromEntity<TransformComponent>(entity).rect);
//        }
//
//    }
    
    // Display
    SDL_RenderPresent(renderComponent.renderer);
    
    // Manage events
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
        Clean();
    }
}

// Clean SDL objects
void RenderSystem::Clean() {
    const auto system = systemManager->GetSystem<RenderSystem>(); // Get system
    auto& renderComponent = componentManager->GetComponentFromSystem<RenderComponent>(system); // Get render component
    
    SDL_DestroyWindow(windowComponent.window);
    SDL_DestroyRenderer(renderComponent.renderer);
    SDL_Quit();
    renderDestroyed = true;
}

