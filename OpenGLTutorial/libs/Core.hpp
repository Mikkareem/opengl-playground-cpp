//
//  Core.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 06/08/24.
//

#ifndef Core_h
#define Core_h

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


#endif /* Core_h */
