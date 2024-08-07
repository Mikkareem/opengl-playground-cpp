//
//  GLWindow.hpp
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 06/08/24.
//

#ifndef GLWindow_hpp
#define GLWindow_hpp

#include <GLFW/glfw3.h>

class GLWindow {
private:
    GLFWwindow* window;
public:
    GLWindow();
    ~GLWindow();

private:
    GLFWwindow* initWindow();
    
};

#endif /* GLWindow_hpp */
