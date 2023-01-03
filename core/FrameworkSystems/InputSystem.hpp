#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include "System.hpp"

class InputSystem : public System
{
    public:
    InputSystem();
    ~InputSystem();
    void handleMessage(Message message, ReturnCode& return_code);
    void update(ReturnCode& return_code);

    private:
};

#endif // INPUT_SYSTEM_HPP