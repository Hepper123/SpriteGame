#include "SpriteBase.h"

SpriteBase::SpriteBase(int x, int y, int dx, int dy, int width, int high, ACL_Image *img)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->width = width;
	this->high = high;
	this->img = img;
}

void SpriteBase::show()
{
	putImageScale(img, x, y, width, high);
}

bool inCube(int x, int y, int x0, int x1, int y0, int y1)
{
	bool flag = 0;
	if (x > x0 && x < x1 && y > y0 && y < y1)
		flag = true;
	return flag;
}

bool collision(SpriteBase *a, SpriteBase *b)
{
	bool flag = 0;
	if (inCube(a->x, a->y,
			   b->x, b->x + b->width, b->y, b->y + b->high))
		flag = 1;
	if (inCube(a->x + a->width, a->y,
			   b->x, b->x + b->width, b->y, b->y + b->high))
		flag = 1;
	if (inCube(a->x, a->y + a->high,
			   b->x, b->x + b->width, b->y, b->y + b->high))
		flag = 1;
	if (inCube(a->x + a->width, a->y + a->high,
			   b->x, b->x + b->width, b->y, b->y + b->high))
		flag = 1;
	return flag;
}

void SpriteBase::move()
{
	if (x + dx > 0 && x + dx < WIDTH-width)
	{
		x += dx;
	}
	if (y + dy > 0 && y + dy < HIGH-high)
	{
		y += dy;
	}
}