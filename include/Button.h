#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Image.h"
#include "ShaderProgram.h"
#include "Glyph.h"

namespace csci3081{

class Button : public Glyph {
public:
    Button(float x, float y, float w, float h, const Image& image);

    void update(const Image& image);
    int getWidth() const { return buttonImgWidth; }
    int getHeight() const { return buttonImgHeight; }
    unsigned char* getImg() const { return buttonImg; }
    void draw();
    bool contains(float buttonX, float buttonY);
    void setHighlighted(bool highlighted) { this->buttonHighlighted = highlighted; }
    void setClicked(bool clicked) { this->buttonClicked = clicked; }
    bool isHighlighted() { return buttonHighlighted; }

private:
    int buttonWidth = 0.01;
    int buttonHeight = 0.01;
    unsigned char* buttonImg;
    int buttonImgWidth, buttonImgHeight, buttonImgChannels;
    float buttonX = 0.01;
    float buttonY = 0.01;

    bool buttonHighlighted = false;
    bool buttonClicked = false;
    unsigned int textureID;
};

}


#endif //BUTTON_H