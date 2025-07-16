#include <rogue.h>

// returns random int [begin, end)
int getRandomInt(int begin, int end)
{
    return (int)((rand() % (end - begin)) + begin);
}

// returns random float [begin, end)
float getRandomFloat(float begin, float end)
{
    return ((end - begin) * ((float)rand() / RAND_MAX)) + begin;
}