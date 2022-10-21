//
// Created by admin on 2022/10/21.
//

#ifndef LOG_UTILS
#define LOG_UTILS


#include <android/log.h>
#include <sys/time.h>

#define  LOG_TAG "dingjia-media"

#define  LOGCATE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGCATV(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGCATD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGCATI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


#endif //LOG_UTILS
