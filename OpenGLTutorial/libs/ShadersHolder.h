//
//  ShadersHolder.h
//  OpenGLTutorial
//
//  Created by Irsath Kareem on 07/08/24.
//

#ifndef ShadersHolder_h
#define ShadersHolder_h

#include "Shader.hpp"

class ShadersHolder {
private:
    static Shader* basicShader;
public:
    static Shader* GetBasicShader() {
        if(basicShader == nullptr) {
            basicShader = new Shader("res/shaders/Basic.shader");
        }
        return basicShader;
    }
};

#endif /* ShadersHolder_h */
