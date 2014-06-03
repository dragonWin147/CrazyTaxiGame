//
//  SoundManager.cpp
//  XomNhaLa
//
//  Created by Tiến Bảo on 12/17/13.
//
//

#include "SoundManager.h"
#include "SimpleAudioEngine.h"
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
		"Final Sound/TT_Title.wav",
		"Final Sound/TT_Button_Press.wav",
		// Game Start
		"Final Sound/TT_LightCountDownRed.wav",
		"Final Sound/TT_LightCountDownRed.wav",
		"Final Sound/TT_LightCountDownRed.wav",
		"Final Sound/TT_LightCountDownGreen.wav",

		//Game
		"Final Sound/TT_Title1.wav", "Final Sound/TT_Title2.wav",

		//Swipe
		"Final Sound/TT_SwipeLeft.wav", "Final Sound/TT_SwipeRight.wav",

		//Crash
		"Final Sound/TT_Crash.wav",
		//Hover
		"Final Sound/TT_Hover.wav",

		//high score
		"Final Sound/TT_AlmosthighScore.wav",
		"Final Sound/TT_EqualhighScore.wav",

		//GameOver
		"Final Sound/TT_GameOver_Music.wav", "Final Sound/TT_Button_Press.wav",

		//-	Leaderboard
		"Final Sound/TT_GameOver_Music.wav", "Final Sound/TT_Button_Press.wav",

};

void SoundManager::playSound(eTypeSound type) {
	if (isEnable)
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
				listSoundName[type]);
}

SoundManager::~SoundManager() {

}
