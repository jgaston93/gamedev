#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "MessageBus/MessageBus.hpp"
#include "FrameworkSystems/System.hpp"
#include "Common/ReturnCodes.hpp"

class MessageBus;
class Message;

class System
{
    public:
        void setMessageBus(MessageBus* message_bus, ReturnCode& return_code);
        virtual void handleMessage(Message message, ReturnCode& return_code) = 0;

    protected:
        MessageBus* m_message_bus;
};

#endif // SYSTEM_HPP