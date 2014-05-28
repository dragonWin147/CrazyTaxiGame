#ifndef __PinkCar_SCENE_H__
#define __PinkCar_SCENE_H__

#include "cocos2d.h"
#include "Car.h"
USING_NS_CC;
class PinkCar: public CCSprite {
private:
	PinkCar();
	~PinkCar();
	static PinkCar* pinkCar;
	CCAction* actionNormal;
	CCAction* actionScore;
public:
	static PinkCar* create();
	void runActionNormal();
	void runActionScore();
	void stopNormal();
	void stopScore();
};

#endif // __PinkCar_SCENE_H__
