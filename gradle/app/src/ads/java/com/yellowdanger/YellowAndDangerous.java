package com.yellowdanger;

import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.InterstitialAd;
import com.google.android.gms.ads.MobileAds;

public class YellowAndDangerous extends BaseActivity {
    private InterstitialAd mInterstitialAd;
    private boolean showingAd;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        MobileAds.initialize(getApplicationContext(), "ca-app-pub-7818455682102414~3747009689");
        mInterstitialAd = new InterstitialAd(this);
        mInterstitialAd.setAdUnitId("ca-app-pub-7818455682102414/8273221287");

        mInterstitialAd.setAdListener(new AdListener() {
            @Override
            public void onAdClosed() {
                Log.d("YellowAndDangerous", "onAdClosed");
                requestNewInterstitial();
                showingAd = false;
            }
        });

        requestNewInterstitial();
    }

    private void requestNewInterstitial() {
        Log.d("YellowAndDangerous", "requestNewInterstitial");
        AdRequest adRequest = new AdRequest.Builder().build();
        mInterstitialAd.loadAd(adRequest);
    }

    @Override
    public void showInterstitialAd() {
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                if (mInterstitialAd.isLoaded()) {
                    showingAd = true;
                    mInterstitialAd.show();
                }
                else if (!mInterstitialAd.isLoading()) {
                    requestNewInterstitial();
                }
            }
        });
    }

    @Override
    public int showAdDone() {
        return showingAd ? 0 : 1;
    }


}
