// Spelklass. Subklass till sprite
//Andreas Lundmark, anlu0845 C++ HT23

#include "Enemy.h"
#include "Sprite.h"
#include "Constants.h"
#include "System.h"
#include "GameEngine.h"
#include "Player.h"

using namespace std;

using namespace spacewing;

std::shared_ptr<Enemy> Enemy::create(int x, int y, int w, int h, const std::string &s)
{
    return std::shared_ptr<Enemy>(new Enemy(x, y, w, h, s));
}

Enemy::Enemy(int x, int y, int w, int h, const std::string &s) : Sprite(x, y, w, h)
{

    setSurf(s);
    removeWhite(surf);
    setTexture(surf);
}

Enemy::~Enemy(){

}


void Enemy::setSlowerSpeed(int n){
    if(n<0){
        throw std::invalid_argument("Speed cannot be negative");
    }else{
    slowerSpeed = n;
    }
}

void Enemy::tick()
{

    counter++;

    std::shared_ptr<Sprite> s = game.collisionDetect(shared_from_this());

    if (s != nullptr)
    {
        if (auto p = dynamic_pointer_cast<Player>(s))
        {
            game.gameOver(250, 350, 200, 40, "Game Over", 255, 255, 255);
        }
    }

    if (rect.y >= 620)
    {
        game.remove(shared_from_this());
    }
    else if (counter % slowerSpeed == 0)
    {
        rect.y++;
    }
}
