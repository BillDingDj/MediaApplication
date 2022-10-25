//
// Created by admin on 2022/10/21.
//

#ifndef MEDIAAPPLICATION_TEXTUREMAPSAMPLE_H
#define MEDIAAPPLICATION_TEXTUREMAPSAMPLE_H

#include "GLES3/gl3.h"
#include "../utils/GLUtils.h"
#include "../utils/ImageUtils.h"

class TextureMapSample {
private:
    GLuint m_VertexShader;
    GLuint m_FragmentShader;
    GLuint m_ProgramObj;
    GLuint m_TextureId;
    GLuint m_SamplerLoc;
    NativeImage m_RenderImage;

public:
    TextureMapSample() {

    }

    ~TextureMapSample() {

    }

    void Init();
    void Draw(int width, int height);
    void Destroy();
    void LoadImage(NativeImage *pImage);
};


#endif //MEDIAAPPLICATION_TEXTUREMAPSAMPLE_H
