#ifndef VOLUMEBUTTONDOWN_H
#define VOLUMEBUTTONDOWN_H
#include "Button.h"
#include "System.h"




class VolumeButtonDown : public spacewing::Button{

public: 

    static std::shared_ptr<VolumeButtonDown>create(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);

    virtual ~VolumeButtonDown() override;
    virtual void perform(Button* source) override;

protected:

    VolumeButtonDown(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);

};








#endif