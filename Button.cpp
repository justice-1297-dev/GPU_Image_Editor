#include "Button.h"
#include "Application.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>
namespace csci3081 {

Button::Button()
    : buttonImgWidth(0), buttonImgHeight(0), buttonImgChannels(0), buttonImg(nullptr),
    buttonX(0.01f), buttonY(0.01f), buttonWidth(0.1f), buttonHeight(0.1f),
    buttonHighlighted(false), buttonClicked(false) {}
Button::Button(int buttonImgWidth, int buttonImgHeight){
    float aspect = 1.0f*buttonImgWidth/buttonImgHeight;
    buttonX = 0.01;
    buttonY = 0.01;
    buttonWidth = 0.1;
    buttonHeight = 0.1*aspect;
    buttonHighlighted = false;
    buttonClicked = false;
}
Button::~Button(){
}

void Button::load(const std::string& filename){
    buttonImg = stbi_load(filename.c_str(), &buttonImgWidth, &buttonImgHeight, &buttonImgChannels, 4);
    if (!buttonImg) {
        std::cerr << "Failed to load button image: " << filename << std::endl;
    }
}

}