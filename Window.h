#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace csci3081{

class Window {
public:
    Window(int width, int height);
    ~Window();
    void set();
    GLFWwindow* getWindow();
    void swapBuffers();
    void pollEvents();
    bool shouldClose() const;

private:
    int width;
    int height;
    GLFWwindow* window;
};

}


#endif 