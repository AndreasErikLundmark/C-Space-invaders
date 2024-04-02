// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "Shot.h"
#include "System.h"
#include "Constants.h"
#include "GameEngine.h"
#include <memory>


using namespace std;
using namespace spacewing;

std::shared_ptr<Shot> Shot::create(int x, int y, int w, int h, const std::string &s)
{
    return std::shared_ptr<Shot>(new Shot(x, y, w, h, s));
}

Shot::Shot(int x, int y, int w, int h, const std::string &s) : Sprite(x, y, w, h, s)
{

    setSurf(s);
    removeWhite(surf);
    setTexture(surf);
    slowSpeed = game.getSlowShotSpeed();
}

Shot::~Shot(){
    
}


void Shot::tick()
{

    counter++;

    if (rect.y < 5)
    {
        game.remove(shared_from_this());
    }
    else if (counter % slowSpeed == 0)
    {
        rect.y--;
    }
}


