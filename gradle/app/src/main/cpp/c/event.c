/* This file was generated by scramble.py. */
#line 1 "src/event.py"
#include "event.h"
#line 2
#ifdef ANDROID
#include "allegro5/allegro_android.h"
#line 3
#endif
#line 6
void event(char const * format, ...) {
    LandBuffer * b = land_buffer_new();
    va_list args;
    va_start(args, format);
    land_buffer_addv(b, format, args);
    va_end(args);
    char * data = land_buffer_finish(b);
    #ifdef ANDROID
    JNIEnv * env = al_android_get_jni_env();
#line 16
    jclass class_id = (* env)->GetObjectClass(env, al_android_get_activity());
    jmethodID method_id = (* env)->GetMethodID(env, class_id, "postEvent", "(Ljava/lang/String;)V");
#line 19
    jstring jdata = (* env)->NewStringUTF(env, data);
    (* env)->CallVoidMethod(env, al_android_get_activity(), method_id, jdata);
    (* env)->DeleteLocalRef(env, jdata);
    (* env)->DeleteLocalRef(env, class_id);
    land_log_message("%s", data);
#line 23
    #endif
#line 25
    land_free(data);
}
void show_interstitial_ad(void) {
    #ifdef ANDROID
    JNIEnv * env = al_android_get_jni_env();
    jclass class_id = (* env)->GetObjectClass(env, al_android_get_activity());
    jmethodID method_id = (* env)->GetMethodID(env, class_id, "showInterstitialAd", "()V");
    (* env)->CallVoidMethod(env, al_android_get_activity(), method_id);
    (* env)->DeleteLocalRef(env, class_id);
#line 33
    #endif
}
#line 36
bool show_ad_done(void) {
    #ifdef ANDROID
    JNIEnv * env = al_android_get_jni_env();
    jclass class_id = (* env)->GetObjectClass(env, al_android_get_activity());
    jmethodID method_id = (* env)->GetMethodID(env, class_id, "showAdDone", "()I");
    jint r = (* env)->CallIntMethod(env, al_android_get_activity(), method_id);
    (* env)->DeleteLocalRef(env, class_id);
    return r != 0;
#line 43
    #endif
#line 45
    return 1;
}
void open_link(str url) {
    #ifdef ANDROID
    JNIEnv * env = al_android_get_jni_env();
#line 51
    jclass class_id = (* env)->GetObjectClass(env, al_android_get_activity());
    jmethodID method_id = (* env)->GetMethodID(env, class_id, "openUrl", "(Ljava/lang/String;)V");
#line 54
    jstring jdata = (* env)->NewStringUTF(env, url);
    (* env)->CallVoidMethod(env, al_android_get_activity(), method_id, jdata);
    (* env)->DeleteLocalRef(env, jdata);
    (* env)->DeleteLocalRef(env, class_id);
#line 57
    #else
#line 59
    print("would open link %s", url);
#line 59
    #endif
#line 59
    return ;
}
/* This file was generated by scramble.py. */
