#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"

namespace csci3081{

class Button {
public:
    Button();
    // Button(int buttonImgWidth, int buttonImgHeight);
    ~Button();

    void load_button(const std::string& filename, int& width, int& height, int& channels);
    void load(const std::string& filename);
    int getWidth() const { return buttonImgWidth; }
    int getHeight() const { return buttonImgHeight; }
    unsigned char* getImg() const { return buttonImg; }
    void draw();

private:
    float buttonImgWidth, buttonImgHeight, buttonImgChannels;
    float buttonX, buttonY,  buttonWidth, buttonHeight;
    bool buttonHighlighted, buttonClicked;
    unsigned char *buttonImg;
};

}


#endif //BUTTON_H