#include <iostream>
#include "Renderer.hpp"
#include "Core.hpp"

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
//    DebugBindings();
    
    GLCall(glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_SHORT, nullptr));
}

void Renderer::RenderCommand::DrawLines(const VertexArray* va, const IndexBuffer* ib, const Shader* shader) {
    va->Bind();
    ib->Bind();
    shader->Bind();
//    DebugBindings();
    GLCall(glDrawElements(GL_LINES, ib->GetCount(), GL_UNSIGNED_SHORT, nullptr));
}
