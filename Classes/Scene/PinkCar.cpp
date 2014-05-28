#include "PinkCar.h"
#include "../AppDelegate.h"

PinkCar::PinkCar() {
	pinkCar = NULL;
	actionNormal = NULL;
	actionScore = NULL;
}
PinkCar::~PinkCar() {

}
PinkCar* PinkCar::pinkCar = NULL;
PinkCar* PinkCar::create(){
	pinkCar = new PinkCar();
	if (pinkCar && pinkCar->initWithFile("PinkCarNormal/Pink Car Normal1.png")) {
		return pinkCar;
	}
	CC_SAFE_DELETE(pinkCar);
	return NULL;
}

void PinkCar::runActionNormal(){
	if(actionNormal == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("PinkCarNormal/Pink Car Normal1.png");
		animation->addSpriteFrameWithFileName("PinkCarNormal/Pink Car Normal2.png");
		animation->addSpriteFrameWithFileName("PinkCarNormal/Pink Car Normal3.png");
		animation->addSpriteFrameWithFileName("PinkCarNormal/Pink Car Normal4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionNormal = CCRepeatForever::create(animate);
		actionNormal->retain();
	}
	pinkCar->runAction(actionNormal);
}

void PinkCar::runActionScore(){
	if(actionScore == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("PinkCarScore/Pink Car Score1.png");
		animation->addSpriteFrameWithFileName("PinkCarScore/Pink Car Score2.png");
		animation->addSpriteFrameWithFileName("PinkCarScore/Pink Car Score3.png");
		animation->addSpriteFrameWithFileName("PinkCarScore/Pink Car Score4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionScore = CCRepeatForever::create(animate);
		actionScore->retain();
	}
	pinkCar->runAction(actionScore);
}

void PinkCar::stopNormal(){
	if(actionNormal)
		pinkCar->stopAction(actionNormal);
}

void PinkCar::stopScore(){
	if(actionScore)
		pinkCar->stopAction(actionScore);
}







