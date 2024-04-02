// Spelmotorklass.
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef BUTTON_H
#define BUTTON_H
#include "Sprite.h"
#include <memory>

namespace spacewing
{

    class Button : public Sprite
    {

    public:
        static std::shared_ptr<Button> create(int x, int y, int w, int h, const std::string &upButtonUrl, const std::string &pressButtonUrl);
        virtual void mouseDown(const SDL_Event &) override;
        virtual void mouseUp(const SDL_Event &) override;
        virtual void draw() const override;
        virtual void perform(Button *source){};

        virtual ~Button() override;

    protected:
        Button(int x, int y, int w, int h, const std::string &upButtonUrl, const std::string &pressButtonUrl);

    private:
        SDL_Texture *upButton, *pressButton;

        bool isDown = false;
    };

}

#endif