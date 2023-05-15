/**
 * @file player.cpp
 * @author Juan Pablo Gutiérez
 * @date  12/03/23.
 */
#include "player.hpp"

#include <iostream>
#include <stdio.h>

typedef struct
{
    bool w, a, s, d;
} keys;
keys K;

using namespace std;

void movePlayer(SDL_Rect &sdlRect, int pixelsAdded)
{

    if (K.w == true)
    {
        cout << "up" << endl;
        sdlRect.y -= 10;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        sdlRect.x -= 10;
    }
    if (K.s == true)
    {
        cout << "down" << endl;
        sdlRect.y += 10;
    }
    if (K.d == true)
    {
        cout << "right" << endl;
        sdlRect.x += 10;
    }
}

void handleKeysDown(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
            K.w = true;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
            K.a = true;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
            K.s = true;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            K.d = true;
        }
    }
}

void handleKeysUp(SDL_Event event)
{
    if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
            K.w = false;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
            K.a = false;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
            K.s = false;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
            K.d = false;
        }
    }
}