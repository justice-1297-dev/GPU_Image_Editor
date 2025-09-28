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

// Button::Button(float x, float y, float w, float h, const Image& image) : Glyph(x, y, w, h, image, new ShaderProgram("src/shaders/quad.vsh", "src/shaders/button.fsh")) {
// }
Button::Button(float x, float y, float w, float h, const Image& image, ShaderProgram* shaderProgram)
    : Glyph(x, y, w, h, image, shaderProgram) {}

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

// void Button::draw(const ShaderProgram& shader) const{
//     // const ShaderProgram& shaderProgram = getShaderProgram();
//     // shaderProgram.use();
//     // int buttonHighlightLoc = glGetUniformLocation(shaderProgram.getId(), "highlight");
//     // glUniform1i(buttonHighlightLoc, buttonHighlighted && !buttonClicked);
//     // Glyph::draw();
//     shader.use();
//     int buttonHighlightLoc = glGetUniformLocation(shader.getId(), "highlight");
//     glUniform1i(buttonHighlightLoc, buttonHighlighted && !buttonClicked);

//     float vertices[] = {
//         buttonX,      buttonY,      0.0f, 0.0f,
//         buttonX + buttonWidth,  buttonY,      1.0f, 0.0f,
//         buttonX + buttonWidth,  buttonY + buttonHeight,  1.0f, 1.0f,
//         buttonX,      buttonY + buttonHeight,  0.0f, 1.0f
//     };
 
//     GLuint VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
//     glEnableVertexAttribArray(1);

//     glBindTexture(GL_TEXTURE_2D, textureID);

//     glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

void Button::draw() {
    const ShaderProgram& shaderProgram = getShaderProgram();
    shaderProgram.use();
    int buttonHighlightLoc = glGetUniformLocation(shaderProgram.getId(), "highlight");
    glUniform1i(buttonHighlightLoc, buttonHighlighted && !buttonClicked);

    Glyph::draw();
}

}