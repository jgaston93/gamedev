#include "SDL.h"
#include "InputSystem.hpp"

InputSystem::InputSystem()
{

}

InputSystem::~InputSystem()
{

}

void InputSystem::handleMessage(Message message, ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;
}

void InputSystem::update(ReturnCode& return_code)
{
    return_code = ReturnCode::NO_ERROR;

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        Message message;
        switch(event.type)
        {
            case SDL_QUIT:
                message.message_type = MessageType::QUIT;
                m_message_bus->postMessage(message, return_code);
                break;
            case SDL_KEYDOWN:
                if(!event.key.repeat)
                {
                    message.message_type = MessageType::KEYPRESS;
                    message.message_data = event.key.keysym.scancode;
                    m_message_bus->postMessage(message, return_code);
                }
                break;
            case SDL_KEYUP:
                if(!event.key.repeat)
                {
                    message.message_type = MessageType::KEYRELEASE;
                    message.message_data = event.key.keysym.scancode;
                    m_message_bus->postMessage(message, return_code);
                }
                break;
            default:
                break;
        }
    }
}
