package com.billdingdj.mediaapplication

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet
import android.util.Log
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MyGLSurfaceView : android.opengl.GLSurfaceView {
    companion object {
        val IMAGE_FORMAT_RGB = 0x00
        val IMAGE_FORMAT_RGBA = 0x01
        private val IMAGE_FORMAT_NV21 = 0x02
        private val IMAGE_FORMAT_NV12 = 0x03
        private val IMAGE_FORMAT_I420 = 0x04
    }

    private lateinit var mRenderer: GLSurfaceView.Renderer
    private lateinit var myNativeRender: MyNativeRender

    constructor(context: Context, attributeSet: AttributeSet) : super(context, attributeSet){
        init()
    }

    constructor(context: Context) : super(context) {
        init()
    }

    private fun init() {
        Log.d("dingjia", "MyGLSurfaceView::init()")
        this.setEGLContextClientVersion(3)
        myNativeRender = MyNativeRender()
        mRenderer = MyGLRender(myNativeRender)
        setRenderer(mRenderer)
        renderMode = RENDERMODE_CONTINUOUSLY;
    }

    inner class MyGLRender : GLSurfaceView.Renderer {

        private lateinit var myNativeRender: MyNativeRender

        constructor(nativeRender: MyNativeRender) {
            myNativeRender = nativeRender
        }

        override fun onSurfaceCreated(p0: GL10?, p1: EGLConfig?) {
            Log.d("dingjia", "native_OnInit")
            myNativeRender.native_OnInit()
        }

        override fun onSurfaceChanged(p0: GL10?, p1: Int, p2: Int) {
            Log.d("dingjia", "native_OnSurfaceChanged")

            myNativeRender.native_OnSurfaceChanged(p1, p2)
        }

        override fun onDrawFrame(p0: GL10?) {
            Log.d("dingjia", "native_OnDrawFrame")

            myNativeRender.native_OnDrawFrame()
        }
    }

    fun setImageData(format: Int, width: Int, height: Int, bytes: ByteArray) {
        myNativeRender.native_SetImageData(format, width, height, bytes)
    }
}
