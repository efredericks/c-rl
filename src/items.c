#include <rogue.h>

// setup all items
Entity **createItems(void)
{
    Entity **items = calloc(MAX_ITEMS, sizeof(Entity *));

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        int itemID = getRandomInt(0, 3);
        Position p = getOpenCell();
        Entity *item = createItem(p, itemID);
        items[i] = item;
    }
    TOTAL_ITEMS = MAX_ITEMS;

    return items;
}

// add individual item
Entity *createItem(Position pos, enum ItemTypes itemType)
{
    Entity *newItem = calloc(1, sizeof(Entity));

    char ch = ' ';
    switch (itemType)
    {
    case SCROLL_OF_TELEPORT:
        ch = '!';
        break;
    case HP_POTION:
        ch = 'H';
        break;
    case MP_POTION:
        ch = 'M';
        break;
    default:
        break;
    }

    newItem->pos.x = pos.x;
    newItem->pos.y = pos.y;
    newItem->ch = ch;
    newItem->color = COLOR_PAIR(VISIBLE_ITEM_COLOR);
    newItem->FOVRadius = -1;
    newItem->visible = false;
    newItem->seen = false;

    return newItem;
}