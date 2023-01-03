#include "OrientationComponent.hpp"

OrientationComponent::OrientationComponent() : Component(ComponentType::ORIENTATION) 
{

};

void OrientationComponent::setOrientation(float orientation) 
{ 
    m_orientation = orientation; 
};

void OrientationComponent::getOrientation(float& orientation) 
{ 
    orientation = m_orientation; 
};
