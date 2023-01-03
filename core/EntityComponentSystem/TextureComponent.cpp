#include "TextureComponent.hpp"

TextureComponent::TextureComponent() : Component(ComponentType::TEXTURE) 
{

}

void TextureComponent::setTexture(SDL_Texture* position_vector) 
{ 
    m_texture = position_vector;
}

void TextureComponent::getTexture(SDL_Texture*& position_vector) 
{ 
    position_vector = m_texture;
}
