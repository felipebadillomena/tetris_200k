#pragma once
#include "Game.hpp"

class GameObject
{

public:
    GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y, int width, int height);
    ~GameObject();

    void Update();
    void Render();

private:
int xpos;
int ypos;   
int width;
int height;
int realWidth;
int realHeight;
SDL_Texture* objTexture;
SDL_Rect srcRect, destRect;
SDL_Renderer* renderer;


};
