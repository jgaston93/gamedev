#include "TextureComponent.hpp"

TextureComponent::TextureComponent() : Component(ComponentType::TEXTURE) 
{

}

void TextureComponent::setTexture(SDL_Texture* texture) 
{ 
    m_texture = texture;
}

void TextureComponent::getTexture(SDL_Texture*& texture) 
{ 
    texture = m_texture;
}
