#include "Texture.h"

// Include glad and glfw for graphics and windowing
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace csci3081{

class Texture {
public:
    Texture::Texture(){
        glGenTextures(1, &texture);  
        glBindTexture(GL_TEXTURE_2D, texture);  
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    void Texture::use(){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        int texLoc = glGetUniformLocation(shaderProgram, "tex");
        glUniform1i(texLoc, 0);
    }

private:
};

}