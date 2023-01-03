#include "PositionComponent.hpp"

PositionComponent::PositionComponent() : Component(ComponentType::POSITION) 
{

};

void PositionComponent::setPosition(Vector position_vector) 
{ 
    m_position_vector = position_vector;
};

void PositionComponent::getPosition(Vector& position_vector) 
{ 
    position_vector = m_position_vector;
};
