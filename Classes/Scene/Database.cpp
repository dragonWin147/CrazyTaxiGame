/*
 * FishGutouyu.cpp
 *
 *  Created on: Sep 6, 2013
 *      Author: Admin
 */

#include "Database.h"
USING_NS_CC;
using namespace std;

bool Database::init() {
	if (!CCNode::init()) {
		return false;
	}
	return true;
}
Database::Database(){
	numberArr = new CCArray();
	initNumber();
	initTextureRes();
}
Database::~Database(){

}
void Database::initTextureRes(){
	//Turtle Car
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward1.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward2.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward3.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward4.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward5.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward6.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward7.png");
	CCSprite::create("TurtleForward/Turtle Animation 1_Forward8.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left1.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left2.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left3.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left4.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left5.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left6.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left7.png");
	CCSprite::create("TurtleLeft/Turtle Animation 1_Left8.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right1.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right2.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right3.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right4.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right5.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right6.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right7.png");
	CCSprite::create("TurtleRight/Turtle Animation 1_Right8.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash1.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash2.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash3.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash4.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash5.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash6.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash7.png");
	CCSprite::create("TurtleCrash/Turtle Animation 1_Crash8.png");

	CCSprite::create("TurtleHover/Turtle Animation 1_Hover1.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover2.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover3.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover4.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover5.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover6.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover7.png");
	CCSprite::create("TurtleHover/Turtle Animation 1_Hover8.png");

	//Blue Car
	CCSprite::create("BlueCarNormal/Blue Care Normal1.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal2.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal3.png");
	CCSprite::create("BlueCarNormal/Blue Care Normal4.png");
	CCSprite::create("BlueCarScore/Blue Care Score1.png");
	CCSprite::create("BlueCarScore/Blue Care Score2.png");
	CCSprite::create("BlueCarScore/Blue Care Score3.png");
	CCSprite::create("BlueCarScore/Blue Care Score4.png");
	//Pink
	CCSprite::create("PinkCarNormal/Pink Car Normal1.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal2.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal3.png");
	CCSprite::create("PinkCarNormal/Pink Car Normal4.png");
	CCSprite::create("PinkCarScore/Pink Car Score1.png");
	CCSprite::create("PinkCarScore/Pink Car Score2.png");
	CCSprite::create("PinkCarScore/Pink Car Score3.png");
	CCSprite::create("PinkCarScore/Pink Car Score4.png");
	//Blue truck

	CCSprite::create("BlueTruckNormal/Blue Truck Normal1.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal2.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal3.png");
	CCSprite::create("BlueTruckNormal/Blue Truck Normal4.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score1.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score2.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score3.png");
	CCSprite::create("BlueTruckScore/Blue Truck Score4.png");

	//Orange
	CCSprite::create("OrangeCarNormal/Orange Car_Normal1.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal2.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal3.png");
	CCSprite::create("OrangeCarNormal/Orange Car_Normal4.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score1.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score2.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score3.png");
	CCSprite::create("OrangeCarScore/Orange Car_Score4.png");

	CCSprite::create("FinalPNG/City_Background.png");
	CCSprite::create("FinalPNG/Country Background.png");
	CCSprite::create("FinalPNG/TT_LeaderBoard.png");
	CCSprite::create("FinalPNG/TT_GameOverScoreBackground.png");
	CCSprite::create("FinalPNG/TT_LeaderTitle.png");
	CCSprite::create("FinalPNG/TT_GameOverTitle.png");
	CCSprite::create("FinalPNG/TT_Ready_1.png");
	CCSprite::create("FinalPNG/TT_Ready_2.png");
	CCSprite::create("FinalPNG/TT_Ready_3.png");
	CCSprite::create("FinalPNG/TT_Ready_4GO.png");
}
void Database::saveData(int score){
	CCDate* date = new CCDate();
	CCString* timeStr = CCString::createWithFormat("%d/%d/%d", date->mday(), date->month(), date->year());
	int scoreData = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore0",0);
	int scoreOfDay = CCUserDefault::sharedUserDefault()->getIntegerForKey(timeStr->getCString(),0);
//	if(score > scoreData)
//		CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore",score);
	if(score > scoreOfDay)
		CCUserDefault::sharedUserDefault()->setIntegerForKey(timeStr->getCString(),score);

	int _score;
	for (int i = 0; i < 8; i++) {
		CCString* str = CCString::createWithFormat("%s%d", "highScore", i);
		_score = CCUserDefault::sharedUserDefault()->getIntegerForKey(
				str->getCString(), 0);
		if (score > _score) {
//			if(checkScoreInit(i+1)||_score == 0){
				CCString* str_day = CCString::createWithFormat("%s%s", str->getCString(), "day");
				CCString* str_month = CCString::createWithFormat("%s%s", str->getCString(), "month");
				CCString* str_year = CCString::createWithFormat("%s%s", str->getCString(), "year");
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str->getCString(), score);
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_day->getCString(), date->mday());
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_month->getCString(), date->month());
				CCUserDefault::sharedUserDefault()->setIntegerForKey(
						str_year->getCString(), date->year());
				if(_score > 0 )
					saveData(_score);
				break;
