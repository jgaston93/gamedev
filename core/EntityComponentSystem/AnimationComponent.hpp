#ifndef ANIMATION_COMPONENT_HPP
#define ANIMATION_COMPONENT_HPP

#include "SDL.h"
#include "Common/Vector.hpp"
#include "Component.hpp"

class AnimationComponent : public Component
{
    public:
    AnimationComponent();
    ~AnimationComponent();

    void setTextureList(SDL_Texture** texture_list, uint32_t num_textures);
    void getTextureList(SDL_Texture**& texture_list, uint32_t& num_textures);

    private:
    uint32_t m_num_textures;
    SDL_Texture** m_texture_list;
    float m_speed;
    uint32_t m_texture_index;
    bool m_is_playing;
    float m_animation_counter;

};

#endif // ANIMATION_COMPONENT_HPP