#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <stdint.h>

#include "Component.hpp"
#include "Common/ReturnCodes.hpp"

class Entity
{
    public:
    Entity(uint32_t id, uint32_t max_num_components);
    ~Entity();
    
    void getId(uint32_t& id);
    void addComponent(Component* component, ReturnCode& return_code);
    void getComponent(ComponentType component_type, Component** component, ReturnCode& return_code);

    private:
    const uint32_t m_id;
    const uint32_t m_max_num_components;
    uint32_t m_num_components;
    Component** m_components;
};

#endif // ENTITY_HPP