#ifndef LOGIC_COMPONENT_HPP
#define LOGIC_COMPONENT_HPP

#include "Common/Vector.hpp"
#include "Component.hpp"
#include "MessageBus/Message.hpp"
#include "Entity.hpp"

class LogicComponent : public Component
{
    public:
    LogicComponent();
    void setEntity(Entity* entity);
    virtual void event(Message message) = 0;
    virtual void start() = 0;
    virtual void update() = 0;


    protected:
    Entity* m_entity;

};

#endif // LOGIC_COMPONENT_HPP