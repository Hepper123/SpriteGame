#include "SpriteBase.h"

class UserSprite : public SpriteBase
{
private:
    int v;
public:
    UserSprite(int x, int y, int v, int width, int high, ACL_Image* img);
    ~UserSprite(){};
    void PickDirection(int key);
    void ResetDirection(int key);
};