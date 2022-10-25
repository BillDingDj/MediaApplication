//
// Created by admin on 2022/10/21.
//

#include "MyGLRenderContext.h"

MyGLRenderContext* MyGLRenderContext::p_context = nullptr;

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pData) {
    NativeImage nativeImage;
    nativeImage.format = format;
    nativeImage.width = width;
    nativeImage.height = height;
    nativeImage.ppPlane[0] = pData;

    switch (format)
    {
        case IMAGE_FORMAT_NV12:
        case IMAGE_FORMAT_NV21:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
            break;
        case IMAGE_FORMAT_I420:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
            nativeImage.ppPlane[2] = nativeImage.ppPlane[1] + width * height / 4;
            break;
        default:
            break;
    }

    if (sample)
    {
        sample->LoadImage(&nativeImage);
    }
}

void MyGLRenderContext::OnSurfaceCreated() {
    LOGCATD("OnSurfaceCreated");
    glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
}

void MyGLRenderContext::OnSurfaceChanged(int width, int height) {
    LOGCATD("OnSurfaceChanged");
    glViewport(0,0,width, height);
}

void MyGLRenderContext::OnDrawFrame() {
    LOGCATD("OnDrawFrame");

    if (sample) {
        sample->Init();
        sample->Draw(0,0);
    }
}

MyGLRenderContext *MyGLRenderContext::GetInstance() {
    LOGCATD("GetInstance");
    if (p_context == nullptr) {
        p_context = new MyGLRenderContext();
    }

    return p_context;
}

void MyGLRenderContext::DestroyInstance() {
    LOGCATD("DestroyInstance");
    if (p_context) {
        delete p_context;
        p_context = nullptr;
    }
}
