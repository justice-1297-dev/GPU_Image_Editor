#ifndef TEXTURE_H
#define TEXTURE_H

#include "Image.h"

namespace csci3081{

class Texture {
public:
    Texture(const Image& image);
    ~Texture();
    void use(unsigned int shaderProgram, int unit);
    void copyToGPU(const Image& image);

private:
    unsigned int texture;
    int unit;
};

}


#endif 