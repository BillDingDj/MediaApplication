//
// Created by admin on 2022/10/21.
//

#include "MyGLRenderContext.h"

MyGLRenderContext* MyGLRenderContext::p_context = nullptr;

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pDatda) {

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
        sample->Draw();
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
