/*
 * Based on: https://dev.to/ignaoya/series/13852
 */
#include <rogue.h>
#include <stdio.h>
// #include <SDL2/SDL.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;
const int MAX_ITEMS = 10;
int TOTAL_ITEMS = 0;

Entity *player;
Tile **map;
Entity **items;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(void)
{
    bool isCompatibleTerminal;
    Position start_pos;

    // SDL_Window *window = NULL;
    // SDL_Surface *screenSurface = NULL;

    isCompatibleTerminal = cursesSetup();

    // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) < 0)
    // {
    //     printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    // }
    // else
    // {
    //     // Create window
    //     window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //     if (window == NULL)
    //     {
    //         printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    //     }
    //     else
    //     {
    //         // Get window surface
    //         screenSurface = SDL_GetWindowSurface(window);

    //         // Fill the surface white
    //         SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    //         // Update the surface
    //         SDL_UpdateWindowSurface(window);

    //         // Hack to get window to stay up
    //         SDL_Event e;
    //         bool quit = false;
    //         while (quit == false)
    //         {
    //             while (SDL_PollEvent(&e))
    //             {
    //                 if (e.type == SDL_QUIT)
    //                     quit = true;
    //             }
    //         }
    //     }

    // Destroy window
    //  SDL_DestroyWindow( window );

    // Quit SDL subsystems
    //  SDL_Quit();
    //  }

    if (isCompatibleTerminal)
    {
        srand(time(NULL));

        map = createMapTiles();
        start_pos = setupMap();
        player = createPlayer(start_pos);
        items = createItems();

        gameLoop();
        closeGame();
    }
    else
    {
        endwin();
    }

    return 0;
}