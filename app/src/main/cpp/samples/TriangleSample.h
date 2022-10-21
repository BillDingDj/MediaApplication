//
// Created by admin on 2022/10/21.
//

#ifndef MEDIAAPPLICATION_TRIANGLESAMPLE_H
#define MEDIAAPPLICATION_TRIANGLESAMPLE_H

#include "GLES3/gl3.h"
#include "../utils/GLUtils.h"

class TriangleSample {

private:
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_ProgramObj;

public:
    TriangleSample() {

    }

    ~TriangleSample() {

    }

    void Init();
    void Draw();
    void Destroy();

};


#endif //MEDIAAPPLICATION_TRIANGLESAMPLE_H
