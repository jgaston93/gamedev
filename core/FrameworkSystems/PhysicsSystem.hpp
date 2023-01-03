#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP

#include "Scene/Scene.hpp"
#include "System.hpp"

class PhysicsSystem : public System
{
    public:
    PhysicsSystem();
    ~PhysicsSystem();
    void handleMessage(Message message, ReturnCode& return_code);
    void update(float delta_time_ms, ReturnCode& return_code);
    void setScene(Scene* scene);

    private:
    Scene* m_scene;
};

#endif // PHYSICS_SYSTEM_HPP