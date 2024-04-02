#ifndef VOLUMEBAR_H
#define VOLUMEBAR_H
#include "Sprite.h"
#include "System.h"
#include <vector>

namespace spacewing{

class VolumeBar : public Sprite{

    public: 

    static VolumeBar* create(int x, int y, int w, int h);
 

    void set_level_icon(int currentLevel);
    void draw() const;
    // void tick();
    void loadTextures();

    ~VolumeBar();

    protected: 

        VolumeBar(int x, int y, int w, int h);
   

    private: 

    SDL_Texture* volumeIconDefault = nullptr;
    SDL_Texture* currentIcon = nullptr;
    SDL_Surface* volumeIconHighSurf = nullptr;
    SDL_Surface* volumeIconMediumSurf = nullptr;
    SDL_Surface* volumeIconLowSurf = nullptr;
    SDL_Surface* volumeIconSilentSurf = nullptr;
    SDL_Texture* volumeIconHigh = nullptr;
    SDL_Texture* volumeIconMedium = nullptr;
    SDL_Texture* volumeIconLow = nullptr;
    SDL_Texture* volumeIconSilent = nullptr;

    std::vector<SDL_Surface*> surfs; 

    // enum VolumeLevel{
    //     High =128,
    //     Medium = 84,
    //     Low = 42
    // };

    
};

// extern VolumeBar vbar;

}



#endif