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
    GLFWwindow* getWindow() const;
    void swapBuffers();
    void pollEvents();
    bool shouldClose() const;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

private:
    int width;
    int height;
    GLFWwindow* window;
};

}


#endif 