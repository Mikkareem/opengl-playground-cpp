#include "Triangle.hpp"
#include "Renderer.hpp"

Triangle::Triangle(PVector* position, Color* color): m_Position(position), m_Color(color) {
    coordinates = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    indices = {
        0,1,2
    };
    InitLayout();
}

void Triangle::Draw(Camera* camera) {
    glm::vec3 _Position = glm::vec3(m_Position->x, m_Position->y, m_Position->z);
    m_ModelMatrix = glm::translate(glm::mat4(1.0f), _Position);

    shader->Bind();
    shader->SetUniformMat4f("u_Camera", camera->getCameraMatrix());
    shader->SetUniformMat4f("u_Model", m_ModelMatrix);
    shader->SetUniform4f("u_Color", m_Color->r, m_Color->g, m_Color->b, m_Color->a);
    Renderer::RenderCommand::DrawTriangles(va, ib, shader);
}

void Triangle::InitLayout() {
    shader = ShadersHolder::GetBasicShader();
    va = new VertexArray();
    vb = new VertexBuffer(getCoordinates(), getCoordinatesSize() * sizeof(float));
    ib = new IndexBuffer(getIndices(), getIndicesSize());
    
    layout = new VertexBufferLayout();
    layout->Push<float>(3);
    va->AddBuffer(*vb, *layout);
}

void Triangle::UpdatePosition(PVector* newPosition) {
    m_Position = newPosition;
}

void Triangle::UpdateColor(Color* color) {
    m_Color = color;
}
