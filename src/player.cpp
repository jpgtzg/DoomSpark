/**
 * @file player.cpp
 * @author Juan Pablo Gutiérez
 * @date  12/03/23.
 */
#include "player.hpp"

#include <iostream>
#include <stdio.h>

#define pixelsPerFrame 3
#define rotationPerFrame 0.1

typedef struct
{
    bool w, a, s, d;
} keys;
keys K;

using namespace std;

/**
 * Moves a SDL_Rect object in the direction of the key pressed.
 */
void movePlayer(SDL_Rect &sdlRect)
{

    if (K.w == true)
    {
        cout << "up" << endl;
        sdlRect.y -= pixelsPerFrame;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        sdlRect.x -= pixelsPerFrame;
    }
    if (K.s == true)
    {
        cout << "down" << endl;
        sdlRect.y += pixelsPerFrame;
    }
    if (K.d == true)
    {
        cout << "right" << endl;
        sdlRect.x += pixelsPerFrame;
    }
}

/**
 * Moves the player, given their current positions
 */
void movePlayer(float &x, float &y, float &dx, float &dy)
{
    if (K.w == true)
    {
        cout << "up" << endl;
        y -= pixelsPerFrame;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        x -= pixelsPerFrame;
    }
    if (K.s == true)
    {
        cout << "down" << endl;
        y += pixelsPerFrame;
    }
    if (K.d == true)
    {
        cout << "right" << endl;
        x += pixelsPerFrame;
    }
}

/**
 * Moves the SDL_Rect and updates its positions
 */
void movePlayer(SDL_Rect &sdlRect, float &x, float &y, float &dx, float &dy)
{
    if (K.w == true)
    {
        cout << "up" << endl;
        sdlRect.y -= pixelsPerFrame;
        y -= pixelsPerFrame;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        sdlRect.x -= pixelsPerFrame;
        dx -= 0.1;
        x -= pixelsPerFrame;
    }
    if (K.s == true)
    {
        cout << "down" << endl;
        sdlRect.y += pixelsPerFrame;
        y += pixelsPerFrame;
    }
    if (K.d == true)
    {
        cout << "right" << endl;
        sdlRect.x += pixelsPerFrame;
        x += pixelsPerFrame;
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