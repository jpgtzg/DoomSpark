/**
 * doom-renderengine
 * @file main.cpp
 * @author Juan Pablo Gutiérez
 * @date 07/03/23.
*/

#include <iostream>
#include <SDL2/SDL.h>

#include "player.hpp"

using namespace std;

#define resW 1280
#define resH 720

int main()
{
    SDL_Rect sdlRect;
    sdlRect.w = resW / 30;
    sdlRect.h = resH / 10;
    sdlRect.x = resW / 2 - sdlRect.w / 2;
    sdlRect.y = resH / 2 - sdlRect.h / 2;
    int numPixelsToMovePerFrame = sdlRect.w / 4;

    bool upArrowDown = false;
    bool leftArrowDown = false;
    bool downArrowDown = false;
    bool rightArrowDown = false;

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
        "An SDL2 window",        // window title
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

        movePlayer(sdlRect, numPixelsToMovePerFrame);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 105, 180, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &sdlRect);
        SDL_RenderPresent(renderer);
        
        lastDrawTime = SDL_GetTicks64();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    std::cout << "exiting..." << std::endl;
    SDL_Quit();
    return 0;
}
