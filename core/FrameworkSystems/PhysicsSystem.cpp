#include "PhysicsSystem.hpp"
#include "EntityComponentSystem/PositionComponent.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "EntityComponentSystem/BoundingBoxComponent.hpp"

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
    // TODO: clean up this maybe?
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
            if(return_code == ReturnCode::NO_ERROR)
            {
                entities[i]->getComponent(ComponentType::VELOCITY, &component, return_code);
            }
            VelocityComponent* velocity_component = (VelocityComponent*)component;
            if(return_code == ReturnCode::NO_ERROR)
            {
                Vector position, velocity;
                position_component->getPosition(position);
                velocity_component->getVelocity(velocity);
                Vector new_position = position + velocity * delta_time;
                position_component->setPosition(new_position);

                // entities[i]->getComponent(ComponentType::BOUNDING_BOX, &component, return_code);
                // BoundingBoxComponent* bounding_box_component = (BoundingBoxComponent*)component;
                // if(return_code == ReturnCode::NO_ERROR)
                // {
                //     Vector bounding_box_1;
                //     bounding_box_component->getBoundingBox(bounding_box_1);

                //     float x_min_time = 1;
                //     float y_min_time = 1;

                //     if(velocity.x != 0)
                //     {
                //         for(uint32_t j = 0; j < num_entities; j++)
                //         {
                //             if(i != j)
                //             {
                //                 entities[j]->getComponent(ComponentType::POSITION, &component, return_code);
                //                 PositionComponent* position_component = (PositionComponent*)component;
                //                 entities[j]->getComponent(ComponentType::BOUNDING_BOX, &component, return_code);
                //                 BoundingBoxComponent* bounding_box_component = (BoundingBoxComponent*)component;
                //                 if(return_code == ReturnCode::NO_ERROR)
                //                 {
                //                     Vector position_2, bounding_box_2;
                //                     position_component->getPosition(position_2);
                //                     bounding_box_component->getBoundingBox(bounding_box_2);
                                    
                //                 }

                //             }
                //         }
                //     }
                // }
            }
        }
    }
}

void PhysicsSystem::setScene(Scene* scene)
{
    m_scene = scene;
}
