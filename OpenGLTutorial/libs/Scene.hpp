//
//  Scene.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 06/08/24.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <vector>

#include "Shape.hpp"
#include "Camera.hpp"

class Scene {
private:
    std::vector<Shape*> m_Shapes;
    Camera* m_Camera;
    glm::mat4 m_Projection;

public:
    Scene(Camera* camera);
    ~Scene();
    
    void AddShape(Shape* shape);
    
    // Draw call over scene
    void update();
};

#endif /* Scene_hpp */
