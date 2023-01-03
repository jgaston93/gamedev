#include "RenderSystem.hpp"
#include "EntityComponentSystem/PositionComponent.hpp"
#include "EntityComponentSystem/TextureComponent.hpp"

RenderSystem::RenderSystem(SDL_Window* win, SDL_Renderer* renderer) : 
    m_win(win),
    m_renderer(renderer),
    m_scene(0)
{

}

RenderSystem::~RenderSystem()
{

}

void RenderSystem::handleMessage(Message message, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
}

void RenderSystem::update(ReturnCode& return_code)
{
    SDL_RenderClear(m_renderer);
    return_code = ReturnCode::NO_ERROR;
    if(m_scene)
    {
        Entity** entities;
        uint32_t num_entities;
        m_scene->getEntities(entities, num_entities);

        for(uint32_t i = 0; i < num_entities; i++)
        {
            Component* component;
            entities[i]->getComponent(ComponentType::POSITION, (Component**)&component, return_code);
            PositionComponent* position_component = (PositionComponent*)component;
            entities[i]->getComponent(ComponentType::TEXTURE, (Component**)&component, return_code);
            TextureComponent* texture_component = (TextureComponent*)component;
            if(return_code == ReturnCode::NO_ERROR)
            {
                Vector position, extent;
                position_component->getPosition(position);

                SDL_Rect dest;
                dest.x = position.x;
                dest.y = position.y;

                SDL_Texture* texture;
                texture_component->getTexture(texture);

                SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
                SDL_RenderCopy(m_renderer, texture, NULL, &dest);
                
            }
        }
    }
    SDL_RenderPresent(m_renderer);
}

void RenderSystem::setScene(Scene* scene)
{
    m_scene = scene;
}
