//
//  Shader.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <unordered_map>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader {
private:
    unsigned int m_RendererID;
    std::unordered_map<std::string, unsigned int> m_UniformLocationCache;
public:
    Shader(const std::string& filepath);
    ~Shader();
    
    void Bind() const;
    void Unbind() const;
    
    // Set Uniforms
    void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
    ShaderProgramSource ParseShader(const std::string& filePath);
    unsigned int GetUniformLocation(const std::string& name);
    unsigned int CreateShader(const std::string& vertex, const std::string& fragment);
    unsigned int LoadShader(const GLenum type, const std::string& shaderCode);
};

#endif /* Shader_hpp */
