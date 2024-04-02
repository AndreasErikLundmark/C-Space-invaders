// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>

class Label : public spacewing::Sprite
{

public:
    static std::shared_ptr<Label> create(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b);

    virtual ~Label() override;

protected:
    Label(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b);

private:
    std::string text;
};

#endif