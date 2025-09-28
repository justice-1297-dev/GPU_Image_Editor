#include "Texture.h"

// Include glad and glfw for graphics and windowing
#include <glad/glad.h>

namespace csci3081{

Texture::Texture(const Image& image){
    glGenTextures(1, &texture);  
    glBindTexture(GL_TEXTURE_2D, texture);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());
    glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture(){
    glDeleteTextures(1, &texture);
}

// void Texture::use(unsigned int shaderProgram){
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     int texLoc = glGetUniformLocation(shaderProgram, "tex");
//     glUniform1i(texLoc, 0);
// }

void Texture::use(unsigned int shaderProgram, int unit){
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, texture);
    int texLoc = glGetUniformLocation(shaderProgram, "tex");
    glUniform1i(texLoc, unit);
}

void Texture::copyToGPU(const Image& image){
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());
}

}