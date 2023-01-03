#include "Entity.hpp"

Entity::Entity(uint32_t id, uint32_t max_num_components) :
    m_id(id),
    m_max_num_components(max_num_components),
    m_num_components(0),
    m_components(new Component*[max_num_components])
{
    for(int i = 0; i < max_num_components; i++)
    {
        m_components[i] = 0;
    }
}

Entity::~Entity()
{
    for(int i = 0; i < m_num_components; i++)
    {
        delete m_components[i];
    }
    delete[] m_components;
}

void Entity::getId(uint32_t& id)
{
    id = m_id;
}

void Entity::addComponent(Component* component, ReturnCode& return_code)
{
    // Check for duplicates
    return_code = NO_ERROR;
    ComponentType type_to_add;
    component->getComponentType(type_to_add);
    for(uint32_t i = 0; i < m_num_components; i++)
    {
        ComponentType current_type;
        m_components[i]->getComponentType(current_type);
        if(current_type == type_to_add)
        {
            return_code = INVALID_PARAM;
        }
    }
    
    // Try to add if space available
    if(return_code == NO_ERROR)
    {
        return_code = NO_SPACE_LEFT;
        if(m_num_components < m_max_num_components)
        {
            m_components[m_num_components++] = component;
            return_code = NO_ERROR;
        }
    }
}

void Entity::getComponent(ComponentType component_type, Component** component, ReturnCode return_code)
{
    return_code = NOT_FOUND;
    for(uint32_t i = 0; i < m_num_components; i++)
    {
        ComponentType current_type;
        m_components[i]->getComponentType(current_type);
        if(current_type == component_type)
        {
            *component = m_components[i];
            return_code = NO_ERROR;
        }
    }
}
