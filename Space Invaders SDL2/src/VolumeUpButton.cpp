// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "VolumeUpButton.h"
#include <string>
#include "System.h"

using namespace std;
using namespace spacewing;

VolumeUpButton::VolumeUpButton(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl)
    : Button(x, y, w, h, upButtonUrl, pressButtonUrl)
{
}

std::shared_ptr<VolumeUpButton> VolumeUpButton::create(int x, int y, int w, int h, const string &upButtonUrl, const string &pressButtonUrl)
{
    return std::shared_ptr<VolumeUpButton>(new VolumeUpButton(x, y, w, h, upButtonUrl, pressButtonUrl));
}

VolumeUpButton::~VolumeUpButton()
{
}

void VolumeUpButton::perform(Button *source)
{

    sys.volumeUp();
}
