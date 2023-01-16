#ifndef CUSTOM_INITIALIZATION_SYSTEM_HPP
#define CUSTOM_INITIALIZATION_SYSTEM_HPP

#include "FrameworkSystems/InitializationSystem.hpp"
#include "SDL.h"
#include "rapidxml.hpp"

class CustomInitializationSystem : public InitializationSystem
{
    public:
    CustomInitializationSystem();
    ~CustomInitializationSystem();

    private:
    void createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component);
    void createCustomLogicComponent(char* logic_class_name, rapidxml::xml_node<>* component_node, Component*& component);
};

#endif // CUSTOM_INITIALIZATION_SYSTEM_HPP