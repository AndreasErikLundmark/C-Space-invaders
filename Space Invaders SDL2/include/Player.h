// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"
#include <string>
#include "GameEngine.h"
#include <memory>


class Player : public spacewing::Sprite
{

public:
    static std::shared_ptr<Player> create(int x, int y, int w, int h, const std::string &s);

    virtual ~Player() override;
    virtual void tick() override;

    virtual void leftKeyDown() override;
    virtual void rightKeyDown() override;
    virtual void upKeyDown() override;
    virtual void fireTrigger();
    virtual void leftKeyUp() override;
    virtual void rightKeyUp() override;
    virtual void upKeyUp() override;
    virtual void positionTracker();
    virtual void setSpeed(int n);

protected:
    Player(int x, int y, int w, int h, const std::string &s);

private:
    Player(const Player &other) = delete;
    const Player &operator=(const Player &other) = delete;

    int direction = 0;
    int speed = 1;
    bool fire = false;
    bool fireControl = false;
    bool move = false;
    int middleX;
};

#endif
