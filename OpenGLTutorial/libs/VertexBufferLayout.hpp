//
//  VertexBufferLayout.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#ifndef VertexBufferLayout_hpp
#define VertexBufferLayout_hpp

#include <vector>
#include "Renderer.hpp"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    bool normalized;
    
    static unsigned int GetSizeOfType(unsigned int type) {
        switch(type) {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
            case GL_UNSIGNED_SHORT: return 2;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
public:
    VertexBufferLayout(): m_Stride(0) {}
    ~VertexBufferLayout() {
        printf("Vertex Buffer Layout deleted");
    }
    
    template<typename T>
    void Push(unsigned int count) {
//        static_assert(false, "Count is 0");
    }
    
    template<>
    void Push<float>(unsigned int count) {
        m_Elements.push_back({ GL_FLOAT, count, false });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }
    
    template<>
    void Push<unsigned int>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_INT, count, false });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }
    
    template<>
    void Push<unsigned char>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_BYTE, count, true });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }
    
    template<>
    void Push<unsigned short>(unsigned int count) {
        m_Elements.push_back({ GL_UNSIGNED_SHORT, count, false });
        m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_SHORT);
    }
    
    inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const { return m_Stride; }
};

#endif /* VertexBufferLayout_hpp */

