#include "Scene.hpp"


Scene::Scene(uint32_t scene_id, uint32_t max_num_entities) :
    m_scene_id(scene_id),
    m_max_num_entities(max_num_entities),
    m_num_entities(0),
    m_entities(new Entity*[max_num_entities])
{

}

Scene::~Scene()
{
    for(uint32_t i = 0; i < m_num_entities; i++)
    {
        delete m_entities[i];
    }
    delete[] m_entities;
}

void Scene::getId(uint32_t& id)
{
    id = m_scene_id;
}

void Scene::addEntity(Entity* entity, ReturnCode& return_code)
{
    // Check for duplicates
    return_code = NO_ERROR;
    uint32_t id_to_add;
    entity->getId(id_to_add);
    for(uint32_t i = 0; i < m_num_entities; i++)
    {
        uint32_t current_id;
        m_entities[i]->getId(current_id);
        if(current_id == id_to_add)
        {
            return_code = INVALID_PARAM;
        }
    }
    
    // Try to add if space available
    if(return_code == NO_ERROR)
    {
        return_code = NO_SPACE_LEFT;
        if(m_num_entities < m_max_num_entities)
        {
            m_entities[m_num_entities++] = entity;
            return_code = NO_ERROR;
        }
    }
}

void Scene::getEntity(uint32_t entity_id, Entity*& entity, ReturnCode return_code)
{
    return_code = NOT_FOUND;
    for(uint32_t i = 0; i < m_num_entities; i++)
    {
        uint32_t current_id;
        m_entities[i]->getId(current_id);
        if(current_id == entity_id)
        {
            entity = m_entities[i];
            return_code = NO_ERROR;
        }
    }
}

void Scene::getEntities(Entity**& entities, uint32_t& num_entities)
{
    entities = m_entities;
    num_entities = m_num_entities;
}