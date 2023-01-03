#ifndef PLAYER_LOGIC_COMPONENT_HPP
#define PLAYER_LOGIC_COMPONENT_HPP

#include "EntityComponentSystem/LogicComponent.hpp"

class PlayerLogicComponent : public LogicComponent
{
    public:
    PlayerLogicComponent();
    void event(Message message);
    void start();
    void update();


    protected:
};

#endif // PLAYER_LOGIC_COMPONENT_HPP