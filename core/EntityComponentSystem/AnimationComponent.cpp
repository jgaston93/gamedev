#include "AnimationComponent.hpp"

AnimationComponent::AnimationComponent() : Component(ComponentType::ANIMATION) 
{

}

AnimationComponent::~AnimationComponent()
{
    delete[] m_texture_list;
}

void AnimationComponent::setTextureList(SDL_Texture** texture_list, uint32_t num_textures) 
{ 
    m_texture_list = texture_list;
}

void AnimationComponent::getTextureList(SDL_Texture**& texture_list, uint32_t& num_textures) 
{ 
    texture_list = m_texture_list;
}
