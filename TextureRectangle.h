#ifndef TEXTURERECTANBLE_G
#define TEXTURERECTANBLE_G

namespace csci3081{

class TextureRectangle {
public:
    TextureRectangle();
    ~TextureRectangle();
    void draw();
private:
    unsigned int VBO, VAO, EBO;
};

}


#endif 