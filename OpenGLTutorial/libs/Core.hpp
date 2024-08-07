//
//  Core.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 06/08/24.
//

#ifndef Core_h
#define Core_h

#include <iostream>
//#include <GL/glew.h>

struct PVector {
    float x;
    float y;
    float z;
public:
    inline void setX(float x) {
        this->x = x;
    }
    
    inline void setY(float y) {
        this->y = y;
    }
    
    inline void setZ(float z) {
        this->z = z;
    }
    
    inline void moveX(float x) {
        this->x += x;
    }
    
    inline void moveY(float y) {
        this->y += y;
    }
    
    inline void moveZ(float z) {
        this->z += z;
    }
};

struct Color {
    float r;
    float g;
    float b;
    float a = 0.1f;
};

//void DebugBindings() {
//    GLint vaId, vbId, ibId;
//    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &vbId);
//    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vaId);
//    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &ibId);
//
//    std::cout << vaId << " " << vbId << " " << ibId << std::endl;
//}


#endif /* Core_h */
