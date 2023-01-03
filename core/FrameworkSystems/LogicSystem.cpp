#include "LogicSystem.hpp"
#include "EntityComponentSystem/LogicComponent.hpp"

LogicSystem::LogicSystem() : 
    m_scene(0)
{

}

LogicSystem::~LogicSystem()
{

}

void LogicSystem::handleMessage(Message message, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
    if(m_scene)
    {
        Entity** entities;
        uint32_t num_entities;
        m_scene->getEntities(entities, num_entities);

        for(uint32_t i = 0; i < num_entities; i++)
        {
            Component* component = 0;
            entities[i]->getComponent(ComponentType::LOGIC, &component, return_code);
            LogicComponent* logic_component = (LogicComponent*)component;
            if(return_code == ReturnCode::NO_ERROR && logic_component)
            {
                logic_component->event(message);
            }
        }
    }
}

void LogicSystem::update(ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
    if(m_scene)
    {
        Entity** entities;
        uint32_t num_entities;
        m_scene->getEntities(entities, num_entities);

        for(uint32_t i = 0; i < num_entities; i++)
        {
            Component* component;
            entities[i]->getComponent(ComponentType::LOGIC, &component, return_code);
            LogicComponent* logic_component = (LogicComponent*)component;
            if(return_code == ReturnCode::NO_ERROR && logic_component)
            {
                logic_component->update();
            }
        }
    }
}

void LogicSystem::setScene(Scene* scene)
{
    m_scene = scene;
}