//			}
		}
	}

}

CCSprite* Database::drawScore(const char * str){
	CCSprite *sprite = CCSprite::create();
	int _score = CCUserDefault::sharedUserDefault()->getIntegerForKey(
			str, 0);
	if (_score > 0) {
		CCString* str_day = CCString::createWithFormat("%s%s", str, "day");
		CCString* str_month = CCString::createWithFormat("%s%s",str, "month");
		CCString* str_year = CCString::createWithFormat("%s%s", str, "year");
		int _day = CCUserDefault::sharedUserDefault()->getIntegerForKey(str_day->getCString(), 0);
		int _month = CCUserDefault::sharedUserDefault()->getIntegerForKey(str_month->getCString(),
				0);
		int _year = CCUserDefault::sharedUserDefault()->getIntegerForKey(str_year->getCString(),
				0);
		CCSprite* sprite_1 = getNumberFont(_score);
		CCSprite* sprite_2 = getNumberFont(_day);
		CCSprite* sprite_3 = CCSprite::create();
		sprite_3->setDisplayFrame(getKey(2));
		CCSprite* sprite_4 = getNumberFont(_month);
		CCSprite* sprite_5 = CCSprite::create();
		sprite_5->setDisplayFrame(getKey(2));
		CCSprite* sprite_6 = getNumberFont(_year/1000);
		CCSprite* sprite_7 = getNumberFont((_year/100)%10);
		CCSprite* sprite_8 = getNumberFont((_year/10)%10);
		CCSprite* sprite_9 = getNumberFont(_year%10);
		sprite->addChild(sprite_1);
		sprite->addChild(sprite_2);
		sprite->addChild(sprite_3);
		sprite->addChild(sprite_4);
		sprite->addChild(sprite_5);
		sprite->addChild(sprite_6);
		sprite->addChild(sprite_7);
		sprite->addChild(sprite_8);
		sprite->addChild(sprite_9);
		sprite_1->setAnchorPoint(ccp(0,0.5f));
		sprite_2->setAnchorPoint(ccp(0,0.5f));
		sprite_3->setAnchorPoint(ccp(0,0.5f));
		sprite_4->setAnchorPoint(ccp(0,0.5f));
		sprite_5->setAnchorPoint(ccp(0,0.5f));
		sprite_6->setAnchorPoint(ccp(0,0.5f));
		sprite_7->setAnchorPoint(ccp(0,0.5f));
		sprite_8->setAnchorPoint(ccp(0,0.5f));
		sprite_9->setAnchorPoint(ccp(0,0.5f));

		sprite_1->setPosition(ccp(0,sprite->getContentSize().height/2));
		sprite_2->setPosition(ccp(3 * 90,sprite->getContentSize().height/2));
		sprite_3->setPosition(ccp(sprite_2->getPositionX() + 2 * 90,sprite->getContentSize().height/2));
		sprite_4->setPosition(ccp(sprite_3->getPositionX() + sprite_3->getContentSize().width,sprite->getContentSize().height/2));
		sprite_5->setPosition(ccp(sprite_4->getPositionX() + sprite_4->getContentSize().width,sprite->getContentSize().height/2));
		sprite_6->setPosition(ccp(sprite_5->getPositionX() + sprite_5->getContentSize().width,sprite->getContentSize().height/2));
		sprite_7->setPosition(ccp(sprite_6->getPositionX() + sprite_6->getContentSize().width,sprite->getContentSize().height/2));
		sprite_8->setPosition(ccp(sprite_7->getPositionX() + sprite_7->getContentSize().width,sprite->getContentSize().height/2));
		sprite_9->setPosition(ccp(sprite_8->getPositionX() + sprite_8->getContentSize().width,sprite->getContentSize().height/2));
	}else{
		sprite->setDisplayFrame(getKey(4));
	}
	sprite->setScale(0.5f);
	return sprite ;
}

