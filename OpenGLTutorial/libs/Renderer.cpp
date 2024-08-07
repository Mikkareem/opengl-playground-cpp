#include <iostream>
#include "Renderer.hpp"

void GLClearError() {
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error]: (" << error << "): " << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::RenderCommand::Clear() {
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::RenderCommand::DrawTriangles(const VertexArray* va, const IndexBuffer* ib, const Shader* shader) {
    va->Bind();
    ib->Bind();
    shader->Bind();
//    GLint vaId, vbId, ibId;
//    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &vbId);
//    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vaId);
//    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &ibId);
//    
//    std::cout << vaId << " " << vbId << " " << ibId << std::endl;
    
    GLCall(glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_SHORT, nullptr));
}
