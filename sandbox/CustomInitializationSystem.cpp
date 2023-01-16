#include "CustomInitializationSystem.hpp"
#include "PlayerLogicComponent.hpp"

CustomInitializationSystem::CustomInitializationSystem()
{

}

CustomInitializationSystem::~CustomInitializationSystem()
{

}

void CustomInitializationSystem::createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component)
{

}

void CustomInitializationSystem::createCustomLogicComponent(char* logic_class_name, rapidxml::xml_node<>* component_node, Component*& component)
{
    if(strcmp(logic_class_name, "PlayerLogicComponent") == 0)
    {
        rapidxml::xml_node<>* player_speed_node = component_node->first_node("player_speed");
        component = new PlayerLogicComponent();
        PlayerLogicComponent* player_logic_component = (PlayerLogicComponent*)component;
        player_logic_component->setPlayerSpeed(atof(player_speed_node->value()));
    }
}