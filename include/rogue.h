#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// colors
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2
#define VISIBLE_ITEM_COLOR 3
#define SEEN_ITEM_COLOR 4
#define UI_LABEL_COLOR 5
#define UI_VALUE_COLOR 6

typedef struct
{
    int y;
    int x;
} Position;

typedef struct
{
    Position pos;
    char ch;
    int color;
    int FOVRadius;
    bool visible;
    bool seen;
    int HP;
    int maxHP;
} Entity;

typedef struct
{
    char ch;
    bool walkable;
    int color;
    bool transparent;
    bool visible;
    bool seen;
} Tile;

typedef struct
{
    int height;
    int width;
    Position pos;
    Position center;
} Room;

// enums
enum ItemTypes {
    SCROLL_OF_TELEPORT,
    HP_POTION,
    MP_POTION,
};

// engine.c things
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c things
Tile **createMapTiles(void);
Position setupMap(void);
Position generateCAMap(void);
void freeMap(void);
Position getOpenCell(void);

// draw.c things
void drawMap(void);
void drawEntity(Entity *entity);
void drawEverything(void);
void drawUI(void);

// player.c things
Entity *createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);
void handlePickup(Position pos);
void removeItem(int idx);

// items.c things
Entity **createItems(void);
Entity *createItem(Position pos, enum ItemTypes itemType);

// room.c things
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// utils.c things
int getRandomInt(int begin, int end);
float getRandomFloat(float begin, float end);

// fov.c things
void makeFOV(Entity *player);
void clearFOV(Entity *player);
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);

extern Entity *player;
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern const int MAX_ITEMS;
extern int TOTAL_ITEMS;
extern Tile **map;
extern Entity **items;

#endif
