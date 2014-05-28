#include "BlueTruckCar.h"
#include "../AppDelegate.h"

BlueTruckCar::BlueTruckCar() {
	blueTruckCar = NULL;
	actionNormal = NULL;
	actionScore = NULL;
}
BlueTruckCar::~BlueTruckCar() {

}
BlueTruckCar* BlueTruckCar::blueTruckCar = NULL;
BlueTruckCar* BlueTruckCar::create(){
	blueTruckCar = new BlueTruckCar();
	if (blueTruckCar && blueTruckCar->initWithFile("BlueTruckNormal/Blue Truck Normal1.png")) {
		return blueTruckCar;
	}
	CC_SAFE_DELETE(blueTruckCar);
	return NULL;
}

void BlueTruckCar::runActionNormal(){
	if(actionNormal == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("BlueTruckNormal/Blue Truck Normal1.png");
		animation->addSpriteFrameWithFileName("BlueTruckNormal/Blue Truck Normal2.png");
		animation->addSpriteFrameWithFileName("BlueTruckNormal/Blue Truck Normal3.png");
		animation->addSpriteFrameWithFileName("BlueTruckNormal/Blue Truck Normal4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionNormal = CCRepeatForever::create(animate);
		actionNormal->retain();
	}
	blueTruckCar->runAction(actionNormal);
}

void BlueTruckCar::runActionScore(){
	if(actionScore == NULL){
		CCAnimation* animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("BlueTruckScore/Blue Truck Score1.png");
		animation->addSpriteFrameWithFileName("BlueTruckScore/Blue Truck Score2.png");
		animation->addSpriteFrameWithFileName("BlueTruckScore/Blue Truck Score3.png");
		animation->addSpriteFrameWithFileName("BlueTruckScore/Blue Truck Score4.png");
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionScore = CCRepeatForever::create(animate);
		actionScore->retain();
	}
	blueTruckCar->runAction(actionScore);
}

void BlueTruckCar::stopNormal() {
	if (actionNormal)
		blueTruckCar->stopAction(actionNormal);
}

void BlueTruckCar::stopScore() {
	if (actionScore)
		blueTruckCar->stopAction(actionScore);
}







