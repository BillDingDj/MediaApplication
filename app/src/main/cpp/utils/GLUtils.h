//
// Created by admin on 2022/10/21.
//

#ifndef MEDIAAPPLICATION_GLUTILS_H
#define MEDIAAPPLICATION_GLUTILS_H

#include "GLES3/gl3.h"
#include <cstdlib>
class GLUtils {

public:
    static GLuint LoaderShader(GLenum shaderType, const char *pSource);
    static GLuint CreateProgram(const char *pVertexShaderSource, const char *pFragShaderSource, GLuint &vertexShaderHandle, GLuint &fragShaderHandle);

};

#endif //MEDIAAPPLICATION_GLUTILS_H
