// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "Button.h"
#include "VolumeBar.h"
#include "NextSongButton.h"
#include <string>

using namespace spacewing;

NextSongButton::NextSongButton(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl)
:Button(x,y,w,h,upButtonUrl,pressButtonUrl){

}

std::shared_ptr<NextSongButton> NextSongButton::create(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl){
    return std::shared_ptr<NextSongButton>(new NextSongButton(x,y,w,h,upButtonUrl,pressButtonUrl));
}

NextSongButton::~NextSongButton(){

}

void NextSongButton::perform(Button* source){
    sys.next_song();
}


