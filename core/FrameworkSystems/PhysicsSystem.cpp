#include "PhysicsSystem.hpp"
#include "EntityComponentSystem/PositionComponent.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"

#include "SDL.h" // TODO: remove this

PhysicsSystem::PhysicsSystem() : 
    m_scene(0)
{

}

PhysicsSystem::~PhysicsSystem()
{

}

void PhysicsSystem::handleMessage(Message message, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
}

void PhysicsSystem::update(float delta_time, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
    if(m_scene)
    {
        Entity** entities;
        uint32_t num_entities;
        m_scene->getEntities(entities, num_entities);

        for(uint32_t i = 0; i < num_entities; i++)
        {
            Component* component;
            entities[i]->getComponent(ComponentType::POSITION, &component, return_code);
            PositionComponent* position_component = (PositionComponent*)component;
            entities[i]->getComponent(ComponentType::VELOCITY, &component, return_code);
            VelocityComponent* velocity_component = (VelocityComponent*)component;
            if(return_code == ReturnCode::NO_ERROR)
            {
                Vector position, velocity;
                position_component->getPosition(position);
                velocity_component->getVelocity(velocity);
                position = position + velocity * delta_time;
                position_component->setPosition(position);
            }
        }
    }
}

void PhysicsSystem::setScene(Scene* scene)
{
    m_scene = scene;
}
