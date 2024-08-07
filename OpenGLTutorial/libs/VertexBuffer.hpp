
#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

class VertexBuffer {
private:
    unsigned int m_RendererID;
public:
    VertexBuffer(const void* data, const unsigned int size);
    ~VertexBuffer();
    
    void Bind() const;
    void Unbind() const;
};

#endif /* VertexBuffer_hpp */
