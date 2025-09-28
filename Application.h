#ifndef APPLICATION_H
#define APPLICATION_H

#include "Button.h"

namespace csci3081{

class Application{
public:
    Application();
    ~Application();
    int run();

    
public:
    int windowWidth;
    int windowHeight;
    float buttonWidth;
    float buttonHeight;
    float buttonX;
    float buttonY;
    bool buttonHighlighted;
    bool buttonClicked;
    bool drawing = false;
    int imgWidth;
    int imgHeight;
    unsigned char* img;
    Button* button = nullptr;
};

}


#endif
