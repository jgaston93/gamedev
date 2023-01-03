#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "SDL.h"
#include "Scene/Scene.hpp"
#include "System.hpp"

class RenderSystem : public System
{
    public:
    RenderSystem(SDL_Window* win, SDL_Renderer* renderer);
    ~RenderSystem();
    void handleMessage(Message message, ReturnCode& return_code);
    void update(ReturnCode& return_code);
    void setScene(Scene* scene);

    private:
    Scene* m_scene;
    SDL_Window* m_win;
    SDL_Renderer* m_renderer;
};

#endif // RENDER_SYSTEM_HPP