#include "EscapedSprite.h"

EscapedSprite::EscapedSprite(int x, int y, int v, int width, int high, ACL_Image *img) : SpriteBase(x, y, 0, 0, width, high, img)
{
    this->v = v;
}

void EscapedSprite::escape(SpriteBase *userSprite)
{
    int x1 = this->x + this->width / 2;
    int x2 = userSprite->x + userSprite->width / 2;
    int y1 = this->y + this->high / 2;
    int y2 = userSprite->y + userSprite->high / 2;
    double x_ = x1 - x2;
    double y_ = y1 - y2;
    dx = v * x_ / sqrt(x_ * x_ + y_ * y_);
    dy = v * y_ / sqrt(x_ * x_ + y_ * y_);
}