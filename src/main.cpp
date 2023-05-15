/**
 * doom-renderengine
 * @file main.cpp
 * @author Juan Pablo Gutiérez
 * @date 07/03/23.
 */

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

#include "player.hpp"

using namespace std;

#define resW 1280
#define resH 720

/* Remove, raycast engine */
float playerX = 5;
float playerY = 5;
float playerDX = 0;
float playerDY = 0;
float playerA = 0;

int mapX = 8, mapY = 8, mapSize = 64;

void drawMap(SDL_Renderer *renderer);

/**
 * @brief Map of the game, 1 is a wall color red, 2 is a wall color green, 0 is empty space
 */
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 2, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 2, 0, 0, 1,
    1, 0, 2, 0, 0, 2, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1};

int main()
{
    SDL_Rect playerSDLRect;
    playerSDLRect.w = 10;
    playerSDLRect.h = 10;
    playerSDLRect.x = playerX;
    playerSDLRect.y = playerY;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool appIsRunning = true;

    int numMillisToThrottle = 6;
    Uint64 lastDrawTime = SDL_GetTicks64();

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "3D Game Engine",        // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        resW,                    // width, in pixels
        resH,                    // height, in pixels
        SDL_WINDOW_SHOWN         // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        // In the case that the renderer could not be made...
        printf("Could not create renderer: %s\n", SDL_GetError());
        return 1;
    }

    // main game/app loop
    while (appIsRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_QUIT)
            {
                appIsRunning = false;
            }
            else
            {
                handleKeysDown(event);
                handleKeysUp(event);
            }

            lastDrawTime = SDL_GetTicks64();
        }

        /* Calculates the position of the player, handling inputs*/
        movePlayer(playerSDLRect, playerX, playerY, playerDX, playerDY, playerA);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        /* Draws the player*/
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &playerSDLRect);

        /* Draws the ray */
        SDL_SetRenderDrawColor(renderer, 100, 100, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, playerX, playerY, playerX + playerDX * 10, playerY + playerDY * 10);

        drawMap(renderer);

        SDL_RenderPresent(renderer);

        lastDrawTime = SDL_GetTicks64();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}

void drawMap(SDL_Renderer *renderer)
{
    SDL_Rect blockReck;

    for (int y = 0; y < mapY; y++)
    {
        for (int x = 0; x < mapX; x++)
        {
            /* Runs through the array, the multiplication has to be done as it is a one dimensional array*/
            /* All multiplications are done because of the offset */
            int mapIndex = y * mapX + x;
            int mapValue = map[mapIndex];

            blockReck.x = x * mapSize;
            blockReck.y = y * mapSize;
            blockReck.w = mapSize;
            blockReck.h = mapSize;

            if (mapValue == 1)
            {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer, &blockReck);
            }
            else if (mapValue == 2)
            {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer, &blockReck);
            }
        }
    }
}

void doRaycast(){
    
}