#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent() : Component(ComponentType::VELOCITY) 
{

};

void VelocityComponent::setVelocity(Vector velocity_vector) 
{ 
    m_velocity_vector = velocity_vector;
};

void VelocityComponent::getVelocity(Vector& velocity_vector) 
{ 
    velocity_vector = m_velocity_vector;
};
