#include "System.hpp"


void System::setMessageBus(MessageBus* message_bus, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
    message_bus->registerSystem(this, return_code);
    if(return_code == ReturnCode::NO_ERROR)
    {
        m_message_bus = message_bus;
    }
}