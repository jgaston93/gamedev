#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include "System.hpp"
#include "Common/InputMap.hpp"

class InputSystem : public System
{
    public:
    InputSystem();
    ~InputSystem();
    void handleMessage(Message message, ReturnCode& return_code);
    void update(ReturnCode& return_code);
    void setInputMap(InputMap* input_map);

    private:
    InputMap* m_input_map;
};

#endif // INPUT_SYSTEM_HPP