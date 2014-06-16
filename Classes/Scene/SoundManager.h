//
//  SoundManager.h
//  XomNhaLa
//
//  Created by Tiến Bảo on 12/17/13.
//
//

#ifndef __XomNhaLa__SoundManager__
#define __XomNhaLa__SoundManager__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
USING_NS_CC_EXT;
enum eTypeSound {
	//Game Intro
	TT_Title,
	TT_Button_Press,
	// Game Start
	TT_LightCountDownRed,
	TT_LightCountDownGreen,

	//Game
	TT_Title1,
	TT_Title2,

	//Swipe
	TT_SwipeLeft,
	TT_SwipeRight,

	//Crash
	TT_Crash,
	//Hover
	TT_Hover,

	//high score
	TT_AlmosthighScore,
	TT_EqualhighScore,

	//GameOver
	TT_GameOver_Music,
//	TT_Button_Press,
	TT_Score,
	//-	Leaderboard
//	TT_GameOver_Music,
//	TT_Button_Press,
};

class SoundManager{
public:

public:
	SoundManager();
	virtual ~SoundManager();
	static SoundManager* gI();
	static SoundManager* instance;
    void playSoundEffect(eTypeSound type);
    void playSoundBackground(eTypeSound type);
    CC_SYNTHESIZE(bool, isEnable, IsEnable);
};

#endif /* defined(__XomNhaLa__SoundManager__) */
