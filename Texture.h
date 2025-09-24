#ifndef TEXTURE_H
#define TEXTURE_H

namespace csci3081{

class Texture {
public:
    Texture(int width, int height, unsigned char* img);
    void use();

private:
    unsigned int texture;
};

}


#endif 