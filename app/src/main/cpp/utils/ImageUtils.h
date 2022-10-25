//
// Created by admin on 2022/10/25.
//

#ifndef MEDIAAPPLICATION_IMAGEUTILS_H
#define MEDIAAPPLICATION_IMAGEUTILS_H

#include <cstdlib>
#include "LogUtils.h"
#include <string.h>


#define IMAGE_FORMAT_RGB           0x00
#define IMAGE_FORMAT_RGBA           0x01
#define IMAGE_FORMAT_NV21           0x02
#define IMAGE_FORMAT_NV12           0x03
#define IMAGE_FORMAT_I420           0x04
#define IMAGE_FORMAT_YUYV           0x05
#define IMAGE_FORMAT_GRAY           0x06

struct NativeImage {
    int width;
    int height;
    int format;
    uint8_t *ppPlane[3];

    NativeImage() {
        width = 0;
        height = 0;
        format = 0;
        ppPlane[0] = nullptr;
        ppPlane[1] = nullptr;
        ppPlane[2] = nullptr;
    }
};

static void AllocNativeImage(NativeImage *pImage) {
    if (pImage->height == 0 || pImage->width == 0) return;

    switch (pImage->format) {
        case IMAGE_FORMAT_RGB: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(pImage->width * pImage->height * 3));
            break;
        }
        case IMAGE_FORMAT_RGBA: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(pImage->width * pImage->height * 4));
        }
            break;
        case IMAGE_FORMAT_YUYV: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(pImage->width * pImage->height * 2));
        }
            break;
        case IMAGE_FORMAT_NV12:
        case IMAGE_FORMAT_NV21: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(
                    pImage->width * pImage->height * 1.5));
            pImage->ppPlane[1] = pImage->ppPlane[0] + pImage->width * pImage->height;
        }
            break;
        case IMAGE_FORMAT_I420: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(
                    pImage->width * pImage->height * 1.5));
            pImage->ppPlane[1] = pImage->ppPlane[0] + pImage->width * pImage->height;
            pImage->ppPlane[2] = pImage->ppPlane[1] + pImage->width * (pImage->height >> 2);
        }
            break;
        case IMAGE_FORMAT_GRAY: {
            pImage->ppPlane[0] = static_cast<uint8_t *>(malloc(pImage->width * pImage->height));
        }
            break;
        default:
            LOGCATE("NativeImageUtil::AllocNativeImage do not support the format. Format = %d",
                    pImage->format);
            break;
    }
}

static void CopyNativeImage(NativeImage *pSrcImg, NativeImage *pDstImg) {
    if (pSrcImg == nullptr || pSrcImg->ppPlane[0] == nullptr) return;

    if (pSrcImg->format != pDstImg->format ||
        pSrcImg->width != pDstImg->width ||
        pSrcImg->height != pDstImg->height)
        return;

    if (pDstImg->ppPlane[0] == nullptr) AllocNativeImage(pDstImg);

    switch (pSrcImg->format) {
        case IMAGE_FORMAT_I420:
        case IMAGE_FORMAT_NV21:
        case IMAGE_FORMAT_NV12: {
            memcpy(pDstImg->ppPlane[0], pSrcImg->ppPlane[0],
                   pSrcImg->width * pSrcImg->height * 1.5);
        }
            break;
        case IMAGE_FORMAT_YUYV: {
            memcpy(pDstImg->ppPlane[0], pSrcImg->ppPlane[0], pSrcImg->width * pSrcImg->height * 2);
        }
            break;
        case IMAGE_FORMAT_RGBA: {
            memcpy(pDstImg->ppPlane[0], pSrcImg->ppPlane[0], pSrcImg->width * pSrcImg->height * 4);
        }
            break;
        case IMAGE_FORMAT_RGB: {
            memcpy(pDstImg->ppPlane[0], pSrcImg->ppPlane[0], pSrcImg->width * pSrcImg->height * 3);
        }
            break;
        case IMAGE_FORMAT_GRAY: {
            memcpy(pDstImg->ppPlane[0], pSrcImg->ppPlane[0], pSrcImg->width * pSrcImg->height);
        }
            break;
        default: {
            LOGCATE("NativeImageUtil::CopyNativeImage do not support the format. Format = %d",
                    pSrcImg->format);
        }
            break;
    }

}


#endif //MEDIAAPPLICATION_IMAGEUTILS_H

