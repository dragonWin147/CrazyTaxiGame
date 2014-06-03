#include "AppDelegate.h"
#include "Scene/MainMenu.h"

USING_NS_CC;
using namespace cocos2d;

float AppDelegate::scaleX = 1;

float AppDelegate::scaleY = 1;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	CCSize frameSize = pEGLView->getFrameSize();
	AppDelegate::scaleX = frameSize.width / 1536;
	AppDelegate::scaleY = frameSize.height / 2048;
	pDirector->setOpenGLView(pEGLView);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	CCScene *pScene = MainMenu::scene();

	// run
	pDirector->runWithScene(pScene);

	return true;
}

float AppDelegate::getScaleX() {
	return AppDelegate::scaleX;
}

float AppDelegate::getScaleY() {
	return AppDelegate::scaleY;
}

float AppDelegate::getMinScale() {

	return MIN(AppDelegate::scaleX, AppDelegate::scaleY);

}
// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
