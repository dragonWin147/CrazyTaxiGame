#include "Car.h"
#include "../AppDelegate.h"

Car::Car() {
	typeCar = 0;
	change =false;
	actionNormal = NULL;
	actionScore = NULL;
	speed = 0;
	land = 0 ;
	pass = false;
}
Car::~Car() {

}
//Car* Car::car = NULL;
Car* Car::createBlueCar() {
	Car *car = new Car();
	if (car && car->initWithFile("BlueCarNormal/Blue Care Normal1.png")) {
		return car;
	}
	CC_SAFE_DELETE(car);
	return NULL;
}
Car* Car::createPinkCar() {
	Car *car = new Car();
	if (car && car->initWithFile("PinkCarNormal/Pink Car Normal1.png")) {
		return car;
	}
	CC_SAFE_DELETE(car);
	return NULL;
}
Car* Car::createOrangeCar() {
	Car *car = new Car();
	if (car && car->initWithFile("OrangeCarNormal/Orange Car_Normal1.png")) {
		return car;
	}
	CC_SAFE_DELETE(car);
	return NULL;
}
Car* Car::createBlueTruck() {
	Car *car = new Car();
	if (car && car->initWithFile("BlueTruckNormal/Blue Truck Normal1.png")) {
		return car;
	}
	CC_SAFE_DELETE(car);
	return NULL;
}

void Car::runActionNormal() {
	if (actionNormal == NULL) {
		CCAnimation* animation = CCAnimation::create();
		if (typeCar == 1) {
			animation->addSpriteFrameWithFileName(
					"BlueCarNormal/Blue Care Normal1.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarNormal/Blue Care Normal2.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarNormal/Blue Care Normal3.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarNormal/Blue Care Normal4.png");
		} else if (typeCar == 2) {
			animation->addSpriteFrameWithFileName(
					"PinkCarNormal/Pink Car Normal1.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarNormal/Pink Car Normal2.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarNormal/Pink Car Normal3.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarNormal/Pink Car Normal4.png");
		} else if (typeCar == 3) {
			animation->addSpriteFrameWithFileName(
					"OrangeCarNormal/Orange Car_Normal1.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarNormal/Orange Car_Normal2.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarNormal/Orange Car_Normal3.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarNormal/Orange Car_Normal4.png");
		} else if (typeCar == 4) {
			animation->addSpriteFrameWithFileName(
					"BlueTruckNormal/Blue Truck Normal1.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckNormal/Blue Truck Normal2.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckNormal/Blue Truck Normal3.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckNormal/Blue Truck Normal4.png");
		}
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionNormal = CCRepeatForever::create(animate);
		actionNormal->retain();
	}
	this->runAction(actionNormal);
}

void Car::runActionScore() {
	if (actionScore == NULL) {
		CCLog("type_card stopNormal %d", this->typeCar);
		CCAnimation* animation = CCAnimation::create();
		if (typeCar == 1) {
			animation->addSpriteFrameWithFileName(
					"BlueCarScore/Blue Care Score1.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarScore/Blue Care Score2.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarScore/Blue Care Score3.png");
			animation->addSpriteFrameWithFileName(
					"BlueCarScore/Blue Care Score4.png");
		} else if (typeCar == 2) {
			animation->addSpriteFrameWithFileName(
					"PinkCarScore/Pink Car Score1.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarScore/Pink Car Score2.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarScore/Pink Car Score3.png");
			animation->addSpriteFrameWithFileName(
					"PinkCarScore/Pink Car Score4.png");
		} else if (typeCar == 3) {
			animation->addSpriteFrameWithFileName(
					"OrangeCarScore/Orange Car_Score1.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarScore/Orange Car_Score2.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarScore/Orange Car_Score3.png");
			animation->addSpriteFrameWithFileName(
					"OrangeCarScore/Orange Car_Score4.png");
		} else if (typeCar == 4) {
			animation->addSpriteFrameWithFileName(
					"BlueTruckScore/Blue Truck Score1.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckScore/Blue Truck Score2.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckScore/Blue Truck Score3.png");
			animation->addSpriteFrameWithFileName(
					"BlueTruckScore/Blue Truck Score4.png");
		}
		animation->setDelayPerUnit(0.1f);
		CCAnimate *animate = CCAnimate::create(animation);
		actionScore = CCRepeatForever::create(animate);
		actionScore->retain();
	}
	this->runAction(actionScore);
}

void Car::stopNormal() {
	if (actionNormal)
		this->stopAction(actionNormal);
}

void Car::stopScore() {
	if (actionScore)
		this->stopAction(actionScore);
}

