#include "TextureRectangle.h"

// Include glad and glfw for graphics and windowing
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace csci3081{

TextureRectangle::TextureRectangle(){
    float vertices[] = {
         x,     y,      0.0f, 0.0f,
        x + w, y,      1.0f, 0.0f,
        x + w, y + h,  1.0f, 1.0f,
        x,     y + h,  0.0f, 1.0f 
    };
    float coords[] = {
         1.0f,  0.0f,
         1.0f, 1.0f,
        0.0f, 1.0f, 
        0.0f,  0.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3 
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coords), (void*)0, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(coords), &coords);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(sizeof(vertices)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}
TextureRectangle::~TextureRectangle(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void TextureRectangle::draw(unsigned int shaderProgram, float x, float y, float w, float h){
    int scaleLoc = glGetUniformLocation(shaderProgram, "scale");
    int offsetLoc = glGetUniformLocation(shaderProgram, "offset");
    int highlightLoc = glGetUniformLocation(shaderProgram, "highlight");
    // glUniform3f(scaleLoc, 1.0f, 1.0f, 1.0f);
    // glUniform3f(offsetLoc, 0.0f, 0.0f, 0.0f);
    glUniform3f(scaleLoc, w, h, 1.0f);
    glUniform3f(offsetLoc, x, y, 0.0f);
    glUniform1i(highlightLoc, false);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



}