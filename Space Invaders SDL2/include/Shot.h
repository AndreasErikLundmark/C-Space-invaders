// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef SHOT_H
#define SHOT_H
#include "Sprite.h"
#include <string>
#include "GameEngine.h"
#include <memory>

class Shot : public spacewing::Sprite
{

public:

    static std::shared_ptr<Shot>create(int x, int y, int w, int h, const std::string& s);

    virtual ~Shot() override;
    virtual void tick() override;

protected:
    Shot(int x, int y, int w, int h, const std::string& s);
  

private:
    Shot(const Shot &other) = delete;
    const Shot &operator=(const Shot &) = delete;
    int counter = 0;
    int slowSpeed = 1;

};

#endif