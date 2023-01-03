#ifndef LOGIC_SYSTEM_HPP
#define LOGIC_SYSTEM_HPP

#include "Scene/Scene.hpp"
#include "System.hpp"

class LogicSystem : public System
{
    public:
    LogicSystem();
    ~LogicSystem();
    void handleMessage(Message message, ReturnCode& return_code);
    void update(ReturnCode& return_code);
    void setScene(Scene* scene);

    private:
    Scene* m_scene;
};

#endif // LOGIC_SYSTEM_HPP