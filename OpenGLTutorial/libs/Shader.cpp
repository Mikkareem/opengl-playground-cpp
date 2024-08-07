//
//  Shader.cpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#include "Shader.hpp"
#include "Renderer.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& filepath): m_RendererID(0) {
    ShaderProgramSource source = ParseShader(filepath);
    m_RendererID = CreateShader(source.vertexSource, source.fragmentSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(m_RendererID));
}

void Shader::Bind() const {
    GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const {
    GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) {
    unsigned int location = GetUniformLocation(name);
    GLCall(glUniform4f(location, v1, v2, v3, v4));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) {
    unsigned int location = GetUniformLocation(name);
    GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix)));
}

unsigned int Shader::GetUniformLocation(const std::string& name) {
    if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
        return m_UniformLocationCache[name];
    }
    
    GLCall(unsigned int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if(location == -1) {
        std::cout << "Warning: uniform " << name << " doesn't exists!!!" << std::endl;
    }
    
    m_UniformLocationCache[name] = location;
    return location;
}

ShaderProgramSource Shader::ParseShader(const std::string& filePath) {
//    std::cout << std::filesystem::current_path() << std::endl;
    std::ifstream stream(filePath);
    
    if(!stream.is_open()) {
        std::cout << "Cannot open file: " << filePath << std::endl;
    }
    
    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    
    while(getline(stream, line)) {
        if(line.find("#shader") != std::string::npos) {
            if(line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if(line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else {
            ss[(int)type] << line << '\n';
        }
    }
    
    return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::LoadShader(const GLenum type, const std::string& shaderCode) {
    unsigned int shader = glCreateShader(type);
    const char * source = shaderCode.c_str();
    GLCall(glShaderSource(shader, 1, &source, nullptr));
    GLCall(glCompileShader(shader));
    
    // Error Handling
    int result;
    GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));
    if(result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));
        char* message = (char *)alloca(length * sizeof(char));
        GLCall(glGetShaderInfoLog(shader, length, &length, message));
        std::cout << "Failed to Compile Shader" << std::endl;
        std::cout << message << std::endl;
    }
    
    return shader;
}

unsigned int Shader::CreateShader(const std::string& vertex, const std::string& fragment) {
    GLCall(unsigned int program = glCreateProgram());
    unsigned int vs = LoadShader(GL_VERTEX_SHADER, vertex);
    unsigned int fs = LoadShader(GL_FRAGMENT_SHADER, fragment);
    
    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));
    
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));
    
    return program;
}
