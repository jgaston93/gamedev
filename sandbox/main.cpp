#include <stdio.h>
#include <thread>

#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "EntityComponentSystem/Entity.hpp"
#include "EntityComponentSystem/PositionComponent.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "EntityComponentSystem/TextureComponent.hpp"
#include "PlayerLogicComponent.hpp"
#include "Scene/Scene.hpp"
#include "FrameworkSystems/PhysicsSystem.hpp"
#include "FrameworkSystems/RenderSystem.hpp"
#include "FrameworkSystems/InputSystem.hpp"
#include "FrameworkSystems/LogicSystem.hpp"
#include "CustomInitializationSystem.hpp"

int main(int argv, char* args[])
{
    if(argv < 2)
    {
        printf("No Conifguration Specified\n");
        return 1;
    }

    Scene** scenes;
    uint32_t num_scenes;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    char window_name[] = "Sandbox";
    char image_filename[] = "Test_Pic.bmp";
    SDL_Window* win = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);
    
    CustomInitializationSystem initialization_system;
    initialization_system.loadData(args[1], renderer);
    initialization_system.getScenes(scenes, num_scenes);

    MessageBus message_bus(64, 64);

    ReturnCode return_code = ReturnCode::NO_ERROR;
    PhysicsSystem physics_system;
    physics_system.setMessageBus(&message_bus, return_code);
    physics_system.setScene(scenes[0]);

    RenderSystem render_system(win, renderer);
    render_system.setMessageBus(&message_bus, return_code);
    render_system.setScene(scenes[0]);

    InputSystem input_system;
    input_system.setMessageBus(&message_bus, return_code);

    LogicSystem logic_system;
    logic_system.setMessageBus(&message_bus, return_code);
    logic_system.setScene(scenes[0]);

    uint32_t prev_time = 0;
    uint32_t num_frames = 0;
    uint32_t MS_PER_FRAME = 16;

    bool is_running = true;

    while(is_running)
    {
        uint32_t current_time = SDL_GetTicks();
        float delta_time = (current_time - prev_time) * 1e-3;
        prev_time = current_time;
        
        message_bus.update(is_running, return_code); // TODO: find a better to to shut down?
        input_system.update(return_code);
        physics_system.update(delta_time, return_code);
        render_system.update(return_code);
        logic_system.update(return_code);
        
        // Calculate time to sleep and sleep if necessary
        int next_frame_time = num_frames++ * MS_PER_FRAME;
        current_time = SDL_GetTicks();
        if(current_time < next_frame_time)
        {
            int ms_to_sleep = next_frame_time - current_time;
            SDL_Delay(ms_to_sleep);
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}