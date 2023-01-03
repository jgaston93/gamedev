#ifndef BOUNDING_BOX_COMPONENT_HPP
#define BOUNDING_BOX_COMPONENT_HPP

#include "Common/Vector.hpp"
#include "Component.hpp"

class BoundingBoxComponent : public Component
{
    public:
    BoundingBoxComponent();

    void setBoundingBox(Vector bounding_box_vector);
    void getBoundingBox(Vector& bounding_box_vector);

    private:
    Vector m_bounding_box_vector;
};

#endif // BOUNDING_BOX_COMPONENT_HPP