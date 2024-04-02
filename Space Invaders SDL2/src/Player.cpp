// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "Player.h"
#include "Constants.h"
#include "System.h"
#include "GameEngine.h"
#include <string>
#include "Shot.h"

#include "Label.h"
#include "Sprite.h"
#include <vector>
#include <iostream>
#include <memory>


using namespace spacewing;

std::shared_ptr<Player> Player::create(int x, int y, int w, int h, const std::string &s)
{
    return std::shared_ptr<Player>(new Player(x, y, w, h, s));
}

Player::Player(int x, int y, int w, int h, const std::string &s) : Sprite(x, y, w, h), middleX(x + w / 2)
{
    setSurf(s);
    removeWhite(surf);
    setTexture(surf);
}

Player::~Player()
{

}


void Player::leftKeyDown()
{
    move = true;
    direction = -speed;
}
void Player::rightKeyDown()
{
    move = true;
    direction = speed;
}
void Player::upKeyDown()
{
    fire = true;
}

void Player::fireTrigger()
{

    if (fire && !fireControl)
    {
        // creating new shot/bullet
        std::shared_ptr<Shot> shot = Shot::create(middleX, getRect().y, 5, 10, "images/bullet4.png");
        game.add(shot);
        fireControl = true;
    }
    else if (!fire)
    {
        fireControl = false;
    }
}

void Player::leftKeyUp()
{
    move = false;
    direction = 0;
}

void Player::rightKeyUp()
{
    move = false;
    direction = 0;
}

void Player::upKeyUp()
{
    fire = false;
}

void Player::positionTracker()
{

    rect.x += direction;
    // middleX for calculating shot position ( center of player ship );
    middleX = rect.x + (rect.w / 2);

    // Boundary checks and stops player if reaching limit
    if (rect.x > 660)
    {
        direction = 0;
        rect.x = 659;
    }
    else if (rect.x < 10)
    {
        direction = 0;
        rect.x = 11;
    }
}

void Player::setSpeed(int n)
{
    if(n<1){
        throw std::invalid_argument("Player setSpeed must be at least 1");
    }
    speed = n;
}

void Player::tick()
{

    positionTracker();
    fireTrigger();
}
