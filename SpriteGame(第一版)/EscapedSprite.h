#include "SpriteBase.h"

class EscapedSprite : public SpriteBase
{
private:
    int v;
public:
    EscapedSprite(int x, int y, int v, int width, int high, ACL_Image* img);
    ~EscapedSprite(){}
    void escape(SpriteBase* usersprite);
};