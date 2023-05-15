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
#define PI 3.14159265

typedef struct
{
    bool w, a, s, d;
} keys;
keys K;

using namespace std;

/**
 * Moves the player, given their current positions
 */
void movePlayer(float &x, float &y, float &dx, float &dy, float &angle)
{
    if (K.w == true)
    {
        cout << "up" << endl;
        y -= pixelsPerFrame;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        dx -= rotationPerFrame;
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
void movePlayer(SDL_Rect &sdlRect, float &x, float &y, float &dx, float &dy, float &angle)
{
    if (K.w == true)
    {
        cout << "up" << endl;

        x += dx;
        y += dy;
    }
    if (K.a == true)
    {
        cout << "left" << endl;
        angle -= rotationPerFrame;
        if (angle < 0)
            angle += 2 * PI;
        dx = cos(angle) * 10;
        dy = sin(angle) * 10;
    }
    if (K.s == true)
    {
        cout << "down" << endl;

        x -= dx;
        y -= dy;
    }
    if (K.d == true)
    {
        cout << "right" << endl;
        angle += rotationPerFrame;
        if (angle > 2 * PI)
            angle -= 2 * PI;
        dx = cos(angle) * 10;
        dy = sin(angle) * 10;
    }

    sdlRect.x = x;
    sdlRect.y = y;
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