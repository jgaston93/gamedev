#include <stdio.h>

#include "Common/Vector.hpp"
#include "InitializationSystem.hpp"
#include "SDL2/SDL_image.h"
#include "rapidxml_utils.hpp"
#include "EntityComponentSystem/PositionComponent.hpp"
#include "EntityComponentSystem/VelocityComponent.hpp"
#include "EntityComponentSystem/TextureComponent.hpp"

InitializationSystem::InitializationSystem()
{

}

InitializationSystem::~InitializationSystem()
{

}

void InitializationSystem::loadData(char* filename, SDL_Renderer* renderer)
{
    // TODO: lots of error checking
    rapidxml::file<> xml_file(filename);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xml_file.data());

    rapidxml::xml_node<>* root_node = doc.first_node();

    // Get window properties
    rapidxml::xml_node<>* window_node = root_node->first_node("window");
    rapidxml::xml_node<>* window_name_node = window_node->first_node("window_name");
    rapidxml::xml_node<>* window_size_x_node = window_node->first_node("window_size_x");
    rapidxml::xml_node<>* window_size_y_node = window_node->first_node("window_size_y");

    uint32_t window_name_size = window_name_node->value_size();
    m_window_name = new char[window_name_size + 1];
    strcpy(m_window_name, window_name_node->value());
    m_window_size_x = atoi(window_size_x_node->value());
    m_window_size_y = atoi(window_size_y_node->value());
    
    rapidxml::xml_node<>* num_scenes_node = root_node->first_node("num_scenes");
    rapidxml::xml_node<>* scene_node = root_node->first_node("scene");
    m_num_scenes = atoi(num_scenes_node->value());
    m_scenes = new Scene*[m_num_scenes];
    uint32_t scene_counter = 0;

    for(uint32_t i = 0; i < m_num_scenes; i++)
    {
        rapidxml::xml_node<>* scene_id_node = scene_node->first_node("scene_id");
        rapidxml::xml_node<>* num_entities_node = scene_node->first_node("num_entities");
        rapidxml::xml_node<>* entity_node = scene_node->first_node("entity");
        uint32_t scene_id = atoi(scene_id_node->value());
        uint32_t num_entities = atoi(num_entities_node->value());
        Scene* scene = new Scene(scene_id, num_entities);

        for(uint32_t j = 0; j < num_entities; j++)
        {
            rapidxml::xml_node<>* entity_id_node = entity_node->first_node("entity_id");
            rapidxml::xml_node<>* num_components_node = entity_node->first_node("num_components");
            rapidxml::xml_node<>* component_node = entity_node->first_node("component");
            uint32_t entity_id = atoi(entity_id_node->value());
            uint32_t num_components = atoi(num_components_node->value());
            Entity* entity = new Entity(entity_id, num_components);
            for(uint32_t k = 0; k < num_components; k++)
            {
                Component* component = 0;
                createComponent(component_node, component, renderer);
                if(!component)
                {
                    createCustomComponent(component_node, component, renderer, entity);
                }
                if(component)
                {
                    ReturnCode return_code = ReturnCode::NO_ERROR;
                    entity->addComponent(component, return_code);
                }
                component_node = component_node->next_sibling();
            }
            ReturnCode return_code = ReturnCode::NO_ERROR;
            scene->addEntity(entity, return_code);
            entity_node = entity_node->next_sibling();
        }
        m_scenes[scene_counter++] = scene;
    }
}

void InitializationSystem::createComponent(rapidxml::xml_node<>* component_node, Component*& component, SDL_Renderer* renderer)
{
    rapidxml::xml_node<>* component_type_node = component_node->first_node("component_type");

    if(strcmp(component_type_node->value(), "Position") == 0)
    {
        component = new PositionComponent();
        rapidxml::xml_node<>* position_x_node = component_node->first_node("position_x");
        rapidxml::xml_node<>* position_y_node = component_node->first_node("position_y");
        float x = atof(position_x_node->value());
        float y = atof(position_y_node->value());
        Vector position_vector(x, y);
        PositionComponent* position_component = (PositionComponent*)component;
        position_component->setPosition(position_vector);
    }
    else if(strcmp(component_type_node->value(), "Velocity") == 0)
    {
        component = new VelocityComponent();
        rapidxml::xml_node<>* velocity_x_node = component_node->first_node("velocity_x");
        rapidxml::xml_node<>* velocity_y_node = component_node->first_node("velocity_y");
        float x = atof(velocity_x_node->value());
        float y = atof(velocity_y_node->value());
        Vector velocity_vector(x, y);
        VelocityComponent* velocity_component = (VelocityComponent*)component;
        velocity_component->setVelocity(velocity_vector);
    }
    else if(strcmp(component_type_node->value(), "Texture") == 0)
    {
        component = new TextureComponent();
        rapidxml::xml_node<>* texture_node = component_node->first_node("filename");
        TextureComponent* texture_component = (TextureComponent*)component;
        texture_component->setTexture(IMG_LoadTexture(renderer, texture_node->value()));
    }
}

void InitializationSystem::createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component, SDL_Renderer* renderer, Entity* entity)
{

}

void InitializationSystem::getWindowName(char*& window_name)
{
    window_name = m_window_name;
}

void InitializationSystem::getWindowSize(uint32_t& x, uint32_t& y)
{
    x = m_window_size_x;
    y = m_window_size_y;
}

void InitializationSystem::getScenes(Scene**& scenes, uint32_t& num_scenes)
{
    scenes = m_scenes;
    num_scenes = m_num_scenes;
}
