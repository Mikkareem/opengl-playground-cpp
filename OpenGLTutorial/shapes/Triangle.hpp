#ifndef Triangle_hpp
#define Triangle_hpp

#include <array>

#include "../libs/Shape.hpp"
#include "../libs/Shader.hpp"
#include "../libs/ShadersHolder.h"
#include "../libs/VertexBufferLayout.hpp"
#include "../libs/IndexBuffer.hpp"
#include "../libs/VertexArray.hpp"

class Triangle: public Shape {
private:
    std::array<float, 9> coordinates;
    std::array<unsigned short, 3> indices;
    Color* m_Color;
    Shader* shader;
    VertexArray* va;
    VertexBuffer* vb;
    VertexBufferLayout* layout;
    IndexBuffer* ib;
    
    PVector* m_Position;
    glm::mat4 m_ModelMatrix;
public:
    Triangle(PVector* position, Color* color);
    void Draw(Camera* camera) override;
    void UpdatePosition(PVector* newPosition);
    void UpdateColor(Color* newColor);
    
    inline PVector* getPosition() const {
        return m_Position;
    }
    
private:
    inline float* getCoordinates() const {
        return (float*)coordinates.data();
    }
    
    inline unsigned short* getIndices() const {
        return (unsigned short*)indices.data();
    }
    
    inline unsigned int getCoordinatesSize() const {
        return (unsigned int)coordinates.size();
    }
    
    inline unsigned int getIndicesSize() const {
        return (unsigned int)indices.size();
    }

    void InitLayout();
};

#endif /* Triangle_hpp */
