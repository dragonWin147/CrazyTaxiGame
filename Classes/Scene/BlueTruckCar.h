#ifndef __BlueTruckCar_SCENE_H__
#define __BlueTruckCar_SCENE_H__

#include "cocos2d.h"
#include "Car.h"
USING_NS_CC;
class BlueTruckCar: public CCSprite {
private:
	BlueTruckCar();
	~BlueTruckCar();
	static BlueTruckCar* blueTruckCar;
	CCAction* actionNormal;
	CCAction* actionScore;
public:
	static BlueTruckCar* create();
	void runActionNormal();
	void runActionScore();
	void stopNormal();
	void stopScore();
};

#endif // __BlueTruckCar_SCENE_H__
