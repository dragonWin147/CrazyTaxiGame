#ifndef __BlueCar_SCENE_H__
#define __BlueCar_SCENE_H__

#include "cocos2d.h"
#include "Car.h"
USING_NS_CC;
class BlueCar: public CCSprite {
private:
	BlueCar();
	~BlueCar();
	static BlueCar* blueCar;
	CCAction* actionNormal;
	CCAction* actionScore;
public:
	static BlueCar* create();
	void runActionNormal();
	void runActionScore();
	void stopNormal();
	void stopScore();
};

#endif // __BlueCar_SCENE_H__
