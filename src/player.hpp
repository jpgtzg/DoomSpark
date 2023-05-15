/**
 * @file player.hpp
 * @author Juan Pablo Gutiérez
 * @date 12/03/23.
 */

#ifndef player_hpp
#define player_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

void movePlayer(SDL_Rect &sdlRect);

void movePlayer(float &x, float &y, float &dx, float &dy);

void movePlayer(SDL_Rect &sdlRect, float &x, float &y, float &dx, float &dy);

void handleKeysDown(SDL_Event event);

void handleKeysUp(SDL_Event event);

#endif /* player_hpp */