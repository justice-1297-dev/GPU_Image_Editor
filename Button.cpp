#include "Button.h"
#include "ShaderProgram.h"

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// #define STBI_MSC_SECURE_CRT
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "stb_image_write.h"
#include <stb_image.h>
#include <glad/glad.h>
#include <iostream>
namespace csci3081 {

Button::Button(float x, float y, float w, float h, const Image& image){
    float aspect = 1.0f*buttonImgWidth/buttonImgHeight;
    buttonX = 0.01;
    buttonY = 0.01;
    buttonWidth = 0.1;
    buttonHeight = 0.1*aspect;
    buttonHighlighted = false;
    buttonClicked = false;
}

// Button::Button(int buttonImgWidth, int buttonImgHeight){
//     float aspect = 1.0f*buttonImgWidth/buttonImgHeight;
//     buttonX = 0.01;
//     buttonY = 0.01;
//     buttonWidth = 0.1;
//     buttonHeight = 0.1*aspect;
//     buttonHighlighted = false;
//     buttonClicked = false;
// }

// void Button::update(const Image& image){
//     buttonImg = stbi_load(image.saveAs(), &buttonImgWidth, &buttonImgHeight, &buttonImgChannels, 4);
//     if (!buttonImg) {
//         std::cerr << "Failed to load button image: " << image << std::endl;
//     }
// }

// void Button::draw() {
//     const ShaderProgram& shaderProgram = getShaderProgram();
//     shaderProgram.use();
//     int buttonHighlightLoc = glGetUniformLocation(shaderProgram.getId(), "highlight");
//     glUniform1i(buttonHighlightLoc, highlighted && !clicked);
//     Glyph::draw();
// }

}