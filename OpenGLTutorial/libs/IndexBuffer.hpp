//
//  IndexBuffer.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 05/08/24.
//

#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp

class IndexBuffer {
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned short* data, const unsigned int count);
    ~IndexBuffer();
    
    void Bind() const;
    void Unbind() const;
    
    inline unsigned int GetCount() const { return m_Count; }
};

#endif /* IndexBuffer_hpp */
