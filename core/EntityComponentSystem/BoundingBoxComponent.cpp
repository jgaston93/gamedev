#include "BoundingBoxComponent.hpp"

BoundingBoxComponent::BoundingBoxComponent() : Component(ComponentType::BOUNDING_BOX) 
{

};

void BoundingBoxComponent::setBoundingBox(Vector bounding_box_vector) 
{ 
    m_bounding_box_vector = bounding_box_vector;
};

void BoundingBoxComponent::getBoundingBox(Vector& bounding_box_vector) 
{ 
    bounding_box_vector = m_bounding_box_vector;
};
