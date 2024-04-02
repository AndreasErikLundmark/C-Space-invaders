// Spelmotorklass. Basklass till alla sprites
// Andreas Lundmark, anlu0845 C++ HT23

#include "Sprite.h"
#include "Constants.h"
#include "System.h"

using namespace std;

namespace spacewing
{

    Sprite::Sprite(int x, int y, int w, int h, const std::string &s) : rect{x, y, w, h}
    {
        setSurf(s);
    }

    Sprite::Sprite(int x, int y, int w, int h) : rect{x, y, w, h}
    {
    }

    Sprite::~Sprite()
    {
   if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    if (surf != nullptr) {
        SDL_FreeSurface(surf);
        surf = nullptr;
    }
    }

    void Sprite::setSurf(const std::string &s)
    {

        surf = IMG_Load((constants::gResPath + s).c_str());
        if (surf == nullptr)
        {
            throw std::invalid_argument("No image loaded to surf");
        }
    }

    void Sprite::setTextSurf(const std::string &s, unsigned char r, unsigned char g, unsigned char b)
    {
        surf = TTF_RenderText_Solid(sys.get_font(), s.c_str(), {r, g, b});
    }

    void Sprite::removeWhite(SDL_Surface *s)
    {
    Uint32 white = SDL_MapRGB(s->format, 255, 255, 255);
        SDL_SetColorKey(s, SDL_TRUE, white);
    }

    void Sprite::setTexture(SDL_Surface *s)
    {
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), s);
    }

    void Sprite::draw() const
    {
        const SDL_Rect &rect = getRect();
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
    }

    void Sprite::keyDown(const SDL_Event &event)
    {
        SDL_Keycode keyPressed = event.key.keysym.sym;

        switch (keyPressed)
        {
        case SDLK_LEFT:
            leftKeyDown();
            break;

        case SDLK_RIGHT:
            rightKeyDown();
            break;
        case SDLK_UP:
            upKeyDown();
            break;
        }
    }

    void Sprite::keyUp(const SDL_Event &event)
    {
        SDL_Keycode keyPressed = event.key.keysym.sym;

        switch (keyPressed)
        {
        case SDLK_LEFT:
            if (!(SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT] || SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT]))
            {
                leftKeyUp();
            }

            break;
        case SDLK_RIGHT:
            if (!(SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT] || SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT]))
            {
                rightKeyUp();
            }
            break;

        case SDLK_UP:
            upKeyUp();
            break;
        }
    }

}