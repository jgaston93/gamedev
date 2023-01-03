#ifndef TEXTURE_COMPONENT_HPP
#define TEXTURE_COMPONENT_HPP

#include "SDL.h"
#include "Common/Vector.hpp"
#include "Component.hpp"

class TextureComponent : public Component
{
    public:
    TextureComponent();

    void setTexture(SDL_Texture* texture);
    void getTexture(SDL_Texture*& texture);

    private:
    SDL_Texture* m_texture;

};

#endif // TEXTURE_COMPONENT_HPP