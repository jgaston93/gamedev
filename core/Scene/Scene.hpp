#ifndef SCENE_HPP
#define SCENE_HPP

#include "EntityComponentSystem/Entity.hpp"

class Scene
{
    public:
    Scene(uint32_t scene_id, uint32_t max_num_entities);
    ~Scene();

    void getId(uint32_t& id);
    void addEntity(Entity* entity, ReturnCode& return_code);
    void getEntity(uint32_t entity_id, Entity*& entity, ReturnCode return_code);
    void getEntities(Entity**& entities, uint32_t& num_entities);

    private:
    const uint32_t m_scene_id;
    const uint32_t m_max_num_entities;
    uint32_t m_num_entities;
    Entity** m_entities;

};

#endif // SCENE_HPP