#ifndef INPUT_MAP_HPP
#define INPUT_MAP_HPP

#include <stdint.h>

#include "SDL.h"

class InputMap
{
    public:
    InputMap(uint32_t num_inputs);
    ~InputMap();

    void addInput(SDL_Scancode input);
    void setPressed(SDL_Scancode input, bool is_pressed);
    void isPressed(SDL_Scancode input, bool& is_pressed);

    private:
    const int m_max_num_inputs;
    int m_num_inputs;
    bool* m_input_list;
    SDL_Scancode* m_input_index_list;
};

#endif // INPUT_MAP_HPP