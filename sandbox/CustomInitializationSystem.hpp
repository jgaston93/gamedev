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
    void createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component, SDL_Renderer* renderer, Entity* entity);
};

#endif // CUSTOM_INITIALIZATION_SYSTEM_HPP