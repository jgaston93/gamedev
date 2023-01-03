#include "PlayerLogicComponent.hpp"
#include "EntityComponentSystem/Entity.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "SDL.h"


PlayerLogicComponent::PlayerLogicComponent()
{

}

void PlayerLogicComponent::event(Message message)
{
    ReturnCode return_code = ReturnCode::NO_ERROR;
    if(message.message_type == MessageType::KEYPRESS)
    {
        Component* component;
        m_entity->getComponent(ComponentType::VELOCITY, &component, return_code);
        VelocityComponent* velocity_component = (VelocityComponent*)component;
        Vector velocity_vector;
        if(message.message_data == SDL_SCANCODE_LEFT)
        {
            velocity_vector.x = -100;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_RIGHT)
        {
            velocity_vector.x = 100;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_UP)
        {
            velocity_vector.y = -100;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_DOWN)
        {
            velocity_vector.y = 100;
            velocity_component->setVelocity(velocity_vector);
        }
    }
    if(message.message_type == MessageType::KEYRELEASE)
    {
        Component* component;
        m_entity->getComponent(ComponentType::VELOCITY, &component, return_code);
        VelocityComponent* velocity_component = (VelocityComponent*)component;
        Vector velocity_vector;
        if(message.message_data == SDL_SCANCODE_LEFT)
        {
            velocity_vector.x = 0;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_RIGHT)
        {
            velocity_vector.x = 0;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_UP)
        {
            velocity_vector.y =  0;
            velocity_component->setVelocity(velocity_vector);
        }
        else if (message.message_data == SDL_SCANCODE_DOWN)
        {
            velocity_vector.y = 0;
            velocity_component->setVelocity(velocity_vector);
        }
    }
}

void PlayerLogicComponent::start()
{

}

void PlayerLogicComponent::update()
{

}
