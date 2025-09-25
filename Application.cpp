#include "Application.h"
#include "Texture.h"
#include "Image.h"
#include "TextureRectangle.h"
#include "ShaderProgram.h"

#include <iostream>

// Include glad and glfw for graphics and windowing
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Include stb_image for image loading
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace csci3081{
// Holds all the application specific variables
struct App {
    int windowWidth;
    int windowHeight;
    float buttonWidth;
    float buttonHeight;
    float buttonX;
    float buttonY;
    bool buttonHighlighted;
    bool buttonClicked;
    bool drawing = false;
    int imgWidth;
    int imgHeight;
    unsigned char* img;
} app;

// Prototypes for user interaction
unsigned char* load_image(const std::string& fileName, int& width, int& height, int& channels);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

Application::Application(){}

int Application::run() {
    // -------------------------------------
    //  Load background image
    // -------------------------------------
    int width, height, channels;
    // unsigned char *img = load_image("img_small.jpeg", width, height, channels);
    // app.imgWidth = width;
    // app.imgHeight = height;
    // app.img = img;

    // -------------------------------------
    //  Load button image
    // -------------------------------------
    int buttonImgWidth, buttonImgHeight, buttonImgChannels;
    unsigned char *buttonImg = load_image("reset.png", buttonImgWidth, buttonImgHeight, buttonImgChannels);

    // -------------------------------------
    // Create window of height and width.  Initialize input callbacks
    // -------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(width, height, "Image Editor", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // -------------------------------------
    // Set the application and the window height and width
    // -------------------------------------
    glfwSetWindowUserPointer(window, &app);
    app.windowWidth = width;
    app.windowHeight = height;

    // -------------------------------------
    // Create Shader Program (Renders Image)
    // -------------------------------------
    ShaderProgram shader;
    // const char *vertexShaderSource = "#version 330 core\n"
    // "layout (location = 0) in vec3 aPos;\n"
    // "layout (location = 1) in vec2 coord;\n"
    // "uniform vec3 offset;\n"
    // "uniform vec3 scale;\n"
    // "out vec2 interpCoord;\n"
    // "void main()\n"
    // "{\n"
    // "   interpCoord = coord;\n"
    // //"   float scale = 0.5;\n"
    // "   gl_Position = vec4(aPos.xyz*scale + offset, 1.0);\n"
    // "}\0";
    // const char *fragmentShaderSource = "#version 330 core\n"
    // "out vec4 FragColor;\n"
    // "uniform sampler2D tex;\n"
    // "uniform bool highlight;\n"
    // "in vec2 interpCoord;\n"
    // "void main()\n"
    // "{\n"
    // "   vec4 color = texture(tex, interpCoord); \n"
    // "   if (color.a < 0.9) {discard;} \n"
    // "   if (highlight) { \n"
    // "       FragColor = clamp(color*vec4(2.0,2.0,2.0,1.0), 0, 1.0); \n"
    // "   } \n"
    // "   else { \n"
    // "       FragColor = texture(tex, interpCoord);\n"
    // "   } \n"
    // "}\n\0";
    // // vertex shader
    // unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // glCompileShader(vertexShader);
    // // check for shader compile errors
    // int success;
    // char infoLog[512];
    // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    // }
    // // fragment shader
    // unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // glCompileShader(fragmentShader);
    // // check for shader compile errors
    // glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    // }
    // // link shaders
    // unsigned int shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // glLinkProgram(shaderProgram);
    // // check for linking errors
    // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // if (!success) {
    //     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    // }
    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);

    // -------------------------------------
    // Create Textured Rectangle (For drawing images to the screen)
    // -------------------------------------

    TextureRectangle texRec;
    // float vertices[] = {
    //      1.0f,  1.0f, 0.0f,  // top right
    //      1.0f, -1.0f, 0.0f,  // bottom right
    //     -1.0f, -1.0f, 0.0f,  // bottom left
    //     -1.0f,  1.0f, 0.0f   // top left 
    // };
    // float coords[] = {
    //      1.0f,  0.0f,  // top right
    //      1.0f, 1.0f,  // bottom right
    //     0.0f, 1.0f,  // bottom left
    //     0.0f,  0.0f   // top left 
    // };
    // unsigned int indices[] = {  // note that we start from 0!
    //     0, 1, 3,  // first Triangle
    //     1, 2, 3   // second Triangle
    // };
    // unsigned int VBO, VAO, EBO;
    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);
    // // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    // glBindVertexArray(VAO);
    // // Add the data to the VBO
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coords), (void*)0, GL_STATIC_DRAW);
    // glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
    // glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(coords), &coords);
    // // Add the elements to the EBO
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // // Setup vertex attributes to be used in shader
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(sizeof(vertices)));
    // glEnableVertexAttribArray(1);
    // glBindBuffer(GL_ARRAY_BUFFER, 0); 
    // glBindVertexArray(0); 

    // -------------------------------------
    // Create Background Texture with width and height and img data (Texture Constructor)
    // -------------------------------------
    
    Texture backgroundTexture(app.imgWidth, app.imgHeight, app.img);
    
    // -------------------------------------
    // Create button
    // -------------------------------------
    float aspect = 1.0f*width/height;
    app.buttonX = 0.01;
    app.buttonY = 0.01;
    app.buttonWidth = 0.1;
    app.buttonHeight = 0.1*aspect;
    app.buttonHighlighted = false;
    app.buttonClicked = false;

    // -------------------------------------
    // Create Button Texture with buttonImageWidth, buttonImgHeight and buttonImg data
    // -------------------------------------
    Texture buttonTexture(buttonImgWidth, buttonImgHeight, buttonImg);
    

    // -------------------------------------
    // Set the window drawing area
    // -------------------------------------
    glViewport(0, 0, width, height);

    // -------------------------------------
    // Loop until the window should close
    // -------------------------------------
    while(!glfwWindowShouldClose(window))
    {
        // -------------------------------------
        // Process window input (e.g. mouse movement, clicks, resize, etc...)
        // -------------------------------------
        // If the escape key is pressed, close the window
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // -------------------------------------
        // Copy background image data to the texture
        // -------------------------------------
        backgroundTexture.copyToGPU(width, height, img);

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
            backgroundTexture.use(shader.getShaderProgram());

            // -------------------------------------
            // Draw the Texture Rectangle defined above
            // -------------------------------------
            // 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, false
            TextureRectangle texRec.draw();
            // int scaleLoc = glGetUniformLocation(shaderProgram, "scale");
            // int offsetLoc = glGetUniformLocation(shaderProgram, "offset");
            // int highlightLoc = glGetUniformLocation(shaderProgram, "highlight");
            // glUniform3f(scaleLoc, 1.0f, 1.0f, 1.0f);
            // glUniform3f(offsetLoc, 0.0f, 0.0f, 0.0f);
            // glUniform1i(highlightLoc, false);
            // glBindVertexArray(VAO);
            // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            // -------------------------------------
            // Use the button texture defined above
            // -------------------------------------
            buttonTexture.use(shaderProgram);

            // -------------------------------------
            // Draw button using the Texture Rectangle defined above
            // -------------------------------------
            TextureRectangle texRec.draw(app.buttonWidth, app.buttonHeight, 1.0f, app.buttonX*2.0-1.0 + app.buttonWidth, 1.0 - app.buttonHeight - app.buttonY*2.0, 0.0f, app.buttonHighlighted && !app.buttonClicked);
            // int buttonScaleLoc = glGetUniformLocation(shaderProgram, "scale");
            // int buttonOffsetLoc = glGetUniformLocation(shaderProgram, "offset");
            // int buttonHighlightLoc = glGetUniformLocation(shaderProgram, "highlight");
            // glUniform3f(buttonScaleLoc, app.buttonWidth, app.buttonHeight, 1.0f);
            // glUniform3f(buttonOffsetLoc, app.buttonX*2.0-1.0 + app.buttonWidth, 1.0 - app.buttonHeight - app.buttonY*2.0, 0.0f);
            // glUniform1i(buttonHighlightLoc, app.buttonHighlighted && !app.buttonClicked);
            // glBindVertexArray(VAO);
            // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        }

        // -------------------------------------
        // Show window on the screen
        // -------------------------------------
        glfwSwapBuffers(window);

        // -------------------------------------
        // Check for user input (mouse movement, clicks, keyboard, etc...)
        // -------------------------------------
        glfwPollEvents();
    }

    // -------------------------------------
    // Destroy Textured Rectangle
    // -------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // -------------------------------------
    // Destroy Shader Program
    // -------------------------------------
    glDeleteProgram(shaderProgram);

    // -------------------------------------
    // Destroy Images
    // -------------------------------------
    stbi_image_free(img);
    stbi_image_free(buttonImg);
    
    // -------------------------------------
    // Terminate windowing application
    // -------------------------------------
    glfwTerminate();

    return 0;
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
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

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    // -------------------------------------
    // handle button presses and drawing
    // -------------------------------------
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        App& app = *static_cast<App*>(glfwGetWindowUserPointer(window));
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

// unsigned char* load_image(const std::string& fileName, int& width, int& height, int& channels) {
    
//     unsigned char *img = stbi_load(fileName.c_str(), &width, &height, &channels, 4);
//     channels = 4;
//     if(img == NULL) {
//         printf("Error in loading the image\n");
//         exit(1);
//     }
//     printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

//     return img;
// }

}