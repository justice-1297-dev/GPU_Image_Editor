#ifndef GLYPH_H
#define GLYPH_H

#include "Texture.h"
#include "ShaderProgram.h"
#include "Quad.h"

namespace csci3081 {

class Glyph {
public:
    Glyph(float x, float y, float w, float h, const Image& image);
    Glyph(float x, float y, float w, float h, const Image& image, ShaderProgram* shaderProgram);
    virtual ~Glyph();

    void update(const Image& image);
    virtual void draw();

    Glyph(const Glyph& glyph) = delete;
    Glyph& operator=(const Glyph& glyph) = delete;

protected:
    const ShaderProgram& getShaderProgram() const { return *shaderProgram; }

protected:
    float x, y, w, h;
private:
    Texture* texture;
    ShaderProgram* shaderProgram;
    Quad quad;
};

}

#endif