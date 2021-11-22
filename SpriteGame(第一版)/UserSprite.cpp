#include "UserSprite.h"

UserSprite::UserSprite(int x, int y, int v, int width, int high, ACL_Image *img) : SpriteBase(x, y, 0, 0, width, high, img)
{
    this->v = v;
}

void UserSprite::PickDirection(int key)
{
    switch (key)
    {
    case VK_UP:
        dx = 0;
        dy = -v;
        break;
    case VK_DOWN:
        dx = 0;
        dy = v;
        break;
    case VK_LEFT:
        dx = -v;
        dy = 0;
        break;
    case VK_RIGHT:
        dx = v;
        dy = 0;
        break;
    default:
        break;
    }
}

void UserSprite::ResetDirection(int key)
{
    switch (key)
    {
    case VK_UP:
        dy = 0;
        break;
    case VK_DOWN:
        dy = 0;
        break;
    case VK_LEFT:
        dx = 0;
        break;
    case VK_RIGHT:
        dx = 0;
        break;
    default:
        break;
    }
}
