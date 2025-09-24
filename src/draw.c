#include <rogue.h>

void drawMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (map[y][x].visible)
            {
                mvaddch(y+1, x, map[y][x].ch | map[y][x].color);
            }
            else if (map[y][x].seen)
            {
                mvaddch(y+1, x, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
            }
            else
            {
                mvaddch(y+1, x, ' ');
            }
        }
    }
}

void drawEntity(Entity *entity)
{
    if (entity->visible)
        mvaddch(entity->pos.y+1, entity->pos.x, entity->ch | entity->color);
    else if (entity->seen)
        mvaddch(entity->pos.y+1, entity->pos.x, entity->ch | COLOR_PAIR(SEEN_ITEM_COLOR));
}

void drawItems(void)
{
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        drawEntity(items[i]);
    }
}

void drawUI(void)
{
    char ui[] = "rogue.c // HP: ";
    int length = strlen(ui);
    for (int i = 0; i < length; i++) 
        mvaddch(0, i, ui[i] | COLOR_PAIR(UI_LABEL_COLOR));
    attron(COLOR_PAIR(UI_VALUE_COLOR));
    mvprintw(0, length, "%d/%d", player->HP, player->maxHP);
    refresh();

}

void drawEverything(void)
{
    clear();
    drawMap();
    drawItems();
    drawEntity(player);
    drawUI();
}
