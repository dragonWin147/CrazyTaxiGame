#ifndef __OrangeCar_SCENE_H__
#define __OrangeCar_SCENE_H__

#include "cocos2d.h"
#include "Car.h"
USING_NS_CC;
class OrangeCar: public CCSprite {
private:
	OrangeCar();
	~OrangeCar();
	static OrangeCar* orangeCar;
	CCAction* actionNormal;
	CCAction* actionScore;
public:
	static OrangeCar* create();
	void runActionNormal();
	void runActionScore();
	void stopNormal();
	void stopScore();
};

#endif // __OrangeCar_SCENE_H__
