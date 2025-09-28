#include "Application.h"
#include "Texture.h"
#include "Image.h"
#include "TextureRectangle.h"
#include "ShaderProgram.h"
#include "Window.h"
#include "Button.h"

#include <iostream>

// Include glad and glfw for graphics and windowing
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Include stb_image for image loading
// #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace csci3081{

// Prototypes for user interaction
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

Application::Application(){
    windowWidth = 800;
    windowHeight = 600;
    buttonX = 0.01f;
    buttonY = 0.01f;
    buttonWidth = 0.1f;
    buttonHeight = 0.1f;
    buttonHighlighted = false;
    buttonClicked = false;
}

Application::~Application(){
    glfwTerminate();
}

int Application::run() {
    Image image("img_small.jpeg");
    img = const_cast<unsigned char*>(image.getData());
    imgWidth = image.getWidth();
    imgHeight = image.getHeight();
    
    Image buttonImage("reset.png");

    Window appWindow(windowWidth, windowHeight);
    if (appWindow.getWindow() == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(appWindow.getWindow());
    glfwSetFramebufferSizeCallback(appWindow.getWindow(), framebuffer_size_callback);
    glfwSetCursorPosCallback(appWindow.getWindow(), cursor_position_callback);
    glfwSetMouseButtonCallback(appWindow.getWindow(), mouse_button_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetWindowUserPointer(appWindow.getWindow(), this);

    ShaderProgram shader("src/shaders/quad.vsh", "src/shaders/button.fsh");

    TextureRectangle backgroundRec;
    TextureRectangle buttonRec;

    Texture backgroundTexture(image);

    Button button(0.1f, 0.1f, 0.01f, 0.01f, buttonImage);
    // Texture buttonTexture(buttonImage);
    
    appWindow.set();

    while(!glfwWindowShouldClose(appWindow.getWindow()))
    {
        // -------------------------------------
        // Process window input (e.g. mouse movement, clicks, resize, etc...)
        // -------------------------------------
        // If the escape key is pressed, close the window
        if(glfwGetKey(appWindow.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(appWindow.getWindow(), true);

        // -------------------------------------
        // Copy background image data to the texture
        // -------------------------------------
        backgroundTexture.copyToGPU(image);

        // -------------------------------------
        // Render Graphics
        // -------------------------------------
        {
            // Clear the screen
            // keep
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // -------------------------------------
            // Use the shader program defined above
            // -------------------------------------
            shader.use();
            
            // -------------------------------------
            // Use the texture defined above
            // -------------------------------------
            backgroundTexture.use(shader.getId());

            // -------------------------------------
            // Draw the Texture Rectangle defined above
            // -------------------------------------
            backgroundRec.draw(shader.getId(), 0.0f, 0.0f, 1.0f, 1.0f);
            // button.draw(shader);

            // -------------------------------------
            // Use the button texture defined above
            // -------------------------------------
            // buttonTexture.use(shader.getId());

            // -------------------------------------
            // Draw button using the Texture Rectangle defined above
            // -------------------------------------
            // buttonRec.draw(shader.getId(), -0.8f, -0.8f, -0.6f, -0.6f);
            button.draw(shader);
        }

        // -------------------------------------
        // Show window on the screen
        // -------------------------------------
        appWindow.swapBuffers();

        // -------------------------------------
        // Check for user input (mouse movement, clicks, keyboard, etc...)
        // -------------------------------------
        appWindow.pollEvents();
    }
    return 0;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    // -------------------------------------
    // Get the applicaiton
    // -------------------------------------
    Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // -------------------------------------
    // Set the window drawing area
    // -------------------------------------
    glViewport(0, 0, width, height);

    
    // -------------------------------------
    // Get the applicaiton
    // -------------------------------------
    Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));
    app.windowWidth = width;
    app.windowHeight = height;

    // -------------------------------------
    // update the button height
    // -------------------------------------
    float aspect = 1.0f*width/height;
    app.buttonHeight = 0.1*aspect;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    // -------------------------------------
    // handle button presses and drawing
    // -------------------------------------
    Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        // Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));
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

unsigned char* load_image(const std::string& fileName, int& width, int& height, int& channels) {
    
    unsigned char *img = stbi_load(fileName.c_str(), &width, &height, &channels, 4);
    channels = 4;
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    return img;
}

}