#ifndef GAME
#define GAME
#include "acllib.h"
#include <math.h>

const int WIDTH = 1280;
const int HIGH = 720;

class SpriteBase
{
public:
    int x, y;
    int dx, dy;
    int width, high;
    ACL_Image *img;
    SpriteBase(int x, int y, int dx, int dy, int width, int high, ACL_Image *img);
    virtual ~SpriteBase(){};
    void move();
    void show();
    friend bool collision(SpriteBase *a, SpriteBase *b);
};

#endif