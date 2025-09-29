#include "Window.h"
#include "Application.h"
#include <iostream>

#include <stb_image.h>
namespace csci3081{

Window::Window(int width, int height){
    this->width = width;
    this->height = height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window = glfwCreateWindow(width, height, "Image Editor", NULL, NULL);
}

Window::~Window(){}

void Window::set(){
    glViewport(0, 0, width, height);
}

GLFWwindow* Window::getWindow() const{
    return window;
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

}