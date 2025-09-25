#ifndef APP_H_
#define APP_H_

namespace csci3081 {
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
}

#endif