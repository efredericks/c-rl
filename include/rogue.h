#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
    int y;
    int x;
} Position;

typedef struct
{
    Position pos;
    char ch;
} Entity;

typedef struct
{
    char ch;
    bool walkable;
} Tile;

// engine.c things
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c things
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// draw.c things
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// player.c things
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

extern Entity* player;
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Tile** map;

#endif
