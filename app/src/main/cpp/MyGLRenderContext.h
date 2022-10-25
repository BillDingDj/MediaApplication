//
// Created by admin on 2022/10/21.
//

#ifndef MEDIAAPPLICATION_MYGLRENDERCONTEXT_H
#define MEDIAAPPLICATION_MYGLRENDERCONTEXT_H

#include <stdint.h>
#include "GLES3/gl3.h"
#include "samples/TriangleSample.h"
#include "utils/LogUtils.h"
#include "samples/TextureMapSample.h"

class MyGLRenderContext {

private:
    static MyGLRenderContext *p_context;

    MyGLRenderContext() {
        sample = new TextureMapSample();
    }

    ~MyGLRenderContext() {

    }

    TextureMapSample *sample = nullptr;

public:

    void SetImageData(int format, int width, int height, uint8_t *pDatda);

    void OnSurfaceCreated();

    void OnSurfaceChanged(int width, int height);

    void OnDrawFrame();

    static MyGLRenderContext *GetInstance();

    static void DestroyInstance();
};


#endif //MEDIAAPPLICATION_MYGLRENDERCONTEXT_H
