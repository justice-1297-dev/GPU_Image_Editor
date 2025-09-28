#include "Glyph.h"

// Include glad graphics
#include <glad/glad.h>


namespace csci3081 {

Glyph::Glyph(float x, float y, float w, float h, const Image& image) : x(x), y(y), w(w), h(h) {
    texture = new Texture(image);
    shaderProgram = new ShaderProgram("src/shaders/quad.vsh", "src/shaders/quad.fsh");
}

Glyph::Glyph(float x, float y, float w, float h, const Image& image, ShaderProgram* shaderProgram) : x(x), y(y), w(w), h(h), shaderProgram(shaderProgram) {
    texture = new Texture(image);
}

Glyph::~Glyph() {
    delete texture;
    delete shaderProgram;
}


void Glyph::update(const Image& image) {
    texture->copyToGPU(image);
}

void Glyph::draw() {
    shaderProgram->use();
    texture->use(shaderProgram->getId());
    int buttonScaleLoc = glGetUniformLocation(shaderProgram->getId(), "scale");
    int buttonOffsetLoc = glGetUniformLocation(shaderProgram->getId(), "offset");
    int buttonHighlightLoc = glGetUniformLocation(shaderProgram->getId(), "highlight");
    glUniform3f(buttonScaleLoc, w, h, 1.0f);
    glUniform3f(buttonOffsetLoc, x*2.0-1.0 + w, 1.0 - h - y*2.0, 0.0f);
    //glUniform1i(buttonHighlightLoc, app.buttonHighlighted && !app.buttonClicked);
    quad.draw();
}

}