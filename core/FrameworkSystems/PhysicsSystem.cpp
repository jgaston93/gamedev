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
                // position_component->setPosition(new_position);

                float x_min_time = 1;
                float y_min_time = 1;
                entities[i]->getComponent(ComponentType::BOUNDING_BOX, &component, return_code);
                BoundingBoxComponent* bounding_box_component = (BoundingBoxComponent*)component;
                if(return_code == ReturnCode::NO_ERROR)
                {
                    Vector bounding_box_1;
                    bounding_box_component->getBoundingBox(bounding_box_1);

                    if(velocity.x != 0)
                    {
                        for(uint32_t j = 0; j < num_entities; j++)
                        {
                            if(i != j)
                            {
                                entities[j]->getComponent(ComponentType::POSITION, &component, return_code);
                                PositionComponent* position_component = (PositionComponent*)component;
                                entities[j]->getComponent(ComponentType::BOUNDING_BOX, &component, return_code);
                                BoundingBoxComponent* bounding_box_component = (BoundingBoxComponent*)component;
                                if(return_code == ReturnCode::NO_ERROR)
                                {
                                    Vector position_2, bounding_box_2;
                                    position_component->getPosition(position_2);
                                    bounding_box_component->getBoundingBox(bounding_box_2);

                                    bool x_collision = new_position.x < position_2.x + bounding_box_2.x && 
                                                        new_position.x + bounding_box_1.x > position_2.x && 
                                                        position.y < position_2.y + bounding_box_2.y && 
                                                        position.y + bounding_box_1.y > position_2.y;
                                    if(x_collision)
                                    {
                                        float dx = 0;
                                        if(position.x < position_2.x)
                                        {
                                            dx = position_2.x - (position.x + bounding_box_1.x);
                                        }
                                        else if (position.x > position_2.x)
                                        {
                                            dx = position.x - (position_2.x + bounding_box_2.x);
                                        }
                                        float x_time = abs(dx / velocity.x);
                                        if(x_time < x_min_time)
                                        {
                                            x_min_time = x_time;
                                        }
                                    }
                                    
                                }

                            }
                        }
                    }
                    if(velocity.y != 0)
                    {
                        for(uint32_t j = 0; j < num_entities; j++)
                        {
                            if(i != j)
                            {
                                entities[j]->getComponent(ComponentType::POSITION, &component, return_code);
                                PositionComponent* position_component = (PositionComponent*)component;
                                entities[j]->getComponent(ComponentType::BOUNDING_BOX, &component, return_code);
                                BoundingBoxComponent* bounding_box_component = (BoundingBoxComponent*)component;
                                if(return_code == ReturnCode::NO_ERROR)
                                {
                                    Vector position_2, bounding_box_2;
                                    position_component->getPosition(position_2);
                                    bounding_box_component->getBoundingBox(bounding_box_2);

                                    bool y_collision = position.x < position_2.x + bounding_box_2.x && 
                                                        position.x + bounding_box_1.x > position_2.x && 
                                                        new_position.y < position_2.y + bounding_box_2.y && 
                                                        new_position.y + bounding_box_1.y > position_2.y;
                                    if(y_collision)
                                    {
                                        float dy = 0;
                                        if(position.y < position_2.y)
                                        {
                                            dy = position_2.y - (position.y + bounding_box_1.y);
                                        }
                                        else if (position.y > position_2.y)
                                        {
                                            dy = position.y - (position_2.y + bounding_box_2.y);
                                        }
                                        float y_time = abs(dy / velocity.y);
                                        if(y_time < y_min_time)
                                        {
                                            y_min_time = y_time;
                                        }
                                    }
                                    
                                }

                            }
                        }
                    }
                }
                position.x = position.x + velocity.x * delta_time * x_min_time;
                position.y = position.y + velocity.y * delta_time * y_min_time;
                position_component->setPosition(position);
            }
        }
    }
}

void PhysicsSystem::setScene(Scene* scene)
{
    m_scene = scene;
}