CCSprite* Database::getNumberFont(int number){
	CCSprite* sprite = CCSprite::create();
	sprite->retain();
	if(number < 10){
		sprite->setDisplayFrame((CCSpriteFrame*)numberArr->objectAtIndex(number));
	}
	else if(number < 100){
		CCSprite* sprite_1 = CCSprite::create();
		sprite_1->setDisplayFrame(
				(CCSpriteFrame*) numberArr->objectAtIndex(number/10));
		sprite->addChild(sprite_1);
		sprite_1->setPosition(ccp(sprite_1->getContentSize().width/2,sprite->getContentSize().height/2));

		CCSprite* sprite_2 = CCSprite::create();
		sprite_2->setDisplayFrame(
				(CCSpriteFrame*) numberArr->objectAtIndex(number % 10));
		sprite->addChild(sprite_2);
		sprite_2->setPosition(ccp(sprite_1->getContentSize().width/2 + sprite_2->getContentSize().width/2 + 10,sprite->getContentSize().height/2));
//		sprite->setScale(0.8f);
	}else if(number < 1000){
		CCSprite* sprite_1 = CCSprite::create();
		sprite_1->setDisplayFrame(
				(CCSpriteFrame*) numberArr->objectAtIndex(number/100));
		sprite->addChild(sprite_1);
		sprite_1->setPosition(ccp(sprite_1->getContentSize().width/2,sprite->getContentSize().height/2));

		CCSprite* sprite_2 = CCSprite::create();
		sprite_2->setDisplayFrame(
				(CCSpriteFrame*) numberArr->objectAtIndex((number%100)/10));
		sprite->addChild(sprite_2);
		sprite_2->setPosition(ccp(sprite_1->getContentSize().width/2 + sprite_2->getContentSize().width/2 + 10,sprite->getContentSize().height/2));

		CCSprite* sprite_3 = CCSprite::create();
		sprite_3->setDisplayFrame(
				(CCSpriteFrame*) numberArr->objectAtIndex(number % 10));
		sprite->addChild(sprite_3);
		sprite_3->setPosition(ccp(sprite_2->getContentSize().width + sprite_3->getContentSize().width/2 + 25,sprite->getContentSize().height/2));

//		sprite->setScale(0.5f);
	}
	return sprite;
}

CCSpriteFrame* Database::getKey(int key){
	CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(
			"FinalPNG/TT_FONTS.png");
	CCSpriteFrame * frame = NULL;
	if(key == 1){
		frame = CCSpriteFrame::createWithTexture(texture,
						CCRect(22, 1486, 40, 106));
	}else if(key == 2){
		frame = CCSpriteFrame::createWithTexture(texture,
						CCRect(155, 1486, 69, 106));
	}else if(key == 3){
		frame = CCSpriteFrame::createWithTexture(texture,
						CCRect(362, 1554, 40, 40));
	}else if(key == 4){
		frame = CCSpriteFrame::createWithTexture(texture,
						CCRect(486, 1527, 45, 25));
	}
	return frame;
}
void Database::initNumber(){
	CCLog("Database::initNumber");
	CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(
			"FinalPNG/TT_FONTS.png");
	for(int i = 0 ; i < 10; i++){
		CCSpriteFrame * numberFrame = CCSpriteFrame::createWithTexture(texture,
				CCRect(130 *i, 1283, 130, 130));
		numberArr->addObject(numberFrame);
	}
}
