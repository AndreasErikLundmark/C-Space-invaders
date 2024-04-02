// Spelmotorklass. 
// Andreas Lundmark, anlu0845 C++ HT23

#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "VolumeBar.h"
#include <string>
#include <vector>
#include "System.h"

namespace spacewing
{

    class System
    {

    public:
        SDL_Renderer *get_ren() const;
        TTF_Font *get_font() const;
        SDL_Texture *get_texture() const;

        void set_master_volume(int x);
        int get_master_volume();
        void add_music(const std::string &songUrl);
        void next_song();
        void pause();
        void resume();
        void volumeUp();
        void volumeDown();
        void setSongUrl(const std::string& s);

        void setWindowWidth(int x);
        void setWindowHeight(int y);
        void setMainWindow(int x, int y);
        void setBackGround(const std::string& s);
  
        System();
        ~System();

    private:
      
        System(const System &other) = delete;
        const System &operator=(const System &other) = delete;
        SDL_Window *win;     // Main window
        SDL_Surface *bgSurf; // background surface
        SDL_Texture *bgTx;
        SDL_Renderer *ren;
        TTF_Font *font;
        Mix_Music *mus;
        
        int masterVolume = 128;

        std::string songUrl;
        std::vector<std::string> songs;
        int currentSongIndex = 0;
        int windowHeight = 700;
        int windowWidth = 700;
        std::string backGroundUrl;

    };

    extern System sys;
}
#endif