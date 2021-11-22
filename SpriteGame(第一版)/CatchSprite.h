#include "SpriteBase.h"

class CatchSprite : public SpriteBase
{
private:
    int v;

public:
    CatchSprite(int x, int y, int v, int width, int high, ACL_Image *img);
    ~CatchSprite(){};
    void SelectDirection(SpriteBase *usersprite);
};