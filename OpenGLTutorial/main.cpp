#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "libs/Renderer.hpp"
#include "libs/VertexBufferLayout.hpp"
#include "libs/VertexBuffer.hpp"
#include "libs/IndexBuffer.hpp"
#include "libs/VertexArray.hpp"
#include "libs/Shader.hpp"

#include "shapes/Triangle.hpp"

float randomf(float min, float max) {
    float random = (float)(rand()) / (float)(rand());
    return random * (((float)rand()/(float)RAND_MAX) > 0.5f ? -1.0f : 1.0f);
}

GLFWwindow* initWindow();
void key_Callback(GLFWwindow* window, int key, int scanCode, int action, int mods);

std::array<Triangle*, 30> triangles;
Camera* camera;

float zGo = -0.00101f;

int main(int argc, const char * argv[]) {
    srand(time(0));
    GLFWwindow* window = initWindow();
    
    if(window == nullptr) return -1;
    
    camera = new Camera();
    
    Triangle* triangle1 = new Triangle(new PVector { 0.0f, 0.0f, -3.0f }, new Color { 1.0f, 0.0f, 0.0f, 1.0f } );
    Triangle* triangle2 = new Triangle(new PVector { 0.0f, 0.0f, 3.0f }, new Color { 0.0f, 0.0f, 1.0f, 1.0f } );
    
    float coordinates[] = {
        0.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    
    unsigned short indices[] = {0,1};
    
    VertexArray va;
    VertexBuffer vb(coordinates, 6 * sizeof(float));
    
    VertexBufferLayout layout;
    layout.Push<float>(3);
    va.AddBuffer(vb, layout);
    
    IndexBuffer ib(indices, 2);
    
    Shader* shader = ShadersHolder::GetBasicShader();
    
    glm::vec3 pivot(0.0f, 0.0f, 0.0f); // Example pivot point
    float angle = 1.0f;
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        Renderer::RenderCommand::Clear();
        
        shader->Bind();
        shader->SetUniformMat4f("u_Camera", camera->getCameraMatrix());
        shader->SetUniformMat4f("u_Model", glm::mat4(1.0f));
        shader->SetUniform4f("u_Color", 1.0f, 0.34f, 0.65f, 1.0f);
        
        Renderer::RenderCommand::DrawLines(&va, &ib, shader);
        
        triangle1->Draw(camera);
        triangle2->Draw(camera);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        glfwSetKeyCallback(window, key_Callback);

        /* Poll for and process events */
        glfwPollEvents();
        
    }

    glfwTerminate();
    
    return 0;
}

static int times = 0;

void key_Callback(GLFWwindow* window, int key, int scanCode, int action, int mods) {
    if(action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch(key) {
            case GLFW_KEY_SPACE:
                std::cout << "Space is pressed " << times++ << " times" << std::endl;
                break;
            case GLFW_KEY_UP:
                std::cout << "Up is pressed " << times++ << " times" << std::endl;
                camera->MoveUp();
                break;
            case GLFW_KEY_DOWN:
                std::cout << "Down is pressed " << times++ << " times" << std::endl;
                camera->MoveDown();
                break;
            case GLFW_KEY_LEFT:
                std::cout << "Left is pressed " << times++ << " times" << std::endl;
                camera->MoveLeft();
                break;
            case GLFW_KEY_RIGHT:
                std::cout << "Right is pressed " << times++ << " times" << std::endl;
                camera->MoveRight();
                break;
            case GLFW_KEY_Z:
                std::cout << "Z is pressed " << times++ << " times" << std::endl;
                camera->ZoomIn();
                break;
            case GLFW_KEY_X:
                std::cout << "X is pressed " << times++ << " times" << std::endl;
                camera->ZoomOut();
                break;
        }
    }
}

GLFWwindow* initWindow() {
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return nullptr;
    
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
//    #ifdef __APPLE__
//      std::cout << "I'm apple machine" << std::endl;
//      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    #endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
//    glViewport(-1, 1, 640, 480);
    
    if(glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
    }
    
//    GLCall(glEnable(GL_DEPTH_TEST));
//    glDepthFunc(GL_LESS);
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    
    
    return window;
}
