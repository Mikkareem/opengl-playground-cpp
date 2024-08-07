//
//  IndexBuffer.cpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#include "IndexBuffer.hpp"
#include "Renderer.hpp"

#include <GL/glew.h>

IndexBuffer::IndexBuffer(const unsigned short* data, const unsigned int count)
    : m_Count(count)
{
    GLCall(glGenBuffers(1, &m_RendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
