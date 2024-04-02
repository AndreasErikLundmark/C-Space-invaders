#ifndef NEXTSONGBUTTON_H
#define NEXTSONGBUTTON_H
#include "Button.h"


class NextSongButton : public spacewing::Button{

public: 

    static std::shared_ptr<NextSongButton>create(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);

    virtual ~NextSongButton()override;
    virtual void perform(Button* source) override;

protected:

    NextSongButton(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);

};




#endif