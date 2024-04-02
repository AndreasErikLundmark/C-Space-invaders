// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

# ifndef VOLUMEUPBUTTON_H
# define VOLUMEUPBUTTON_H
#include "Button.h"
#include <string>




class VolumeUpButton : public spacewing::Button{

public:

static std::shared_ptr<VolumeUpButton> create(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);
virtual ~VolumeUpButton() override;
virtual void perform(Button* source) override;



protected:

    VolumeUpButton(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);


};




#endif