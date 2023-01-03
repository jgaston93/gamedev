#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "Common/Vector.hpp"
#include "Component.hpp"

class PositionComponent : public Component
{
    public:
    PositionComponent();

    void setPosition(Vector position_vector);
    void getPosition(Vector& position_vector);

    private:
    Vector m_position_vector;
};

#endif // POSITION_COMPONENT_HPP