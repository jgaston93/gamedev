#ifndef SCALE_COMPONENT_HPP
#define SCALE_COMPONENT_HPP

#include "Common/Vector.hpp"
#include "Component.hpp"

class ScaleComponent : public Component
{
    public:
    ScaleComponent();

    void setScale(Vector scale_vector);
    void getScale(Vector& scale_vector);

    private:
    Vector m_scale_vector;
};

#endif // SCALE_COMPONENT_HPP