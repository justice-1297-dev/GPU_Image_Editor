#ifndef APPLICATION_H
#define APPLICATION_H

namespace csci3081{

class Application{
public:
    Application();
    int run();
struct App {
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
};
private:
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
};

}


#endif