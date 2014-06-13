/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package com.example.taxigame;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.json.JSONException;
import org.json.JSONObject;

import com.easyndk.classes.AndroidNDKHelper;

import android.os.Bundle;
import android.util.Log;

public class CrazyTaxiGame extends Cocos2dxActivity {

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		AndroidNDKHelper.SetNDKReciever(this);
	}

	public Cocos2dxGLSurfaceView onCreateView() {
		Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
		// CrazyTaxiGame should create stencil buffer
		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

		return glSurfaceView;
	}

	public void postScoreFaceBook(JSONObject json) {
		try {
			String score = (String) json.getString("score");
			Log.e("postScoreFaceBook ", score);
			AndroidNDKHelper.SendMessageWithParameters("postScoreFaceBookSuccess", null);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void postScoreTwitter(JSONObject json) {
		try {
			String score = (String) json.getString("score");
			Log.e("postScoreFaceBook ", score);
			AndroidNDKHelper.SendMessageWithParameters("postScoreTwitterSuccess", null);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public void likeFaceBook(JSONObject json) {
		Log.e("likeFaceBook ", "likeFaceBook");
		AndroidNDKHelper.SendMessageWithParameters("likeFaceBookSuccess", null);
	}

	public void showAdsTop(JSONObject json) {
		Log.e("showAdsTop ", "showAdsTop");
		AndroidNDKHelper.SendMessageWithParameters("showAdsSuccess", new JSONObject());
	}

	public void showAdsCenter(JSONObject json) {
		Log.e("showAdsCenter ", "showAdsCenter");
		AndroidNDKHelper.SendMessageWithParameters("showAdsSuccess", null);
	}

	public void hideAds(JSONObject json) {
		Log.e("hideAds ", "hideAds");
		AndroidNDKHelper.SendMessageWithParameters("hideAdsSuccess", null);
	}
	static {
		System.loadLibrary("cocos2dcpp");
	}
}
