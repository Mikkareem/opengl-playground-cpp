//
//  Camera.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 06/08/24.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Core.hpp"

class Camera {
private:
    PVector* location;
    PVector* seenAtCenter;
    PVector* up;
    
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
public:
    Camera();
    ~Camera();
    
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void ZoomIn();
    void ZoomOut();
    
    glm::mat4 getCameraMatrix() const;
private:
    void ChangeViewMatrix();
};

#endif /* Camera_hpp */
