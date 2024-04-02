// Spelmotorklass. Basklass till alla sprites
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <memory>


namespace spacewing
{

    class Sprite : public std::enable_shared_from_this<Sprite>
    {

    public:
        virtual ~Sprite();
        virtual void mouseDown(const SDL_Event &) {}
        virtual void mouseUp(const SDL_Event &) {}
        virtual void keyDown(const SDL_Event &);
        virtual void keyUp(const SDL_Event &);
        virtual void draw() const;
        virtual void tick(){};
        virtual void setSurf(const std::string& s) ;
        virtual void setTextSurf(const std::string& s, unsigned char r, unsigned char g, unsigned char b);
        virtual void removeWhite(SDL_Surface* s);
        virtual void setTexture(SDL_Surface* s);


        virtual void leftKeyDown(){};
        virtual void rightKeyDown(){};
        virtual void upKeyDown(){};
        virtual void leftKeyUp(){};
        virtual void rightKeyUp(){};
        virtual void upKeyUp(){};

        const SDL_Rect &getRect() const
        {
            return rect;
        }

    protected:
        Sprite(int x, int y, int w, int h, const std::string& s);
        Sprite(int x, int y, int w, int h);
        SDL_Rect rect; // rectangle for every 2d object
        SDL_Texture *texture;
        SDL_Surface *surf;

    private:
        Sprite(const Sprite &other) = delete;             // prevents copying of Sprite
        const Sprite &operator=(const Sprite &) = delete; // prevents allocation of Sprite
   
    };
    using smartPointer = std::shared_ptr<Sprite>;
}
#endif