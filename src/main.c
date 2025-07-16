/*
 * Based on: https://dev.to/ignaoya/series/13852
 */
#include <rogue.h>
#include <stdio.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;
const int MAX_ITEMS = 10;

Entity *player;
Tile **map;
Entity **items;

int main(void)
{
    bool isCompatibleTerminal;
    Position start_pos;

    isCompatibleTerminal = cursesSetup();

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