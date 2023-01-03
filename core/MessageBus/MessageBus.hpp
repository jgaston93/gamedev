#ifndef MESSAGE_BUS_HPP
#define MESSAGE_BUS_HPP

#include "FrameworkSystems/System.hpp"
#include "Common/ReturnCodes.hpp"
#include "Message.hpp"

class System;

class MessageBus
{
    public:
    MessageBus(uint32_t max_num_messages, uint32_t max_num_systems);
    ~MessageBus();
    void registerSystem(System* system, ReturnCode& return_code);
    void update(bool& is_running, ReturnCode& return_code);
    void postMessage(Message message, ReturnCode& return_code);

    private:
    const uint32_t m_max_num_messages;
    uint32_t m_num_messages;
    uint32_t m_message_queue_index;
    Message* m_message_queue;

    const uint32_t m_max_num_systems;
    uint32_t m_num_systems;
    System** m_systems;

};

#endif // MESSAGE_BUS_HPP