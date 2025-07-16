#include <rogue.h>

Tile **createMapTiles(void)
{
    Tile **tiles = calloc(MAP_HEIGHT, sizeof(Tile *));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';
            tiles[y][x].walkable = false;
            tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
            tiles[y][x].transparent = false;
            tiles[y][x].seen = false;
            tiles[y][x].visible = false;
        }
    }

    return tiles;
}

// https://www.roguebasin.com/index.php/Cellular_Automata_Method_for_Generating_Random_Cave-Like_Levels
Position generateCAMap(void)
{
    Position start_pos;

    return start_pos;
}

Position setupMap(void)
{
    int x, y, width, height, n_rooms;
    Position start_pos;
    n_rooms = getRandomInt(5, 35);
    Room *rooms = calloc(n_rooms, sizeof(Room));

    for (int i = 0; i < n_rooms; i++)
    {
        x = getRandomInt(2, MAP_WIDTH - 20);
        y = getRandomInt(2, MAP_HEIGHT - 10);
        width = getRandomInt(5, 20);
        height = getRandomInt(3, 10);

        rooms[i] = createRoom(y, x, height, width);
        addRoomToMap(rooms[i]);

        // hallways
        if (i > 0)
        {
            connectRoomCenters(rooms[i - 1].center, rooms[i].center);
        }
    }

    start_pos.x = rooms[0].center.x;
    start_pos.y = rooms[0].center.y;

    free(rooms);

    return start_pos;
}

void freeMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
}

// should be tracking this in some kind of list
Position getOpenCell(void)
{
    Position pos;
    bool done = false;
    while (!done)
    {
        pos.x = getRandomInt(1, MAP_WIDTH - 1);
        pos.y = getRandomInt(1, MAP_HEIGHT - 1);

        if (map[pos.y][pos.x].walkable)
        {
            done = true;
            break;
        }
    }

    return pos;
}