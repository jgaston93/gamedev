#include "InputMap.hpp"


InputMap::InputMap(uint32_t num_inputs) : 
    m_max_num_inputs(num_inputs),
    m_num_inputs(0),
    m_input_list(new bool[num_inputs]),
    m_input_index_list(new SDL_Scancode[num_inputs])
{

}

InputMap::~InputMap()
{
    delete m_input_list;
    delete m_input_index_list;
}

void InputMap::addInput(SDL_Scancode input)
{
    if(m_num_inputs < m_max_num_inputs)
    {
        m_input_list[m_num_inputs] = false;
        m_input_index_list[m_num_inputs] = input;
        m_num_inputs++;
    }
}

void InputMap::setPressed(SDL_Scancode input, bool is_pressed)
{
    for(int i = 0; i < m_num_inputs; i++)
    {
        if(m_input_index_list[i] == input)
        {
            m_input_list[i] = is_pressed;
        }
    }
}

void InputMap::isPressed(SDL_Scancode input, bool& is_pressed)
{
    for(int i = 0; i < m_num_inputs; i++)
    {
        if(m_input_index_list[i] == input)
        {
            is_pressed = m_input_list[i];
        }
    }
}
