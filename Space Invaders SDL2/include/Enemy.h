// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"
#include "GameEngine.h"

class Enemy : public spacewing::Sprite
{

public:
    static std::shared_ptr<Enemy> create(int x, int y, int w, int h, const std::string &s);

    virtual ~Enemy() override;
    virtual void tick() override;
    virtual void setSlowerSpeed(int n);

protected:
    Enemy(int x, int y, int w, int h, const std::string &s);

private:
    Enemy(const Enemy &other) = delete;
    const Enemy &operator=(const Enemy &other) = delete;
    int counter = 0;
    int slowerSpeed = 1;
};

#endif
