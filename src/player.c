#include <rogue.h>

Entity *createPlayer(Position start_pos)
{
    Entity *newPlayer = calloc(1, sizeof(Entity));

    newPlayer->pos.x = start_pos.x;
    newPlayer->pos.y = start_pos.y;
    newPlayer->ch = '@';
    newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);
    newPlayer->FOVRadius = 15;
    newPlayer->visible = true;
    newPlayer->seen = true;

    return newPlayer;
}

void handleInput(int input)
{
    Position newPos = {player->pos.y, player->pos.x};

    switch (input)
    {
    case 'k':
        newPos.y--;
        break;
    case 'j':
        newPos.y++;
        break;
    case 'h':
        newPos.x--;
        break;
    case 'l':
        newPos.x++;
        break;
    case 'y':
        newPos.x--;
        newPos.y--;
        break;
    case 'u':
        newPos.x++;
        newPos.y--;
        break;
    case 'b':
        newPos.x--;
        newPos.y++;
        break;
    case 'n':
        newPos.x++;
        newPos.y++;
        break;

    case ',':
        handlePickup(player->pos);
        break;

    default:
        break;
    }

    movePlayer(newPos);
}

void handlePickup(Position pos)
{
    // iterate from end of list as they may be stacked 
    for (int i = TOTAL_ITEMS - 1; i >= 0; --i)
    {
        if ((pos.x == items[i]->pos.x) && (pos.y == items[i]->pos.y))
        {
            items[i]->ch = '~';
            removeItem(i);
        }
    }
}

void removeItem(int idx)
{
    if ((idx < 0) || (idx > MAX_ITEMS - 1))
        return;
    else
    {
        for (int i = idx; i < MAX_ITEMS - 1; i++)
        {
            items[i] = items[i + 1];
        }
        --TOTAL_ITEMS;
    }
}

void movePlayer(Position newPos)
{
    if (map[newPos.y][newPos.x].walkable)
    {
        clearFOV(player);
        player->pos.y = newPos.y;
        player->pos.x = newPos.x;
        makeFOV(player);
    }
}