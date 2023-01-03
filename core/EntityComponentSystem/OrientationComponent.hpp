#ifndef ORIENTATION_COMPONENT_HPP
#define ORIENTATION_COMPONENT_HPP

#include "Component.hpp"

class OrientationComponent : public Component
{
    public:
    OrientationComponent();

    void setOrientation(float position_vector);
    void getOrientation(float& position_vector);

    private:
    float m_orientation;
};

#endif // ORIENTATION_COMPONENT_HPP