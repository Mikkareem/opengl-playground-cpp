//
//  VertexArray.cpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#include "VertexBufferLayout.hpp"
#include "VertexArray.hpp"
#include "Renderer.hpp"

VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray() {
    printf("Vertex Array deleted");
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(0, 
                                     element.count,
                                     element.type,
                                     element.normalized ? GL_TRUE : GL_FALSE,
                                     layout.GetStride(), 
                                     (const void*)offset)
               );
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const {
    GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}
