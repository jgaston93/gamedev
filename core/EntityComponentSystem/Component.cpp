#include "Component.hpp"


Component::Component(ComponentType component_type) : 
    m_component_type(component_type)
{

}

void Component::getComponentType(ComponentType& type)
{ 
    type = m_component_type;
}