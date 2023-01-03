#include "MessageBus.hpp"

MessageBus::MessageBus(uint32_t max_num_messages, uint32_t max_num_systems) : 
    m_max_num_messages(max_num_messages),
    m_num_messages(0),
    m_message_queue_index(0),
    m_message_queue(new Message[max_num_messages]),
    m_max_num_systems(max_num_systems),
    m_num_systems(0),
    m_systems(new System*[max_num_systems])
{

}

MessageBus::~MessageBus()
{
    delete[] m_message_queue;
}

void MessageBus::registerSystem(System* system, ReturnCode& return_code)
{
    return_code = NO_SPACE_LEFT;
    if(m_num_systems < m_max_num_systems)
    {
        m_systems[m_num_systems++] = system;
        return_code = NO_ERROR;
    }
}

void MessageBus::update(bool& is_running, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
    // Rewind the circular queue? TODO: make this better
    uint32_t message_queue_index = m_message_queue_index;
    for(uint32_t i = 0; i < m_num_messages; i++)
    {
        message_queue_index--;
        if(message_queue_index >= m_max_num_messages) message_queue_index = m_max_num_messages - 1; // Rollover occured
    }

    uint32_t messages_to_read = m_num_messages;
    for(uint32_t i = 0; i < messages_to_read; i++)
    {
        if(m_message_queue[message_queue_index].message_type == MessageType::QUIT)
        {
            is_running = false;
        }
        for(uint32_t j = 0; j < m_num_systems; j++)
        {
            m_systems[j]->handleMessage(m_message_queue[message_queue_index], return_code);
        }
        message_queue_index++;
        if(m_message_queue_index >= m_max_num_messages) m_message_queue_index = 0;
    }
    m_num_messages = m_num_messages - messages_to_read;
}

void MessageBus::postMessage(Message message, ReturnCode& return_code)
{
    return_code = NO_SPACE_LEFT;
    if(m_num_messages < m_max_num_messages)
    {
        m_message_queue[m_message_queue_index++] = message;
        if(m_message_queue_index >= m_max_num_messages) m_message_queue_index = 0;
        m_num_messages++;
        return_code = NO_ERROR;
    }
}
