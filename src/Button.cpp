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

Button::Button(float x, float y, float w, float h, const Image& image) : Glyph(x, y, w, h, image, new ShaderProgram("src/shaders/quad.vsh", "src/shaders/button.fsh")) {
}

void Button::draw() {
    const ShaderProgram& shaderProgram = getShaderProgram();
    shaderProgram.use();
    int buttonHighlightLoc = glGetUniformLocation(shaderProgram.getId(), "highlight");
    glUniform1i(buttonHighlightLoc, buttonHighlighted && !buttonClicked);

    Glyph::draw();
}

}