#include "LogicComponent.hpp"
#include "SDL.h"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "Common/ReturnCodes.hpp"

LogicComponent::LogicComponent() : Component(ComponentType::LOGIC) 
{

}

void LogicComponent::setEntity(Entity* entity)
{
    m_entity = entity;
}

void LogicComponent::setInputMap(InputMap* input_map)
{
    m_input_map = input_map;
}