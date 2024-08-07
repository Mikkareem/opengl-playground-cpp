
#ifndef Renderer_hpp
#define Renderer_hpp

#include <GL/glew.h>

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

#define ASSERT(x) if (!(x)) __builtin_trap();
#define GLCall(x) GLClearError();\
    x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
private:
public:
    Renderer();
    ~Renderer();
    
    class RenderCommand {
    public:
        static void Clear();
        static void DrawTriangles(const VertexArray* va, const IndexBuffer* ib, const Shader* shader);
    };
};

#endif /* Renderer_hpp */
