//
//  render.cpp
//  doom-renderengine
//
//  Created by Juan Pablo Gutierrez on 12/03/23.
//
#include "render.hpp"

#include <iostream>
#include <stdio.h>
#include <SDL.h>

void drawPixel(int x, int y, int color, SDL_Renderer& renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);

    SDL_RenderDrawPoint(renderer, x, y);
}
