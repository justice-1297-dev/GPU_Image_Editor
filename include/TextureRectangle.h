#ifndef TEXTURERECTANBLE_G
#define TEXTURERECTANBLE_G

namespace csci3081{

class TextureRectangle {
public:
    TextureRectangle();
    TextureRectangle(int width, int height, unsigned char* img);
    ~TextureRectangle();

    void draw(unsigned int shaderProgram);
private:
    unsigned int VBO, VAO, EBO;
};

}


#endif 