// Spelmotorklass.
// Andreas Lundmark, anlu0845 C++ HT23

#include "Button.h"
#include "System.h"
#include "Constants.h"

using namespace std;
namespace spacewing
{

    std::shared_ptr<Button> Button::create(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl)
    {
        return std::shared_ptr<Button>(new Button(x, y, w, h, upButtonUrl, pressButtonUrl));
    }

    Button::Button(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl) : Sprite(x, y, w, h)
    {
        string txt = "";

        upButton = IMG_LoadTexture(sys.get_ren(), upButtonUrl.c_str());
        pressButton = IMG_LoadTexture(sys.get_ren(), pressButtonUrl.c_str());
    }
    Button::~Button() // destructor
    {
        SDL_DestroyTexture(upButton);
        SDL_DestroyTexture(pressButton);
    }

    void Button::mouseDown(const SDL_Event &event)
    {
        SDL_Point p = {event.button.x, event.button.y};
        if (SDL_PointInRect(&p, &getRect()))
        {
            isDown = true;
        }
    }
    void Button::mouseUp(const SDL_Event &event)
    {
        SDL_Point p = {event.button.x, event.button.y};
        if (SDL_PointInRect(&p, &getRect()))
        {
            isDown = false;
            perform(this);
        }
    }
    void Button::draw() const
    {
        if (isDown)
        {
            SDL_RenderCopy(sys.get_ren(), pressButton, NULL, &getRect());
        }
        else
        {
            SDL_RenderCopy(sys.get_ren(), upButton, NULL, &getRect());
        }
    }

}
