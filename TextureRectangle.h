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
    float vertices[12] = {
         1.0f,  1.0f, 0.0f,  // top right
         1.0f, -1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 0.0f,  // bottom left
        -1.0f,  1.0f, 0.0f   // top left 
    };
    float coords[8] = {
         1.0f,  0.0f,  // top right
         1.0f, 1.0f,  // bottom right
        0.0f, 1.0f,  // bottom left
        0.0f,  0.0f   // top left 
    };
    unsigned int indices[6] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
};

}


#endif 