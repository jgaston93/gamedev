#ifndef VELOCITY_COMPONENT_HPP
#define VELOCITY_COMPONENT_HPP

#include "Common/Vector.hpp"
#include "Component.hpp"

class VelocityComponent : public Component
{
    public:
    VelocityComponent();

    void setVelocity(Vector velocity_vector);
    void getVelocity(Vector& velocity_vector);

    private:
    Vector m_velocity_vector;
};

#endif // VELOCITY_COMPONENT_HPP