// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "VolumeButtonDown.h"
#include "VolumeBar.h"

using namespace std;
using namespace spacewing;

VolumeButtonDown::VolumeButtonDown(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl)
    : Button(x, y, w, h, upButtonUrl, pressButtonUrl)
{
}

std::shared_ptr<VolumeButtonDown> VolumeButtonDown::create(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl)
{
    return std::shared_ptr<VolumeButtonDown>(new VolumeButtonDown(x, y, w, h, upButtonUrl, pressButtonUrl));
}

VolumeButtonDown::~VolumeButtonDown(){
    
} 

void VolumeButtonDown::perform(Button *source)
{

    sys.volumeDown();
}
