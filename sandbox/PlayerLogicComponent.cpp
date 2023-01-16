#include "PlayerLogicComponent.hpp"
#include "EntityComponentSystem/Entity.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "SDL.h"


PlayerLogicComponent::PlayerLogicComponent()
{

}

void PlayerLogicComponent::event(Message message)
{

}

void PlayerLogicComponent::start()
{

}

void PlayerLogicComponent::update()
{
    bool left_pressed = false;
    bool right_pressed = false;
    bool up_pressed = false;
    bool down_pressed = false;

    m_input_map->isPressed(SDL_Scancode::SDL_SCANCODE_LEFT, left_pressed);
    m_input_map->isPressed(SDL_Scancode::SDL_SCANCODE_RIGHT, right_pressed);
    m_input_map->isPressed(SDL_Scancode::SDL_SCANCODE_UP, up_pressed);
    m_input_map->isPressed(SDL_Scancode::SDL_SCANCODE_DOWN, down_pressed);

    ReturnCode return_code = ReturnCode::NO_ERROR;
    Component* component;
    m_entity->getComponent(ComponentType::VELOCITY, &component, return_code);
    VelocityComponent* velocity_component = (VelocityComponent*)component;
    Vector velocity_vector;

    if(left_pressed && !right_pressed)
    {
        velocity_vector.x = -m_speed;
    }
    else if(!left_pressed && right_pressed)
    {
        velocity_vector.x = m_speed;
    }

    if(up_pressed && !down_pressed)
    {
        velocity_vector.y = -m_speed;
    }
    else if(!up_pressed && down_pressed)
    {
        velocity_vector.y = m_speed;
    }

    velocity_component->setVelocity(velocity_vector);
}

void PlayerLogicComponent::setPlayerSpeed(float speed)
{
    m_speed = speed;
}
