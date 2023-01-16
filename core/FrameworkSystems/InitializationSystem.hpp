#ifndef INITIALIZATION_SYSTEM_HPP
#define INITIALIZATION_SYSTEM_HPP

#include "SDL.h"
#include "Common/InputMap.hpp"
#include "Scene/Scene.hpp"
#include "rapidxml.hpp"

class InitializationSystem
{
    public:
    InitializationSystem();
    ~InitializationSystem();
    void loadData(char* filename, SDL_Renderer* renderer, InputMap* input_map);

    void getWindowName(char*& window_name);
    void getWindowSize(uint32_t& x, uint32_t& y);
    void getScenes(Scene**& scenes, uint32_t& num_scenes);

    private:
    void createComponent(rapidxml::xml_node<>* component_node, Component*& component, SDL_Renderer* renderer, Entity* entity, InputMap* input_map);
    virtual void createCustomComponent(rapidxml::xml_node<>* component_node, Component*& component);
    virtual void createCustomLogicComponent(char* logic_class_name, rapidxml::xml_node<>* component_node, Component*& component);

    char* m_window_name;
    uint32_t m_window_size_x;
    uint32_t m_window_size_y;

    uint32_t m_num_scenes;
    Scene** m_scenes;
};

#endif // INITIALIZATION_SYSTEM_HPP