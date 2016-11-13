package com.yellowdanger;

import android.os.Bundle;
import android.support.annotation.Keep;
import android.util.Log;

import com.google.firebase.analytics.FirebaseAnalytics;

import org.liballeg.android.AllegroActivity;

public class YellowAndDangerous extends AllegroActivity {


    private FirebaseAnalytics mFirebaseAnalytics;

    static void loadLibrary(String name) {
        try {
            Log.d("loadLibrary", name + "-debug");
            System.loadLibrary(name + "-debug");
        } catch (UnsatisfiedLinkError e) {
            Log.d("loadLibrary", name);
            System.loadLibrary(name);
        }
    }

    /* Load Allegro and other shared libraries in the lib directory of the apk
     * bundle.  You must load libraries which are required by later libraries
     * first.
     */
    static {
        loadLibrary("allegro");
        loadLibrary("allegro_primitives");
        loadLibrary("allegro_image");
        loadLibrary("allegro_font");
        loadLibrary("allegro_ttf");
        loadLibrary("allegro_audio");
        loadLibrary("allegro_acodec");
        loadLibrary("allegro_color");
    }

    /* By default, AllegroActivity.onCreate will cause Allegro to load the
     * shared object `libapp.so'.  You can specify another library name by
     * overriding the constructor.
     */
    public YellowAndDangerous() {
        super("libnative.so");
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mFirebaseAnalytics = FirebaseAnalytics.getInstance(this);
    }

    @Keep
    public void postEvent(String message) {
        Log.d("YellowAndDangerous", "event: " + message);
        String[] parameters = message.split(" ");
        Bundle bundle = new Bundle();
        for (int i = 1; i < parameters.length; i++) {
            String[] keyval = parameters[i].split("=");
            bundle.putString(keyval[0], keyval[1]);
        }
        mFirebaseAnalytics.logEvent(parameters[0], bundle);
        if (parameters[0].equals("level_up")) {
            mFirebaseAnalytics.logEvent(parameters[0] + bundle.getString("level"), null);
        }
    }
}
