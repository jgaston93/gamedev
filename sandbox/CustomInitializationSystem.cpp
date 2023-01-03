#include "CustomInitializationSystem.hpp"
#include "PlayerLogicComponent.hpp"

CustomInitializationSystem::CustomInitializationSystem()
{

}

CustomInitializationSystem::~CustomInitializationSystem()
{

}

void CustomInitializationSystem::createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component, SDL_Renderer* renderer, Entity* entity)
{
    rapidxml::xml_node<>* component_type_node = component_node->first_node("component_type");

    if(strcmp(component_type_node->value(), "PlayerLogicComponent") == 0)
    {
        component = new PlayerLogicComponent();
        PlayerLogicComponent* player_logic_component = (PlayerLogicComponent*)component;
        player_logic_component->setEntity(entity);
    }
}