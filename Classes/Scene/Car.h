#ifndef __Car_SCENE_H__
#define __Car_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class Car: public CCSprite {
public:
	Car();
	~Car();
//	static Car* car;
	CCAction* actionNormal;
	CCAction* actionScore;
	int typeCar; //1: BLue Car; 2: Pink ; 3 Orange; 4 Blue Truck
	float speed;
	bool change;
public:
	static Car* createBlueCar();
	static Car* createBlueTruck();
	static Car* createOrangeCar();
	static Car* createPinkCar();
	void runActionNormal();
	void runActionScore();
	void stopNormal();
	void stopScore();
};

#endif // __Car_SCENE_H__
