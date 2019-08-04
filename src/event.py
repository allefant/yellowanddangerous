import common
***ifdef ANDROID
***include "allegro5/allegro_android.h"
***endif

def event(char const *format, ...):
    LandBuffer *b = land_buffer_new()
    va_list args
    va_start(args, format)
    land_buffer_addv(b, format, args)
    va_end(args)
    char *data = land_buffer_finish(b)
    ***ifdef ANDROID
    JNIEnv *env = al_android_get_jni_env()
  
    jclass class_id = (*env)->GetObjectClass(env, al_android_get_activity())
    jmethodID method_id = (*env)->GetMethodID(env, class_id, "postEvent", "(Ljava/lang/String;)V")
    
    jstring jdata = (*env)->NewStringUTF(env, data)
    (*env)->CallVoidMethod(env, al_android_get_activity(), method_id, jdata);
    (*env)->DeleteLocalRef(env, jdata);
    (*env)->DeleteLocalRef(env, class_id);
    land_log_message("%s", data)
    ***endif
    land_free(data)

def show_interstitial_ad:
    ***ifdef ANDROID
    JNIEnv *env = al_android_get_jni_env()
    jclass class_id = (*env)->GetObjectClass(env, al_android_get_activity())
    jmethodID method_id = (*env)->GetMethodID(env, class_id, "showInterstitialAd", "()V")
    (*env)->CallVoidMethod(env, al_android_get_activity(), method_id);
    (*env)->DeleteLocalRef(env, class_id);
    ***endif

def show_ad_done -> bool:
    ***ifdef ANDROID
    JNIEnv *env = al_android_get_jni_env()
    jclass class_id = (*env)->GetObjectClass(env, al_android_get_activity())
    jmethodID method_id = (*env)->GetMethodID(env, class_id, "showAdDone", "()I")
    jint r = (*env)->CallIntMethod(env, al_android_get_activity(), method_id);
    (*env)->DeleteLocalRef(env, class_id);
    return r != 0
    ***endif
    return True

def open_link(str url):
    ***ifdef ANDROID
    JNIEnv *env = al_android_get_jni_env()
  
    jclass class_id = (*env)->GetObjectClass(env, al_android_get_activity())
    jmethodID method_id = (*env)->GetMethodID(env, class_id, "openUrl", "(Ljava/lang/String;)V")
    
    jstring jdata = (*env)->NewStringUTF(env, url)
    (*env)->CallVoidMethod(env, al_android_get_activity(), method_id, jdata);
    (*env)->DeleteLocalRef(env, jdata);
    (*env)->DeleteLocalRef(env, class_id);
    ***else
    print("would open link %s", url)
    ***endif
    
    return
