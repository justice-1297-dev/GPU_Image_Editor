#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

namespace csci3081{

class ShaderProgram {
public:
    ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath));
    ~ShaderProgram();
    void use();
    unsigned int getShaderProgram(){ return shaderProgram;}

private:
    unsigned int shaderProgram;
};

}


#endif 