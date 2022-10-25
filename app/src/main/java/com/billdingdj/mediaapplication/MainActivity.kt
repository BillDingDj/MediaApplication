package com.billdingdj.mediaapplication

import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.billdingdj.mediaapplication.MyGLSurfaceView.Companion.IMAGE_FORMAT_RGB
import com.billdingdj.mediaapplication.MyGLSurfaceView.Companion.IMAGE_FORMAT_RGBA
import com.billdingdj.mediaapplication.databinding.ActivityMainBinding
import java.io.InputStream
import java.nio.ByteBuffer

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var glRender: MyGLSurfaceView

    companion object {
        // Used to load the 'mediaapplication' library on application startup.
        init {
            System.loadLibrary("native-bridge")
        }

        const val TAG = "dingjia-java"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        glRender = findViewById(R.id.myGlSurfaceView)
        loadImage(R.drawable.image)
    }

    private fun loadImage(resId: Int) {
        val input = resources.openRawResource(resId)

        try {
            val bitmap = BitmapFactory.decodeStream(input)
            bitmap?.let {
                val bytes = bitmap.byteCount
                val buffer = ByteBuffer.allocate(bytes)
                bitmap.copyPixelsToBuffer(buffer)
                Log.d(TAG, "${bitmap.config}")
                glRender.setImageData(
                    IMAGE_FORMAT_RGBA,
                    bitmap.width,
                    bitmap.height,
                    buffer.array()
                )
            }
        } catch (e: java.lang.Exception) {
            Log.e(TAG, "error when open bitmap, ${e.message}")
        }
    }

    /**
     * A native method that is implemented by the 'mediaapplication' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
}