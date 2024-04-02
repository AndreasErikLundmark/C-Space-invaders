// Spelklass. Subklass till sprite
// Andreas Lundmark, anlu0845 C++ HT23

#include "Label.h"
#include "System.h"

    using namespace spacewing;

    using namespace std;

     std::shared_ptr<Label> Label::create(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b)
    {
        return std::shared_ptr<Label> (new Label(x, y, w, h, txt,r,g,b));
    }

    Label::Label(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b) : Sprite(x, y, w, h)
    {

        setTextSurf(txt, r,g,b);
        setTexture(surf);

    }


    Label::~Label()
    {

      
    }




