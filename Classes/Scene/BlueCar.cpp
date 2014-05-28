#include "BlueCar.h"
#include "../AppDelegate.h"

BlueCar::BlueCar() {
	blueCar = NULL;
	actionNormal = NULL;
	actionScore = NULL;
}
BlueCar::~BlueCar() {
	CCLog("Car::~BlueCar()");
}
BlueCar* BlueCar::blueCar = NULL;
BlueCar* BlueCar::create(){
	blueCar = new BlueCar();
	if (blueCar && blueCar->initWithFile("BlueCarNormal/Blue Care Normal1.png")) {
		return blueCar;
	}
	CC_SAFE_DELETE(blueCar);
	return NULL;
}

void BlueCar::runActionNormal(){
	if(actionNormal == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("BlueCarNormal/Blue Care Normal1.png");
		animation->addSpriteFrameWithFileName("BlueCarNormal/Blue Care Normal2.png");
		animation->addSpriteFrameWithFileName("BlueCarNormal/Blue Care Normal3.png");
		animation->addSpriteFrameWithFileName("BlueCarNormal/Blue Care Normal4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionNormal = CCRepeatForever::create(animate);
		actionNormal->retain();
	}
	blueCar->runAction(actionNormal);
}

void BlueCar::runActionScore(){
	if(actionScore == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("BlueCarScore/Blue Care Score1.png");
		animation->addSpriteFrameWithFileName("BlueCarScore/Blue Care Score2.png");
		animation->addSpriteFrameWithFileName("BlueCarScore/Blue Care Score3.png");
		animation->addSpriteFrameWithFileName("BlueCarScore/Blue Care Score4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionScore = CCRepeatForever::create(animate);
		actionScore->retain();
	}
	blueCar->runAction(actionScore);
}

void BlueCar::stopNormal(){
	if(actionNormal!=NULL)
	blueCar->stopAction(actionNormal);
}

void BlueCar::stopScore(){
	if(actionScore!=NULL)
	blueCar->stopAction(actionScore);
}







