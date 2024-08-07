#ifndef Shape_hpp
#define Shape_hpp

#include "Core.hpp"
#include "Camera.hpp"

class Shape {
public:
    virtual ~Shape() = default;
    virtual void Draw(Camera* camera) = 0;
};

#endif /* Shape_hpp */
