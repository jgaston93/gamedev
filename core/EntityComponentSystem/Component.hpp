#ifndef COMPONENT_HPP
#define COMPONENT_HPP

enum ComponentType
{
    POSITION,
    ORIENTATION,
    SCALE,
    BOUNDING_BOX,
    VELOCITY,
    TEXTURE,
    LOGIC,
    ANIMATION
};

struct Component
{
    public:
    Component(ComponentType component_type);
    void getComponentType(ComponentType& type);

    private:
    const ComponentType m_component_type;
};

#endif // COMPONENT_HPP