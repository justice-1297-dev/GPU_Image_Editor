#ifndef WINDOW_H
#define WINDOW_H


namespace csci3081{

class Window {
public:
    Window(int windowWidth, int windowHeight);
    ~Window();
    void set();
    GLFWwindow* getWindow();

private:
    int width;
    int height;
    GLFWwindow* window;
};

}


#endif 