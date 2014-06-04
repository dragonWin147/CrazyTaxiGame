//
//  SoundManager.cpp
//  XomNhaLa
//
//  Created by Tiến Bảo on 12/17/13.
//
//

#include "SoundManager.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

SoundManager* SoundManager::instance = NULL;

SoundManager* SoundManager::gI() {
	//If the singleton has no instance yet, create one
	if (NULL == instance) {
		//Create an instance to the singleton
		instance = new SoundManager();
	}

	//Return the singleton object
	return instance;
}

SoundManager::SoundManager() {
	isEnable = true;
}

const char * listSoundName[] = {
		"FinalSound/TT_Title.wav",
		"FinalSound/TT_Button_Press.wav",
		// Game Start
		"FinalSound/TT_LightCountDownRed.wav",
		"FinalSound/TT_LightCountDownGreen.wav",

		//Game
		"FinalSound/TT_Title1.wav",
		"FinalSound/TT_Title2.wav",

		//Swipe
		"FinalSound/TT_SwipeLeft.wav",
		"FinalSound/TT_SwipeRight.wav",

		//Crash
		"FinalSound/TT_Crash.wav",
		//Hover
		"FinalSound/TT_Hover.wav",

		//high score
		"FinalSound/TT_AlmostHighScore.wav",
		"FinalSound/TT_EqualHighScore.wav",

		//GameOver
		"FinalSound/TT_GameOver_Music.wav",
//		"Final Sound/TT_Button_Press.wav",

		//-	Leaderboard
//		"Final Sound/TT_GameOver_Music.wav",
//		"Final Sound/TT_Button_Press.wav",

};

void SoundManager::playSoundEffect(eTypeSound type) {
	if (isEnable)
		SimpleAudioEngine::sharedEngine()->playEffect(
				listSoundName[type]);
}
void SoundManager::playSoundBackground(eTypeSound type) {
	if (isEnable)
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
				listSoundName[type],true);
}
SoundManager::~SoundManager() {

}
