#ifndef TEXTURE_H
#define TEXTURE_H

namespace csci3081{

class Texture {
public:
    Texture(int width, int height, unsigned char* img);
    void use(unsigned int shaderProgram);
    void copy(int width, int height, unsigned char* img);

private:
    unsigned int texture;
};

}


#endif 