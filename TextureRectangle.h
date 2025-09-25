#ifndef TEXTURERECTANBLE_G
#define TEXTURERECTANBLE_G

namespace csci3081{

class TextureRectangle {
public:
    TextureRectangle(float vertices[], float coords[], unsigned int indices[]);
    ~TextureRectangle();
    void draw(unsigned int shaderProgram);
private:
    unsigned int VBO, VAO, EBO;
};

}


#endif 