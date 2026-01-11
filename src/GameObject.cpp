#include "GameObject.hpp"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y, int _width, int _height)
     
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, renderer);
    xpos = x;
    ypos = y;
    this->width = _width;
    this->height = _height;
    // Obtenemos el tamaño REAL del archivo de imagen
    SDL_QueryTexture(objTexture, NULL, NULL, &realWidth, &realHeight);
}

void GameObject::Update()
{
    xpos++;
    ypos++;

    // srcRect: Tomamos TODA la imagen original (desde 0,0 hasta su tamaño real)
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = realWidth;  
    srcRect.h = realHeight;

    // destRect: Aquí definimos la posición y el tamaño de renderizado (Escalado)
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = width;  // el ancho deseado
    destRect.h = height; // el alto deseado
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}