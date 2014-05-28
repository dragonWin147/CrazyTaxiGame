#include "OrangeCar.h"
#include "../AppDelegate.h"

OrangeCar::OrangeCar() {
	orangeCar = NULL;
	actionNormal = NULL;
	actionScore = NULL;
}
OrangeCar::~OrangeCar() {

}
OrangeCar* OrangeCar::orangeCar = NULL;
OrangeCar* OrangeCar::create(){
	orangeCar = new OrangeCar();
	if (orangeCar && orangeCar->initWithFile("OrangeCarNormal/Orange Car_Normal1.png")) {
		return orangeCar;
	}
	CC_SAFE_DELETE(orangeCar);
	return NULL;
}

void OrangeCar::runActionNormal(){
	if(actionNormal == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("OrangeCarNormal/Orange Car_Normal1.png");
		animation->addSpriteFrameWithFileName("OrangeCarNormal/Orange Car_Normal2.png");
		animation->addSpriteFrameWithFileName("OrangeCarNormal/Orange Car_Normal3.png");
		animation->addSpriteFrameWithFileName("OrangeCarNormal/Orange Car_Normal4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionNormal = CCRepeatForever::create(animate);
		actionNormal->retain();
	}
	orangeCar->runAction(actionNormal);
}

void OrangeCar::runActionScore(){
	if(actionScore == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("OrangeCarScore/Orange Car_Score1.png");
		animation->addSpriteFrameWithFileName("OrangeCarScore/Orange Car_Score2.png");
		animation->addSpriteFrameWithFileName("OrangeCarScore/Orange Car_Score3.png");
		animation->addSpriteFrameWithFileName("OrangeCarScore/Orange Car_Score4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionScore = CCRepeatForever::create(animate);
		actionScore->retain();
	}
	orangeCar->runAction(actionScore);
}

void OrangeCar::stopNormal(){
	if (actionNormal)
		orangeCar->stopAction(actionNormal);
}

void OrangeCar::stopScore() {
	if (actionScore)
		orangeCar->stopAction(actionScore);
}







