#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if (tempSurface == NULL) {
        std::cout << "Error loading image: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
    
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}