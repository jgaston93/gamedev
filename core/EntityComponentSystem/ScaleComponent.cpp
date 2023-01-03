#include "ScaleComponent.hpp"

ScaleComponent::ScaleComponent() : Component(ComponentType::SCALE) 
{

};

void ScaleComponent::setScale(Vector scale_vector) 
{ 
    m_scale_vector = scale_vector;
};

void ScaleComponent::getScale(Vector& scale_vector) 
{ 
    scale_vector = m_scale_vector;
};
