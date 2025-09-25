#include "Window.h"
#include <iostream>

namespace csci3081{

Window::Window(int width, int height){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window = glfwCreateWindow(width, height, "Image Editor", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        // return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        // return -1;
    }
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

void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
// -------------------------------------
// Get the applicaiton
// -------------------------------------
App& app = *static_cast<App*>(glfwGetWindowUserPointer(window));

// -------------------------------------
// If the mouse is over the button, highlight it
// -------------------------------------
float x = xpos/app.windowWidth;
float y = ypos/app.windowHeight;
if (x >= app.buttonX && x <= app.buttonX + app.buttonWidth && y >= app.buttonY && y <= app.buttonY + app.buttonHeight ) {
    app.buttonHighlighted = true;
}
else {
    app.buttonHighlighted = false;
}

// -------------------------------------
// If we are drawing, edit the background image
// -------------------------------------
if (app.drawing) {
    std::cout << x << " " << y << std::endl;
    int imgX = x * app.imgWidth;
    int imgY = y * app.imgHeight;
    int radius = 2;
    for (int i = imgX-radius; i < imgX+radius+1; i++) {
        for (int j = imgY-radius; j < imgY + radius+1; j++) {
            app.img[(j*app.imgWidth + i)*4 + 0] = 0;
            app.img[(j*app.imgWidth + i)*4 + 1] = 0;
            app.img[(j*app.imgWidth + i)*4 + 2] = 255;
            app.img[(j*app.imgWidth + i)*4 + 3] = 255;
        }
    }
}


}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
// -------------------------------------
// Set the window drawing area
// -------------------------------------
glViewport(0, 0, width, height);


// -------------------------------------
// Get the applicaiton
// -------------------------------------
App& app = *static_cast<App*>(glfwGetWindowUserPointer(window));
app.windowWidth = width;
app.windowHeight = height;

// -------------------------------------
// update the button height
// -------------------------------------
float aspect = 1.0f*width/height;
app.buttonHeight = 0.1*aspect;
}

void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
// -------------------------------------
// handle button presses and drawing
// -------------------------------------
if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    // App& app = *static_cast<App*>(glfwGetWindowUserPointer(window));
    if (app.buttonHighlighted) {
        std::cout << "Clicked" << std::endl;
        app.buttonClicked = true;
    }
    else {
        app.drawing = true;
    }
}
if (action == GLFW_RELEASE) {
    app.buttonClicked = false;
    app.drawing = false;
}

}
}