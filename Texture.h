#ifndef TEXTURE_H
#define TEXTURE_H

namespace csci3081{

class Texture {
public:
    Texture(const Image& img);
    ~Texture();
    void use(unsigned int shaderProgram);
    void copyToGPU(int width, int height, unsigned char* img);

private:
    unsigned int texture;
};

}


#endif 