#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"

namespace csci3081{

class Button {
public:
    Button(int buttonImgWidth, int buttonImgHeight);
    ~Button();

    void load(const std::string& filename);
    void draw();

private:
    int buttonImgWidth, buttonImgHeight, buttonImgChannels;
    float buttonX, buttonY,  buttonWidth, buttonHeight;
    bool buttonHighlighted, buttonClicked;
    unsigned char *buttonImg = load_image("reset.png", buttonImgWidth, buttonImgHeight, buttonImgChannels);
};

}


#endif //BUTTON_H