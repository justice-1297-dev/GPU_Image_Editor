#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"
#include "ShaderProgram.h"

namespace csci3081{

class Button {
public:
    Button(float x, float y, float w, float h, const Image& image);

    void update(const Image& image);
    int getWidth() const { return buttonImgWidth; }
    int getHeight() const { return buttonImgHeight; }
    unsigned char* getImg() const { return buttonImg; }
    void draw(const ShaderProgram& shader) const;
    bool contains(float buttonX, float buttonY);
    void setHighlighted(bool highlighted) { this->buttonHighlighted = highlighted; }
    void setClicked(bool clicked) { this->buttonClicked = clicked; }
    bool isHighlighted() { return buttonHighlighted; }

private:
    int buttonWidth;
    int buttonHeight;
    unsigned char* buttonImg;
    int buttonImgWidth, buttonImgHeight, buttonImgChannels;
    float buttonX;
    float buttonY;

    bool buttonHighlighted = false;
    bool buttonClicked = false;
    unsigned int textureID;
};

}


#endif //BUTTON_H