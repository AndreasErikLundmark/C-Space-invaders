// Spelmotorklass. 
// Andreas Lundmark, anlu0845 C++ HT23

#include "System.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include "Constants.h"
#include <string>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include "GameEngine.h"
using namespace std;
namespace spacewing
{

    System::System()

    {
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_PNG);

        setMainWindow(windowWidth, windowHeight);
        setBackGround(backGroundUrl);

        TTF_Init();
        font = TTF_OpenFont((constants::gResPath + "fonts/Perfect DOS VGA 437 Win.ttf").c_str(), 20); // font and fontsize

        Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
        setSongUrl("sounds/cinematic-atmosphere.mp3");
        mus = Mix_LoadMUS((songUrl).c_str());
        Mix_PlayMusic(mus, -1);
    }

    System::~System()
    {
        Mix_FreeMusic(mus);
        Mix_CloseAudio();
        SDL_DestroyTexture(bgTx);
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        songs.clear();
        TTF_CloseFont(font);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    SDL_Renderer *System::get_ren() const
    {
        return ren;
    }

    TTF_Font *System::get_font() const
    {
        return font;
    }

    SDL_Texture *System::get_texture() const
    {
        return bgTx;
    }

    void System::set_master_volume(int x)
    {
        masterVolume = x;
        Mix_VolumeMusic(masterVolume);
    }

    int System::get_master_volume()
    {
        return masterVolume;
    }
    void System::add_music(const std::string &songUrl)
    {
        songs.push_back(songUrl);
    }
    void System::next_song()
    {

        Mix_FreeMusic(mus);

        int nextSongIndex = currentSongIndex + 1;

        if (currentSongIndex == (songs.size() - 1))
        {
            nextSongIndex = 0;
        }

        songUrl = constants::gResPath + songs[nextSongIndex];

        if (mus == nullptr)
        {
            throw std::invalid_argument("No music found");
        }

        mus = Mix_LoadMUS((songUrl).c_str());
        Mix_PlayMusic(mus, -1);
        currentSongIndex = nextSongIndex;
    }

    void System::setSongUrl(const std::string &s)
    {
        songUrl = constants::gResPath + s;
    }

    void System::pause()
    {
        Mix_Pause(-1);
    }
    void System::resume()
    {
        Mix_Resume(-1);
    }

    void System::volumeUp()
    {

        int volume = sys.get_master_volume();
        volume += 42;
        sys.set_master_volume(volume);
    }

    void System::volumeDown()
    {
        int volume = sys.get_master_volume();
        volume -= 42;
        sys.set_master_volume(volume);
    }

    void (System::*mfunc)();

    void System::setMainWindow(int x, int y)
    {
        setWindowWidth(x);
        setWindowHeight(y);

        win = SDL_CreateWindow("SpaceWindow", SDL_WINDOWPOS_CENTERED, // main window
                               SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
        ren = SDL_CreateRenderer(win, -1, 0);
    }

    void System::setBackGround(const std::string &s)
    {

        backGroundUrl = s;
        bgSurf = IMG_Load((constants::gResPath + s).c_str()); // background img

        bgTx = SDL_CreateTextureFromSurface(ren, bgSurf);
        SDL_FreeSurface(bgSurf);
    }

    void System::setWindowWidth(int x)
    {
        windowWidth = x;
    }
    void System::setWindowHeight(int y)
    {
        windowHeight = y;
    }

    System sys;
}